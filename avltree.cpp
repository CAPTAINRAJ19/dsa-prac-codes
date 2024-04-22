// A Dictionary stores keywords & its meanings. Provide facility for adding new keywords,
// deleting keywords, updating values of any entry. Provide facility to display whole data sorted in ascending/ Descending order. Also find how many maximum comparisons may require for finding any keyword. Use Height balance tree and find the complexity for finding a keyword in easiest possible way.

#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string keyword;
    string meaning;
    int height;
    Node *left;
    Node *right;

    Node(string key, string value)
    {
        keyword = key;
        meaning = value;
        height = 1;
        left = nullptr;
        right = nullptr;
    }
};

class Dictionary
{
private:
    Node *root;

    int getHeight(Node *node)
    {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    int getBalanceFactor(Node *node)
    {
        if (node == nullptr)
            return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    Node *rotateLeft(Node *node)
    {
        Node *newRoot = node->right;
        node->right = newRoot->left;
        newRoot->left = node;
        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        newRoot->height = max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;
        return newRoot;
    }

    Node *rotateRight(Node *node)
    {
        Node *newRoot = node->left;
        node->left = newRoot->right;
        newRoot->right = node;
        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        newRoot->height = max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;
        return newRoot;
    }

    Node *insertNode(Node *node, string key, string value)
    {
        if (node == nullptr)
            return new Node(key, value);
        if (key < node->keyword)
            node->left = insertNode(node->left, key, value);
        else if (key > node->keyword)
            node->right = insertNode(node->right, key, value);
        else
        {
            // Keyword already exists, update the meaning
            node->meaning = value;
            return node;
        }
        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        int balanceFactor = getBalanceFactor(node);
        if (balanceFactor > 1 && key < node->left->keyword)
            return rotateRight(node);
        if (balanceFactor < -1 && key > node->right->keyword)
            return rotateLeft(node);
        if (balanceFactor > 1 && key > node->left->keyword)
        {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        if (balanceFactor < -1 && key < node->right->keyword)
        {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
        return node;
    }

    Node *findMinNode(Node *node)
    {
        if (node == nullptr || node->left == nullptr)
            return node;
        return findMinNode(node->left);
    }

    Node *deleteNode(Node *node, string key)
    {
        if (node == nullptr)
            return node;
        if (key < node->keyword)
            node->left = deleteNode(node->left, key);
        else if (key > node->keyword)
            node->right = deleteNode(node->right, key);
        else
        {
            if (node->left == nullptr || node->right == nullptr)
            {
                Node *temp = node->left ? node->left : node->right;
                if (temp == nullptr)
                {
                    temp = node;
                    node = nullptr;
                }
                else
                {
                    *node = *temp;
                }
                delete temp;
            }
            else
            {
                Node *temp = findMinNode(node->right);
                node->keyword = temp->keyword;
                node->meaning = temp->meaning;
                node->right = deleteNode(node->right, temp->keyword);
            }
        }
        if (node == nullptr)
            return node;
        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        int balanceFactor = getBalanceFactor(node);
        if (balanceFactor > 1 && getBalanceFactor(node->left) >= 0)
            return rotateRight(node);
        if (balanceFactor > 1 && getBalanceFactor(node->left) < 0)
        {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        if (balanceFactor < -1 && getBalanceFactor(node->right) <= 0)
            return rotateLeft(node);
        if (balanceFactor < -1 && getBalanceFactor(node->right) > 0)
        {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
        return node;
    }

    void inorderTraversal(Node *node)
    {
        if (node != nullptr)
        {
            inorderTraversal(node->left);
            cout << node->keyword << ": " << node->meaning << endl;
            inorderTraversal(node->right);
        }
    }
    void revinorderTraversal(Node *node)
    {
        if (node != nullptr)
        {
            revinorderTraversal(node->right);
            cout << node->keyword << ": " << node->meaning << endl;
            revinorderTraversal(node->left);
        }
    }

public:
    Dictionary()
    {
        root = nullptr;
    }

    void addKeyword(string key, string value)
    {
        root = insertNode(root, key, value);
    }

    void deleteKeyword(string key)
    {
        root = deleteNode(root, key);
    }

    void displayAscending()
    {
        inorderTraversal(root);
    }

    void displayDescending()
    {
        revinorderTraversal(root);
        // TODO: Implement reverse inorder traversal
    }
};

int main()
{
    Dictionary dict;
    dict.addKeyword("apple", "A fruit");
    dict.addKeyword("banana", "A fruit");
    dict.addKeyword("car", "A vehicle");
    dict.addKeyword("dog", "An animal");

    cout << "Ascending order:" << endl;
    dict.displayAscending();

    cout << endl;

    cout << "Descending order:" << endl;
    dict.displayDescending();

    return 0;
}