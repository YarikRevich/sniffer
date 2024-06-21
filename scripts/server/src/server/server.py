from flask import Flask

from ..storage import Storage

app = Flask(__name__)


@app.route("/")
def __records():
    """Retrieves available newest records."""

    return Storage.get_records()


def run(host: str, port: int) -> None:
    """Starts application server."""

    app.run(host=host, port=port)
