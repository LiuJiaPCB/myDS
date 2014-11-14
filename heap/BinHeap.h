#ifndef _BinHeap_H
#define _BinHeap_H

struct HeapStruct;
typedef struct HeapStruct *PriorityQueue;
typedef int ElementType; 

PriorityQueue Initialize(int MaxElements);
void Destory(PriorityQueue H);
void MakeEmpty(PriorityQueue H);
void Insert(ElementType X,PriorityQueue H);
ElementType DeleteMin(PriorityQueue H);
ElementType FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
int IsFull(PriorityQueue H);

#endif

struct HeapStruct
{
	int Capacity;
	int Size;
	ElementType *Elements;
};
