/** @file
  Defined the platform specific device path which will be filled to
  ConIn/ConOut variables.

Copyright (c) 2019, Hewlett Packard Enterprise Development LP. All rights reserved.<BR>
Copyright (c) 2015, Intel Corporation. All rights reserved.<BR>

SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include "PlatformBootManager.h"

//
// Platform specific serial device path
//
SERIAL_CONSOLE_DEVICE_PATH  gSerialConsoleDevicePath0 = {
  {
    { HARDWARE_DEVICE_PATH,  HW_VENDOR_DP,                   DP_NODE_LEN (VENDOR_DEVICE_PATH) },
    EFI_SERIAL_DXE_GUID  // Use the driver's GUID
  },
  {
    { MESSAGING_DEVICE_PATH, MSG_UART_DP,                    DP_NODE_LEN (UART_DEVICE_PATH) },
    0,                  // Reserved
    115200,             // BaudRate
    8,                  // DataBits
    1,                  // Parity
    1                   // StopBits
  },
  {
    { MESSAGING_DEVICE_PATH, MSG_VENDOR_DP,                  DP_NODE_LEN (VENDOR_DEVICE_PATH) },
    EFI_TTY_TERM_GUID
  },
  { END_DEVICE_PATH_TYPE,  END_ENTIRE_DEVICE_PATH_SUBTYPE, DP_NODE_LEN (EFI_DEVICE_PATH_PROTOCOL) }
};

//
// Predefined platform default console device path
//
PLATFORM_CONSOLE_CONNECT_ENTRY  gPlatformConsole[] = {
  {
    (EFI_DEVICE_PATH_PROTOCOL *)&gSerialConsoleDevicePath0,
    CONSOLE_OUT | CONSOLE_IN
  },
  {
    NULL,
    0
  }
};
