/*
 *  pm.h
 *
 *  Created by Dave Carlton on 05/27/08.
 *  Copyright 2008 Polymicro Systems. All rights reserved.
 *
 */

#ifndef __PMSTUFF__
#define __PMSTUFF__

#import <Foundation/Foundation.h>

extern int				gDebugLevel;
extern int				gVerboseIndex;
extern Boolean			gVerboseStack[256];


#define NSLogF(a) \
do { NSString *logstring = @"%s: "; \
logstring = [logstring stringByAppendingString:a]; \
NSLog(logstring, __PRETTY_FUNCTION__); \
} while(0)

#define NSLogFunc	NSLog(@"%s", __PRETTY_FUNCTION__)
#define NSLOGVF(x)	if (gVerboseIndex > gDebugLevel) NSLog(@"%s: %s: %d", __PRETTY_FUNCTION__, x)

enum PMLOGLevel {
    PMLogLevelNone = 0,
    PMLogLevelTest,
    PMLogLevelEmerg,
    PMLogLevelAlert,
    PMLogLevelCritical,
    PMLogLevelError,
    PMLogLevelWarning,
    PMLogLevelNotice,
    PMLogLevelInfo,
    PMLogLevelDebug,
    PMLogLevelDebug1,
    PMLogLevelDebug2,
    PMLogLevelDebug3,
    };

void pmLOGSELF(id self, NSString * format, ...);
void pmLOG(const char *file, const char *function, int inLevel, NSString * format, ...);
void pmERR(const char *file, const char *function, int err, NSString * format, ...);
void pmMSG(const char *function,  int inLevel, NSString * format, ...);

//#define PMLOG(ARGS...) PM_LogInternal(__FILE__, __PRETTY_FUNCTION__, ## ARGS)
#define PMLOGSELF(...) pmLOGSELF(self, __VA_ARGS__)
#define PMLOG(...) pmLOG(__FILE__, __PRETTY_FUNCTION__, __VA_ARGS__)
#define PMERR(err, ...) if (err) pmERR(__FILE__, __PRETTY_FUNCTION__, (int)err, __VA_ARGS__)
#define PMSYM(symbol) pmLOG(__FILE__, __PRETTY_FUNCTION__, PMLogLevelTest, @#symbol ": %@", symbol)
#define PMNOTE(note) pmLOG(__FILE__, __PRETTY_FUNCTION__, PMLogLevelTest, @"NOTE: %@", note)
#define PMHERE pmLOG(__FILE__, __PRETTY_FUNCTION__, PMLogLevelTest, @"")
#define PMMSG(...) pmMSG(__PRETTY_FUNCTION__, PMLogLevelTest, __VA_ARGS__)
#define PMLOGWITHLEVEL(level, ...) pmLOG(__FILE__, __PRETTY_FUNCTION__, level, __VA_ARGS__)
#define PMLOGTEST(...) PMLOGWITHLEVEL(PMLogLevelTest, __VA_ARGS__)
#define PMLOGEMERG(...) PMLOGWITHLEVEL(PMLogLevelEmerg, __VA_ARGS__)
#define PMLOGALERT(...) PMLOGWITHLEVEL(PMLogLevelAlert, __VA_ARGS__)
#define PMLOGCRITICAL(...) PMLOGWITHLEVEL(PMLogLevelTest, __VA_ARGS__)
#define PMLOGERROR(...) PMLOGWITHLEVEL(PMLogLevelCritical, __VA_ARGS__)
#define PMLOGWARNING(...) PMLOGWITHLEVEL(PMLogLevelError, __VA_ARGS__)
#define PMLOGNOTICE(...) PMLOGWITHLEVEL(PMLogLevelWarning, __VA_ARGS__)
#define PMLOGINFO(...) PMLOGWITHLEVEL(PMLogLevelNotice, __VA_ARGS__)
#define PMLOGDEBUG(...) PMLOGWITHLEVEL(PMLogLevelDebug, __VA_ARGS__)

void pmLOGSetVerbose(int value);
void pmLOGPushVerbose(int value);
void pmLOGPopVerbose(void);

#define RELEASENIL(var) [var release]; var = 0;
#define IFCFRELEASE(symbol) if (symbol) CFRelease(symbol)
#endif