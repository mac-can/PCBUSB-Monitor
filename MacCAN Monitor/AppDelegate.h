//
//  AppDelegate.h
//  MacCAN Monitor
//
//  Created by Uwe Vogt on 18.08.13.
//  Copyright (c) 2013 UV Software. All rights reserved.
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
