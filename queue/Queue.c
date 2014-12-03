#include"Queue.h"
#include<stdio.h>
#include<stdlib.h>

struct QueueRecord
{
	int Capacity;
	int Front;
	int Rear;
	int Size;
	ElementType *Array;
};

int IsQEmpty(Queue Q)
{
	return Q->Size == 0;
}

int IsFull(Queue Q)
{
	return Q->Size == Q->Capacity; 
}
Queue CreateQueue(int MaxElements)
{
	Queue Q = (Queue)malloc(sizeof(Queue));
	Q->Array = (ElementType*)malloc(sizeof(ElementType)*MaxElements);
	Q->Capacity = MaxElements;
	return Q;
}
void DisposeQueue(Queue Q)
{
	free(Q->Array);
	free(Q); 
	
}
void MakeQEmpty(Queue Q)
{
	Q->Size = 0;
	Q->Front = 1;
	Q->Rear = 0;
	 
}

static int Succ(int Value,Queue Q)
{
	if(++Value == Q->Capacity)
	{
		Value = 0;
	}
	return Value;
}
void Enqueue(ElementType X,Queue Q)
{
	if(IsFull(Q))
	{
		return ;
	}
	else
	{
		Q->Size++;
		Q->Rear = Succ(Q->Rear,Q);
		Q->Array[Q->Rear] = X;
	}
}
ElementType Front(Queue Q)
{
	if(!IsQEmpty(Q))
	{
		return Q->Array[Q->Front];
	}
}
void Dequeue(Queue Q)
{
	if(!IsQEmpty(Q))
	{
		Q->Size--;
		Q->Front = Succ(Q->Front,Q);
	}
}
ElementType FrontAndDequeue(Queue Q)
{
	ElementType p = Front(Q);
	Dequeue(Q);
	return p;	
}

int main()
{   
    Queue Q = CreateQueue(5);
    MakeQEmpty(Q);
    Enqueue(1,Q);
    Enqueue(2,Q);
    Enqueue(3,Q);
    while(!IsQEmpty(Q))
    {
    	printf("%d\n",FrontAndDequeue(Q));
    }
    free(Q);
	return 0;
}
