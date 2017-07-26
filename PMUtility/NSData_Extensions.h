//
//  NSData_Extensions.h
//  PickADisk
//
//  Created by PolyMicro Systems on 10/6/08.
//  Copyright 2008 PolyMicro Systems. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface NSData(StandardDigest)

@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSString *hexString;

@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSData *md5Data;
@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSString *md5String;

@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSData *sha1Data;

@end
