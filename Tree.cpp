#include "Tree.h"
template<class Type>
Tree<Type>::Tree<Type>()
{
	this->root = nullptr;
}
template<class Type>
Tree<Type>::~Tree<Type>()
{
	if (!root)
	{
		destroyTree(this->root);
	}
}
template<class Type>
void Tree<Type>::destroyTree(Node<Type>* temp)
{
	if (temp)
	{
		if (temp->leftChild != nullptr)
		{
			destroyTree(temp->leftChild);
		}
		if (temp->rightChild != nullptr)
		{
			destroyTree(temp->rightChild);
		}
		delete root;
	}
}