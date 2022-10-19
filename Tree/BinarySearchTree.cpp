#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left,*right;
};
class LNode
{
    public:
    int data;
    LNode* next;
};
Node* create_node(int data)
{
    Node* new_node=new Node();
    new_node->data=data;
    new_node->left=new_node->right=NULL;
    return new_node;
}
// Connstruct BST form given preOrder travarsal
Node* ConstructTreeUtil(int pre[],int*preIndex,int low,int high,int size)
{
    if(*preIndex>=size or low>high) return NULL;
    Node* root=create_node(pre[*preIndex]);
    *preIndex=*preIndex+1;
    if(low==high) return root;
    int i;
    for(i=low;i<=high;i++)
    {
        if(pre[i]>root->data) break;
    }
    root->left=ConstructTreeUtil(pre,preIndex,*preIndex,i-1,size);
    root->right=ConstructTreeUtil(pre,preIndex,i,high,size);
    return root;
}
// Count List Node
int countLNode(LNode* head)
{
    int count=0;
    LNode* temp=head;
    while(temp)
    {
        temp=temp->next;
        count++;
    }
    return count;
}
 Node* sortedListToBSTRecur(LNode* &head_ref,int n)
 {
    if(n<=0) return NULL;
    Node * left=sortedListToBSTRecur(head_ref,n/2);
    Node* root=create_node(head_ref->data);
    root->left=left;
    head_ref=head_ref->next;
    root->right=sortedListToBSTRecur(head_ref,n-n/2-1);
 }
// Sorted List to  BST 
Node* sortedListToBST(LNode*  head)
{
   int n=countLNode(head);
   return sortedListToBSTRecur(head,n);
}

// Sorted Array to BST
Node* SortedArrayToBST(int arr[],int start,int end)
{
    if(start>end)
    {
        return NULL;
    }
    int mid=(start+end)/2;
    Node* root=create_node(arr[mid]);
    root->left=SortedArrayToBST(arr,start,mid-1);
    root->right=SortedArrayToBST(arr,mid+1,end);
    return root;
}

//  Transform a BST to greater sum tree
void transfromTreeUtil(Node* root,int &sum)
{
    if(root==NULL) return;
    transfromTreeUtil(root->right,sum);
    sum+=root->data;
    root->data=sum-root->data;
    transfromTreeUtil(root->left,sum);
}
void TransformTree(Node* root)
{
    int sum=0;
    transfromTreeUtil(root,sum);
}

// Construct a BST from Level Order 
Node* LevelOrder(Node* root,int data)
{
    if(root==NULL)
    {
        root=create_node(data);
        return root;
    }
    if(data<=root->data)
    {
        root->left=LevelOrder(root->left,data);
    }
    else 
    root->right=LevelOrder(root->right,data);
    return root;
}
Node* ConstructBST(int arr[],int n)
{
    if(n==0) return NULL;
    Node* root=NULL;
    for(int i=0;i<n;i++)
    root=LevelOrder(root,arr[i]);
    return root;
}




int main()
{

}