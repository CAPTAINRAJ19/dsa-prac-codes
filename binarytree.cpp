// 7220 Dhruv binary tree implementation




#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int dat)//parameterised constructor
    {
        this->left = nullptr;
        this->right = nullptr;
        this->data = dat;
    }
};





// code for normal binary tree insertion
void insert(Node *root, int key)
{
    Node *t = new Node(key);//creating new node that is pointed by t
    Node *temp = root;//temp is pointing to the root
    while (1)
    {
        cout << "Where to enter:right(r) or left(l) of" << temp->data;
        char c;
        cin >> c;
        if (c == 'r')
        {
            if (temp->right == nullptr)//if right is empty then insert the new node here
            {
                temp->right = t;
                cout << "Node entered successfully" << endl;
                break;
            }
            else//else move right
            {
                temp = temp->right;
            }
        }
        else
        {
            if (temp->left == nullptr)//if left is empty then insert new node here
            {
                temp->left = t;
                cout << "Node entered successfully" << endl;
                break;
            }
            else//else move left
            {
                temp = temp->left;
            }
        }
    }
}





// insertion in binary searchtree
void insertbtree(Node *root, int key)
{
    Node *t = new Node(key);
    Node *temp = root;
    while (1)
    {
        if (temp->data > key)//if data at temp is greater than data to be entered then we move left if subtree exists else enter new node as left child
        {
            if (temp->left == nullptr)
            {
                temp->left = t;
                cout << "Node entered successfully" << endl;
                break;
            }
            else
            {
                temp = temp->left;
            }
        }
        else//if data at temp is smaller than data to be entered then we move right if subtree exists else enter the new node to be entered as right child
        {
            if (temp->right == nullptr)
            {
                temp->right = t;
                cout << "Node entered successfully" << endl;
                break;
            }
            else
            {
                temp = temp->right;
            }
        }
    }
}




// recursive function for inorder traversal
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






// recursive function for preorder traversal
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



// function for calculating the height of the given tree
int heightcalculator(Node *root)
{
    int lh;
    int rh;
    if (root->left == nullptr)
    {
        lh = 0;
    }
    else
    {
        lh = (heightcalculator(root->left));
    }
    if (root->right == nullptr)
    {
        rh = 0;
    }
    else
    {
        rh = (heightcalculator(root->right));
    }

    return max(lh, rh) + 1;
}

// function for creating the mirror image of a given tree
Node *mirrorimage(Node *root)
{
    if (root != nullptr)
    {
        Node *x = new Node(root->data);
        x->right = mirrorimage(root->left);
        x->left = mirrorimage(root->right);
        return x;
    }
    else
    {
        return nullptr;
    }
}

// function for creating the clone  of a given tree
Node *clone(Node *root)
{
    if (root != nullptr)
    {
        Node *x = new Node(root->data);
        x->left = clone(root->left);
        x->right = clone(root->right);
        return x;
    }
    else
    {
        return nullptr;
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

int main()
{
    Node *root = nullptr;
    Node *p = new Node(25);
    root = p;
    root->left = new Node(5);
    root->right = new Node(17);
    int t;
    deleteNode(root, 5);

    // The above is hardcoded part of the tree having one root and two child nodes

    // The below coded part is for the normal binary tree insertion
    cout << "Enter the no of new nodes to insert in the tree";
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int key;
        cout << "Enter the data of the next key to be entered";
        cin >> key;
        insert(root, key);
    }
    cout << "Inorder traversal is as follows" << endl;
    displayinorder(root);
    cout << endl
         << "preorder traversal is as follows" << endl;
    displaypreorder(root);
    cout << endl
         << "postorder traversal is as follows" << endl;
    displaypostorder(root);
    cout << endl
         << "Inorder traversal non recursive is as follows" << endl;
    displayinordernonrecursive(root);
    cout << endl
         << "Preorder traversal non recursive is as follows" << endl;
    displaypreordernonrecursive(root);
    cout << endl
         << "postorder traversal non recursive is as follows" << endl;
    displaypostordernonrecursive(root);
    cout << endl
         << "The height of the given tree is : " << heightcalculator(root) << endl;
    cout << endl
         << "The inorder traversal of mirror image of given tree is" << endl;
    displayinorder(mirrorimage(root));
}