#include <iostream>
using namespace std;

template <class Type> //structure template
struct Node           //Linked list Node
{
    Type data;  //data item
    Node *next; //pointer to next link
};
template <class Type> //class template
class LinkedList
{
private:
    Node<Type> *Head, *newNode; //pointer to head
public:
    LinkedList() //constructor
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
        }
        else
        {
            newNode->next = Head; //it points to head
        }

        Head = newNode; //head points to new node
    }
    void insertBefore(Type before, Type item) //insert data at beginning
    {
        if (!inLinkedList(before)) //check if data exist in list or not
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
        if (Head->data != before)
            prev->next = newNode;
        else
        {
            Head = newNode;
        }
    }
    void insertAfter(Type after, Type item) //insert data after
    {
        if (!inLinkedList(after)) //check if data exist in list or not
            throw NotExist();
        newNode = new Node<Type>; //create new node
        newNode->data = item;     //set data to item
        Node<Type> *temp = Head;
        while (temp->data != after)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    void insertAtEnd(Type item) //insert data at end
    {
        newNode = new Node<Type>; //create new node
        newNode->data = item;     //set data to item
        newNode->next = NULL;
        if (isEmpty()) //check for head is null
        {
            Head = newNode;
        }
        else
        {
            Node<Type> *temp = Head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
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
            cout << "\n---------------Linked List---------------\n";
            while (temp != NULL)
            {
                cout << temp->data << "\t";
                temp = temp->next;
            }
            cout << "\n--------------------END--------------------\n";
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
        if (!inLinkedList(after)) //check if data exist in list or not
            throw NotExist();
        Node<Type> *temp = Head;
        Node<Type> *temp1 = temp;
        while (temp->data != after)
        {
            temp = temp->next;
        }
        if (temp->next == NULL)
            throw NotExist();
        temp1 = temp->next;
        temp->next = temp1->next;
        delete temp1;
    }
    bool isEmpty()
    {
        return (Head == NULL) ? true : false;
    }
    bool inLinkedList(Type item)
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
    LinkedList<int> list;
    try
    {
        if (list.isEmpty())
        {
            cout << "\nLinkedList is Empty\n";
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
        list.removeAfter(8);
        cout << "\nHead is at: " << list.headIsAt() << endl;
        list.display();
        list.removeAfter(0);
        cout << "\nHead is at: " << list.headIsAt() << endl;
        list.display();
        list.removeAfter(4);
        cout << "\nHead is at: " << list.headIsAt() << endl;
        list.display();
        list.removeFromEnd();
        cout << "\nHead is at: " << list.headIsAt() << endl;
        list.display();
        list.removeAfter(9);
        cout << "\nHead is at: " << list.headIsAt() << endl;
        list.display();
    }
    catch (LinkedList<int>::Empty)
    {
        cout << "\nException: LinkedList is Empty" << endl;
    }
    catch (LinkedList<int>::NotExist)
    {
        cout << "\nException: Data doesn't exist in this Linked List" << endl;
    }
    return 0;
}