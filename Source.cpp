/*#include <iostream>
#include <cstdlib>
using namespace std;
// Binary Search Tree Node Declaration
struct node
{
    int info;
    struct node* left;
    struct node* right;
}*root;
// Class Declaration for Binary Search Tree
class BST
{
public:
    void find(int, node**, node**);
    void insert(node*, node*);
    void del(int);
    void case_a(node*, node*);
    void case_b(node*, node*);
    void case_c(node*, node*);
    void preorder(node*);
    void inorder(node*);
    void postorder(node*);
    void display(node*, int);
    BST()
    {
        root = NULL;
    }
};
// Main Contains Menu
int main()
{
    int choice, num;
    BST bst;
    node* temp;
    while (1)
    {
        // Main menu for Binary Search Tree Operations
        cout << "-----------------" << endl;
        cout << "Operations on BST" << endl;
        cout << "-----------------" << endl;
        cout << "1.Insert Element " << endl;
        cout << "2.Delete Element " << endl;
        cout << "3.Inorder Traversal" << endl;
        cout << "4.Preorder Traversal" << endl;
        cout << "5.Postorder Traversal" << endl;
        cout << "6.Display" << endl;
        cout << "7.Quit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            system("CLS");
            temp = new node;
            cout << "Enter the number to be inserted : ";
            cin >> temp->info;
            bst.insert(root, temp);
            break;
        case 2:
            system("CLS");
            if (root == NULL)
            {
                cout << "Tree is empty, nothing to delete" << endl;
                continue;
            }
            cout << "Enter the number to be deleted : ";
            cin >> num;
            bst.del(num);
            break;
        case 3:
            cout << "Inorder Traversal of BST:" << endl;
            bst.inorder(root);
            cout << endl;
            break;
        case 4:
            cout << "Preorder Traversal of BST:" << endl;
            bst.preorder(root);
            cout << endl;
            break;
        case 5:
            cout << "Postorder Traversal of BST:" << endl;
            bst.postorder(root);
            cout << endl;
            break;
        case 6:
            system("CLS");
            cout << "Display BST:" << endl;
            bst.display(root, 1);
            cout << endl;
            break;
        case 7:
            exit(1);
        default:
            cout << "Wrong choice" << endl;
        }
    }
}
// Find Element in the Binary Search Tree
void BST::find(int item, node** par, node** loc)
{
    node* ptr, * ptrsave;
    if (root == NULL)
    {
        *loc = NULL;
        *par = NULL;
        return;
    }
    if (item == root->info)
    {
        *loc = root;
        *par = NULL;
        return;
    }
    if (item < root->info)
        ptr = root->left;
    else
        ptr = root->right;
    ptrsave = root;
    while (ptr != NULL)
    {
        if (item == ptr->info)
        {
            *loc = ptr;
            *par = ptrsave;
            return;
        }
        ptrsave = ptr;
        if (item < ptr->info)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }
    *loc = NULL;
    *par = ptrsave;
}
// Inserting Element into the Binary Search Tree
void BST::insert(node* tree, node* newnode)
{
    if (root == NULL)
    {
        root = new node;
        root->info = newnode->info;
        root->left = NULL;
        root->right = NULL;
        cout << "Root Node is Added" << endl;
        return;
    }
    if (tree->info == newnode->info)
    {
        cout << "Element already in the tree" << endl;
        return;
    }
    if (tree->info > newnode->info)
    {
        if (tree->left != NULL)
        {
            insert(tree->left, newnode);
        }
        else
        {
            tree->left = newnode;
            (tree->left)->left = NULL;
            (tree->left)->right = NULL;
            cout << "Node Added To Left" << endl;
            return;
        }
    }
    else
    {
        if (tree->right != NULL)
        {
            insert(tree->right, newnode);
        }
        else
        {
            tree->right = newnode;
            (tree->right)->left = NULL;
            (tree->right)->right = NULL;
            cout << "Node Added To Right" << endl;
            return;
        }
    }
}
// Delete Element from the Binary Search tree
void BST::del(int item)
{
    node* parent, * location;
    if (root == NULL)
    {
        cout << "Tree empty" << endl;
        return;
    }
    find(item, &parent, &location);
    if (location == NULL)
    {
        cout << "Item not present in tree" << endl;
        return;
    }
    if (location->left == NULL && location->right == NULL)
        case_a(parent, location);
    if (location->left != NULL && location->right == NULL)
        case_b(parent, location);
    if (location->left == NULL && location->right != NULL)
        case_b(parent, location);
    if (location->left != NULL && location->right != NULL)
        case_c(parent, location);
    free(location);
}
// * Case A
void BST::case_a(node* par, node* loc)
{
    if (par == NULL)
    {
        root = NULL;
    }
    else
    {
        if (loc == par->left)
            par->left = NULL;
        else
            par->right = NULL;
    }
}
// * Case B
void BST::case_b(node* par, node* loc)
{
    node* child;
    if (loc->left != NULL)
        child = loc->left;
    else
        child = loc->right;
    if (par == NULL)
    {
        root = child;
    }
    else
    {
        if (loc == par->left)
            par->left = child;
        else
            par->right = child;
    }
}
// * Case C
void BST::case_c(node* par, node* loc)
{
    node* ptr, * ptrsave, * suc, * parsuc;
    ptrsave = loc;
    ptr = loc->right;
    while (ptr->left != NULL)
    {
        ptrsave = ptr;
        ptr = ptr->left;
    }
    suc = ptr;
    parsuc = ptrsave;
    if (suc->left == NULL && suc->right == NULL)
        case_a(parsuc, suc);
    else
        case_b(parsuc, suc);
    if (par == NULL)
    {
        root = suc;
    }
    else
    {
        if (loc == par->left)
            par->left = suc;
        else
            par->right = suc;
    }
    suc->left = loc->left;
    suc->right = loc->right;
}
// Pre Order Traversal
void BST::preorder(node* ptr)
{
    if (root == NULL)
    {
        cout << "Tree is empty" << endl;
        return;
    }
    if (ptr != NULL)
    {
        cout << ptr->info << "  ";
        preorder(ptr->left);
        preorder(ptr->right);
    }
}
// In Order Traversal
void BST::inorder(node* ptr)
{
    if (root == NULL)
    {
        cout << "Tree is empty" << endl;
        return;
    }
    if (ptr != NULL)
    {
        inorder(ptr->left);
        cout << ptr->info << "  ";
        inorder(ptr->right);
    }
}
// Postorder Traversal
void BST::postorder(node* ptr)
{
    if (root == NULL)
    {
        cout << "Tree is empty" << endl;
        return;
    }
    if (ptr != NULL)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        cout << ptr->info << "  ";
    }
}
// Display Binary Search Tree Structure
void BST::display(node* ptr, int level)
{
    int i;
    if (ptr != NULL)
    {
        display(ptr->right, level + 1);
        cout << endl;
        if (ptr == root)
            cout << "Root->:  ";
        else
        {
            for (i = 0; i < level; i++)
                cout << "       ";
        }
        cout << ptr->info;
        display(ptr->left, level + 1);
    }
} //INSERT, DELETE, PREORDER, INORDER, POSTORDER BST */

/*#include <iostream>  
using namespace std;

struct node
{
    int key;
    struct node* left, * right;
};

// A utility function to create a new BST node 
struct node* newNode(int item)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// A utility function to insert a new node with given key in BST 
struct node* insert(struct node* node, int key)
{
    struct node* newNode(int);
    // If the tree is empty, return a new node 
    if (node == NULL) return newNode(key);

    // Otherwise, recur down the tree 
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    // return the (unchanged) node pointer 
    return node;
}
// Given a non-empty binary search tree,
//return the minimum data value found in that
//tree. Note that the entire tree does not need
//to be searched. 
int minValue(struct node* node)
{
    struct node* current = node;

    // loop down to find the leftmost leaf 
    while (current->left != NULL)
    {
        current = current->left;
    }
    return(current->key);
}
// Given a non-empty binary search tree,
//return the maximum data value found in that
//tree. Note that the entire tree does not need
//to be searched. 
int maxValue(struct node* node)
{
    struct node* current = node;

    // loop down to find the leftmost leaf 
    while (current->right != NULL)
    {
        current = current->right;
    }
    return(current->key);
}
// Driver Program to test above functions 
int main()
{
    int maxValue(struct node*);
    struct node* insert(struct node*, int);
    int minValue(struct node*);
    struct node* root = NULL;
    root = insert(root, 8);
    insert(root, 0);
    insert(root, 30);
    insert(root, 1);
    insert(root, 6);
    insert(root, 4);
    insert(root, 7);
    insert(root, 5);
    insert(root, 10);
    insert(root, 9);
    insert(root, 13);
    insert(root, 11);
    insert(root, 14);
    insert(root, 12);
    insert(root, 2);

    cout << "Minimum value in BST is " << minValue(root) << endl;
    cout << "\nMaximum value in BST is " << maxValue(root);
    cout << endl;
    return 0;
} //FIND MAX AND MIN ELEMENT IN BST */

/*#include <iostream>

using namespace std;

// structure of a binary tree 
struct node
{
    int data;    // to store the value of a node in tree
    node* left;   // pointer to the left child
    node* right;   // pointer to the right child
};

// function to find the maximum height of binary tree 
int FindHeight(node* node)
{
    if (node == NULL)  // when the subtree is empty
        return 0;
    else
    {
        int leftH, rightH;
        //find the height of left subtree 
        leftH = FindHeight(node->left);
        //find the height of right subtree 
        rightH = FindHeight(node->right);
        // return the maximum height 
        if (leftH > rightH)
            return(leftH + 1);
        else
            return(rightH + 1);
    }
}

// function to get new node for the tree 
node* getNode(int data)
{
    node* newNode = new node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return(newNode);
}
int main()
{
    // creating the binary tree 
    node* root = getNode(1);
    root->left = getNode(2);
    root->right = getNode(3);
    root->left->left = getNode(4);
    root->left->right = getNode(5);
    root->right->left = getNode(6);
    root->right->right = getNode(7);
    cout << "The Height of the binary tree is " << FindHeight(root);
    return 0;
} FIND HEIGHT OF A BST */

/*#include <iostream>
using namespace std;

// structure of a binary tree 
struct node
{
    int data;    // to store the value of a node in tree
    node* left;   // pointer to the left child
    node* right;   // pointer to the right child
};

// Finding the depth of tree 
int FindDepth(node* node)
{
    if (node == NULL)  // when the subtree is empty
        return 0;
    else
    {
        int leftD, rightD;
        //find the depth of left child 
        leftD = FindDepth(node->left);
        //find the depth of right child 
        rightD = FindDepth(node->right);
        // return the maximum depth 
        if (leftD > rightD)
            return(leftD + 1);
        else
            return(rightD + 1);
    }
}

// function to get new node for the tree 
node* getNode(int data)
{
    node* newNode = new node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return(newNode);
}
int main()
{
    // creating the binary tree 
    node* root = getNode(1);
    root->left = getNode(2);
    root->right = getNode(3);
    root->left->left = getNode(4);
    root->left->right = getNode(5);
    root->right->left = getNode(6);
    root->right->right = getNode(7);
    root->left->right->right = getNode(10);
    cout << "The Depth of the binary tree is " << FindDepth(root) - 1;
    cout << endl << endl << endl;
    system("pause>0");
    return 0;
} //FIND DEPTH OF A BST */

/*#include<iostream>
#include<queue>
using namespace std;
class node {
public:
    int h_left, h_right, bf, value;
    node* left, * right;
};
class tree {
private:
    node* get_node(int key);
public:
    node* root;
    tree() {
        root = NULL; //set root as NULL at the beginning
    }
    void levelorder_traversal(node* r);
    node* insert_node(node* root, int key);
};
node* tree::get_node(int key) {
    node* new_node;
    new_node = new node; //create a new node dynamically
    new_node->h_left = 0; new_node->h_right = 0;
    new_node->bf = 0;
    new_node->value = key; //store the value from given key
    new_node->left = NULL; new_node->right = NULL;
    return new_node;
}
void tree::levelorder_traversal(node* root) {
    queue <node*> que;
    node* item;
    que.push(root); //insert the root at first
    while (!que.empty()) {
        item = que.front(); //get the element from the front end
        cout << item->value << " ";
        if (item->left != NULL) //When left child is present, insert into queue
            que.push(item->left);                                                                     
        if (item->right != NULL) //When right child is present, insert into queue
            que.push(item->right);
        que.pop(); //remove the item from queue
    }
}
node* tree::insert_node(node* root, int key) {
    if (root == NULL) {
        return (get_node(key)); //when tree is empty, create a node as root
    }
    if (key < root->value) { //when key is smaller than root value, go to the left
        root->left = insert_node(root->left, key);
    }
    else if (key > root->value) { //when key is greater than root value, go to the right
        root->right = insert_node(root->right, key);
    }
    return root; //when key is already present, do not insert it again
}
int main() {
    node* root;
    tree my_tree;
    //Insert some keys into the tree.
    my_tree.root = my_tree.insert_node(my_tree.root, 10);
    my_tree.root = my_tree.insert_node(my_tree.root, 5);
    my_tree.root = my_tree.insert_node(my_tree.root, 16);
    my_tree.root = my_tree.insert_node(my_tree.root, 20);
    my_tree.root = my_tree.insert_node(my_tree.root, 15);
    my_tree.root = my_tree.insert_node(my_tree.root, 8);
    my_tree.root = my_tree.insert_node(my_tree.root, 23);
    cout << "Level-Order Traversal: ";
    my_tree.levelorder_traversal(my_tree.root);
    cout << endl << endl;

    system("pause>0");
    return 0;
} BINARY TREE: LEVEL-ORDER TRAVERSAL */


/*#include<iostream> 
using namespace std;

// A binary tree node has data,
//pointer to left child and
//a pointer to right child 
class node
{
public:
    int data;
    node* left;
    node* right;

    // Constructor that allocates
    //a new node with the given data
    //and NULL left and right pointers. 
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

int isBSTUtil(node* node, int min, int max);

// Returns true if the given
//tree is a binary search tree
//(efficient version). 
int isBST(node* node)
{
    return(isBSTUtil(node, INT_MIN, INT_MAX));
}

// Returns true if the given
//tree is a BST and its values
//are >= min and <= max. 
int isBSTUtil(node* node, int min, int max)
{
    // an empty tree is BST 
    if (node == NULL)
        return 1;

    // false if this node violates
    //the min/max constraint 
    if (node->data < min || node->data > max)
        return 0;

    // otherwise check the subtrees recursively,
    //tightening the min or max constraint 
    return
        isBSTUtil(node->left, min, node->data - 1) && // Allow only distinct values  
        isBSTUtil(node->right, node->data + 1, max); // Allow only distinct values  
}


// Driver code
int main()
{
    node* root = new node(7);
    root->left = new node(11);
    root->right = new node(9);
    root->left->left = new node(1);
    root->left->right = new node(6);

    if (isBST(root))
        cout << "Is BST";
    else
        cout << "Not a BST";

    cout << endl;
    return 0;
}  // CHECK IF GIVEN BINARY TREE IS BST OR NOT */


/*#include <iostream>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode* left, * right;
    TreeNode(int data) {
        val = data;
        left = NULL;
        right = NULL;
    }
};
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root) return NULL;
        if (root->val <= p->val) {
            return inorderSuccessor(root->right, p);
        }
        else {
            TreeNode* option = inorderSuccessor(root->left, p);
            return !option ? root : option;
        }
    }
};
int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    TreeNode* p = root->left;
    Solution ob;
    cout << "Successor is: ";
    cout << (ob.inorderSuccessor(root, p))->val;
    cout << endl << endl;
} INORDER SUCCESSOR IN BST */
