#ifdef _DLL

#include <Windows.h>
#include <conio.h>
#include "../KLInterface_dll/pch.h"

#else

#include <dlfcn.h>

#endif

#include "klinterface.h"
#include <iostream>
#include <stdlib.h>

#ifdef _DLL

HINSTANCE commandLayer_handle;

#else

void* commandLayer_handle;

#endif

int robotStatus;

int(*MyInitAPI)();
int(*MyCloseAPI)();
int(*MySendBasicTrajectory)(TrajectoryPoint command);
int(*MyGetDevices)(KinovaDevice devices[MAX_KINOVA_DEVICE], int& result);
int(*MySetActiveDevice)(KinovaDevice device);
int(*MyMoveHome)();
int(*MyInitFingers)();
int(*MyGetCartesianCommand)(CartesianPosition&);
int(*MyGetCartesianPosition)(CartesianPosition&);
int(*MyGetAngularCommand)(AngularPosition&);
int(*MyGetAngularPosition)(AngularPosition&);
int(*MyEraseAllTrajectories)();
int(*MyGetGlobalTrajectoryInfo)(TrajectoryFIFO&);

int open()
{

#ifdef _DLL

	commandLayer_handle = LoadLibrary(L"CommandLayerWindows.dll");

	//We load the functions from the library (Under Windows, use GetProcAddress)
	MyInitAPI = (int(*)()) GetProcAddress(commandLayer_handle, "InitAPI");
	MyCloseAPI = (int(*)()) GetProcAddress(commandLayer_handle, "CloseAPI");
	MyMoveHome = (int(*)()) GetProcAddress(commandLayer_handle, "MoveHome");
	MyInitFingers = (int(*)()) GetProcAddress(commandLayer_handle, "InitFingers");
	MyGetDevices = (int(*)(KinovaDevice devices[MAX_KINOVA_DEVICE], int& result)) GetProcAddress(commandLayer_handle, "GetDevices");
	MySetActiveDevice = (int(*)(KinovaDevice devices)) GetProcAddress(commandLayer_handle, "SetActiveDevice");
	MySendBasicTrajectory = (int(*)(TrajectoryPoint)) GetProcAddress(commandLayer_handle, "SendBasicTrajectory");
	MyGetCartesianCommand = (int(*)(CartesianPosition&)) GetProcAddress(commandLayer_handle, "GetCartesianCommand");
	MyGetCartesianPosition = (int(*)(CartesianPosition&)) GetProcAddress(commandLayer_handle, "GetCartesianPosition");
	MyGetAngularCommand = (int(*)(AngularPosition&)) GetProcAddress(commandLayer_handle, "GetAngularCommand");
	MyGetAngularPosition = (int(*)(AngularPosition&)) GetProcAddress(commandLayer_handle, "GetAngularPosition");
	MyEraseAllTrajectories = (int(*)()) GetProcAddress(commandLayer_handle, "EraseAllTrajectories");
	MyGetGlobalTrajectoryInfo = (int(*)(TrajectoryFIFO&)) GetProcAddress(commandLayer_handle, "GetGlobalTrajectoryInfo");

#else

	commandLayer_handle = dlopen("Kinova.API.USBCommandLayerUbuntu.so", RTLD_NOW | RTLD_GLOBAL);

	//We load the functions from the library (Under Windows, use GetProcAddress)
	MyInitAPI = (int(*)()) dlsym(commandLayer_handle, "InitAPI");
	MyCloseAPI = (int(*)()) dlsym(commandLayer_handle, "CloseAPI");
	MyMoveHome = (int(*)()) dlsym(commandLayer_handle, "MoveHome");
	MyInitFingers = (int(*)()) dlsym(commandLayer_handle, "InitFingers");
	MyGetDevices = (int(*)(KinovaDevice devices[MAX_KINOVA_DEVICE], int& result)) dlsym(commandLayer_handle, "GetDevices");
	MySetActiveDevice = (int(*)(KinovaDevice devices)) dlsym(commandLayer_handle, "SetActiveDevice");
	MySendBasicTrajectory = (int(*)(TrajectoryPoint)) dlsym(commandLayer_handle, "SendBasicTrajectory");
	MyGetCartesianCommand = (int(*)(CartesianPosition&)) dlsym(commandLayer_handle, "GetCartesianCommand");
	MyGetCartesianPosition = (int(*)(CartesianPosition&)) dlsym(commandLayer_handle, "GetCartesianPosition");
	MyGetAngularCommand = (int(*)(AngularPosition&)) dlsym(commandLayer_handle, "GetAngularCommand");
	MyGetAngularPosition = (int(*)(AngularPosition&)) dlsym(commandLayer_handle, "GetAngularPosition");
	MyEraseAllTrajectories = (int(*)()) dlsym(commandLayer_handle, "EraseAllTrajectories");
	MyGetGlobalTrajectoryInfo = (int(*)(TrajectoryFIFO&)) dlsym(commandLayer_handle, "GetGlobalTrajectoryInfo");

#endif

	//Verify that all functions has been loaded correctly
	if ((MyInitAPI == NULL) || (MyCloseAPI == NULL) || (MySendBasicTrajectory == NULL) ||
		(MyGetDevices == NULL) || (MySetActiveDevice == NULL) || (MyGetCartesianCommand == NULL) ||
		(MyMoveHome == NULL) || (MyInitFingers == NULL) || (MyGetCartesianCommand == NULL) || 
		(MyGetCartesianPosition == NULL) || (MyGetAngularCommand == NULL) || (MyGetAngularPosition == NULL) ||
		(MyEraseAllTrajectories == NULL) || (MyGetGlobalTrajectoryInfo == NULL))

	{
		return -1;
	}
	else
	{

		robotStatus = (*MyInitAPI)();
		return robotStatus;

	}

}

int close()
{

	int result;

	result = MyCloseAPI();

#ifdef _DLL

	FreeLibrary(commandLayer_handle);

#else

	dlclose(commandLayer_handle);

#endif

	return result;

}

int getMaxDevices()

{

	return MAX_KINOVA_DEVICE;

}

int getDevices(LVKinovaDevice *devices, int *devicecount)
{

	KinovaDevice list[MAX_KINOVA_DEVICE];

	*devicecount = MyGetDevices(list, robotStatus);

	LVKinovaDevice result[MAX_KINOVA_DEVICE];

	for (int i = 0; i < MAX_KINOVA_DEVICE; i++)
	{
		result[i] = LVKinovaDevice(list[i]);
	}

	memcpy(devices, result, sizeof(LVKinovaDevice) * MAX_KINOVA_DEVICE);

	return robotStatus;

}

int setActiveDevice(LVKinovaDevice *device)
{

	KinovaDevice input;

	input = *device;

	return MySetActiveDevice(input);

}


int sendBasicTrajectory(LVTrajectoryPoint *point)
{

	TrajectoryPoint input;

	input = *point;

	return MySendBasicTrajectory(input);

}

int home()
{

	return MyMoveHome();

}

int initFingers()
{

	return MyInitFingers();

}


int getCartesianCommand(CartesianPosition *position)
{

	return MyGetCartesianCommand(*position);

}

int getCartesianPosition(CartesianPosition *position)
{

	return MyGetCartesianPosition(*position);

}

int getAngularCommand(AngularPosition* actuators)
{

	return MyGetAngularCommand(*actuators);

}

int getAngularPosition(AngularPosition* actuators)
{

	return MyGetAngularPosition(*actuators);

}

int clearTrajectory()
{

	return MyEraseAllTrajectories();

}

int getGlobalTrajectoryInfo(TrajectoryFIFO* data)
{

	return MyGetGlobalTrajectoryInfo(*data);

}


char* LStrHandletoCharArray(LStrHandle string) {

	std::string cppString((char*)LStrBuf(*string), 0, LStrLen(*string));

	char result[SERIAL_LENGTH];

#ifdef _DLL

	strcpy_s(result, cppString.c_str());

#else

	strcpy(result, cppString.c_str());

#endif

	return result;

}

LStrHandle CharArraytoLStrHandle(char* arr) {

	std::string cppString(arr);

	LStrHandle result;

#ifdef _DLL

	result = (LStrHandle)DSNewHandle(sizeof(int32) + cppString.size() * sizeof(uChar));

#endif

	cppString.copy((char*)LStrBuf(*result), cppString.size());

	LStrLen(*result) = cppString.size();

	return result;

}