#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>

#include "unsorted.h"
#include"Easy.h"

using namespace std;
enum DisplayMenu { DOCTOR, PATIENT, PRINTALL, CHECKOUT_DOC, CHECKOUT_PAT, QUIT };

void getCommand(DisplayMenu&);

void yesNoMenu();
int getChoice();





int main()
{


	ifstream inFile;				// file containing operations
	ofstream outFile;					// file containing output
	ifstream inFile2;
	ifstream inFile3;
	ifstream inFile4;
	ifstream inFileNumbers;

	string inFileName;     // input file external name
	string outFileName;    // output file external name
	string outputLabel;
	string buffer1, buffer2, buffer3, buffer4, buffer5;

	

	ItemType itemDocName, item2PatientName,item3Room,item4Spec,item5FullSpec, itemPatientSpec;
	
	ItemType itemRoom_A, itemRoom_N, itemAge;
	ItemType itemSpecE;
	UnsortedType listDoc, listPat, listSpec, listSpec2, listNumA, ListNumN, listPaientU_Wait, listPaientO_Wait, listCheckedIn;
	Easy Fun1;

	string DocName, DocSpec, DocFav;
	string PatientName, PatientSpec;
	string yes;
	int PatientAge, listLenght,choice,LenghtDoc,LenghtCheckIn,LenghtPatientU,LenghtPatientO,OVerallLenght;

	bool check;
	bool check2;
	bool check3;
	bool doccheck;
	bool found;
	bool found1;
	bool found2;
	bool found3;
	bool found4;
	bool found5;
	bool found6;
		bool found7;
	bool found10;
	bool found12;
	bool found13;

	inFile.open("rooms.txt");
	if (!inFile)
	{
		cout << " In file not opned" << endl;
	}
	inFile2.open("fullspec.txt");
	if (!inFile2)
	{
		cout << " In file not opned" << endl;
	}

	inFile3.open("spec.txt");
		if (!inFile3)
		{
			cout << " In file not opned" << endl;
		}
		inFile4.open("Doctors.txt");
		if (!inFile3)
		{
			cout << " In file not opned" << endl;
		}

		outFile.open("outPut.txt");

		if (!outFile)
		{
			cout << " In file not opned" << endl;
		}

		outFile << "Doctors Checked in By Default" << endl;
		for (int i = 0; i < 12; i++)
		{
			getline(inFile4, buffer1);
			getline(inFile, buffer2);
			getline(inFile3, buffer3);
			itemDocName.Initialize(buffer1);
			item3Room.Initialize(buffer2);
			itemSpecE.Initialize(buffer3);

			listDoc.PutItemS(itemDocName, itemSpecE, item3Room);
			

		
			itemDocName.Print(outFile);
			itemSpecE.Print(outFile);
			item3Room.Print(outFile);



		}
		
	
		
		cout << "Not Avaiable Rooms" << endl;
	
		
			for (int i = 0; i < 12; i++)
			{
				getline(inFile, buffer1);
				item3Room.Initialize(buffer1);
				ListNumN.PutItem(item3Room);
				outFile << "Not Rooms" << endl;
				item3Room.Print(outFile);


			}
			cout << "Avaiable Rooms" << endl;
		
			for (int i = 0; i < 8; i++)
			{
				getline(inFile, buffer1);
				item3Room.Initialize(buffer1);
				listNumA.PutItem(item3Room);
				outFile << "Avaiable Rooms" << endl;
				item3Room.Print(outFile);

			}
		
			outFile << "Full Spec Display List" << endl;
		// rooms
		if (!inFile2.eof())
		{
			for (int i = 0; i < 12; i++)
			{
				getline(inFile2, buffer2);
				item5FullSpec.Initialize(buffer2);
				listSpec2.PutItem(item5FullSpec);
				
				item5FullSpec.Print(outFile);


			}

		}





		//spec 3 dit
		if (!inFile3.eof())
		{
			for (int i = 0; i < 12; i++)
			{
				getline(inFile3, buffer3);
				item4Spec.Initialize(buffer3);
				listSpec.PutItem(item4Spec);
				item4Spec.Print(outFile);


			}

		}

		system("cls");
		

		DisplayMenu command;
		getCommand(command);

		while (command != QUIT)
		{
		
			switch (command)
			{
			case DOCTOR:
				// checks in doctors 
				cin.ignore();
				cout << " Enter Doctor Name" << endl;
				outFile<< " Enter Doctor Name" << endl;
				getline(cin, DocName);
				Fun1.Find(DocName, itemDocName, listDoc, found, outFile);// checks if this doctor is already checked in
				if (found)
				{

					cout << "You are already checked in clinc" << endl;
					outFile << "You are already checked in clinc" << endl;
				}
				else
				{
					itemDocName.Initialize(DocName);
					Fun1.Available_M(item4Spec, listSpec, outFile);//Shows all the spec spelled out fully
					do
					{
						cout << " Enter 3 digit Spec" << endl;
						getline(cin, DocSpec);
						
						Fun1.Find(DocSpec, item4Spec, listSpec, found1, outFile);// checks if spec is valid
						
	
						
							itemSpecE.Initialize(DocSpec);

						
							
								
						if (found1)

							yesNoMenu();
						choice = getChoice();
						switch (choice)// doctor choice to choose his favorite room or be asigned first avaiable room in the clinic
						{
						case 1:
							Fun1.Available_M(item3Room, listNumA, outFile);//shows avaiable rooms
							do
							{
								cin.ignore();
								cout << " Enter Room Number" << endl;
								getline(cin, DocFav);
								Fun1.Find(DocFav, item3Room, listNumA, found2, outFile);// finds doctor favorite room and checks if its free
								if (found2)
								{
									item3Room.Initialize(DocFav);

									outFile << "New Doctor ADDED " << endl;
									outFile << "--------------------" << endl;
									listDoc.PutItemS(itemDocName, itemSpecE, item3Room);

									itemDocName.Print(outFile);
									itemSpecE.Print(outFile);
									item3Room.Print(outFile);
									ListNumN.PutItem(item3Room);
									listNumA.DeleteItem(item3Room);

								}



							} while (!found2);
							

							break;
						case 2:
							cout << "Next Avaiable room " << endl;
							listNumA.ResetList();
							item3Room = listNumA.GetNextItem();// gets next avaiable room

							item3Room.Print(outFile);

							outFile << "New Doctor ADDED " << endl;
							outFile << "--------------------" << endl;
							listDoc.PutItemS(itemDocName, itemSpecE, item3Room);

							itemDocName.Print(outFile);
							itemSpecE.Print(outFile);
							item3Room.Print(outFile);
							ListNumN.PutItem(item3Room);
							listNumA.DeleteItem(item3Room);// deletes that room from list 

								break;
							
						default:
							break;
						}
								
									
								
								

								

									

								
						

					} while (!found1);


				}
				outFile << "Not Avaiable rooms " << endl;
				outFile << "--------------------" << endl;
				cout<< "Not Avaiable rooms " << endl;
				Fun1.Available_M(item3Room, ListNumN, outFile);// shows rooms not avaiable 
				cout<<" Avaiable rooms " << endl;
				outFile << "Avaiable rooms " << endl;
				outFile << "--------------------" << endl;
				Fun1.Available_M(item3Room, listNumA, outFile);// shows rooms that are still avaiable 

				LenghtDoc = listDoc.GetLength();// doctor list length if needed
				break;
			case PATIENT:

				listLenght = listCheckedIn.GetLength();
				
					cin.ignore();
					cout << " Enter Patient Name" << endl;
					getline(cin, PatientName);
					item2PatientName.Initialize(PatientName);

					cout << " Enter Patient Age" << endl;
					cin >> PatientAge;

					if (PatientAge < 16)// patients under aged 16 childern assigned a PED automatically 
					{
						if (listLenght < 21)// checks if clinic is full if so assigns the patient to waitlist
						{
							// assigns patient to PED Doctor 

							Fun1.IsListEmpty(listPaientU_Wait, found5);
							itemSpecE.Initialize("PED");
							listDoc.GetItemSpec_WithName(itemSpecE, itemDocName, found);
							listDoc.GetItemSpec_Room(itemSpecE, item3Room, found1);
							if (!found5 && found)
							{
								// if somone in wait list they will see the doctor first once avaiable
								cout << "some one is waiting for this doctor " << endl;
								item2PatientName = listPaientU_Wait.GetNextItem();
								listCheckedIn.PutItemM(itemDocName, itemSpecE, item3Room, item2PatientName); // adding to main list
								item3Room.Print2();
								itemDocName.Print2();
								itemSpecE.Print2();
								item2PatientName.Print2();

								cout << "List of Doctors updated  " << endl;
								cout << "------------------" << endl;
								listDoc.DeleteItem(itemDocName);

								Fun1.ShowList(itemDocName, item3Room, itemSpecE, listDoc, outFile);
								listPaientU_Wait.DeleteItem(item2PatientName);
							}
							else if (found && found5)
							{
								//

								cout << " Since your 16 years old our clinic will assign you PED" << endl;


								cout << "Items Checking in to Room" << endl;
								item3Room.Print2();
								itemDocName.Print2();
								itemSpecE.Print2();
								item2PatientName.Print2();

								listCheckedIn.PutItemM(itemDocName, itemSpecE, item3Room, item2PatientName);
								listDoc.DeleteItem(itemDocName);
								cout << "List of Doctors left in list  " << endl;
								cout << "------------------" << endl;
								Fun1.ShowList(itemDocName, item3Room, itemSpecE, listDoc, outFile);





							}
							else
							{
								//if no doctors available put in waitlist
								cout << "Currently There are no Pediatrics PED available your put on wait list" << endl;
								listPaientU_Wait.PutItem(item2PatientName);
								cout << "Patient is in Wait list " << PatientName << endl;
								outFile << "Patient is in Wait list" << endl;
								item2PatientName.Print(outFile);

							}
						}
						else
						{
							//if no rooms available put in waitlist
							cout << "Currently There are no Pediatrics PED avaiable your put on wait list" << endl;
							listPaientU_Wait.PutItem(item2PatientName);
							cout << "Patient is in Wait list " << PatientName << endl;
							outFile << "Patient is in Wait list" << endl;
							item2PatientName.Print(outFile);
						}
						
					}
					else
					{
						//if patient is older than 
						if (listLenght < 21)
						{

							Fun1.Available_M(item5FullSpec, listSpec2, outFile);
							do
							{
								cout << " Enter 3 digit Spec To see A Doctor" << endl;
								getline(cin, PatientSpec);
								cout << "You entered:---- " << PatientSpec << endl;
								outFile << "Show Full Spec" << endl;
								cout << "Show Full Spec" << endl;

								Fun1.Find(PatientSpec, item4Spec, listSpec, found10, outFile);
							} while (!found10);// forces user to enter spec from list otherwise loops until they do

							itemSpecE.Initialize(PatientSpec);
							listDoc.GetItemSpec_WithName(itemSpecE, itemDocName, found12);// Once user enters the spec this goes threw the list of doctors finds one needed for patient and gets doctors name
							Fun1.IsListEmpty(listPaientO_Wait, found4);//if wait list is empty 
							if (found12)
							{
								listDoc.GetItemSpec_Room(itemSpecE, item3Room, found1);// once doctor is found this uses the same spec to get doctors room number

								item3Room.Print2();
								itemDocName.Print2();
								itemSpecE.Print2();
								item2PatientName.Print2();

								listCheckedIn.PutItemM(itemDocName,itemSpecE, item3Room, item2PatientName);// checks in patient and doctor into clinic room
								listDoc.DeleteItem(itemDocName);// deletes doctor from available list to being checked in seeing patient 


							}
							else if (!found12)
							{
								// if cant find doctor then patient is put on wait list
								cout << "Currently There are no doctors your put into wait list" << endl;
								listPaientO_Wait.PutItemPatient(item2PatientName, itemSpecE);
								cout << "Patient is in Wait list " << PatientName << endl;
								outFile << "Patient is in Wait list" << endl;
								item2PatientName.Print(outFile);
								itemSpecE.Print(outFile);
								

							}
							else if (!found4)
							{
								// if waitlist is not empty assigns the next patient waiting in the list to next available doctor 
								cout << "Your next on the list" << endl;
								listPaientO_Wait.ResetList();
								item2PatientName = listPaientO_Wait.GetNextItem();
								listPaientO_Wait.GetItemName_Spec(item2PatientName,itemSpecE,found1);
								listDoc.GetItemSpec_WithName(itemSpecE, itemDocName, found2);
								if (found2)
								{

									listDoc.GetItemSpec_Room(itemSpecE, item3Room, found1);

									item3Room.Print2();
									itemDocName.Print2();
									itemSpecE.Print2();
									item2PatientName.Print2();

									listCheckedIn.PutItemM(itemDocName, itemSpecE, item3Room, item2PatientName);
									listDoc.DeleteItem(itemDocName);
									listPaientO_Wait.DeleteItem(item2PatientName);

								}
								else
								{
									cout << "All doctors are seeing patients please wait for doctor to be avaiable " << endl;
								}

							}
						



							cout << "List of Doctors left in list  " << endl;
							cout << "------------------" << endl;
							Fun1.ShowList(itemDocName, item3Room, itemSpecE, listDoc, outFile);

						}
						else
						{
							// if main clinic is full adds patients to waitlist 

							cout << "ALl the room are Full your put into a wait list" << endl;
							listPaientO_Wait.PutItemPatient(item2PatientName,itemSpecE);
							
							cout << "Patient is in Wait list " << PatientName << endl;
							outFile << "Patient is in Wait list" << endl;
							item2PatientName.Print(outFile);
							itemSpecE.Print(outFile);
						}


					}
				


				break;
			case PRINTALL:
				// prints all the lists in the system 
				outFile << "Show All the Lists In project" << endl;
				outFile << "*****************************" << endl;
				cout << " Doctors Checked In" << endl;

				cout << "------------------" << endl;
				Fun1.ShowList(itemDocName, item3Room, itemSpecE, listDoc, outFile);
				cout << endl;
				cout << "Patients Seeing doctor " << endl;
				cout << "------------------" << endl;
				Fun1.ShowList2(itemDocName,itemSpecE, item3Room, item2PatientName, listCheckedIn, outFile);

				cout << "wait list Patients that are under the age of 16" << endl;
				Fun1.Available_M(item2PatientName, listPaientO_Wait, outFile);
				cout << "wait list Patients" << endl;
				Fun1.Available_M(item2PatientName, listPaientU_Wait, outFile);
				cout << "Rooms Avaiable for Doctors " << endl;
				Fun1.Available_M(item3Room, listNumA, outFile);
				cout << "Full Spec" << endl;
				Fun1.Available_M(item5FullSpec, listSpec2, outFile);

				break;
			case CHECKOUT_DOC:

				//check out doctors 
				LenghtPatientO = listPaientO_Wait.GetLength();
				LenghtPatientU = listPaientU_Wait.GetLength();
				LenghtCheckIn = listCheckedIn.GetLength();
				LenghtDoc = listDoc.GetLength();

				cout << "List of Doctors seeing Patients " << endl;
				cout << "--------------------------------- " << endl;
				Fun1.ShowList2(itemDocName, itemSpecE, item3Room, item2PatientName, listCheckedIn,outFile);

				cout << endl;

				cout << "List of Doctors checked in not Seeing patient " << endl;
				cout << "--------------------------------- " << endl;
				Fun1.ShowList(itemDocName, itemSpecE, item3Room, listDoc, outFile);
				cin.ignore();
					cout << "Check out Doctor " << endl;
					cout << "Enter Doctor Name you want to check out" << endl;
					getline(cin, DocName);
					Fun1.Find(DocName, itemDocName, listDoc, found, outFile);
					Fun1.Find(DocName, itemDocName, listCheckedIn, found2, outFile);
					if (found)
					{
						cout << "Found in list" << endl;
						listDoc.GetItemRoom(itemDocName, item3Room,found10);
						cout << "Found in list Room" << endl;
						item3Room.Print2();

						listNumA.PutItem(item3Room);

						listDoc.DeleteItem(itemDocName);

						cout << "Updated doctor list" << endl;
						Fun1.ShowList(itemDocName, itemSpecE, item3Room, listDoc, outFile);

					}
					else if (found2)
					{

						cout << "Found in list" << endl;
						itemDocName.Print2();
						listCheckedIn.GetItemRoom(itemDocName, item3Room, found10);
						item3Room.Print2();

						listNumA.PutItem(item3Room);

						listCheckedIn.DeleteItem(itemDocName);

						cout << "Updated doctor list" << endl;
						cout << "List of Doctors seeing Patients " << endl;
						cout << "--------------------------------- " << endl;
						Fun1.ShowList2(itemDocName, itemSpecE, item3Room, item2PatientName, listCheckedIn, outFile);
					}
					else
					{
						cout << " You entered the wrong Name please try again " << endl;
					}

				
				


				
				break;
			case CHECKOUT_PAT:

				//checks out patients 
				Fun1.IsListEmpty(listCheckedIn, found10);
				if (!found10)
				{


					cout << "Patients Seeing doctor " << endl;
					cout << "------------------" << endl;
					Fun1.ShowList2(itemDocName, itemSpecE, item3Room, item2PatientName, listCheckedIn, outFile);
					do
					{

						//asks user to release patient from doctors room 

						cout << "Which room would you like to empty " << endl;
						getline(cin, DocFav);
						item3Room.Initialize(DocFav);
						listCheckedIn.GetItemRoom_Doc(item3Room, itemDocName, found);

					} while (!found);

					listCheckedIn.GetItemRoom_Patient(item3Room, item2PatientName, found1);

					listCheckedIn.GetItemRoom_Spec(item3Room, itemSpecE, found2);
					if (found)
					{
						outFile << "Patient checking out of hospital " << endl;
						cout << "Patient checking out of hospital " << endl;
						item2PatientName.Print(outFile);
						cout << "Doctor avaiable to take next patient " << endl;
						item3Room.Print(outFile);
						itemDocName.Print(outFile);
						itemSpecE.Print(outFile);

						listDoc.PutItemS(itemDocName, itemSpecE, item3Room);
						


					}
					else
					{
						cout << "Something went wrong we couldnt find the patient" << endl;
					}
					cout << "room number being delteed and put back as avaiable" << endl;
					item3Room.Print2();
					listCheckedIn.DeleteItemRoom(item3Room);

					outFile << "Updated Doctor list Doctor added back to list " << endl;
					cout << "Updated Doctor list Doctor added back to list " << endl;
					Fun1.ShowList(itemDocName, item3Room, itemSpecE, listDoc, outFile);
					outFile << "Updated Doctor list Doctor added back to list " << endl;
					cout << endl;
					cout << "Clinic Patients being seeen__________________" << endl;
					Fun1.ShowList2(itemDocName, itemSpecE, item3Room, item2PatientName, listCheckedIn, outFile);
				}
				else
				{
					cout << "There are no Patients being seen by doctors " << endl;
				}
				break;
			case QUIT:
				

				break;
			default:
				

				break;
			}
			getCommand(command);

		}

		//outFile << flush;
	

		do
		{
	LenghtPatientO = listPaientO_Wait.GetLength();
		LenghtPatientU = listPaientU_Wait.GetLength();
		LenghtCheckIn = listCheckedIn.GetLength();
		OVerallLenght = LenghtPatientO + LenghtPatientU + LenghtCheckIn;
		cout << "Overall Lenght " << OVerallLenght << endl;
		cout << " we are closing all the patients waiting will see a doctor and be checked out " << endl;
		cout << "Lastly all the doctors will be checked out after seeing patients " << endl;
		outFile << " we are closing all the patients waiting will see a doctor and be checked out " << endl;
		outFile << "Lastly all the doctors will be checked out after seeing patients " << endl;
		system("pause");
			do
			{

				//checks if wait list is empty and if there is enough rooms avaible to see doctors 
				Fun1.IsListEmpty(listPaientU_Wait, found5);
				if (LenghtCheckIn <= 20)
				{


					if (found5)
					{
						cout << "Young childerns wait list is empty" << endl;


					}
					else
					{
						cout << "There are this many kids waiting to see a doctor" << LenghtPatientU << endl;


						// gets the first person of under aged list and assigns it PED if it can if not 
						//gets next avaiable doctor 

						itemSpecE.Initialize("PED");



						listDoc.GetItemSpec_WithName(itemSpecE, itemDocName, found);
						listDoc.GetItemSpec_Room(itemSpecE, item3Room, found1);
						if (found)
						{
							cout << "some one is waiting for this doctor " << endl;
							item2PatientName = listPaientU_Wait.GetNextItem();
							listCheckedIn.PutItemM(itemDocName, itemSpecE, item3Room, item2PatientName); // adding to main list
							item3Room.Print2();
							itemDocName.Print2();
							itemSpecE.Print2();
							item2PatientName.Print2();

							cout << "List of Doctors updated  " << endl;
							cout << "------------------" << endl;
							listDoc.DeleteItem(itemDocName);
							listDoc.ResetList();
							Fun1.ShowList(itemDocName, item3Room, itemSpecE, listDoc, outFile);
							listPaientU_Wait.DeleteItem(item2PatientName);
							system("pause");
							LenghtPatientU--;
						}
						else if (!found)
						{
							listPaientU_Wait.ResetList();
							item2PatientName = listPaientU_Wait.GetNextItem();
							cout << "Patient Name" << endl;
							item2PatientName.Print2();
							cout << "Your being assinged a new doctor since we are closing soon" << endl;
							LenghtDoc = listDoc.GetLength();
							cout << "Doctor list: " << LenghtDoc << endl;
							Fun1.ShowList(itemDocName, item3Room, itemSpecE, listDoc, outFile);

							listDoc.ResetList();
							itemDocName = listDoc.GetNextItem();

							cout << "Doctor :" << endl;
							itemDocName.Print2();
							cout << "Will see you now " << endl;
							listDoc.GetItemName_Spec(itemDocName, itemSpecE, found10);
							listDoc.GetItemRoom(itemDocName, item3Room, found12);
							listCheckedIn.PutItemM(itemDocName, itemSpecE, item3Room, item2PatientName);
							outFile << "Clinic Closing so Next avaiable doctor is seeing the childeren ---" << endl;
						
							item3Room.Print(outFile);
							itemDocName.Print(outFile);
							itemSpecE.Print(outFile);
							item2PatientName.Print(outFile);

							system("pause");
							cout << "List of Doctors updated  " << endl;
							cout << "------------------" << endl;
							outFile << "Doctor deleted from doctor list--- " << endl;
							item3Room.Print(outFile);
							itemDocName.Print(outFile);
							itemSpecE.Print(outFile);

							ListNumN.PutItem(item3Room);
							listDoc.DeleteItemRoom(item3Room);
							listPaientU_Wait.DeleteItem(item2PatientName);
							LenghtPatientU--;
							system("pause");


						}





					}
				}
				else
				{
					// if there are too many doctors checked into main clinic this makes half of them avaible for new patients 
					int num;
					cout << "clinic is full checking out few patietns to make room to see new ones" << endl;
					outFile << " clinic is full checking out few patietns to make room to see new ones" << endl;
					num = LenghtCheckIn / 2;
					for (int i = 0; i < num; i++)
					{

						listCheckedIn.ResetList();
						listCheckedIn.GetNextItem();

						item3Room.Print(outFile);
						itemDocName.Print(outFile);
						itemSpecE.Print(outFile);
						outFile << "Doctors added back in doctors list after seeing patients--- " << endl;
						item3Room.Print(outFile);
						itemDocName.Print(outFile);
						itemSpecE.Print(outFile);
						listDoc.PutItemS(itemDocName, itemSpecE, item3Room);

						cout << "Patient checking out" << endl;
						outFile << "Patient checking out" << endl;
						cout << "-----------------" << endl;
						outFile << "---------------" << endl;
						item2PatientName.Print(outFile);
						item2PatientName.Print2();

						listCheckedIn.DeleteItem(item3Room);
						listNumA.PutItem(item3Room);// adding room from not avaiable to avaiable
						ListNumN.DeleteItem(item3Room);// removing room from not avaiable 


					}


				}
			} while (!found5);

			do
			{
				Fun1.IsListEmpty(listPaientO_Wait, found10);


				if (found10)
				{
					cout << "There are No patients waiting in list" << endl;
				}
				else
				{
					// get the next patient on wait list and assigns the next avaiable doctor 
					listPaientO_Wait.ResetList();
					item2PatientName = listPaientO_Wait.GetNextItem();


					cout << " Patient " << endl;
					item2PatientName.Print2();
					cout << " Spec grabed" << endl;
					listDoc.ResetList();

					itemDocName = listDoc.GetNextItem();
					listDoc.GetItemName_Spec(itemDocName, itemSpecE, found4);
					listDoc.GetItemRoom(itemDocName, item3Room, found5);

					if (LenghtCheckIn <= 20)
					{


						itemSpecE.Print2();
						listCheckedIn.PutItemM(itemDocName, itemSpecE, item3Room, item2PatientName); // adding to main list
						item3Room.Print2();
						itemDocName.Print2();
						itemSpecE.Print2();
						item2PatientName.Print2();
						outFile << "Patient added to checkin from wait list" << endl;
						cout << "Patient added to checkin from wait list" << endl;
						item3Room.Print(outFile);
						itemDocName.Print(outFile);
						itemSpecE.Print(outFile);
						item2PatientName.Print(outFile);
						cout << "List of Doctors updated  " << endl;
						cout << "------------------" << endl;
						listDoc.DeleteItem(itemDocName);
						listDoc.ResetList();
						Fun1.ShowList(itemDocName, item3Room, itemSpecE, listDoc, outFile);
						listPaientO_Wait.DeleteItem(item2PatientName);
						system("pause");

						LenghtPatientO--;



					}
					else
					{
						int num;
						cout << "clinic is full checking out few patietns to make room to see new ones" << endl;
						outFile << " clinic is full checking out few patietns to make room to see new ones" << endl;
						num = LenghtCheckIn / 2;
						for (int i = 0; i < num; i++)
						{

							listCheckedIn.ResetList();
							listCheckedIn.GetNextItem();

							item3Room.Print(outFile);
							itemDocName.Print(outFile);
							itemSpecE.Print(outFile);
							outFile << "Doctors added back in doctors list after seeing patients--- " << endl;
							item3Room.Print(outFile);
							itemDocName.Print(outFile);
							itemSpecE.Print(outFile);
							listDoc.PutItemS(itemDocName, itemSpecE, item3Room);

							cout << "Patient checking out" << endl;
							outFile << "Patient checking out" << endl;
							cout << "-----------------" << endl;
							outFile << "---------------" << endl;
							item2PatientName.Print(outFile);
							item2PatientName.Print2();

							listCheckedIn.DeleteItem(item3Room);
							listNumA.PutItem(item3Room);// adding room from not avaiable to avaiable
							ListNumN.DeleteItem(item3Room);// removing room from not avaiable 
						}
					}

				}

			} while (!found10);

			
			do
			{
				Fun1.IsListEmpty(listCheckedIn, check);
				if (check)
				{
					cout << "No doctors seeing patients " << endl;
				}
				else
				{
					listCheckedIn.ResetList();
					itemDocName = listCheckedIn.GetNextItem();

					//item2PatientName = listCheckedIn.CurrentPatient();

					listDoc.GetItemName_Spec(itemDocName, itemSpecE, check2);
					listDoc.GetItemRoom(itemDocName, item3Room, check3);
					listDoc.GetItemName_DOcToPatient(itemDocName, item2PatientName, found12);
					cout << "checking out" << endl;
					outFile << "patient checking out" << endl;
				
					item3Room.Print(outFile);
					itemDocName.Print(outFile);
					itemSpecE.Print(outFile);

					outFile << "doctor added back to doctors list " << endl;
					listDoc.PutItemS(itemDocName, itemSpecE, item3Room);

					listCheckedIn.ResetList();
					listCheckedIn.DeleteItem(itemDocName);
				
					LenghtCheckIn--;

				}
			} while (!check&&!(LenghtCheckIn==0));
			
			
			do
			{
				Fun1.IsListEmpty(listDoc, doccheck);
				if (doccheck)
				{
					cout << "All the doctors are checked out" << endl;
					outFile << "All the doctors are checked out" << endl;
				}
				else
				{
					listDoc.ResetList();
					itemDocName = listDoc.GetNextItem();
					//listDoc.GetItemRoom(itemDocName, item3Room, found13);
					cout << "Doctor Checked Out of clinic " << endl;
					outFile<< "Doctor Checked Out of clinic " << endl;

					itemDocName.Print(outFile);
					itemDocName.Print2();
					cout << "Room Freed " << endl;
					outFile << "Room Freed " << endl;
					item3Room.Print(outFile);
					item3Room.Print2();

					listDoc.DeleteItem(itemDocName);
					listNumA.PutItem(item3Room);
					

				}
				
				
			} while (!doccheck);

			OVerallLenght--;
			if (OVerallLenght<=0)
			{
				
				OVerallLenght = 0;
			}

		} while (!(OVerallLenght==0));
	


	cout << "Testing completed." << endl;
	inFile.close();
	outFile.close();
	return 0;
}






	void getCommand(DisplayMenu & command)
	{

		cout << " Please Choose from menu" << endl;
		cout << "D: for Doctor Check in" << endl;
		cout << "P: for Patient check in" << endl;
		cout << "A: print all list" << endl;
		cout << "B: Check out A doctor " << endl;
		cout << "C: Checkout A Patient" << endl;
		cout << "Q: Quit" << endl;

		char letter;
		cin >> letter;

		bool ok = false;
		while (!ok)
		{
			ok = true;
			switch (letter)
			{
			case 'D':command = DOCTOR;
				break;
			case 'P':command = PATIENT;
				break;
			case 'A':command = PRINTALL;
				break;
			case'B':command = CHECKOUT_DOC;
				break;
			case'C':command = CHECKOUT_PAT;
				break;
			case 'Q':command = QUIT;
				break;




			default:cout << "Letter entered is not one of the "
				<< "specified upppercse commands. "
				<< " Reenter and press return. "
				<< endl;
				cin >> letter;
				ok = false;
				break;

			}



		}


	}



	void yesNoMenu()
	{

		cout << " Enter 1 to choose a room your self" << endl;
		cout << " Enter 2 get assigned a room " << endl;

	}

	int getChoice()
	{
		int choice;
		cin >> choice;
		while (choice<1||choice>2)
		{
			cout << "The only valid choice is 1 or 2" << endl;
			cin >> choice;
		}
		return choice;

	}



