/*
 *  pmCFUtility.h
 *
 *  Created by PolyMicro Systems on 7/16/08.
 *  Copyright 2008 Polymicrosystems. All rights reserved.
 *
 */

#include <ApplicationServices/ApplicationServices.h>
#include <CoreFoundation/CoreFoundation.h>

#ifndef _pmsCFUtility

// Equivalent of macro in <AssertMacros.h>, without causing compiler warning:
// "'DebugAssert' is deprecated: first deprecated in OS X 10.8"
#ifndef AF_Require_noErr
       #define AF_Require_noErr(errorCode, exceptionLabel)                        \
          do {                                                                    \
              if (__builtin_expect(0 != (errorCode), 0)) {                        \
                  goto exceptionLabel;                                            \
              }                                                                   \
          } while (0)
#endif

extern OSStatus    FSPathSetXattr(UInt8 *pathText, CFStringRef inKeyName, CFStringRef inKeyValue);

extern CFStringRef FSPathCopyXattr(CFAllocatorRef inAllocator, UInt8 *pathText, CFStringRef inKeyName, OSStatus *outError) CF_RETURNS_RETAINED;

extern ssize_t     CFURLGetXattrSize(CFURLRef inURL, CFStringRef inKeyName);

extern ssize_t     FSPathGetXattrSize(UInt8 *pathText, CFStringRef inKeyName);

extern OSStatus CFURLSetXattr(CFURLRef inURL, CFStringRef inKeyName, CFStringRef inKeyValue);

extern CFStringRef CFURLCopyXattr(CFAllocatorRef inAllocator, CFURLRef inURL, CFStringRef inKeyName, OSStatus *outError) CF_RETURNS_RETAINED;

extern OSStatus FSSetXattr(FSRef *inLocation, CFStringRef inKeyName, CFStringRef inKeyValue);

extern ssize_t FSGetXattrSize(FSRef *inLocation, CFStringRef inKeyName);

extern CFStringRef FSCopyXattr(CFAllocatorRef inAllocator, FSRef *inLocation, CFStringRef inKeyName, OSStatus *outError) CF_RETURNS_RETAINED;

extern OSStatus          FSSetXattrProperty(CFAllocatorRef inAllocator, FSRef *inLocation, CFStringRef inKeyName, CFPropertyListRef inKeyValue);

extern CFPropertyListRef FSCopyXattrProperty(CFAllocatorRef inAllocator, FSRef *inLocation, CFStringRef inKeyName, OSStatus *outError) CF_RETURNS_RETAINED;

extern char *CFStringCreateCString(CFStringRef theString, CFStringEncoding theEncoding);

extern CFStringRef CFStringCreateFromCommandPipe(CFAllocatorRef inAllocator, CFURLRef inCommandURL, CFStringRef inCommandArgs, OSStatus *outError) CF_RETURNS_RETAINED;

extern CFStringRef CFBundleRunShellScript(CFAllocatorRef inAllocator, CFBundleRef inBundle, CFStringRef inScriptName, CFStringRef inScriptArgs, OSStatus *outError) CF_RETURNS_NOT_RETAINED;

//
// WARNING: The CFStringSpeak function leaks theWords of each call because no copy is made and
// it creates a speach channel that never gets destroyed, although it is reused, if no channel is specified.
//

OSErr CFStringSpeak(CFStringRef theWords, Boolean interrupt, SpeechChannel onChannel);

CFDateRef   CFURLCopyDateAccessed(CFAllocatorRef inAllocator, CFURLRef url, SInt32 *outError) CF_RETURNS_RETAINED;

CFDateRef   CFURLCopyDateCreated(CFAllocatorRef inAllocator, CFURLRef url, SInt32 *outError) CF_RETURNS_RETAINED;

CFDateRef   CFURLCopyDateModified(CFAllocatorRef inAllocator, CFURLRef url, SInt32 *outError) CF_RETURNS_RETAINED;

CFStringRef CFURLCopyUTI(CFAllocatorRef inAllocator, CFURLRef inURL, OSStatus *outError) CF_RETURNS_RETAINED;

Boolean     CFURLConfromsToUTIs(CFAllocatorRef inAllocator, CFURLRef testURL, CFArrayRef inUTIs, OSStatus *outError);

Boolean CFAbsoluteTimeBetweenTimes(CFAbsoluteTime lowTime, CFAbsoluteTime unknownTime, CFAbsoluteTime hiTime);


CFDataRef CFDataCreateMD5Digest(CFAllocatorRef inAllocator, CFDataRef inData) CF_RETURNS_RETAINED;

CFDataRef CFDataCreateSHA1Digest(CFAllocatorRef inAllocator, CFDataRef inData) CF_RETURNS_RETAINED;

CFDataRef CFStringCreateMD5Digest(CFAllocatorRef inAllocator, CFStringRef inString) CF_RETURNS_RETAINED;

CFDataRef CFStringCreateSHA1Digest(CFAllocatorRef inAllocator, CFStringRef inString) CF_RETURNS_RETAINED;

CFStringRef CFDataCreateHexString(CFAllocatorRef inAllocator, CFDataRef inData) CF_RETURNS_RETAINED;

CFDataRef   CFStringCreateDataForHex(CFAllocatorRef inAllocator, CFStringRef inHexString) CF_RETURNS_RETAINED;

void     statusCallbackPath(FSFileOperationRef fileOp, const char *currentItem, FSFileOperationStage stage, OSStatus error, CFDictionaryRef statusDictionary, void *info);

void     statusCallback(FSFileOperationRef fileOp, const FSRef *currentItem, FSFileOperationStage stage, OSStatus error, CFDictionaryRef statusDictionary, void *info);

OSStatus SetAsyncPathOpInMotion(Boolean copy, FSFileOperationRef fileOp, const char *sourcePath, const char *destDirPath, CFStringRef destName, OptionBits flags, FSPathFileOperationStatusProcPtr callback, CFTimeInterval statusChangeInterval, CFStringRef contextString);

OSStatus SetAsyncOpInMotion(Boolean copy, FSFileOperationRef fileOp, const FSRef *source, const FSRef *destDir, CFStringRef destName, OptionBits flags, FSFileOperationStatusProcPtr callback, CFTimeInterval statusChangeInterval, CFStringRef contextString);

OSStatus OperateByPath(Boolean copy, const char *sourcePath, const char *destPath, const char *destName, CFTimeInterval statusInterval, OptionBits options, Boolean async, CFStringRef contextString);

OSStatus OperateByRef(Boolean copy, const char *sourcePath, const char *destPath, const char *destName, CFTimeInterval statusInterval, OptionBits options, Boolean async, CFStringRef contextString);

#endif



