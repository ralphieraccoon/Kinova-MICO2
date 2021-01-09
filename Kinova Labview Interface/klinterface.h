#include "CommunicationLayerWindows.h"
#include "KinovaTypes.h"
#include "C:/Program Files (x86)/National Instruments/LabVIEW 2019/cintools/extcode.h"
#include "C:/Program Files (x86)/National Instruments/LabVIEW 2019/cintools/fundtypes.h"
#include "C:/Program Files (x86)/National Instruments/LabVIEW 2019/cintools/platdefines.h"
#include "C:/Program Files (x86)/National Instruments/LabVIEW 2019/cintools/lv_prolog.h"
#include "C:/Program Files (x86)/National Instruments/LabVIEW 2019/cintools/lv_epilog.h"


#ifdef KLINTERFACE_EXPORTS
#define KLINTERFACE_API __declspec(dllexport)
#else
#define KLINTERFACE_API __declspec(dllimport)
#endif

char* LStrHandletoCharArray(LStrHandle string);

LStrHandle CharArraytoLStrHandle(char* arr);

struct LVKinovaDevice {

	LStrHandle SerialNumber;

	LStrHandle Model;

	int32_t VersionMajor;

	int32_t VersionMinor;

	int32_t VersionRelease;

	int32_t DeviceType;

	int32_t DeviceID;

	operator KinovaDevice() const

	{

		KinovaDevice k;

		strcpy_s(k.SerialNumber, 20, LStrHandletoCharArray(SerialNumber));
		strcpy_s(k.Model, 20, LStrHandletoCharArray(Model));
		k.VersionMajor = VersionMajor;
		k.VersionMinor = VersionMinor;
		k.VersionRelease = VersionRelease;
		k.DeviceType = DeviceType;
		k.DeviceID = DeviceID;

		return k;


	};

	LVKinovaDevice(KinovaDevice kdevice)
		: SerialNumber(CharArraytoLStrHandle(kdevice.SerialNumber))
		, Model(CharArraytoLStrHandle(kdevice.Model))
		, VersionMajor(kdevice.VersionMajor)
		, VersionMinor(kdevice.VersionMinor)
		, VersionRelease(kdevice.VersionRelease)
		, DeviceType(kdevice.DeviceType)
		, DeviceID(kdevice.DeviceID)
	{}

	LVKinovaDevice()
	{}

};



//extern "C" KLINTERFACE_API int open();

//extern "C" KLINTERFACE_API int close();

//extern "C" KLINTERFACE_API int getMaxDevices();

//extern "C" KLINTERFACE_API int getDevices(KinovaDevice *devices);

//extern "C" KLINTERFACE_API int setActiveDevice(KinovaDevice device);

extern "C" KLINTERFACE_API int TestConversion(LVKinovaDevice *device);

//extern "C" KLINTERFACE_API void home();

//extern "C" KLINTERFACE_API void addTrajectoryPoint(struct::TrajectoryPoint point);

//extern "C" KLINTERFACE_API void clearTrajectory();

//extern "C" KLINTERFACE_API void getCartesianPosition();

//extern "C" KLINTERFACE_API void getAnglePosition();

//extern "C" KLINTERFACE_API void getCartesianCommand();

//extern "C" KLINTERFACE_API void getAngleCommand();



