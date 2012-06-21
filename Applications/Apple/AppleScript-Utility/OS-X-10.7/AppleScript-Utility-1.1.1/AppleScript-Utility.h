/*
 * AppleScriptUtility.h
 */

#import <AppKit/AppKit.h>
#import <ScriptingBridge/ScriptingBridge.h>


@class AppleScriptUtilityApplication;

enum AppleScriptUtilityApplicationScriptsPositions {
	AppleScriptUtilityApplicationScriptsPositionsTop = 'top ' /* top */,
	AppleScriptUtilityApplicationScriptsPositionsBottom = 'bttm' /* bottom */
};
typedef enum AppleScriptUtilityApplicationScriptsPositions AppleScriptUtilityApplicationScriptsPositions;



/*
 * AppleScript Utility Suite
 */

// the AppleScript Utility application
@interface AppleScriptUtilityApplication : SBApplication

@property (copy) NSURL *defaultScriptEditor;  // the editor to be used to open scripts
@property BOOL GUIScriptingEnabled;  // Are GUI Scripting events currently being processed?
@property AppleScriptUtilityApplicationScriptsPositions applicationScriptsPosition;  // the position in the Script menu at which the application scripts are displayed
@property BOOL ScriptMenuEnabled;  // Is the Script menu installed in the menu bar?
@property BOOL showComputerScripts;  // Are the Computer scripts shown in the Script menu?

@end

