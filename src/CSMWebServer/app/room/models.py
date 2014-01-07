from app import db
from app.room import constants in ROOM 

class Room(db.Model):
    __tablename__ = 'tbl_room'
    id = db.Column(db.Integer, primary_key=True)
    title = db.Column(db.String(100))
    size = db.Column(db.Integer)
    type = db.Column(db.String(10))

    def __init__(self, title=None, title=None, size=None, type=None):
        self.title = title
        self.size = size
        self.type = type

    def getSize():
        return ROOM.SIZE[self.size]

    def getType():
        return ROOM.TYPE[self.type]
