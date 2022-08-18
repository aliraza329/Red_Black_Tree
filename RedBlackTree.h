#pragma once
#include"LinkTree.h"
template<class Type>
class RedBlackTree :public Tree<Type>
{
	bool searchWrapper(Node<Type>*, Type);
	void inorderWrapper(Node<Type>*);
	void preorderWrapper(Node<Type>*);
	void postorderWrapper(Node<Type>*);
	void selfInorderWrapper(Node<Type>*);
	void selfPreorderWrapper(Node<Type>*);
	void selfPostOrderWrapper(Node<Type>*);
	void displayTreeWrapper(Node<Type>*,int);
	void insertFix(Node<Type>*);
	void leftRotate(Node<Type>*);
	void rightRotate(Node<Type>*);
	void destroyWholeTree(Node<Type>*);
	Node<Type>* siblingOfparentNode(Type);
	Node<Type>* grandparentNode(Type);
	Node<Type>* parentNodeWrapper(Node<Type>*, Type);
	Node<Type>* tempROOT; // used to handle Root Node
	Type minimumValue();
	Type maximumValue();
	// Delete Functions
	Node<Type>* minimum(Node<Type>*);
	Node<Type>* maximum(Node<Type>*);
	void deleteNodeWrapper(Node<Type>*, Type);
	void RedBlackChangeShape(Node<Type>*,Node<Type>*);
	void deleteFix(Node<Type>*);
public:
	RedBlackTree();
	~RedBlackTree();
	void insert(Type);
	bool search(Type);
	void deleteAValue(Type);
	void inorder();
	void preorder();
	void postorder();
	void selfInorder();
	void selfPreorder();
	void selfPostOrder();
	void destroyRBTree();
	void deleteGreaterThanX(Type);
	Type getParentValue(Type);
	bool readFile();
	bool emptyTree();
	void displayTree();
	Node<Type>* getRoot(Node<Type>*);	
	Node<Type>* parentNode(Type);
};