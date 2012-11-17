/*
 * VMwareFusion.h
 */

#import <AppKit/AppKit.h>
#import <ScriptingBridge/ScriptingBridge.h>


@class VMwareFusionApplication, VMwareFusionDocument, VMwareFusionWindow, VMwareFusionDocument, VMwareFusionSnapshot;

enum VMwareFusionSaveOptions {
	VMwareFusionSaveOptionsYes = 'yes ' /* Save the file. */,
	VMwareFusionSaveOptionsNo = 'no  ' /* Do not save the file. */,
	VMwareFusionSaveOptionsAsk = 'ask ' /* Ask the user whether or not to save the file. */
};
typedef enum VMwareFusionSaveOptions VMwareFusionSaveOptions;

enum VMwareFusionPrintingErrorHandling {
	VMwareFusionPrintingErrorHandlingStandard = 'lwst' /* Standard PostScript error handling */,
	VMwareFusionPrintingErrorHandlingDetailed = 'lwdt' /* print a detailed report of PostScript errors */
};
typedef enum VMwareFusionPrintingErrorHandling VMwareFusionPrintingErrorHandling;

enum VMwareFusionPowerstate {
	VMwareFusionPowerstatePoweredOn = 'PsOn' /* powered on */,
	VMwareFusionPowerstatePoweredOff = 'PsOf' /* powered off */,
	VMwareFusionPowerstateSuspended = 'PsSu' /* suspended */
};
typedef enum VMwareFusionPowerstate VMwareFusionPowerstate;

enum VMwareFusionToolsrunningstatus {
	VMwareFusionToolsrunningstatusRunning = 'TRon' /* running */,
	VMwareFusionToolsrunningstatusOff = 'TRof' /* off */,
	VMwareFusionToolsrunningstatusScriptExecuting = 'TRse' /* script executing */,
	VMwareFusionToolsrunningstatusUnknown = 'TRuk' /* unknown */
};
typedef enum VMwareFusionToolsrunningstatus VMwareFusionToolsrunningstatus;

enum VMwareFusionToolsversionstatus {
	VMwareFusionToolsversionstatusInstalled = 'TVin' /* installed */,
	VMwareFusionToolsversionstatusUnmanaged = 'TVum' /* unmanaged */,
	VMwareFusionToolsversionstatusUnavailable = 'TVna' /* unavailable */,
	VMwareFusionToolsversionstatusUninstalled = 'TVni' /* uninstalled */,
	VMwareFusionToolsversionstatusOutdated = 'TVou' /* outdated */,
	VMwareFusionToolsversionstatusUnknown = 'TVuk' /* unknown */
};
typedef enum VMwareFusionToolsversionstatus VMwareFusionToolsversionstatus;



/*
 * Standard Suite
 */

// The application's top-level scripting object.
@interface VMwareFusionApplication : SBApplication

- (SBElementArray *) documents;
- (SBElementArray *) windows;

@property (copy, readonly) NSString *name;  // The name of the application.
@property (readonly) BOOL frontmost;  // Is this the active application?
@property (copy, readonly) NSString *version;  // The version number of the application.

- (id) open:(id)x;  // Open a document.
- (void) print:(id)x withProperties:(NSDictionary *)withProperties printDialog:(BOOL)printDialog;  // Print a document.
- (void) quitSaving:(VMwareFusionSaveOptions)saving;  // Quit the application.
- (BOOL) exists:(id)x;  // Verify that an object exists.

@end

// A document.
@interface VMwareFusionDocument : SBObject

@property (copy, readonly) NSString *name;  // Its name.
@property (readonly) BOOL modified;  // Has it been modified since the last save?
@property (copy, readonly) NSURL *file;  // Its location on disk, if it has one.

- (void) closeSaving:(VMwareFusionSaveOptions)saving savingIn:(NSURL *)savingIn;  // Close a document.
- (void) saveIn:(NSURL *)in_ as:(id)as;  // Save a document.
- (void) printWithProperties:(NSDictionary *)withProperties printDialog:(BOOL)printDialog;  // Print a document.
- (void) delete;  // Delete an object.
- (void) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Copy an object.
- (void) moveTo:(SBObject *)to;  // Move an object to a new location.
- (void) resumeForce:(BOOL)force;  // Resume a virtual machine
- (void) suspendForce:(BOOL)force;  // Suspend a virtual machine
- (void) powerOffForce:(BOOL)force;  // Power off a virtual machine
- (void) restartForce:(BOOL)force;  // Restart a virtual machine
- (void) pause;  // Pause a virtual machine
- (void) unpause;  // Unpause a virtual machine
- (void) enterUnity;  // Enter Unity mode
- (void) exitUnity;  // Exit Unity mode
- (void) takeSnapshotName:(NSString *)name notes:(NSString *)notes;  // Takes a new snapshot

@end

// A window.
@interface VMwareFusionWindow : SBObject

@property (copy, readonly) NSString *name;  // The title of the window.
- (NSInteger) id;  // The unique identifier of the window.
@property NSInteger index;  // The index of the window, ordered front to back.
@property NSRect bounds;  // The bounding rectangle of the window.
@property (readonly) BOOL closeable;  // Does the window have a close button?
@property (readonly) BOOL miniaturizable;  // Does the window have a minimize button?
@property BOOL miniaturized;  // Is the window minimized right now?
@property (readonly) BOOL resizable;  // Can the window be resized?
@property BOOL visible;  // Is the window visible right now?
@property (readonly) BOOL zoomable;  // Does the window have a zoom button?
@property BOOL zoomed;  // Is the window zoomed right now?
@property (copy, readonly) VMwareFusionDocument *document;  // The document whose contents are displayed in the window.

- (void) closeSaving:(VMwareFusionSaveOptions)saving savingIn:(NSURL *)savingIn;  // Close a document.
- (void) saveIn:(NSURL *)in_ as:(id)as;  // Save a document.
- (void) printWithProperties:(NSDictionary *)withProperties printDialog:(BOOL)printDialog;  // Print a document.
- (void) delete;  // Delete an object.
- (void) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Copy an object.
- (void) moveTo:(SBObject *)to;  // Move an object to a new location.
- (void) resumeForce:(BOOL)force;  // Resume a virtual machine
- (void) suspendForce:(BOOL)force;  // Suspend a virtual machine
- (void) powerOffForce:(BOOL)force;  // Power off a virtual machine
- (void) restartForce:(BOOL)force;  // Restart a virtual machine
- (void) pause;  // Pause a virtual machine
- (void) unpause;  // Unpause a virtual machine
- (void) enterUnity;  // Enter Unity mode
- (void) exitUnity;  // Exit Unity mode
- (void) takeSnapshotName:(NSString *)name notes:(NSString *)notes;  // Takes a new snapshot

@end



/*
 * VMware Fusion Suite
 */

// A virtual machine document
@interface VMwareFusionDocument (VMwareFusionSuite)

- (SBElementArray *) snapshots;

@property (readonly) BOOL paused;  // true if the virtual machine is paused
@property (copy, readonly) NSString *OSName;  // the name of the currently installed operating system
@property (copy) NSString *notes;  // notes
@property (readonly) VMwareFusionPowerstate powerState;  // the current power state
@property (readonly) BOOL Unity;  // true if the virtual machine is in Unity mode
@property (readonly) VMwareFusionToolsrunningstatus toolsRunningStatus;  // tools running status
@property (readonly) VMwareFusionToolsversionstatus toolsVersionStatus;  // tools version status

@end

// A snapshot.
@interface VMwareFusionSnapshot : SBObject

- (SBElementArray *) snapshots;

@property (copy) NSString *name;  // the name of the snapshot
@property (copy, readonly) NSDate *creationDate;  // the date on which the snapshot was taken
@property (copy) NSString *notes;  // notes
@property (readonly) VMwareFusionPowerstate powerState;  // power state of the snapshot
- (NSString *) id;  // the unique identifier

- (void) closeSaving:(VMwareFusionSaveOptions)saving savingIn:(NSURL *)savingIn;  // Close a document.
- (void) saveIn:(NSURL *)in_ as:(id)as;  // Save a document.
- (void) printWithProperties:(NSDictionary *)withProperties printDialog:(BOOL)printDialog;  // Print a document.
- (void) delete;  // Delete an object.
- (void) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Copy an object.
- (void) moveTo:(SBObject *)to;  // Move an object to a new location.
- (void) resumeForce:(BOOL)force;  // Resume a virtual machine
- (void) suspendForce:(BOOL)force;  // Suspend a virtual machine
- (void) powerOffForce:(BOOL)force;  // Power off a virtual machine
- (void) restartForce:(BOOL)force;  // Restart a virtual machine
- (void) pause;  // Pause a virtual machine
- (void) unpause;  // Unpause a virtual machine
- (void) enterUnity;  // Enter Unity mode
- (void) exitUnity;  // Exit Unity mode
- (void) takeSnapshotName:(NSString *)name notes:(NSString *)notes;  // Takes a new snapshot
- (void) restore;  // Restore a snapshot
- (void) keep;  // Keep an autosave snapshot

@end

