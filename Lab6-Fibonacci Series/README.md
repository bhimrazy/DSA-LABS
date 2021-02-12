# Fibonacci Series Implementation in c++

The Fibonacci numbers are the numbers in the following integer sequence.
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ……..

In mathematical terms, the sequence Fn of Fibonacci numbers is defined by the recurrence relation

> Fn = Fn-1 + Fn-2
> with seed values

> F0 = 0 and F1 = 1.

```c++
#include <iostream>
using namespace std;
int fib(int x)
{
    if ((x == 1) || (x == 0))
    {
        return (x);
    }
    else
    {
        return (fib(x - 1) + fib(x - 2));
    }
}
int main()
{
    int x, i = 0;
    cout << "Enter the number of terms of series : ";
    cin >> x;
    cout << "\nFibonnaci Series : ";
    while (i < x)
    {
        cout << " " << fib(i);
        i++;
    }
    return 0;
}
```

## Output of above program

```
Enter the number of terms of series : 10
Fibonnaci Series :  0 1 1 2 3 5 8 13 21 34
```

## Notes
