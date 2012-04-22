#ifndef _PACKET_H
#define _PACKET_H

#define PACKET_SEQ_STANDALONE   3   //Packet is the only one in this sequence (i.e. a stand-alone packet)
#define PACKET_SEQ_FIRST        1   //Packet is the first of a sequence
#define PACKET_SEQ_MIDDLE       0   //Packet is somewhere in the middle of the sequence
#define PACKET_SEQ_LAST         2   //Packet is the last of the sequence

#define PACKET_SEC_HEADER_PRESENT_FLAG 0x10 //Mask to check for presence of a secondary header

#pragma pack(no-pack) //Do NOT byte-align. Please.

typedef struct {
    unsigned char version:3;    //Version is always 0, according to CCSDS 203.0-B-2
    unsigned char type:1;       //Type is 1 for Telecommand packets, 0 means its a Telemetry data packet
    unsigned char sh_present:1; //Second header presence flag. 0 means absence of a secondary header, 1 indicates presence
    unsigned short apid:11;     //Application Process ID, identifies the receipient on the spacecraft to receive and handle this packet
    //Sequence control
    unsigned char seq_flags:2; //Determine if this packet belongs to a sequence and if its the first, last or somewhere in between. (see PACKET_SEQ_*)
    unsigned short seq_count:14;  //Could be either Sequence Count or Packet name
    
    unsigned short length;        //Length of the packet in bytes, excluding the primary header
} qb_tc_packet_header;

typedef struct {
    qb_tc_packet_header *primary_header;
    /*
        REMARK: The CCSDS 203.0-B-2 specifies this to have the highest bit 
        set to 0 if its a custom header, 1 is reserved for CCSDS-specified 
        secondary headers
    */
    void *secondary_header; //Optional - might be NULL
    void *data;             //The actual payload of the packet
} qb_tc_packet;

#endif
