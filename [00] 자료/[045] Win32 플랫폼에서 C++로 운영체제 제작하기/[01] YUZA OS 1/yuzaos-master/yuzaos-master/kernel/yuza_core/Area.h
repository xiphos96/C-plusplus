#pragma once

#include "AVLTree.h"
#include "Resource.h"
#include "PageCache.h"

// ����(area)�� ��� ������� ���� �ּ� ������ ǥ���Ѵ�.
// ������ �޸� ���� �����̰ų� ���� �����̳� Ŀ�� ������ �͸��� ���ҵ� ������ �� �ִ�.
// �Ǵ� Ŀ�� ���ð��� ��� ������ �������� �� �ִ�.(���ҵǾ�� �ȵǴ�)
class Area : public AVLNode, public Resource {
public:
	inline Area(const char name[], PageProtection = 0, PageCache* = 0, off_t = 0,
		AreaWiring lock = AREA_WIRED);
	virtual ~Area();

	// �� ������ ���� ���� ���� �ּҸ� ��ȯ�Ѵ�.
	inline unsigned int GetBaseAddress() const;

	// ���� ���� ���� �ּҿ��� ���� ���� �ּұ����� ����Ʈ ũ�⸦ ��ȯ�Ѵ�.
	inline unsigned int GetSize() const;

	// �� ������ ���õ� ������ ĳ���� ��ȯ�Ѵ�. ������ ĳ���� �� �������� �߻��ϴ� ������ ��Ʈ�� �ذ��ϱ� ���� ���ȴ�.
	inline PageCache* GetPageCache() const;

	// �� �������� ��� �������� ���� ��Ű��ó �������� �����ؼ� �÷��׸� ��´�.Get architecture independent protection flags for all pages in this area (can
	// �������� ������ �ý���, �Ǵ� �� ��ΰ� ���ų� ���� �� �ִ�.
	inline PageProtection GetProtection() const;

	//�� ������ ���� ���� �ּҿ� ���� ������ ĳ�� ������
	inline off_t GetCacheOffset() const;

	/// �������� ���ҵ� �� �ִ����� �����Ѵ�.
	inline AreaWiring GetWiring() const;

private:
	PageProtection m_protection;
	PageCache *fPageCache;
	off_t fCacheOffset;
	AreaWiring m_wiring;
};

inline Area::Area(const char name[], PageProtection protection, PageCache *cache, off_t offset, AreaWiring lock)
	:	Resource(OBJ_AREA, name),
	m_protection(protection),
		fPageCache(cache),
		fCacheOffset(offset),
	m_wiring(lock)
{
	if (fPageCache)
		fPageCache->AcquireRef();

	AcquireRef();
}

inline Area::~Area()
{
	if (fPageCache)
		fPageCache->ReleaseRef();
}

inline unsigned int Area::GetBaseAddress() const
{
	return GetLowKey();
}

inline unsigned int Area::GetSize() const
{
	return GetHighKey() - GetLowKey() + 1;
}

inline PageCache* Area::GetPageCache() const
{
	return fPageCache;
}

inline PageProtection Area::GetProtection() const
{
	return m_protection;
}

inline off_t Area::GetCacheOffset() const
{
	return fCacheOffset;
}

inline AreaWiring Area::GetWiring() const
{
	return m_wiring;
}