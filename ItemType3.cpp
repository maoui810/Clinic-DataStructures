#include "ItemType3.h"

#include <fstream>
#include <iostream>


ItemType3::ItemType3()
{
	value = "";

}

RelationType3 ItemType3::ComparedTo(ItemType3 otherItem) const
{
	if (value < otherItem.value)
		return LESS7;
	else if (value > otherItem.value)
		return GREATER8;
	else return EQUAL9;
}




void ItemType3::Initialize(string name)
{
	value = name;
}


void ItemType3::Print(std::ostream& out) const
// pre:  out has been opened.
// post: value has been sent to the stream out.
{

	out << value << endl;
	cout << value << " in list" << endl;

}