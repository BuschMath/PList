#ifndef UNSORTEDTYPE_H
#define UNSORTEDTYPE_H

#include "ItemType.h"

struct Node
{
	ItemType info;
	Node* next;
};

class UnsortedType
{
public:
	UnsortedType();
	~UnsortedType();

	void MakeEmpty();
	bool IsFull() const;
	int GetLength() const;
	ItemType GetItem(ItemType item, bool& found);
	void PutItem(ItemType item);
	void DeleteItem(ItemType item);
	void ResetList();
	ItemType GetNextItem();
	UnsortedType Union(UnsortedType &list);

private:
	Node* head;
	int length;
	Node* pos;

};

#endif // !UNSORTEDTYPE_H
