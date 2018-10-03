#include <iostream>
#include <cstring>
using namespace std;

struct treeNode
{
	char data;
	treeNode* left;
	treeNode* right;
};

treeNode* root;

treeNode* MakeRootNode(char data, treeNode* leftNode, treeNode* rightNode)
{
	root = new treeNode;
	root->data = data;
	root->left = leftNode;
	root->right = rightNode;
	return root;
}

void PreOrder(treeNode* root)
{
	if(root!=NULL) {
		cout << root->data << " ";	// Data Read
		PreOrder(root->left);		// Left Node Move
		PreOrder(root->right);		// Right Node Move
	}
}

void InOrder(treeNode* root)
{
	if(root!=NULL)
	{
		InOrder(root->left);		// Left Node Move
		cout << root->data << " ";	// Data Read
		InOrder(root->right);		// Right Node Move
	}
}

void PostOrder(treeNode* root)
{
	if(root!=NULL)
	{
		PostOrder(root->left);		// Left Node Move
		PostOrder(root->right);		// Right Node Move
		cout << root->data << " ";	// Data Read
	}
}



int main()
{
	treeNode* TN7 = MakeRootNode('d',NULL,NULL);
	treeNode* TN6 = MakeRootNode('c',NULL,NULL);
	treeNode* TN5 = MakeRootNode('b',NULL,NULL);
	treeNode* TN4 = MakeRootNode('a',NULL,NULL);
	treeNode* TN3 = MakeRootNode('-',TN6,TN7);
	treeNode* TN2 = MakeRootNode('+',TN4,TN5);
	treeNode* TN1 = MakeRootNode('*',TN2,TN3);

	cout << "PreOrder: ";
	PreOrder(TN1);
  cout << endl;
	cout << "InOrder: ";
	InOrder(TN1);
  cout << endl;
	cout << "PostOrder: ";
	PostOrder(TN1);
  cout << endl;

	return 0;
}
