import io
import os

from setuptools import find_packages, setup


def read(*paths, **kwargs):
    """Reads content at the given location."""

    content = ""
    with io.open(
            os.path.join(os.path.dirname(__file__), *paths),
            encoding=kwargs.get("encoding", "utf8"),
    ) as open_file:
        content = open_file.read().strip()
    return content


def read_description() -> str:
    """Reads description at the static location."""

    return read("README.md")


def read_requirements() -> list[str]:
    """Reads requirements file at the static location."""

    return [
        line.strip()
        for line in read("requirements.txt").split("\n")
        if not line.startswith(('"', "#", "-", "git+"))
    ]


setup(
    name="sniffer-server",
    version="0.0.1",
    description="A tool used to serve incoming sniffer data from ESP32 board as public API.",
    url="https://github.com/YarikRevich/sniffer",
    long_description=read_description(),
    long_description_content_type="text/markdown",
    author="YarikRevich",
    packages=find_packages(exclude=["tests", ".github"]),
    install_requires=read_requirements(),
    entry_points={
        "console_scripts": ["sniffer-server = src.__main__:main"]
    },
)
