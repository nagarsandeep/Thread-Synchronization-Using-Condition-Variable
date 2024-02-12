// Thread Synchronization Using Condition Variable.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<thread>
#include"Thread Synchronization Using Condition Variable.h"


void Thread_Synchronization_Using_Condition_Variable::UpdateVal()
{
    std::unique_lock<std::mutex> ul(mt);
    cond.wait(ul, [&]() {if (cond_flag == 1) return true; else return false; });
    std::cout << "Multiplying the values\n";
    val = val * val;
    cond_flag++;
    ul.unlock();
}

void Thread_Synchronization_Using_Condition_Variable::ReadVal()
{
    std::unique_lock<std::mutex> ul(mt);
    val++;
    std::cout << "Enter the value: ";
    std::cin >> val;
    cond_flag++;
    cond.notify_one();
}

void Thread_Synchronization_Using_Condition_Variable::PrintVal()
{
    std::unique_lock<std::mutex> ul(mt);
    cond.wait(ul, [&]() {if (cond_flag == 2) return true; else return false; });
    cond_flag = 0;
    std::cout << "Value is " << val << std::endl;
}


int main()
{
    Thread_Synchronization_Using_Condition_Variable obj;
    obj.ReadVal();
    obj.UpdateVal();
    obj.PrintVal();
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
