#include "CommunicationLayerWindows.h"
#include "KinovaTypes.h"

#ifdef KLINTERFACE_EXPORTS
#define KLINTERFACE_API __declspec(dllexport)
#else
#define KLINTERFACE_API __declspec(dllimport)
#endif


extern "C" KLINTERFACE_API int open();

//extern "C" KLINTERFACE_API int close();

extern "C" KLINTERFACE_API int getMaxDevices();

extern "C" KLINTERFACE_API int getDevices(KinovaDevice *devices);

//extern "C" KLINTERFACE_API void setActiveDevice();

//extern "C" KLINTERFACE_API void home();

//extern "C" KLINTERFACE_API void addTrajectoryPoint(struct::TrajectoryPoint point);

//extern "C" KLINTERFACE_API void clearTrajectory();

//extern "C" KLINTERFACE_API void getCartesianPosition();

//extern "C" KLINTERFACE_API void getAnglePosition();

//extern "C" KLINTERFACE_API void getCartesianCommand();

//extern "C" KLINTERFACE_API void getAngleCommand();



