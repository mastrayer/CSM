from flask import Blueprint, request, render_template, flash, g, session, redirect, url_for

from app import db
from app.user.forms import LoginForm
from app.user.models import User

mod = Blueprint('general', __name__, url_prefix='/')

@mod.route('/')
def main():
	form = LoginForm(request.form)
	return render_template('general/main.html', user=g.user, form=form)

@mod.before_request
def before_request():
	g.user = None
	if 'user_id' in session:
		g.user = User.query.get(session['user_id'])
