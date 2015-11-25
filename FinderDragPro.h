/*	File:		FinderDragPro.h		Description: 	Sample file illustrating drag and drop techniques for use				with file system objects.  This file illustrates how applications				can use drag and drop commands in a way compatible with current				and past versions of the Finder.	Author:		John Montbriand	Copyright: 	Copyright: � 1999 by Apple Computer, Inc.				all rights reserved.		Disclaimer:	You may incorporate this sample code into your applications without				restriction, though the sample code has been provided "AS IS" and the				responsibility for its operation is 100% yours.  However, what you are				not permitted to do is to redistribute the source as "DSC Sample Code"				after having made changes. If you're going to re-distribute the source,				we require that you make it clear in the source that the code was				descended from Apple Sample Code, but that you've made changes.		Change History (most recent first):	9/9/99 by John Montbriand*/#ifndef __FINDERDRAGPRO__#define __FINDERDRAGPRO__#include <MacTypes.h>#include <Drag.h>	/* apple menu constants */enum {	mApple = 128,	iAbout = 1,	iFirstAppleItem = 3};	/* file menu constants */enum {	mFile = 129,	iNew = 1,	iOpen = 2,	iClose = 3,	iSave = 5,	iSaveAs = 6,	iRevert = 7,	iPageSetup = 9,	iPrint = 10,	iQuit = 12};	/* edit menu constants */enum {	mEdit = 130,	iUndo = 1,	iCut = 3,	iCopy = 4,	iPaste = 5,	iClear = 6};enum {	/* the main menu bar resource */	kFDPMenuBarResource = 128};	/* main window dialog constants */enum {	kFDPDialogResource = 128,	kFDPUserItem = 1,	kFDPhfsItem = 2,	kFDPpromiseItem = 3,		/* kUsePromiseHFS and kUseRegularHFS are used for		internal tracking of the state of the kFDPhfsItem and		the kFDPpromiseItem dialog controls. */	kUsePromiseHFS = 100, /* output promise hfs flavors in drags */	kUseRegularHFS = 101,/* output hfs flavors in drags */	kFDPDragItemID = 392 /* item identifier for our drags */};enum {	/* picture displayed when selection is empty */	kFDPSpashPictResource = 128};	/* constants for the copy progress dialog */enum {	kCopyProgressTicksOffset = 50, /* 50 ticks before the progress box pops up */	kCopyProgressDialog = 130,	kPlainCopyProgressDialog = 131,	kCProCancelItem = 1,	kCProIndicatorItem = 2};	/* alert id numbers */enum {	kCannotCopyDirAlert = 132,	kCopyFailedAlert = 133,	kDragFailedAlert = 134,	kOpenAppFailedAlert = 135,	kMainFailedAlert = 136,	kAboutBoxAlert = 137,	kNoDragManagerAlert = 138,	kNoThreadManagerAlert = 139};	/* promise flavor types */enum {	kPromisedFlavor = 'fssP',		/* default promise */	kPromisedFlavorFindFile = 'rWm1' /* Find File promise -- special case */};	/* internal error codes.  Operating system errors are	negative.  We use positive ones for our own internal errors.  */enum {	kNoDragMgrError = 1235, /* drag manager not installed */	kNoThreadMgrError = 1236 /* thread manager not installed */};enum {		/* sleep value passed to WaitNextEvent.  Normally		we'll delay for 1 second between events, unless		we're performing a file copy. */ 	kNormalSleepTime = (1*60), /* normal operation -> 1 second */	kCopySleepTime = 0 /* during copies -> return as soon as possible */};/* routine prototypes *//* ProcessNextEvent calls WaitNextEvent to get the next event and then it passes	the event along to the HandleNextEvent routine.  sleepTime is passed to the	WaitNextEvent routine in the sleep parameter. */void ProcessNextEvent(long sleepTime);/* ParamAlert is a general alert handling routine.  If Apple events exist, then it	calls AEInteractWithUser to ensure the application is in the forground, and then	it displays an alert after passing the s1 and s2 parameters to ParamText. */short ParamAlert(short alertID, StringPtr s1, StringPtr s2);/* SetNewDisplay is called to set the file or folder being displayed in the main window.	Here, structures are deallocated and an alias is saved referring to the file. 	SetNewDisplay is called from the drag receive handler and since it is not	safe to call "GetIconSuiteFromFinder()" from inside of the drag receive handler	(it uses apple events), the flag gFileUpToDate is used to defer that operation	until the next time ValidateFDPWindowDisplay.  ValidateFDPWindowDisplay is	called from the main loop.  If targetFile is NULL, then the display is cleared. */void SetNewDisplay(HFSFlavor *targetFile);#endif