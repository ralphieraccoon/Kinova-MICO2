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
	int32_t VersionRelease;
	int32_t DeviceType;
	int32_t DeviceID;
	} TD1;

#include "lv_epilog.h"

int32_t TestConversion(TD1 *device);

int32_t TestConversion(TD1 *device)
{

	/* Insert code here */

}

