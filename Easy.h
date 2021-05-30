#pragma once
#include<iostream>
#include"unsorted.h"


class Easy
{
public:

	void Available_M(ItemType& item, UnsortedType& linkedlist, ofstream& dataFile);
	
	
	void ShowList(ItemType& item, ItemType& itemNum, ItemType& ItemSpec, UnsortedType& linkedlist, ofstream& dataFile);


	bool IsListEmpty(UnsortedType& linkedList, bool& found);

	// finds names in list
	void Find(string name, ItemType& item, UnsortedType& linkedList, bool& found, ofstream& dataFile);

	void ShowList2(ItemType& item,  ItemType& ItemSpec, ItemType& itemNum, ItemType& ItemPatient, UnsortedType& linkedlist, ofstream& dataFile);
	
	void FindNextDoctor(ItemType& item, ItemType& itemNum, ItemType& ItemSpec, ItemType& patientName, UnsortedType& linkedlist, ofstream& dataFile, UnsortedType& linkedlist2, UnsortedType& linkedlistC);
private:
	int length;
	int length2;

};