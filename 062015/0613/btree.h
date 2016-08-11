/*************************************************************************
	> File Name: btree.h
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Sat 13 Jun 2015 11:08:33 AM CST
 ************************************************************************/

#ifndef __BTREE_H__
#define __BTREE_H__

#include<iostream>

struct BNode
{
	int data;
	BNode * lchild;
	BNode * rchild;
};

class BTree
{
	public:
		BTree(void);
		~BTree(void);

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

};




#endif
