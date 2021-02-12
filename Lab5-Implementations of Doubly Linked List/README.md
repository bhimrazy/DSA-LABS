# DoublyLinked List Implementation in c++

Dynamic List

- Insertion ->Start/AnyPosition/End
- Deletion ->Start/AnyPosition/End

## Operations

1.  InsertionAtBeginning(x) :
2.  InsertionAtEnd(x) :
3.  InsertionBefore(x,y) :
4.  InsertionAfter(x,y) :
5.  IsEmpty() :
6.  InLinkedList() :
7.  HeadIsAt() :
8.  DeletionAtBeginning(x) :
9.  DeletionAtEnd(x) :
10. DeletionBefore(x,y) :
11. DeletionAfter(x,y) :

## Time Complexity of DoublyLinked List

 <p>
| Operation  	                |Time Complexity: Worst Case   	|Time Complexity: Average Case   	|	
|---	                        |---	                        |---	                            |   		
| Insert at beginning or end  	|   	    O(1)                |   	        O(1)                |
| Delete at beginning or end    |   	    O(1)                |               O(1) 	            |      	   	
|Search   	                    |   	    O(n)                |   	        O(n)                |
|Access   	                    |           O(n)                |               O(n)                |

</p>

## C++ Implementation of DoublyLinked List

```c++
#include <iostream>
using namespace std;

template <class Type> //structure template
/* Node of a doubly linked list */
struct Node
{
    int data;
    struct Node *next; // Pointer to next node
    struct Node *prev; // Pointer to previous node
};
template <class Type> //class template
class DoublyLinkedList
{
private:
    Node<Type> *Head, *newNode; //pointer to head
public:
    DoublyLinkedList() //constructor
    {
        Head = NULL;
    }
    class Empty //exception class for empty Linked list
    {
    };
    class NotExist //exception class for data not existing in Linked list
    {
    };
    void insertAtBeginning(Type item) //insert data at beginning
    {
        newNode = new Node<Type>; //create new node
        newNode->data = item;     //set data to item
        if (isEmpty())            //check for head is null
        {
            newNode->next = NULL; //it points to null
            newNode->prev = NULL;
        }
        else
        {
            newNode->next = Head; //it points to head
            Head->prev = newNode;
            newNode->prev = NULL;
        }

        Head = newNode; //head points to new node
    }
    void insertBefore(Type before, Type item) //insert data before
    {
        if (!inDoublyLinkedList(before)) //check if data exist in list or not
            throw NotExist();
        newNode = new Node<Type>; //create new node
        newNode->data = item;     //set data to item
        Node<Type> *temp = Head;
        Node<Type> *prev = temp;
        while (temp->data != before)
        {
            prev = temp;
            temp = temp->next;
        }
        newNode->next = temp;
        temp->prev = newNode;
        if (Head->data != before)
        {
            prev->next = newNode;
            newNode->prev = prev;
        }
        else
        {
            newNode->prev = NULL;
            Head = newNode;
        }
    }
    void insertAfter(Type after, Type item) //insert data after
    {
        if (!inDoublyLinkedList(after)) //check if data exist in list or not
            throw NotExist();
        newNode = new Node<Type>; //create new node
        newNode->data = item;     //set data to item
        Node<Type> *temp = Head;
        while (temp->data != after)
        {
            temp = temp->next;
        }
        newNode->prev = temp;
        newNode->next = temp->next;
        temp->next = newNode;
        if (newNode->next != NULL)
        {
            newNode->next->prev = newNode;
        }
    }
    void insertAtEnd(Type item) //insert data at end
    {
        newNode = new Node<Type>; //create new node
        newNode->data = item;     //set data to item
        newNode->next = NULL;
        if (isEmpty()) //check for head is null
        {
            Head = newNode;
            newNode->prev = NULL;
        }
        else
        {
            Node<Type> *temp = Head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            newNode->prev = temp;
            temp->next = newNode;
        }
    }
    void display() //display all the items from start
    {
        if (isEmpty())     //check if linked list is empty
            throw Empty(); //throw exception
        else
        {
            Node<Type> *temp = Head;
            cout << "\n---------------DoublyLinked List---------------\n";
            while (temp != NULL)
            {
                cout << temp->data << "\t";
                temp = temp->next;
            }
            cout << "\n-----------------------END---------------------\n";
        }
    }
    void displayFromEnd() //display all the items from end
    {
        if (isEmpty())     //check if linked list is empty
            throw Empty(); //throw exception
        else
        {
            Node<Type> *temp = Head;
            Node<Type> *prev1 = temp;
            cout << "\n---------------DoublyLinked List From End---------------\n";
            while (temp != NULL)
            {
                prev1 = temp;
                temp = temp->next;
            }
            while (prev1 != NULL)
            {
                cout << prev1->data << "\t";
                prev1 = prev1->prev;
            }
            cout << "\n---------------------------END---------------------------\n";
        }
    }
    void removeFromBeginning()
    {
        if (isEmpty())     //check if linked list is empty
            throw Empty(); //throw exception

        else
        {
            Node<Type> *temp = Head;
            Head = Head->next;
            Head->prev = NULL;
            delete temp;
        }
    }
    void removeFromEnd()
    {
        if (isEmpty())     //check if linked list is empty
            throw Empty(); //throw exception

        else
        {
            Node<Type> *temp = Head;
            Node<Type> *prev = temp;
            while (temp->next != NULL)
            {
                prev = temp;
                temp = temp->next;
            }
            delete temp;
            prev->next = NULL;
        }
    }
    void removeAfter(Type after)
    {
        if (!inDoublyLinkedList(after)) //check if data exist in list or not
            throw NotExist();
        Node<Type> *temp = Head;
        Node<Type> *temp1 = temp;
        Node<Type> *temp2 = temp;
        while (temp->data != after)
        {
            temp = temp->next;
        }
        if (temp->next == NULL)
            throw NotExist();
        temp1 = temp->next;
        if (temp1->next != NULL)
        {
            temp2 = temp1->next;
            temp2->prev = temp;
        }
        temp->next = temp2;

        delete temp1;
    }
    bool isEmpty()
    {
        return (Head == NULL) ? true : false;
    }
    bool inDoublyLinkedList(Type item)
    {
        if (isEmpty())     //check if linked list is empty
            throw Empty(); //throw exception
        Node<Type> *temp = Head;
        while (temp != NULL)
        {
            if (temp->data == item)
                return true;
            temp = temp->next;
        }
        return false;
    }
    Type headIsAt()
    {
        if (isEmpty())     //check if linked list is empty
            throw Empty(); //throw exception

        return Head->data;
    }
};

int main()
{
    DoublyLinkedList<int> list;
    try
    {
        if (list.isEmpty())
        {
            cout << "\nDoublyLinkedList is Empty\n";
        }
        list.insertAtBeginning(2);
        cout << "\nHead is at: " << list.headIsAt() << endl;
        list.display();
        list.insertBefore(2, 0);
        cout << "\nHead is at: " << list.headIsAt() << endl;
        list.display();
        list.insertAtBeginning(5);
        cout << "\nHead is at: " << list.headIsAt() << endl;
        list.display();
        list.insertAtBeginning(9);
        cout << "\nHead is at: " << list.headIsAt() << endl;
        list.display();
        list.insertAtEnd(8);
        cout << "\nHead is at: " << list.headIsAt() << endl;
        list.display();
        list.insertAtEnd(4);
        cout << "\nHead is at: " << list.headIsAt() << endl;
        list.display();
        list.insertAtEnd(6);
        cout << "\nHead is at: " << list.headIsAt() << endl;
        list.display();
        list.insertBefore(8, 0);
        cout << "\nHead is at: " << list.headIsAt() << endl;
        list.display();
        list.insertAfter(8, 0);
        cout << "\nHead is at: " << list.headIsAt() << endl;
        list.display();
        list.removeFromBeginning();
        cout << "\nHead is at: " << list.headIsAt() << endl;
        list.display();
        list.removeFromBeginning();
        cout << "\nHead is at: " << list.headIsAt() << endl;
        list.display();
        list.displayFromEnd();
        list.removeAfter(8);
        cout << "\nHead is at: " << list.headIsAt() << endl;
        list.display();
        list.removeAfter(0);
        cout << "\nHead is at: " << list.headIsAt() << endl;
        list.display();
        // list.removeAfter(4);
        cout << "\nHead is at: " << list.headIsAt() << endl;
        list.display();
        list.removeFromEnd();
        cout << "\nHead is at: " << list.headIsAt() << endl;
        list.display();
        list.displayFromEnd();
        list.removeAfter(9);
        cout << "\nHead is at: " << list.headIsAt() << endl;
        list.display();
    }
    catch (DoublyLinkedList<int>::Empty)
    {
        cout << "\nException: DoublyLinkedList is Empty" << endl;
    }
    catch (DoublyLinkedList<int>::NotExist)
    {
        cout << "\nException: Data doesn't exist in this Linked List" << endl;
    }
    return 0;
}


```

## Output of above program

```
DoublyLinkedList is Empty

Head is at: 2

---------------DoublyLinked List---------------
2
-----------------------END---------------------

Head is at: 0

---------------DoublyLinked List---------------
0	2
-----------------------END---------------------

Head is at: 5

---------------DoublyLinked List---------------
5	0	2
-----------------------END---------------------

Head is at: 9

---------------DoublyLinked List---------------
9	5	0	2
-----------------------END---------------------

Head is at: 9

---------------DoublyLinked List---------------
9	5	0	2	8
-----------------------END---------------------

Head is at: 9

---------------DoublyLinked List---------------
9	5	0	2	8	4
-----------------------END---------------------

Head is at: 9

---------------DoublyLinked List---------------
9	5	0	2	8	4	6
-----------------------END---------------------

Head is at: 9

---------------DoublyLinked List---------------
9	5	0	2	0	8	4	6
-----------------------END---------------------

Head is at: 9

---------------DoublyLinked List---------------
9	5	0	2	0	8	0	4	6
-----------------------END---------------------

Head is at: 5

---------------DoublyLinked List---------------
5	0	2	0	8	0	4	6
-----------------------END---------------------

Head is at: 0

---------------DoublyLinked List---------------
0	2	0	8	0	4	6
-----------------------END---------------------

---------------DoublyLinked List From End---------------
6	4	0	8	0	2	0
---------------------------END---------------------------

Head is at: 0

---------------DoublyLinked List---------------
0	2	0	8	4	6
-----------------------END---------------------

Head is at: 0

---------------DoublyLinked List---------------
0	0	8	4	6
-----------------------END---------------------

Head is at: 0

---------------DoublyLinked List---------------
0	0	8	4	6
-----------------------END---------------------

Head is at: 0

---------------DoublyLinked List---------------
0	0	8	4
-----------------------END---------------------

---------------DoublyLinked List From End---------------
4	8	0	0
---------------------------END---------------------------

Exception: Data doesn't exist in this Linked List

```

## Notes
