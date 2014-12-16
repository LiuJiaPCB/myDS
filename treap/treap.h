#ifndef _Treap_H
#define _Treap_H 
struct TreapNode;
typedef TreapNode* Node;
struct TreapNode
{
	int key;
	int priority;//增加优先级 
	Node Left;
	Node Right;	
};

struct treap
{
	Node root;
};
void InsertTreap(Node *root,int data,int priority);
void DeleteTreap(Node *root,int data,int priority);
void traverse_of_order(Node root);
void left_rotate(Node *node);
void right_rotate(Node *node);

#endif
