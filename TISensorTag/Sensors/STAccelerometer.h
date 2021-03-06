//
//  STAccelerometer.h
//  TISensorTag
//
//  Created by Andre Muis on 11/14/13.
//  Copyright (c) 2013 Andre Muis. All rights reserved.
//

#import <CoreBluetooth/CoreBluetooth.h>
#import <Foundation/Foundation.h>

#import "STSensor.h"
#import "STSensorTagDelegate.h"

@class STAcceleration;

@interface STAccelerometer : STSensor

@property (readonly, strong, nonatomic) CBUUID *dataCharacteristicUUID;
@property (readwrite, strong, nonatomic) CBCharacteristic *dataCharacteristic;

@property (readonly, strong, nonatomic) CBUUID *configurationCharacteristicUUID;
@property (readwrite, strong, nonatomic) CBCharacteristic *configurationCharacteristic;

@property (readonly, strong, nonatomic) CBUUID *periodCharacteristicUUID;
@property (readwrite, strong, nonatomic) CBCharacteristic *periodCharacteristic;

@property (readonly, assign, nonatomic) BOOL configured;
@property (readwrite, assign, nonatomic) BOOL enabled;

- (id)initWithSensorTagDelegate: (id<STSensorTagDelegate>)sensorTagDelegate
            sensorTagPeripheral: (CBPeripheral *)sensorTagPeripheral;

- (void)sensorTagPeripheralDidUpdateValueForCharacteristic: (CBCharacteristic *)characteristic;
- (void)updateWithPeriodInMilliseconds: (int)periodInMilliseconds;

- (STAcceleration *)accelerationWithCharacteristicValue: (NSData *)characteristicValue;
- (STAcceleration *)smoothedAccelerationWithCharacteristicValue: (NSData *)characteristicValue;

@end
