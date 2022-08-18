#include "RedBlackTree.h"
template<class Type>
RedBlackTree<Type>::RedBlackTree():Tree<Type>()
{
	tempROOT = new Node<Type>;
	tempROOT->colour = 'B';
	tempROOT->leftChild = nullptr;
	tempROOT->rightChild = nullptr;
	Tree<Type>::root = tempROOT;
}
template<class Type>
RedBlackTree<Type>::~RedBlackTree()
{}
template<class Type>
void RedBlackTree<Type>::inorderWrapper(Node<Type>* temp)
{
	if (temp != tempROOT)
	{
		inorderWrapper(temp->leftChild);
		cout << " -> " << temp->data;
		if (temp->colour == 'R')
		{
			cout << " Red ";
		}
		else
		{
			cout << " Black ";
		}
		inorderWrapper(temp->rightChild);
	}
}
template<class Type>
void RedBlackTree<Type>::inorder()
{
	cout << "\n--------------------------------------------------------------------------\n";
	inorderWrapper(Tree<Type>::root);
	cout << "\n--------------------------------------------------------------------------\n";
}
template<class Type>
void RedBlackTree<Type>::preorderWrapper(Node<Type>* temp)
{
	if (temp != tempROOT)
	{
		cout << " -> " << temp->data;
		if (temp->colour == 'R')
		{
			cout << " Red ";
		}
		else
		{
			cout << " Black ";
		}
		preorderWrapper(temp->leftChild);
		preorderWrapper(temp->rightChild);
	}
}
template<class Type>
void RedBlackTree<Type>::preorder()
{
	cout << "\n--------------------------------------------------------------------------\n";
	preorderWrapper(Tree<Type>::root);
	cout << "\n--------------------------------------------------------------------------\n";
}
template<class Type>
void RedBlackTree<Type>::postorderWrapper(Node<Type>* temp)
{
	if (temp != tempROOT) 
	{
		postorderWrapper(temp->leftChild);
		postorderWrapper(temp->rightChild);
		cout << " -> " << temp->data;
		if (temp->colour == 'R')
		{
			cout << " Red ";
		}
		else
		{
			cout << " Black ";
		}
	}
}
template<class Type>
void RedBlackTree<Type>::postorder()
{
	cout << "\n--------------------------------------------------------------------------\n";
	postorderWrapper(Tree<Type>::root);
	cout << "\n--------------------------------------------------------------------------\n";
}
template<class Type>
void RedBlackTree<Type>::selfInorderWrapper(Node<Type>* temp)
{
	if (temp != tempROOT)
	{
		selfInorderWrapper(temp->rightChild);
		cout << " -> " << temp->data;
		if (temp->colour == 'R')
		{
			cout << " Red ";
		}
		else
		{
			cout << " Black ";
		}
		selfInorderWrapper(temp->leftChild);
	}
}
template<class Type>
void RedBlackTree<Type>::selfInorder()
{
	cout << "\n--------------------------------------------------------------------------\n";
	selfInorderWrapper(Tree<Type>::root);
	cout << "\n--------------------------------------------------------------------------\n";
}
template<class Type>
void RedBlackTree<Type>::selfPreorderWrapper(Node<Type>* temp)
{
	if (temp != tempROOT)
	{
		selfPreorderWrapper(temp->rightChild);
		selfPreorderWrapper(temp->leftChild);
		cout << " -> " << temp->data;
		if (temp->colour == 'R')
		{
			cout << " Red ";
		}
		else
		{
			cout << " Black ";
		}
	}
}
template<class Type>
void RedBlackTree<Type>::selfPreorder()
{
	cout << "\n--------------------------------------------------------------------------\n";
	selfPreorderWrapper(Tree<Type>::root);
	cout << "\n--------------------------------------------------------------------------\n";
}
template<class Type>
void RedBlackTree<Type>::selfPostOrderWrapper(Node<Type>* temp)
{
	if (temp != tempROOT)
	{
		cout<<" -> " << temp->data;
		if (temp->colour == 'R')
		{
			cout << " Red " ;
		}
		else
		{
			cout << " Black " ;
		}
		selfPostOrderWrapper(temp->rightChild);
		selfPostOrderWrapper(temp->leftChild);
	}
}
template<class Type>
bool RedBlackTree<Type>::emptyTree()
{
	if (tempROOT == Tree<Type>::root)
	{
		if ((Tree<Type>::root->leftChild == nullptr && Tree<Type>::root->rightChild == nullptr) && (tempROOT->leftChild == nullptr && tempROOT->rightChild == nullptr))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}
template<class Type>
void RedBlackTree<Type>::selfPostOrder()
{
	selfPostOrderWrapper(Tree<Type>::root);
}
template<class Type>
bool RedBlackTree<Type>::readFile()
{
	Type val;
	ifstream fin;
	fin.open("input.txt", ios::in);
	if (!fin.is_open())
	{
		cout << "File is not found...!";
		return false;
	}
	else
	{
		while (!fin.eof())
		{
			fin >> val;
			insert(val);
		}
		fin.close();
		return true;
	}
}
template<class Type>
void RedBlackTree<Type>::displayTreeWrapper(Node<Type>* temp, int level)
{
	int i;
	HANDLE colors = GetStdHandle(STD_OUTPUT_HANDLE);
	if (temp != tempROOT)
	{
		displayTreeWrapper(temp->rightChild, level + 1);
		cout << endl;
		if (temp == Tree<Type>::root)
		{
			cout << "Root->:  ";
		}
		else
		{
			for (i = 0; i < level; i++)
				cout << "       ";
		}
		if (temp->colour == 'R')
		{
			SetConsoleTextAttribute(colors, 4);
			cout << temp->data;
			cout << " Red " << endl;
			SetConsoleTextAttribute(colors, 7);
		}
		else
		{
			cout << temp->data;
			cout << " Black " << endl;
		}
		displayTreeWrapper(temp->leftChild, level + 1);
	}
}
template<class Type>
void RedBlackTree<Type>::displayTree()
{
	cout << "\n--------------------------------------------------------------------------\n";
	displayTreeWrapper(Tree<Type>::root, 1);
	cout << "\n--------------------------------------------------------------------------";
}
template<class Type>
bool RedBlackTree<Type>::searchWrapper(Node<Type>* temp, Type val)
{
	if (temp == nullptr)
	{
		return false;
	}
	if (val == temp->data)
	{
		return true;
	}
	if (val < temp->data)
	{
		return searchWrapper(temp->leftChild, val);
	}
	else
	{
		return searchWrapper(temp->rightChild, val);
	}
}
template<class Type>
bool RedBlackTree<Type>::search(Type val)
{
	return searchWrapper(Tree<Type>::root,val);
}
template<class Type>
Node<Type>* RedBlackTree<Type>::parentNodeWrapper(Node<Type>* temp, Type val)
{
	if (temp == nullptr)
	{
		return nullptr;
	}
	else if ((temp->rightChild != nullptr && temp->rightChild->data == val) || (temp->leftChild != nullptr && temp->leftChild->data == val))
	{
		return temp;
	}
	else if (temp->data > val)
	{
		return parentNodeWrapper(temp->leftChild, val);
	}
	else
	{
		return parentNodeWrapper(temp->rightChild, val);
	}
}
template<class Type>
Node<Type> * RedBlackTree<Type>::getRoot(Node<Type>* temp)
{
	return temp;
}
template<class Type>
Node<Type>* RedBlackTree<Type>::grandparentNode(Type val)
{
	Node<Type>* temp = parentNodeWrapper(Tree<Type>::root, val);
	return parentNodeWrapper(Tree<Type>::root, temp->data);
}
template<class Type>
Node<Type>* RedBlackTree<Type>::parentNode(Type val)
{
	return parentNodeWrapper(Tree<Type>::root, val);
}
template<class Type>
Node<Type>* RedBlackTree<Type>::siblingOfparentNode(Type val)
{
	Node<Type>* temp = parentNodeWrapper(Tree<Type>::root, val);
	Node<Type>* grandParent = parentNodeWrapper(Tree<Type>::root, temp->data);
	if (grandParent->leftChild->leftChild != nullptr && grandParent->leftChild->leftChild->data == val)
	{
		return grandParent->rightChild;
	}
	else if (grandParent->leftChild->rightChild != nullptr && grandParent->leftChild->rightChild->data == val)
	{
		return grandParent->rightChild;
	}
	else if (grandParent->rightChild->rightChild != nullptr && grandParent->rightChild->rightChild->data == val)
	{
		return grandParent->leftChild;
	}
	else if (grandParent->rightChild->leftChild != nullptr && grandParent->rightChild->leftChild->data == val)
	{
		return grandParent->leftChild;
	}
}
template<class Type>
Type RedBlackTree<Type>::minimumValue()
{
	Node<Type>* temp = minimum(Tree<Type>::root);
	return temp->data;
}
template<class Type>
Type RedBlackTree<Type>::maximumValue()
{
	Node<Type>* temp = maximum(Tree<Type>::root);
	return temp->data;
}
template<class Type>
void RedBlackTree<Type>::deleteAValue(Type val)
{
	deleteNodeWrapper(Tree<Type>::root, val);
}
template<class Type>
void RedBlackTree<Type>::deleteNodeWrapper(Node<Type>* node,Type key)
{
	Node<Type>* z = tempROOT;
	Node<Type>* x;
	Node<Type>* y;
	while (node != tempROOT)
	{
		if (node->data == key)
		{

			z = node;

		}

		if (node->data <= key) {

			node = node->rightChild;

		}
		else {

			node = node->leftChild;

		}

	}

	if (z == tempROOT) {

		cout << "Key not found in the tree" << endl;

		return;

	}

	y = z;
	char yOriginalColour = y->colour;

	if (z->leftChild == tempROOT)
	{
		x = z->rightChild;
		RedBlackChangeShape(z, z->rightChild);
	}
	else if (z->rightChild == tempROOT)
	{
		x = z->leftChild;
		RedBlackChangeShape(z, z->leftChild);
	}
	else
	{
		y = minimum(z->rightChild);
		yOriginalColour = y->colour;
		x = y->rightChild;
		Node<Type>* yp = parentNode(y->data);
		Node<Type>* xp = parentNode(x->data);
		if (yp == z)
		{
			xp = y;
		}
		else
		{
			RedBlackChangeShape(y, y->rightChild);
			y->rightChild = z->rightChild;
			Node<Type>* yrp = parentNode(y->rightChild->data);
			yrp = y;
		}
		RedBlackChangeShape(z, y);
		y->leftChild = z->leftChild;
		Node<Type>* ylp = parentNode(y->leftChild->data);
		ylp = y;
		y->colour = z->colour;
	}
	delete z;
	if (yOriginalColour == 'B')
	{
		deleteFix(x);
	}
}
template<class Type>
void RedBlackTree<Type>::deleteFix(Node<Type>* tempX)
{
	Node<Type>* s;
	Node<Type>* tempXp = parentNode(tempX->data);
	while (tempX != Tree<Type>::root && tempX->colour == 'B')
	{
		if (tempX == tempXp->leftChild)
		{
			s = tempXp->rightChild;
			if (s->colour == 'R')
			{
				s->colour = 'B';
				tempXp->colour = 'R';
				leftRotate(tempXp);
				s = tempXp->rightChild;
			}
			if (s->leftChild->colour == 'B' && s->rightChild->colour == 'B')
			{
				s->colour = 'R';
				tempX = tempXp;
			}
			else
			{
				if (s->rightChild->colour == 'B')
				{
					s->leftChild->colour = 'B';
					s->colour = 'R';
					rightRotate(s);
					s = tempXp->rightChild;
				}
				s->colour = tempXp->colour;
				tempXp->colour = 'B';
				s->rightChild->colour = 'B';
				leftRotate(tempXp);
				tempX = Tree<Type>::root;
			}
		}
		else
		{
			s = tempXp->leftChild;
			if (s->colour == 'R')
			{
				s->colour = 'B';
				tempXp->colour = 'R';
				rightRotate(tempXp);
				s = tempXp->leftChild;
			}
			if (s->rightChild->colour == 'B' && s->rightChild->colour == 'B')
			{
				s->colour = 'R';
				tempX = tempXp;
			}
			else
			{
				if (s->leftChild->colour == 'B')
				{
					s->rightChild->colour = 'B';
					s->colour = 'R';
					leftRotate(s);
					s = tempXp->leftChild;
				}
				s->colour = tempXp->colour;
				tempXp->colour = 'B';
				s->leftChild->colour = 'B';
				rightRotate(tempXp);
				tempX = Tree<Type>::root;
			}
		}

	}
	tempX->colour = 'B';
}
template<class Type>
void RedBlackTree<Type>::destroyWholeTree(Node<Type>* temp)
{
	if (temp != tempROOT)
	{
		destroyWholeTree(temp->leftChild);
		destroyWholeTree(temp->rightChild);
		delete temp;
		temp = nullptr;
	}
}
template<class Type>
void RedBlackTree<Type>::destroyRBTree()
{
	destroyWholeTree(Tree<Type>::root);
	Tree<Type>::root = tempROOT;
}
template<class Type>
Type RedBlackTree<Type>::getParentValue(Type val)
{
	if (getRoot(parentNode(val)) != nullptr)
	{
		return getRoot(parentNode(val))->data;
	}
	else
	{
		return false;
	}
}
template<class Type>
void RedBlackTree<Type>::deleteGreaterThanX(Type val)
{
	Type maxVal = maximumValue();
	for (int i = val; i <=maxVal; i++)
	{
		if (search(i)==true)
		{
			cout << "This value " << i << " has been deleted from Red-Black Tree.\n";
			deleteAValue(i);
		}
	}
}
/*----------------------------------------------------------------------------------------*/
template<class Type>
void RedBlackTree<Type>::insert(Type val)
{
	Node<Type>* node = new 	Node<Type>;
	Node<Type>* nodeParent = new Node<Type>;
	nodeParent = parentNode(node->data);
	nodeParent = nullptr;
	node->data = val;
	node->leftChild = tempROOT;
	node->rightChild = tempROOT;
	node->colour = 'R';
	Node<Type>* tempY = nullptr;
	Node<Type>* tempX = this->root;
	while (tempX != tempROOT) 
	{
		tempY = tempX;
		if (node->data < tempX->data) 
		{
			tempX = tempX->leftChild;
		}
		else {
			tempX = tempX->rightChild;
		}
	}
	nodeParent = tempY;
	if (tempY == nullptr)
	{
		Tree<Type>::root = node;
	}
	else if (node->data < tempY->data) 
	{
		tempY->leftChild = node;
	}
	else 
	{
		tempY->rightChild = node;
	}
	if (nodeParent == nullptr)
	{
		node->colour = 'B';
		return;
	}
	Node<Type>* nodeGrandParent = grandparentNode(node->data);
	if (nodeGrandParent == nullptr) 
	{
		return;
	}
	insertFix(node);
}
template<class Type>
void RedBlackTree<Type>::insertFix(Node<Type>* tempK)
{
	Node<Type>* tempU;
	Node<Type>* tempKP = parentNode(tempK->data);
	Node<Type>* tempKGP = grandparentNode(tempK->data);
	while (tempKP->colour == 'R')
	{
		if (tempKP == tempKGP->rightChild) 
		{
			tempU = tempKGP->leftChild;
			if (tempU->colour == 'R') {
				tempU->colour = 'B';
				tempKP->colour = 'B';
				tempKGP->colour = 'R';
				tempK = tempKGP;
			}
			else 
			{
				if (tempK == tempKP->leftChild) 
				{
					tempK = tempKP;
					rightRotate(tempK);
				}
				tempKP->colour = 'B';
				tempKGP->colour = 'R';
				leftRotate(tempKGP);
			}
		}
		else 
		{
			tempU = tempKGP->rightChild;

			if (tempU->colour == 'R')
			{
				tempU->colour = 'B';
				tempKP->colour = 'B';
				tempKGP->colour = 'R';
				tempK = tempKGP;
			}
			else 
			{
				if (tempK == tempKP->rightChild)
				{
					tempK = tempKP;
					leftRotate(tempK);
				}
				tempKP->colour = 'B';
				tempKGP->colour = 'R';
				rightRotate(tempKGP);
			}
		}
		if (tempK == Tree<Type>::root) {
			break;
		}
	}
	Tree<Type>::root->colour = 'B';
}
template<class Type>
void RedBlackTree<Type>::leftRotate(Node<Type>* tempA) 
{
	Node<Type>* tempB = tempA->rightChild;
	tempA->rightChild = tempB->leftChild;
	if (tempB->leftChild != tempROOT)
	{
		Node<Type>* tempBLP = parentNode(tempB->leftChild->data);
		tempBLP = tempA;
	}
	Node<Type>* tempAP = parentNode(tempA->data);
	Node<Type>* tempBP = parentNode(tempB->data);
	tempBP = tempAP;
	if (tempAP == nullptr) 
	{
		this->root = tempB;
	}
	else if (tempA == tempAP->leftChild) 
	{
		tempAP->leftChild = tempB;
	}
	else 
	{
		tempAP->rightChild = tempB;
	}
	tempB->leftChild = tempA;
	tempAP = tempB;
}
template<class Type>
void RedBlackTree<Type>::rightRotate(Node<Type>* tempC) 
{
	Node<Type>* tempD = tempC->leftChild;
	tempC->leftChild = tempD->rightChild;
	if (tempD->rightChild != tempROOT)
	{
		Node<Type>* tempDRP = parentNode(tempD->rightChild->data);
		tempDRP = tempC;
	}
	Node<Type>* tempCP = parentNode(tempC->data);
	Node<Type>* tempDP = parentNode(tempD->data);
	tempDP = tempCP;
	if (tempCP == nullptr) 
	{
		Tree<Type>::root = tempD;
	}
	else if (tempC == tempCP->rightChild)
	{
		tempCP->rightChild = tempD;
	}
	else {
		tempCP->leftChild = tempD;
	}
	tempD->rightChild = tempC;
	tempCP = tempD;
}
template<class Type>
void RedBlackTree<Type>::RedBlackChangeShape(Node<Type>* tempU, Node<Type>* tempV)
{
	Node<Type>* tempUp = parentNode(tempU->data);
	if (tempUp == nullptr) 
	{
		Tree<Type>::root = tempV;
	}
	else if (tempU == tempUp->leftChild)
	{
		tempUp->leftChild = tempV;
	}
	else
	{
		tempUp->rightChild = tempV;
	}
	Node<Type>* tempVp = parentNode(tempV->data);
	tempVp = tempUp;
}
template<class Type>
Node<Type>* RedBlackTree<Type>::minimum(Node<Type>* temp)
{
	while (temp->leftChild != tempROOT)
	{
		temp = temp->leftChild;
	}
	return temp;
}
template<class Type>
Node<Type>* RedBlackTree<Type>::maximum(Node<Type>* temp)
{
	while (temp->rightChild != tempROOT)
	{
		temp = temp->rightChild;
	}
	return temp;
}