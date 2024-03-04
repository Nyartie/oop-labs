#include <iostream>

int find_devider(int a, int b)
{
    a = abs(a);
    b = abs(b);

    while (a != 0 and b != 0)
    {
        if (a > b) a = a % b;
        else b = b % a;
    }
    
    return a + b;
}