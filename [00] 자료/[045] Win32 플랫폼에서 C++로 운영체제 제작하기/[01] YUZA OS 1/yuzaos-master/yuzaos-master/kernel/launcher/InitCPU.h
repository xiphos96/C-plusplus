#pragma once
#include <MultBootUtil.h>

bool InitCPU();
//����/���� �޸� �Ŵ����� �ʱ�ȭ�Ѵ�.
bool InitPhysicalMemorySystem(multiboot_info_t* pBootInfo);
bool InitVirtualMemorySystem(int maskPageCount);