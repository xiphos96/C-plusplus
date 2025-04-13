#pragma once
#include <memory.h>
#include "AVLTree.h"
#include "Mutex.h"
#include "ktypes.h"

class Area;
class PageCache;
class PhysicalMap;
class Team;

// AddressSpace�� �ϵ���� �������� ���� �ּ� ������ ǥ���Ѵ�.
// �� ���μ����� �ϳ��� AddressSpace ��ü�� ������.
class AddressSpace 
{
public:
	AddressSpace();
	~AddressSpace();

	// �ּҰ������� ������ ������ �����ּ� ������ �Ҵ��Ѵ�.
	// @param name �ش� Area�� �̸�. ����� �������� ���
	// @param areaSize Area�� ����Ʈ ũ��. ���� �������� ������� �Ѵ�.
	// @param wiring ���������� ��Ȳ�� ���� ���Ұ��������� �����Ѵ�. �� ���� true�̸� �޸𸮿��� ���ҵ��� �ʴ´�.
	// @param protection �������� ���۹�����, ������ ���� �б�/���Ⱑ ���������� �����Ѵ�.
	// @param PageCache �� Area�� ���ε� �������� ���� �� �ִ�. �� ���� 0�̸� ���� Area�� ���ٽ� �׻� ������ ��Ʈ�� �߻��� ���̴�.
	// @param cacheOffset ������ Area�� ���� ���� �ּҸ� ���� ������ ĳ�� �������� ������. PageCache�� 0�̸� �ǹ̰� ����.
	// @param va : �� Area�� ���� ���� ���� �ּ�. ���� �������� ����� �ش��ؾ� �Ѵ�.
	// �� ���� INVALID_PAGE��� �� �Լ��� areaSize ũ���� ������ ���� �ּҰ����� ã�Ƽ� ������ Area�� ���̽� �ּҷ� �����Ѵ�.
	// @param flags Area�� �����ϱ� ���� ����� ���� �÷���(�ֻ��� �ּ�, �Ǵ� ���� ���� �ּҿ��� ���� ��ȿ�� �ּҰ����� ã�� �� ���)
	// @returns
	// - ������ Area ��ü�� �����͸� ��ȯ�Ѵ�.
	// - Area ��ü ���н� NULL�� ��ȯ�Ѵ�.
	Area* CreateArea(const char name[], unsigned int areaSize, AreaWiring wiring, PageProtection protection,
		PageCache *cache, off_t cacheOffset, unsigned int va = INVALID_PAGE, int flags = 0);

	// ���� �޸𸮿� �����ϴ� Area�� �����Ѵ�.
	// ����̽��� ���� �޸𸮿� ���εǹǷ� �� �޼ҵ�� ����̽� ����̹��� �ַ� ����Ѵ�.
	// @returns
	// - ������ Area ��ü�� �����͸� ��ȯ�Ѵ�.
	// - Area ��ü ���н� NULL�� ��ȯ�Ѵ�.
	Area* MapPhysicalMemory(const char name[], unsigned int pa, unsigned int size,
		PageProtection protection, unsigned int fixed_va = INVALID_PAGE);

	// ���� Area�� ũ�⸦ ����. ���� Area�� ���õ� Backing Store�� �Ҵ��ϰų� ������.
	// @param area �������� Area
	// @param newSize �������� Area�� ���ο� ũ��(����Ʈ ����). ���� �������� ������� �Ѵ�.
	// @returns
	// - E_NO_ERROR ���������� �������Ǿ��� ���
	// - E_NO_MEMORY 
	int ResizeArea(Area *area, unsigned int newSize);

	// �� �ּ� �������� �ش� Area�� �����ϰ� �� Area�� �����ߴ� ��� �������� ������ �����Ѵ�
	void DeleteArea(Area* pArea);

	// �����尡 �� �ּҰ����� ���ε� ���� �������� ������ ���� �޸� ���� ���� �õ��� �Ҷ� ȣ��ȴ�.
	// ������ ��Ʈ�� �߻��ϸ� �ش� �ּҿ� ������ �������� ������ ���̴�.
	// @param va ������ ���� �õ��� ���� �ּ�
	// @param write �ּҰ����� ���⸦ �õ������� true, �б�õ��� ������ false��.
	// @param user ���� �ڵ尡 �� �ּҿ� ���� �õ������� true, ���۹����� �ڵ尡 ���������� false
	// @returns
	//  - E_NOT_ALLOWED �����尡 �־��� Area�� �����ؼ� ������ ������ ������ ���� �ʴ�.
	// (������� ���� �����尡 ���۹��������� ����� �б� ������ Area�� ���� �õ�)
	// - E_IO Backing Store�� ���� �����͸� �дµ��� ������ �߻��ߴ�.
	// - E_BAD_ADDRESS ���ٵ� �ּҿ� ������ �� �ִ� Area�� ����.
	// - E_NO_ERROR �������� �� �ּҿ� ���������� ���ε�
	int HandleFault(unsigned int va, bool write, bool user);

	// �� �ּ� �������� �ֱٿ� ������ ���� ���� �������� ���������Ѵ�.
	// �翬�� �̾߱����� �������� ȸ���ϸ� �׸�ŭ �������� ���������� Ȯ���Ѵٴ� �ǹ��̹Ƿ� �ٸ� ���μ����� �˳��� �ڿ��� ������ �� �� �ִ�.
	void TrimWorkingSet();

	// �ش� �ּҰ����� ���� ����� ������ ���
	void Print() const;

	/// ��Ű��ó �������� ���� ������Ʈ�� ��´�.
	const PhysicalMap* GetPhysicalMap() const;


	/// Get the address space that the current thread is executing in
	static AddressSpace* GetCurrentAddressSpace();

	/// Get the address space for the kernel (note, although the kernel is physically mapped into
	/// the top of every address space, it has its own AddressSpace object representing it).
	static AddressSpace* GetKernelAddressSpace();

	/// Called at boot time to initialize structures
	static void Bootstrap();

	/// This thread just attempts to remove least frequently pages from address spaces
	/// @bug Shouldn't this be private?
	/// @bug Shouldn't this be NORETURN?
	static void PageDaemonLoop();
	
private:
	AddressSpace(PhysicalMap* physicalMap);
	//�־��� ũ���� ������� �ּҰ������� �����ϴ��� Ȯ���ϰ�
	//�����ϸ� �ش� ���� �����ּҰ���, �������� ������ INVALID_PAGE�� ��ȯ�Ѵ�.
	unsigned int FindFreeRange(unsigned int size, int flags = 0) const; 
	
	PhysicalMap* m_pPhysicalMap;
	RWLock m_areaLock;
	int m_faultCount; //������ ��Ʈ ī��Ʈ ��
	AVLTree fAreas;
	volatile int m_changeCount; //Area�� �����ǰų� ���� �Ǵ� ��������ɶ� ī��Ʈ��
	
	int fWorkingSetSize;
	int fMinWorkingSet;
	int fMaxWorkingSet;
	bigtime_t fLastWorkingSetAdjust;
	unsigned int fNextTrimAddress;


	static AddressSpace *fKernelAddressSpace;
	static void TrimTeamWorkingSet(void*, Team*);
};
