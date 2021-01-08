/* Call Library source file */

#include "extcode.h"

/* lv_prolog.h and lv_epilog.h set up the correct alignment for LabVIEW data. */
#include "lv_prolog.h"

/* Typedefs */

typedef struct {
	LStrHandle SerialNumber;
	LStrHandle Model;
	int32_t VersionMajor;
	int32_t VersionMinor;
	int32_t Release;
	int32_t DeviceType;
	int32_t DeviceID;
	} TD1;

#include "lv_epilog.h"

uint8_t GetDevices(TD1 *devices, uint8_t *result);

uint8_t GetDevices(TD1 *devices, uint8_t *result)
{

	/* Insert code here */

}

