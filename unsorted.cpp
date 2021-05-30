
// This file contains the linked implementation of class
// UnsortedType.

#include "unsorted.h"
#include"ItemType.h"
#include<iostream>
using namespace std;

struct NodeType
{
	ItemType info;
	ItemType info2;
	ItemType info3;
	ItemType info4;

	NodeType* next;
};

UnsortedType::UnsortedType()  // Class constructor
{
	length = 0;
	listData = NULL;

}
bool UnsortedType::IsFull() const
// Returns true if there is no room for another ItemType 
//  on the free store; false otherwise.
{
	NodeType* location;
	try
	{
		location = new NodeType;
		delete location;
		return false;
	}
	catch (std::bad_alloc exception)
	{
		return true;
	}
}

int UnsortedType::GetLength() const
// Post: Number of items in the list is returned.
{
	return length;
}

void UnsortedType::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{
	NodeType* tempPtr;

	while (listData != NULL)
	{
		tempPtr = listData;
		listData = listData->next;
		delete tempPtr;
	}
	length = 0;
}
void UnsortedType::PutItem(ItemType item)
// item is in the list; length has been incremented.
{
	NodeType* location;			// Declare a pointer to a node


	location = new NodeType;		// Get a new node 
	location->info = item;		// Store the item in the node
	location->next = listData;	// Store address of first node 
						  //   in next field of new node
	listData = location;		// Store address of new node into
						  //   external pointer
	length++;
}

void UnsortedType::PutItemPatient(ItemType PatientName, ItemType Spec)
{
	NodeType* location;

	location = new NodeType;
	location->info = PatientName;
	location->info2 = Spec;


	location->next = listData;

	listData = location;

	length++;
}


void UnsortedType::PutItemS(ItemType item1, ItemType item2, ItemType item3)
{


	NodeType* location;

	location = new NodeType;
	location->info = item1;
	location->info2 = item2;
	location->info3 = item3;

	location->next = listData;

	listData = location;

	length++;

}
void UnsortedType::PutItemM(ItemType item1, ItemType item2, ItemType item3, ItemType item4)
{
	NodeType* location;

	location = new NodeType;
	location->info = item1;
	location->info2 = item2;
	location->info3 = item3;
	location->info4 = item4;
	location->next = listData;

	listData = location;

	length++;
}




ItemType UnsortedType::GetItem(ItemType& item, bool& found)
// Pre:  Key member(s) of item is initialized.
// Post: If found, item's key matches an element's key in the 
//       list and a copy of that element has been stored in item;
//       otherwise, item is unchanged. 
{
	bool moreToSearch;
	NodeType* location;

	location = listData;
	found = false;
	moreToSearch = (location != NULL);

	while (moreToSearch && !found)
	{
		switch (item.ComparedTo(location->info))
		{
		case LESS:
		case GREATER: location = location->next;
			moreToSearch = (location != NULL);
			break;
		case EQUAL: found = true;
			item = location->info;

			break;
		}
	}
	
	return item;
}

ItemType UnsortedType::GetItemSpec_WithName(ItemType& Spec, ItemType& DocName, bool& found)
{
	bool moreToSearch;
	NodeType* location;

	location = listData;
	found = false;
	moreToSearch = (location != NULL);

	while (moreToSearch && !found)
	{
		switch (Spec.ComparedTo(location->info2))
		{
		case LESS:
		case GREATER: location = location->next;
			moreToSearch = (location != NULL);
			break;
		case EQUAL: found = true;
			Spec = location->info2;
			Spec.Print2();
			DocName = location->info;
			DocName.Print2();
			break;
		}
	}
	
	return DocName;

}

ItemType UnsortedType::GetItemSpec_Room(ItemType& Spec, ItemType& room, bool& found)
{
	bool moreToSearch;
	NodeType* location;

	location = listData;
	found = false;
	moreToSearch = (location != NULL);

	while (moreToSearch && !found)
	{
		switch (Spec.ComparedTo(location->info2))
		{
		case LESS:
		case GREATER: location = location->next;
			moreToSearch = (location != NULL);
			break;
		case EQUAL: found = true;
			Spec = location->info2;
			Spec.Print2();
			room = location->info3;

			break;
		}
	}

	return room;
}


ItemType UnsortedType::GetItemRoom(ItemType& DocName, ItemType& room, bool& found)
{

	bool moreToSearch;
	NodeType* location;

	location = listData;
	found = false;
	moreToSearch = (location != NULL);

	while (moreToSearch && !found)
	{
		switch (DocName.ComparedTo(location->info))
		{
		case LESS:
		case GREATER: location = location->next;
			moreToSearch = (location != NULL);
			break;
		case EQUAL: found = true;
			DocName = location->info;
			DocName.Print2();
			room = location->info3;
			room.Print2();
			break;
		}
	}

	return room;
}
ItemType UnsortedType:: GetItemRoom_Doc(ItemType& room, ItemType& DocName, bool& found)
{
	bool moreToSearch;
	NodeType* location;

	location = listData;
	found = false;
	moreToSearch = (location != NULL);

	while (moreToSearch && !found)
	{
		switch (room.ComparedTo(location->info3))
		{
		case LESS:
		case GREATER: location = location->next;
			moreToSearch = (location != NULL);
			break;
		case EQUAL: found = true;
			room = location->info3;
			room.Print2();
			DocName = location->info;
			DocName.Print2();
			break;
		}
	}

	return DocName;
}

ItemType UnsortedType::GetItemRoom_Spec(ItemType& room, ItemType& spec, bool& found)
{
	bool moreToSearch;
	NodeType* location;

	location = listData;
	found = false;
	moreToSearch = (location != NULL);

	while (moreToSearch && !found)
	{
		switch (room.ComparedTo(location->info3))
		{
		case LESS:
		case GREATER: location = location->next;
			moreToSearch = (location != NULL);
			break;
		case EQUAL: found = true;
			room = location->info3;
			room.Print2();
			spec = location->info2;
			spec.Print2();
			break;
		}
	}

	return spec;
}

ItemType UnsortedType::GetItemRoom_Patient(ItemType& room, ItemType& patient, bool& found)
{
	bool moreToSearch;
	NodeType* location;

	location = listData;
	found = false;
	moreToSearch = (location != NULL);

	while (moreToSearch && !found)
	{
		switch (room.ComparedTo(location->info3))
		{
		case LESS:
		case GREATER: location = location->next;
			moreToSearch = (location != NULL);
			break;
		case EQUAL: found = true;
			room = location->info3;
			room.Print2();
			patient = location->info4;
			patient.Print2();
			break;
		}
	}
	
	return patient;
}


ItemType UnsortedType::GetItemName_Spec(ItemType& DocName, ItemType& Spec, bool& found)
{
	bool moreToSearch;
	NodeType* location;

	location = listData;
	found = false;
	moreToSearch = (location != NULL);

	while (moreToSearch && !found)
	{
		switch (DocName.ComparedTo(location->info))
		{
		case LESS:
		case GREATER: location = location->next;
			moreToSearch = (location != NULL);
			break;
		case EQUAL: found = true;
			DocName = location->info;
			DocName.Print2();
			Spec = location->info2;
			Spec.Print2();
			break;
		}
	}

	return Spec;
}

ItemType UnsortedType::GetItemName_DOcToPatient(ItemType& DocName, ItemType& patient, bool& found)
{
	bool moreToSearch;
	NodeType* location;

	location = listData;
	found = false;
	moreToSearch = (location != NULL);

	while (moreToSearch && !found)
	{
		switch (DocName.ComparedTo(location->info))
		{
		case LESS:
		case GREATER: location = location->next;
			moreToSearch = (location != NULL);
			break;
		case EQUAL: found = true;
			DocName = location->info;
			DocName.Print2();
			patient = location->info4;
			patient.Print2();
			break;
		}
	}

	return patient;
}





void UnsortedType::ResetList()
// Post: Current position has been initialized.
{
	currentPos = NULL;
}

ItemType UnsortedType::GetNextItem()
// Post:  A copy of the next item in the list is returned.
//        When the end of the list is reached, currentPos
//        is reset to begin again.
{
	

	ItemType item;
	if (currentPos == NULL)
		currentPos = listData;
	else
		currentPos = currentPos->next;
	item = currentPos->info;


	return item;
}




ItemType UnsortedType::CurrentSpec()
{
	ItemType item2;

	item2 = currentPos->info2;
	return item2;
}

ItemType UnsortedType:: CurrentNum() 
{
	ItemType item3;

	item3 = currentPos->info3;
	return item3;
}

ItemType UnsortedType::CurrentPatient()
{
	ItemType item4;

	item4 = currentPos->info4;
	return item4;
}
void UnsortedType::DeleteItem(ItemType item)
// Pre:  item's key has been initialized.
//       An element in the list has a key that matches item's.
// Post: No element in the list has a key that matches item's.
{
	NodeType* location = listData;
	NodeType* tempLocation;
	
	// Locate node to be deleted.
	if (item.ComparedTo(listData->info) == EQUAL)
	{
		tempLocation = location;
		listData = listData->next;		// Delete first node.
	}
	else
	{
		while (item.ComparedTo((location->next)->info) != EQUAL)
			location = location->next;

		// Delete node at location->next
		tempLocation = location->next;
		location->next = (location->next)->next;
	}
	delete tempLocation;
	length--;
}
void UnsortedType::DeleteItemRoom(ItemType room) {

	NodeType* location = listData;
	NodeType* tempLocation;

	// Locate node to be deleted.
	if (room.ComparedTo(listData->info3) == EQUAL)
	{
		tempLocation = location;
		listData = listData->next;		// Delete first node.
	}
	else
	{
		while (room.ComparedTo((location->next)->info3) != EQUAL)
			location = location->next;

		// Delete node at location->next
		tempLocation = location->next;
		location->next = (location->next)->next;
	}
	delete tempLocation;
	length--;
}

UnsortedType::~UnsortedType()
// Post: List is empty; all items have been deallocated.
{
	NodeType* tempPtr;

	while (listData != NULL)
	{
		tempPtr = listData;
		listData = listData->next;
		delete tempPtr;
	}
}
