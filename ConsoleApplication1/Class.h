#pragma once

class Stack
{
private:
    int* _stackArr;
    int _topIndex;
    int _size;

public:

    Stack(int stackSize) : _topIndex(-1), _size(stackSize)
    {
        if (_size <= 0)
        {
            throw invalid_argument("Stack size must be positive");
        }
        _stackArr = new int[_size];

        if (_stackArr == nullptr)
        {
            throw ("Stack is nullptr");
        }
    }

    ~Stack()
    {
        delete[] _stackArr;
    }

    void Push(int value)
    {
        if (_topIndex == _size - 1)
        {
            throw overflow_error("Stack overflow!");
        }
        _stackArr[++_topIndex] = value;
    }

    int Pop()
    {
        if (_topIndex == -1)
        {
            throw ("Top index < 0");
        }

        return _stackArr[_topIndex--];
    }

    const bool IsEmpty()
    {
        return _topIndex == -1;
    }

    const bool IsFull()
    {
        return _topIndex == _size - 1;
    }

    const void Print()  
    {
        cout << "Ur stack: ";
        if (IsEmpty()) 
        {
            cout << "is empty";
        }
        else 
        {
            for (int i = _topIndex; i >= 0; i--) 
            {
                cout << _stackArr[i] << " ";
            }
        }
        cout << endl;
    }
};