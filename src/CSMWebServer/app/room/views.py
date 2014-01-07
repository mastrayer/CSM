from flask import Blueprint, request, render_template, flash, g, session, redirect, url_for

from app import db
from app.user.models import User

mod = Blueprint('room', __name__, url_prefix='/room')

@mod.route('/')
def room_list():
    if g.user == None:
       return redirect(url_for("general.main"))

    return render_template("room/lobby.html")

@mod.before_request
def before_request():
    g.user = None
    if 'user_id' in session:
        g.user = User.query.get(session['user_id'])
