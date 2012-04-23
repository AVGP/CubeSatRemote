#ifndef _SEGMENT_H
#define _SEGMENT_H

#define SEGMENT_SEQ_FLAG_MIDDLE     0
#define SEGMENT_SEQ_FLAG_FIRST      1
#define SEGMENT_SEQ_FLAG_LAST       2
#define SEGMENT_SEQ_FLAG_STANDALONE 3

#pragma pack(0)

typedef struct {
    unsigned char seq_flags:2;  //One of the values of SEGMENT_SEQ_FLAG_*, describing position in a sequence, if in any sequence, or stand-alone packet
    unsigned char map_id:6;     //ID of the Multiplexer Access Point
} qb_tc_segment_header;

typedef struct {
    qb_tc_segment_header *head; 
    void *data;                 // This can either be a complete qb_tc_packet or a part of it (depending on seq_flags in the head)
} qb_tc_segment;

#endif
