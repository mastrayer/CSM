from flask import Blueprint, request, render_template, flash, g, session, redirect, url_for

from app import db
from app.player.models import Player

mod = Blueprint('player',__name__,url_prefix='/player')
