#include "util.h"

unsigned int mkSegments(qb_tc_packet **packets, unsigned int num_packets, qb_tc_segment **segments) {
    return 0;
}

qb_tc_frame *mkFrame(unsigned short spacecraft_id, qb_tc_segment *segment) {
    qb_tc_frame *result = malloc(sizeof(qb_tc_frame));
    result->header = malloc(sizeof(qb_tc_frame_header));
    result->header->version             = 0;
    result->header->bypass_flag         = 0;
    result->header->ctrl_command_flag   = 0;
    result->header->spare               = 0;
    result->header->spacecraft_id       = spacecraft_id;
    result->header->vc_id               = 0; //We don't support that now
    result->header->length              = sizeof(*segment);
    result->header->seq                 = 1; //We don't really use that here.
    result->data                        = segment;

    return result;
}

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

    printf("> Data:\n\t");
    char *p = (packet->primary_header->sh_present == 0 ? packet->data : packet->secondary_header);
    unsigned int i=0;
    for(i=0;i<packet->primary_header->length;i++) {
        printf("0x%X ", (unsigned int)*p);
        p++;
    }
    printf("\n\n");
}



