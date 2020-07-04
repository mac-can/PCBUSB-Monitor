//
//  MacCAN Monitor - CAN Monitor App for macOS
//
//  Copyright (C) 2013-2020  Uwe Vogt, UV Software, Berlin (info@mac-can.com)
//
//  This file is part of MacCAN Monitor.
//
//  MacCAN Monitor is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  MacCAN Monitor is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with MacCAN Monitor.  If not, see <https://www.gnu.org/licenses/>.
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
