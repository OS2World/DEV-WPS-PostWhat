
/*
 *  This file was generated by the SOM Compiler.
 *  Generated using:
 *     SOM incremental update: 2.47
 */


/*
 *  This file was generated by the SOM Compiler and Emitter Framework.
 *  Generated using template emitter:
 *      SOM Emitter emitxtm: 2.47
 */

#ifndef SOM_Module_postwhat_Source
#define SOM_Module_postwhat_Source
#endif
#define PostWhat_Class_Source
#define M_PostWhat_Class_Source

#define _RETAIL /* to completely eliminate the ...MethodDebug(...) debugging output to SOMOutCharRoutine (default:stdout) */
#include "postwhat.xih"

#include <stdio.h>
#include "rc.h"
#include "except.h"
#include "error.h"
#include "filehlp.h"


typedef struct _PERVIEW
{
    USEITEM         useItem;
    VIEWITEM        viewItem;
} PERVIEW, *PPERVIEW;



HMODULE     g_hModule   = NULLHANDLE;

ULONG APIENTRY _DLL_InitTerm(ULONG modhandle,ULONG flag)
{
    if(flag == 0)
    {
#ifndef __IMPORTLIB__
        if (_CRT_init())
        {
            return 0; /* fail */
        }
#endif
#ifdef __cplusplus
        __ctordtorInit();
#endif
        g_hModule   = modhandle;
        return 1;
    }
    else if (flag == 1)
    {
#ifdef __cplusplus
        __ctordtorTerm();
#endif

#ifndef __IMPORTLIB__
        _CRT_term();
#endif
        return 1; /* success */
    }
    else
    {
        return 0;
    }
}

SOMEXTERN VOID SOMLINK SOMInitModule(long majorVersion,long minorVersion, string className)
{
    SOM_IgnoreWarning(majorVersion);
    SOM_IgnoreWarning(minorVersion);
    SOM_IgnoreWarning(className);
    PostWhatNewClass(PostWhat_MajorVersion,PostWhat_MinorVersion);
    return;
}



MRESULT EXPENTRY WndProc(HWND hwndMLE,ULONG msg,MPARAM mp1,MPARAM mp2)
{
    PostWhat *somSelf;
    PostWhatData *somThis;
    PFNWP oldWndProc;
    PPERVIEW pView;
    PBASEWNDWORDS pBase;
    HWND hwndFrame,hwndTitleBar,hwndMenu;
    BOOL bRC;

    hwndFrame       = WinQueryWindow(hwndMLE,QW_PARENT);
    hwndTitleBar    = WinWindowFromID(hwndFrame,FID_TITLEBAR);
    hwndMenu        = WinWindowFromID(hwndFrame,FID_MENU);

    pBase = _PostWhat->wpclsGetPerViewData(hwndMLE,WndProc);

    switch(msg)
    {
        case WM_INIT:
            PERVIEW view;
            memset(&view,0,sizeof(view));
            view.useItem.type   = USAGE_OPENVIEW;
            view.viewItem.view  = MENUID_POSTWHATVIEW;
            view.viewItem.handle = hwndFrame;
            if ((pBase = _PostWhat->wpclsAllocPerViewData(hwndMLE,msg,mp1,mp2,WndProc,&view,sizeof(view))) == NULL)
            {
                WinDestroyWindow(hwndFrame);
            }
            else
            {
                CHAR presParam[FACESIZE+16]={0};
                RGB2 rgb2Value;
                PULONG prgb2Value = (PULONG)&rgb2Value;
                CHAR keyName[32];
                HOBJECT handle=NULLHANDLE;
                PSZ appName=NULL;

                somSelf = (PostWhat*)_PostWhat->wpclsGetsomSelfFromPerViewData(pBase);
                somThis = (PostWhatData*)_PostWhat->wpclsGetsomThisFromPerViewData(pBase);
                pView = (PPERVIEW)_PostWhat->wpclsGetUserDataFromPerViewData(pBase);

                /*
                * appName     = somSelf->somGetClassName();
                * in order to avoid cluttering OS2.INI, we save/restore
                * the window position under the appname of the
                * original class even if this class should be replaced
                * by another one
                */
                appName     = _PostWhat->somGetName();


                handle      = somSelf->wpQueryHandle();
                _itoa(handle,keyName,10);
                bRC = WinRestoreWindowPos(appName,keyName,hwndFrame);

                *prgb2Value = 0x00FFFFA0;
                bRC = WinSetPresParam(hwndMLE,PP_BACKGROUNDCOLOR,sizeof(rgb2Value),&rgb2Value);

                *prgb2Value = 0x00FFFFA0;
                bRC = WinSetPresParam(hwndMLE,PP_FIELDBACKGROUNDCOLOR,sizeof(rgb2Value),&rgb2Value);

                /*
                * This does not seem to have any effect
                * *prgb2Value = 0x00F4AA8F;
                * bRC = WinSetPresParam(hwndMLE,PP_HILITEBACKGROUNDCOLOR,sizeof(rgb2Value),&rgb2Value);
                */

                strcpy(presParam,"8.Helv");
                bRC = WinSetPresParam(hwndMLE,PP_FONTNAMESIZE,sizeof(presParam),presParam);

                *prgb2Value = RGB_BLACK;
                bRC = WinSetPresParam(hwndTitleBar,PP_ACTIVETEXTFGNDCOLOR,sizeof(rgb2Value),&rgb2Value);
                bRC = WinSetPresParam(hwndMenu,PP_MENUFOREGROUNDCOLOR,sizeof(rgb2Value),&rgb2Value);

                *prgb2Value = 0x00FFFFA0;
                bRC = WinSetPresParam(hwndFrame,PP_ACTIVECOLOR,sizeof(rgb2Value),&rgb2Value);
                bRC = WinSetPresParam(hwndTitleBar,PP_ACTIVECOLOR,sizeof(rgb2Value),&rgb2Value);
                bRC = WinSetPresParam(hwndTitleBar,PP_ACTIVETEXTBGNDCOLOR,sizeof(rgb2Value),&rgb2Value);
                bRC = WinSetPresParam(hwndMenu,PP_MENUBACKGROUNDCOLOR,sizeof(rgb2Value),&rgb2Value);

                *prgb2Value = 0x00FFFFC8;
                bRC = WinSetPresParam(hwndFrame,PP_INACTIVECOLOR,sizeof(rgb2Value),&rgb2Value);
                bRC = WinSetPresParam(hwndTitleBar,PP_INACTIVECOLOR,sizeof(rgb2Value),&rgb2Value);
                bRC = WinSetPresParam(hwndTitleBar,PP_INACTIVETEXTBGNDCOLOR,sizeof(rgb2Value),&rgb2Value);
                bRC = WinSetPresParam(hwndMenu,PP_MENUHILITEBGNDCOLOR,sizeof(rgb2Value),&rgb2Value);

                *prgb2Value = 0x00CCCCCC;
                bRC = WinSetPresParam(hwndMenu,PP_MENUHILITEFGNDCOLOR,sizeof(rgb2Value),&rgb2Value);

                bRC = WinSetWindowPos   (
                                            hwndFrame,
                                            NULLHANDLE,
                                            0,0,0,0,
                                            SWP_SHOW|SWP_ACTIVATE
                                        );

                WinSendMsg(hwndMLE,MLM_FORMAT,MPFROMLONG(MLFIE_NOTRANS),MPVOID);
                WinSendMsg(hwndMLE,MLM_RESETUNDO,MPVOID,MPVOID);
                WinEnableMenuItem(hwndMenu,MENUID_UNDO,TRUE);
                WinEnableMenuItem(hwndMenu,MENUID_CUT,FALSE);
                WinEnableMenuItem(hwndMenu,MENUID_COPY,FALSE);
                WinEnableMenuItem(hwndMenu,MENUID_PASTE,TRUE);

                TRY(except)
                {
                    bRC = somSelf->wpAddToObjUseList(&pView->useItem);

                    if (somThis->pNoteData)
                    {
                        IPT ipt=0;
                        WinSendMsg(hwndMLE,MLM_SETIMPORTEXPORT,MPFROMP(somThis->pNoteData),MPFROMLONG(somThis->ulNoteDataLen));
                        WinSendMsg(hwndMLE,MLM_IMPORT,MPFROMP(&ipt),MPFROMLONG(somThis->ulNoteDataLen));
                    }
                }
                CATCH(except)
                {
                    APIRET rc;
                    rc = LogError(400,g_hModule,__FILE__,__LINE__,&except.repRec);
                }
                ENDTRY()
            }
            return (MRESULT)0;

        case WM_CLOSE:
            WinDestroyWindow(hwndFrame);
            return (MRESULT)0;

        case WM_COMMAND:
            switch(SHORT1FROMMP(mp1))
            {
                case MENUID_CUT:
                    WinSendMsg(hwndMLE,MLM_CUT,MPVOID,MPVOID);
                    return (MRESULT)0;

                case MENUID_COPY:
                    WinSendMsg(hwndMLE,MLM_COPY,MPVOID,MPVOID);
                    return (MRESULT)0;

                case MENUID_PASTE:
                    WinSendMsg(hwndMLE,MLM_PASTE,MPVOID,MPVOID);
                    return (MRESULT)0;

                case MENUID_UNDO:
                    WinSendMsg(hwndMLE,MLM_UNDO,MPVOID,MPVOID);
                    return (MRESULT)0;

                case MENUID_IMPORT:
                    {
                        MRESULT mres;
                        FILEDLG fdg;
                        PSZ types[]={"PostWhat Note",DRT_TEXT,NULL};
                        APIRET rc;

                        memset(&fdg,0,sizeof(fdg));
                        fdg.cbSize      = sizeof(fdg);
                        fdg.fl          = FDS_CENTER | FDS_OPEN_DIALOG | FDS_INCLUDE_EAS;
                        fdg.pszTitle    = "Import a note's contents";
                        fdg.pszIType    = types[0];
                        fdg.papszITypeList= (PAPSZ)types;
                        strcpy(fdg.szFullFile,"*.txt;*.pwn");
                        WinFileDlg(HWND_DESKTOP,NULL,&fdg);
                        if (fdg.lReturn == DID_OK)
                        {
                            rc = WriteMLEBufferFromFile(hwndMLE,fdg.szFullFile);
                        }
                    }
                    return (MRESULT)0;

                case MENUID_EXPORT:
                    {
                        FILEDLG fdg;
                        PSZ types[]={"PostWhat Note",NULL};
                        APIRET rc;

                        memset(&fdg,0,sizeof(fdg));
                        fdg.cbSize = sizeof(fdg);
                        fdg.fl      = FDS_CENTER | FDS_SAVEAS_DIALOG | FDS_ENABLEFILELB | FDS_INCLUDE_EAS;
                        fdg.pszTitle    = "Export a note's contents";
                        fdg.pszIType    = types[0];
                        fdg.papszITypeList= (PAPSZ)types;
                        strcpy(fdg.szFullFile,"*.pwn");
                        WinFileDlg(HWND_DESKTOP,HWND_DESKTOP,&fdg);
                        if (fdg.lReturn == DID_OK)
                        {
                            rc = WriteFileFromMLEBuffer(fdg.szFullFile,types[0],hwndMLE);
                        }
                    }
                    return (MRESULT)0;

                default: break;
            }

        case WM_BUTTON1DBLCLK:
            WinEnableMenuItem(hwndMenu,MENUID_CUT,TRUE);
            WinEnableMenuItem(hwndMenu,MENUID_COPY,TRUE);
            break;

        case WM_BUTTON1UP:
            IPT iptMin,iptMax;
            iptMin = (IPT)WinSendMsg(hwndMLE,MLM_QUERYSEL,MPFROMLONG(MLFQS_MINSEL),MPVOID);
            iptMax = (IPT)WinSendMsg(hwndMLE,MLM_QUERYSEL,MPFROMLONG(MLFQS_MAXSEL),MPVOID);
            WinEnableMenuItem(hwndMenu,MENUID_CUT,iptMin == iptMax ? FALSE : TRUE);
            WinEnableMenuItem(hwndMenu,MENUID_COPY,iptMin == iptMax ? FALSE : TRUE);
            break;

        case WM_SAVEAPPLICATION:
            if ((somSelf = (PostWhat *)_PostWhat->wpclsGetsomSelfFromPerViewData(pBase)) != NULL)
            {
                HOBJECT handle=NULLHANDLE;
                PSZ appName=NULL;
                CHAR keyName[32];

                /*
                * appName     = somSelf->somGetClassName();
                * in order to avoid cluttering OS2.INI, we save/restore
                * the window position under the appname of the
                * original class even if this class should be replaced
                * by another one
                */
                appName     = _PostWhat->somGetName();

                handle      = somSelf->wpQueryHandle();
                _itoa(handle,keyName,10);

                WinStoreWindowPos(appName,keyName,hwndFrame);
            }
            break;

        case WM_DESTROY:
            if (pBase)
            {
                ULONG ulLen;
                MRESULT mres;

                somSelf = (PostWhat *)_PostWhat->wpclsGetsomSelfFromPerViewData(pBase);
                somThis = (PostWhatData*)_PostWhat->wpclsGetsomThisFromPerViewData(pBase);

                TRY(except)
                {
                    IPT ipt=0;

                    if (somThis->pNoteData)
                    {
                        somSelf->wpFreeMem(somThis->pNoteData);
                    }
                    ulLen = (ULONG)WinSendMsg(hwndMLE,MLM_QUERYFORMATTEXTLENGTH,MPFROMLONG(ipt),MPFROMLONG(-1));
                    somThis->pNoteData     = somSelf->wpAllocMem(ulLen,NULL);
                    if (somThis->pNoteData)
                    {
                        somThis->ulNoteDataLen = ulLen;
                        WinSendMsg(hwndMLE,MLM_SETIMPORTEXPORT,MPFROMP(somThis->pNoteData),MPFROMLONG(ulLen));
                        if (WinSendMsg(hwndMLE,MLM_EXPORT,MPFROMP(&ipt),MPFROMP(&ulLen)))
                        {
                            somSelf->wpSaveDeferred();
                        }
                    }
                }
                CATCH(except)
                {
                    APIRET rc;
                    rc = LogError(100,g_hModule,__FILE__,__LINE__,&except.repRec);
                }
                ENDTRY()

                pView = (PPERVIEW)_PostWhat->wpclsGetUserDataFromPerViewData(pBase);
                bRC = somSelf->wpDeleteFromObjUseList(&pView->useItem);
                bRC = _PostWhat->wpclsFreePerViewData(hwndMLE,WndProc);
            }
            return (MRESULT)0;

        default:
            break;
    }

    return _PostWhat->wpclsClassDefaultWindowProc(hwndMLE,msg,mp1,mp2,WndProc);
}

SOM_Scope void  SOMLINK wpSubClassWindow(PostWhat *somSelf, HWND hwnd,
                                       PFNWP WndProc)
{
    PFNWP oldWndProc;

    PostWhatData *somThis = PostWhatGetData(somSelf);
    PostWhatMethodDebug("PostWhat","SubClassWindow");

    oldWndProc = WinSubclassWindow(hwnd,WndProc);
    WinSendMsg(hwnd,WM_INIT,MPFROMP(somSelf),MPFROMP(oldWndProc));
    return;
}

SOM_Scope void SOMLINK somDefaultInit(PostWhat *somSelf, som3InitCtrl* ctrl)
{
    PostWhatData *somThis; /* set in BeginInitializer */
    somInitCtrl globalCtrl;
    somBooleanVector myMask;
    PostWhatMethodDebug("PostWhat","somDefaultInit");
    PostWhat_BeginInitializer_somDefaultInit;

    PostWhat_Init_WPAbstract_somDefaultInit(somSelf, ctrl);

    /*
     * local PostWhat initialization code added by programmer
     */
}


SOM_Scope void SOMLINK somDestruct(PostWhat *somSelf, octet doFree,
                                   som3DestructCtrl* ctrl)
{
    PostWhatData *somThis; /* set in BeginDestructor */
    somDestructCtrl globalCtrl;
    somBooleanVector myMask;
    PostWhatMethodDebug("PostWhat","somDestruct");
    PostWhat_BeginDestructor;

    /*
     * local PostWhat deinitialization code added by programmer
     */

    PostWhat_EndDestructor;
}



SOM_Scope BOOL  SOMLINK wpSaveState(PostWhat *somSelf)
{
    BOOL fRet;
    PSZ pszClass;

    PostWhatData *somThis = PostWhatGetData(somSelf);
    PostWhatMethodDebug("PostWhat","wpSaveState");

    /*
        we have a problem here: whatever data wpSaveState saves
        it associates this data with the WPS class of the object
        that calls this function
        Now, what we do is save the text of the MLE. But if this class is replaced
        we want the replacement class to also be able to access that data
        (otherwise it would be inaccessible/lost to the replacement class)
        Therefore we report as classname the original class
        that will assure that no matter if this class or a replacing class is
        active, in any case they will both be able to access the same data as
        to the class manager it looks like an object of the original class
        accessed the data
    */
    pszClass     = _PostWhat->somGetName();
    fRet =  (PostWhat_parent_WPAbstract_wpSaveState(somSelf));

    if (fRet)
    {
        TRY(except)
        {
            BOOL fRet;
            APIRET rc;

            if (somThis->pNoteData)
            {
                fRet = somSelf->wpSaveData(pszClass,KEY_NOTEDATA,somThis->pNoteData,somThis->ulNoteDataLen);
            }
        }
        CATCH(except)
        {
            APIRET rc;
            rc = LogError(200,g_hModule,__FILE__,__LINE__,&except.repRec);
        }
        ENDTRY()
    }

    return fRet;
}

SOM_Scope BOOL  SOMLINK wpRestoreState(PostWhat *somSelf, ULONG ulReserved)
{
    BOOL fRet;
    PSZ pszClass;

    PostWhatData *somThis = PostWhatGetData(somSelf);
    PostWhatMethodDebug("PostWhat","wpRestoreState");

    /*
        we have a problem here: whatever data wpRestoreState restores
        that data is associated with the WPS class of the object
        that calls this function
        Now, what we do is restore the text of the MLE. But if this class is replaced
        we want the replacement class to also be able to access that data
        (otherwise it would be inaccessible/lost to the replacement class)
        Therefore we report as classname the original class
        that will assure that no matter if this class or a replacing class is
        active, in any case they will both be able to access the same data as
        to the class manager it looks like an object of the original class
        accessed the data
    */
    pszClass     = _PostWhat->somGetName();
    fRet = (PostWhat_parent_WPAbstract_wpRestoreState(somSelf,
                                                      ulReserved));
    if (fRet)
    {
        TRY(except)
        {
            ULONG fRet;
            APIRET rc;

            somThis->ulNoteDataLen = 0;
            fRet = somSelf->wpRestoreData(pszClass,KEY_NOTEDATA,NULL,&somThis->ulNoteDataLen);
            if (fRet && somThis->ulNoteDataLen)
            {
                if (somThis->pNoteData)
                {
                    somSelf->wpFreeMem(somThis->pNoteData);
                }
                somThis->pNoteData = somSelf->wpAllocMem(somThis->ulNoteDataLen,NULL);
                if (somThis->pNoteData)
                {
                    fRet = somSelf->wpRestoreData(pszClass,KEY_NOTEDATA,somThis->pNoteData,&somThis->ulNoteDataLen);
                }
            }
        }
        CATCH(except)
        {
            APIRET rc;
            rc = LogError(300,g_hModule,__FILE__,__LINE__,&except.repRec);
        }
        ENDTRY()
    }

    return fRet;
}

/*
SOM_Scope BOOL  SOMLINK wpFilterMenu(PostWhat *somSelf, FILTERFLAGS* pFlags,
                                     HWND hwndCnr, BOOL fMultiSelect,
                                     ULONG ulMenuType, ULONG ulView,
                                     ULONG ulReserved)
{
    BOOL bRet;

    PostWhatData *somThis = PostWhatGetData(somSelf);
    PostWhatMethodDebug("PostWhat","wpFilterMenu");
    bRet =  (PostWhat_parent_WPAbstract_wpFilterMenu(somSelf,
                                                    pFlags, hwndCnr,
                                                    fMultiSelect,
                                                    ulMenuType,
                                                    ulView, ulReserved));

    if (bRet)
    {
        if (pFlags && (ulMenuType == MENU_OBJECTPOPUP))
        {
            pFlags->Flags[0] &= ~(CTXT_ICON|CTXT_TREE|CTXT_DETAILS);
        }
    }

    return bRet;
}
*/

SOM_Scope ULONG  SOMLINK wpFilterPopupMenu(PostWhat *somSelf,
                                           ULONG ulFlags, HWND hwndCnr,
                                           BOOL fMultiSelect)
{
    ULONG ulParentFlags;

    PostWhatData *somThis = PostWhatGetData(somSelf);
    PostWhatMethodDebug("PostWhat","wpFilterPopupMenu");

    ulParentFlags = (PostWhat_parent_WPAbstract_wpFilterPopupMenu(somSelf,
                                                         ulFlags,
                                                         hwndCnr,
                                                         fMultiSelect));

    return (ulParentFlags | (CTXT_CRANOTHER) & ~(CTXT_ICON|CTXT_TREE|CTXT_DETAILS));
}

/*
SOM_Scope BOOL  SOMLINK wpModifyMenu(PostWhat *somSelf, HWND hwndMenu,
                                     HWND hwndCnr, ULONG iPosition,
                                     ULONG ulMenuType, ULONG ulView,
                                     ULONG ulReserved)
{
    BOOL bRet;

    PostWhatData *somThis = PostWhatGetData(somSelf);
    PostWhatMethodDebug("PostWhat","wpModifyMenu");

    bRet = (PostWhat_parent_WPAbstract_wpModifyMenu(somSelf,
                                                    hwndMenu,
                                                    hwndCnr,
                                                    iPosition,
                                                    ulMenuType,
                                                    ulView, ulReserved));

    if (bRet && (ulMenuType == MENU_OBJECTPOPUP))
    {
        bRet = somSelf->wpInsertMenuItems(hwndMenu,iPosition,g_hModule,ID_POPUPMENU,WPMENUID_OPEN);
    }

    return bRet;
}
*/

SOM_Scope BOOL  SOMLINK wpModifyPopupMenu(PostWhat *somSelf,
                                          HWND hwndMenu, HWND hwndCnr,
                                          ULONG iPosition)
{
    BOOL bRet;

    PostWhatData *somThis = PostWhatGetData(somSelf);
    PostWhatMethodDebug("PostWhat","wpModifyPopupMenu");

    bRet = (PostWhat_parent_WPAbstract_wpModifyPopupMenu(somSelf,
                                                         hwndMenu,
                                                         hwndCnr,
                                                         iPosition));


    if (bRet)
    {
        bRet = somSelf->wpInsertPopupMenuItems(hwndMenu,iPosition,g_hModule,ID_POPUPMENU,WPMENUID_OPEN);
    }

    return bRet;
}

SOM_Scope BOOL  SOMLINK wpMenuItemSelected(PostWhat *somSelf,
                                           HWND hwndFrame, ULONG ulMenuId)
{
    PostWhatData *somThis = PostWhatGetData(somSelf);
    PostWhatMethodDebug("PostWhat","wpMenuItemSelected");

    switch (ulMenuId)
    {
        case MENUID_POSTWHATVIEW:
            somSelf->wpViewObject(NULLHANDLE,ulMenuId,0);
            break;

        default:
            return (PostWhat_parent_WPAbstract_wpMenuItemSelected(somSelf,
                                                                hwndFrame,
                                                                ulMenuId));
    }
    return TRUE;
}

SOM_Scope HWND  SOMLINK wpOpen(PostWhat *somSelf, HWND hwndCnr,
                               ULONG ulView, ULONG param)
{
    PostWhatData *somThis = PostWhatGetData(somSelf);
    PostWhatMethodDebug("PostWhat","wpOpen");

    if (ulView == MENUID_POSTWHATVIEW)
    {
        QMSG qmsg;
        HAB hab;
        HMQ hmq;
        BOOL bRC;
        HWND hwnd;
        ULONG ulResult,ulCreateFlags,ulButtonAppearance;
        HWND hwndClient;
        PFNWP oldWndProc;

        ulCreateFlags = FCF_TITLEBAR|FCF_SYSMENU|FCF_SIZEBORDER|FCF_SHELLPOSITION|FCF_MOUSEALIGN|FCF_MENU;

        ulButtonAppearance = somSelf->wpQueryButtonAppearance();
        if (ulButtonAppearance == DEFAULTBUTTON)
        {
            ulButtonAppearance = _PostWhat->wpclsQueryButtonAppearance();
        }
        if (ulButtonAppearance == HIDEBUTTON)
        {
            ulCreateFlags |= FCF_HIDEMAX;
        }
        else
        {
            ulCreateFlags |= FCF_MINMAX;
        }

        hwnd = WinCreateStdWindow(
                                    HWND_DESKTOP,
                                    0UL,
                                    &ulCreateFlags,
                                    WC_MLE,
                                    "",
                                    MLS_HSCROLL|MLS_VSCROLL,
                                    g_hModule,
                                    ID_MAIN,
                                    &hwndClient
                                    );

        if (hwnd)
        {
            bRC         = somSelf->wpRegisterView(hwnd,"Note View");
            somSelf->wpSubClassWindow(hwndClient,WndProc);
        }
        return hwnd;
    }
    else
    {
        return (PostWhat_parent_WPAbstract_wpOpen(somSelf, hwndCnr,
                                                ulView, param));
    }
}


SOM_Scope BOOL  SOMLINK wpFree(PostWhat *somSelf)
{
    HOBJECT handle=NULLHANDLE;
    PSZ appName=NULL;
    CHAR keyName[32];


    PostWhatData *somThis = PostWhatGetData(somSelf);
    PostWhatMethodDebug("PostWhat","wpFree");

    /* clean up OS2.INI, remove our Save/Restore
    * window information (WinStoreWindowPos/WinRestoreWindowPos)
    */
//    appName     = somSelf->somGetClassName();
    /*
    * in order to avoid cluttering OS2.INI, the save/restore
    * window position has been stored under the original
    * class name even if that class has been replaced,
    * see the Window procedure
    */
    appName     = _PostWhat->somGetName();

    handle      = somSelf->wpQueryHandle();
    _itoa(handle,keyName,10);
    PrfWriteProfileData(HINI_USERPROFILE,appName,keyName,NULL,0);

    /*
    * the data saved via wpSaveState is saved under
    * Application Name: "PM_Abstract:Objects"
    * Key Name        : HABS_FROM_HOBJ(somSelf->wpQueryHandle()); (in hex)
    * (see wpobject.xh for definition of HABS_FROM_HOBJ)
    * this data is apparently deleted when wpFree is called
    * for the WPAbstract parent class
    * (or maybe via XWorkplace's override of wpFree for the
    * WPObject class, I am not sure ...)
    * additional info:
    * 0x20000: base class for abstract objects
    * 0x30000: base class for filesystem objects
    * appName = "PM_Abstract:Objects";
    * _itoa(HABS_FROM_HOBJ(handle),keyName,16);
    * PrfWriteProfileData(HINI_USERPROFILE,appName,keyName,NULL,0);
    */


    return (PostWhat_parent_WPAbstract_wpFree(somSelf));
}





SOM_Scope PBASEWNDWORDS  SOMLINK wpclsAllocPerViewData(M_PostWhat *somSelf,
                                                  HWND hwnd,
                                                  ULONG msg,
                                                  MPARAM mp1,
                                                  MPARAM mp2,
                                                  PFNWP WndProc,
                                                  PVOID pUserData,
                                                  ULONG ulLen)
{
    PBASEWNDWORDS pBase=NULL;
    PostWhat *objInst = (PostWhat *)PVOIDFROMMP(mp1);
    PFNWP oldWndProc    = (PFNWP)PVOIDFROMMP(mp2);
    BOOL fRC;

    /* M_PostWhatData *somThis = M_PostWhatGetData(somSelf); */
    M_PostWhatMethodDebug("M_PostWhat","AllocPerViewData");

    if (msg != WM_INIT || !somIsObj(objInst) || !oldWndProc)
    {
        return pBase;
    }

    pBase = (PBASEWNDWORDS)objInst->wpAllocMem(ulLen+sizeof(BASEWNDWORDS),NULL);
    if (pBase)
    {
        pBase->somSelf              = (SOMObject *)objInst;
        /*
            We have to get the instance data pointer dynamically
            because this method is designed so that it can also
            be called from a replacement or subclassing class
            but the instance data pointer for a replacement
            or subclassing class points to a different memory
            address !
        */
        pBase->somThis              = (PVOID)somDataResolve((SOMObject *)objInst,somSelf->somGetInstanceToken());
        pBase->thisWndProc          = WndProc;
        pBase->prevWndProc          = oldWndProc;
        pBase->prevWndWords         = (PBASEWNDWORDS)WinQueryWindowPtr(hwnd,QWL_USER);
        if (pUserData && ulLen)
        {
            memcpy(pBase+1,pUserData,ulLen);
        }
        WinSetWindowPtr(hwnd,QWL_USER,pBase);
    }
    return pBase;
}


SOM_Scope PBASEWNDWORDS  SOMLINK wpclsGetPerViewData(M_PostWhat *somSelf,
                                                HWND hwnd, PFNWP WndProc)
{
    PBASEWNDWORDS pBase;

    /* M_PostWhatData *somThis = M_PostWhatGetData(somSelf); */
    M_PostWhatMethodDebug("M_PostWhat","GetPerViewData");
    pBase = (PBASEWNDWORDS)WinQueryWindowPtr(hwnd,QWL_USER);
    while (pBase && pBase->thisWndProc != WndProc)
    {
        pBase = pBase->prevWndWords;
    }
    return pBase;
}


SOM_Scope SOMObject*  SOMLINK wpclsGetsomSelfFromPerViewData(M_PostWhat *somSelf,
                                                        PBASEWNDWORDS pBase)
{
    /* M_PostWhatData *somThis = M_PostWhatGetData(somSelf); */
    M_PostWhatMethodDebug("M_PostWhat","GetsomSelfFromPerViewData");
    if (pBase)
    {
        return pBase->somSelf;
    }
    else
    {
        return (SOMObject *)NULL;
    }
}



SOM_Scope PVOID  SOMLINK wpclsGetsomThisFromPerViewData(M_PostWhat *somSelf,
                                                   PBASEWNDWORDS pBase)
{
    /* M_PostWhatData *somThis = M_PostWhatGetData(somSelf); */
    M_PostWhatMethodDebug("M_PostWhat","GetsomThisFromPerViewData");
    if (pBase)
    {
        return pBase->somThis;
    }
    else
    {
        return NULL;
    }
}




SOM_Scope PVOID  SOMLINK wpclsGetUserDataFromPerViewData(M_PostWhat *somSelf,
                                                    PBASEWNDWORDS pBase)
{
    /* M_PostWhatData *somThis = M_PostWhatGetData(somSelf); */
    M_PostWhatMethodDebug("M_PostWhat","GetUserDataFromPerViewData");
    if(pBase)
    {
        return (pBase+1);
    }
    else
    {
        return NULL;
    }
}


SOM_Scope BOOL  SOMLINK wpclsFreePerViewData(M_PostWhat *somSelf,
                                        HWND hwnd, PFNWP WndProc)
{
    PBASEWNDWORDS pBase,pTemp;
    PostWhat *objInst;

    /* M_PostWhatData *somThis = M_PostWhatGetData(somSelf); */
    M_PostWhatMethodDebug("M_PostWhat","FreePerViewData");

    pBase = (PBASEWNDWORDS)WinQueryWindowPtr(hwnd,QWL_USER);

    /*
        if our Window Words are the first ones in the chain,
        make sure that we replace the Window Word pointer to
        point to the next element in the chain as our Window Words
        will be removed right away
    */
    if (pBase && pBase->thisWndProc == WndProc)
    {
        WinSetWindowPtr(hwnd,QWL_USER,pBase->prevWndWords);
    }
    else
    {
        /*
            cycle until we are FOLLOWED by the Window Word block that is to be removed
            (identified by a matching Window Procedure address)
        */
        pTemp = NULL;
        while(pBase && pBase->thisWndProc != WndProc)
        {
            pTemp = pBase;
            pBase = pBase->prevWndWords;
        }
        pBase = pTemp;

        /*
            now that we have found the preceding element, unchain our element
            and make sure we close the chain so that the previous ptr of the preceding
            elements points to where our previous ptr pointed to
        */
        if (pBase && pBase->prevWndWords)
        {
            pTemp = pBase->prevWndWords;
            pBase->prevWndWords = pBase->prevWndWords->prevWndWords;
            pBase = pTemp;
        }
    }
    if (pBase)
    {
        objInst = (PostWhat *)pBase->somSelf;
        objInst->wpFreeMem((PBYTE)pBase);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


SOM_Scope MRESULT  SOMLINK wpclsClassDefaultWindowProc(M_PostWhat *somSelf,
                                                  HWND hwnd,
                                                  ULONG msg,
                                                  MPARAM mp1,
                                                  MPARAM mp2,
                                                  PFNWP WndProc)
{
    PBASEWNDWORDS pBase,pTemp;
    MRESULT mres;

    /* M_PostWhatData *somThis = M_PostWhatGetData(somSelf); */
    M_PostWhatMethodDebug("M_PostWhat","ClassDefaultWindowProc");

    pBase = pTemp = (PBASEWNDWORDS)WinQueryWindowPtr(hwnd,QWL_USER);
    while(pTemp && pTemp->thisWndProc != WndProc)
    {
        pTemp = pTemp->prevWndWords;
    }

    if (pTemp && pTemp->prevWndProc)
    {
        mres                = pTemp->prevWndProc(hwnd,msg,mp1,mp2);
    }
    /*
        we have to catch the case that we have to call the old
        Wnd Procedure even when new Window Words could not be allocated
        this will happen if the Window is destroyed because of failure
        of wpclsAllocPerViewData and subsequent calling of WinDestroyWindow
    */
    else if (pBase && pBase->thisWndProc)
    {
        mres                = pBase->thisWndProc(hwnd,msg,mp1,mp2);
    }
    /*
        finally, if we don't succeed in accessing any Window word
        block at all (failure of 1. replacement class),
        let's try to call the original Window procedure
        that was active before any subclassing was done at all
    */
    else
    {
        CHAR szClsName[256];
        CLASSINFO clsInfo;
        ULONG ulLen;
        HAB hab;
        BOOL fRC;

        memset(&clsInfo,0,sizeof(clsInfo));
        hab                     = WinQueryAnchorBlock(hwnd);
        ulLen                   = WinQueryClassName(hwnd,sizeof(szClsName),szClsName);
        fRC                     = WinQueryClassInfo(hab,szClsName,&clsInfo);
        if (fRC)
        {
            mres                = clsInfo.pfnWindowProc(hwnd,msg,mp1,mp2);
        }
        else
        {
            mres                = (MRESULT)0;
        }
    }
    return mres;
}


SOM_Scope BOOL  SOMLINK wpclsCreateDefaultTemplates(M_PostWhat *somSelf,
                                                    WPObject* Folder)
{
    /* M_PostWhatData *somThis = M_PostWhatGetData(somSelf); */
    M_PostWhatMethodDebug("M_PostWhat","wpclsCreateDefaultTemplates");

    /*
    return (M_PostWhat_parent_M_WPAbstract_wpclsCreateDefaultTemplates(somSelf,
                                                                       Folder));
    */
    return TRUE;
}

SOM_Scope PSZ  SOMLINK wpclsQueryTitle(M_PostWhat *somSelf)
{
    /* M_PostWhatData *somThis = M_PostWhatGetData(somSelf); */
    M_PostWhatMethodDebug("M_PostWhat","wpclsQueryTitle");

    return "PostWhat";
}


SOM_Scope ULONG  SOMLINK wpclsQueryDefaultView(M_PostWhat *somSelf)
{
    /* M_PostWhatData *somThis = M_PostWhatGetData(somSelf); */
    M_PostWhatMethodDebug("M_PostWhat","wpclsQueryDefaultView");

    return MENUID_POSTWHATVIEW;
}


SOM_Scope ULONG  SOMLINK wpclsQueryIconData(M_PostWhat *somSelf,
                                            PICONINFO pIconInfo)
{
    /* M_PostWhatData *somThis = M_PostWhatGetData(somSelf); */
    M_PostWhatMethodDebug("M_PostWhat","wpclsQueryIconData");

    /*
    return (M_PostWhat_parent_M_WPAbstract_wpclsQueryIconData(somSelf,
                                                              pIconInfo));
    */
    if (pIconInfo)
    {
        memset(pIconInfo,0,sizeof(*pIconInfo));
        pIconInfo->cb       = sizeof(*pIconInfo);
        pIconInfo->fFormat  = ICON_RESOURCE;
        pIconInfo->hmod     = g_hModule;
        pIconInfo->resid    = ID_MAIN;
    }
    return (sizeof(*pIconInfo));
}
