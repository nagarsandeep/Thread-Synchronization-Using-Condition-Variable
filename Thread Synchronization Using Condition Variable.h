#pragma once
#include<iostream>
#include<vector>
#include<mutex>

#include<condition_variable>

class Thread_Synchronization_Using_Condition_Variable
{
    std::mutex mt;
    std::condition_variable cond;
    int val = 0;
    int cond_flag = 0;
public:
    void ReadVal();
    void UpdateVal();
    void PrintVal();

};


