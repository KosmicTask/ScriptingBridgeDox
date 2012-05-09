
/*
 * Distiller.h
 */

#import <AppKit/AppKit.h>
#import <ScriptingBridge/ScriptingBridge.h>


@class DistillerItem, DistillerApplication, DistillerColor, DistillerDocument, DistillerWindow, DistillerAttributeRun, DistillerCharacter, DistillerParagraph, DistillerText, DistillerAttachment, DistillerWord, DistillerPrintSettings;

enum DistillerSavo {
	DistillerSavoAsk = 'ask ' /* Ask the user whether or not to save the file. */,
	DistillerSavoNo = 'no  ' /* Do not save the file. */,
	DistillerSavoYes = 'yes ' /* Save the file. */
};
typedef enum DistillerSavo DistillerSavo;

enum DistillerEnum {
	DistillerEnumStandard = 'lwst' /* Standard PostScript error handling */,
	DistillerEnumDetailed = 'lwdt' /* print a detailed report of PostScript errors */
};
typedef enum DistillerEnum DistillerEnum;



/*
 * Standard Suite
 */

// A scriptable object.
@interface DistillerItem : SBObject

@property (copy) NSDictionary *properties;  // All of the object's properties.

- (void) closeSaving:(DistillerSavo)saving savingIn:(NSURL *)savingIn;  // Close an object.
- (void) delete;  // Delete an object.
- (void) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Copy object(s) and put the copies at a new location.
- (BOOL) exists;  // Verify if an object exists.
- (void) moveTo:(SBObject *)to;  // Move object(s) to a new location.
- (void) saveAs:(NSString *)as in:(NSURL *)in_;  // Save an object.
- (void) DistillSourcePath:(NSString *)sourcePath adobePDFSettingsPath:(NSString *)adobePDFSettingsPath destinationPath:(NSString *)destinationPath;  // Distill a file.
- (void) EditAdobePDFSettingsAdobePDFSettingsName:(NSString *)adobePDFSettingsName;  // *** Not used for general AppleScripting. *** It displays the Distiller Edit Adobe PDF Settings dialog for the Distiller plugin.
- (void) EditSecurity;  // *** Not used for general AppleScripting. *** It displays the Distiller Security dialog for the Distiller plugin.

@end

// An application's top level scripting object.
@interface DistillerApplication : SBApplication

- (SBElementArray *) documents;
- (SBElementArray *) windows;

@property (readonly) BOOL frontmost;  // Is this the frontmost (active) application?
@property (copy, readonly) NSString *name;  // The name of the application.
@property (copy, readonly) NSString *version;  // The version of the application.

- (DistillerDocument *) open:(NSURL *)x;  // Open an object.
- (void) print:(NSURL *)x printDialog:(BOOL)printDialog withProperties:(DistillerPrintSettings *)withProperties;  // Print an object.
- (void) quitSaving:(DistillerSavo)saving;  // Quit an application.

@end

// A color.
@interface DistillerColor : DistillerItem


@end

// A document.
@interface DistillerDocument : DistillerItem

@property (readonly) BOOL modified;  // Has the document been modified since the last save?
@property (copy) NSString *name;  // The document's name.
@property (copy) NSString *path;  // The document's path.


@end

// A window.
@interface DistillerWindow : DistillerItem

@property NSRect bounds;  // The bounding rectangle of the window.
@property (readonly) BOOL closeable;  // Whether the window has a close box.
@property (copy, readonly) DistillerDocument *document;  // The document whose contents are being displayed in the window.
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
@interface DistillerAttributeRun : DistillerItem

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
@interface DistillerCharacter : DistillerItem

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
@interface DistillerParagraph : DistillerItem

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
@interface DistillerText : DistillerItem

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
@interface DistillerAttachment : DistillerText

@property (copy) NSString *fileName;  // The path to the file for the attachment


@end

// This subdivides the text into words.
@interface DistillerWord : DistillerItem

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
 * Distiller Suite
 */

// Distiller's top level scripting object.
@interface DistillerApplication (DistillerSuite)

@property (copy, readonly) NSString *locale;  // Three character language code for Distiller's UI (ENU is English)
@property (copy, readonly) NSString *postScriptVersion;  // PostScript interpreter version

@end



/*
 * Type Definitions
 */

@interface DistillerPrintSettings : SBObject

@property NSInteger copies;  // the number of copies of a document to be printed
@property BOOL collating;  // Should printed copies be collated?
@property NSInteger startingPage;  // the first page of the document to be printed
@property NSInteger endingPage;  // the last page of the document to be printed
@property NSInteger pagesAcross;  // number of logical pages laid across a physical page
@property NSInteger pagesDown;  // number of logical pages laid out down a physical page
@property (copy) NSDate *requestedPrintTime;  // the time at which the desktop printer should print the document
@property DistillerEnum errorHandling;  // how errors are handled
@property (copy) NSString *faxNumber;  // for fax number
@property (copy) NSString *targetPrinter;  // for target printer

- (void) closeSaving:(DistillerSavo)saving savingIn:(NSURL *)savingIn;  // Close an object.
- (void) delete;  // Delete an object.
- (void) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Copy object(s) and put the copies at a new location.
- (BOOL) exists;  // Verify if an object exists.
- (void) moveTo:(SBObject *)to;  // Move object(s) to a new location.
- (void) saveAs:(NSString *)as in:(NSURL *)in_;  // Save an object.
- (void) DistillSourcePath:(NSString *)sourcePath adobePDFSettingsPath:(NSString *)adobePDFSettingsPath destinationPath:(NSString *)destinationPath;  // Distill a file.
- (void) EditAdobePDFSettingsAdobePDFSettingsName:(NSString *)adobePDFSettingsName;  // *** Not used for general AppleScripting. *** It displays the Distiller Edit Adobe PDF Settings dialog for the Distiller plugin.
- (void) EditSecurity;  // *** Not used for general AppleScripting. *** It displays the Distiller Security dialog for the Distiller plugin.

@end


