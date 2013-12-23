from flask import Blueprint, request, render_template, flash, g, session, redirect, url_for
from werkzeug import check_password_hash, generate_password_hash

from app import db
from app.user.forms import RegisterForm, LoginForm
from app.user.models import User
from app.user.decorators import requires_login

mod = Blueprint('user', __name__, url_prefix='/user')

@mod.route('/')
@requires_login
def profile():
	return render_template("user/profile.html", user=g.user)

@mod.before_request
def before_request():
	g.user = None
	if 'user_id' in session:
		g.user = User.query.get(session['user_id'])

@mod.route('/login/', methods=['GET','POST'])
def login():
	form = LoginForm(request.form)

	if form.validate_on_submit():
		user = User.query.filter_by(email=form.email.data).first()

		if user and check_password_hash(user.password, form.password.data):
			session['user_id'] = user.id
			flash('Welcome %s' % user.name)
			return redirect(url_for('user.home'))
		flash('Worng email or password', 'error-message')
	return render_template('user/login.html', form=form)

@mod.route('/register/', methods=['GET','POST'])
def register():
	form = RegisterForm(request.form)
	if form.validate_on_submit():
		user = User(nickname=form.nickname.data, email=form.email.data, password=generate_password_hash(form.password.data))
		db.session.add(user)
		db.session.commit()

		session['user_id'] = user.id

		flash('Thanks for registering')

		return redirect(url_for('user.profile'))
	return render_template('user/register.html', form=form)


