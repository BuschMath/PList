#include "ItemType.h"
#include "UnsortedType.h"

#include <iostream>

using namespace std;

int main()
{
	ItemType a, b, c, d, e, f, g, h, m, n;

	a.SetData(1);
	b.SetData(2);
	c.SetData(3);
	d.SetData(2);

	e.SetData(2);
	f.SetData(3);
	g.SetData(4);
	h.SetData(5);
	m.SetData(1);
	n.SetData(6);

	UnsortedType list1, list2;
	list1.PutItem(a);
	list1.PutItem(b);
	list1.PutItem(c);
	list1.PutItem(d);

	list2.PutItem(e);
	list2.PutItem(f);
	list2.PutItem(g);
	list2.PutItem(h);
	list2.PutItem(m);
	list2.PutItem(n);

	for (int i = 0; i < list1.GetLength(); i++)
	{
		cout << "List 1, item " << i << ": " << list1.GetNextItem().GetData() << endl;
	}

	for (int i = 0; i < list2.GetLength(); i++)
	{
		cout << "List 2, item " << i << ": " << list2.GetNextItem().GetData() << endl;
	}

	list1.ResetList();
	list2.ResetList();

	UnsortedType list3 = list1.Union(list2);

	list3.ResetList();

	for (int i = 0; i < list3.GetLength(); i++)
	{
		cout << "List 3, item " << i << ": " << list3.GetNextItem().GetData() << endl;
	}

	list2.ResetList();

	for (int i = 0; i < list2.GetLength(); i++)
	{
		cout << "List 2, item " << i << ": " << list2.GetNextItem().GetData() << endl;
	}

	list1.MakeEmpty();
	list2.MakeEmpty();
	list3.MakeEmpty();

	return 0;
}