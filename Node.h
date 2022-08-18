#include"HelperFunction.h"
template<class Type>
struct Node
{
	Type data;
	Node* leftChild;
	Node* rightChild;
	char colour;
};