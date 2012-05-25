/*
 * KosmicTask.h
 */

#import <AppKit/AppKit.h>
#import <ScriptingBridge/ScriptingBridge.h>


@class KosmicTaskApplication, KosmicTaskApplication;



/*
 * Standard Suite
 */

// The application's top-level scripting object.
@interface KosmicTaskApplication : SBApplication

@property (copy, readonly) NSString *name;  // The name of the application.
@property (readonly) BOOL frontmost;  // Is this the frontmost (active) application?
@property (copy, readonly) NSString *version;  // The version of the application.

- (NSURL *) resultFileWithName:(NSString *)withName;  // A file suitable for returning a result. The file will be automatically deleted when the task ends. May also be used for temporary data storage for the lifetime of the task.

@end



/*
 * KosmicTask Suite
 */

// The application's top-level scripting object.
@interface KosmicTaskApplication (KosmicTaskSuite)

@end

