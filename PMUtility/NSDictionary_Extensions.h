//
//  NSDictionary_Extensions.h
//  PMUtility
//
//  Created by Dave Carlton on 08/01/11.
//  Copyright 2011 Polymicro Systems. All rights reserved.
//


#import <Foundation/Foundation.h>

@interface NSDictionary(PMSExtensions)

//@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSString *md5String;

@end	//	NSDictionary(StandardDigest)

@interface NSMutableDictionary(PMSExtensions)

-(void)addEntryFromDictionary:(NSDictionary*)otherDict forKey:(id)otherKey;

@end	//	NSMutableDictionary(PMSExtensions)


