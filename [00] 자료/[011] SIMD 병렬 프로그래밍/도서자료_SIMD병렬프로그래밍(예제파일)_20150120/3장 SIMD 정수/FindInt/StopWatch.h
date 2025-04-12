// StopWatch.h: interface for the CStopWatch class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STOPWATCH_H__C2068F0F_528F_43C3_9A72_ECA8A4DCAFA2__INCLUDED_)
#define AFX_STOPWATCH_H__C2068F0F_528F_43C3_9A72_ECA8A4DCAFA2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afxwin.h>

class AFX_EXT_CLASS CStopWatch  
{
public:
	CStopWatch();
	virtual ~CStopWatch();

public:
	void Start(void);
	void End(void);
	const float GetDurationSecond(void) const { return m_fTimeforDuration; }
	const float GetDurationMilliSecond(void) const { return m_fTimeforDuration*1000.f; }

public:
	LARGE_INTEGER GetStartInteger(void) const { return m_swStart; }
	LARGE_INTEGER GetEndInteger(void) const { return m_swEnd; }
	LARGE_INTEGER GetFrequency(void) const { return m_swFreq; }

protected:
	LARGE_INTEGER		m_swFreq, m_swStart, m_swEnd;
	float				m_fTimeforDuration;
};

#endif // !defined(AFX_STOPWATCH_H__C2068F0F_528F_43C3_9A72_ECA8A4DCAFA2__INCLUDED_)
