/** 
*  @file		NFSingleton.h
*  @brief		�̱��� Ŭ����
*  @remarks	
*  @author		������(edith2580@gmail.com)
*  @date		2009-04-02
*/

#pragma once

#include <minwindef.h>
#include <stdio.h>
#include <assert.h>

/*
#include "NFSingleton.h"

class Test : public Nave::NFSingleton<Test>
{
public:
Test()
{
printf("Test::Test()\n");
}
~Test()
{
printf("Test::~Test()\n");
}

int GetType()
{
return 0;
}
};

INT _tmain(INT argc, WCHAR* argv[])
{
// ���� �̱��� ��ü�� ����Ϸ��� 
// �Ʒ��� ���� ����ϱ� ���ؼ� �ѹ� New�� �ϰ�
Test* pTest = new Test;


// �ٸ� ��ġ�� �ٸ��Լ�.
Test::GetInstance().GetType(); �� ���� ����ϸ� �ȴ�.


delete pTest;
}
*/

#pragma warning (disable : 4311)
#pragma warning (disable : 4312)
#pragma warning (disable : 6011)

/** 
*  @class        NFSingleton
*  @brief        Ŭ���� ��ü�� �̱������� �����մϴ�.
*  @remarks      
*             
*  @warning	  �ش� �̱��� ��ü�� ó�� ������ ���� new�� ������ ���ְ�	\r\n
*				  delete�� �ɶ����� �̱��� ���� ����ϸ� ���α׷��� ����ɶ�\r\n
*				  delete�� ���ָ� �ȴ�.										
*  @par          
*  @author  Edith
*  @date    2009-04-05
*/
template <typename T> class CSingleton
{

public:
	/// NFSingleton ������
	CSingleton (void)
	{
		assert( !s_pSingleton && "NFSingleton : You can't create more"
			" object, because this object is SINGLETON.");

#if defined( _MSC_VER ) && _MSC_VER < 1200	 
		int iOffset = (int)(T*)1 - (int)(CSingleton <T>*)(T*)1;
		s_pSingleton = (T*)((int) this + iOffset);
#else
		s_pSingleton = static_cast< T* >( this );
#endif
	}

	/// NFSingleton �Ҹ���
	~CSingleton (void)
	{
		assert( s_pSingleton && "NFSingleton : This object may be "
			"destroyed by someone's memory control or other causes.");

		s_pSingleton = 0;
	}

	/// �ش� �̱��� ��ü�� �����Ǵ��� Ȯ���Ѵ�.
	static bool IsAlive()
	{
		return s_pSingleton ? true : false;
	}

	/// �̱��� ��ü�� �ν��Ͻ��� ��´�.
	static T& GetInstance(void)
	{
		assert (s_pSingleton && "NFSingleton : Something is wrong."
			" This object destroyed by something bad method or"
			"you didn't create yet!");

		return *s_pSingleton;
	}

	/// �̱��� ��ü�� ������ �ν��Ͻ��� �����͸� ��´�
	static T* GetInstancePtr(void)
	{
		assert (s_pSingleton && "NFSingleton : Something is wrong."
			" This object destroyed by something bad method.");

		return s_pSingleton;
	}

private:
	/// �̱��� ��ü�� ���� ��ü�� ������
	static T* s_pSingleton;
};

/// �̱��� ��ü ������ �ʱ�ȭ �Ѵ�.
template<typename T> T* CSingleton<T>::s_pSingleton = 0;

