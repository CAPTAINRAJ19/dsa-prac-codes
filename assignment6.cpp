#include <bits/stdc++.h>
using namespace std;
// created a class Node  such that each node will have a data, left pointer, right pointer
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int dat)
    {
        this->data = dat;
        this->left = nullptr;
        this->right = nullptr;
    }
};
// function for inserting a new element into the binary search tree
void insert(Node *root, int data1)
{
    if (root == nullptr)
    {
        cout << "Tree does not exists" << endl;
    }
    else
    {
        Node *temp = root;
        Node *t = new Node(data1);
        while (1)
        {
            if (temp->data > data1 && temp->left != nullptr)
            {
                temp = temp->left;
            }
            else if (temp->data < data1 && temp->right != nullptr)
            {
                temp = temp->right;
            }
            else if (temp->data > data1 && temp->left == nullptr)
            {
                temp->left = t;
                break;
            }
            else if (temp->data < data1 && temp->right == nullptr)
            {
                temp->right = t;
                break;
            }
            else if (temp->data == data1)
            {
                cout << "Cannot Enter, entry already exists" << endl;
                break;
            }
        }
    }
}

// function for searching a element inside the binary search tree
void search(Node *root, int data1)
{
    if (root == nullptr)
    {
        cout << "Tree does not exists" << endl;
    }
    else
    {
        Node *temp = root;
        while (1)
        {
            if (temp->data > data1 && temp->left != nullptr)
            {
                temp = temp->left;
            }
            else if (temp->data < data1 && temp->right != nullptr)
            {
                temp = temp->right;
            }
            else if (temp->data > data1 && temp->left == nullptr)
            {
                cout << "Element not found" << endl;
                break;
            }
            else if (temp->data < data1 && temp->right == nullptr)
            {
                cout << "Element not found" << endl;
                break;
            }
            else if (temp->data == data1)
            {
                cout << "Element found" << endl;
                break;
            }
        }
    }
}

// function for recursive inorder traversal of the binarysearch tree
void displayinorder(Node *root)
{
    Node *temp = root;
    if (temp->left != nullptr)
    {
        displayinorder(temp->left);
    }
    cout << temp->data << " ";
    if (temp->right != nullptr)
    {
        displayinorder(temp->right);
    }
}

// function for recursive preorder traversal of the binarysearch tree
void displaypreorder(Node *root)
{
    Node *temp = root;
    cout << temp->data << " ";
    if (temp->left != nullptr)
    {
        displaypreorder(temp->left);
    }
    if (temp->right != nullptr)
    {
        displaypreorder(temp->right);
    }
}

// recursive function for postorder traversal
void displaypostorder(Node *root)
{
    Node *temp = root;
    if (temp->left != nullptr)
    {
        displaypostorder(temp->left);
    }
    if (temp->right != nullptr)
    {
        displaypostorder(temp->right);
    }
    cout << temp->data << " ";
}

// non recursive inorder traversal using stack
void displayinordernonrecursive(Node *root)
{
    stack<Node *> s;
    Node *p = root;
    while (p != nullptr || s.empty() == false)
    {
        while (p != nullptr)
        {
            s.push(p);
            p = p->left;
        }
        p = s.top();
        s.pop();
        cout << p->data << " ";
        p = p->right;
    }
}

// non recursive preorder traversal using stack
void displaypreordernonrecursive(Node *root)
{
    stack<Node *> nstack;
    nstack.push(root);
    while (nstack.empty() == false)
    {
        Node *temp = nstack.top();
        cout << temp->data << " ";
        nstack.pop();
        if (temp->right != nullptr)
        {
            nstack.push(temp->right);
        }
        if (temp->left != nullptr)
        {
            nstack.push(temp->left);
        }
    }
}

// non recursive postorder traversal using stack
void displaypostordernonrecursive(Node *root)
{
    stack<Node *> s1, s2;
    s1.push(root);
    while (!s1.empty())
    {
        Node *temp = s1.top();
        s1.pop();
        s2.push(temp);
        if (temp->left != nullptr)
        {
            s1.push(temp->left);
        }
        if (temp->right != nullptr)
        {
            s1.push(temp->right);
        }
    }
    while (!s2.empty())
    {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}


//function for level order traversal
void levelOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i) {
            Node* current = q.front();
            q.pop();
            cout << current->data << " ";

            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }
    }
}


Node *findMin(Node *node)
{
    while (node->left != NULL)
    {
        node = node->left;
    }
    return node;
}

Node *deleteNode(Node *&root, int key)
{
    if (root == nullptr)
    {
        return root;
    }

    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }

    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->left == nullptr)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        Node *temp = findMin(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}