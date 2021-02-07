#include <iostream>
using namespace std;
const int MAX = 100; //stack holds maximum 100 entries

template <class Type>
class Stack
{
private:
    Type arr[MAX]; //stack:array of type Type
    int top;       //index of top of stack

public:
    Stack() //constructor
    {
        top = -1;
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
        if (top >= MAX - 1) //condition to check if stack is full or not.
            throw Full();   //throw Full exception
        arr[++top] = var;
    }
    Type pop()
    {
        if (isEmpty())     //condition to check if stack is empty or not.
            throw Empty(); //throw Empty exception
        return arr[top--];
    }
    Type Top() //returns top element of stack
    {
        if (isEmpty())     //condition to check if stack is empty or not.
            throw Empty(); //throw Empty exception
        return arr[top];
    }
    bool isEmpty() //returns if the stack is empty or not
    {
        return (top == -1) ? true : false;
    }
    bool isFull() //returns if the Queue is empty or not
    {
        return (top >= MAX - 1) ? true : false;
    }
    void display() //prints all the elements of stack
    {
        if (top < 0) //condition to check if stack is empty or not.
            throw Empty();

        cout << "\n--------------------Stack--------------------\n";
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << endl;
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
        cout << "\n Top Element:" << s.Top() << endl;
        s.display();
        s.push(3);
        cout << "\n Top Element:" << s.Top() << endl;
        s.display();
        s.push(4);
        cout << "\n Top Element:" << s.Top() << endl;
        s.display();
        cout << "\n Popped Element:" << s.pop();
        s.display();
        cout << "\n Top Element:" << s.Top() << endl;
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
