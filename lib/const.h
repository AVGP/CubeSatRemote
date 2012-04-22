#ifndef _CONSTANT_H
#define _CONSTANT_H

#define TC_FRAME_VERSION        0           // Version number for qb_tc_frame

//TC Frame Commands XOR-Check masks
#define TC_COMMAND_LEN               1;     //Length of this command in byte
#define TC_COMMAND_SET_V_R_MASK 0x4100;     //XOR-Mask for Acceptance check
#define TC_COMMAND_UNLOCK_MASK       0;     //Length of this mask in byte

//TC Frame Validation error codes
#define TC_FRAME_VALIDATION_ERR_VERSION 1   //Mismatching Version field
#define TC_FRAME_VALIDATION_ERR_SCID    2   //Invalid Spacecraft ID
#define TC_FRAME_VALIDATION_ERR_LEN     4   //Specified length mismatches the actual data field
#define TC_FRAME_VALIDATION_ERR_CHKSUM  8   //Checksum error, not implemented
#define TC_FRAME_VALIDATION_ERR_CMD     16  //Invalid Control Command   

#endif
