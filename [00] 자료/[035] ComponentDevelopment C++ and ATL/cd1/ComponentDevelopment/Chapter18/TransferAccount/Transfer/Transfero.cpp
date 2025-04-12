// Transfero.cpp : Implementation of CTransfer

#include "stdafx.h"
#include "Transfero.h"


// CTransfer
#import "progid:Debit.Debit.1" no_namespace
#import "progid:Credit.Credit.1" no_namespace

STDMETHODIMP CTransfer::MoveMoney(long srcAccount, long destAccount, long amount)
{
	// TODO: Add your implementation code here
	IObjectContext* pIContext = NULL;
	::CoGetObjectContext(IID_IObjectContext, (LPVOID*)&pIContext);

	IDebitPtr pIDebit = IDebitPtr(__uuidof(Debit));
	pIDebit->ChangeAccount(srcAccount, amount);
	ICreditPtr pICredit = ICreditPtr(__uuidof(Credit));
	pICredit->ChangeAccount(destAccount, amount);
	
	pIContext->SetComplete();
	pIContext->Release();
	return S_OK;
}
