#pragma once
#include <fstream>

enum RelationType2 { LESS1, GREATER1, EQUAL1 };
using namespace std;

class ItemType2
{
public:
	ItemType2();
	RelationType2 ComparedTo(ItemType2) const;
	void Print(std::ostream&) const;

	void Initialize2(int number);
private:

	int num;
};