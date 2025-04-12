// Shapec.cpp : CShape�� �����Դϴ�.
#include "stdafx.h"
#include "Shapec.h"


// CShape

STDMETHODIMP CShape::get_ShapeType(short* pVal)
{
	*pVal = m_nShapeType;
	return S_OK;
}

STDMETHODIMP CShape::put_ShapeType(short newVal)
{
	if(newVal < 0 || newVal > 2)
		return Error(L"�簢�� - 0, ���� - 1, �ﰢ�� - 2");
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
