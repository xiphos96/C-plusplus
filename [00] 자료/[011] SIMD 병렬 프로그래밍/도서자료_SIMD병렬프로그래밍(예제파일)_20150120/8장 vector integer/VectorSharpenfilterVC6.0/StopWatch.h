// StopWatch.h: interface for the CStopWatch class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STOPWATCH_H__E7816932_3565_43D8_8DDB_F4C17B7C249D__INCLUDED_)
#define AFX_STOPWATCH_H__E7816932_3565_43D8_8DDB_F4C17B7C249D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CStopWatch  
{
public:
	CStopWatch();
	virtual ~CStopWatch();
	
public:
	void Start();
	void End();
	const float GetDurationSecond() const { return m_fTimeforDuration; }
	const float GetDurationMilliSecond() const { return m_fTimeforDuration*1000.f; }
	
protected:
	LARGE_INTEGER		m_swFreq, m_swStart, m_swEnd;
	float				m_fTimeforDuration;
};

#endif // !defined(AFX_STOPWATCH_H__E7816932_3565_43D8_8DDB_F4C17B7C249D__INCLUDED_)
