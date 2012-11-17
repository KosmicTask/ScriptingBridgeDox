/*
 * ASDictionary.h
 */

#import <AppKit/AppKit.h>
#import <ScriptingBridge/ScriptingBridge.h>


@class ASDictionaryExportStatus, ASDictionaryApplication;

enum ASDictionaryEFor {
	ASDictionaryEForPlainText = 'PTex',
	ASDictionaryEForSingleFileHTML = 'SHTM',
	ASDictionaryEForFrameBasedHTML = 'FHTM',
	ASDictionaryEForObjCAppscriptGlue = 'OCGl'
};
typedef enum ASDictionaryEFor ASDictionaryEFor;

enum ASDictionaryESty {
	ASDictionaryEStyAppleScript = 'AScr',
	ASDictionaryEStyPythonAppscript = 'PyAp',
	ASDictionaryEStyRubyAppscript = 'RbAp',
	ASDictionaryEStyObjCAppscript = 'OCAp'
};
typedef enum ASDictionaryESty ASDictionaryESty;



/*
 * ASDictionary Suite
 */

// A record containing the result of a single export operation.
@interface ASDictionaryExportStatus : SBObject

@property BOOL success;  // Was the dictionary successfully exported?
@property (copy) NSURL *source;  // The application or scripting addition source file.
@property (copy) NSURL *destination;  // The exported dictionary file/folder if the export succeeded, or 'missing value' if it failed.
@property (copy) NSString *errorMessage;  // An error description if the export failed, or 'missing value' if it succeeded.


@end



/*
 * Standard Suite
 */

@interface ASDictionaryApplication : SBApplication

- (void) run;  // Run the application.
- (void) open:(NSArray *)x;  // Open one or more application and/or scripting addition files.
- (void) quit;  // Quit the application.
- (NSArray *) export:(NSArray *)x to:(NSURL *)to usingFileFormats:(NSArray *)usingFileFormats usingStyles:(NSArray *)usingStyles compactingClasses:(BOOL)compactingClasses showingHiddenItems:(BOOL)showingHiddenItems exportingToSubfolders:(BOOL)exportingToSubfolders;  // Export application and/or scripting addition dictionaries as plain text and/or HTML files.

@end

