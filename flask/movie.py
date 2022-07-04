from flask import Flask, jsonify
app = Flask(__name__)

@app.route("/api/v1/movies")
def get_api():
    movies = [{'name': '刺激1995'}, {'name': '教父'}]
    return jsonify(movies)
