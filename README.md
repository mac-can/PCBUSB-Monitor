# CAN Monitor App for macOS®

_Copyright © 2013-2023 by UV Software, Berlin._

The MacCAN Monitor App is a little demo program to show the functionally of the PCBUSB library:
the [macOS® Library for PCAN-USB Interfaces](https://www.mac-can.com/).

## MacCAN Monitor App for PCAN-USB Interfaces

The program displays received CAN messages in a table view.
Furthermore it is possible to send single standard CAN messages with 0 to 8 data bytes.

**Limitations (Demo Program):**

- CAN channel and CAN bit rate must be chosen once the program is started; they cannot be changed afterwards.
- PCAN-USB FD devices can only be operated in CAN Classic mode (CAN 2.0).
- The size of the table view is limited to 1024 rows.
- The size of the trace file is limited to 100K frames.


### macOS® Library for PCAN-USB Interfaces

The dynamic library libPCBUSB is running under macOS 10.13 and later (Intel architecture and Apple silicon).
The API is almost compatible to PEAK´s PCANBasic DLL on Windows.
See the [MacCAN](https://www.mac-can.com/) website to learn more.

### Supported Devices

Only the following devices from PEAK-System Technik are supported:
- PCAN-USB (product code: IPEH-002021, IPEH-002022)
- PCAN-USB FD (product code: IPEH-004022)

### Required Library Version

The minimum required library version is v0.9 (Build 902 of June 25, 2020), but _Latest is Greatest_.

### Target Platform

- macOS 11.0 and later (Intel and Apple silicon)
- OS X 10.13 and later (Intel architecture only)

### Development Environment

#### macOS Ventura

- macOS Ventura (13.6.1) on a Mac mini (M1, 2020)
- Apple clang version 15.0.0 (clang-1500.0.40.1)
- Xcode Version 15.0.1 (15A507)

#### macOS Big Sur

- macOS Big Sur (11.7.10) on a MacBook Pro (2019)
- Apple clang version 13.0.0 (clang-1300.0.29.30)
- Xcode Version 13.2.1 (13C100)

#### macOS High Sierra

- macOS High Sierra (10.13.6) on a MacBook Pro (late 2011)
- Apple LLVM version 10.0.0 (clang-1000.11.45.5)
- Xcode Version 10.1 (10B61)

## Known Bugs and Caveats

- For a list of known bugs and caveats see tab [Issues](https://github.com/mac-can/PCBUSB-Monitor/issues) in the GitHub repo.
- For a list of known bugs and caveats in the underlying PCBUSB library read the documentation of the appropriated library version.
- PCAN-USB Pro FD devices are supported since version 0.10 of the PCBUSB library, _but only the first channel_ (CAN1).
- Apple´s M1 chip is supported since version 0.10.1 of the PCBUSB library (Universal macOS Binary).

## This and That

The PCBUSB library can be downloaded form its [GitHub repo](https://github.com/mac-can/PCBUSB-Library/releases) (binaries only).
Please note the copyright and license agreements.

### License

This work is licensed under the terms of the BSD 2-Clause "Simplified" License.

`SPDX-License-Identifier: BSD-2-Clause`

### Trademarks

- Mac and macOS are trademarks of Apple Inc., registered in the U.S. and other countries.
- PCAN is a registered trademark of PEAK-System Technik GmbH, Darmstadt.
- All other company, product and service names mentioned herein may be trademarks, registered trademarks, or service marks of their respective owners.

### Credits

- Toolbar icons by Oxygen Team (GNU Lesser General Public License)
- Apple M1 support by Sebastião Beirão (https://github.com/sebashb)

### Hazard Note

_If you connect your CAN device to a real CAN network when using this program, you might damage your application._

## Contact
mailto:info@mac-can.com \
https://www.mac-can.com
