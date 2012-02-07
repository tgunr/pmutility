/*
 *  pm.h
 *
 *  Created by Dave Carlton on 05/27/08.
 *  Copyright 2008 Polymicro Systems. All rights reserved.
 *
 */
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

void pmLOGSELF(id self, NSString * format, ...);
void pmLOG(const char *file, const char *function, int inLevel, NSString * format, ...);
void pmERR(const char *file, const char *function, int err, NSString * format, ...);
void pmMSG(const char *function,  int inLevel, NSString * format, ...);

//#define PMLOG(ARGS...) PM_LogInternal(__FILE__, __PRETTY_FUNCTION__, ## ARGS)
#define PMLOG(...) pmLOG(__FILE__, __PRETTY_FUNCTION__, __VA_ARGS__)
#define PMERR(err, ...) if (err) pmERR(__FILE__, __PRETTY_FUNCTION__, (int)err, __VA_ARGS__)
#define PMSYM(symbol) pmLOG(1, @#symbol ": %@", symbol)
#define PMNOTE(note) pmLOG(1, note)
#define PMHERE pmLOG(__FILE__, __PRETTY_FUNCTION__, 1, @"")
#define PMMSG(...) pmMSG(__PRETTY_FUNCTION__, __VA_ARGS__)

#define RELEASENIL(var) [var release]; var = 0;

void pmLOGSetVerbose(int value);
void pmLOGPushVerbose(int value);
void pmLOGPopVerbose(void);
