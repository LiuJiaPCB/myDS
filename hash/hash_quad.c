#include"hash_quad.h"
#include<stdio.h>
#include<stdlib.h>

HashTable InitializeTable(int TableSize)
{
	HashTable H;
	int i;
	
	H=(HashTable)malloc(sizeof(struct HashTbl));
	if(H==NULL)
	{
		exit(1); 
	}
	H->TheCells = (Cell*)malloc(sizeof(Cell)*H->TableSize);
	if(H->TheCells==NULL)
	{
		exit(1);
	} 
	for(i=0;i<H->TableSize;i++)
	{
		H->TheCells[i].Info=Empty;
	}
	return H;
}

void DestoryTable(HashTable H)
{
	
}
/*找到插入的位置*/ 
Position Find(ElementType Key,HashTable H)
{
	Position CurrentPos;
	int CollisionNum = 0;
	CurrentPos = Hash(Key,H->TableSize);
	while(H->TheCells[CurrentPos].Info!=Empty&&H->TheCells[CurrentPos].Element!=Key)
	{
		CurrentPos += 2*(++CollisionNum)-1;
		if(CurrentPos>=H->TableSize)
		{
			CurrentPos-=H->TableSize;
		} 
	}
	return CurrentPos;
}
/*平方散列探测散列表*/ 
void Insert(ElementType Key,HashTable H)
{
	Position Pos;
	Pos = Find(Key,H);
	if(H->TheCells[Pos].Info!=Legitimate)
	{
		H->TheCells[Pos].Info = Legitimate;
		H->TheCells[Pos].Element = Key; 
	}
} 

ElementType Retrieve(Position P,HashTable H)
{
	
}

HashTable Rehash(HashTable H)
{
	int i,OldSize;
	Cell *OldCells;
	
	HashTable OldH = H; //增加，后面用来释放内存 
	OldCells = H->TheCells;
	OldSize = H->TableSize;
	
	H = InitializeTable(2*OldSize);
	for(i=0;i<OldSize;i++)
	{
		if(OldCells[i].Info == Legitimate)
		{
			Insert(OldCells[i].Element,H);
		}
	}
	free(OldCells);
	free(OldH);//防止内存泄露 
	return H;
}
