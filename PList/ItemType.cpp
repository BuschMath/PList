#include "ItemType.h"

ItemType::ItemType()
{
	data = 0;
}

ItemType::~ItemType()
{
}

RelationType ItemType::ComparedTo(ItemType item)
{
	if (data < item.data)
		return LESS;
	else if (data > item.data)
		return GREATER;
	return EQUAL;
}
