from flask import Blueprint, request, render_template, flash, g, session, redirect, url_for

from app import db
from app.board.models import Board

mod = Blueprint('board', __name__, url_prefix='/board/')

@mod.route('/list/', methods=['GET'])
def list():
	return render_template("board/list.html")

@mod.route('/detail/<board_id>', methods=['GET'])
def detail():
	return render_template("board/detail.html")
