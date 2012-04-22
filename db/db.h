#ifndef _DB_H
#define _DB_H

#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>

typedef enum success_e { TRUE, FALSE } success_e;
typedef struct database_t {
    MYSQL *conn;
} database_t;

database_t *initAndConnectToDatabase(char *server, char *user, char *password, char *database);

void releaseDatabase(database_t *db);

void sendData(database_t *db, int h_version_number, int h_type, int h_data_field_header_flag, int h_application_process_id, int h_sequence_flags, int h_sequence_count, size_t h_packet_length, void* data, success_e success);

#endif
