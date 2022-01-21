/*#include <iostream>
using namespace std;
struct Node {
    int data;
    struct Node* next;
};
struct Node* top = NULL;
void push(int val) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = val;
    newnode->next = top;
    top = newnode;
}

void pop() {
    if (top == NULL)
        cout << "Stack Underflow" << endl;
    else {
        cout << "The popped element is " << top->data << endl;
        top = top->next;
    }
}

void display() {
    struct Node* ptr;
    if (top == NULL)
        cout << "stack is empty";
    else {
        ptr = top;
        cout << "Stack elements are: ";
        while (ptr != NULL) {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
    }
    cout << endl;
}
int main() {
    int ch, val;
    cout << "1) Push in stack" << endl;
    cout << "2) Pop from stack" << endl;
    cout << "3) Display stack" << endl;
    cout << "4) Exit" << endl;
    do {
        cout << "Enter choice: " << endl;
        cin >> ch;
        switch (ch) {
        case 1: {
            cout << "Enter value to be pushed:" << endl;
            cin >> val;
            push(val);
            break;
        }
        case 2: {
            pop();
            break;
        }
        case 3: {
            display();
            break;
        }
        case 4: {
            cout << "Exit";
            break;
        }
        default: {
            cout << "Invalid Choice" << endl;
        }
        }
    } while (ch != 4);
    return 0;
} ARRAY IMPLEMENTATION OF STACK */

/*#include<iostream>
#include<stack>
using namespace std;

void reverse(char *C, int n)
{
    stack<char> S;
    int i;

    // Push into a stack
    for (i = 0; i < n; i++)
        S.push(C[i]);

    // Pop from a stack   
    for (i = 0; i < n; i++)
    {
        C[i] = S.top();
        S.pop();
    }

}

int main()
{
    
    char C[100];
    cout << "\tEnter A String: \n\t";
    gets_s(C);

    reverse(C, strlen(C));

    cout << "\n\tAfter reversing a string: \n\t" << C;
    cout << endl << endl << endl;


    system("pause");
    return 0;
} REVERSE A STRING USING STACK */

/*#include<iostream>
using namespace std;

struct node {
    int data;
    struct node* next;
};

// To create a demo we have to construct a linked list and this 
// function is to push the elements to the list. 
void push(struct node** head_ref, int data) {
    struct node* node;
    node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->next = (*head_ref);
    (*head_ref) = node;
}

// Function to reverse the list
void reverse(struct node** head_ref) {
    struct node* temp = NULL;
    struct node* prev = NULL;
    struct node* current = (*head_ref);
    while (current != NULL) {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    (*head_ref) = prev;
}

// To check our program 
void printnodes(struct node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

// Driver function
int main() {
    struct node* head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);
    push(&head, 6);
    push(&head, 7);
    push(&head, 8);
    push(&head, 9);
    push(&head, 10);
    cout << "Linked List Before Reversing" << endl;
    printnodes(head);
    reverse(&head);
    cout << endl;
    cout << "Linked List After Reversing" << endl;
    printnodes(head);
    return 0;
} REVERSE A LINKED LIST USING ITERATION*/

/*#include<iostream>
using namespace std;


struct Node {
    int data;
    struct Node* next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

struct LinkedList {
    Node* head;
    LinkedList()
    {
        head = NULL;
    }

    Node* reverse(Node* head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        // Recursive call
        Node* rest = reverse(head->next);
        head->next->next = head;

        head->next = NULL;

        return rest;
    }

    void print()
    {
        struct Node* temp = head;
        while (temp != NULL) {
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
    ll.push(320);
    ll.push(34);
    ll.push(315);
    ll.push(385);

    cout << "Linked List Before Reversing\n";
    ll.print();

    ll.head = ll.reverse(ll.head);

    cout << "\nLinked List After Reversing \n";
    ll.print();
    return 0;
} REVERSE LINKED LIST USING RECURSION */

/*#include <stack>
#include<iostream>
using namespace std;

class BalancedParenthesisChecker {
public:
    bool isParenthesisBalanced(char s[]) {

        //Char STL stack
        stack<char> Stack;
        int i = 0;

        // Traverse the given string expression
        //to check matching brackets 

        while (s[i])
        {
            //If the s[i] is a opening bracket then
            //push it to Stack

            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                Stack.push(s[i]);
            }
            // If s[i] is a opening bracket then
            //get top character from stack and match it
            //to the current character if match
            //found then pop it from Stack else
            //return false

            if (s[i] == ')' || s[i] == '}' || s[i] == ']')
            {
                if (Stack.empty() || !isEqual(Stack.top(), s[i]))
                {
                    return false;
                }
                else
                {
                    //Corresponding brackets matched
                    //pop it from stack
                    Stack.pop();
                }
            }
            i++;
        }


        //If Stack is empty then parenthesis
        //are balanced or else not balanced
        

        return Stack.empty();
    }

private:
    bool isEqual(char c1, char c2) {

        if (c1 == '(' && c2 == ')')
            return true;
        else if (c1 == '{' && c2 == '}')
            return true;
        else if (c1 == '[' && c2 == ']')
            return true;
        else
            return false;
    }
};


// Test program 

int main()
{
    int ch; 
    int val;
    char str[50];
    BalancedParenthesisChecker cheker;
    cout << "PRESS 1 TO BEGIN THE PROGRAM: ";
    cout << "PRESS 2 TO EXIT THE PROGRAM: ";
    cin >> ch;
    do {
        switch (ch) {
        case 1: {

            cout << "Enter parenthesis expression:" << endl;
            cin.getline(str, 50);

            bool isBalanced = cheker.isParenthesisBalanced(str);

            if (isBalanced) {
                cout << "Balanced" << endl;
            }
            else {
                cout << "Not Balanced" << endl;
            }
            break;
        }
        case 2: {
            exit(0);
        }
        }
    } while (ch != 2);
    return 0;
} CHECK IF PARENTHESIS IS BALANCED OR NOT */

/*#include<iostream>
#include <string>

using namespace std;
using std::string;

class stack {
public:
    int top;
    char* astack;
    int size;
    stack(int s) {
        size = s;
        top = -1;
        astack = new char[size];
    }
    void Push(char element);
    char Pop();
    bool isEmpty();
    bool isFull();
    char Peek();
    void clear();
    void print(stack* ptr);
};

char stack::Peek() {
    if (isEmpty()) {
        return 0;
    }
    return astack[top];
}

void stack::clear() {
    top = -1;
    delete astack;
    astack = new char(size);
};

void stack::Push(char element) {
    if (isFull()) {
        cout << "The stack is already Full" << endl;
        return;
    }
    else
        astack[++top] = element;
    return;
}

char stack::Pop() {
    if (isEmpty()) {
        cout << "The Array is already empty" << endl;
    }
    else {
        return astack[--top];
    }
}

void stack::print(stack* ptr) {
    for (int i = 0; i < ptr->top; i++) {
        cout << ptr->astack[i];
    }
}

bool stack::isEmpty() {
    if (top == -1) {
        return 1;
    }
    return 0;
}

bool stack::isFull() {
    if (top == size - 1) {
        return 1;
    }
    return 0;
}

int precedence(char element) {
    int weight = -1;
    switch (element) {
    case '+':
    case '-':
        weight = 1;
    case '*':
    case '/':
        weight = 2;
    case '$':
        weight = 3;
    }
    return weight;
}

bool IsOperator(char C) {
    if (C == '+' || C == '-' || C == '*' || C == '/' || C == '$')
        return true;
    return false;
}

bool IsOperand(char C) {
    if (C >= '0' && C <= '9') return true;
    if (C >= 'a' && C <= 'z') return true;
    if (C >= 'A' && C <= 'Z') return true;
    return false;
}

int main() {
    string infix;
    getline(cin, infix);

    int j = 1;

    string post = "";

    stack* postfix = new stack(50);
    for (int i = 0; i != infix.size(); i++) {
        char element = infix[i];
        if (IsOperand(element)) {
            post += element;
        }
        if (IsOperator(element)) {
            if (precedence(element) > precedence(postfix->Peek())) {
                postfix->Push(element);
            }
            else {
                while (precedence(element) <= precedence(postfix->Peek())) {
                    if (precedence(element) < precedence(postfix->Peek())) {
                        post += postfix->Pop();
                    }
                    if (precedence(element) == precedence(postfix->Peek())) {
                        cout << postfix->Peek() << endl;
                        post += postfix->Pop();
                    }
                }
            }
        }
    }

    while (!postfix->isEmpty()) {
        post += postfix->Pop();
    }

    cout << "Postfix expression is : " << post;

    cout << endl;
    system("pause");
    return 0;
} INFIX TO POSTFIX */
