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