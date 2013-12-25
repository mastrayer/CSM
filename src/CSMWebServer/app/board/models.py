from app import db
from app.board import constants as BOARD

from app.user.models import User

class Board(db.Model):
	__tablename__ = 'tbl_board'
	id = db.Column(db.Integer, primary_key=True)
	#user_id = db.Column(db.Integer, ForeignKey('user.id'))
	user = db.ForeignKey(User)
	title = db.Column(db.String(150))
	content = db.Column(db.Text)
	type = db.Column(db.SmallInteger)

	def __init__(self, title=None, content=None, type=None):
		self.title = title
		self.content = content
		self.type = type
	
	def getType(self):
		return BOARD.TYPE[self.type]
