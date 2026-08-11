#!/bin/sh

docker run -it -p 8080:8080 --rm --volume ${PWD}:/src hugo_relearn:latest bash -c "cd /src ; rm -rf public; hugo --minify"
# docker run -it -p 8080:8080 --rm --volume ${PWD}:/src hugo_relearn:latest bash -c "cd /src ; rm -rf public; hugo --minify --baseURL https://coursinfo.ca/420-5G4/"
