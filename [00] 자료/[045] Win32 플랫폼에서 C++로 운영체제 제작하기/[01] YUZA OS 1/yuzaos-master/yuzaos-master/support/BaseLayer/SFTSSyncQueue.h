#pragma once
///////////////////////////////////////////////////////////////////////////
//������ ������ ����ȭ ť
///////////////////////////////////////////////////////////////////////////

template <typename T>
class SFTSSyncQueue
{
public:
	SFTSSyncQueue(void){}
	virtual ~SFTSSyncQueue(void){}

	virtual bool Push(T* pMsg) = 0;
	virtual T* Pop((int wait = -1) = 0;

protected:
	virtual bool Initialize() = 0;
	virtual bool Finally() = 0;

private:
};