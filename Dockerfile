# Use the official Ubuntu base image
FROM ubuntu:18.04

# Update the package list and install Qt 5
RUN apt-get update
RUN apt-get install -y --no-install-recommends qt5-default
RUN apt-get install -y qtmultimedia5-dev
RUN apt-get install -y libqt5sql5-mysql
RUN apt-get install -y pulseaudio
RUN apt-get install -y mesa-utils
RUN apt-get install -y doxygen
RUN apt-get install -y graphviz
RUN rm -rf /var/lib/apt/lists/*

# Your application setup here
COPY . /usr/src/myapp
WORKDIR /usr/src/myapp
RUN qmake -o Makefile app.pro
RUN make
RUN make clean
CMD ["./group10"]
