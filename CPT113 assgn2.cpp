#include <iostream> 
#include "INHERITLINKEDLIST2.h" 
using namespace std; 

int main() 
{
	orderedLinkedList<string, string, int, double> orderedList;
	unorderedLinkedList<string, string, int, double> unorderedList;

	string name;
	string matric;
	int year;
	double cgpa;
	string deleteItem, searchItem;
	string menu;
	int type, choice, select, option;
	char status;
	
	cout << "Welcome to Student Information System" << endl << endl;
	cout << "Which type of linked list you want to test?" << endl;
	cout << "1. Ordered linked list. "<< endl;
	cout << "2. Unordered linked list. " << endl;
	cin >> type;
	
	if(type == 1)
		menu = "1";
	else if(type == 2)
		menu = "2";
	else
		cout << "Invalid entry. "<< endl;
			
	while(menu == "1") //ordered
	{
		system("cls");
		
		cout << "=== ORDERED LINKED LIST ===" << endl;
		cout << "===== STUDENT RECORDS =====" << endl << endl;
		cout << "1. Add student information" << endl;
		cout << "2. Delete student information" << endl;
		cout << "3. Search student information" << endl;		
		cout << "4. Display student list" << endl;
		cout << "5. Quit" << endl << endl;
		cout << "Which option you want to select?";
		cin >> choice;
		
		switch(choice)
		{
			case 1:
				system("cls");
				status = 'y';
				
				cout << "Add student information. " << endl;
				
				while(status == 'y' || status == 'Y')
				{
					cout << "Student name: ";
					cin >> name;
					cout << "Matric number: ";
					cin >> matric;
					cout << "Current year: ";
					cin >> year;
					cout << "CGPA: ";
					cin >> cgpa;
					orderedList.insert(name, matric, year, cgpa);
					cout << endl;
					cout << "Insert Y to continue, or else stop to add. ";
					cin >> status;
				}
				break;
			
			case 2:
				system("cls");
				
				cout << "Delete student information" << endl << endl;
				cout << "Enter student name or matric number that need to be deleted: ";
				cin >> deleteItem;
				orderedList.deleteNode(deleteItem);
				
				break;
			
			case 3:
				system("cls");
				
				cout << "Search student information" << endl << endl;
				cout << "Choose what to search" << endl;
				cout << "1. Student name" << endl;
				cout << "2. Matric number" << endl;
				cout << "3. Current year" << endl;
				cout << "4. CGPA" << endl;
				cout << "Your selection is: ";
				cin >> select;
				
				switch(select)
				{
					case 1:
						cout << "Key in student name: ";
						cin >> name;
						orderedList.searchName(name);
						break;
					case 2:
						cout << "Key in matric number: ";
						cin >> matric;
						orderedList.searchMatric(matric);
						break;
					case 3:
						cout << "Key in current year: ";
						cin >> year;
						orderedList.searchYear(year);
						break;
					case 4:
						cout << "Key in CGPA: ";
						cin >> cgpa;
						orderedList.searchCGPA(cgpa);
						break;
					default:
						cout << "Invalid entry. " << endl << endl;
						break;
				}
				break;
				
			case 4:
				system("cls");
				
				cout << "Display student list" << endl << endl;
				orderedList.print();
				cout << endl;
				
				break; 
			
			case 5:
				system("cls");
				
				cout << "Thanks for using. " << endl;
				exit(0);
				
				break;
				
			default:
				cout << "Invalid entry." << endl << endl;
				break;
		}
		system("pause");
	}


	while(menu == "2") //unordered
	{
		system("cls");
		
		cout << "== UNORDERED LINKED LIST ==" << endl;
		cout << "===== STUDENT RECORDS =====" << endl << endl;
		cout << "1. Add student information" << endl;
		cout << "2. Delete student information" << endl;
		cout << "3. Search student information" << endl;		
		cout << "4. Display student list" << endl;
		cout << "5. Quit" << endl << endl;
		cout << "Which option you want to select?";
		cin >> choice;
		
		switch(choice)
		{
			case 1:
				system("cls");
				status = 'y';
				
				cout << "Add student information. " << endl;
				cout << "Choose option below: "<< endl;
				cout << "1. Insert at the end. " << endl;
				cout << "2. Insert after specific location. " << endl;
				cin >> option;
				
				if(option == 1)
				{
					while(status == 'y' || status == 'Y')
					{
						cout << "Student name: ";
						cin >> name;
						cout << "Matric number: ";
						cin >> matric;
						cout << "Current year: ";
						cin >> year;
						cout << "CGPA: ";
						cin >> cgpa;
						unorderedList.insertLast(name, matric, year, cgpa);
						cout << endl;
						cout << "Insert Y to continue, or else stop to add. ";
						cin >> status;
					}
				}
				else if(option == 2)
				{
					cout << "Enter a specific name or matric number that existed. ";
					cin >> searchItem;
					
					if(unorderedList.search(searchItem))
					{
					while(status == 'y' || status == 'Y')
					{	
						cout << "Student name: ";
						cin >> name;
						cout << "Matric number: ";
						cin >> matric;
						cout << "Current year: ";
						cin >> year;
						cout << "CGPA: ";
						cin >> cgpa;
						unorderedList.insertAfter(name, matric, year, cgpa, searchItem);
						cout << endl;
						cout << "Insert Y to continue, or else stop to add. ";
						cin >> status;
					}
					}
					else
					{
						cout << "Item not found. "<< endl;
					}
				}
				else
				{
					cout << "Invalid entry. "<< endl;
				}
				
				break;
			
			case 2:
				system("cls");
				
				cout << "Delete student information" << endl << endl;
				cout << "Enter student name or matric number that need to be deleted: ";
				cin >> deleteItem;
				unorderedList.deleteNode(deleteItem);
				
				break;
			
			case 3:
				system("cls");
				
				cout << "Search student information" << endl << endl;
				cout << "Choose what to search" << endl;
				cout << "1. Student name" << endl;
				cout << "2. Matric number" << endl;
				cout << "3. Current year" << endl;
				cout << "4. CGPA" << endl;
				cout << "Your selection is: ";
				cin >> select;
				
				switch(select)
				{
					case 1:
						cout << "Key in student name: ";
						cin >> name;
						unorderedList.searchName(name);
						break;
					case 2:
						cout << "Key in matric number: ";
						cin >> matric;
						unorderedList.searchMatric(matric);
						break;
					case 3:
						cout << "Key in current year: ";
						cin >> year;
						unorderedList.searchYear(year);
						break;
					case 4:
						cout << "Key in CGPA: ";
						cin >> cgpa;
						unorderedList.searchCGPA(cgpa);
						break;
					default:
						cout << "Invalid entry. " << endl << endl;
						break;
				}
				break;
				
			case 4:
				system("cls");
				
				cout << "Display student list" << endl << endl;
				unorderedList.print();
				cout << endl;
				
				break; 
			
			case 5:
				system("cls");
				
				cout << "Thanks for using. " << endl;
				exit(0);
				
				break;
				
			default:
				cout << "Invalid entry." << endl << endl;
				break;
		}
		system("pause");
	}

	return 0;
	

}
