#include "btree.h"
#include <queue>
#define OK 1
#define ERROR -1

/*
   int createTree(BNode * root);
   int preOrder(BNode * root);	//先序遍历
   int inOrder(BNode * root);
   int postOrder(BNode * root);
   int levelOrder(BNode * root);//层次遍历

   int insertBTree(BNode **root, int elem);
   int deleteBTreeByElem(BNode * root, int elem);
   int createBSTree(BNode ** root, int data[], int len);

   BNode * getParentNode(BNode * root, BNode *p);

   BNode * searchBSTree(BNode * root, int elem);
   BNode * getSuccessor(BNode * root);//取后继
   BNode * getPresuccessor(BNode * root);
   BNode * getMininum(BNode * root);
   BNode * getMaxinum(BNode * root);

   int getTreeHeight(BNode * root);
   int getLeafNum(BNode * root);

   void destroyBTee(BNode * root);
*/
BTree::BTree(void)
{
}

BTree::~BTree(void)
{
}

int BTree::createTree(BNode * root)
{
	int value;
	std::cin >> value;
	if(value == -1)
	{
		root = NULL;
	}
	else
	{
		BNode * newNode = new BNode();
		//test
		std::cout << newNode << std::endl;
		newNode->data = value;
		std::cout << "generate left tree: " << std::endl;
		createTree(root->lchild);

		std::cout << "generate right tree: " << std::endl;
		createTree(root->rchild);
	}

	return OK;
}

int BTree::preOrder(BNode* root)
{
	if(root == NULL)
	{
		std::cout << "This tree is null!" << std::endl;
		return ERROR;
	}
	std::cout << root -> data << "\t";
	preOrder(root -> lchild);
	preOrder(root -> rchild);

	return OK;
}

int BTree::inOrder(BNode* root)
{
	if(root == NULL)
	{
		std::cout << "This tree is NULL!" << std::endl;
		return ERROR;
	}
	inOrder(root -> lchild);
	std::cout << root -> data << "\t";
	inOrder(root -> rchild);
	return OK;
}

int BTree::postOrder(BNode* root)
{
	if(root == NULL)
	{
		std::cout << "This tree is NULL" << std::endl;
		return ERROR;
	}
	postOrder(root -> lchild);
	postOrder(root -> rchild);
	std::cout << root -> data << "\t";
	return OK;
}




BNode* BTree::getParentNode(BNode * root, BNode *p)
{

}

int main(void)
{
	BNode *root;
	BTree mytree;
	mytree.createTree(root);

	return 0;
}
