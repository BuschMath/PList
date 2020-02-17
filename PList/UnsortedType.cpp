#include "UnsortedType.h"
#include <new>

UnsortedType::UnsortedType()
{
	head = nullptr;
	pos = nullptr;
	length = 0;
}

UnsortedType::~UnsortedType()
{
	MakeEmpty();
}

void UnsortedType::MakeEmpty()
{
	Node* temp;

	while (head != nullptr)
	{
		temp = head;
		head = head->next;
		delete temp;
	}

	head = nullptr;

	length = 0;
}

bool UnsortedType::IsFull() const
{
	if (MAX_ITEMS < length + 1)
		return true;

	Node* loc;
	try
	{
		loc = new Node;
		delete loc;
		return false;
	}
	catch(std::bad_alloc e)
	{
		return true;
	}

	return false;
}

int UnsortedType::GetLength() const
{
	return length;
}

ItemType UnsortedType::GetItem(ItemType item, bool& found)
{
	bool moreToSearch;
	Node* loc;

	loc = head;
	found = false;
	moreToSearch = (loc != nullptr);

	while (moreToSearch && !found)
	{
		switch (item.ComparedTo(loc->info))
		{
		case LESS:
		case GREATER: loc = loc->next;
			moreToSearch = (loc != nullptr);
			break;
		case EQUAL: found = true;
			item = loc->info;
			break;
		}
	}

	return item;
}

void UnsortedType::PutItem(ItemType item)
{
	Node* loc;
	loc = new Node;
	loc->info = item;
	loc->next = head;
	head = loc;
	length++;
}

void UnsortedType::DeleteItem(ItemType item)
{
	Node* loc = head;
	Node* temp;

	if (RelationType::EQUAL == item.ComparedTo(head->info))
	{
		temp = loc;
		head = head->next;
	}
	else
	{
		while ((item.ComparedTo(loc->next->info)) != RelationType::EQUAL)
			loc = loc->next;

		temp = loc->next;
		loc->next = loc->next->next;
	}

	delete temp;
	length--;
}

void UnsortedType::ResetList()
{
	pos = nullptr;
}

ItemType UnsortedType::GetNextItem()
{
	if (pos == nullptr)
		pos = head;
	else if(pos->next != nullptr)
	{
		pos = pos->next;
	}

	return pos->info;
}

UnsortedType UnsortedType::Union(UnsortedType &list)
{
	UnsortedType* u = new UnsortedType;

	Node* loc = head;
	ItemType tempItem;
	bool match = false;

	while (loc != nullptr)
	{
		match = false;
		u->ResetList();

		for (int i = 0; i < u->GetLength(); i++)
		{
			if (u->GetNextItem().ComparedTo(loc->info) == RelationType::EQUAL)
				match = true;
		}

		if (!match)
			u->PutItem(loc->info);

		loc = loc->next;
	}

	list.ResetList();

	for (int i = 0; i < list.GetLength(); i++)
	{
		match = false;
		u->ResetList();
		tempItem.SetData(list.GetNextItem().GetData());

		for (int j = 0; j < u->GetLength(); j++)
		{
			if (u->GetNextItem().ComparedTo(tempItem) == RelationType::EQUAL)
				match = true;
		}

		if (!match)
			u->PutItem(tempItem);
	}

	return *u;
}
