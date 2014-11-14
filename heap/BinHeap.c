#include"BinHeap.h"
#include<stdio.h>
#include<stdlib.h>

PriorityQueue Initialize(int MaxElements)
{
	PriorityQueue H;
	H = (PriorityQueue)malloc(sizeof(struct HeapStruct));
	if(H==NULL)
	{
		exit(-1);
	}
	H->Elements = (ElementType*)malloc((MaxElements+1)*sizeof(ElementType));
	if(H->Elements==NULL)
	{
		exit(-1);
	}
	H->Capacity = MaxElements;
	H->Size = 0;
	H->Elements[0] = -1;//MinData是标记，必须比堆中的所有值都小 
	return H; 
}

void Destory(PriorityQueue H)
{
	PriorityQueue temp = H;
	free(temp);
	H = NULL;
}

void MakeEmpty(PriorityQueue H);
void Insert(ElementType X,PriorityQueue H)
{
	int i;
	if(IsFull)
	{
		return;
	}
	for(i==++H->Size;H->Elements[i/2]>X;i/=2)
	{
		H->Elements[i] = H->Elements[i/2];
	}
	H->Elements[i] = X;
}
 
ElementType DeleteMin(PriorityQueue H)
{
	int i,Child;
	ElementType MinElement,LastElement;
	if(IsEmpty(H))
	{
		exit(-1);
	}
	MinElement = H->Elements[1];
	LastElement = H->Elements[H->Size];
	H->Size--;
	for(i=1;i*2<=H->Size;i=Child)
	{
		Child = i*2;
		if(Child != H->Size&&H->Elements[Child+1]<H->Elements[Child])
		{
			Child++;
		}
		if(LastElement > H->Elements[Child])
		{
			H->Elements[i] = H->Elements[Child];
		}
		else
		{
			break;
		}
	}
	H->Elements[i]=LastElement;
	return MinElement;
}

ElementType FindMin(PriorityQueue H)
{
	if(!IsEmpty(H))
	{
		return H->Elements[1];
	} 	 
}

int IsEmpty(PriorityQueue H)
{
	return H->Size == 0;
}

int IsFull(PriorityQueue H)
{
	return H->Size == H->Capacity; 
}
