#include "Easy.h"

#include<iostream>

using namespace std;


void Easy::Available_M(ItemType& item, UnsortedType& linkedlist, ofstream& dataFile)
{

	length = linkedlist.GetLength();
	linkedlist.ResetList();
	for (int i = 0; i < length; i++)
	{
		item = linkedlist.GetNextItem();

		item.Print(dataFile);

	}


}
void Easy::ShowList(ItemType& item, ItemType& itemNum, ItemType& ItemSpec, UnsortedType& linkedlist, ofstream& dataFile)
{
	length = linkedlist.GetLength();
	linkedlist.ResetList();
	for (int i = 0; i < length; i++)
	{
		item = linkedlist.GetNextItem();
		ItemSpec = linkedlist.CurrentSpec();
		itemNum = linkedlist.CurrentNum();

		cout << endl;
		itemNum.Print(dataFile);
		item.Print(dataFile);
		ItemSpec.Print(dataFile);
		
	}
}

void Easy::FindNextDoctor(ItemType& item, ItemType& itemNum, ItemType& ItemSpec, ItemType& patientName, UnsortedType& linkedlist, ofstream& dataFile, UnsortedType& linkedlistP, UnsortedType& linkedlistC)
{
	length = linkedlistP.GetLength();
	linkedlistP.ResetList();
	linkedlist.ResetList();

	
		item = linkedlist.GetNextItem();
		ItemSpec = linkedlist.CurrentSpec();
		itemNum = linkedlist.CurrentNum();
		patientName = linkedlistP.GetNextItem();
		
		linkedlistC.PutItemM(item, ItemSpec, itemNum, patientName);



		cout << endl;
		itemNum.Print(dataFile);
		item.Print(dataFile);
		ItemSpec.Print(dataFile);
	
}

void Easy::ShowList2(ItemType& item,  ItemType& ItemSpec, ItemType& itemNum, ItemType& ItemPatient, UnsortedType& linkedlist, ofstream& dataFile)
{
	length = linkedlist.GetLength();
	linkedlist.ResetList();
	for (int i = 0; i < length; i++)
	{
		item = linkedlist.GetNextItem();
		ItemSpec = linkedlist.CurrentSpec();
		itemNum = linkedlist.CurrentNum();
		ItemPatient = linkedlist.CurrentPatient();

		cout << endl;

		itemNum.Print(dataFile);
		item.Print(dataFile);
		ItemSpec.Print(dataFile);
		ItemPatient.Print(dataFile);

	}
}


void Easy::Find(string name, ItemType& item, UnsortedType& linkedList, bool& found, ofstream& dataFile) {



	item.Initialize(name);
	linkedList.ResetList();
	linkedList.GetItem(item, found);
	item.Print(dataFile);
	if (found)
	{
		cout << name << " Item was found in list: " << endl;
		dataFile << name << "found " << endl;
	}
	else
	{
		dataFile << name << " not found " << endl;
		cout << name << " not found " << endl;
	}

}






bool Easy::IsListEmpty(UnsortedType& linkedList, bool& found)
{
	length = linkedList.GetLength();

	if (length == 0)
	{
		found = true;
	}
	else
	{
		found = false;
	}
	return found;
}
