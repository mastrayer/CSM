from flask import Blueprint, request, render_template, flash, g, session, redirect, url_for

from app import db
from app.room.forms import CreateRoomForm
from app.room.models import Room
from app.user.models import User
from app.player.models import Player
from app.user.decorators import requires_login

mod = Blueprint('room', __name__, url_prefix='/room')

@mod.route('/')
@requires_login
def room_list():
    game_list = Room.query.all()
    for game in game_list:
        game.player_count = Player.query.filter_by(room_id=game.id).count()

    user = Player.query.filter_by(user_id=session['user_id']).first()
    if user:
        return redirect(url_for("room.already"))

    return render_template("room/lobby.html", game_list=game_list)

@mod.route('/create/', methods=['GET','POST'])
@requires_login
def room_create():
    form = CreateRoomForm(request.form)

    #if form.validate_on_submit():
    if request.method == 'POST' and form.title.data != None and form.type.data != None:
        room = Room(title=form.title.data, type=form.type.data)
        db.session.add(room)
        db.session.commit()

        return redirect(url_for("room.room_list"))
    
    return render_template("room/create_room.html")

@mod.route('/already/')
@requires_login
def already():
    user = Player.query.filter_by(user_id=session['user_id']).first()
    if not user:
        return redirect(url_for("room.room_list"))

    return render_template("room/already_game.html")

@mod.before_request
def before_request():
    g.user = None
    if 'user_id' in session:
        g.user = User.query.get(session['user_id'])
