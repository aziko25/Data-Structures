/*#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head = NULL;
    }

    void push_front(int newElement) {
        Node* newNode = new Node();
        newNode->data = newElement;
        newNode->next = head;
        head = newNode;
    }

    void PrintList() {
        Node* temp = head;
        if (temp != NULL) {
            cout << "The list contains: ";
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        else {
            cout << "The list is empty.\n";
        }
    }
};

int main() {
    LinkedList MyList;

    MyList.push_front(10);
    MyList.push_front(20);
    MyList.push_front(30);
    MyList.push_front(5);
    MyList.PrintList();

    system("pause");
    return 0;
}INSERTING AT THE BEGINNING */

/*#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head = NULL;
    }

    //Add new element at the end of the list
    void push_back(int newElement) {
        Node* newNode = new Node();
        newNode->data = newElement;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    //Inserts a new element at the given position
    void push_at(int newElement, int position) {
        Node* newNode = new Node();
        newNode->data = newElement;
        newNode->next = NULL;

        if (position < 1) {
            cout << "\nposition should be >= 1.";
        }
        else if (position == 1) {
            newNode->next = head;
            head = newNode;
        }
        else {

            Node* temp = head;
            for (int i = 1; i < position - 1; i++) {
                if (temp != NULL) {
                    temp = temp->next;
                }
            }

            if (temp != NULL) {
                newNode->next = temp->next;
                temp->next = newNode;
            }
            else {
                cout << "\nThe previous node is null.";
            }
        }
    }

    //display the content of the list
    void PrintList() {
        Node* temp = head;
        if (temp != NULL) {
            cout << "The list contains: ";
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        else {
            cout << "The list is empty.\n";
        }
    }
};

int main() {
    LinkedList MyList;

    //Add three elements at the end of the list.
    MyList.push_back(10);
    MyList.push_back(20);
    MyList.push_back(30);
    MyList.PrintList();

    //Insert an element at position 4
    MyList.push_at(50, 4);
    MyList.PrintList();

    //Insert an element at position 3
    MyList.push_at(300, 3);
    MyList.PrintList();

    //Insert an element at position 2
    MyList.push_at(100, 2);
    MyList.PrintList();

    //Insert an element at position 1
    MyList.push_at(200, 1);
    MyList.PrintList();

    return 0;
}INSERT A NODE AT NTH POSITION*/

/*#include <iostream>
using namespace std;
struct Node {
    int data;
    struct Node* next;
};
void insertNode(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
void deleteNode(struct Node** head_ref, int position) {
    if (*head_ref == NULL) {
        return;
    }
    struct Node* temp = *head_ref;
    if (position == 1) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    for (int i = 2; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        return;
    }
    struct Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}
void printLinkedList(struct Node* node) {
    while (node != NULL) {
        cout << node->data << "-";
        node = node->next;
    }
}
int main() {
    struct Node* head = NULL;
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);
    insertNode(&head, 5);
    cout << "Linked list before deletion:" << endl;
    printLinkedList(head);
    deleteNode(&head, 6);
    cout << "\nLinked list after deletion:" << endl;
    printLinkedList(head);
    return 0;
}DELETE A NODE FROM NTH POSITION*/

/*#include<iostream> 
using namespace std;

// Link list node 
struct Node
{
    int data;
    struct Node* next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

struct LinkedList
{
    Node* head;
    LinkedList()
    {
        head = NULL;
    }


    // Function to reverse the linked list 
    void reverse()
    {
        // Initialize current, previous and 
        // next pointers 
        Node* current = head;
        Node* prev = NULL, * next = NULL;


        while (current != NULL)
        {
            // Store next 
            next = current->next;

            // Reverse current node's pointer 
            current->next = prev;

            // Move pointers one position ahead. 
            prev = current;
            current = next;
        }
        head = prev;
    }

    // Function to print linked list 
    void print()
    {
        struct Node* temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void push(int data)
    {
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }
};

int main()
{
    LinkedList ll;
    ll.push(1);
    ll.push(2);
    ll.push(3);
    ll.push(4);
    ll.push(5);

    cout << "Given linked list: "; 
        ll.print();

    ll.reverse();

    cout << "\nReversed Linked list: "; 
        ll.print();

        cout << endl << endl;
        system("pause");
        return 0;
}REVERSE A LINKED LIST */

/*#include <iostream>
using namespace std;
struct Node {
    int data;
    struct Node* next;
    Node(int data) {
        this->data = data;
        next = NULL;
    }
};
struct LinkedList {
    Node* head;
    LinkedList() { head = NULL; }
    // Function to print linked list
    void rreverse(Node* curr, Node* prev) {
        if (curr == NULL) {
            // prev -> next = curr;
            head = prev;
            return;
        }
        rreverse(curr->next, curr);
        curr->next = prev;
        prev->next = NULL;
    }

    void reverse() {
        auto curr = head; // current pointer
        Node* prev = NULL; // previous pointer
        rreverse(curr->next, curr);
    }
    void print() {
        struct Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    void push(int data) {
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }
};
int main() {
    LinkedList list;
    list.push(20);
    list.push(1);
    list.push(15);
    list.push(85);
    list.print();
    list.reverse();
    cout << "\n";
    list.print();

}REVERSE A LINKED LIST USING RECURSION*/

/*#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head = NULL;
    }

    //Add new element at the end of the list
    void push_back(int newElement) {
        Node* newNode = new Node();
        newNode->data = newElement;
        newNode->next = NULL;
        newNode->prev = NULL;
        if (head == NULL) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    //Inserts a new element at the given position 
    void push_at(int newElement, int position) {
        Node* newNode = new Node();
        newNode->data = newElement;
        newNode->next = NULL;
        newNode->prev = NULL;
        if (position < 1) {
            cout << "\nposition should be >= 1.";
        }
        else if (position == 1) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        else {
            Node* temp = head;
            for (int i = 1; i < position - 1; i++) {
                if (temp != NULL) {
                    temp = temp->next;
                }
            }
            if (temp != NULL) {
                newNode->next = temp->next;
                newNode->prev = temp;
                temp->next = newNode;
                if (newNode->next != NULL)
                    newNode->next->prev = newNode;
            }
            else {
                cout << "\nThe previous node is null.";
            }
        }
    }

    //reverse the list
    void reverseList() {
        if (head != NULL) {
            Node* prevNode = head;
            Node* tempNode = head;
            Node* curNode = head->next;

            prevNode->next = NULL;
            prevNode->prev = NULL;

            while (curNode != NULL) {
                tempNode = curNode->next;
                curNode->next = prevNode;
                prevNode->prev = curNode;
                prevNode = curNode;
                curNode = tempNode;
            }

            head = prevNode;
        }
    }

    //delete all nodes
    void deleteAllNodes() {
        Node* temp = new Node();
        while (head != NULL) {
            temp = head;
            head = head->next;
            free(temp);
        }
        cout << "All nodes are deleted successfully.\n";
    }

    //display the content of the list
    void PrintList() {
        Node* temp = head;
        if (temp != NULL) {
            cout << "The list contains: ";
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        else {
            cout << "The list is empty.\n";
        }
    }
};

// test the code 
int main() {
    LinkedList MyList;

    //Add three elements in the list.
    MyList.push_back(10);
    MyList.push_back(20);
    MyList.push_back(30);
    MyList.PrintList();

    //Insert an element at position 3
    MyList.push_at(100, 3);
    MyList.PrintList();

    //Insert an element at position 2
    MyList.push_at(100, 2);
    MyList.PrintList();

    //Insert an element at position 1
    MyList.push_at(200, 1);
    MyList.PrintList();

    //Reversing the list.
    MyList.reverseList();
    MyList.PrintList();

    //delete all nodes of the list
    MyList.deleteAllNodes();
    MyList.PrintList();

    cout << "\n\n\n\n";
    system("pause");
    return 0;
} OPERATIONS WITH DOUBLY LINKED LIST*/