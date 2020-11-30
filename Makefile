.PHONY: all test clean compile gen mkbuild clean

all: build

build:
	docker build . -t bw_replay_db:0.1

run:
	docker run bw_replay_db:0.1 /bin/bash -c \
		"\
		cd /home/bw_replay_db/libs/bwapi/build/bin \
		&& ./BWAPILauncher \
		&& cat ./maps/replays/test_replay.rep.rgd \
		"
