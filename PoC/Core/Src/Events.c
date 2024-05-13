#include "Events.h"

struct event overVoltage = {"OverVoltage", OVER_VOLTAGE_ID, DEM_EVENT_STATUS_PASSED, OVER_VOLTAGE_BOCK_ID, OVER_VOLTAGE_ID};
struct event underVoltage = {"UnderVoltage", UNDER_VOLTAGE_ID, DEM_EVENT_STATUS_PASSED, UNDER_VOLTAGE_BOCK_ID, UNDER_VOLTAGE_ID};
