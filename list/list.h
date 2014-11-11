#ifndef _LIST_H
#define _LIST_H

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Position;
typedef PtrToNode List;
typedef int ElementType;

List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position p,List L);
Position Find(ElementType X,List L);
void Delete(ElementType X,List L);
Position FindPrevious(ElementType X,List L);
void Insert(ElementType X,List L,Position P);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);

#endif  /* __List_H_*/ 
