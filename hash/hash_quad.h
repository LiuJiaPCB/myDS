#ifndef _HashQuad_H
#define _HashQuad_H

typedef unsigned int Index;
typedef Index Position;

struct HashTbl;
typedef struct HashTbl *HashTable;
typedef int ElementType;
HashTable InitializeTable(int TableSize);
void DestoryTable(HashTable H);
Position Find(ElementType Key,HashTable H);
void Insert(ElementType Key,HashTable H);
ElementType Retrieve(Position P,HashTable H);
HashTable Rehash(HashTable H);

enum KindOfEntry{Legitimate,Empty,Deleted};

struct HashEntry
{
	ElementType Element;
	enum KindOfEntry Info;
};
typedef struct HashEntry Cell;
struct HashTbl
{
	int TableSize;
	Cell *TheCells;
};


#endif //_HashQuad_H 
