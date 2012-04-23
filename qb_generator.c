#include <stdio.h>
#include <stdlib.h>
#include "lib/packet.h"
#include "lib/qb_tc_data_routing.h"
#include "db/db.h"
#include "simulator/simulator.h"

int main(int argc, char **argv) {
    if(argc < 3) {
        printf("Usage: packet_gen <number of packets overall> <number of senders>\n");
        return 0;
    }

    FILE *dbConf = fopen("db.conf", "r");
    char *dbConnectInfo[4];
    if(!dbConf) {
        printf("db.conf not present!");
        return 1;
    }
    int i=0;
    for(i=0;i<4;i++) {
        dbConnectInfo[i] = malloc(100);
        fgets(dbConnectInfo[i], 100, dbConf);
        int len = strlen(dbConnectInfo[i]);
        if(dbConnectInfo[i][len-1] == '\n') dbConnectInfo[i][len-1] = 0; //strip \n
    } 
    fclose(dbConf);
/*    
    printf("Connecting to %s as user %s for db: %s\n", dbConnectInfo[0], dbConnectInfo[2], dbConnectInfo[1]);
    database_t *db = initAndConnectToDatabase(
        dbConnectInfo[0],
        dbConnectInfo[2],
        dbConnectInfo[3],
        dbConnectInfo[1]);
*/
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
    p->primary_header->length = 12; //The last (ZERO-)byte is not counted in the length field, as stated in the specs.
    p->data = "Hello world!"; 

    qb_tc_frame *f = malloc(sizeof(qb_tc_frame));
    f->header = malloc(sizeof(qb_tc_frame_header));
    f->header->version = 0;
    f->header->bypass_flag = 0;
    f->header->ctrl_command_flag = 0;
    f->header->spare = 0;
    f->header->spacecraft_id = 3;
    f->header->vc_id=0;
    f->header->length = sizeof(qb_tc_packet_header) + p->primary_header->length;
    f->header->seq = 1;
    f->data = p;

    unsigned short *spacecraft_ids = malloc(sizeof(short)*2);
    spacecraft_ids[0] = 1;
    spacecraft_ids[1] = 2;
    unsigned char validation_result = qb_validateFrame(f, &spacecraft_ids, 2);
    printf("Is frame valid? -> %s (Err-Code: %i)\n", (validation_result == 0 ? "yes" : "no"), validation_result);

    printf("DBG: Size of packet: %i\n", sizeof(*p));

    //Send it to the DB
    /*
    sendData(db,
        p->primary_header->version,
        p->primary_header->type,
        p->primary_header->sh_present,
        p->primary_header->apid,
        p->primary_header->seq_flags,
        p->primary_header->seq_count,
        p->primary_header->length,
        (void *)p->data,
        TRUE);
    releaseDatabase(db);
*/
    dumpPacket(p);

    return 0;
}

