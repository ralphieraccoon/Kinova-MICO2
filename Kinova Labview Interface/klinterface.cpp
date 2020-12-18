#include "pch.h"
#include "klinterface.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>


int robotStatus;

int(*MyInitAPI)();
int(*MyCloseAPI)();
int(*MySendBasicTrajectory)(TrajectoryPoint command);
int(*MyGetDevices)(KinovaDevice devices[MAX_KINOVA_DEVICE], int& result);
int(*MySetActiveDevice)(KinovaDevice device);
int(*MyMoveHome)();
int(*MyInitFingers)();
int(*MyGetCartesianCommand)(CartesianPosition&);

int open()
{

	HINSTANCE commandLayer_handle;

	commandLayer_handle = LoadLibrary(L"C:\\Users\\mcjssdcc\\source\\repos\\Kinova Labview Interface\\Debug\\CommandLayerWindows.dll");

	//We load the functions from the library (Under Windows, use GetProcAddress)
	MyInitAPI = (int(*)()) GetProcAddress(commandLayer_handle, "InitAPI");
	//MyCloseAPI = (int(*)()) GetProcAddress(commandLayer_handle, "CloseAPI");
	//MyMoveHome = (int(*)()) GetProcAddress(commandLayer_handle, "MoveHome");
	//MyInitFingers = (int(*)()) GetProcAddress(commandLayer_handle, "InitFingers");
	MyGetDevices = (int(*)(KinovaDevice devices[MAX_KINOVA_DEVICE], int& result)) GetProcAddress(commandLayer_handle, "GetDevices");
	//MySetActiveDevice = (int(*)(KinovaDevice devices)) GetProcAddress(commandLayer_handle, "SetActiveDevice");
	//MySendBasicTrajectory = (int(*)(TrajectoryPoint)) GetProcAddress(commandLayer_handle, "SendBasicTrajectory");
	//MyGetCartesianCommand = (int(*)(CartesianPosition&)) GetProcAddress(commandLayer_handle, "GetCartesianCommand");

	//Verify that all functions has been loaded correctly
	//if ((MyInitAPI == NULL) || (MyCloseAPI == NULL) || (MySendBasicTrajectory == NULL) ||
	//	(MyGetDevices == NULL) || (MySetActiveDevice == NULL) || (MyGetCartesianCommand == NULL) ||
	//	(MyMoveHome == NULL) || (MyInitFingers == NULL))

	//{
	//	return -1;
	//}
	//else
	//{
		return (*MyInitAPI)();
	//}

}

int getMaxDevices()

{

	return MAX_KINOVA_DEVICE;

}

int getDevices(KinovaDevice *devices)
{

	KinovaDevice list[MAX_KINOVA_DEVICE];

	int result = MyGetDevices(list, robotStatus);

	memcpy(devices, list, MAX_KINOVA_DEVICE);

	return result;

}