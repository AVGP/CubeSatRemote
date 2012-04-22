#ifndef _FRAME_H
#define _FRAME_H

#include "segment.h"

#pragma pack(0)

typedef struct {
    unsigned char   version:2;            //Is set to 00 (see CCSDS 202.0-B-3)
    unsigned char   bypass_flag:1;        //If set to 1, some of the acceptance
                                          //tests can be skipped. 
    unsigned char   ctrl_command_flag:1;  //0 means actual data, 1 means command
                                          // used for configuring the FARM system
    unsigned char   spare:2;              //Reserved, set to 0
    unsigned short  spacecraft_id:10;     //Spacecraft ID
    unsigned char   vc_id:6;              //Virtual Channel ID
    unsigned short  length:10;            //Length in bytes (incl. header)
    unsigned char   seq;                  //Sequence number 
} qb_tc_frame_header;

typedef struct {
    qb_tc_frame_header *header;
    qb_tc_segment *data;
    unsigned short checksum;
} qb_tc_frame;

#endif
