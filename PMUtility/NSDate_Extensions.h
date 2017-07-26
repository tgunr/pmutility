//
//  NSDate_Extensions.h
//
//  Created by PolyMicro Systems on 7/14/08.
//  Copyright 2008 PolyMicro Systems. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NSString_Extensions.h"

extern const	time_t	kTimeOneDayInSeconds;

@interface NSDate(PMSExtensions)

+(NSDate*)tomorrow;
+(NSDate*)yesterday;

-(BOOL)isBetweenStartDate:(NSDate*)startDate andEndDate:(NSDate*)endDate;
-(float)rankWithDate:(id)other withOptions:(NSMutableDictionary*)options;

-(NSString*)formatDateString:(NSString*)dateFormat useNatural:(BOOL)doNatural;
@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSString *naturalDateString;
@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSString *shorterDateString;
@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSString *longerDateString;

@end
