from flask import Flask, render_template
from flask.ext.sqlalchemy import SQLAlchemy

app = Flask(__name__)
app.config.from_object('config')

db = SQLAlchemy(app)

@app.errorhandler(404)
def not_found(error):
	return render_template('404.html'), 404

from app.user.views import mod as userModule
from app.general.views import mod as generalModule
app.register_blueprint(userModule)
app.register_blueprint(generalModule)
