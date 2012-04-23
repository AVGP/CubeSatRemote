#include <stdio.h>
#include <stdlib.h>
#include "lib/packet.h"
#include "lib/qb_tc_data_routing.h"
#include "lib/util.h"
#include "db/db.h"

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
/*
    unsigned short *spacecraft_ids = malloc(sizeof(short)*2);
    spacecraft_ids[0] = 1;
    spacecraft_ids[1] = 2;
    unsigned char validation_result = qb_validateFrame(f, &spacecraft_ids, 2);
*/
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
    qb_tc_packet *p = qb_data_to_packet(1, 1, (void *)"0123456789", 11);
    printf("Size: %i\n", sizeof(*p));
    dumpPacket(p);

    return 0;
}

