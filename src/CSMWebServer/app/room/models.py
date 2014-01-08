from app import db
from app.room import constants as ROOM 

class Room(db.Model):
    __tablename__ = 'tbl_room'
    id = db.Column(db.Integer, primary_key=True)
    title = db.Column(db.String(100))
    type = db.Column(db.Integer)

    def __init__(self, title=None, type=None):
        self.title = title
        self.type = type
    def getType():
        return ROOM.TYPE[self.type]
