//
//  NSMutableArray_Extensions.h
//  PMUtility
//
//  Created by Dave Carlton on 07/20/11.
//  Copyright 2011 Polymicro Systems. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSMutableArray(PMExtension)

-(void)insertObjectsFromArray:(NSArray *)array atIndex:(NSInteger)index;

-(id)reverseObjects;

-(id)insertUniqueObjectsFromArray:(NSArray*)newArray atIndex:(NSInteger)index;
-(id)addUniqueObjectsFromArray:(NSArray*)newArray;

@end	//	NSMutableArray(PMExtension)

