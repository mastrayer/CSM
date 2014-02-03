from app import db
from app.user import constants as USER

class User(db.Model):
	__tablename__ = 'tbl_user'
	id = db.Column(db.Integer, primary_key=True)
	nickname = db.Column(db.String(120,collation='utf8_general_ci'), unique=True)
	email = db.Column(db.String(120,collation='utf8_general_ci'), unique=True)
	password = db.Column(db.String(120,collation='utf8_general_ci'))
	play_count = db.Column(db.Integer, default=0)
	win_count = db.Column(db.Integer, default=0)
	lose_count = db.Column(db.Integer, default=0)
        kill_sum = db.Column(db.Integer, default=0)
	role = db.Column(db.SmallInteger, default=USER.USER)
	status = db.Column(db.SmallInteger, default=USER.INACTIVE)

	def __init__(self, nickname=None, email=None, password=None):
		self.nickname = nickname
		self.email = email
		self.password = password

	def getStatus(self):
		return USER.STATUS[self.status]

	def getRole(self):
		return USER.ROLE[self.role]

