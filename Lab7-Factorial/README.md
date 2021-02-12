# Factorial Implementation in c++

Factorial can be calculated using following recursive formula.

```
  n! = n * (n-1)!
  n! = 1 if n = 0 or n = 1
```

```c++
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

```

## Output of above program

```
Factorial of 8 is 40320
```

## Notes
