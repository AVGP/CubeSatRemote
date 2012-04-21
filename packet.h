#ifndef _PACKET_H
#define _PACKET_H

#define PACKET_SEQ_STANDALONE   3   //Packet is the only one in this sequence (i.e. a stand-alone packet)
#define PACKET_SEQ_FIRST        1   //Packet is the first of a sequence
#define PACKET_SEQ_MIDDLE       0   //Packet is somewhere in the middle of the sequence
#define PACKET_SEQ_LAST         2   //Packet is the last of the sequence

#pragma pack(1) //Do NOT byte-align. Please.

typedef struct {
    unsigned char version:3;   //Version is always 0, according to CCSDS 203.0-B-2
    unsigned char type:1;      //Type is 1 for Telecommand packets, 0 means its a Telemetry data packet.
    unsigned short apid:11;     //Application Process ID, identifies the receipient on the spacecraft to receive and handle this packet.
    //Sequence control
    unsigned char seq_flags:2; //Determine if this packet belongs to a sequence and if its the first, last or somewhere in between. (see PACKET_SEQ_*)_
    unsigned short seq_count:14;  //Could be either Sequence Count or Packet name
    
    unsigned short length;        //Length of the packet in bytes, excluding the primary header
} qb_packet_header;

typedef struct {
    qb_packet_header *primary_header;
    qb_packet_header *secondary_header; //Optional - might be NULL
    void *data;                         //The actual payload of the packet
} qb_packet;

#endif
