#include "ItemType2.h"
#include <fstream>
#include <iostream>


ItemType2::ItemType2()
{
	num = 0;
}

RelationType2 ItemType2::ComparedTo(ItemType2 otherItem) const
{
	if (num < otherItem.num)
		return LESS1;
	else if (num > otherItem.num)
		return GREATER1;
	else return EQUAL1;
}




void ItemType2::Initialize2(int number)
{
	num = number;
}

void ItemType2::Print(std::ostream& out) const
// pre:  out has been opened.
// post: value has been sent to the stream out.
{

	out << num << endl;
	cout << num << " in list" << endl;

}