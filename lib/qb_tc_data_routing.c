#include "qb_tc_data_routing.h"

    char qb_validateFrame(qb_tc_frame *frame, unsigned short **spacecraft_ids, unsigned short num_spacecraft_ids) {
        if(frame->header->version != 0) return TC_FRAME_VALIDATION_ERR_VERSION;
     
        int i=0;
        unsigned char valid_scid = 0;
        for(i=0;i<num_spacecraft_ids;i++) {
            if(*spacecraft_ids[i] == frame->header->spacecraft_id) {
                valid_scid = 1;
                break;
            }
        }
        if(valid_scid != 1) return TC_FRAME_VALIDATION_ERR_SCID;
        
        //This is still buggy. And by buggy I mean: It doesn't work.
        /*
        if(sizeof(*(frame->data)) != frame->header->length) 
            return TC_FRAME_VALIDATION_ERR_LEN;
        */

        if(frame->header->ctrl_command_flag == 1) {
            unsigned char len = TC_COMMAND_LEN;
            unsigned char mask = 0;
            char *tmp = malloc(len);
            memcpy(tmp, frame->data, len);
            mask = TC_COMMAND_UNLOCK_MASK
            if(((int)*tmp ^ mask) != 0)
                return TC_FRAME_VALIDATION_ERR_CMD;

            memcpy(tmp, frame->data, len);
            mask = TC_COMMAND_SET_V_R_MASK;
            if(((int)*tmp ^ mask) != 0)
                return TC_FRAME_VALIDATION_ERR_CMD;
            free(tmp);
        }
         
        return 0;
    }
