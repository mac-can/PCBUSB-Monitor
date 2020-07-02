//
//  CANMessage.h
//  MacCAN Monitor
//
//  Created by Uwe Vogt on 18.08.13.
//  Copyright (c) 2013 UV Software. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CANMessage : NSObject{
    
    NSString *number;
    NSString *timestamp;
    NSString *identifier;
    NSString *type;
    NSString *data;
    NSString *ascii;
}

@property (retain) NSString *number;
@property (retain) NSString *timestamp;
@property (retain) NSString *identifier;
@property (retain) NSString *type;
@property (retain) NSString *data;
@property (retain) NSString *ascii;

@end
