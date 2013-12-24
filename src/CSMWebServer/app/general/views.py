from flask import Blueprint, request, render_template, flash, g, session, redirect, url_for

from app import db


mod = Blueprint('general', __name__, url_prefix='/')

@mod.route('/')
def main():
	return render_template('general/main.html')


