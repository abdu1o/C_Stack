#include <iostream>
#include <exception>
#include <string>
using namespace std;
#include "Class.h"

int StringToInt(const string& str)
{
    int result = 0;
    bool negative = false;
    int i = 0;

    if (str[0] == '-') 
    {
        negative = true;
        i++;
    }

    for (int i = 0; i < str.length(); i++) 
    {
        if (str[i] >= '0' && str[i] <= '9') 
        {
            int digit = str[i] - '0';

            if (negative) 
            {
                digit = -digit;
            }

            if (result > 2147483647 || (result == 2147483647 && digit > 7))
            {
                throw ("Int is out bounds");
            }
            if (result < -2147483647 || (result == -2147483647 && digit < -8))
            {
                throw ("Int is out bounds");
            }
            result = result * 10 + digit;
        }
        else 
        {
            throw ("Wrong string input");
        }
    }
    return result;
}

int main() 
{
    //1 task
    string str;
    cout << "Enter an string of numbers: ";
    cin >> str;
    try 
    {
        int result = StringToInt(str);
        cout << "Result: " << result << endl;
    }
    catch (const exception& ex) 
    {
        cerr << "Error: " << ex.what() << endl;
    }


    //2 task
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