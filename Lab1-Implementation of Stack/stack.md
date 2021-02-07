# Stack Implementation in c++

## Time Complexity of Stack

> <p>

    Push - O(1)->Best Case

     - O(n)->Worst Case
     - O(1)->Average Case

</p>

### C++ Implementation of Stack

```c++
#include <iostream>
using namespace std;
const int MAX = 100; //stack holds maximum 100 entries

template <class Type>
class Stack
{
private:
    Type st[MAX]; //stack:array of type Type
    int Top;      //index of Top of stack

public:
    Stack() //constructor
    {
        Top = -1;
    }
    // Exceptions
    class Full //exception class for full stack
    {
    };
    class Empty //exception class for empty stack
    {
    };
    //Member Functions
    void push(Type var) //push numbers on stack
    {
        if (Top >= MAX - 1) //condition to check if stack is full or not.
            throw Full();   //throw Full exception
        st[++Top] = var;
    }
    Type pop()
    {
        if (Top < 0)       //condition to check if stack is empty or not.
            throw Empty(); //throw Empty exception
        return st[Top--];
    }
    Type top() //returns top element of stack
    {
        return st[Top];
    }
    bool isEmpty() //returns if the stack is empty or not
    {
        return (Top == -1) ? true : false;
    }
    void display() //prints all the elements of stack
    {
        if (Top < 0) //condition to check if stack is empty or not.
            throw Empty();

        cout << "\n--------------------Stack--------------------\n";
        for (int i = Top; i >= 0; i--)
        {
            cout << st[i] << endl;
        }
        cout << "\n--------------------End--------------------\n";
    }
};
int main()
{
    Stack<int> s;
    try
    {
        if (s.isEmpty())
        {
            cout << "\n Stack is Empty" << endl;
        }
        s.push(2);
        cout << "\n Top Element:" << s.top() << endl;
        s.display();
        s.push(3);
        cout << "\n Top Element:" << s.top() << endl;
        s.display();
        s.push(4);
        cout << "\n Top Element:" << s.top() << endl;
        s.display();
        s.pop();
        s.display();
        cout << "\n Top Element:" << s.top() << endl;
    }
    catch (Stack<int>::Full)
    {
        cout << "\nException: Stack Full/Overflow" << endl;
    }
    catch (Stack<int>::Empty)
    {
        cout << "\nException: Stack Empty/Underflow" << endl;
    }

    return 0;
}

```

##Output of above program

```
Stack is Empty


 Top Element:2

--------------------Stack--------------------
2

--------------------End--------------------

 Top Element:3

--------------------Stack--------------------
3
2

--------------------End--------------------

 Top Element:4

--------------------Stack--------------------
4
3
2

--------------------End--------------------

--------------------Stack--------------------
3
2

--------------------End--------------------

 Top Element:3
```

### Note

> <p>
> Incase of **Overflow** -> Create a larger array (double the size of previous) and then copy all the elements.

</p>
