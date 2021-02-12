# Tower of Hanoi Implementation in c++

Tower of Hanoi is a mathematical puzzle where we have three rods and n disks. The objective of the puzzle is to move the entire stack to another rod, obeying the following simple rules:

1. Only one disk can be moved at a time.
2. Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack i.e. a disk can only be moved if it is the uppermost disk on a stack
3. No disk may be placed on top of a smaller disk.

## Approach :

```
Take an example for 2 disks :
Let rod 1 = 'A', rod 2 = 'B', rod 3 = 'C'.

Step 1 : Shift first disk from 'A' to 'B'.
Step 2 : Shift second disk from 'A' to 'C'.
Step 3 : Shift first disk from 'B' to 'C'.

The pattern here is :
Shift 'n-1' disks from 'A' to 'B'.
Shift last disk from 'A' to 'C'.
Shift 'n-1' disks from 'B' to 'C'.
```

## C++ Implementation of Tower Of Hanoi

```c++
#include <iostream>
using namespace std;

void towerOfHanoi(int n, char src,
                  char des, char aux)
{
    if (n == 1)
    {
        cout << "Move disk 1 from rod " << src << " to rod " << des << endl;
        return;
    }
    towerOfHanoi(n - 1, src, aux, des);
    cout << "Move disk " << n << " from rod " << src << " to rod " << des << endl;
    towerOfHanoi(n - 1, aux, des, src);
}

int main()
{
    int n = 3;                      // Number of disks
    towerOfHanoi(n, 'A', 'C', 'B'); // A, B and C are names of rods
    return 0;
}

```

## Output of above program

```
Move disk 1 from rod A to rod C
Move disk 2 from rod A to rod B
Move disk 1 from rod C to rod B
Move disk 3 from rod A to rod C
Move disk 1 from rod B to rod A
Move disk 2 from rod B to rod C
Move disk 1 from rod A to rod C
```

## Notes
