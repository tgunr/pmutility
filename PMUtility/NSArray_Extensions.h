#import <Foundation/Foundation.h>
#import "NSString_Extensions.h"

@interface NSArray(PMExtensions)

-(BOOL)containsObjectIdenticalTo:(id)object;


-(NSArray*)arrayOfURLsFromPaths;
-(NSArray*)arrayOfPathsFromURLs;

-(NSArray*)arrayOfPathsThatConformToUTIs:(NSArray*)theUTIs resultsAsURL:(BOOL)saveURLs;

@property (NS_NONATOMIC_IOSONLY, readonly, strong) id randomObject;

//@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSString *md5String;

@end	//	NSArray(PMExtensions)

