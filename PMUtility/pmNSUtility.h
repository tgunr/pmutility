//
//  pmNSUtility.h
//  PDFGarden
//
//  Created by Dave Carlton on 09/24/10.
//  Copyright 2010 PolyMicro Systems. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface PMUtility : NSObject {
	
}

@end

BOOL			BooleanToBOOL		(Boolean		inBoolean);
Boolean			BOOLToBoolean		(BOOL			inBool);

CF_IMPLICIT_BRIDGING_ENABLED

CFBooleanRef	BooleanToCFBoolean	(Boolean		inBoolean);
CFBooleanRef	BOOLToCFBoolean		(BOOL			inBool);

CF_IMPLICIT_BRIDGING_DISABLED

BOOL			CFBooleanToBOOL		(CFBooleanRef	inCFBoolean);
Boolean			CFBooleanToBoolean	(CFBooleanRef	inCFBoolean);
CFBooleanRef	NSNumberToCFBoolean	(NSNumber*		inNSNum) CF_RETURNS_NOT_RETAINED;
NSNumber*		CFBooleanToNSNumber	(CFBooleanRef	inCFBoolean);

