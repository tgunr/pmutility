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
} ;

void pmLOGSELF(id myself);
void pmLOG(const char *file, const char *function, int inLevel, NSString * format, ...);
void pmERR(const char *file, const char *function, int err, NSString * format, ...);
void pmMSG(const char *function,  int inLevel, NSString * format, ...);

//#define PMLOG(ARGS...) PM_LogInternal(__FILE__, __PRETTY_FUNCTION__, ## ARGS)
#define PMLOG_SELF pmLOGSELF(self)

#define PMLOG(...) pmLOG(__FILE__, __PRETTY_FUNCTION__, __VA_ARGS__)
#define PMLOGWITHLEVEL(level, ...) pmLOG(__FILE__, __PRETTY_FUNCTION__, level, __VA_ARGS__)

#define PMLOG_ERR(err, ...) if (err) pmERR(__FILE__, __PRETTY_FUNCTION__, (int)err, __VA_ARGS__)
#define PMLOG_SYM(symbol) pmLOG(__FILE__, __PRETTY_FUNCTION__, PMLogLevelTest, @#symbol ": %@", symbol)
#define PMLOG_VALUE(value) pmLOG(__FILE__, __PRETTY_FUNCTION__, PMLogLevelTest, @#value ": %d", (int)value)
#define PMLOG_UVALUE(value) pmLOG(__FILE__, __PRETTY_FUNCTION__, PMLogLevelTest, @#value ": %u", (unsigned)value)
#define PMLOG_NOTE(note) pmLOG(__FILE__, __PRETTY_FUNCTION__, PMLogLevelTest, @"NOTE: %@", note)
#define PMLOG_HERE pmLOG(__FILE__, __PRETTY_FUNCTION__, PMLogLevelTest, @"")
#define PMLOG_MSG(...) pmMSG(__PRETTY_FUNCTION__, PMLogLevelTest, __VA_ARGS__)

#define PMLOG_TEST(...) PMLOGWITHLEVEL(PMLogLevelTest, __VA_ARGS__)
#define PMLOG_EMERG(...) PMLOGWITHLEVEL(PMLogLevelEmerg, __VA_ARGS__)
#define PMLOG_ALERT(...) PMLOGWITHLEVEL(PMLogLevelAlert, __VA_ARGS__)
#define PMLOG_CRITICAL(...) PMLOGWITHLEVEL(PMLogLevelCritical, __VA_ARGS__)
#define PMLOG_ERROR(...) PMLOGWITHLEVEL(PMLogLevelError, __VA_ARGS__)
#define PMLOG_WARNING(...) PMLOGWITHLEVEL(PMLogLevelWarning, __VA_ARGS__)
#define PMLOG_NOTICE(...) PMLOGWITHLEVEL(PMLogLevelNotice, __VA_ARGS__)
#define PMLOG_INFO(...) PMLOGWITHLEVEL(PMLogLevelInfo, __VA_ARGS__)
#define PMLOG_DEBUG(...) PMLOGWITHLEVEL(PMLogLevelDebug, __VA_ARGS__)

void PMLOG_SetVerbose(enum PMLOGLevel value);
void PMLOG_PushVerbose(enum PMLOGLevel value);
void PMLOG_PopVerbose(void);

#define RELEASENIL(var) [var release]; var = 0;
#define IFCFRELEASE(symbol) if (symbol) CFRelease(symbol)
#endif