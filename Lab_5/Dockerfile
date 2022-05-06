# run: docker build -t kolokwium .           # - jednokrotnie
# then run: docker run --rm kolokwium        # potem po kazdych zmianach
# cleanup after test: docker rmi kolokwium   # po zakonczeniu kolokwium (czyszczenie obrazu dockera)

FROM ubuntu:21.04

MAINTAINER Grzegorz Prowadzacy

#### instalacja zaleznosci:
RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get install -y git cmake apt-utils build-essential libgtest-dev


#### Przygotowanie plikow
RUN mkdir -p /home/kolokwium/kolokwium_build/
ADD . /home/kolokwium/

WORKDIR /home/kolokwium/kolokwium_build/

#### cmake generuje co trzeba
RUN cmake ..
RUN make -j4

# wystawienie komendy na zewnatrz:
CMD make && /home/kolokwium/kolokwium_build/bin/lab
