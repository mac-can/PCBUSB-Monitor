//
//  PCBUSB.c
//  MacCAN Monitor
//  Wrapper for libPCBUSB
//
//  Created by Uwe Vogt on 18.08.13.
//  Copyright (c) 2013 UV Software. All rights reserved.
//

#include "PCBUSB.h"

#include <stdio.h>
#include <dlfcn.h>
#include <string.h>

typedef TPCANStatus (*CAN_Initialize_t)(TPCANHandle Channel, TPCANBaudrate Btr0Btr1, TPCANType HwType, DWORD IOPort, WORD Interrupt);
typedef TPCANStatus (*CAN_Uninitialize_t)(TPCANHandle Channel);
typedef TPCANStatus (*CAN_Reset_t)(TPCANHandle Channel);
typedef TPCANStatus (*CAN_GetStatus_t)(TPCANHandle Channel);
typedef TPCANStatus (*CAN_Read_t)(TPCANHandle Channel, TPCANMsg* MessageBuffer, TPCANTimestamp* TimestampBuffer);
typedef TPCANStatus (*CAN_Write_t)(TPCANHandle Channel, TPCANMsg* MessageBuffer);
typedef TPCANStatus (*CAN_FilterMessages_t)(TPCANHandle Channel, DWORD FromID, DWORD ToID, TPCANMode Mode);
typedef TPCANStatus (*CAN_GetValue_t)(TPCANHandle Channel, TPCANParameter Parameter, void* Buffer, DWORD BufferLength);
typedef TPCANStatus (*CAN_SetValue_t)(TPCANHandle Channel, TPCANParameter Parameter, void* Buffer, DWORD BufferLength);
typedef TPCANStatus (*CAN_GetErrorText_t)(TPCANStatus Error, WORD Language, char* Buffer);

static CAN_Initialize_t _CAN_Initialize = NULL;
static CAN_Uninitialize_t _CAN_Uninitialize = NULL;
static CAN_Reset_t _CAN_Reset = NULL;
static CAN_GetStatus_t _CAN_GetStatus = NULL;
static CAN_Read_t _CAN_Read = NULL;
static CAN_Write_t _CAN_Write = NULL;
static CAN_FilterMessages_t _CAN_FilterMessages = NULL;
static CAN_GetValue_t _CAN_GetValue = NULL;
static CAN_SetValue_t _CAN_SetValue = NULL;
static CAN_GetErrorText_t _CAN_GetErrorText = NULL;

static void *hLibrary = NULL;

static int LoadLibrary(void)
{
    if(!hLibrary) {
        hLibrary = dlopen("libPCBUSB.dylib", RTLD_LAZY);
        if(!hLibrary)
            return -1;
        if((_CAN_Initialize = (CAN_Initialize_t)dlsym(hLibrary, "CAN_Initialize")) == NULL)
            goto err;
        if((_CAN_Uninitialize = (CAN_Uninitialize_t)dlsym(hLibrary, "CAN_Uninitialize")) == NULL)
            goto err;
        if((_CAN_Reset = (CAN_Reset_t)dlsym(hLibrary, "CAN_Reset")) == NULL)
            goto err;
        if((_CAN_GetStatus = (CAN_GetStatus_t)dlsym(hLibrary, "CAN_GetStatus")) == NULL)
            goto err;
        if((_CAN_Read = (CAN_Read_t)dlsym(hLibrary, "CAN_Read")) == NULL)
            goto err;
        if((_CAN_Write = (CAN_Write_t)dlsym(hLibrary, "CAN_Write")) == NULL)
            goto err;
        if((_CAN_FilterMessages = (CAN_FilterMessages_t)dlsym(hLibrary, "CAN_FilterMessages")) == NULL)
            goto err;
        if((_CAN_GetValue = (CAN_GetValue_t)dlsym(hLibrary, "CAN_GetValue")) == NULL)
            goto err;
        if((_CAN_SetValue = (CAN_SetValue_t)dlsym(hLibrary, "CAN_SetValue")) == NULL)
            goto err;
        if((_CAN_GetErrorText = (CAN_GetErrorText_t)dlsym(hLibrary, "CAN_GetErrorText")) == NULL)
            goto err;
    }
    return 0;
err:
    _CAN_Initialize = NULL;
    _CAN_Uninitialize = NULL;
    _CAN_Reset = NULL;
    _CAN_GetStatus = NULL;
    _CAN_Read = NULL;
    _CAN_Write = NULL;
    _CAN_FilterMessages = NULL;
    _CAN_GetValue = NULL;
    _CAN_SetValue = NULL;
    _CAN_GetErrorText = NULL;
    dlclose(hLibrary);
    return -1;
}

TPCANStatus CAN_Initialize(TPCANHandle Channel, TPCANBaudrate Btr0Btr1, TPCANType HwType, DWORD IOPort, WORD Interrupt)
{
    if(LoadLibrary() != 0)
        return PCAN_ERROR_NODRIVER;
	if(_CAN_Initialize)
		return _CAN_Initialize(Channel, Btr0Btr1, HwType, IOPort, Interrupt);
	else
		return PCAN_ERROR_UNKNOWN;
}

TPCANStatus CAN_Uninitialize(TPCANHandle Channel)
{
    //if(LoadLibrary() != 0)
    //    return PCAN_ERROR_NODRIVER;
	if(_CAN_Uninitialize)
		return _CAN_Uninitialize(Channel);
	else
		return PCAN_ERROR_UNKNOWN;
}

TPCANStatus CAN_Reset(TPCANHandle Channel)
{
    if(LoadLibrary() != 0)
        return PCAN_ERROR_NODRIVER;
	if(_CAN_Reset)
		return _CAN_Reset(Channel);
	else
		return PCAN_ERROR_UNKNOWN;
}

TPCANStatus CAN_GetStatus(TPCANHandle Channel)
{
    if(LoadLibrary() != 0)
        return PCAN_ERROR_NODRIVER;
	if(_CAN_GetStatus)
		return _CAN_GetStatus(Channel);
	else
		return PCAN_ERROR_UNKNOWN;
}

TPCANStatus CAN_Read(TPCANHandle Channel, TPCANMsg* MessageBuffer, TPCANTimestamp* TimestampBuffer)
{
    if(LoadLibrary() != 0)
        return PCAN_ERROR_NODRIVER;
	if(_CAN_Read)
		return _CAN_Read(Channel, MessageBuffer, TimestampBuffer);
	else
		return PCAN_ERROR_UNKNOWN;
}

TPCANStatus CAN_Write(TPCANHandle Channel, TPCANMsg* MessageBuffer)
{
    if(LoadLibrary() != 0)
        return PCAN_ERROR_NODRIVER;
	if(_CAN_Write)
		return _CAN_Write(Channel, MessageBuffer);
	else
		return PCAN_ERROR_UNKNOWN;
}

TPCANStatus CAN_FilterMessages(TPCANHandle Channel, DWORD FromID, DWORD ToID, TPCANMode Mode)
{
    if(LoadLibrary() != 0)
        return PCAN_ERROR_NODRIVER;
	if(_CAN_FilterMessages)
		return _CAN_FilterMessages(Channel, FromID, ToID, Mode);
	else
		return PCAN_ERROR_UNKNOWN;
}

TPCANStatus CAN_GetValue(TPCANHandle Channel, TPCANParameter Parameter, void* Buffer, DWORD BufferLength)
{
    if(LoadLibrary() != 0)
        return PCAN_ERROR_NODRIVER;
	if(_CAN_GetValue)
		return _CAN_GetValue(Channel, Parameter, Buffer, BufferLength);
	else
		return PCAN_ERROR_UNKNOWN;
}

TPCANStatus CAN_SetValue(TPCANHandle Channel, TPCANParameter Parameter, void* Buffer, DWORD BufferLength)
{
    if(LoadLibrary() != 0)
        return PCAN_ERROR_NODRIVER;
	if(_CAN_SetValue)
		return _CAN_SetValue(Channel, Parameter, Buffer, BufferLength);
	else
		return PCAN_ERROR_UNKNOWN;
}

TPCANStatus CAN_GetErrorText(TPCANStatus Error, WORD Language, char* Buffer)
{
    if(LoadLibrary() != 0) {
        if(Buffer)
            strcpy(Buffer, "PCANUSB library could not be loaded");
        return PCAN_ERROR_NODRIVER;
    }
	if(_CAN_GetErrorText)
		return _CAN_GetErrorText(Error, Language, Buffer);
	else
		return PCAN_ERROR_UNKNOWN;
}

