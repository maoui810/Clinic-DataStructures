#pragma once
#include <fstream>

enum RelationType { LESS, GREATER, EQUAL };

using namespace std;

class ItemType
{
public:
	ItemType();
	RelationType ComparedTo(ItemType) const;
	void Print(std::ostream&) const;
	void Print2() const;
	void Initialize(string name);


private:
	string value;


};
