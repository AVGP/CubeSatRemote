#include <stdio.h>
#include <stdlib.h>
#include "packet.h"

void dumpPacket(qb_tc_packet *packet) {
    printf("> Header\n");
    printf("\tVersion: 0x%X\n", packet->primary_header->version);
    printf("\tType: %d (%s)\n", packet->primary_header->type, 
        (packet->primary_header->type == 0 ? "Telemetry" : "Telecommand"));
    printf("\tAPID: 0x%X\n", packet->primary_header->apid);
    printf("\tSequence Flags: %d\n", packet->primary_header->seq_flags);
 
    switch(packet->primary_header->seq_flags) {
        case PACKET_SEQ_FIRST:
            printf("\tSequence info: first packet of seq.\n");
            break;
        case PACKET_SEQ_LAST:
            printf("\tSequence info: last packet of seq.\n");
            break;
        case PACKET_SEQ_MIDDLE:
            printf("\tSequence info: intermediate packet of seq.\n");
            break;
        default:
            printf("\tSequence info: standalone packet.\n");
            break;
    }
    printf("\tSequence Count: 0x%X\n", packet->primary_header->seq_count);
    printf("\tPackage length: %d bytes\n", packet->primary_header->length);
    printf("\tSecondary header present: %s\n", (packet->primary_header->sh_present ? "yes" : "no"));

    if(packet->primary_header->sh_present && packet->secondary_header == NULL) {
        printf("ERROR: Header says a secondary header is present, but the pointer to it is NULL!\n"); 
    }

    printf("\tData:\n");
    char *p = (packet->primary_header->sh_present == 0 ? packet->data : packet->secondary_header);
    unsigned int i=0;
    for(i=0;i<packet->primary_header->length;i++) {
        printf("0x%X ", (unsigned int)*p);
        p++;
    }
    printf("\n\n");
}

int main(int argc, char **argv) {
    if(argc < 3) {
        printf("Usage: packet_gen <number of packets overall> <number of senders>\n");
        return 0;
    }
    
    int numPackets = atoi(argv[1]);
    int numSatellites = atoi(argv[2]);

    qb_tc_packet *p = malloc(sizeof(qb_tc_packet));
    p->primary_header = malloc(sizeof(qb_tc_packet_header));
    p->primary_header->version = 0;
    p->primary_header->type = 1;
    p->primary_header->sh_present = 0;
    p->primary_header->apid = 2047; //all 11 bit are set to 1.    
    p->primary_header->seq_flags = PACKET_SEQ_STANDALONE;
    p->primary_header->seq_count = 16383; //all 14 bit are set to1.
    p->primary_header->length = 13;
    p->data = "Hello world!"; 


    dumpPacket(p);

    return 0;
}

