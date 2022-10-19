#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
};
// Function to create new Node
Node *Create_node(int data)
{
    Node *newNode = new Node();
    if (!newNode)
    {
        cout << "Memory erroer" << endl;
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
}
// Insert element in Binary Tree
Node *InsertNode(Node *root, int data)
{
    if (root = NULL)
    {
        root = Create_node(data);
        return root;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp->left)
        {
            q.push(temp->left);
        }
        else
        {
            temp->left = Create_node(data);
            return root;
        }
        if (temp->right)
        {
            q.push(temp->right);
        }
        else
        {
            temp->right = Create_node(data);
            return root;
        }
    }
}
// Deletion in a Binary Tree
Node *deleteNode(Node *root, int key)
{
    if (root == NULL)
        return NULL;
    if (root->left == NULL and root->right == NULL)
    {
        if (root->data == key)
            return NULL;
        else
            return root;
    }
    Node *key_node = NULL;
    Node *temp, *last;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp->data == key)
        {
            key_node = temp;
        }
        if (temp->left)
        {
            last = temp;
            q.push(temp->left);
        }
        if (temp->right)
        {
            last = temp;
            q.push(temp->right);
        }
    }
    if (key_node != NULL)
    {
        key_node->data = temp->data;
        if (last->left == temp)
        {
            last->left = NULL;
        }
        else
            last->right = NULL;
        delete (temp);
    }
    return root;
}
// Function to check tree is continuous or Not
bool treeConntinuous(Node *root)
{
    if (root == NULL)
        return true;
    if (root->left == NULL and root->right == NULL)
        return true;

    if (root->left == NULL)
        return (abs(root->data - root->right->data) == 1) and treeConntinuous(root->right);
    if (root->right == NULL)
        return (abs(root->data - root->left->data) == 1) and treeConntinuous(root->left);
    return abs(root->data - root->left->data) and abs(root->right->data - root->data) and treeConntinuous(root->left) and treeConntinuous(root->right);
}
// Converts a Tree to it's Mirror image
void mirror(Node *root)
{
    if (root == NULL)
        return;
    else
    {
        mirror(root->left);
        mirror(root->right);
        swap(root->left, root->right);
    }
}
// check Structure is same
bool isStructSame(Node *a, Node *b)
{
    if (a == NULL and b == NULL)
        return true;
    return (a != NULL and b != NULL and isStructSame(a->left, b->left) and isStructSame(a->right, b->right));
}
//  check is foldable
bool is_foldable(Node *root)
{
    bool res;
    if (root == NULL)
        return true;
    mirror(root->left);
    res = isStructSame(root->left, root->right);
    mirror(root->left);
    return res;
}

// Mirror of Self or Symmetric Tree
bool is_Mirror_of_self(Node *root1, Node *root2)
{
    if (root1 == NULL and root2 == NULL)
        return true;
    return root1 and root2 and root1->data == root2->data and is_Mirror_of_self(root1->left, root2->right) && is_Mirror_of_self(root1->right, root2->left);
}

// Symmetric Tree (Mirror Image of itself)
bool isSymmetric(Node *root)
{
    return is_Mirror_of_self(root, root);
}

// Tree Traversal

// Inorder Traversal
void InOrder(Node *root)
{
    if (root == NULL)
        return;
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

// Inorder without Recursion
void Inorder_without_recursion(Node *root)
{
    stack<Node *> st;
    Node *curr = root;
    while (curr != NULL or !st.empty())
    {
        while (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        cout << st.top()->data << " ";
        curr = st.top()->right;
        st.pop();
    }
}

// Inorder without Recursion and without Stack or Using Morris Traversal ---(IMP)---
void Morris_Inoder(Node *root)
{
    Node *curr, *prev;
    if (root == NULL)
        return;
    curr = root;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            cout << curr->data << " ";
            curr = curr->right;
        }
        else
        {
            prev = curr->left;
            while (prev->right != NULL and prev->right != curr)
            {
                prev = prev->right;
            }
            if (prev->right == NULL)
            {
                prev->right == curr;
                curr = curr->left;
            }
            else
            {
                prev->right == NULL;
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
    }
}
// PreOrder Traversal
void PreOrder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}
// PreOrder without Recursion
void PreOrder_without_recursion(Node *root)
{
    Node *curr = root;
    stack<Node *> st;
    while (curr != NULL and !st.empty())
    {
        while (curr != NULL)
        {
            cout << curr->data << " ";

            if (curr->right)
                st.push(curr->right);

            curr = curr->left;
        }
        if (!st.empty())
        {
            curr = st.top();
            st.pop();
        }
    }
}

// Morris Traversal  or preOrder without Recursion and without stack
void MorrisTraversalPreorder(Node *root)
{
    while (root)
    {
        // if left child is NULL print current and move to right child
        if (root->left == NULL)
        {
            cout << root->data << " ";
            root = root->right;
        }
        else
        {
            // Find Inorder Predecerssor
            Node *curr = root->left;
            while (curr->right and curr->right != root)
            {
                curr = curr->right;
            }
            // if the right child of inorder predecessor alredady points to this node
            if (curr->right == root)
            {
                curr->right = NULL;
                root = root->right;
            }
            else
            {
                cout << root->data << " ";
                curr->right = root;
                root = root->left;
            }
        }
    }
}
// Post Order Traversal
void PostOrder(Node *root)
{
    if (root == NULL)
        return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
}
// Post Order Traversal without Recursion
void PostOrderIterative(Node *root)
{
    if (root == NULL)
        return;
    stack<Node *> s1, s2;
    s1.push(root);
    Node *node;
    while (!s1.empty())
    {
        node = s1.top();
        s1.pop();
        if (node->left)
            s1.push(node->left);
        if (node->right)
            s1.push(node->right);
    }
    while (!s2.empty())
    {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}
vector<int> postOrderIterative(Node *root)
{
    vector<int> postOrderList;
    // Check for empty tree
    if (root == NULL)
        return postOrderList;
    stack<Node *> S;
    S.push(root);
    Node *prev = NULL;
    while (!S.empty())
    {
        auto current = S.top();
        /* go down the tree in search of a leaf an if so
           process it and pop stack otherwise move down */
        if (prev == NULL || prev->left == current || prev->right == current)
        {
            if (current->left)
                S.push(current->left);
            else if (current->right)
                S.push(current->right);
            else
            {
                S.pop();
                postOrderList.push_back(current->data);
            }
            /* go up the tree from left node, if the child
               is right push it onto stack otherwise process
               parent and pop stack */
        }

        else if (current->left == prev)
        {
            if (current->right)
                S.push(current->right);
            else
            {
                S.pop();
                postOrderList.push_back(current->data);
            }

            /* go up the tree from right node and after
            coming back from right node process parent and
            pop stack */
        }
        else if (current->right == prev)
        {
            S.pop();
            postOrderList.push_back(current->data);
        }
        prev = current;
    }
    return postOrderList;
}

// Level Order Binary Tree Traversal
void Level_Order(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
}
// Reverse Level Order Traversal
void reverselevelOrder(Node *root)
{
    stack<Node *> st;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        st.push(temp);

        if (temp->right)
            q.push(temp->right);
        if (temp->left)
            q.push(temp->left);
    }
    while (!st.empty())
    {
        cout << st.top()->data << " ";
        st.pop();
    }
}

// Reverse alternate levels of a perfect binary
void preOrder_reverse(Node *root1, Node *root2, int lvl)
{
    if (root1 == NULL or root2 == NULL)
        return;
    if (lvl % 2 == 0)
        swap(root1->data, root2->data);
    preOrder_reverse(root1->left, root2->right, lvl + 1);
    preOrder_reverse(root1->right, root2->left, lvl + 1);
}
// reverse of alterate node's
void RevereAlternate(Node *root)
{
    preOrder_reverse(root->left, root->right, 0);
}
// Print PostOrder Traversal from given Inorder and  preOrder Traversals
int preIndex = 0;
int search(int arr[], int startIn, int endIn, int data)
{
    int i = 0;
    for (int i = startIn; i < endIn; i++)
    {
        if (arr[i] == data)
            return i;
    }
    return i;
}
void printPost(int arr[], int pre[], int inStart, int inEnd)
{
    if (inStart > inEnd)
    {
        return;
    }
    int inIndex = search(arr, inStart, inEnd, pre[preIndex++]);
    printPost(arr, pre, inStart, inIndex - 1);
    printPost(arr, pre, inIndex + 1, inEnd);
    cout << arr[inIndex] << " ";
}

// {4,2,5,1,3,6}
// {1,2,4,5,3,6}
//        1
//     2    3
//   4  5      6

// Diagonal Print
void digonalPrinntUtil(Node *root, int d, map<int, vector<int>> &diagonalPrint)
{
    if (!root)
        return;
    diagonalPrint[d].push_back(root->data);
    digonalPrinntUtil(root->left, d + 1, diagonalPrint);
    digonalPrinntUtil(root->right, d, diagonalPrint);
}
// Diagonal Traversal of Binary Tree
void DiagonalPrint(Node *root)
{
    map<int, vector<int>> diagonalPrint;
    digonalPrinntUtil(root, 0, diagonalPrint);
    cout << "Diagonal Traversal of binary Tree:" << endl;
    for (auto it : diagonalPrint)
    {
        vector<int> v = it.second;
        for (auto i : v)
        {
            cout << i << " ";
        }
    }
}
// Or
vector<int>diagonal(Node* root)
{
    vector<int>diagonalVals;
    if(!root) return diagonalVals;
    queue<Node*>q;
    Node* node=root;
    while(node)
    {
        diagonalVals.push_back(node->data);
        if(node->left)
        {
            q.push(root->left);
        }
        if(node->right)
        {
            node=node->right;
        }
        else
        {
            if(!q.empty())
            {
                node=q.front(); q.pop();
            }
            else node=NULL;
        }
    }
    return diagonalVals;
}
// Boundary Traversal of binary Tree

// A simple fuction to print leaf node of a binary tree
void printLeaves(Node * root)
{
    if(root==NULL) return;
    printLeaves(root->left);
    if(!(root->left) and !(root->right))
    {
        cout<<root->data<<"  ";
    }
    printLeaves(root->right);
}

// A function t o print all left boundary nodes
void printBoundaryLeft(Node*  root)
{
    if(root=NULL) return;
    if(root->left)
    {
        cout<<root->data<<" ";
        printBoundaryLeft(root->left);
    }
    else if(root->right)
    {
        cout<<root->data<<" ";
        printBoundaryLeft(root->right);
    }
}
void printBoundaryRight(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    if(root->right)
    {
        printBoundaryRight(root->right);
        cout<<root->data<<" ";
    }
    else if(root->left)
    {
        printBoundaryRight(root->left);
        cout<<root->data<<" ";
    }
}

void printBoundary(Node* root)
{
    if(root==NULL)
    return;
    cout<<root->data<<" ";
    printBoundaryLeft(root->left);
    printLeaves(root->left);
    printLeaves(root->right);
    printBoundaryRight(root->right);
}
int height(Node* root)
{
    if(root==NULL) return 0;
    return max(height(root->left),height(root->right)+1);
}
void count(Node* root,int &size)
{
    if(root==NULL) return;
    count(root->left,size);
    count(root->right,size);
    size++;
}
double density(Node* root)
{
    if(root==NULL)
    return 0;
    int size=0;
    count(root,size);
    int _height=height(root);
    return double(size)/double(_height);
}

// Construct a Complete binary tree from given array in level ofrder fashion

Node* insertLevelOrder(int arr[],int i,int n)
{
    Node* root=NULL;
    if(i<n)
    {
        root=Create_node(arr[i]);
        root->left=insertLevelOrder(arr,2*i+1,n);
        root->right=insertLevelOrder(arr,2*i+2,n);
    }
    return root;
}
// Convert a Given treee to a sum tree
int toSumTree(Node* node)
{
    if(node==NULL) return 0;
    int old_val=node->data;
    node->data=toSumTree(node->left)+toSumTree(node->right);
    return node->data+old_val;
}
// sum od BT includeing it's self
int LeftSubTree(Node* root)
{
    if(!root) return 0;
    if(root->left==NULL and root->right==NULL) return root->data;
    int leftsum=LeftSubTree(root->left);
    int rightsum=LeftSubTree(root->right);
    root->data+=leftsum;
    return root->data+rightsum;

}