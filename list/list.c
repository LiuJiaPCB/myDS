#include"list.h"
#include<stdlib.h>
#include<stdio.h>

struct Node
{
	ElementType Element;
	Position Next;
};

List MakeEmpty(List L)
{
	L = (List)malloc(sizeof(struct Node));
	if(L == NULL)
	{
		return 0;
	}
	L->Next = NULL;
	return L;
}

int IsEmpty(List L)
{
	return L->Next == NULL;
}

int IsLast(Position P,List L)
{
	return P->Next == NULL;
}

Position Find(ElementType X,List L)
{
	Position P = NULL;
	P = L->Next;
	while(P != NULL && P->Element != X)
	{
		P = P->Next;
	}
	
	return P;
}

Position FindPrevious(ElementType X,List L)
{
	Position P;
	P = L;
	while(P->Next != NULL && P->Next->Element != X)
	{
		P = P->Next;
	} 
	return P;
}

void DeleteList(ElementType X,List L)
{
	Position P,TmpCell;
	P = FindPrevious(X,L);
	
	if(!IsLast(P,L))
	{
		TmpCell = P->Next;
		P->Next = TmpCell->Next;
		free(TmpCell);
	}
}

void Insert(ElementType X,List L,Position P)
{
	Position TmpCell;
	
	TmpCell = (Position)malloc(sizeof(struct Node));
	if(TmpCell == NULL)
	{
		return ;
	}
	
	TmpCell->Element = X;
	TmpCell->Next = P->Next;
	P->Next = TmpCell; 
}

void DeleteList(List L)
{
	Position P,Tmp;
	
	P = L->Next;
	L->Next = NULL;
	while(P != NULL)
	{
		Tmp = P->Next;
		free(P);
		P = Tmp;
	}
}

