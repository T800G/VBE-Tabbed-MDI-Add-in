#ifndef _DISPHELPER_80522B16_E4B3_42FF_9322_4BE206925134_
#define _DISPHELPER_80522B16_E4B3_42FF_9322_4BE206925134_
#include <oaidl.h>

//
//   FUNCTION: AutoWrap(int, VARIANT*, IDispatch*, LPOLESTR, int,...)
//   PURPOSE: Automation helper function. It simplifies most of the low-level 
//      details involved with using IDispatch directly. Feel free to use it 
//      in your own implementations. One caveat is that if you pass multiple 
//      parameters, they need to be passed in reverse-order.
//   PARAMETERS:
//      * autoType - Could be one of these values: DISPATCH_PROPERTYGET, 
//      DISPATCH_PROPERTYPUT, DISPATCH_PROPERTYPUTREF, DISPATCH_METHOD.
//      * pvResult - Holds the return value in a VARIANT.
//      * pDisp - The IDispatch interface.
//      * ptName - The property/method name exposed by the interface.
//      * cArgs - The count of the arguments.
//   RETURN VALUE: An HRESULT value indicating whether the function succeeds or not.
//   EXAMPLE: 
//      AutoWrap(DISPATCH_METHOD, NULL, pDisp, L"call", 2, parm[1], parm[0]);
//
HRESULT AutoWrap(int autoType, VARIANT *pvResult, IDispatch *pDisp, LPOLESTR ptName, int cArgs...)
{
	if (!pDisp) return E_INVALIDARG;

	// Variables used
	DISPPARAMS dp = { NULL, NULL, 0, 0 };
	DISPID dispidNamed = DISPID_PROPERTYPUT;
	DISPID dispID;
	HRESULT hr;

	// Get DISPID for name passed
	hr = pDisp->GetIDsOfNames(IID_NULL, &ptName, 1, /*LOCALE_USER_DEFAULT*/ LOCALE_SYSTEM_DEFAULT, &dispID);
	if (FAILED(hr))
	{
//#ifdef _DEBUG
		OutputDebugString(_T("AutoWrap::IDispatch->GetIDsOfNames failed\n"));
		_com_error err(hr);
		OutputDebugString(err.ErrorMessage()); OutputDebugString(_T("\n"));
//#endif//_DEBUG
		return hr;
	}
	
	// Begin variable-argument list
	va_list marker;
	va_start(marker, cArgs);
	
	// Allocate memory for arguments
	VARIANT *pArgs = new VARIANT[cArgs + 1];
	// Extract arguments...
	for(int i=0; i < cArgs; i++)
	{
		pArgs[i] = va_arg(marker, VARIANT);
	}

	// Build DISPPARAMS
	dp.cArgs = cArgs;
	dp.rgvarg = pArgs;

	// Handle special-case for property-puts
	if (autoType & DISPATCH_PROPERTYPUT)
	{
		dp.cNamedArgs = 1;
		dp.rgdispidNamedArgs = &dispidNamed;
	}

	// Make the call
	hr = pDisp->Invoke(dispID, IID_NULL, /*LOCALE_USER_DEFAULT*/ LOCALE_SYSTEM_DEFAULT, (WORD)autoType, &dp, pvResult, NULL, NULL);
	if FAILED(hr) 
	{
//#ifdef _DEBUG
		OutputDebugString(_T("AutoWrap::IDispatch->Invoke failed\n"));
		_com_error err(hr);
		OutputDebugString(err.ErrorMessage()); OutputDebugString(_T("\n"));
//#endif//_DEBUG
	}

	// End variable-argument section
	va_end(marker);
	delete[] pArgs;
return hr;
}

#endif//_DISPHELPER_80522B16_E4B3_42FF_9322_4BE206925134_
