#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 1. 固定分割

int stackSize = 100;

int *buffer = new int[stackSize * 3];
int stackPointer[] = {-1, -1, -1};


int absTopStack(int stackNum)
{
    return stackNum * stackSize + stackPointer[stackNum];
}


void push(int stackNum, int value)
{
    /*检查有无空闲空间*/
    if(stackPointer[stackNum] + 1 > stackSize)
    {
        throw "out of space";
    }

    stackPointer[stackNum]++;
    buffer[absTopStack(stackNum)] = value;
}

int pop(int stackNum)
{
    try
    {
        // 检查栈是否为空
        if(stackPointer[stackNum] == -1)
        {
            cout << "good" << endl;
        }
    }
    catch(const exception &e)
    {
        throw e.what();
    }

    int value = buffer[absTopStack(stackNum)];
    buffer[absTopStack(stackNum)] = 0;  // 清空该位置的值
    stackPointer[stackNum]--;

    return value;
}

int peek(int stackNum)
{
    int index = absTopStack(stackNum);
    return buffer[index];
}

bool isEmpty(int stackNum)
{
    return stackPointer[stackNum] == -1;
}

int main(int argc, char** argv)
{
    
    return 0;
}

// 2. 弹性分割
