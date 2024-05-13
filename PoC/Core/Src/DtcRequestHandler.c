#include "DtcRequestHandler.h"

void ClearAllDtc()
{
	LOGF(DL_DEBUG, "Operation started!");
	Dem_ClearDTC(overVoltage.clientId);
	Dem_ClearDTC(underVoltage.clientId);
	LOGF(DL_DEBUG, "Operation finished!");
}

void ReadAllDtc()
{
	uint8_t dtcStatus[4] = {0};

	LOGF(DL_DEBUG, "Operation started!");
	Dem_GetStatusOfDTC(overVoltage.clientId, dtcStatus);
	Dem_GetStatusOfDTC(underVoltage.clientId, dtcStatus);
	LOGF(DL_DEBUG, "Operation finished!");
}
