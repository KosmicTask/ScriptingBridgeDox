/*
 * Automator.h
 */

#import <AppKit/AppKit.h>
#import <ScriptingBridge/ScriptingBridge.h>


@class AutomatorItem, AutomatorApplication, AutomatorColor, AutomatorDocument, AutomatorWindow, AutomatorAttributeRun, AutomatorCharacter, AutomatorParagraph, AutomatorText, AutomatorAttachment, AutomatorWord, AutomatorAutomatorAction, AutomatorRequiredResource, AutomatorSetting, AutomatorVariable, AutomatorWorkflow, AutomatorPrintSettings;

enum AutomatorSavo {
	AutomatorSavoAsk = 'ask ' /* Ask the user whether or not to save the file. */,
	AutomatorSavoNo = 'no  ' /* Do not save the file. */,
	AutomatorSavoYes = 'yes ' /* Save the file. */
};
typedef enum AutomatorSavo AutomatorSavo;

enum AutomatorWlev {
	AutomatorWlevIrreversible = 'irrv' /* irreversible */,
	AutomatorWlevNone = 'none' /* none */,
	AutomatorWlevReversible = 'rvbl' /* reversible */
};
typedef enum AutomatorWlev AutomatorWlev;

enum AutomatorEnum {
	AutomatorEnumStandard = 'lwst' /* Standard PostScript error handling */,
	AutomatorEnumDetailed = 'lwdt' /* print a detailed report of PostScript errors */
};
typedef enum AutomatorEnum AutomatorEnum;



/*
 * Standard Suite
 */

// A scriptable object.
@interface AutomatorItem : SBObject

@property (copy) NSDictionary *properties;  // All of the object's properties.

- (void) closeSaving:(AutomatorSavo)saving savingIn:(NSURL *)savingIn;  // Close an object.
- (void) delete;  // Delete an object.
- (void) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Copy object(s) and put the copies at a new location.
- (BOOL) exists;  // Verify if an object exists.
- (void) moveTo:(SBObject *)to;  // Move object(s) to a new location.
- (void) saveAs:(NSString *)as in:(NSURL *)in_;  // Save an object.

@end

// An application's top level scripting object.
@interface AutomatorApplication : SBApplication

- (SBElementArray *) documents;
- (SBElementArray *) windows;

@property (readonly) BOOL frontmost;  // Is this the frontmost (active) application?
@property (copy, readonly) NSString *name;  // The name of the application.
@property (copy, readonly) NSString *version;  // The version of the application.

- (AutomatorDocument *) open:(NSURL *)x;  // Open an object.
- (void) print:(NSURL *)x printDialog:(BOOL)printDialog withProperties:(AutomatorPrintSettings *)withProperties;  // Print an object.
- (void) quitSaving:(AutomatorSavo)saving;  // Quit an application.
- (void) add:(id)x to:(AutomatorWorkflow *)to atIndex:(NSInteger)atIndex;  // Add an Automator action or variable to a workflow
- (void) remove:(id)x;  // Remove an Automator action or variable from a workflow

@end

// A color.
@interface AutomatorColor : AutomatorItem


@end

// A document.
@interface AutomatorDocument : AutomatorItem

@property (readonly) BOOL modified;  // Has the document been modified since the last save?
@property (copy) NSString *name;  // The document's name.
@property (copy) NSString *path;  // The document's path.


@end

// A window.
@interface AutomatorWindow : AutomatorItem

@property NSRect bounds;  // The bounding rectangle of the window.
@property (readonly) BOOL closeable;  // Whether the window has a close box.
@property (copy, readonly) AutomatorDocument *document;  // The document whose contents are being displayed in the window.
@property (readonly) BOOL floating;  // Whether the window floats.
- (NSInteger) id;  // The unique identifier of the window.
@property NSInteger index;  // The index of the window, ordered front to back.
@property (readonly) BOOL miniaturizable;  // Whether the window can be miniaturized.
@property BOOL miniaturized;  // Whether the window is currently miniaturized.
@property (readonly) BOOL modal;  // Whether the window is the application's current modal window.
@property (copy) NSString *name;  // The full title of the window.
@property (readonly) BOOL resizable;  // Whether the window can be resized.
@property (readonly) BOOL titled;  // Whether the window has a title bar.
@property BOOL visible;  // Whether the window is currently visible.
@property (readonly) BOOL zoomable;  // Whether the window can be zoomed.
@property BOOL zoomed;  // Whether the window is currently zoomed.


@end



/*
 * Text Suite
 */

// This subdivides the text into chunks that all have the same attributes.
@interface AutomatorAttributeRun : AutomatorItem

- (SBElementArray *) attachments;
- (SBElementArray *) attributeRuns;
- (SBElementArray *) characters;
- (SBElementArray *) paragraphs;
- (SBElementArray *) words;

@property (copy) NSColor *color;  // The color of the first character.
@property (copy) NSString *font;  // The name of the font of the first character.
@property NSInteger size;  // The size in points of the first character.


@end

// This subdivides the text into characters.
@interface AutomatorCharacter : AutomatorItem

- (SBElementArray *) attachments;
- (SBElementArray *) attributeRuns;
- (SBElementArray *) characters;
- (SBElementArray *) paragraphs;
- (SBElementArray *) words;

@property (copy) NSColor *color;  // The color of the first character.
@property (copy) NSString *font;  // The name of the font of the first character.
@property NSInteger size;  // The size in points of the first character.


@end

// This subdivides the text into paragraphs.
@interface AutomatorParagraph : AutomatorItem

- (SBElementArray *) attachments;
- (SBElementArray *) attributeRuns;
- (SBElementArray *) characters;
- (SBElementArray *) paragraphs;
- (SBElementArray *) words;

@property (copy) NSColor *color;  // The color of the first character.
@property (copy) NSString *font;  // The name of the font of the first character.
@property NSInteger size;  // The size in points of the first character.


@end

// Rich (styled) text
@interface AutomatorText : AutomatorItem

- (SBElementArray *) attachments;
- (SBElementArray *) attributeRuns;
- (SBElementArray *) characters;
- (SBElementArray *) paragraphs;
- (SBElementArray *) words;

@property (copy) NSColor *color;  // The color of the first character.
@property (copy) NSString *font;  // The name of the font of the first character.
@property NSInteger size;  // The size in points of the first character.


@end

// Represents an inline text attachment.  This class is used mainly for make commands.
@interface AutomatorAttachment : AutomatorText

@property (copy) NSString *fileName;  // The path to the file for the attachment


@end

// This subdivides the text into words.
@interface AutomatorWord : AutomatorItem

- (SBElementArray *) attachments;
- (SBElementArray *) attributeRuns;
- (SBElementArray *) characters;
- (SBElementArray *) paragraphs;
- (SBElementArray *) words;

@property (copy) NSColor *color;  // The color of the first character.
@property (copy) NSString *font;  // The name of the font of the first character.
@property NSInteger size;  // The size in points of the first character.


@end



/*
 * Automator Suite
 */

// The Automator application
@interface AutomatorApplication (AutomatorSuite)

- (SBElementArray *) AutomatorActions;
- (SBElementArray *) variables;
- (SBElementArray *) workflows;

@end

// A single step in a workflow
@interface AutomatorAutomatorAction : AutomatorItem

- (SBElementArray *) requiredResources;
- (SBElementArray *) settings;

@property (copy, readonly) NSString *bundleId;  // The bundle identifier for the action
@property (copy, readonly) NSArray *category;  // The category that contains the action
@property (copy) NSString *comment;  // The comment for the name of the action
@property BOOL enabled;  // Is the action enabled?
@property (copy, readonly) NSString *executionErrorMessage;  // The text error message generated by execution of the action
@property (readonly) NSInteger executionErrorNumber;  // The numeric error code generated by execution of the action
@property (copy, readonly) id executionResult;  // The result of the action, passed as input to the next action
@property (copy, readonly) NSString *iconName;  // The icon name of the action
- (NSString *) id;  // The unique identifier for the action
@property BOOL ignoresInput;  // Shall the action ignore its input when it is run?
@property NSInteger index;  // The index of the action
@property (copy, readonly) NSArray *inputTypes;  // The input types accepted by the action
@property (copy, readonly) NSArray *keywords;  // The keywords that describe the action
@property (copy, readonly) NSString *name;  // The localized name of the action
@property (copy, readonly) NSArray *outputTypes;  // The output types produced by the action
@property (copy, readonly) AutomatorWorkflow *parentWorkflow;  // The workflow that contains the action
@property (copy, readonly) NSURL *path;  // The path of the file that contains the action
@property BOOL showActionWhenRun;  // Shall the action show its user interface when it is run?
@property (copy, readonly) NSArray *targetApplication;  // The application with which the action communicates
@property (copy, readonly) NSString *version;  // The version of the action
@property (copy, readonly) NSString *warningAction;  // The action suggested by the warning, if any
@property (readonly) AutomatorWlev warningLevel;  // The level of the warning, increasing in likelihood of data loss
@property (copy, readonly) NSString *warningMessage;  // The message that accompanies the warning, if any


@end

// A resource required for proper operation of the action
@interface AutomatorRequiredResource : AutomatorItem

@property (copy, readonly) NSString *kind;  // The kind of required resource
@property (copy, readonly) NSString *name;  // The name of the required resource
@property (copy, readonly) NSString *resource;  // The specification of the required resource
@property (readonly) NSInteger version;  // The minimum acceptable version of the required resource


@end

// A named value
@interface AutomatorSetting : AutomatorItem

@property (copy, readonly) id defaultValue;  // The default value of the setting
@property (copy, readonly) NSString *name;  // The name of the setting
@property (copy) id value;  // The value of the setting


@end

// A variable used by the workflow.
@interface AutomatorVariable : AutomatorItem

@property (copy) NSString *name;  // The name of the variable
@property (readonly) BOOL settable;  // Are the name and value of the variable settable?
@property (copy) id value;  // The value of the variable


@end

// A series of actions stored in a file
@interface AutomatorWorkflow : AutomatorDocument

- (SBElementArray *) AutomatorActions;
- (SBElementArray *) variables;

@property (copy, readonly) AutomatorAutomatorAction *currentAction;  // The current or most recent action of the workflow
@property (copy, readonly) NSString *executionErrorMessage;  // The text error message generated by the most recent execution
@property (readonly) NSInteger executionErrorNumber;  // The numeric error code generated by the most recent execution
@property (copy, readonly) NSString *executionId;  // The identifier of the current or most recent execution
@property (copy, readonly) id executionResult;  // The result of the most recent execution; the output of the last action of that execution
@property (copy, readonly) NSString *name;  // The name of the workflow

- (id) execute;  // Execute the workflow

@end



/*
 * Type Definitions
 */

@interface AutomatorPrintSettings : SBObject

@property NSInteger copies;  // the number of copies of a document to be printed
@property BOOL collating;  // Should printed copies be collated?
@property NSInteger startingPage;  // the first page of the document to be printed
@property NSInteger endingPage;  // the last page of the document to be printed
@property NSInteger pagesAcross;  // number of logical pages laid across a physical page
@property NSInteger pagesDown;  // number of logical pages laid out down a physical page
@property (copy) NSDate *requestedPrintTime;  // the time at which the desktop printer should print the document
@property AutomatorEnum errorHandling;  // how errors are handled
@property (copy) NSString *faxNumber;  // for fax number
@property (copy) NSString *targetPrinter;  // for target printer

- (void) closeSaving:(AutomatorSavo)saving savingIn:(NSURL *)savingIn;  // Close an object.
- (void) delete;  // Delete an object.
- (void) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Copy object(s) and put the copies at a new location.
- (BOOL) exists;  // Verify if an object exists.
- (void) moveTo:(SBObject *)to;  // Move object(s) to a new location.
- (void) saveAs:(NSString *)as in:(NSURL *)in_;  // Save an object.

@end

