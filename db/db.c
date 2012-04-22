#include "db.h"

database_t *initAndConnectToDatabase(char *server, char *user, char *password, char *database) {

	database_t *db = NULL;
	db = malloc(sizeof(database_t*));
		
	db->conn = mysql_init(NULL);
	
	/* Connect to database */
	if (!mysql_real_connect(db->conn, server, user, password, database, 0, NULL, 0)) {
		fprintf(stderr, "%s\n", mysql_error(db->conn));
		exit(1);
	}
	
	return db;
}

void releaseDatabase(database_t *db) {

	mysql_close(db->conn);
	free(db);
}


void sendData(database_t *db, int h_version_number, int h_type, int h_data_field_header_flag, int h_application_process_id, int h_sequence_flags, int h_sequence_count, size_t h_packet_length, void* data, success_e success) {

	
	MYSQL_RES *res;
	MYSQL_ROW row;	
	char query[500];
	int successValue = 0;
	
	switch (success) {
		case TRUE:
			successValue = 1;
			break;
		case FALSE:
			successValue = 0;
			break;
	}
	
	sprintf(query, "INSERT INTO `cubesat`.`packet` (`id`, `h_version_number`, `h_type`, `h_data_field_header_flag`, `h_application_process_id`, `h_sequence_flags`, `h_sequence_count`, `h_packet_length`, `timestamp`, `success`, `data`) VALUES (NULL, %d, %d, %d, %d, %d, %d, %lu, CURRENT_TIMESTAMP, %d, '%s');", h_version_number, h_type, h_data_field_header_flag,h_application_process_id, h_sequence_flags, h_sequence_count, h_packet_length, successValue, data);
	
	
	printf("query: %s\n", query);
	
	
	
	// send SQL query 
	if (mysql_query(db->conn, query)) {
		fprintf(stderr, "%s\n", mysql_error(db->conn));
		exit(1);
	}
	return;
	res = mysql_use_result(db->conn);
	
	// output table name 
	printf("MySQL Tables in mysql database:\n");
	while ((row = mysql_fetch_row(res)) != NULL) {
		printf("%s \n", row[0]);
	}
	
	// close connection 
	mysql_free_result(res);
	
}
