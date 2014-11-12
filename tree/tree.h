#ifndef _Tree_H
#define _Tree_H

#define Max(a,b) ((a)>(b)?(a):(b))
struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;
typedef int ElementType;

SearchTree MakeEmpty(SearchTree T);
Position Find(ElementType X,SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(ElementType X,SearchTree T);
SearchTree Delete(ElementType X,SearchTree T);
void PrintTree(SearchTree T);
int Height(SearchTree T); 
ElementType Retrieve(Position P);

#endif

 
