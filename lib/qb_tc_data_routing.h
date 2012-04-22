#ifndef _TC_DATA_ROUTING
#define _TC_DATA_ROUTING

#include <stdlib.h>
#include "frame.h"
#include "segment.h"
#include "const.h"

/**
* Performs mandatory Frame Validation
* @param[in] frame              The frame data structure to validate
* @param[in] spacecraft_ids     Pointer to array of valid spacecraft IDs
* @param[in] num_spacecraft_ids Number of IDs in spacecraft_ids
* @return 0 for valid frame, one of the TC_FRAME_VALIDATION_ERR_* constants otherwise, indicating the type of error.
*/
char validateFrame(qb_tc_frame *frame, unsigned short **spacecraft_ids, unsigned short num_spacecraft_ids);

#endif
