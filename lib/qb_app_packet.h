#ifndef _APP_PACKET_H
#define _APP_PACKET_H

typedef struct {
    unsigned short spacecraft_id;   //The Spacecraft ID the original packet came from;
    unsigned char is_valid;         //Tells if the original frame was valid (1 = valid, 0 = invalid)
    qb_tc_packet *packet;           //The actual TC-Packet
} qb_app_packet;

#endif
