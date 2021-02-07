#include <iostream>
using namespace std;
const int MAX = 100; //Queue holds maximum 100 entries

template <class Type>
class Queue
{
private:
    Type arr[MAX]; //Queue:array of type Type
    int front;     //index of front of Queue
    int rear;      //index of rear of Queue
public:
    Queue() //constructor
    {
        front = -1;
        rear = -1;
    }
    // Exceptions
    class Full //exception class for full Queue
    {
    };
    class Empty //exception class for empty Queue
    {
    };
    //Member Functions
    void enqueue(Type var) //push numbers on Queue
    {
        if (isFull())     //condition to check if Queue is full or not.
            throw Full(); //throw Full exception
        else if (
            isEmpty() //condition to check if Queue is empty or not.
        )
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = var;
    }
    Type dequeue()
    {
        if (isEmpty())     //condition to check if Queue is empty or not.
            throw Empty(); //throw Empty exception
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        return arr[front++];
    }
    Type Front() //returns front element of Queue
    {
        if (isEmpty())     //condition to check if Queue is empty or not.
            throw Empty(); //throw Empty exception
        return arr[front];
    }
    bool isEmpty() //returns if the Queue is empty or not
    {
        return (front == -1 && rear == -1) ? true : false;
    }
    bool isFull() //returns if the Queue is empty or not
    {
        return (rear >= MAX - 1) ? true : false;
    }
    void display() //prints all the elements of Queue
    {
        if (isEmpty()) //condition to check if Queue is empty or not.
            throw Empty();

        cout << "\n--------------------Queue--------------------\n";
        for (int i = front; i <= rear; i++)
        {
            cout << "\t" << arr[i];
        }
        cout << "\n--------------------End--------------------\n";
    }
};
int main()
{
    Queue<int> q;
    try
    {
        if (q.isEmpty())
        {
            cout << "\n Queue is Empty" << endl;
        }
        q.enqueue(2);
        cout << "\n Front Element:" << q.Front() << endl;
        q.display();
        q.enqueue(3);
        cout << "\n Front Element:" << q.Front() << endl;
        q.display();
        q.enqueue(4);
        cout << "\n Front Element:" << q.Front() << endl;
        q.display();
        cout << "\n Dequeued Element:" << q.dequeue();
        q.display();
        cout << "\n Front Element:" << q.Front() << endl;
    }
    catch (Queue<int>::Full)
    {
        cout << "\nException: Queue Full/Overflow" << endl;
    }
    catch (Queue<int>::Empty)
    {
        cout << "\nException: Queue Empty/Underflow" << endl;
    }

    return 0;
}
