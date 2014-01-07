# -*- coding: utf-8 -*-
from flask.ext.wtf import Form
from wtforms import TextField, SelectField
from wtforms.validators import Required

class CreateRoomForm(Form):
    title = TextField('Room Title', [Required()])
    type = SelectField('Room Type', coerce=int, choices=[(1,1),(2,2),(3,3)])

