# Brood War Replay Database
The purpose of this project is to extract reliable gameplay data using
bwapi and openbw and insert it into a database. 
The hope is that by extracting all usable replay information and making it
available in an easy to use format, that others can build on top of it with
off the shelf SQL tools.

## To build
`make build`

## To run
`make run`

## Current Capabilities
Extracts data from replays using a modified version of bwrepdump

## Limitations
Currently only works with old replays (pre v1.18)
So this will not work with replays from Starcraft Remastered (yet)

## Next steps
- take output files and put them in a psql database
- add support for newer replay versions
- clean up Dockerfile
- make pull requests on all repos I used.
