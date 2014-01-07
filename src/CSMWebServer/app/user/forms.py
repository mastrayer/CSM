from flask.ext.wtf import Form, RecaptchaField
from flask.ext.wtf.html5 import EmailField
from wtforms import TextField, PasswordField
from wtforms.validators import Required, EqualTo, Email

class LoginForm(Form):
	email = EmailField('Email address', [Required(), Email()])
	password = PasswordField('Password', [Required()])

class RegisterForm(Form):
	email = EmailField('Email address', [Required(), Email()])
	password = PasswordField('Password', [Required()])
	confirm = PasswordField('Repeat Pasword', [Required(), EqualTo('password', message='Passwords must match')])
	nickname = TextField('NickName', [Required()])

	#recaptcha = RecaptchaField()
