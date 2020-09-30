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
void preOrder(BinaryTreeNode<int>* root)
{
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(BinaryTreeNode<int>* root)
{
    if(root==NULL)
        return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void postOrder(BinaryTreeNode<int>* root)
{
    if(root==NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

int sumOfAllNodes(BinaryTreeNode<int>* root)
{
    if(root==NULL)
        return 0;
    return root->data+sumOfAllNodes(root->left)+sumOfAllNodes(root->right);
}

int getDifferenceEvenOddValues(BinaryTreeNode<int>* root)
{
    if(root==NULL)
        return 0;
    return root->data - getDifferenceEvenOddValues(root->left) - getDifferenceEvenOddValues(root->right);
}

int numNodes(BinaryTreeNode<int>* root)
{
    if(root==NULL)
        return 0;
    return 1+numNodes(root->left)+numNodes(root->right);
}

int numLeafNodes(BinaryTreeNode<int>* root)
{
    if(root==NULL)
        return 0;
    if(root->left==NULL && root->right==NULL)
        return 1+numLeafNodes(root->left)+numLeafNodes(root->right);
    else
        return numLeafNodes(root->left)+numLeafNodes(root->right);;
}

int height(BinaryTreeNode<int>* root)
{
	if(root==NULL)
		return 0;
	return 1+max(height(root->left),height(root->right));
}

void printElementsAtGivenLevel(BinaryTreeNode<int>* root,int level)
{
	if(root==NULL)
		return;
	if(level==1)
		cout<<root->data<<" ";
	printElementsAtGivenLevel(root->left,level-1);
	printElementsAtGivenLevel(root->right,level-1);
}
*/
/*
void printLevelOrderRec(BinaryTreeNode<int>* root)
{
	//To do this first we have to find the height of tree
	// then for loop from 0 to height and at each level we will print nodes over there
	int h=height(root);
	for(int i=0;i<=h;i++)
	{
		printElementsAtGivenLevel(root,i+1);
		cout<<"\n";
	}
}
*/
/*
void printLevelOrderQueue(BinaryTreeNode<int>* root)
{
	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while(pendingNodes.size()!=0)
	{
		BinaryTreeNode<int>* front=pendingNodes.front();
		pendingNodes.pop();
		cout<<front->data<<" ";
		if(front->left)
			pendingNodes.push(front->left);
		if(front->right)
			pendingNodes.push(front->right);
	}
}

void reverseLevelOrderRec(BinaryTreeNode<int>* root)
{
	int h=height(root);
	for(int i=h;i>0;i--)
	{
		printElementsAtGivenLevel(root,i);
		cout<<"\n";
	}
}

void reverseLevelOrderWithoutRec(BinaryTreeNode<int>* root)
{
	queue<BinaryTreeNode<int>*> pendingNodes;
	stack<BinaryTreeNode<int>*> s1;
	pendingNodes.push(root);
	while(pendingNodes.size()!=0)
	{
		BinaryTreeNode<int>* front=pendingNodes.front();
		pendingNodes.pop();
		s1.push(front);
		if(front->right)
		{
			pendingNodes.push(front->right);
		}
		if(front->left)
		{
			pendingNodes.push(front->left);
		}
	}
	while(s1.size()!=0)
	{
		cout<<s1.top()->data<<" ";
		s1.pop();
	}
}

void leftView(BinaryTreeNode<int>* root,int level,int* max_level)
{
	if(root==NULL)
		return;
	if(level>*max_level)
	{
		cout<<root->data<<" ";
		*max_level=level;
	}
	leftView(root->left,level+1,max_level);
	leftView(root->right,level+1,max_level);
}

void rightView(BinaryTreeNode<int>* root,int level,int* max_level)
{
	if(root==NULL)
		return;
	if(*max_level<level)
	{
		cout<<root->data<<" ";
		*max_level=level;
	}
	rightView(root->right,level+1,max_level);
	rightView(root->left,level+1,max_level);
}


void inOrderIterative(BinaryTreeNode<int>* root)
{
	// 1) Go (root->left) till left becomes null push all in stack
	// 2) when root==NULL then 
	//         print(top)
	//		   pop()
	//		   put root=top->right (to move to right tree)
	if(root==NULL)
		return;
	stack<BinaryTreeNode<int>*> s1;
	while(true)
	{
		if(root!=NULL)
		{
			s1.push(root);
			root=root->left;
		}
		else
		{
			if(s1.empty())
				break;
			BinaryTreeNode<int>* front=s1.top();
			cout<<front->data<<" ";
			s1.pop();
			root=front->right;
		}
	}
}

BinaryTreeNode<int>* mirror(BinaryTreeNode<int>* root)
{
	if(root==NULL)
		return NULL;
	root->left=mirror(root->left);
	root->right=mirror(root->right);
	BinaryTreeNode<int>* temp=root->left;
	root->left=root->right;
	root->right=temp;
	return root;
}


bool isIdentical(BinaryTreeNode<int>* root1,BinaryTreeNode<int>* root2)
{
	if(root1 && root2)
		return true;
	if(root1 || root2)
		return false;
	if(root1->data!=root2->data)
		return false;
	bool b1=isIdentical(root1->left,root2->left);
	bool b2=isIdentical(root1->right,root2->right);
	if(b1 && b2)
		return true;
	else
		return false;
}


int getLevelOfANode(BinaryTreeNode<int>* root,int val,int level)
{
	if(root==NULL)
		return 0;
	if(root->data==val)
		return level;
	int ans1=getLevelOfANode(root->left,val,level+1);
	if(ans1!=0)
		return ans1;
	int ans2=getLevelOfANode(root->right,val,level+1);
	return ans2;
}

int getLevelOfANode(BinaryTreeNode<int>* root,int val)
{
	return getLevelOfANode(root,val,1);
}
*/
/*

void topView(BinaryTreeNode<int>* root)
{
	if(root==NULL)
		return;
	queue<BinaryTreeNode<int>*> pendingNodes;
	map<int,int> m1;
	int hd=0;
	root->hd=hd;
	pendingNodes.push(root);
	while(pendingNodes.size()!=0)
	{
		BinaryTreeNode<int>* front=pendingNodes.front();
		pendingNodes.pop();
		hd=root->hd;
		if(m1.count(hd)==0)
			m1[hd]=front->data;
		if(front->left)
		{
			front->left->hd=hd-1;
			pendingNodes.push(front->left);
		}
		if(front->right)
		{
			front->right->hd=hd+1;
			pendingNodes.push(front->right);
		}
	}
	for(auto i=m1.begin();i!=m1.end();i++)
	{
		cout<<i->second<<" ";
	}
}
*/

/*

void printLeftView(BinaryTreeNode<int>* root)
{
	if(root==NULL)
		return;
	if(root->left==NULL && root->right==NULL)
		return;
	cout<<root->data<<" ";
	if(root->left)
		printLeftView(root->left);
	else
		printLeftView(root->right);
}

void printBottomView(BinaryTreeNode<int>* root)
{
	if(root==NULL)
		return;
	if(root->left==NULL && root->right==NULL)
	{
		cout<<root->data<<" ";
		return;
	}
	if(root->left)
		printBottomView(root->left);
	if(root->right)
		printBottomView(root->right);
}

void printRightView(BinaryTreeNode<int>* root)
{
	if(root==NULL)
		return;
	if(root->left==NULL && root->right==NULL)
		return;
	if(root->right)
	{
		printRightView(root->right);
		cout<<root->data<<" ";
	}
	else
	{
		printRightView(root->left);
		cout<<root->data<<" ";
	}

}

void printBoundary(BinaryTreeNode<int>* root)
{
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	//for this we have to make 3 functions
	//1) first will be the left view
	//2) second will be the bottom view
	//3) third will be the right view

	//left view
	printLeftView(root->left);
	//bottom view which means only leaf nodes
	printBottomView(root->left);
	printBottomView(root->right);
	//right view
	printRightView(root->right);
}
*/

/*
void verticalOrderTraversal(BinaryTreeNode<int>* root)
{
	if(root==NULL)
		return;
	map<int,vector<int>> m1;
	int hd=0;
	queue<pair<BinaryTreeNode<int>*,int>> pendingNodes;
	pendingNodes.push(make_pair(root,hd));
	while(pendingNodes.size()!=0)
	{
		pair<BinaryTreeNode<int>*,int> front=pendingNodes.front();
		pendingNodes.pop();
		hd=front.second;
		BinaryTreeNode<int>* node=front.first;
		m1[hd].push_back(node->data);
		if(node->left)
			pendingNodes.push(make_pair(node->left,hd-1));
		if(node->right)
			pendingNodes.push(make_pair(node->right,hd+1));
	}
	for(auto i=m1.begin();i!=m1.end();i++)
	{
		for(int j=0;j<i->second.size();j++)
		{
			cout<<i->second[j]<<" ";
		}
		cout<<"\n";
	}
}
*/
/*
void verticalSum(BinaryTreeNode<int> *root)
{
	if(root==NULL)
		return;
	map<int,int> m1;
	int hd=0;
	queue<pair<BinaryTreeNode<int>*,int>> pendingNodes;
	pendingNodes.push(make_pair(root,hd));
	while(!pendingNodes.empty())
	{
		pair<BinaryTreeNode<int>*,int> front=pendingNodes.front();
		pendingNodes.pop();
		hd=front.second;
		BinaryTreeNode<int>* node=front.first;
		//cout<<m1.count(hd)<<" ";
		if(m1.count(hd)==0)
			m1[hd]=node->data;
		else
			m1[hd]+=node->data;
		if(node->left)
			pendingNodes.push(make_pair(node->left,hd-1));
		if(node->right)
			pendingNodes.push(make_pair(node->right,hd+1));
	}
	for(auto i=m1.begin();i!=m1.end();i++)
	{
		cout<<i->second<<"\n";
	}
}
*/
/*
bool searchElement(BinaryTreeNode<int>* root,int element)
{
	if(root==NULL)
		return false;
	return (root->data==element) || (searchElement(root->left,element)) || (searchElement(root->right,element));
}
*/
/*
void printSpiral(BinaryTreeNode<int>* root)
{
	if(root==NULL)
		return;
	stack<BinaryTreeNode<int>*> s1;
	stack<BinaryTreeNode<int>*> s2;
	s1.push(root);
	while(!s1.empty() || !s2.empty())
	{
		while(!s1.empty())
		{
			BinaryTreeNode<int>* node=s1.top();
			s1.pop();
			cout<<node->data<<" ";
			if(node->left)
				s2.push(node->left);
			if(node->right)
				s2.push(node->right);
		}
		while(!s2.empty())
		{
			BinaryTreeNode<int>* node=s2.top();
			s2.pop();
			cout<<node->data<<" ";
			if(node->right)
				s1.push(node->right);
			if(node->left)
				s1.push(node->left);
		}
	}
}
*/

/*
void printLevels(BinaryTreeNode<int>* root,int currLevel,int mini,int maxi)
{
	if(root==NULL)
		return;
	if(currLevel>=mini && currLevel<=maxi)
		cout<<root->data<<" ";
	printLevels(root->left,currLevel+1,mini,maxi);
	printLevels(root->right,currLevel+1,mini,maxi);
}

void printLevelsRec(BinaryTreeNode<int>* root,int mini,int maxi)
{
	if(root==NULL)
		return;
	queue<BinaryTreeNode<int>*> q;
	q.push(root);
	int level=1;
	while(1)
	{
		int size=q.size();
		if(size==0 || level>maxi)
			break;
		while(size>0)
		{
			BinaryTreeNode<int>* front=q.front();
			q.pop();
			if(level>=mini && level<=maxi)
			{
				cout<<front->data<<" ";
			}
			if(front->left)
				q.push(front->left);
			if(front->right)
				q.push(front->right);
			size--;
		}
		level++;
	}
}


int maximumWidth(BinaryTreeNode<int>* root)
{
	int maxWidth=0;
	if(root==NULL)
		return maxWidth;
	queue<BinaryTreeNode<int>*> q;
	q.push(root);
	while(1)
	{
		int size=q.size();
		if(size==0)
			break;
		int width=0;
		while(size>0)
		{
			BinaryTreeNode<int>* front=q.front();
			q.pop();
			width++;
			if(front->left)
				q.push(front->left);
			if(front->right)
				q.push(front->right);
			size--;
		}
		if(width>maxWidth)
			maxWidth=width;
	}
	return maxWidth;
}
*/
/*
bool checkMirror(BinaryTreeNode<int>* root1,BinaryTreeNode<int>* root2)
{
	if(root1 && root2)
		return true;
	if(root1 || root2)
	{
		return false;
	}
	return (root1->data==root2->data) && (checkMirror(root1->left,root2->right)) &&
	 (checkMirror(root1->right,root2->left));
}


bool checkMirrorStructure(BinaryTreeNode<int>* root1,BinaryTreeNode<int>* root2)
{
	if(root1==NULL && root2==NULL)
		return true;
	if(root1==NULL || root2==NULL)
		return false;
	return checkMirrorStructure(root1->left,root2->right) && checkMirrorStructure(root1->right,root2->left);
}

bool checkFoldable(BinaryTreeNode<int>* root)
{
	if(root==NULL)
		return true;
	bool check=checkMirrorStructure(root->left,root->right);
	return check;
}

bool isIsomorphic(BinaryTreeNode<int>* root1,BinaryTreeNode<int>* root2)
{
	if(root1==NULL && root2==NULL)
		return true;
	if(root1==NULL || root2==NULL)
		return false;
	if(root1->data!=root2->data)
		return false;
	return ((isIsomorphic(root1->left,root2->left)) && (isIsomorphic(root2->right,root1->right))) || 
		((isIsomorphic(root1->left,root2->right)) && (isIsomorphic(root1->right,root2->left)));
}
*/

void doubleTree(BinaryTreeNode<int>* root)
{
	if(root==NULL)
		return;
	BinaryTreeNode<int>* newLeft=new BinaryTreeNode<int>(root->data);
	BinaryTreeNode<int>* temp=root->left;
	root->left=newLeft;
	newLeft->left=temp;
	doubleTree(root->left->left);
	doubleTree(root->right);
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
/*
			1
		  /   \
		 2     3
		/ \   / \
	   4   5 6   7
	        / \
	       8   9

*/
// 2 7 5 2 6 -1 9 -1 -1 5 11 4 -1 -1 -1 -1 -1 -1 -1

/*
			2
		   / \
		  7   5
		 / \   \
		2   6   9
		   / \  /
		  5  11 4

*/

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	BinaryTreeNode<int>* root=takeInputLevelWise();
	/*
    BinaryTreeNode<int>* root1=takeInputLevelWise();
    BinaryTreeNode<int>* root2=takeInputLevelWise();
    
    cout<<endl;
    cout<<"Preorder: ";
    preOrder(root);
    
    cout<<endl<<"Inorder: ";
    inOrder(root);
    
    cout<<endl<<"Postorder: ";
    postOrder(root);
    cout<<endl;
    
    cout<<"Sum of all nodes: "<<sumOfAllNodes(root)<<endl;
    
    cout<<"Difference between Even Odd values: "<<getDifferenceEvenOddValues(root)<<endl;
    
    cout<<"Number of nodes: "<<numNodes(root)<<endl;
    
    cout<<"Number of leaf Nodes: "<<numLeafNodes(root)<<endl;
    
    cout<<"Height of tree: "<<height(root)<<endl;
	
	cout<<"Elements at given level: ";
	printElementsAtGivenLevel(root,3);
	cout<<endl;
	
	

	printLevelOrderQueue(root);
	
	reverseLevelOrderRec(root);

	reverseLevelOrderWithoutRec(root);
	
	int max_level=0;
	leftView(root,1,&max_level);
	cout<<endl;
	int max_level1=0;
	rightView(root,1,&max_level1);
	
	inOrderIterative(root);
    
    BinaryTreeNode<int>* temp=mirror(root);
    preOrder(temp);
	*/
	/*
	//cout<<isIdentical(root1,root2);

	//cout<<getLevelOfANode(root,11);

	//topView(root);

	//printBoundary(root);

	//verticalOrderTraversal(root);

	//verticalSum(root);

	//cout<<searchElement(root,11);

	//printSpiral(root);

	//printLevelsRec(root,3,4);

	//cout<<maximumWidth(root);

	//cout<<checkMirror(root1,root2);

	//cout<<checkMirrorStructure(root1,root2);

	//cout<<checkFoldable(root);

	//cout<<isIsomorphic(root1,root2);

	//cout<<getWidthOfGivenLevel(root,2);

	//doubleTree(root);
	//printLevelOrderQueue(root);

	*/
    
    return 0;
}