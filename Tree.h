#pragma once
#include"Node.h"
template<class Type>
class Tree
{
protected:
	Node<Type>* root;
	Tree<Type>();
	~Tree<Type>();
	void destroyTree(Node<Type>*) ;
	virtual void insert(Type) = 0;
	virtual void inorder() = 0;
	virtual void preorder() = 0;
	virtual void postorder() = 0;
};

