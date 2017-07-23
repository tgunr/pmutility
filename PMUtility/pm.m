/*
 *  pm.m
 *
 *  Created by Dave Carlton on 10/12/09.
 *  Copyright 2009 PolyMicro Systems. All rights reserved.
 *
 */

#include <stdio.h>
#include <stdarg.h>
#include <sys/time.h>
#include "pm.h"

int				gDebugLevel = PMLogLevelError;
int				gVerboseIndex = 0;
Boolean			gVerboseStack[256];
UInt64			startTime = 0;

// PMLOGSetVerbose sets a new debug level
void PMLOG_SetVerbose(enum PMLOGLevel value) {
    gDebugLevel = value;
}

// PMLOGPushVerbose sets a new debug setting and saves the previous one
// Use this to reduce debug output inside loops etc.
void PMLOG_PushVerbose(enum PMLOGLevel value) {
	gVerboseStack[gVerboseIndex] = gDebugLevel;
	gVerboseIndex++;
	if (gVerboseIndex > 256)
		gVerboseIndex = 256;
	gDebugLevel = value;
}

// PMLOGPopVerbose restores the previous debug setting
void PMLOG_PopVerbose(void) {
	gVerboseIndex--;
	if (gVerboseIndex < 0)
		gVerboseIndex = 0;
	gDebugLevel = gVerboseStack[gVerboseIndex];
}

NSString * pmLogLevelString(int inLevel);
NSString * pmLogLevelString(int inLevel) {
    NSString *      level;
    switch (inLevel) {
        case PMLogLevelNone:
            level = @"";
            break;
        case PMLogLevelTest:
            level = @"PMTEST:";
            break;
        case PMLogLevelEmerg:
            level = @"PMEMERG:";
            break;
        case PMLogLevelAlert:
            level = @"PMALERT:";
            break;
        case PMLogLevelCritical:
            level = @"PMCRITICAL:";
            break;
        case PMLogLevelError:
            level = @"PMERROR:";
            break;
        case PMLogLevelWarning:
            level = @"PMWARNING:";
            break;
        case PMLogLevelNotice:
            level = @"PMNOTICE:";
            break;
        case PMLogLevelInfo:
            level = @"PMINFO:";
            break;
        case PMLogLevelDebug:
            level = @"PMDEBUG:";
            break;
        default:
            level = [NSString stringWithFormat: @"PMDEBUGLEVEL: %d", inLevel];
            break;
    }
    return level;
}

static NSString* 
pmLOGSelfFormat(id self) {
	if(self != nil)
	{
		return [NSString stringWithFormat:@"PMSELF:(%@)", self];
	}
	else
	{
		return [NSString stringWithFormat:@"PMNOSELF"];
	}
}

void pmLOGSELF(id myself) {
	NSString * finalFormat = pmLOGSelfFormat(myself);
	NSLog(@"%@",finalFormat);
}

void pmMSG(const char *function,  int inLevel, NSString * format, ...)
{
    if( (inLevel > gDebugLevel || inLevel == 0) &&  inLevel != PMLogLevelTest)
    {
		// The level is not high enough to be displayed, we're skipping this item.
		// inLevel = 0 = disabled          PMLOG(0, @"log, but disabled");
		// gDebugLevel = 1 = least verbose PMLOG(1, @"Routine log");
		// gDebugLevel = 7 = most verbose  PMLOG(5, @"Really detailed debug level");
        return;
    }
    else
    {
        NSString *level = pmLogLevelString(inLevel);
        NSString *finalFormat =  [NSString stringWithFormat:@"%@ %s: %@", level, function, format];
        
        va_list ap;
        va_start(ap, format);
        NSLogv(finalFormat, ap);
        va_end(ap);
    }
}

void pmLOG(const char *file, const char *function,  int inLevel, NSString * format, ...)
{
    if( inLevel >= gDebugLevel || inLevel == 0 )
    {
		// The level is not high enough to be displayed, we're skipping this item.
		// inLevel = 0 = disabled          PMLOG(0, @"log, but disabled");
		// gDebugLevel = 1 = least verbose PMLOG(1, @"Routine log");
		// gDebugLevel = 7 = most verbose  PMLOG(7, @"Really detailed debug level");
        return;
    }
    else
    {
        NSString *level = pmLogLevelString(inLevel);
		NSString *pathString = @(file);
        const char *fileString = [pathString.lastPathComponent cStringUsingEncoding: NSUTF8StringEncoding];
        NSString *finalFormat =  [NSString stringWithFormat:@"%@ %s: %s %@", level, fileString, function, format];
        
        va_list ap;
        va_start(ap, format);
        NSLogv(finalFormat, ap);
        va_end(ap);
    }
}

void pmERR(const char *file, const char *function, int err, NSString * format, ...) {
	NSString *pathString = @(file);
	const char *fileString = [pathString.lastPathComponent cStringUsingEncoding: NSUTF8StringEncoding];
	NSString *finalFormat =  [NSString stringWithFormat:@"PMERR %s: %s err: %x %@", fileString, function, err, format];
	
	va_list ap;
	va_start(ap, format);
	NSLogv(finalFormat, ap);
	va_end(ap);
	
}
