/*
 * AppleScriptRunner.h
 */

#import <AppKit/AppKit.h>
#import <ScriptingBridge/ScriptingBridge.h>


@class AppleScriptRunnerApplication;



/*
 * AppleScript Runner Suite
 */

// The application's top-level scripting object.
@interface AppleScriptRunnerApplication : SBApplication

@property (copy, readonly) NSString *name;  // The name of the application.
@property (readonly) BOOL frontmost;  // Is this the active application?
@property (copy, readonly) NSString *version;  // The version number of the application.

- (id) doScript:(NSString *)x;  // Execute an OSA script.

@end

