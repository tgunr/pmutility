//
//  NSNumber_Extensions.m
//  PMUtility
//
//  Created by Dave Carlton on 08/01/11.
//  Copyright 2011 Polymicro Systems. All rights reserved.
//

#import "NSNumber_Extensions.h"

@implementation NSNumber(PMSExtensions)

+(NSNumber*)zero
{	return @0;	}

-(NSString*)md5String
{	return [self.stringValue md5String];	}

-(NSNumber*)addToNumber:(NSNumber*)otherNum
{	return @(self.doubleValue + otherNum.doubleValue);	}

@end		//	NSNumber(StandardDigest)
