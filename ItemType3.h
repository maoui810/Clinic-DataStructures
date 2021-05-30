#pragma once
#include <fstream>

enum RelationType3 { LESS7, GREATER8, EQUAL9 };
using namespace std;

class ItemType3
{
public:
	ItemType3();
	RelationType3 ComparedTo(ItemType3) const;
	void Print(std::ostream&) const;
	void Initialize(string name);


private:
	string value;
};