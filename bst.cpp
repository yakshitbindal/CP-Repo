#include<bits/stdc++.h>
#include"BinaryTreeNode.h"
using namespace std;

BinaryTreeNode<int>* takeInputLevelWise()
{
    int rootData;
    cout<<"Enter root Data: ";
    cin>>rootData;
    cout<<endl;
    if(rootData==-1)
        return NULL;
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0)
    {
        BinaryTreeNode<int>* front=pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter left node of "<<front->data<<":";
        int leftChildData;
        cin>>leftChildData;
        cout<<endl;
        if(leftChildData!=-1)
        {
            BinaryTreeNode<int>* childNode=new BinaryTreeNode<int>(leftChildData);
            front->left=childNode;
            pendingNodes.push(childNode);
        }
        cout<<"Enter right node of "<<front->data<<":";
        int rightChildData;
        cin>>rightChildData;
        cout<<endl;
        if(rightChildData!=-1)
        {
            BinaryTreeNode<int>* childNode=new BinaryTreeNode<int>(rightChildData);
            front->right=childNode;
            pendingNodes.push(childNode);
        }
    }
    return root;
}

/*
//time cpmplexity is too high
int maximum(BinaryTreeNode<int>* root)
{
    if(root==NULL)
        return INT_MIN;
    return max(root->data,max(maximum(root->left),maximum(root->right)));
}

int minimum(BinaryTreeNode<int>* root)
{
    if(root==NULL)
        return INT_MAX;
    return min(root->data,min(minimum(root->left),minimum(root->right)));
}

bool isBST(BinaryTreeNode<int>* root)
{
    if(root==NULL)
        return true;
    int leftMax=maximum(root->left);
    int rightMin=minimum(root->right);
    bool output= (root->data > leftMax) && (root->data <= rightMin) && isBST(root->left) && isBST(root->right);
    return output;
}


class IsBSTReturn
{
    public:
    bool isBSTCheck;
    int maximum;
    int minimum;
};

IsBSTReturn isBST2(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        IsBSTReturn output;
        output.isBSTCheck=true;
        output.maximum=INT_MIN;
        output.minimum=INT_MAX;
        return output;
    }
    IsBSTReturn leftOutput=isBST2(root->left);
    IsBSTReturn rightOutput=isBST2(root->right);
    int minimum=min(root->data,min(leftOutput.minimum,rightOutput.minimum));
    int maximum=max(root->data,max(leftOutput.maximum,rightOutput.maximum));
    bool isBSToutput= (root->data > leftOutput.maximum) && (root->data <= rightOutput.minimum) && leftOutput.isBSTCheck && rightOutput.isBSTCheck;
    IsBSTReturn output;
    output.minimum=minimum;
    output.maximum=maximum;
    output.isBSTCheck=isBSToutput;
    return output;
}
*/

BinaryTreeNode<int>* helper(int *input,int si,int ei)
{
    if(si>ei)
        return NULL;
    int mid=(si+ei)/2;
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(input[mid]);
    root->left=helper(input,si,mid-1);
    root->right=helper(input,mid+1,ei);
    return root;
}

BinaryTreeNode<int>* constructTree(int *input, int n) {
    return helper(input,0,n-1);
}

void preOrder(BinaryTreeNode<int>* root) {
    if(root == NULL) {
        return;
    }
    cout << root -> data << " ";
    preOrder(root -> left);
    preOrder(root -> right);
}

int main()
{
	//BinaryTreeNode<int>* root=takeInputLevelWise();
    /*
    IsBSTReturn output=isBST2(root);
    cout<<output.isBSTCheck<<endl;
    */
    int size;
    cin>>size;
    int *input=new int[1+size];
    
    for(int i=0;i<size;i++)
        cin>>input[i];
    
    BinaryTreeNode<int>* root = constructTree(input, size);
    preOrder(root);
    return 0;
}