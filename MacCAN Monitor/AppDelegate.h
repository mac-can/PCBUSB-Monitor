//  SPDX-License-Identifier: BSD-2-Clause
//
//  MacCAN Monitor App for PCAN-USB Interfaces
//
//  Copyright (c) 2013-2021 Uwe Vogt, UV Software, Berlin (info@mac-can.com)
//  All rights reserved.
//
//  BSD 2-Clause "Simplified" License:
//  Redistribution and use in source and binary forms, with or without
//  modification, are permitted provided that the following conditions are met:
//  1. Redistributions of source code must retain the above copyright notice, this
//     list of conditions and the following disclaimer.
//  2. Redistributions in binary form must reproduce the above copyright notice,
//     this list of conditions and the following disclaimer in the documentation
//     and/or other materials provided with the distribution.
//
//  MacCAN-KvaserCAN IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
//  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
//  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
//  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
//  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
//  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
//  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
//  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
//  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
//  OF MacCAN-KvaserCAN, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
#import <Cocoa/Cocoa.h>
#import "Wrapper/PCBUSB.h"

#define TIME_ZERO	0
#define TIME_ABS	1
#define TIME_REL	2


@interface AppDelegate : NSObject <NSApplicationDelegate> {
    
    // PCAN Moni - main window
    IBOutlet NSArrayController *arrayController;
    IBOutlet NSTableView *tableView;
    IBOutlet id outputStatus;
    
    // Connect dialog - panel
    IBOutlet NSPanel *connectSheet;
    IBOutlet NSComboBox *comboInterface;
    IBOutlet NSComboBox *comboBaudrate;
    IBOutlet NSButton *checkboxLog;
    IBOutlet NSImageView *imageIcon;
    
    // Transmit dialog -panel
    IBOutlet NSPanel *transmitSheet;
    IBOutlet NSComboBox *comboMessage;
    IBOutlet NSTextField *textMessage;
    
    // CAN device interface
    TPCANHandle hDevice;
    UInt64 frameCounter;
    
    // Mother´s little helpers
    long indexInterface;
    long indexBaudrate;
    long modeTimestamp;
    bool firstTimestamp;
    UInt64 lastTimestamp;
    bool clearViewRequest;
    NSTimer *receiveTimer;
}

@property (assign) IBOutlet NSWindow *window;

@end
