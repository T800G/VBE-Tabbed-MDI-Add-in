#ifndef _36DBD031_4072_4022_985B_DA22907E4520_
#define _36DBD031_4072_4022_985B_DA22907E4520_
#ifdef _DEBUG

#include <shobjidl.h>
#include <Shlobj.h>
	

#include<Credentialprovider.h>
#include<Shdeprecated.h>
#include<Shappmgr.h>
#include<Thumbcache.h>
#include<Shimgdata.h>
#include<Imagetranscode.h>
#include<oleacc.h>

//undocumented interface
#include <guiddef.h>
static const GUID IID_IFolderType={0x053B4A86, 0x0DC9, 0x40A3, {0xB7, 0xED, 0xBC, 0x6A, 0x2E, 0x95, 0x1F, 0x48}};
MIDL_INTERFACE("053B4A86-0DC9-40A3-B7ED-BC6A2E951F48")
IFolderType: public IUnknown
{
public:
	STDMETHOD(GetFolderType)(THIS_ FOLDERTYPEID* folderTypeID) PURE;
};


static const GUID IID_IVBE={0x0002E166, 0x0000, 0x0000, {0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46}};
MIDL_INTERFACE("0002E166-0000-0000-C000-000000000046")
IVBE: public IUnknown
{
	//
};


typedef struct tagIFACE
{
	union {IID iid;} guid;
	LPCSTR iname;
	UINT n;
} IFACE;


//#define IFACECOUNT 248//287
static const IFACE g_IFaces[]=
{

#ifdef IAccessible
	{__uuidof(IAccessible),"IAccessible", 0},
#endif
#ifdef IAccessibleWindowlessSite
	{__uuidof(IAccessibleWindowlessSite),"IAccessibleWindowlessSite", 0},
#endif
#ifdef IAccIdentity
	{__uuidof(IAccIdentity),"IAccIdentity", 0},
#endif
#ifdef IAccPropServer
	{__uuidof(IAccPropServer),"IAccPropServer", 0},
#endif
#ifdef IAccPropServices
	{__uuidof(IAccPropServices),"IAccPropServices", 0},
#endif
#ifdef IAccessibleHandler
	{__uuidof(IAccessibleHandler),"IAccessibleHandler", 0},
#endif
#ifdef IAccessibleObject
	{__uuidof(IAccessibleObject), "IAccessibleObject", 0},
#endif
#ifdef IACList
	{__uuidof(IACList), "IACList" ,0},
#endif
#ifdef IACList2
	{__uuidof(IACList2), "IACList2" ,0},
#endif
#ifdef IActionProgress
	{__uuidof(IActionProgress), "IActionProgress" ,0},
#endif
#ifdef IActionProgressDialog
	{__uuidof(IActionProgressDialog), "IActionProgressDialog" ,0},
#endif
#ifdef IAssocHandler
	{__uuidof(IAssocHandler), "IAssocHandler" ,0},
#endif
#ifdef IAssocHandlerInvoker
	{__uuidof(IAssocHandlerInvoker), "IAssocHandlerInvoker" ,0},
#endif
#ifdef IAsyncOperation
	{__uuidof(IAsyncOperation), "IAsyncOperation" ,0},
#endif
#ifdef IAttachmentExecute
	{__uuidof(IAttachmentExecute), "IAttachmentExecute" ,0},
#endif
#ifdef IAutoComplete
	{__uuidof(IAutoComplete), "IAutoComplete" ,0},
#endif
#ifdef IAutoComplete2
	{__uuidof(IAutoComplete2), "IAutoComplete2" ,0},
#endif
#ifdef IAutoCompleteDropDown
	{__uuidof(IAutoCompleteDropDown), "IAutoCompleteDropDown" ,0},
#endif
#ifdef IBandHost
	{__uuidof(IBandHost), "IBandHost" ,0},
#endif
#ifdef IBandSite
	{__uuidof(IBandSite), "IBandSite" ,0},
#endif
#ifdef IBrowserFrameOptions
	{__uuidof(IBrowserFrameOptions), "IBrowserFrameOptions" ,0},
#endif
#ifdef IBrowserService
	{__uuidof(IBrowserService), "IBrowserService" ,0},
#endif
#ifdef IBrowserService2
	{__uuidof(IBrowserService2), "IBrowserService2" ,0},
#endif
#ifdef IBrowserService3
	{__uuidof(IBrowserService3), "IBrowserService3" ,0},
#endif
#ifdef IBrowserService4
	{__uuidof(IBrowserService4), "IBrowserService4" ,0},
#endif
#ifdef ICategorizer
	{__uuidof(ICategorizer), "ICategorizer" ,0},
#endif
#ifdef ICategoryProvider
	{__uuidof(ICategoryProvider), "ICategoryProvider" ,0},
#endif
#ifdef ICDBurn
	{__uuidof(ICDBurn), "ICDBurn" ,0},
#endif
#ifdef ICDBurnExt
	{__uuidof(ICDBurnExt), "ICDBurnExt" ,0},
#endif
#ifdef IColumnManager
	{__uuidof(IColumnManager), "IColumnManager" ,0},
#endif
#ifdef IColumnProvider
	{__uuidof(IColumnProvider), "IColumnProvider" ,0},
#endif
#ifdef ICommDlgBrowser
	{__uuidof(ICommDlgBrowser), "ICommDlgBrowser" ,0},
#endif
#ifdef ICommDlgBrowser2
	{__uuidof(ICommDlgBrowser2), "ICommDlgBrowser2" ,0},
#endif
#ifdef ICommDlgBrowser3
	{__uuidof(ICommDlgBrowser3), "ICommDlgBrowser3" ,0},
#endif
#ifdef IComputerInfoChangeNotify
	{__uuidof(IComputerInfoChangeNotify), "IComputerInfoChangeNotify" ,0},
#endif
#ifdef IContextMenu
	{__uuidof(IContextMenu), "IContextMenu" ,0},
#endif
#ifdef IContextMenu2
	{__uuidof(IContextMenu2), "IContextMenu2" ,0},
#endif
#ifdef IContextMenu3
	{__uuidof(IContextMenu3), "IContextMenu3" ,0},
#endif
#ifdef IContextMenuCB
	{__uuidof(IContextMenuCB), "IContextMenuCB" ,0},
#endif
#ifdef IContextMenuSite
	{__uuidof(IContextMenuSite), "IContextMenuSite" ,0},
#endif
#ifdef IControlMarkup
	{__uuidof(IControlMarkup), "IControlMarkup" ,0},
#endif
#ifdef ICopyHook
	{__uuidof(ICopyHook), "ICopyHook" ,0},
#endif
#ifdef ICreateObject
	{__uuidof(ICreateObject), "ICreateObject" ,0},
#endif
#ifdef ICredentialProvider
	{__uuidof(ICredentialProvider), "ICredentialProvider" ,0},
#endif
#ifdef ICredentialProviderCredential
	{__uuidof(ICredentialProviderCredential), "ICredentialProviderCredential" ,0},
#endif
#ifdef ICredentialProviderCredentialEvents
	{__uuidof(ICredentialProviderCredentialEvents), "ICredentialProviderCredentialEvents" ,0},
#endif
#ifdef ICredentialProviderEvents
	{__uuidof(ICredentialProviderEvents), "ICredentialProviderEvents" ,0},
#endif
#ifdef ICredentialProviderFilter
	{__uuidof(ICredentialProviderFilter), "ICredentialProviderFilter" ,0},
#endif
#ifdef ICurrentItem
	{__uuidof(ICurrentItem), "ICurrentItem" ,0},
#endif
#ifdef ICurrentWorkingDirectory
	{__uuidof(ICurrentWorkingDirectory), "ICurrentWorkingDirectory" ,0},
#endif
#ifdef IDefaultExtractIconInit
	{__uuidof(IDefaultExtractIconInit), "IDefaultExtractIconInit" ,0},
#endif
#ifdef IDefViewID
	{__uuidof(IDefViewID), "IDefViewID" ,0},
#endif
#ifdef IDelayedPropertyStoreFactory
	{__uuidof(IDelayedPropertyStoreFactory), "IDelayedPropertyStoreFactory" ,0},
#endif
#ifdef IDelegateFolder
	{__uuidof(IDelegateFolder), "IDelegateFolder" ,0},
#endif
#ifdef IDeskBand
	{__uuidof(IDeskBand), "IDeskBand" ,0},
#endif
#ifdef IDeskBand2
	{__uuidof(IDeskBand2), "IDeskBand2" ,0},
#endif
#ifdef IDeskBandInfo
	{__uuidof(IDeskBandInfo), "IDeskBandInfo" ,0},
#endif
#ifdef IDeskBar
	{__uuidof(IDeskBar), "IDeskBar" ,0},
#endif
#ifdef IDestinationStreamFactory
	{__uuidof(IDestinationStreamFactory), "IDestinationStreamFactory" ,0},
#endif
#ifdef IDisplayItem
	{__uuidof(IDisplayItem), "IDisplayItem" ,0},
#endif
#ifdef IDispatch
	{__uuidof(IDispatch), "IDispatch" ,0},
#endif
#ifdef IDockingWindow
	{__uuidof(IDockingWindow), "IDockingWindow" ,0},
#endif
#ifdef IDockingWindowFrame
	{__uuidof(IDockingWindowFrame), "IDockingWindowFrame" ,0},
#endif
#ifdef IDockingWindowSite
	{__uuidof(IDockingWindowSite), "IDockingWindowSite" ,0},
#endif
#ifdef IDocViewSite
	{__uuidof(IDocViewSite), "IDocViewSite" ,0},
#endif
#ifdef IDragSourceHelper
	{__uuidof(IDragSourceHelper), "IDragSourceHelper" ,0},
#endif
#ifdef IDragSourceHelper2
	{__uuidof(IDragSourceHelper2), "IDragSourceHelper2" ,0},
#endif
#ifdef IDropTargetHelper
	{__uuidof(IDropTargetHelper), "IDropTargetHelper" ,0},
#endif
#ifdef IDynamicHWHandler
	{__uuidof(IDynamicHWHandler), "IDynamicHWHandler" ,0},
#endif
#ifdef IEnumAssocHandlers
	{__uuidof(IEnumAssocHandlers), "IEnumAssocHandlers" ,0},
#endif
#ifdef IEnumerableView
	{__uuidof(IEnumerableView), "IEnumerableView" ,0},
#endif
#ifdef IEnumExplorerCommand
	{__uuidof(IEnumExplorerCommand), "IEnumExplorerCommand" ,0},
#endif
#ifdef IEnumExtraSearch
	{__uuidof(IEnumExtraSearch), "IEnumExtraSearch" ,0},
#endif
#ifdef IEnumFullIDList
	{__uuidof(IEnumFullIDList), "IEnumFullIDList" ,0},
#endif
#ifdef IEnumIDList
	{__uuidof(IEnumIDList), "IEnumIDList" ,0},
#endif
#ifdef IEnumObjects
	{__uuidof(IEnumObjects), "IEnumObjects" ,0},
#endif
#ifdef IEnumPublishedApps
	{__uuidof(IEnumPublishedApps), "IEnumPublishedApps" ,0},
#endif
#ifdef IEnumReadyCallback
	{__uuidof(IEnumReadyCallback), "IEnumReadyCallback" ,0},
#endif
#ifdef IEnumResources
	{__uuidof(IEnumResources), "IEnumResources" ,0},
#endif
#ifdef IEnumShellItems
	{__uuidof(IEnumShellItems), "IEnumShellItems" ,0},
#endif
#ifdef IEnumUserIdentity
	{__uuidof(IEnumUserIdentity), "IEnumUserIdentity" ,0},
#endif
#ifdef IExecuteCommand
	{__uuidof(IExecuteCommand), "IExecuteCommand" ,0},
#endif
#ifdef IExpDispSupport
	{__uuidof(IExpDispSupport), "IExpDispSupport" ,0},
#endif
#ifdef IExpDispSupportXP
	{__uuidof(IExpDispSupportXP), "IExpDispSupportXP" ,0},
#endif
#ifdef IExplorerBrowser
	{__uuidof(IExplorerBrowser), "IExplorerBrowser" ,0},
#endif
#ifdef IExplorerBrowserEvents
	{__uuidof(IExplorerBrowserEvents), "IExplorerBrowserEvents" ,0},
#endif
#ifdef IExplorerCommand
	{__uuidof(IExplorerCommand), "IExplorerCommand" ,0},
#endif
#ifdef IExplorerCommandProvider
	{__uuidof(IExplorerCommandProvider), "IExplorerCommandProvider" ,0},
#endif
#ifdef IExplorerPaneVisibility
	{__uuidof(IExplorerPaneVisibility), "IExplorerPaneVisibility" ,0},
#endif
#ifdef IExtractIcon
	{__uuidof(IExtractIcon), "IExtractIcon" ,0},
#endif
#ifdef IExtractImage
	{__uuidof(IExtractImage), "IExtractImage" ,0},
#endif
#ifdef IExtractImage2
	{__uuidof(IExtractImage2), "IExtractImage2" ,0},
#endif
#ifdef IFileDialog
	{__uuidof(IFileDialog), "IFileDialog" ,0},
#endif
#ifdef IFileDialogControlEvents
	{__uuidof(IFileDialogControlEvents), "IFileDialogControlEvents" ,0},
#endif
#ifdef IFileDialogCustomize
	{__uuidof(IFileDialogCustomize), "IFileDialogCustomize" ,0},
#endif
#ifdef IFileDialogEvents
	{__uuidof(IFileDialogEvents), "IFileDialogEvents" ,0},
#endif
#ifdef IFileIsInUse
	{__uuidof(IFileIsInUse), "IFileIsInUse" ,0},
#endif
#ifdef IFileOpenDialog
	{__uuidof(IFileOpenDialog), "IFileOpenDialog" ,0},
#endif
#ifdef IFileOperation
	{__uuidof(IFileOperation), "IFileOperation" ,0},
#endif
#ifdef IFileOperationProgressSink
	{__uuidof(IFileOperationProgressSink), "IFileOperationProgressSink" ,0},
#endif
#ifdef IFileSaveDialog
	{__uuidof(IFileSaveDialog), "IFileSaveDialog" ,0},
#endif
#ifdef IFileSystemBindData
	{__uuidof(IFileSystemBindData), "IFileSystemBindData" ,0},
#endif
#ifdef IFileSystemBindData2
	{__uuidof(IFileSystemBindData2), "IFileSystemBindData2" ,0},
#endif
#ifdef IFolderBandPriv
	{__uuidof(IFolderBandPriv), "IFolderBandPriv" ,0},
#endif
#ifdef IFolderFilter
	{__uuidof(IFolderFilter), "IFolderFilter" ,0},
#endif
#ifdef IFolderFilterSite
	{__uuidof(IFolderFilterSite), "IFolderFilterSite" ,0},
#endif
#ifdef IFolderView
	{__uuidof(IFolderView), "IFolderView" ,0},
#endif
#ifdef IFolderView2
	{__uuidof(IFolderView2), "IFolderView2" ,0},
#endif
#ifdef IFolderViewHost
	{__uuidof(IFolderViewHost), "IFolderViewHost" ,0},
#endif
#ifdef IFolderViewOptions
	{__uuidof(IFolderViewOptions), "IFolderViewOptions" ,0},
#endif
#ifdef IFolderViewSettings
	{__uuidof(IFolderViewSettings), "IFolderViewSettings" ,0},
#endif
#ifdef IHWEventHandler
	{__uuidof(IHWEventHandler), "IHWEventHandler" ,0},
#endif
#ifdef IHWEventHandler2
	{__uuidof(IHWEventHandler2), "IHWEventHandler2" ,0},
#endif
#ifdef IIdentityName
	{__uuidof(IIdentityName), "IIdentityName" ,0},
#endif
#ifdef IImageRecompress
	{__uuidof(IImageRecompress), "IImageRecompress" ,0},
#endif
#ifdef IInitializeNetworkFolder
	{__uuidof(IInitializeNetworkFolder), "IInitializeNetworkFolder" ,0},
#endif
#ifdef IInitializeWithFile
	{__uuidof(IInitializeWithFile), "IInitializeWithFile" ,0},
#endif
#ifdef IInitializeWithItem
	{__uuidof(IInitializeWithItem), "IInitializeWithItem" ,0},
#endif
#ifdef IInitializeWithStream
	{__uuidof(IInitializeWithStream), "IInitializeWithStream" ,0},
#endif
#ifdef IInputObject
	{__uuidof(IInputObject), "IInputObject" ,0},
#endif
#ifdef IInputObject2
	{__uuidof(IInputObject2), "IInputObject2" ,0},
#endif
#ifdef IInputObjectSite
	{__uuidof(IInputObjectSite), "IInputObjectSite" ,0},
#endif
#ifdef IInsertItem
	{__uuidof(IInsertItem), "IInsertItem" ,0},
#endif
#ifdef IIOCancelInformation
	{__uuidof(IIOCancelInformation), "IIOCancelInformation" ,0},
#endif
#ifdef IItemNameLimits
	{__uuidof(IItemNameLimits), "IItemNameLimits" ,0},
#endif
#ifdef IKnownFolder
	{__uuidof(IKnownFolder), "IKnownFolder" ,0},
#endif
#ifdef IKnownFolderManager
	{__uuidof(IKnownFolderManager), "IKnownFolderManager" ,0},
#endif
#ifdef IMarkupCallback
	{__uuidof(IMarkupCallback), "IMarkupCallback" ,0},
#endif
#ifdef IMenuBand
	{__uuidof(IMenuBand), "IMenuBand" ,0},
#endif
#ifdef IMenuPopup
	{__uuidof(IMenuPopup), "IMenuPopup" ,0},
#endif
#ifdef IModalWindow
	{__uuidof(IModalWindow), "IModalWindow" ,0},
#endif
#ifdef INamedPropertyBag
	{__uuidof(INamedPropertyBag), "INamedPropertyBag" ,0},
#endif
#ifdef INamedPropertyStore
	{__uuidof(INamedPropertyStore), "INamedPropertyStore" ,0},
#endif
#ifdef INameSpaceTreeAccessible
	{__uuidof(INameSpaceTreeAccessible), "INameSpaceTreeAccessible" ,0},
#endif
#ifdef INameSpaceTreeControl
	{__uuidof(INameSpaceTreeControl), "INameSpaceTreeControl" ,0},
#endif
#ifdef INameSpaceTreeControlEvents
	{__uuidof(INameSpaceTreeControlEvents), "INameSpaceTreeControlEvents" ,0},
#endif
#ifdef INamespaceWalk
	{__uuidof(INamespaceWalk), "INamespaceWalk" ,0},
#endif
#ifdef INamespaceWalkCB
	{__uuidof(INamespaceWalkCB), "INamespaceWalkCB" ,0},
#endif
#ifdef INewShortcutHook
	{__uuidof(INewShortcutHook), "INewShortcutHook" ,0},
#endif
#ifdef INewWindowManager
	{__uuidof(INewWindowManager), "INewWindowManager" ,0},
#endif
#ifdef IOleWindow
	{__uuidof(IOleWindow), "IOleWindow" ,0},
#endif
#ifdef IObjectProvider
	{__uuidof(IObjectProvider), "IObjectProvider" ,0},
#endif
#ifdef IObjectWithBackReferences
	{__uuidof(IObjectWithBackReferences), "IObjectWithBackReferences" ,0},
#endif
#ifdef IObjectWithPropertyKey
	{__uuidof(IObjectWithPropertyKey), "IObjectWithPropertyKey" ,0},
#endif
#ifdef IObjMgr
	{__uuidof(IObjMgr), "IObjMgr" ,0},
#endif
#ifdef IOpenControlPanel
	{__uuidof(IOpenControlPanel), "IOpenControlPanel" ,0},
#endif
#ifdef IOperationsProgressDialog
	{__uuidof(IOperationsProgressDialog), "IOperationsProgressDialog" ,0},
#endif
#ifdef IParentAndItem
	{__uuidof(IParentAndItem), "IParentAndItem" ,0},
#endif
#ifdef IParseAndCreateItem
	{__uuidof(IParseAndCreateItem), "IParseAndCreateItem" ,0},
#endif
#ifdef IPassportClientServices
	{__uuidof(IPassportClientServices), "IPassportClientServices" ,0},
#endif
#ifdef IPassportWizard
	{__uuidof(IPassportWizard), "IPassportWizard" ,0},
#endif
#ifdef IPersistFolder
	{__uuidof(IPersistFolder), "IPersistFolder" ,0},
#endif
#ifdef IPersistFolder2
	{__uuidof(IPersistFolder2), "IPersistFolder2" ,0},
#endif
#ifdef IPersistFolder3
	{__uuidof(IPersistFolder3), "IPersistFolder3" ,0},
#endif
#ifdef IPersistIDList
	{__uuidof(IPersistIDList), "IPersistIDList" ,0},
#endif
#ifdef IPersistSerializedPropStorage
	{__uuidof(IPersistSerializedPropStorage), "IPersistSerializedPropStorage" ,0},
#endif
#ifdef IPersistSerializedPropStorage2
	{__uuidof(IPersistSerializedPropStorage2), "IPersistSerializedPropStorage2" ,0},
#endif
#ifdef IPreviewHandler
	{__uuidof(IPreviewHandler), "IPreviewHandler" ,0},
#endif
#ifdef IPreviewHandlerFrame
	{__uuidof(IPreviewHandlerFrame), "IPreviewHandlerFrame" ,0},
#endif
#ifdef IPreviewHandlerVisuals
	{__uuidof(IPreviewHandlerVisuals), "IPreviewHandlerVisuals" ,0},
#endif
#ifdef IPreviewItem
	{__uuidof(IPreviewItem), "IPreviewItem" ,0},
#endif
#ifdef IPreviousVersionsInfo
	{__uuidof(IPreviousVersionsInfo), "IPreviousVersionsInfo" ,0},
#endif
#ifdef IPrivateIdentityManager
	{__uuidof(IPrivateIdentityManager), "IPrivateIdentityManager" ,0},
#endif
#ifdef IPrivateIdentityManager2
	{__uuidof(IPrivateIdentityManager2), "IPrivateIdentityManager2" ,0},
#endif
#ifdef IProfferService
	{__uuidof(IProfferService), "IProfferService" ,0},
#endif
#ifdef IProgressDialog
	{__uuidof(IProgressDialog), "IProgressDialog" ,0},
#endif
#ifdef IPublishedApp
	{__uuidof(IPublishedApp), "IPublishedApp" ,0},
#endif
#ifdef IPublishedApp2
	{__uuidof(IPublishedApp2), "IPublishedApp2" ,0},
#endif
#ifdef IPublishingWizard
	{__uuidof(IPublishingWizard), "IPublishingWizard" ,0},
#endif
#ifdef IQueryAssociations
	{__uuidof(IQueryAssociations), "IQueryAssociations" ,0},
#endif
#ifdef IQueryCancelAutoPlay
	{__uuidof(IQueryCancelAutoPlay), "IQueryCancelAutoPlay" ,0},
#endif
#ifdef IQueryCodePage
	{__uuidof(IQueryCodePage), "IQueryCodePage" ,0},
#endif
#ifdef IQueryContinue
	{__uuidof(IQueryContinue), "IQueryContinue" ,0},
#endif
#ifdef IQueryContinueWithStatus
	{__uuidof(IQueryContinueWithStatus), "IQueryContinueWithStatus" ,0},
#endif
#ifdef IQueryInfo
	{__uuidof(IQueryInfo), "IQueryInfo" ,0},
#endif
#ifdef IRegTreeItem
	{__uuidof(IRegTreeItem), "IRegTreeItem" ,0},
#endif
#ifdef IRelatedItem
	{__uuidof(IRelatedItem), "IRelatedItem" ,0},
#endif
#ifdef IRemoteComputer
	{__uuidof(IRemoteComputer), "IRemoteComputer" ,0},
#endif
#ifdef IResolveShellLink
	{__uuidof(IResolveShellLink), "IResolveShellLink" ,0},
#endif
#ifdef IResultsFolder
	{__uuidof(IResultsFolder), "IResultsFolder" ,0},
#endif
#ifdef IRunnableTask
	{__uuidof(IRunnableTask), "IRunnableTask" ,0},
#endif
#ifdef ISearchBoxInfo
	{__uuidof(ISearchBoxInfo), "ISearchBoxInfo" ,0},
#endif
#ifdef ISearchContext
	{__uuidof(ISearchContext), "ISearchContext" ,0},
#endif
#ifdef ISearchFolderItemFactory
	{__uuidof(ISearchFolderItemFactory), "ISearchFolderItemFactory" ,0},
#endif
#ifdef ISharedBitmap
	{__uuidof(ISharedBitmap), "ISharedBitmap" ,0},
#endif
#ifdef ISharingConfigurationManager
	{__uuidof(ISharingConfigurationManager), "ISharingConfigurationManager" ,0},
#endif
#ifdef IShellApp
	{__uuidof(IShellApp), "IShellApp" ,0},
#endif
#ifdef IShellBrowser
	{__uuidof(IShellBrowser), "IShellBrowser" ,0},
#endif
#ifdef IShellChangeNotify
	{__uuidof(IShellChangeNotify), "IShellChangeNotify" ,0},
#endif
#ifdef IShellDetails
	{__uuidof(IShellDetails), "IShellDetails" ,0},
#endif
#ifdef IShellExecuteHook
	{__uuidof(IShellExecuteHook), "IShellExecuteHook" ,0},
#endif
#ifdef IShellExtInit
	{__uuidof(IShellExtInit), "IShellExtInit" ,0},
#endif
#ifdef IShellFolder
	{__uuidof(IShellFolder), "IShellFolder" ,0},
#endif
#ifdef IShellFolder2
	{__uuidof(IShellFolder2), "IShellFolder2" ,0},
#endif
#ifdef IShellFolderBand
	{__uuidof(IShellFolderBand), "IShellFolderBand" ,0},
#endif
#ifdef IShellFolderSearchable
	{__uuidof(IShellFolderSearchable), "IShellFolderSearchable" ,0},
#endif
#ifdef IShellFolderSearchableCallback
	{__uuidof(IShellFolderSearchableCallback), "IShellFolderSearchableCallback" ,0},
#endif
#ifdef IShellFolderView
	{__uuidof(IShellFolderView), "IShellFolderView" ,0},
#endif
#ifdef IShellFolderViewCB
	{__uuidof(IShellFolderViewCB), "IShellFolderViewCB" ,0},
#endif
#ifdef IShellFolderViewDual
	{__uuidof(IShellFolderViewDual), "IShellFolderViewDual" ,0},
#endif
#ifdef IShellFolderViewDual2
	{__uuidof(IShellFolderViewDual2), "IShellFolderViewDual2" ,0},
#endif
#ifdef IShellFolderViewDual3
	{__uuidof(IShellFolderViewDual3), "IShellFolderViewDual3" ,0},
#endif
#ifdef IShellFolderViewType
	{__uuidof(IShellFolderViewType), "IShellFolderViewType" ,0},
#endif
#ifdef IShellIcon
	{__uuidof(IShellIcon), "IShellIcon" ,0},
#endif
#ifdef IShellIconOverlay
	{__uuidof(IShellIconOverlay), "IShellIconOverlay" ,0},
#endif
#ifdef IShellIconOverlayIdentifier
	{__uuidof(IShellIconOverlayIdentifier), "IShellIconOverlayIdentifier" ,0},
#endif
#ifdef IShellIconOverlayManager
	{__uuidof(IShellIconOverlayManager), "IShellIconOverlayManager" ,0},
#endif
#ifdef IShellImageData
	{__uuidof(IShellImageData), "IShellImageData" ,0},
#endif
#ifdef IShellImageDataAbort
	{__uuidof(IShellImageDataAbort), "IShellImageDataAbort" ,0},
#endif
#ifdef IShellImageDataFactory
	{__uuidof(IShellImageDataFactory), "IShellImageDataFactory" ,0},
#endif
#ifdef IShellImageStore
	{__uuidof(IShellImageStore), "IShellImageStore" ,0},
#endif
#ifdef IShellItem
	{__uuidof(IShellItem), "IShellItem" ,0},
#endif
#ifdef IShellItem2
	{__uuidof(IShellItem2), "IShellItem2" ,0},
#endif
#ifdef IShellItemArray
	{__uuidof(IShellItemArray), "IShellItemArray" ,0},
#endif
#ifdef IShellItemFilter
	{__uuidof(IShellItemFilter), "IShellItemFilter" ,0},
#endif
#ifdef IShellItemImageFactory
	{__uuidof(IShellItemImageFactory), "IShellItemImageFactory" ,0},
#endif
#ifdef IShellItemResources
	{__uuidof(IShellItemResources), "IShellItemResources" ,0},
#endif
#ifdef IShellLibrary
	{__uuidof(IShellLibrary), "IShellLibrary" ,0},
#endif
#ifdef IShellLink
	{__uuidof(IShellLink), "IShellLink" ,0},
#endif
#ifdef IShellLinkDataList
	{__uuidof(IShellLinkDataList), "IShellLinkDataList" ,0},
#endif
#ifdef IShellMenu
	{__uuidof(IShellMenu), "IShellMenu" ,0},
#endif
#ifdef IShellMenuCallback
	{__uuidof(IShellMenuCallback), "IShellMenuCallback" ,0},
#endif
#ifdef IShellPropSheetExt
	{__uuidof(IShellPropSheetExt), "IShellPropSheetExt" ,0},
#endif
#ifdef IShellRunDll
	{__uuidof(IShellRunDll), "IShellRunDll" ,0},
#endif
#ifdef IShellService
	{__uuidof(IShellService), "IShellService" ,0},
#endif
#ifdef IShellTaskScheduler
	{__uuidof(IShellTaskScheduler), "IShellTaskScheduler" ,0},
#endif
#ifdef IShellTaskScheduler2
	{__uuidof(IShellTaskScheduler2), "IShellTaskScheduler2" ,0},
#endif
#ifdef IShellView
	{__uuidof(IShellView), "IShellView" ,0},
#endif
#ifdef IShellView2
	{__uuidof(IShellView2), "IShellView2" ,0},
#endif
#ifdef IShellView3
	{__uuidof(IShellView3), "IShellView3" ,0},
#endif
#ifdef IShellWindows
	{__uuidof(IShellWindows), "IShellWindows" ,0},
#endif
#ifdef IStartMenuPinnedList
	{__uuidof(IStartMenuPinnedList), "IStartMenuPinnedList" ,0},
#endif
#ifdef IStreamAsync
	{__uuidof(IStreamAsync), "IStreamAsync" ,0},
#endif
#ifdef IStreamUnbufferedInfo
	{__uuidof(IStreamUnbufferedInfo), "IStreamUnbufferedInfo" ,0},
#endif
#ifdef ISyncMgrConflict
	{__uuidof(ISyncMgrConflict), "ISyncMgrConflict" ,0},
#endif
#ifdef ISyncMgrConflictFolder
	{__uuidof(ISyncMgrConflictFolder), "ISyncMgrConflictFolder" ,0},
#endif
#ifdef ISyncMgrConflictItems
	{__uuidof(ISyncMgrConflictItems), "ISyncMgrConflictItems" ,0},
#endif
#ifdef ISyncMgrConflictPresenter
	{__uuidof(ISyncMgrConflictPresenter), "ISyncMgrConflictPresenter" ,0},
#endif
#ifdef ISyncMgrConflictResolveInfo
	{__uuidof(ISyncMgrConflictResolveInfo), "ISyncMgrConflictResolveInfo" ,0},
#endif
#ifdef ISyncMgrConflictStore
	{__uuidof(ISyncMgrConflictStore), "ISyncMgrConflictStore" ,0},
#endif
#ifdef ISyncMgrControl
	{__uuidof(ISyncMgrControl), "ISyncMgrControl" ,0},
#endif
#ifdef ISyncMgrEnumItems
	{__uuidof(ISyncMgrEnumItems), "ISyncMgrEnumItems" ,0},
#endif
#ifdef ISyncMgrEvent
	{__uuidof(ISyncMgrEvent), "ISyncMgrEvent" ,0},
#endif
#ifdef ISyncMgrEventLinkUIOperation
	{__uuidof(ISyncMgrEventLinkUIOperation), "ISyncMgrEventLinkUIOperation" ,0},
#endif
#ifdef ISyncMgrEventStore
	{__uuidof(ISyncMgrEventStore), "ISyncMgrEventStore" ,0},
#endif
#ifdef ISyncMgrHandler
	{__uuidof(ISyncMgrHandler), "ISyncMgrHandler" ,0},
#endif
#ifdef ISyncMgrHandlerCollection
	{__uuidof(ISyncMgrHandlerCollection), "ISyncMgrHandlerCollection" ,0},
#endif
#ifdef ISyncMgrHandlerInfo
	{__uuidof(ISyncMgrHandlerInfo), "ISyncMgrHandlerInfo" ,0},
#endif
#ifdef ISyncMgrRegister
	{__uuidof(ISyncMgrRegister), "ISyncMgrRegister" ,0},
#endif
#ifdef ISyncMgrResolutionHandler
	{__uuidof(ISyncMgrResolutionHandler), "ISyncMgrResolutionHandler" ,0},
#endif
#ifdef ISyncMgrSessionCreator
	{__uuidof(ISyncMgrSessionCreator), "ISyncMgrSessionCreator" ,0},
#endif
#ifdef ISyncMgrSyncCallback
	{__uuidof(ISyncMgrSyncCallback), "ISyncMgrSyncCallback" ,0},
#endif
#ifdef ISyncMgrSynchronize
	{__uuidof(ISyncMgrSynchronize), "ISyncMgrSynchronize" ,0},
#endif
#ifdef ISyncMgrSynchronizeCallback
	{__uuidof(ISyncMgrSynchronizeCallback), "ISyncMgrSynchronizeCallback" ,0},
#endif
#ifdef ISyncMgrSynchronizeInvoke
	{__uuidof(ISyncMgrSynchronizeInvoke), "ISyncMgrSynchronizeInvoke" ,0},
#endif
#ifdef ISyncMgrSyncItem
	{__uuidof(ISyncMgrSyncItem), "ISyncMgrSyncItem" ,0},
#endif
#ifdef ISyncMgrSyncItemContainer
	{__uuidof(ISyncMgrSyncItemContainer), "ISyncMgrSyncItemContainer" ,0},
#endif
#ifdef ISyncMgrSyncItemInfo
	{__uuidof(ISyncMgrSyncItemInfo), "ISyncMgrSyncItemInfo" ,0},
#endif
#ifdef ISyncMgrSyncResult
	{__uuidof(ISyncMgrSyncResult), "ISyncMgrSyncResult" ,0},
#endif
#ifdef ISyncMgrUIOperation
	{__uuidof(ISyncMgrUIOperation), "ISyncMgrUIOperation" ,0},
#endif
#ifdef ISyncSchedule
	{__uuidof(ISyncSchedule), "ISyncSchedule" ,0},
#endif
#ifdef ISyncScheduleMgr
	{__uuidof(ISyncScheduleMgr), "ISyncScheduleMgr" ,0},
#endif
#ifdef ITaskbarList
	{__uuidof(ITaskbarList), "ITaskbarList" ,0},
#endif
#ifdef ITaskbarList2
	{__uuidof(ITaskbarList2), "ITaskbarList2" ,0},
#endif
#ifdef ITaskbarList3
	{__uuidof(ITaskbarList3), "ITaskbarList3" ,0},
#endif
#ifdef ITaskbarList4
	{__uuidof(ITaskbarList4), "ITaskbarList4" ,0},
#endif
#ifdef IThumbnailCache
	{__uuidof(IThumbnailCache), "IThumbnailCache" ,0},
#endif
#ifdef IThumbnailCapture
	{__uuidof(IThumbnailCapture), "IThumbnailCapture" ,0},
#endif
#ifdef IThumbnailHandlerFactory
	{__uuidof(IThumbnailHandlerFactory), "IThumbnailHandlerFactory" ,0},
#endif
#ifdef IThumbnailProvider
	{__uuidof(IThumbnailProvider), "IThumbnailProvider" ,0},
#endif
#ifdef ITrackShellMenu
	{__uuidof(ITrackShellMenu), "ITrackShellMenu" ,0},
#endif
#ifdef ITranscodeImage
	{__uuidof(ITranscodeImage), "ITranscodeImage" ,0},
#endif
#ifdef ITransferAdviseSink
	{__uuidof(ITransferAdviseSink), "ITransferAdviseSink" ,0},
#endif
#ifdef ITransferDestination
	{__uuidof(ITransferDestination), "ITransferDestination" ,0},
#endif
#ifdef ITransferMediumItem
	{__uuidof(ITransferMediumItem), "ITransferMediumItem" ,0},
#endif
#ifdef ITransferSource
	{__uuidof(ITransferSource), "ITransferSource" ,0},
#endif
#ifdef ITravelEntry
	{__uuidof(ITravelEntry), "ITravelEntry" ,0},
#endif
#ifdef ITravelLog
	{__uuidof(ITravelLog), "ITravelLog" ,0},
#endif
#ifdef ITrayDeskBand
	{__uuidof(ITrayDeskBand), "ITrayDeskBand" ,0},
#endif
#ifdef IUpdateIDList
	{__uuidof(IUpdateIDList), "IUpdateIDList" ,0},
#endif
#ifdef IURLSearchHook
	{__uuidof(IURLSearchHook), "IURLSearchHook" ,0},
#endif
#ifdef IURLSearchHook2
	{__uuidof(IURLSearchHook2), "IURLSearchHook2" ,0},
#endif
#ifdef IUserAccountChangeCallback
	{__uuidof(IUserAccountChangeCallback), "IUserAccountChangeCallback" ,0},
#endif
#ifdef IUserIdentity
	{__uuidof(IUserIdentity), "IUserIdentity" ,0},
#endif
#ifdef IUserIdentity2
	{__uuidof(IUserIdentity2), "IUserIdentity2" ,0},
#endif
#ifdef IUserIdentityManager
	{__uuidof(IUserIdentityManager), "IUserIdentityManager" ,0},
#endif
#ifdef IUserNotification
	{__uuidof(IUserNotification), "IUserNotification" ,0},
#endif
#ifdef IUserNotification2
	{__uuidof(IUserNotification2), "IUserNotification2" ,0},
#endif
#ifdef IUserNotificationCallback
	{__uuidof(IUserNotificationCallback), "IUserNotificationCallback" ,0},
#endif
#ifdef IUseToBrowseItem
	{__uuidof(IUseToBrowseItem), "IUseToBrowseItem" ,0},
#endif
#ifdef IViewStateIdentityItem
	{__uuidof(IViewStateIdentityItem), "IViewStateIdentityItem" ,0},
#endif
#ifdef IVisualProperties
	{__uuidof(IVisualProperties), "IVisualProperties" ,0},
#endif
#ifdef IWebWizardExtension
	{__uuidof(IWebWizardExtension), "IWebWizardExtension" ,0},
#endif
#ifdef IWizardExtension
	{__uuidof(IWizardExtension), "IWizardExtension" ,0},
#endif
#ifdef IWizardSite
	{__uuidof(IWizardSite), "IWizardSite" ,0},
#endif


	//undocumented
	{IID_IFolderType, "IFolderType" ,0},

	//VBA IDE
	{IID_IVBE, "IVBE" ,0}


};


void __traceIFaces(IUnknown* pUnk)
{
	IUnknown* pu=NULL;
	int i;
	for (i=0; i<_countof(g_IFaces); i++)
	{
		if SUCCEEDED(pUnk->QueryInterface((IID&)g_IFaces[i].guid ,(void**)&pu))
		{
			DBGTRACE("got interface: %s\n",g_IFaces[i].iname);
			pu->Release();
			pu=NULL;
		}
	}
}

//
//void __traceIFaces(IUnknown *pUnk, LPCSTR szIFaceName, UINT il)
//{
//	ATLTRACE("LVL%d----------tracing %s----------\n", il, szIFaceName);
//
//	UINT n=il;
//
//	IUnknown* pu=NULL;
//	int i;
//	for (i=0; i<IFACECOUNT; i++)
//	{
//
//			if SUCCEEDED(pUnk->QueryInterface((IID&)g_IFaces[i].guid ,(void**)&pu))
//			{
//				if (pUnk!=pu)
//				{
//					ATLTRACE("LVL%d found %s (%x)\n", il, g_IFaces[i].iname, (void*)pu);
//
//
//					//__traceIFaces(pu, g_IFaces[i].iname, ++n);
//
//				}
//				else
//				{
//					ATLTRACE("LVL%d same interface found %s\n", il, g_IFaces[i].iname);
//				}
//
//				pu->Release();
//			pu=NULL;
//			}
//
//	}
//
//ATLTRACE("LVL%d----------------------------\n", il);
//}

#else
#define __traceIFaces(x)
#endif//DEBUG

//
//static void __tracefolderflags2(DWORD ff)
//{
//if (ff & FWF_NONE)	ATLTRACE("FWF_NONE");
//if (ff & FWF_AUTOARRANGE)	ATLTRACE(" | FWF_AUTOARRANGE");
//if (ff & FWF_ABBREVIATEDNAMES)	ATLTRACE(" | FWF_ABBREVIATEDNAMES");
//if (ff & FWF_SNAPTOGRID)	ATLTRACE(" | FWF_SNAPTOGRID");
//if (ff & FWF_OWNERDATA)	ATLTRACE(" | FWF_OWNERDATA");
//if (ff & FWF_BESTFITWINDOW)	ATLTRACE(" | FWF_BESTFITWINDOW");
//if (ff & FWF_DESKTOP)	ATLTRACE(" | FWF_DESKTOP");
//if (ff & FWF_SINGLESEL)	ATLTRACE(" | FWF_SINGLESEL");
//if (ff & FWF_NOSUBFOLDERS)	ATLTRACE(" | FWF_NOSUBFOLDERS");
//if (ff & FWF_TRANSPARENT)	ATLTRACE(" | FWF_TRANSPARENT");
//if (ff & FWF_NOCLIENTEDGE)	ATLTRACE(" | FWF_NOCLIENTEDGE");
//if (ff & FWF_NOSCROLL)	ATLTRACE(" | FWF_NOSCROLL");
//if (ff & FWF_ALIGNLEFT)	ATLTRACE(" | FWF_ALIGNLEFT");
//if (ff & FWF_NOICONS)	ATLTRACE(" | FWF_NOICONS");
//if (ff & FWF_SHOWSELALWAYS)	ATLTRACE(" | FWF_SHOWSELALWAYS");
//if (ff & FWF_NOVISIBLE)	ATLTRACE(" | FWF_NOVISIBLE");
//if (ff & FWF_SINGLECLICKACTIVATE)	ATLTRACE(" | FWF_SINGLECLICKACTIVATE");
//if (ff & FWF_NOWEBVIEW)	ATLTRACE(" | FWF_NOWEBVIEW");
//if (ff & FWF_HIDEFILENAMES)	ATLTRACE(" | FWF_HIDEFILENAMES");
//if (ff & FWF_CHECKSELECT)	ATLTRACE(" | FWF_CHECKSELECT");
//if (ff & FWF_NOENUMREFRESH)	ATLTRACE(" | FWF_NOENUMREFRES ");
//if (ff & FWF_NOGROUPING)	ATLTRACE(" | FWF_NOGROUPING");
//if (ff & FWF_FULLROWSELECT)	ATLTRACE(" | FWF_FULLROWSELECT");
//if (ff & FWF_NOFILTERS)	ATLTRACE(" | FWF_NOFILTERS");
//if (ff & FWF_NOCOLUMNHEADER)	ATLTRACE(" | FWF_NOCOLUMNHEADER");
//if (ff & FWF_NOHEADERINALLVIEWS)	ATLTRACE(" | FWF_NOHEADERINALLVIEWS");
//if (ff & FWF_EXTENDEDTILES)	ATLTRACE(" | FWF_EXTENDEDTILES");
//if (ff & FWF_TRICHECKSELECT)	ATLTRACE(" | FWF_TRICHECKSELECT");
//if (ff & FWF_AUTOCHECKSELECT)	ATLTRACE(" | FWF_AUTOCHECKSELECT");
//if (ff & FWF_NOBROWSERVIEWSTATE)	ATLTRACE(" | FWF_NOBROWSERVIEWSTATE");
//if (ff & FWF_SUBSETGROUPS)	ATLTRACE(" | FWF_SUBSETGROUPS");
//if (ff & FWF_USESEARCHFOLDER)	ATLTRACE(" | FWF_USESEARCHFOLDER");
//if (ff & FWF_ALLOWRTLREADING)	ATLTRACE(" | FWF_ALLOWRTLREADING");
//ATLTRACE("\n");
//}


#endif//_36DBD031_4072_4022_985B_DA22907E4520_
