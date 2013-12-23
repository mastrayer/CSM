from flask.ext.wtf import Form, RecaptchaField
from wtforms import TextField, PasswordField, BooleanField
from wtforms.validators import Required, EqualTo, Email

class LoginForm(Form):
	email = TextField('Email address', [Required(), Email()])
	password = PasswordField('Password', [Required()])

class RegisterForm(Form):
	email = TextField('Email address', [Required(), Email()])
	password = PasswordField('Password', [Required()])
	confirm = PasswordField('Repeat Pasword', [Required(), EqualTo('password', message='Passwords must match')])
	nickname = TextField('NickName', [Required()])

	recaptcha = RecaptchaField()
