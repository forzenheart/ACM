#include <iostream>
#include <cstdio>

using namespace std;

class Node{
	public:
		Node()
		{}

		Node(char data, Node* left, Node* right)
			:
				_data(data), _left(left), _right(right)
	{}
		char _data;
		Node* _left;
		Node* _right;
};



Node Tree[30];

void inorder(Node* p)
{
	if(*p._left || *p._right)
	{
		inorder(p->_left);
		printf("%c", p->_data);
		inorder(p->_right);
	}
	else
		return;
}

void preorder(Node* p)
{
	if(*p._left || *p._right)
	{
		printf("%c", p->_data);
		preorder(p->_left);
		preorder(p->_right);
	}
	else
		return;
}

void postorder(Node* p)
{
	if(*p._left || *p._right)
	{
		preorder(p._left);
		preorder(p._right);
		printf("%c", p._data);
	}
	else
		return;
}

int main()
{
	Node tree;
	tree._data = 'A';
	tree._left = NULL;
	tree._right = NULL;

	Node left;
	left._data = 'B';
	left._left = NULL;
	left._right = NULL;

	Node right;
	right._data = 'C';
	right._left = NULL;
	rihgt._right = NULL;

	Node left1;
	left1._data = 'D';
	left1._left = NULL;
	left1._right = NULL;

	Node right1;
	right1._data = 'E';
	right1._left = NULL;
	rihgt1._right = NULL;


	tree._left = &left;
	tree._rihgt = &right;
	left._left = &left1;
	left._rihgt = &right1;

	inorder(&tree);

	return 0;
}
