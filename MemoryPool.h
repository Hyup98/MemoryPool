#pragma once

enum BlockSize
{
    BYTE64,
    BYTE32,
};

struct BYTE_32
{
    double a1;
    double a2;
    double a3;
    double a4;
};

struct BYTE_64
{
    double a1;
    double a2;
    double a3;
    double a4;
    double a5;
    double a6;
    double a7;
    double a8;
};

class MemoryPool
{
    
public:
    MemoryPool(BlockSize size);
    ~MemoryPool();

    void* Alloc32(); 
    void* Alloc64();
    void Release64(BYTE_64* data);
    void Release32(BYTE_32* data);

    
private:
    BYTE_32* pMemory32;
    BYTE_64* pMemory64;
    BYTE_32* mBasePtr32;
    BYTE_64* mBasePtr64;
    BlockSize mSize;
    int* mIndexTable;
    const int ARRAYSIZE = 16;
    int index;
};

