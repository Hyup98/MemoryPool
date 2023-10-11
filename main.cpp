#include<iostream>
#include "MemoryPool.h"
#include <chrono>

using namespace std;
using namespace chrono;

int main(void)
{
    cout << "--------------------------------" << endl
         << "|        Alloc By new          |" << endl
         << "--------------------------------" << endl;
    system_clock::time_point t_time_begin, t_time_end;
    milliseconds t_diff_msec;
    int t = 0;
    t_time_begin = system_clock::now();
    for (size_t i = 0; i < 10000000; i++)
    {
        BYTE_64* test1 = new BYTE_64;
        test1->a1 = i;
        delete test1;
    }
    t_time_end = system_clock::now();
    t_diff_msec = duration_cast<milliseconds>(t_time_end - t_time_begin);
    printf("time diff : %d ms\n\n", (int)t_diff_msec.count());
    MemoryPool testPool(BYTE64);

    cout << "--------------------------------" << endl
         << "|      Alloc By MemoryPoo      |" << endl
         << "--------------------------------" << endl;


    t_time_begin = system_clock::now();
    for (size_t i = 0; i < 10000000; i++)
    {
        BYTE_64* test2 = (BYTE_64*)testPool.Alloc64();
        test2->a1;
        testPool.Release64(test2);
    }
    t_time_end = system_clock::now();
    t_diff_msec = duration_cast<milliseconds>(t_time_end - t_time_begin);
    printf("time diff : %3d ms\n\n", (int)t_diff_msec.count());





    return 0;
}