#ifndef _SIMULATOR_H
#define _SIMULATOR_H

#include <stdio.h>
#include <stdlib.h>
#include "../lib/const.h"
#include "../lib/packet.h"
#include "../lib/segment.h"
#include "../lib/frame.h"

/**
* Creates a qb_tc_packet from any given payload data. It should be a multiple of 8 bits long.
* @param seq_number The packet sequence number, used to identify a packet in a stream of packets. NOTE: Maximum length 14 bit!
* @param apid The application ID to be assigned to the packet. This allows to transfer different kind of data via packets. NOTE: Maximum length 11 bit!
* @param data Pointer to the payload data for the packet
* @param data_len Length of data in byte. The length of a packet shall not exceed 65536 byte!
* @return Returns a pointer to an internally allocated qb_tc_packet structure.
*/
qb_tc_packet *qb_data_to_packet(unsigned short seq_number, unsigned short apid, void *data, unsigned short data_len);

/**
* Creates TC-Segment(s) from a given number of qb_tc_packet structures
* @param[in] packets A pointer to an array of qb_tc_packets to transform into qb_tc_segments
* @param[in] num_packets The numer of packets in the packets array
* @param[out] segments Pointer to a buffer filled with segments. Will be allocated by this function.
* @return Returns the number of generated segments (i.e. number of elements in the segments array)
*/
unsigned int mkSegments(qb_tc_packet **packets, unsigned int num_packets, qb_tc_segment **segments);

/*
* Transforms a TC-Segment into a TC-Frame.
* @param spacecraft_id Spacecraft ID of the sender - NOTE: You can only use the lower 10 bits.
* @param segment A pointer to the qb_tc_segment that is to be turned into a frame
* @return Returns a pointer to the allocated qb_tc_frame structure
*/
qb_tc_frame *mkFrame(unsigned short spacecraft_id, qb_tc_segment *segment);

/**
* Dumps a qb_tc_packet to stdout as human-readable information
* @param packet A pointer to the qb_tc_packet to be dumped
*/
void dump_packet(qb_tc_packet *packet);

#endif
