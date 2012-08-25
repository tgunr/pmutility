#import <Foundation/Foundation.h>
#import "NSString_Extensions.h"

@interface NSArray(PMExtensions)

-(BOOL)containsObjectIdenticalTo:(id)object;

-(NSArray*)arrayWithSubTrees;

-(NSArray*)arrayOfURLsFromPaths;
-(NSArray*)arrayOfPathsFromURLs;

-(NSArray*)arrayOfPathsThatConformToUTIs:(NSArray*)theUTIs resultsAsURL:(BOOL)saveURLs;

-(id)randomObject;

-(NSString*)md5String;

@end	//	NSArray(PMExtensions)

