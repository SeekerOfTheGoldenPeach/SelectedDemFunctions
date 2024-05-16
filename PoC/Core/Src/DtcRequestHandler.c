#include "DtcRequestHandler.h"
#undef DLT_LOG_CONTEX
#define DLT_LOG_CONTEX "DtcH"

uint8_t status[4] = {0};

void ClearAllDtc()
{

	LOGF(DL_DEBUG, "Operation started!");



	Dem_ClearDTC(overVoltage.clientId);
	Dem_ClearDTC(underVoltage.clientId);

	LOGF(DL_DEBUG, "Operation finished!");

}

void ReadAllDtc()
{
	LOGF(DL_DEBUG, "Operation started!");


	Dem_GetStatusOfDTC(overVoltage.clientId, status);
	Dem_GetStatusOfDTC(underVoltage.clientId, status);

	LOGF(DL_DEBUG, "Operation finished!");


}
#undef DLT_LOG_CONTEX
