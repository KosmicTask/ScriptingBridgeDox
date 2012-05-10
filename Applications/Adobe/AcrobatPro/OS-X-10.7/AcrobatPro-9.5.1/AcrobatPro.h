/*
 * AcrobatPro.h
 */

#import <AppKit/AppKit.h>
#import <ScriptingBridge/ScriptingBridge.h>


@class AcrobatProApplication, AcrobatProDocument, AcrobatProWindow, AcrobatProPDFWindow, AcrobatProPage, AcrobatProBookmark, AcrobatProAnnotation, AcrobatProTextAnnotation, AcrobatProLinkAnnotation, AcrobatProConversion, AcrobatProPostScriptConversion, AcrobatProEPSConversion, AcrobatProAVPageView, AcrobatProPDPage, AcrobatProPDBookmark, AcrobatProPDAnnot, AcrobatProPDTextAnnot, AcrobatProPDLinkAnnot, AcrobatProMenu, AcrobatProMenuItem;

enum AcrobatProSavo {
	AcrobatProSavoAsk = 'ask ' /* Whether the user should be prompted */,
	AcrobatProSavoYes = 'yes ' /* Whether saves should automatically be performed */,
	AcrobatProSavoNo = 'no  ' /* saving should not be automatically performed */
};
typedef enum AcrobatProSavo AcrobatProSavo;

enum AcrobatProPvew {
	AcrobatProPvewNotVisible = 'pnvs',
	AcrobatProPvewJustPages = 'pgs ' /* Pages only shown (no thumbs nor bookmarks shown) */,
	AcrobatProPvewPagesAndThumbs = 'pgtb' /* Pages and thumbnails shown */,
	AcrobatProPvewPagesAndBookmarks = 'pgbm' /* Pages and bookmarks shown */
};
typedef enum AcrobatProPvew AcrobatProPvew;

enum AcrobatProPdzt {
	AcrobatProPdztNoVary = 'pznv' /* Don’t change zoom */,
	AcrobatProPdztFitPage = 'pzfp' /* Fit the page to the window */,
	AcrobatProPdztFitWidth = 'pzfw' /* fit the page’s width to the window’s width */,
	AcrobatProPdztFitHeight = 'pzfh' /* fit the page’s height to the window’s height */,
	AcrobatProPdztFitVisibleWidth = 'pzvw' /* fit the part of the page’s width containing visible information to the window’s width */
};
typedef enum AcrobatProPdzt AcrobatProPdzt;

enum AcrobatProPfcd {
	AcrobatProPfcdAlwaysVisible = 'show' /* The cursor is always visible. */,
	AcrobatProPfcdAlwaysHidden = 'hidn' /* The cursor is always hidden. */,
	AcrobatProPfcdHiddenAfterDelay = 'dlay' /* The cursor is hidden after a short delay. */
};
typedef enum AcrobatProPfcd AcrobatProPfcd;

enum AcrobatProPftt {
	AcrobatProPfttLeftTopZoom = 'pxyz' /* put left and top of rectangle at left and top of window, and use the zoom factor property - ignores the right and bottom fields of the destination rectangle */,
	AcrobatProPfttFitPage = 'pzfp' /* fit the page to the window - ignores the destination rect */,
	AcrobatProPfttFitWidth = 'pzfw' /* fit the destination rectangle’s width to the window’s width - ignores the top and bottom fields of the destination rectangle */,
	AcrobatProPfttFitHeight = 'pzfh' /* fit the destination rectangle’s height to the window’s height - ignores the left and right field of the destination rectangle */,
	AcrobatProPfttFitRect = 'pfrt' /* fit the destination rectangle to the window */,
	AcrobatProPfttFitBBox = 'pfbb' /* fit the page’s bounding box to the window - ignores the destination rectangle */,
	AcrobatProPfttFitBBWidth = 'pfbw' /* fit the width of the page to the window’s width - ignores the destination rectangle */,
	AcrobatProPfttFitBBHeight = 'pfbh' /* fit the height of the page to the window’s height - ignores the destination rectangle */
};
typedef enum AcrobatProPftt AcrobatProPftt;



/*
 * Core Suite
 */

// The Acrobat application.
@interface AcrobatProApplication : SBApplication

- (SBElementArray *) documents;
- (SBElementArray *) PDFWindows;
- (SBElementArray *) menus;
- (SBElementArray *) menuItems;
- (SBElementArray *) conversions;

@property (copy) SBObject *activeDoc;  // The active document.
@property (copy) NSString *activeTool;  // The type of the currently active tool.
@property BOOL anti_aliasText;  // Whether to anti-alias text and monochrome images.
@property (copy, readonly) NSNumber *bestType;  // The best descriptor type.
@property BOOL caseSensitivity;  // Whether searches are case sensitive.
@property (copy, readonly) NSNumber *defaultType;  // The default descriptor type.
@property double defaultZoomFactor;  // The default zoom factor at which new documents are displayed.
@property (copy) id defaultZoomType;  // The default zoom type when opening a new document.  Valid values are “no vary”, “fit page”, “fit width”, “fit height”, and “fit visible width”.
@property BOOL downloadEntireFile;  // Whether to download the entire file.
@property BOOL frontmost;  // Whether Acrobat is the frontmost application.  Value can be set to true only; false not supported.
@property (copy, readonly) NSString *fullscreenTransition;  // Default fullscreen transition.
@property (readonly) BOOL fullscreenLoop;  // Loop after last page in fullscreen mode.
@property BOOL fullscreenClickAdvances;  // Mouse click advances in fullscreen mode.
@property BOOL fullscreenEscape;  // Escape key exits fullscreen mode.
@property (copy) id fullscreenCursor;  // Cursor visibility in fullscreen mode. Valid values are “always visible”, “always hidden” or “hidden after delay”).
@property BOOL useFullscreenTimer;  // Whether to use a timer to advance pages in fullscreen mode.
@property NSInteger fullscreenTimerDelay;  // The number of seconds to pause before advancing to next page in fullscreen mode.
@property (copy) id highlightColor;  // Color used to highlight selections.
@property (readonly) NSInteger maximumDocuments;  // Maximum number of open documents.
@property (copy, readonly) NSString *name;  // The application’s name.
@property (copy) id noteColor;  // The color of the border around newly created text annotations.
@property BOOL openInPlace;  // Open cross document links in the same window.
@property (copy) NSString *pageUnits;  // Default page display units. One of Points, Picas, Inches, Millimeters or Centimeters.
@property (copy) NSString *pageLayout;  // Default page layout preference for a document on open. (“Single Page”, “Continuous”, “Continuous - Facing”, “Facing”)
@property BOOL saveAsLinearize;  // Whether to save documents as linearized.  Primarily used to optimize viewing documents in a web browser.
@property BOOL showSplashAtStartup;  // Whether the splash screen is shown at startup.
@property BOOL shrinkToFit;  // Obsolete in Acrobat 6.  No longer used.
@property BOOL skipWarnings;  // Whether to skip warning dialogs during program execution.
@property (copy) NSString *textNoteLabel;  // The text that will appear in the “title bar” of all newly created text notes.
@property BOOL toolbarVisibility;  // Whether the ToolBar is visible.
@property (copy, readonly) NSString *UILanguage;  // Identifys which language Acrobat’s UI is using.  This is a 3 character language codes (ENU is English, for instance).
@property (copy, readonly) NSString *version;  // The version number of the application.
@property BOOL wholeWordSearching;  // Whether searches are for whole words.
@property (copy) NSString *noteFontName;  // Obsolete in Acrobat 6.  No longer used.  (was default note annotation font name).
@property NSInteger noteFontSize;  // Obsolete in Acrobat 6.  No longer used.  (was default note annotation font size).
@property NSInteger PSLevel;  // Obsolete in Acrobat 6.  No longer used.  Please set Postscript Level when using “Save” or “Print pages” commands.

- (void) closeSaving:(id)saving linearize:(BOOL)linearize;  // Close a document.
- (void) open:(NSArray *)x invisible:(BOOL)invisible options:(NSString *)options;  // Open a document or documents.
- (void) quitSaving:(id)saving;  // Tell Acrobat to quit.
- (void) clearSelection;  // Clear any document selection.
- (void) closeAllDocsSaving:(id)saving;  // Close all documents, with optional saving first.
- (void) createThumbs;  // Create thumbnails for all pages in the document.
- (void) deletePagesFirst:(NSInteger)first last:(NSInteger)last;  // Deletes the specified pages in the document.
- (void) deleteThumbs;  // Delete all thumbnails from the document.
- (SBObject *) findNextNoteWrapAround:(BOOL)wrapAround;  // Find and select the next text note.
- (NSString *) findTextString:(NSString *)string CaseSensitive:(BOOL)CaseSensitive wholeWords:(BOOL)wholeWords wrapAround:(BOOL)wrapAround;  // Find text in a document.
- (void) getInfoKey:(NSString *)key;  // Get the string associated with the specified key.
- (void) goBackward;  // Go to the previous view in the stored view chain.
- (void) goForward;  // Go to the next view in the stored view chain.
- (void) gotoPage:(NSInteger)page;  // Make the PDF Window goto the specified page number.
- (void) gotoNext;  // Display the page after the one currently displayed in the PDF Window.
- (void) gotoPrevious;  // Display the page before the one currently displayed in the PDF Window.
- (void) insertPagesAfter:(NSInteger)after from:(SBObject *)from startingWith:(NSInteger)startingWith numberOfPages:(NSInteger)numberOfPages insertBookmarks:(BOOL)insertBookmarks;  // Insert page(s) from another document.
- (BOOL) isToolbuttonEnabledNamed:(NSString *)named;  // Whether the specified toolbutton is enabled or not.
- (void) maximizeMaxSize:(BOOL)maxSize;  // Set the document’s window’s size to be the maximum or its original size.
- (void) printPagesFirst:(NSInteger)first last:(NSInteger)last PSLevel:(NSInteger)PSLevel binaryOutput:(BOOL)binaryOutput shrinkToFit:(BOOL)shrinkToFit;  // Print page(s) from a document.
- (void) readPageDown;  // Scroll to the next screen’s worth.
- (void) readPageUp;  // Scroll to the previous screen’s worth.
- (void) removeToolbuttonNamed:(NSString *)named;  // Remove the specified toolbutton from the toolbar.
- (void) replacePagesOver:(NSInteger)over from:(SBObject *)from startingWith:(NSInteger)startingWith numberOfPages:(NSInteger)numberOfPages mergeNotes:(BOOL)mergeNotes;  // Replaces page(s) with page(s) from another document.
- (void) scrollXAmount:(NSInteger)XAmount YAmount:(NSInteger)YAmount;  // Scroll the page by the specified amount (in device space).
- (void) selectTextFromWords:(NSArray *)fromWords fromChars:(NSArray *)fromChars;  // Selects text as specified by either character or word offsets.
- (void) setInfoKey:(NSString *)key value:(NSString *)value;  // Set a key/value string pair in the document’s Info dictionary.
- (void) zoomTo:(double)to;  // Zoom the display of the current page.
- (void) doScript:(NSString *)x file:(NSURL *)file;  // Perform a JavaScript.

@end

// An Acrobat document.
@interface AcrobatProDocument : SBObject

- (SBElementArray *) pages;
- (SBElementArray *) bookmarks;
- (SBElementArray *) PDFWindows;

@property (copy, readonly) NSNumber *bestType;  // The best descriptor type.
@property (readonly) NSRect bounds;  // The boundary rectangle for the document’s window, in screen coordinates (left, top, right, bottom). Note that (0,0) is in the upper left.
@property (copy, readonly) NSNumber *defaultType;  // The default descriptor type.
@property (copy, readonly) NSURL *fileAlias;  // An alias to the file where the doc will be saved to if no other name is supplied. This is usually the same file as where it the document was read in from.
@property (copy, readonly) NSString *name;  // The document’s name (as shown in the window’s titlebar).
@property (readonly) BOOL modified;  // Whether the document has been modified enough to warrant saving.
@property (copy) id viewMode;  // The view mode of the document (one of: “just pages”, “pages and thumbs”, or “pages and bookmarks”).

- (void) closeSaving:(id)saving linearize:(BOOL)linearize;  // Close a document.
- (void) delete;  // Delete an element from an object.
- (BOOL) exists;  // Verify if an object exists.
- (SBObject *) moveTo:(SBObject *)to;  // Move object (only Page class objects can be moved).
- (void) saveTo:(NSURL *)to using:(SBObject *)using_ linearize:(BOOL)linearize;  // Save the document.
- (void) bringToFront;  // Bring the window containing the document to the front.
- (void) clearSelection;  // Clear any document selection.
- (void) createThumbs;  // Create thumbnails for all pages in the document.
- (void) deletePagesFirst:(NSInteger)first last:(NSInteger)last;  // Deletes the specified pages in the document.
- (void) deleteThumbs;  // Delete all thumbnails from the document.
- (void) execute;  // Execute the menu item as if the user clicked on it.
- (SBObject *) findNextNoteWrapAround:(BOOL)wrapAround;  // Find and select the next text note.
- (NSString *) findTextString:(NSString *)string CaseSensitive:(BOOL)CaseSensitive wholeWords:(BOOL)wholeWords wrapAround:(BOOL)wrapAround;  // Find text in a document.
- (void) getInfoKey:(NSString *)key;  // Get the string associated with the specified key.
- (void) goBackward;  // Go to the previous view in the stored view chain.
- (void) goForward;  // Go to the next view in the stored view chain.
- (void) gotoPage:(NSInteger)page;  // Make the PDF Window goto the specified page number.
- (void) gotoNext;  // Display the page after the one currently displayed in the PDF Window.
- (void) gotoPrevious;  // Display the page before the one currently displayed in the PDF Window.
- (void) insertPagesAfter:(NSInteger)after from:(SBObject *)from startingWith:(NSInteger)startingWith numberOfPages:(NSInteger)numberOfPages insertBookmarks:(BOOL)insertBookmarks;  // Insert page(s) from another document.
- (BOOL) isToolbuttonEnabledNamed:(NSString *)named;  // Whether the specified toolbutton is enabled or not.
- (void) maximizeMaxSize:(BOOL)maxSize;  // Set the document’s window’s size to be the maximum or its original size.
- (void) perform;  // Causes the object’s action to be executed.
- (void) printPagesFirst:(NSInteger)first last:(NSInteger)last PSLevel:(NSInteger)PSLevel binaryOutput:(BOOL)binaryOutput shrinkToFit:(BOOL)shrinkToFit;  // Print page(s) from a document.
- (void) readPageDown;  // Scroll to the next screen’s worth.
- (void) readPageUp;  // Scroll to the previous screen’s worth.
- (void) removeToolbuttonNamed:(NSString *)named;  // Remove the specified toolbutton from the toolbar.
- (void) replacePagesOver:(NSInteger)over from:(SBObject *)from startingWith:(NSInteger)startingWith numberOfPages:(NSInteger)numberOfPages mergeNotes:(BOOL)mergeNotes;  // Replaces page(s) with page(s) from another document.
- (void) scrollXAmount:(NSInteger)XAmount YAmount:(NSInteger)YAmount;  // Scroll the page by the specified amount (in device space).
- (void) selectTextFromWords:(NSArray *)fromWords fromChars:(NSArray *)fromChars;  // Selects text as specified by either character or word offsets.
- (void) setInfoKey:(NSString *)key value:(NSString *)value;  // Set a key/value string pair in the document’s Info dictionary.
- (void) zoomTo:(double)to;  // Zoom the display of the current page.

@end

// A window.
@interface AcrobatProWindow : SBObject

@property (copy, readonly) NSString *name;  // The title of the window.
@property NSRect bounds;  // The boundary rectangle for the window.
@property (readonly) BOOL visible;  // Whether the window is visible.

- (void) closeSaving:(id)saving linearize:(BOOL)linearize;  // Close a document.
- (void) delete;  // Delete an element from an object.
- (BOOL) exists;  // Verify if an object exists.
- (SBObject *) moveTo:(SBObject *)to;  // Move object (only Page class objects can be moved).
- (void) saveTo:(NSURL *)to using:(SBObject *)using_ linearize:(BOOL)linearize;  // Save the document.
- (void) bringToFront;  // Bring the window containing the document to the front.
- (void) clearSelection;  // Clear any document selection.
- (void) createThumbs;  // Create thumbnails for all pages in the document.
- (void) deletePagesFirst:(NSInteger)first last:(NSInteger)last;  // Deletes the specified pages in the document.
- (void) deleteThumbs;  // Delete all thumbnails from the document.
- (void) execute;  // Execute the menu item as if the user clicked on it.
- (SBObject *) findNextNoteWrapAround:(BOOL)wrapAround;  // Find and select the next text note.
- (NSString *) findTextString:(NSString *)string CaseSensitive:(BOOL)CaseSensitive wholeWords:(BOOL)wholeWords wrapAround:(BOOL)wrapAround;  // Find text in a document.
- (void) getInfoKey:(NSString *)key;  // Get the string associated with the specified key.
- (void) goBackward;  // Go to the previous view in the stored view chain.
- (void) goForward;  // Go to the next view in the stored view chain.
- (void) gotoPage:(NSInteger)page;  // Make the PDF Window goto the specified page number.
- (void) gotoNext;  // Display the page after the one currently displayed in the PDF Window.
- (void) gotoPrevious;  // Display the page before the one currently displayed in the PDF Window.
- (void) insertPagesAfter:(NSInteger)after from:(SBObject *)from startingWith:(NSInteger)startingWith numberOfPages:(NSInteger)numberOfPages insertBookmarks:(BOOL)insertBookmarks;  // Insert page(s) from another document.
- (BOOL) isToolbuttonEnabledNamed:(NSString *)named;  // Whether the specified toolbutton is enabled or not.
- (void) maximizeMaxSize:(BOOL)maxSize;  // Set the document’s window’s size to be the maximum or its original size.
- (void) perform;  // Causes the object’s action to be executed.
- (void) printPagesFirst:(NSInteger)first last:(NSInteger)last PSLevel:(NSInteger)PSLevel binaryOutput:(BOOL)binaryOutput shrinkToFit:(BOOL)shrinkToFit;  // Print page(s) from a document.
- (void) readPageDown;  // Scroll to the next screen’s worth.
- (void) readPageUp;  // Scroll to the previous screen’s worth.
- (void) removeToolbuttonNamed:(NSString *)named;  // Remove the specified toolbutton from the toolbar.
- (void) replacePagesOver:(NSInteger)over from:(SBObject *)from startingWith:(NSInteger)startingWith numberOfPages:(NSInteger)numberOfPages mergeNotes:(BOOL)mergeNotes;  // Replaces page(s) with page(s) from another document.
- (void) scrollXAmount:(NSInteger)XAmount YAmount:(NSInteger)YAmount;  // Scroll the page by the specified amount (in device space).
- (void) selectTextFromWords:(NSArray *)fromWords fromChars:(NSArray *)fromChars;  // Selects text as specified by either character or word offsets.
- (void) setInfoKey:(NSString *)key value:(NSString *)value;  // Set a key/value string pair in the document’s Info dictionary.
- (void) zoomTo:(double)to;  // Zoom the display of the current page.

@end



/*
 * Acrobat Viewer Suite
 */

// The window displaying the specified document (corresponds to Acrobat’s internal AVPageView object).
@interface AcrobatProPDFWindow : AcrobatProWindow

- (SBElementArray *) pages;

@property (copy, readonly) NSNumber *bestType;  // The best descriptor type.
@property (copy, readonly) NSNumber *defaultType;  // The default descriptor type.
@property (copy, readonly) id document;  // The document of belonging to this window
@property (copy, readonly) NSString *name;  // The document’s name (as shown in the window’s titlebar).
@property NSInteger pageNumber;  // The number of the current displayed page.
@property double zoomFactor;  // The current zoom factor.
@property (copy) id zoomType;  // The zooming and content fitting algorithm current employed.  Valid values are “no vary”, “fit page”, “fit width”, “fit height”, and “fit visible width”.


@end

// A document page (corresponds to Acrobat’s internal PDPage object).
@interface AcrobatProPage : SBObject

- (SBElementArray *) annotations;

@property (copy, readonly) NSNumber *bestType;  // The best descriptor type.
@property (copy) NSArray *artBox;  // The art box rectangle for the page, in PDF space (left, top, right, bottom).
@property (copy) NSArray *bleedBox;  // The bleed box rectangle for the page, in PDF space (left, top, right, bottom).
@property (copy) NSArray *cropBox;  // The crop rectangle for the page, in PDF space (left, top, right, bottom).
@property (copy, readonly) NSNumber *defaultType;  // The default descriptor type.
@property (copy, readonly) NSString *labelText;  // The label (or custom page number) used to describe the page.
@property (copy) NSArray *mediaBox;  // The media bounds rectangle for the page, in PDF space (left, top, right, bottom).
@property (readonly) NSInteger pageNumber;  // The page’s number.
@property NSInteger rotation;  // The rotation angle of the page (0, 90, 180, 270).
@property (copy) NSArray *trimBox;  // The trim box rectangle for the page, in PDF space (left, top, right, bottom).
@property (copy) NSArray *bounds;  // Obsolete: use media box, crop box, art box, bleed box, and/or trim box instead.

- (void) closeSaving:(id)saving linearize:(BOOL)linearize;  // Close a document.
- (void) delete;  // Delete an element from an object.
- (BOOL) exists;  // Verify if an object exists.
- (SBObject *) moveTo:(SBObject *)to;  // Move object (only Page class objects can be moved).
- (void) saveTo:(NSURL *)to using:(SBObject *)using_ linearize:(BOOL)linearize;  // Save the document.
- (void) bringToFront;  // Bring the window containing the document to the front.
- (void) clearSelection;  // Clear any document selection.
- (void) createThumbs;  // Create thumbnails for all pages in the document.
- (void) deletePagesFirst:(NSInteger)first last:(NSInteger)last;  // Deletes the specified pages in the document.
- (void) deleteThumbs;  // Delete all thumbnails from the document.
- (void) execute;  // Execute the menu item as if the user clicked on it.
- (SBObject *) findNextNoteWrapAround:(BOOL)wrapAround;  // Find and select the next text note.
- (NSString *) findTextString:(NSString *)string CaseSensitive:(BOOL)CaseSensitive wholeWords:(BOOL)wholeWords wrapAround:(BOOL)wrapAround;  // Find text in a document.
- (void) getInfoKey:(NSString *)key;  // Get the string associated with the specified key.
- (void) goBackward;  // Go to the previous view in the stored view chain.
- (void) goForward;  // Go to the next view in the stored view chain.
- (void) gotoPage:(NSInteger)page;  // Make the PDF Window goto the specified page number.
- (void) gotoNext;  // Display the page after the one currently displayed in the PDF Window.
- (void) gotoPrevious;  // Display the page before the one currently displayed in the PDF Window.
- (void) insertPagesAfter:(NSInteger)after from:(SBObject *)from startingWith:(NSInteger)startingWith numberOfPages:(NSInteger)numberOfPages insertBookmarks:(BOOL)insertBookmarks;  // Insert page(s) from another document.
- (BOOL) isToolbuttonEnabledNamed:(NSString *)named;  // Whether the specified toolbutton is enabled or not.
- (void) maximizeMaxSize:(BOOL)maxSize;  // Set the document’s window’s size to be the maximum or its original size.
- (void) perform;  // Causes the object’s action to be executed.
- (void) printPagesFirst:(NSInteger)first last:(NSInteger)last PSLevel:(NSInteger)PSLevel binaryOutput:(BOOL)binaryOutput shrinkToFit:(BOOL)shrinkToFit;  // Print page(s) from a document.
- (void) readPageDown;  // Scroll to the next screen’s worth.
- (void) readPageUp;  // Scroll to the previous screen’s worth.
- (void) removeToolbuttonNamed:(NSString *)named;  // Remove the specified toolbutton from the toolbar.
- (void) replacePagesOver:(NSInteger)over from:(SBObject *)from startingWith:(NSInteger)startingWith numberOfPages:(NSInteger)numberOfPages mergeNotes:(BOOL)mergeNotes;  // Replaces page(s) with page(s) from another document.
- (void) scrollXAmount:(NSInteger)XAmount YAmount:(NSInteger)YAmount;  // Scroll the page by the specified amount (in device space).
- (void) selectTextFromWords:(NSArray *)fromWords fromChars:(NSArray *)fromChars;  // Selects text as specified by either character or word offsets.
- (void) setInfoKey:(NSString *)key value:(NSString *)value;  // Set a key/value string pair in the document’s Info dictionary.
- (void) zoomTo:(double)to;  // Zoom the display of the current page.

@end

// A bookmark (corresponds to Acrobat’s PDBookmark object).
@interface AcrobatProBookmark : SBObject

@property (copy, readonly) NSNumber *bestType;  // The best descriptor type.
@property (copy, readonly) NSNumber *defaultType;  // The default descriptor type.
@property NSInteger destinationPageNumber;  // The number of the page the PDF Window goes to when the bookmark is performed.
@property (copy) NSArray *destinationRectangle;  // The boundary rectangle for the view of the destination, in PDF space (left, top, right, bottom). [Set this only after setting the fit type property].
@property (copy) id fitType;  // Controls how the destination rectangle is fitted to the window when the bookmark is executed. Valid values are: “Left Top Zoom”, “Fit Page”, “Fit Width”, “Fit Height”, “Fit Rect”, “Fit BBox”, “Fit BB Width”, and “Fit BB Height”.
@property (readonly) NSInteger index;  // The bookmark’s index within the Document.
@property (copy) NSString *name;  // The bookmark’s title.
@property double zoomFactor;  // If fit type is “Left Top Zoom”, then this specifies the zoom factor, otherwise, this property is ignored. Setting this property automatically sets the fit type to “Left Top Zoom”.

- (void) closeSaving:(id)saving linearize:(BOOL)linearize;  // Close a document.
- (void) delete;  // Delete an element from an object.
- (BOOL) exists;  // Verify if an object exists.
- (SBObject *) moveTo:(SBObject *)to;  // Move object (only Page class objects can be moved).
- (void) saveTo:(NSURL *)to using:(SBObject *)using_ linearize:(BOOL)linearize;  // Save the document.
- (void) bringToFront;  // Bring the window containing the document to the front.
- (void) clearSelection;  // Clear any document selection.
- (void) createThumbs;  // Create thumbnails for all pages in the document.
- (void) deletePagesFirst:(NSInteger)first last:(NSInteger)last;  // Deletes the specified pages in the document.
- (void) deleteThumbs;  // Delete all thumbnails from the document.
- (void) execute;  // Execute the menu item as if the user clicked on it.
- (SBObject *) findNextNoteWrapAround:(BOOL)wrapAround;  // Find and select the next text note.
- (NSString *) findTextString:(NSString *)string CaseSensitive:(BOOL)CaseSensitive wholeWords:(BOOL)wholeWords wrapAround:(BOOL)wrapAround;  // Find text in a document.
- (void) getInfoKey:(NSString *)key;  // Get the string associated with the specified key.
- (void) goBackward;  // Go to the previous view in the stored view chain.
- (void) goForward;  // Go to the next view in the stored view chain.
- (void) gotoPage:(NSInteger)page;  // Make the PDF Window goto the specified page number.
- (void) gotoNext;  // Display the page after the one currently displayed in the PDF Window.
- (void) gotoPrevious;  // Display the page before the one currently displayed in the PDF Window.
- (void) insertPagesAfter:(NSInteger)after from:(SBObject *)from startingWith:(NSInteger)startingWith numberOfPages:(NSInteger)numberOfPages insertBookmarks:(BOOL)insertBookmarks;  // Insert page(s) from another document.
- (BOOL) isToolbuttonEnabledNamed:(NSString *)named;  // Whether the specified toolbutton is enabled or not.
- (void) maximizeMaxSize:(BOOL)maxSize;  // Set the document’s window’s size to be the maximum or its original size.
- (void) perform;  // Causes the object’s action to be executed.
- (void) printPagesFirst:(NSInteger)first last:(NSInteger)last PSLevel:(NSInteger)PSLevel binaryOutput:(BOOL)binaryOutput shrinkToFit:(BOOL)shrinkToFit;  // Print page(s) from a document.
- (void) readPageDown;  // Scroll to the next screen’s worth.
- (void) readPageUp;  // Scroll to the previous screen’s worth.
- (void) removeToolbuttonNamed:(NSString *)named;  // Remove the specified toolbutton from the toolbar.
- (void) replacePagesOver:(NSInteger)over from:(SBObject *)from startingWith:(NSInteger)startingWith numberOfPages:(NSInteger)numberOfPages mergeNotes:(BOOL)mergeNotes;  // Replaces page(s) with page(s) from another document.
- (void) scrollXAmount:(NSInteger)XAmount YAmount:(NSInteger)YAmount;  // Scroll the page by the specified amount (in device space).
- (void) selectTextFromWords:(NSArray *)fromWords fromChars:(NSArray *)fromChars;  // Selects text as specified by either character or word offsets.
- (void) setInfoKey:(NSString *)key value:(NSString *)value;  // Set a key/value string pair in the document’s Info dictionary.
- (void) zoomTo:(double)to;  // Zoom the display of the current page.

@end

// An annotation (corresponds to Acrobat’s internal PDAnnot class).
@interface AcrobatProAnnotation : SBObject

@property (copy, readonly) NSNumber *bestType;  // The best descriptor type.
@property (copy) NSArray *bounds;  // The boundary rectangle for the annotation, in PDF space (left, top, right, bottom).
@property (copy) id color;  // The color of the border around the annotation.
@property (copy) NSString *contents;  // Text subtype only: The textual contents of the annotation.
@property (copy, readonly) NSNumber *defaultType;  // The default descriptor type.
@property NSInteger destinationPageNumber;  // Link subtype only: The number of the page the PDF Window goes to when the link annotation is performed.
@property (copy) NSArray *destinationRectangle;  // Link subtype only: The boundary rectangle for the view of the destination, in PDF space (left, top, right, bottom).
@property (copy) id fitType;  // Link subtype only: Controls how the destination rectangle is fitted to the window when the annotation is performed. Valid values are: “Left Top Zoom”, “Fit Page”, “Fit Width”, “Fit Height”, “Fit Rect”, “Fit BBox”, “Fit BB Width”, and “Fit BB Height”.
@property (readonly) NSInteger index;  // The annotation’s index within a Page object.
@property (copy) NSDate *modificationDate;  // The date and time the annotation was last modified.
@property (copy) NSString *name;  // Text subtypes only: The annotation’s label.
@property BOOL openState;  // Text subtype only: Whether the annotation is open.
@property (copy, readonly) NSString *subtype;  // The subtype of the annotation.
@property double zoomFactor;  // Link subtype only: If fit type is “Left Top Zoom”, then this specifies the zoom factor, otherwise, this property is ignored. Setting this property automatically sets the fit type to “Left Top Zoom”.

- (void) closeSaving:(id)saving linearize:(BOOL)linearize;  // Close a document.
- (void) delete;  // Delete an element from an object.
- (BOOL) exists;  // Verify if an object exists.
- (SBObject *) moveTo:(SBObject *)to;  // Move object (only Page class objects can be moved).
- (void) saveTo:(NSURL *)to using:(SBObject *)using_ linearize:(BOOL)linearize;  // Save the document.
- (void) bringToFront;  // Bring the window containing the document to the front.
- (void) clearSelection;  // Clear any document selection.
- (void) createThumbs;  // Create thumbnails for all pages in the document.
- (void) deletePagesFirst:(NSInteger)first last:(NSInteger)last;  // Deletes the specified pages in the document.
- (void) deleteThumbs;  // Delete all thumbnails from the document.
- (void) execute;  // Execute the menu item as if the user clicked on it.
- (SBObject *) findNextNoteWrapAround:(BOOL)wrapAround;  // Find and select the next text note.
- (NSString *) findTextString:(NSString *)string CaseSensitive:(BOOL)CaseSensitive wholeWords:(BOOL)wholeWords wrapAround:(BOOL)wrapAround;  // Find text in a document.
- (void) getInfoKey:(NSString *)key;  // Get the string associated with the specified key.
- (void) goBackward;  // Go to the previous view in the stored view chain.
- (void) goForward;  // Go to the next view in the stored view chain.
- (void) gotoPage:(NSInteger)page;  // Make the PDF Window goto the specified page number.
- (void) gotoNext;  // Display the page after the one currently displayed in the PDF Window.
- (void) gotoPrevious;  // Display the page before the one currently displayed in the PDF Window.
- (void) insertPagesAfter:(NSInteger)after from:(SBObject *)from startingWith:(NSInteger)startingWith numberOfPages:(NSInteger)numberOfPages insertBookmarks:(BOOL)insertBookmarks;  // Insert page(s) from another document.
- (BOOL) isToolbuttonEnabledNamed:(NSString *)named;  // Whether the specified toolbutton is enabled or not.
- (void) maximizeMaxSize:(BOOL)maxSize;  // Set the document’s window’s size to be the maximum or its original size.
- (void) perform;  // Causes the object’s action to be executed.
- (void) printPagesFirst:(NSInteger)first last:(NSInteger)last PSLevel:(NSInteger)PSLevel binaryOutput:(BOOL)binaryOutput shrinkToFit:(BOOL)shrinkToFit;  // Print page(s) from a document.
- (void) readPageDown;  // Scroll to the next screen’s worth.
- (void) readPageUp;  // Scroll to the previous screen’s worth.
- (void) removeToolbuttonNamed:(NSString *)named;  // Remove the specified toolbutton from the toolbar.
- (void) replacePagesOver:(NSInteger)over from:(SBObject *)from startingWith:(NSInteger)startingWith numberOfPages:(NSInteger)numberOfPages mergeNotes:(BOOL)mergeNotes;  // Replaces page(s) with page(s) from another document.
- (void) scrollXAmount:(NSInteger)XAmount YAmount:(NSInteger)YAmount;  // Scroll the page by the specified amount (in device space).
- (void) selectTextFromWords:(NSArray *)fromWords fromChars:(NSArray *)fromChars;  // Selects text as specified by either character or word offsets.
- (void) setInfoKey:(NSString *)key value:(NSString *)value;  // Set a key/value string pair in the document’s Info dictionary.
- (void) zoomTo:(double)to;  // Zoom the display of the current page.

@end

// Only use this class as the target of a Make command!
@interface AcrobatProTextAnnotation : AcrobatProAnnotation


@end

// Only use this class as the target of a Make command!
@interface AcrobatProLinkAnnotation : AcrobatProAnnotation


@end

// A file type converter to export PDF files into other formats.
@interface AcrobatProConversion : SBObject

@property (copy, readonly) NSNumber *bestType;  // The best descriptor type.
@property (copy, readonly) NSNumber *defaultType;  // The default descriptor type.
@property (readonly) NSInteger index;  // The index number of the converter.
@property (copy) NSString *name;  // The file conversion’s description.

- (void) closeSaving:(id)saving linearize:(BOOL)linearize;  // Close a document.
- (void) delete;  // Delete an element from an object.
- (BOOL) exists;  // Verify if an object exists.
- (SBObject *) moveTo:(SBObject *)to;  // Move object (only Page class objects can be moved).
- (void) saveTo:(NSURL *)to using:(SBObject *)using_ linearize:(BOOL)linearize;  // Save the document.
- (void) bringToFront;  // Bring the window containing the document to the front.
- (void) clearSelection;  // Clear any document selection.
- (void) createThumbs;  // Create thumbnails for all pages in the document.
- (void) deletePagesFirst:(NSInteger)first last:(NSInteger)last;  // Deletes the specified pages in the document.
- (void) deleteThumbs;  // Delete all thumbnails from the document.
- (void) execute;  // Execute the menu item as if the user clicked on it.
- (SBObject *) findNextNoteWrapAround:(BOOL)wrapAround;  // Find and select the next text note.
- (NSString *) findTextString:(NSString *)string CaseSensitive:(BOOL)CaseSensitive wholeWords:(BOOL)wholeWords wrapAround:(BOOL)wrapAround;  // Find text in a document.
- (void) getInfoKey:(NSString *)key;  // Get the string associated with the specified key.
- (void) goBackward;  // Go to the previous view in the stored view chain.
- (void) goForward;  // Go to the next view in the stored view chain.
- (void) gotoPage:(NSInteger)page;  // Make the PDF Window goto the specified page number.
- (void) gotoNext;  // Display the page after the one currently displayed in the PDF Window.
- (void) gotoPrevious;  // Display the page before the one currently displayed in the PDF Window.
- (void) insertPagesAfter:(NSInteger)after from:(SBObject *)from startingWith:(NSInteger)startingWith numberOfPages:(NSInteger)numberOfPages insertBookmarks:(BOOL)insertBookmarks;  // Insert page(s) from another document.
- (BOOL) isToolbuttonEnabledNamed:(NSString *)named;  // Whether the specified toolbutton is enabled or not.
- (void) maximizeMaxSize:(BOOL)maxSize;  // Set the document’s window’s size to be the maximum or its original size.
- (void) perform;  // Causes the object’s action to be executed.
- (void) printPagesFirst:(NSInteger)first last:(NSInteger)last PSLevel:(NSInteger)PSLevel binaryOutput:(BOOL)binaryOutput shrinkToFit:(BOOL)shrinkToFit;  // Print page(s) from a document.
- (void) readPageDown;  // Scroll to the next screen’s worth.
- (void) readPageUp;  // Scroll to the previous screen’s worth.
- (void) removeToolbuttonNamed:(NSString *)named;  // Remove the specified toolbutton from the toolbar.
- (void) replacePagesOver:(NSInteger)over from:(SBObject *)from startingWith:(NSInteger)startingWith numberOfPages:(NSInteger)numberOfPages mergeNotes:(BOOL)mergeNotes;  // Replaces page(s) with page(s) from another document.
- (void) scrollXAmount:(NSInteger)XAmount YAmount:(NSInteger)YAmount;  // Scroll the page by the specified amount (in device space).
- (void) selectTextFromWords:(NSArray *)fromWords fromChars:(NSArray *)fromChars;  // Selects text as specified by either character or word offsets.
- (void) setInfoKey:(NSString *)key value:(NSString *)value;  // Set a key/value string pair in the document’s Info dictionary.
- (void) zoomTo:(double)to;  // Zoom the display of the current page.

@end

// A converter to export PDF files into PostScript format.
@interface AcrobatProPostScriptConversion : AcrobatProConversion

@property NSInteger postScriptLevel;  // The PostScript Language Level.  Levels 2 and 3 are supported, but not Level 1.
@property BOOL binary;  // Format for output file (ASCII text or binary).
@property BOOL embeddedFonts;  // Whether or not to include fonts.
@property BOOL annotations;  // Whether or not to include annotations.
@property BOOL halftones;  // Whether or not to include halftone screens.
@property BOOL images;  // Obsolete and ignored.
@property BOOL preview;  // Whether or not to include preview in output.
@property BOOL TrueType;  // Whether or not to convert TrueType to Type 1 fonts.


@end

// A file type converter to export PDF files to the EPS format.
@interface AcrobatProEPSConversion : AcrobatProPostScriptConversion


@end

// Obsolete.  Please use PDF window instead.
@interface AcrobatProAVPageView : AcrobatProPDFWindow


@end

// Obsolete.  Please use Page instead.
@interface AcrobatProPDPage : AcrobatProPage


@end

// Obsolete.  Please use Bookmark instead.
@interface AcrobatProPDBookmark : AcrobatProBookmark


@end

// Obsolete.  Please use Annotation instead.
@interface AcrobatProPDAnnot : AcrobatProAnnotation


@end

// Obsolete.  Please use Text Annotation instead.
@interface AcrobatProPDTextAnnot : AcrobatProTextAnnotation


@end

// Obsolete.  Please use Link Annotation instead.
@interface AcrobatProPDLinkAnnot : AcrobatProLinkAnnotation


@end



/*
 * miscellaneous standards
 */

// A menu of Acrobat.  Includes some menus that don't show in UI.
@interface AcrobatProMenu : SBObject

- (SBElementArray *) menuItems;

@property (copy, readonly) NSNumber *bestType;  // The best descriptor type.
@property (copy, readonly) NSNumber *defaultType;  // The default descriptor type.
@property (copy, readonly) NSString *name;  // The menu’s name (a language-independent name that uniquely identifies the menu).
@property (copy, readonly) NSString *title;  // The menu’s title (as shown in the menu itself). This title will be in the application’s UI language.

- (void) closeSaving:(id)saving linearize:(BOOL)linearize;  // Close a document.
- (void) delete;  // Delete an element from an object.
- (BOOL) exists;  // Verify if an object exists.
- (SBObject *) moveTo:(SBObject *)to;  // Move object (only Page class objects can be moved).
- (void) saveTo:(NSURL *)to using:(SBObject *)using_ linearize:(BOOL)linearize;  // Save the document.
- (void) bringToFront;  // Bring the window containing the document to the front.
- (void) clearSelection;  // Clear any document selection.
- (void) createThumbs;  // Create thumbnails for all pages in the document.
- (void) deletePagesFirst:(NSInteger)first last:(NSInteger)last;  // Deletes the specified pages in the document.
- (void) deleteThumbs;  // Delete all thumbnails from the document.
- (void) execute;  // Execute the menu item as if the user clicked on it.
- (SBObject *) findNextNoteWrapAround:(BOOL)wrapAround;  // Find and select the next text note.
- (NSString *) findTextString:(NSString *)string CaseSensitive:(BOOL)CaseSensitive wholeWords:(BOOL)wholeWords wrapAround:(BOOL)wrapAround;  // Find text in a document.
- (void) getInfoKey:(NSString *)key;  // Get the string associated with the specified key.
- (void) goBackward;  // Go to the previous view in the stored view chain.
- (void) goForward;  // Go to the next view in the stored view chain.
- (void) gotoPage:(NSInteger)page;  // Make the PDF Window goto the specified page number.
- (void) gotoNext;  // Display the page after the one currently displayed in the PDF Window.
- (void) gotoPrevious;  // Display the page before the one currently displayed in the PDF Window.
- (void) insertPagesAfter:(NSInteger)after from:(SBObject *)from startingWith:(NSInteger)startingWith numberOfPages:(NSInteger)numberOfPages insertBookmarks:(BOOL)insertBookmarks;  // Insert page(s) from another document.
- (BOOL) isToolbuttonEnabledNamed:(NSString *)named;  // Whether the specified toolbutton is enabled or not.
- (void) maximizeMaxSize:(BOOL)maxSize;  // Set the document’s window’s size to be the maximum or its original size.
- (void) perform;  // Causes the object’s action to be executed.
- (void) printPagesFirst:(NSInteger)first last:(NSInteger)last PSLevel:(NSInteger)PSLevel binaryOutput:(BOOL)binaryOutput shrinkToFit:(BOOL)shrinkToFit;  // Print page(s) from a document.
- (void) readPageDown;  // Scroll to the next screen’s worth.
- (void) readPageUp;  // Scroll to the previous screen’s worth.
- (void) removeToolbuttonNamed:(NSString *)named;  // Remove the specified toolbutton from the toolbar.
- (void) replacePagesOver:(NSInteger)over from:(SBObject *)from startingWith:(NSInteger)startingWith numberOfPages:(NSInteger)numberOfPages mergeNotes:(BOOL)mergeNotes;  // Replaces page(s) with page(s) from another document.
- (void) scrollXAmount:(NSInteger)XAmount YAmount:(NSInteger)YAmount;  // Scroll the page by the specified amount (in device space).
- (void) selectTextFromWords:(NSArray *)fromWords fromChars:(NSArray *)fromChars;  // Selects text as specified by either character or word offsets.
- (void) setInfoKey:(NSString *)key value:(NSString *)value;  // Set a key/value string pair in the document’s Info dictionary.
- (void) zoomTo:(double)to;  // Zoom the display of the current page.

@end

// A menu item.
@interface AcrobatProMenuItem : SBObject

@property (copy, readonly) NSNumber *bestType;  // The best descriptor type.
@property (copy, readonly) NSNumber *defaultType;  // The default descriptor type.
@property (readonly) BOOL enabled;  // Whether the menu item is enabled.
@property (readonly) BOOL marked;  // Whether the menu item is checked.
@property (copy, readonly) NSString *name;  // The menu item’s name (a language-independent name that uniquely identifies the menu item).
@property (copy) NSString *title;  // The menu item’s title (as shown in the menu item itself). This title will be in the application’s UI language.
@property (readonly) BOOL hasSubmenu;  // Whether the menu item has a hierarchical sub-menu.

- (void) closeSaving:(id)saving linearize:(BOOL)linearize;  // Close a document.
- (void) delete;  // Delete an element from an object.
- (BOOL) exists;  // Verify if an object exists.
- (SBObject *) moveTo:(SBObject *)to;  // Move object (only Page class objects can be moved).
- (void) saveTo:(NSURL *)to using:(SBObject *)using_ linearize:(BOOL)linearize;  // Save the document.
- (void) bringToFront;  // Bring the window containing the document to the front.
- (void) clearSelection;  // Clear any document selection.
- (void) createThumbs;  // Create thumbnails for all pages in the document.
- (void) deletePagesFirst:(NSInteger)first last:(NSInteger)last;  // Deletes the specified pages in the document.
- (void) deleteThumbs;  // Delete all thumbnails from the document.
- (void) execute;  // Execute the menu item as if the user clicked on it.
- (SBObject *) findNextNoteWrapAround:(BOOL)wrapAround;  // Find and select the next text note.
- (NSString *) findTextString:(NSString *)string CaseSensitive:(BOOL)CaseSensitive wholeWords:(BOOL)wholeWords wrapAround:(BOOL)wrapAround;  // Find text in a document.
- (void) getInfoKey:(NSString *)key;  // Get the string associated with the specified key.
- (void) goBackward;  // Go to the previous view in the stored view chain.
- (void) goForward;  // Go to the next view in the stored view chain.
- (void) gotoPage:(NSInteger)page;  // Make the PDF Window goto the specified page number.
- (void) gotoNext;  // Display the page after the one currently displayed in the PDF Window.
- (void) gotoPrevious;  // Display the page before the one currently displayed in the PDF Window.
- (void) insertPagesAfter:(NSInteger)after from:(SBObject *)from startingWith:(NSInteger)startingWith numberOfPages:(NSInteger)numberOfPages insertBookmarks:(BOOL)insertBookmarks;  // Insert page(s) from another document.
- (BOOL) isToolbuttonEnabledNamed:(NSString *)named;  // Whether the specified toolbutton is enabled or not.
- (void) maximizeMaxSize:(BOOL)maxSize;  // Set the document’s window’s size to be the maximum or its original size.
- (void) perform;  // Causes the object’s action to be executed.
- (void) printPagesFirst:(NSInteger)first last:(NSInteger)last PSLevel:(NSInteger)PSLevel binaryOutput:(BOOL)binaryOutput shrinkToFit:(BOOL)shrinkToFit;  // Print page(s) from a document.
- (void) readPageDown;  // Scroll to the next screen’s worth.
- (void) readPageUp;  // Scroll to the previous screen’s worth.
- (void) removeToolbuttonNamed:(NSString *)named;  // Remove the specified toolbutton from the toolbar.
- (void) replacePagesOver:(NSInteger)over from:(SBObject *)from startingWith:(NSInteger)startingWith numberOfPages:(NSInteger)numberOfPages mergeNotes:(BOOL)mergeNotes;  // Replaces page(s) with page(s) from another document.
- (void) scrollXAmount:(NSInteger)XAmount YAmount:(NSInteger)YAmount;  // Scroll the page by the specified amount (in device space).
- (void) selectTextFromWords:(NSArray *)fromWords fromChars:(NSArray *)fromChars;  // Selects text as specified by either character or word offsets.
- (void) setInfoKey:(NSString *)key value:(NSString *)value;  // Set a key/value string pair in the document’s Info dictionary.
- (void) zoomTo:(double)to;  // Zoom the display of the current page.

@end

