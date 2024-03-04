#include <iostream>
#include "task.hpp"

using namespace std;

int main ()
{
    int a;
    int b;
    cin >> a >> b;
    int d = find_devider(a, b);
    cout << d;
    return 0;
}