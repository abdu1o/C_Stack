#include <iostream>
#include <exception>
using namespace std;
#include "Class.h"

int main() 
{
    try 
    {
        Stack stack(5);
        
        for (int i = 0; i < 5; i++)
        {
            stack.Push(i);
        }
        stack.Print();

        for (int i = 0; i < 6; i++)
        {
            stack.Push(i);
        }
    }
    catch (const exception& ex) 
    {
        cerr << ex.what() << endl;
    }
}