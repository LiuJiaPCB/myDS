#ifndef _hash_h
#define _hash_h

struct ListNode;
typedef struct ListNode *Position;
struct HashTbl;
typedef struct HashTbl *HashTable;
typedef int ElementType;
/*散列函数返回值类型*/ 
typedef unsigned int Index;
HashTable InitializeTable(int TableSize);
void DestoryTable(HashTable H);
Position Find(ElementType Key,HashTable H);
void Insert(ElementType Key,HashTable H);
ElementType Retrieve(Position P);

struct ListNode
{
	ElementType Element;
	Position Next;
};

typedef Position List;
struct HashTbl
{
	int TableSize;
	List *TheLists;
};


#endif
