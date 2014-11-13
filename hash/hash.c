#include"hash.h"
#include<stdio.h>
#include<stdlib.h>

Index Hash(int Key,int TableSize)
{
   /*此处填写哈希函数*/	
} 

HashTable InitializeTable(int TableSize)
{
	HashTable H;
	int i;

	H = (HashTable)malloc(sizeof(struct HashTbl));
	if(H==NULL)
	{
		exit(-1);
	}
	H->TableSize = TableSize;
	H->TheLists = (List*)malloc(sizeof(List)*H->TableSize);
	if(H->TheLists==NULL)
	{
		exit(-1);
	}
	for(i=0;i<H->TableSize;++i)
	{
		H->TheLists[i] = (List)malloc(sizeof(struct ListNode));
		if(H->TheLists[i] == NULL)
		{
			exit(-1);
		}
		else
		{
			H->TheLists[i]->Next = NULL; 
		}
	}
	
	return H;
}

void DestoryTable(HashTable H)
{
	
}

Position Find(ElementType Key,HashTable H)
{
	Position P;
	List L;
	
	L = H->TheLists[Hash(Key,H->TableSize)];
	P = L->Next;
	while(P!=NULL&&P->Element!=Key)
	{
		P = P->Next;
	}
	return P;
}

void Insert(ElementType Key,HashTable H)
{
	Position Pos,NewCell;
	List L;
	
	Pos = Find(Key,H);
	if(Pos==NULL)
	{
		NewCell = (Position)malloc(sizeof(struct ListNode));
		if(NewCell==NULL)
		{
			exit(-1);
		}
		else
		{
			L = H->TheLists[Hash(Key,H->TableSize)];
			/*头插法*/ 
			NewCell->Next = L->Next;
			NewCell->Element = Key;
			L->Next = NewCell; 
		}
	}
}
ElementType Retrieve(Position P)
{
	
}
