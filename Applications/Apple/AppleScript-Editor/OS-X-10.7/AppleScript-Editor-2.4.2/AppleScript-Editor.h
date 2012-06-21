/*
 * AppleScriptEditor.h
 */

#import <AppKit/AppKit.h>
#import <ScriptingBridge/ScriptingBridge.h>


@class AppleScriptEditorItem, AppleScriptEditorApplication, AppleScriptEditorColor, AppleScriptEditorDocument, AppleScriptEditorWindow, AppleScriptEditorAttributeRun, AppleScriptEditorCharacter, AppleScriptEditorParagraph, AppleScriptEditorText, AppleScriptEditorAttachment, AppleScriptEditorWord, AppleScriptEditorObjectClass, AppleScriptEditorInsertionPoint, AppleScriptEditorLanguage, AppleScriptEditorSelectionObject, AppleScriptEditorPrintSettings;

enum AppleScriptEditorSavo {
	AppleScriptEditorSavoAsk = 'ask ' /* Ask the user whether or not to save the file. */,
	AppleScriptEditorSavoNo = 'no  ' /* Do not save the file. */,
	AppleScriptEditorSavoYes = 'yes ' /* Save the file. */
};
typedef enum AppleScriptEditorSavo AppleScriptEditorSavo;

enum AppleScriptEditorEnum {
	AppleScriptEditorEnumStandard = 'lwst' /* Standard PostScript error handling */,
	AppleScriptEditorEnumDetailed = 'lwdt' /* print a detailed report of PostScript errors */
};
typedef enum AppleScriptEditorEnum AppleScriptEditorEnum;



/*
 * Standard Suite
 */

// A scriptable object.
@interface AppleScriptEditorItem : SBObject

@property (copy) NSDictionary *properties;  // All of the object's properties.

- (void) closeSaving:(AppleScriptEditorSavo)saving savingIn:(NSURL *)savingIn;  // Close an object.
- (void) delete;  // Delete an object.
- (void) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Copy object(s) and put the copies at a new location.
- (BOOL) exists;  // Verify if an object exists.
- (void) moveTo:(SBObject *)to;  // Move object(s) to a new location.
- (void) saveAs:(NSString *)as in:(NSURL *)in_;  // Save an object.
- (void) checkSyntax;  // Check the syntax of a document.
- (BOOL) compile;  // Compile the script of a document.
- (id) execute;  // Execute the document.
- (void) saveAs:(NSString *)as in:(NSURL *)in_ runOnly:(BOOL)runOnly startupScreen:(BOOL)startupScreen stayOpen:(BOOL)stayOpen;  // Save an object.

@end

// An application's top level scripting object.
@interface AppleScriptEditorApplication : SBApplication

- (SBElementArray *) documents;
- (SBElementArray *) windows;

@property (readonly) BOOL frontmost;  // Is this the frontmost (active) application?
@property (copy, readonly) NSString *name;  // The name of the application.
@property (copy, readonly) NSString *version;  // The version of the application.

- (AppleScriptEditorDocument *) open:(NSURL *)x;  // Open an object.
- (void) print:(NSURL *)x printDialog:(BOOL)printDialog withProperties:(AppleScriptEditorPrintSettings *)withProperties;  // Print an object.
- (void) quitSaving:(AppleScriptEditorSavo)saving;  // Quit an application.

@end

// A color.
@interface AppleScriptEditorColor : AppleScriptEditorItem


@end

// A document.
@interface AppleScriptEditorDocument : AppleScriptEditorItem

@property (readonly) BOOL modified;  // Has the document been modified since the last save?
@property (copy) NSString *name;  // The document's name.
@property (copy) NSString *path;  // The document's path.


@end

// A window.
@interface AppleScriptEditorWindow : AppleScriptEditorItem

@property NSRect bounds;  // The bounding rectangle of the window.
@property (readonly) BOOL closeable;  // Whether the window has a close box.
@property (copy, readonly) AppleScriptEditorDocument *document;  // The document whose contents are being displayed in the window.
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
@interface AppleScriptEditorAttributeRun : AppleScriptEditorItem

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
@interface AppleScriptEditorCharacter : AppleScriptEditorItem

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
@interface AppleScriptEditorParagraph : AppleScriptEditorItem

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
@interface AppleScriptEditorText : AppleScriptEditorItem

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
@interface AppleScriptEditorAttachment : AppleScriptEditorText

@property (copy) NSString *fileName;  // The path to the file for the attachment


@end

// This subdivides the text into words.
@interface AppleScriptEditorWord : AppleScriptEditorItem

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
 * Script Editor Suite
 */

// Script Editor's top level scripting object.
@interface AppleScriptEditorApplication (ScriptEditorSuite)

- (SBElementArray *) objectClasss;
- (SBElementArray *) languages;

@property (copy) AppleScriptEditorSelectionObject *selection;  // The current selection.

@end

// A class
@interface AppleScriptEditorObjectClass : AppleScriptEditorItem


@end

// A script document.
@interface AppleScriptEditorDocument (ScriptEditorSuite)

- (SBElementArray *) windows;

@property (copy) AppleScriptEditorText *contents;  // The contents of the document.
@property (copy) AppleScriptEditorText *objectDescription;  // The description of the document.
@property (copy) AppleScriptEditorLanguage *language;  // The scripting language.
@property (copy) AppleScriptEditorSelectionObject *selection;  // The current selection.
@property (copy) AppleScriptEditorText *text;  // The text of the document.

@end

// An insertion point between two objects.
@interface AppleScriptEditorInsertionPoint : AppleScriptEditorItem

@property (copy) AppleScriptEditorItem *contents;  // The contents of the insertion point.


@end

// A scripting language.
@interface AppleScriptEditorLanguage : AppleScriptEditorItem

@property (copy, readonly) NSString *objectDescription;  // The description
- (NSString *) id;  // The unique id of the language.
@property (copy, readonly) NSString *name;  // The name of the language.
@property (readonly) BOOL supportsCompiling;  // Is the language compilable?
@property (readonly) BOOL supportsRecording;  // Is the language recordable?


@end

// A way to refer to the state of the current selection.
@interface AppleScriptEditorSelectionObject : AppleScriptEditorItem

@property (readonly) NSPoint characterRange;  // The range of characters in the selection.
@property (copy) AppleScriptEditorItem *contents;  // The contents of the selection.


@end

// Rich (styled) text
@interface AppleScriptEditorText (ScriptEditorSuite)

- (SBElementArray *) attributeRuns;
- (SBElementArray *) characters;
- (SBElementArray *) insertionPoints;
- (SBElementArray *) paragraphs;
- (SBElementArray *) text;
- (SBElementArray *) words;

@property (copy) NSColor *color;  // The color of the first character.
@property (copy) NSString *font;  // The name of the font of the first character.
@property NSInteger size;  // The size in points of the first character.

@end

// A window.
@interface AppleScriptEditorWindow (ScriptEditorSuite)

@property (copy) NSString *name;  // The full title of the window.

@end



/*
 * Type Definitions
 */

@interface AppleScriptEditorPrintSettings : SBObject

@property NSInteger copies;  // the number of copies of a document to be printed
@property BOOL collating;  // Should printed copies be collated?
@property NSInteger startingPage;  // the first page of the document to be printed
@property NSInteger endingPage;  // the last page of the document to be printed
@property NSInteger pagesAcross;  // number of logical pages laid across a physical page
@property NSInteger pagesDown;  // number of logical pages laid out down a physical page
@property (copy) NSDate *requestedPrintTime;  // the time at which the desktop printer should print the document
@property AppleScriptEditorEnum errorHandling;  // how errors are handled
@property (copy) NSString *faxNumber;  // for fax number
@property (copy) NSString *targetPrinter;  // for target printer

- (void) closeSaving:(AppleScriptEditorSavo)saving savingIn:(NSURL *)savingIn;  // Close an object.
- (void) delete;  // Delete an object.
- (void) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Copy object(s) and put the copies at a new location.
- (BOOL) exists;  // Verify if an object exists.
- (void) moveTo:(SBObject *)to;  // Move object(s) to a new location.
- (void) saveAs:(NSString *)as in:(NSURL *)in_;  // Save an object.
- (void) checkSyntax;  // Check the syntax of a document.
- (BOOL) compile;  // Compile the script of a document.
- (id) execute;  // Execute the document.
- (void) saveAs:(NSString *)as in:(NSURL *)in_ runOnly:(BOOL)runOnly startupScreen:(BOOL)startupScreen stayOpen:(BOOL)stayOpen;  // Save an object.

@end

