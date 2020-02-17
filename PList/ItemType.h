#ifndef ITEMTYPE_H
#define ITEMTYPE_H

const int MAX_ITEMS = 100000000;

enum RelationType
{
	LESS, GREATER, EQUAL
};

class ItemType
{
public:
	ItemType();
	~ItemType();

	RelationType ComparedTo(ItemType item);

	void SetData(int data_) { data = data_; };
	int GetData() { return data; };

private:
	int data;
};

#endif // !ITEMTYPE_H

