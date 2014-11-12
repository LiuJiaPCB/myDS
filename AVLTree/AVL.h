#ifndef _AvlTree_H
#define _AvlTree_H
#define Max(a,b) (a>b)?(a):(b)
struct AvlNode;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;
typedef int ElementType;

static int Height(Position P); 
AvlTree MakeEmpty(AvlTree T);
Position Find(ElementType X,AvlTree T);
Position FindMin(AvlTree T);
Position FindMax(AvlTree T);
AvlTree Insert(ElementType X,AvlTree T);
AvlTree Delete(ElementType X,AvlTree T);
/*单旋转从左向右*/ 
static Position SingleRotateWithLeft(Position K2);
/*单旋转从右向左*/ 
static Position SingleRotateWithRight(Position K2);
/*双旋转从左向右*/ 
static Position DoubleRotateWithLeft(Position K3);
/*双旋转从右向左*/ 
static Position DoubleRotateWithRight(Position K3);
ElementType Retrieve(Position P);

#endif

