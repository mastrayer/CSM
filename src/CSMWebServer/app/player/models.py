from app import db

class Player(db.Model):
    __tablename__ = 'tbl_player'
    id = db.Column(db.Integer, primary_key=True)
    user_id = db.Column(db.Integer)
    room_id = db.Column(db.Integer)

    def __init__(self, user_id=None, room_id=None):
        self.user_id = user_id
        self.room_id = room_id
