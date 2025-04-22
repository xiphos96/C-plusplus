#pragma once
#include <stl_alloc.h>
#include <list>
#include <winnt.h>

template <typename T, template <typename> class AL = std::allocator>


class CLockFreeStack
{
private:
#pragma pack(push)
#pragma pack(MEMORY_ALLOCATION_ALIGNMENT)
    /// ���� �����͸� �����ϱ� ���� ����ü.
    struct NODE
    {
        SLIST_ENTRY List;
        T           Data;
    };
#pragma pack(pop)

    SLIST_HEADER m_ListHead;  ///< ����Ʈ ���.
    AL<NODE>     m_Allocator; ///< �޸� �Ҵ���.


public:
    /// \brief ������.
    CLockFreeStack()
    {
        InitializeSListHead(&m_ListHead);
    }

    /// \brief �Ҹ���.
    ~CLockFreeStack()
    {
        Clear();
    }


public:
    /// \brief �����͸� �߰��Ѵ�.
    /// \param data �߰��� ������.
    void Push(const T& data)
    {
        NODE* newNode = m_Allocator.allocate(1);
        m_Allocator.construct(newNode, NODE());
        newNode->Data = data;
        InterlockedPushEntrySList(&m_ListHead, &newNode->List);
    }

    /// \brief �����͸� �̾Ƴ���.
    /// \param data �̾Ƴ� �����͸� �� ����.
    /// \return bool �����͸� �̾Ƴ� ��쿡�� true�� ��ȯ�ϰ�, 
    /// �����Ͱ� ���� ��쿡�� false�� ��ȯ�Ѵ�.
    bool Pop(T& data)
    {
        PSLIST_ENTRY entry = InterlockedPopEntrySList(&m_ListHead);
        if (entry)
        {
            NODE* node = reinterpret_cast<NODE*>(entry);
            data = node->Data;
            m_Allocator.destroy(node);
            m_Allocator.deallocate(node, 0);
            return true;
        }

        return false;
    }

    /// \brief ��� �����͸� �����Ѵ�.
    void Clear()
    {
        T data;
        while (Pop(data))
            ;
    }


private:
    /// \brief ���� ���� ����.
    CLockFreeStack(const CLockFreeStack&) {}

    /// \brief ���� ����.
    CLockFreeStack& operator = (const CLockFreeStack&) { return *this; }
};



