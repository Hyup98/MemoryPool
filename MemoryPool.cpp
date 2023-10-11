#include "MemoryPool.h"

MemoryPool::MemoryPool(BlockSize size)
	:mSize(size),
	index(0)
{
	switch (mSize)
	{
	case BYTE64:
		pMemory64 = new BYTE_64[16];
		break;
	case BYTE32:
		pMemory32 = new BYTE_32[16];
		break;
	default:
		break;
	}

	mIndexTable = new int[ARRAYSIZE];

	for (int i = 0; i < ARRAYSIZE; i++)
	{
		mIndexTable[i] = i;
	}
}

MemoryPool::~MemoryPool()
{
	if(mSize == BYTE32)
		delete[] pMemory32;
	else
		delete[] pMemory64;

	delete[] mIndexTable;
}

void* MemoryPool::Alloc64()
{
	if (index == 15)
		return nullptr;

	index++;
	return pMemory64 + mIndexTable[index - 1];
}

void MemoryPool::Release64(BYTE_64* data)
{
	if (index == 0)
		return;

	index--;
	mIndexTable[index] = data - mBasePtr64;
}

void* MemoryPool::Alloc32()
{
	if (index == 15)
		return nullptr;
	index++;
	return pMemory32 + mIndexTable[index - 1];
}

void MemoryPool::Release32(BYTE_32* data)
{
	if (index == 0)
		return;

	index--;
	mIndexTable[index] = data - mBasePtr32;
}