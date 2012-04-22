#include "qb_tc_data_routing.h"

    char validateFrame(qb_tc_frame *frame, unsigned short **spacecraft_ids, unsigned short num_spacecraft_ids) {
        if(frame->header->version != 0) return TC_FRAME_VALIDATION_ERR_VERSION;
     
        int i=0;
        unsigned char valid_scid = false;
        for(i=0;i<num_spacecraft_ids;i++) {
            if(*spacecraft_ids[i] == frame->header->spacecraft_id) {
                valid_scid = true;
                break;
            }
        }
        if(!valid_scid) return TC_FRAME_VALIDATION_ERR_SCID;

        if(sizeof(*frame->data) != frame->header->length) 
            return TC_FRAME_VALIDATION_ERR_LEN;

        if(frame->header->ctrl_command_flag == 1) {
            char *tmp = malloc(TC_COMMAND_LEN);
            memcpy(tmp, frame->data, TC_COMMAND_LEN);
            if(tmp ^ TC_COMMAND_UNLOCK_MASK != 0)
                return TC_FRAME_VALIDATION_ERR_CMD;

            memcpy(tmp, frame->data, TC_COMMAND_LEN);
            if(tmp ^ TC_COMMAND_SET_V_R_MASK != 0)
                return TC_FRAME_VALIDATION_ERR_CMD;
        }
         
        return 0;
    }
