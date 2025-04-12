// Shapec.cpp : CShape의 구현입니다.
#include "stdafx.h"
#include "Shapec.h"
#include ".\shapec.h"


// CShape

STDMETHODIMP CShape::get_ShapeType(short* pVal)
{
	*pVal = m_nShapeType;
	return S_OK;
}

STDMETHODIMP CShape::put_ShapeType(short newVal)
{
	if(newVal < 0 || newVal > 2)
		return Error(L"사각형 - 0, 원형 - 1, 삼각형 - 2");
	else {
		m_nShapeType = newVal;
		FireViewChange();
	}
	return S_OK;
}

STDMETHODIMP CShape::ChangeShape(short shpType)
{
	return put_ShapeType(shpType);
}
