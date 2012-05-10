/*
 * Flash.h
 */

#import <AppKit/AppKit.h>
#import <ScriptingBridge/ScriptingBridge.h>


@class FlashApplication;



/*
 * Standard Suite
 */

@interface FlashApplication : SBApplication

- (void) doScript:(NSString *)x;  // Play the specified Action.

@end

