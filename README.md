This project tackles the CubeSat Command&Control Challenge:

http://spaceappschallenge.org/challenge/new-command-and-control-protocol-cubesats

Considerations:
===============

The project is based upon four components:

1. packet generator: As we cannot access real satellite intercomm and the software build at EPFL, we had to write a packet generator to create TC / TD packets, introduce some noise and error
2. Database-Adapter: A tool to receive packets, make them into frames (TC_FILES) and push them into a database.
3. API-Layer: A program exposing a bunch of methods to serve data from the database to client-applications. Maybe this will be some kind of RESTful service offered to client-apps
4. A client-app to actually access and interact with data collected from the satellite (and, maybe later on) issue commands to the satellite.

1. Packet generator
-------------------

Remarks: We think the underlying protocol, AX.25, is pretty well-known, so we do not tackle this, we're starting at the Packetization-Layer described in
CCSDS 203.0-B-2 and ECSS-E-70-41A.
In our scenario, we're skipping out the SourceID and spare-padding fields (described in ECSS-E-70-41A Section 5.3.3) and set "implicitely known for the mission" lengths of fields to 8 bit.

2. Database adapter
-------------------

3. API-Layer
------------

4. Client-App
-------------

