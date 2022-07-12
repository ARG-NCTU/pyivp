FROM argnctu/pyivp:latest
MAINTAINER mike
USER root
######################################## MOOS ####################################
RUN apt-get -o Acquire::ForceIPv4=true update && apt-get -yq dist-upgrade \
    && apt-get -o Acquire::ForceIPv4=true install -yq --no-install-recommends \
    g++ \
    cmake \
    xterm \
    libfltk1.3-dev \
    freeglut3-dev \
    libpng-dev \
    libjpeg-dev \
    libxft-dev \
    libxinerama-dev \
    libtiff5-dev
# Add MOOS-IvP to the PATH

ENV USER=arg \
    HOME=/home/${USER}
ENV PATH "$PATH:${HOME}/pyivp/svn-mirror/bin"