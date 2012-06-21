/*
 * FontBook.h
 */

#import <AppKit/AppKit.h>
#import <ScriptingBridge/ScriptingBridge.h>


@class FontBookItem, FontBookApplication, FontBookColor, FontBookDocument, FontBookWindow, FontBookFontFamily, FontBookTypeface, FontBookFontContainer, FontBookFontCollection, FontBookFontLibrary, FontBookMyFontsLibrary, FontBookFontDomain, FontBookAllFontsLibraryObject;

enum FontBookSavo {
	FontBookSavoYes = 'yes ' /* Save the file. */,
	FontBookSavoNo = 'no  ' /* Do not save the file. */,
	FontBookSavoAsk = 'ask ' /* Ask the user whether or not to save the file. */
};
typedef enum FontBookSavo FontBookSavo;



/*
 * Standard Suite
 */

// Abstract object provides a base class for scripting classes.  It is never used directly.
@interface FontBookItem : SBObject

@property (copy) NSDictionary *properties;  // All of the object's properties.

- (void) open;  // Open an object.
- (void) print;  // Print an object.
- (void) closeSaving:(FontBookSavo)saving savingIn:(NSURL *)savingIn;  // Close an object.
- (void) delete;  // Delete an object.
- (void) duplicateTo:(SBObject *)to;  // Copy object(s) and put the copies at a new location.
- (BOOL) exists;  // Verify if an object exists.
- (void) moveTo:(SBObject *)to;  // Move object(s) to a new location.
- (void) saveIn:(NSString *)in_ as:(NSString *)as;  // Save an object.
- (void) addTo:(SBObject *)to;  // Add the given object to the container.
- (void) removeFrom:(SBObject *)from;  // Remove the given object from the container.
- (void) exportTo:(NSURL *)to;  // Export the given objects to the specified location.

@end

// An application's top level scripting object.
@interface FontBookApplication : SBApplication

- (SBElementArray *) documents;
- (SBElementArray *) windows;

@property (copy, readonly) NSString *name;  // The name of the application.
@property (readonly) BOOL frontmost;  // Is this the frontmost (active) application?
@property (copy, readonly) NSString *version;  // The version of the application.

- (void) quitSaving:(FontBookSavo)saving;  // Quit an application.

@end

// A color.
@interface FontBookColor : SBObject

- (void) open;  // Open an object.
- (void) print;  // Print an object.
- (void) closeSaving:(FontBookSavo)saving savingIn:(NSURL *)savingIn;  // Close an object.
- (void) delete;  // Delete an object.
- (void) duplicateTo:(SBObject *)to;  // Copy object(s) and put the copies at a new location.
- (BOOL) exists;  // Verify if an object exists.
- (void) moveTo:(SBObject *)to;  // Move object(s) to a new location.
- (void) saveIn:(NSString *)in_ as:(NSString *)as;  // Save an object.
- (void) addTo:(SBObject *)to;  // Add the given object to the container.
- (void) removeFrom:(SBObject *)from;  // Remove the given object from the container.
- (void) exportTo:(NSURL *)to;  // Export the given objects to the specified location.

@end

// A document.
@interface FontBookDocument : SBObject

@property (copy) NSString *path;  // The document's path.
@property (readonly) BOOL modified;  // Has the document been modified since the last save?
@property (copy) NSString *name;  // The document's name.

- (void) open;  // Open an object.
- (void) print;  // Print an object.
- (void) closeSaving:(FontBookSavo)saving savingIn:(NSURL *)savingIn;  // Close an object.
- (void) delete;  // Delete an object.
- (void) duplicateTo:(SBObject *)to;  // Copy object(s) and put the copies at a new location.
- (BOOL) exists;  // Verify if an object exists.
- (void) moveTo:(SBObject *)to;  // Move object(s) to a new location.
- (void) saveIn:(NSString *)in_ as:(NSString *)as;  // Save an object.
- (void) addTo:(SBObject *)to;  // Add the given object to the container.
- (void) removeFrom:(SBObject *)from;  // Remove the given object from the container.
- (void) exportTo:(NSURL *)to;  // Export the given objects to the specified location.

@end

// A window.
@interface FontBookWindow : SBObject

@property (copy) NSString *name;  // The full title of the window.
- (NSInteger) id;  // The unique identifier of the window.
@property NSRect bounds;  // The bounding rectangle of the window.
@property (readonly) BOOL closeable;  // Whether the window has a close box.
@property (readonly) BOOL titled;  // Whether the window has a title bar.
@property NSInteger index;  // The index of the window in the back-to-front window ordering.
@property (readonly) BOOL floating;  // Whether the window floats.
@property (readonly) BOOL miniaturizable;  // Whether the window can be miniaturized.
@property BOOL miniaturized;  // Whether the window is currently miniaturized.
@property (readonly) BOOL modal;  // Whether the window is the application's current modal window.
@property (readonly) BOOL resizable;  // Whether the window can be resized.
@property BOOL visible;  // Whether the window is currently visible.
@property (readonly) BOOL zoomable;  // Whether the window can be zoomed.
@property BOOL zoomed;  // Whether the window is currently zoomed.

- (void) open;  // Open an object.
- (void) print;  // Print an object.
- (void) closeSaving:(FontBookSavo)saving savingIn:(NSURL *)savingIn;  // Close an object.
- (void) delete;  // Delete an object.
- (void) duplicateTo:(SBObject *)to;  // Copy object(s) and put the copies at a new location.
- (BOOL) exists;  // Verify if an object exists.
- (void) moveTo:(SBObject *)to;  // Move object(s) to a new location.
- (void) saveIn:(NSString *)in_ as:(NSString *)as;  // Save an object.
- (void) addTo:(SBObject *)to;  // Add the given object to the container.
- (void) removeFrom:(SBObject *)from;  // Remove the given object from the container.
- (void) exportTo:(NSURL *)to;  // Export the given objects to the specified location.

@end



/*
 * Font Book
 */

// Font Book's top level scripting object.
@interface FontBookApplication (FontBook)

- (SBElementArray *) fontFamilies;
- (SBElementArray *) typefaces;
- (SBElementArray *) fontCollections;
- (SBElementArray *) fontDomains;
- (SBElementArray *) fontLibraries;
- (SBElementArray *) fontContainers;

@property BOOL validateFontsBeforeInstalling;  // Whether validating fonts before installing or not.
@property (copy) FontBookFontLibrary *installationTarget;  // Where to install fonts.
@property (copy, readonly) FontBookFontLibrary *fontsLibrary;  // The All Fonts library.
@property (copy) NSArray *selection;  // current selection.
@property (copy) NSArray *selectedFontFamilies;  // selected font families.
@property (copy) NSArray *selectedCollections;  // selected collections.

@end

// A font family
@interface FontBookFontFamily : FontBookItem

- (SBElementArray *) typefaces;

@property (copy, readonly) NSString *name;  // The name of the family
@property (copy, readonly) NSString *displayName;  // Synonym for displayed name
@property (copy, readonly) NSString *displayedName;  // Font family display name
@property BOOL enabled;  // A font family
@property (readonly) BOOL duplicated;  // Whether the family contains duplicated faces
@property (copy, readonly) NSURL *files;  // Font files for the family


@end

// A typeface
@interface FontBookTypeface : FontBookItem

@property (copy, readonly) NSString *name;  // The name of the family
@property (copy, readonly) NSString *displayName;  // Synonym for displayed name
@property (copy, readonly) NSString *displayedName;  // Typeface display name
@property (copy, readonly) FontBookFontFamily *fontFamily;  // Font family
@property (copy, readonly) NSString *familyName;  // Font family name
@property (copy, readonly) NSString *styleName;  // Style name
@property (copy, readonly) NSString *PostScriptName;  // PostScript font name
@property (copy, readonly) NSString *ID;  // The unique identifier of the typeface
@property BOOL enabled;  // A font family
@property (readonly) BOOL duplicated;  // Whether the typeface is duplicated or not duplicated faces
@property (copy, readonly) NSString *fontType;  // Font format
@property (copy, readonly) NSString *copyright;  // Copyright
@property (copy, readonly) FontBookFontContainer *fontContainer;  // Font container
@property (copy, readonly) NSURL *files;  // Font files for the face


@end

// An abstact object representing font files
@interface FontBookFontContainer : FontBookItem

- (SBElementArray *) fontFamilies;
- (SBElementArray *) typefaces;
- (SBElementArray *) fontDomains;

@property (copy, readonly) NSString *name;  // The name of the container
@property (copy, readonly) NSString *path;  // The path to the main container
@property (copy, readonly) NSURL *files;  // Files for the container
@property (copy, readonly) FontBookFontDomain *domain;  // Font Domain for the container
@property (copy, readonly) NSString *ID;  // The unique identifier of the container


@end

// A font collection.
@interface FontBookFontCollection : FontBookItem

- (SBElementArray *) fontFamilies;
- (SBElementArray *) typefaces;

@property (copy) NSString *name;  // The name of the collection
@property (copy, readonly) NSString *displayName;  // Synonym for displayed name
@property (copy, readonly) NSString *displayedName;  // Display name of the domain
@property BOOL enabled;  // Whether the collection is enabled or disabled.


@end

// A font library
@interface FontBookFontLibrary : FontBookFontCollection

- (SBElementArray *) fontContainers;


@end

// MyFonts font library
@interface FontBookMyFontsLibrary : FontBookFontLibrary


@end

// A font domain
@interface FontBookFontDomain : FontBookFontLibrary

@property (copy, readonly) NSString *ID;  // The unique identifier of the domain


@end

// All Fonts library object
@interface FontBookAllFontsLibraryObject : FontBookFontDomain


@end

