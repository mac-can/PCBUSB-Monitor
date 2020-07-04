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
