# CircularQueue Implementation in c++

First-In-First-Out

- Insertion ->Rear/Tail
- Deletion ->Front/Head

## Operations

1. Enqueue(x) : Addition of an element to the queue
2. Dequeue() : Removal of an element from the queue
3. Front() : Get the front element from the queue
4. Display() : Print all element of the queue
5. IsEmpty() : Checks if the queue is empty or not.
6. IsFull() : Checks if the queue is full or not.

## Time Complexity of CircularQueue

> <p>

    Constant Time - O(1)

</p>

## C++ Implementation of CircularQueue

```c++
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
        if ((rear + 1) % MAX == front) //condition to check if Queue is full or not.
            throw Full();              //throw Full exception
        else if (
            isEmpty() //condition to check if Queue is empty or not.
        )
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % MAX;
        }
        arr[rear] = var;
    }
    Type dequeue()
    {
        if (isEmpty())     //condition to check if Queue is empty or not.
            throw Empty(); //throw Empty exception
        Type data = arr[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
            cout << "\nQueue is  empty\n";
            return 0;
        }
        else
            front = (front + 1) % MAX;
        return data;
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
        if (rear >= front)
        {
            for (int i = front; i <= rear; i++)
            {
                cout << "\t" << arr[i];
            }
        }
        else
        {
            for (int i = front; i <= MAX; i++)
            {
                cout << "\t" << arr[i];
            }

            for (int i = 0; i <= rear; i++)
            {
                cout << "\t" << arr[i];
            }
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


```

## Output of above program

```
Queue is Empty

 Front Element:2

--------------------Queue--------------------
	2
--------------------End--------------------

 Front Element:2

--------------------Queue--------------------
	2	3
--------------------End--------------------

 Front Element:2

--------------------Queue--------------------
	2	3	4
--------------------End--------------------

 Dequeued Element:2
--------------------Queue--------------------
	3	4
--------------------End--------------------

 Front Element:3
```

## Notes

> <p>

> - Incase of **Overflow** -> Create a larger array (double the size of previous) and then copy all the elements.

</p>
