#include <iostream>
using namespace std;

// function to find factorial of given number
int factorial(int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

int main()
{
    int num = 8;
    cout << "Factorial of "
         << num << " is " << factorial(num) << endl;
    return 0;
}
