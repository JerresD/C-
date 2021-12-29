#include <iostream>
#include <iomanip>
#include <fstream> 
#include <cctype>
#include <ctime>
using namespace std;

void readData(string[], double[], double[], const int); 
void member(string[], double[], double[],  const int);
void staff(string[], double[], double[],  const int);
void customer(string[], double[], double[],  const int);

int main()
{
	int i = 0;
	const int size = 8;
	string product[size];
	double itemPrice[size], memberPrice[size];
	string menu = "1";
	char choice;
	string code;
	
 	cout << fixed << showpoint << setprecision(2); //To display certain values in 2 decimal points

	while(menu == "1")
	{
		system("cls");
		cout << endl;
		cout << "\t\t======================================" << endl << endl; //For greetings
		cout << "\t\t\tWELCOME TO ONLINE MART" << endl << endl;
		cout << "\t\t======================================" << endl << endl;
		cout << "Are you member/staff? (Y/N) "; //Validation for member and staff
		cin >> choice; 
		
		if(toupper(choice) == 'Y')
		{
			cout << "Please enter your member/staff code: "; 
			cin >> code;
			
			if(code == "MEMBER")
			{
				member(product, itemPrice, memberPrice, size);	
			}
			else if(code == "STAFF")
			{
				staff(product, itemPrice, memberPrice, size);
			}
			else
			{
				cout << "\nERROR! Please try again . . . " << endl << endl; //error message
				cin.clear();
				cin.ignore(1000, '\n'); //clear buffer
				
				system("pause");
			}
		}
		else if(toupper(choice) == 'N')
		{
			customer(product, itemPrice, memberPrice, size);
		}
		else
		{
			cout << "\nERROR! Please try again . . . " << endl << endl; //error message
			cin.clear();
			cin.ignore(1000, '\n'); //clear buffer
			
			system("pause");
		}
	}
} 

void readData(string product[], double itemPrice[], double memberPrice[], const int size)
{
	int i = 0;
	char space;
	string skip;
	ifstream inFile;
	inFile.open("products.txt");
	
	cout << "Reading data from file 'products.txt'... " << endl;
	
	if(!inFile) //In case the file is not existing
	{
		cout << "Cannot open the file. Please exit and try again. " << endl << endl;
		exit(0);
	}
	else
	{
		getline(inFile, skip); //ignore first line
		
		while (!inFile.eof())
		{
			inFile >> product[i]; 
			inFile.get(space);
			inFile >> itemPrice[i]; 
			inFile.get(space);
			inFile >> memberPrice[i];
			i++;
		}
	}
	inFile.close();
}

void member(string product[], double itemPrice[],  double memberPrice[], const int size)
{
	int choice;
	double total;
	double temp;
	double discount;
	double saving;
	double sum1, sum2, sum3, sum4, sum5, sum6, sum7, sum8;
 	int num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0, num6 = 0, num7 = 0, num8 = 0;
 	int x = 1;
 	string menu = "1";
 	ofstream outFile;
		
	while(menu == "1") //loop for menu
	{
	system("cls");	
	readData(product, itemPrice, memberPrice, size);
	
	cout << endl;
	cout << "\t\t======================================" << endl << endl; //For greetings
	cout << "\t\t\tWELCOME TO ONLINE MART" << endl << endl;
	cout << "\t\t======================================" << endl << endl;
	
	cout << "Which product you want to buy?" << endl; //menu
	cout << "---------------------------------------------------------------" << endl;
	cout << "NO.  |  PRODUCT \t\t\t |  PRICE (RM)" << endl;
	cout << "---------------------------------------------------------------" << endl;
	
	for(int i = 0; i < size; i++)
	{
		cout << (i+1) << "\t" << product[i] << "\t\t\t\t" << memberPrice[i] << endl;
	}
	cout << "Your total spent is: RM " << total << endl << endl;
	cout << "Press '9' to purchase." << endl; //billing
	cout << "Press '0' to exit." << endl << endl; //exit
	cout << "Which option you want to select? ";
	cin >> choice;
		
	switch(choice)
	{
		case 1:
			system("cls");
							
			cout << "---------------------------------------------------------------" << endl;
			cout << "NO.  |  PRODUCT \t\t\t |  PRICE (RM)" << endl;
			cout << "---------------------------------------------------------------" << endl;
			cout << "1. \t" << product[0] << "\t\t    " << memberPrice[0] << endl << endl;
			cout << "Quantity: ";
			cin >> num1;
			
			while(num1 < 0)
			{
				cout << "Invalid entry." << endl << endl;
				cout << "Quantity: ";
				cin >> num1;	
			}
			
			sum1 = memberPrice[0] * num1;
			total += (memberPrice[0] * num1);
			saving += ((itemPrice[0] - memberPrice[0]) * num1);
			cout << product[0] << " x " << num1 << " = " << "RM " << sum1 << endl; 
			cout << "Your current spent is RM " << total << endl << endl;
			
			break; 
			
		case 2:
			system("cls");
			
			cout << "---------------------------------------------------------------" << endl;
			cout << "NO.  |  PRODUCT \t\t\t |  PRICE (RM)" << endl;
			cout << "---------------------------------------------------------------" << endl;
			cout << "2. \t" << product[1] << "\t\t\t    " << memberPrice[1] << endl << endl;
			cout << "Quantity: ";
			cin >> num2;
			
			while(num2 < 0)
			{
				cout << "Invalid entry." << endl << endl;
				cout << "Quantity: ";
				cin >> num2;	
			}
			
			sum2 = memberPrice[1] * num2;
			total += (memberPrice[1] * num2);
			saving += ((itemPrice[1] - memberPrice[1]) * num2);
			cout << product[1] << " x " << num2 << " = " << "RM " << sum2 << endl; 
			cout << "Your current spent is RM " << total << endl << endl;
			
			break; 
		
		case 3:
			system("cls");
			
			cout << "---------------------------------------------------------------" << endl;
			cout << "NO.  |  PRODUCT \t\t\t |  PRICE (RM)" << endl;
			cout << "---------------------------------------------------------------" << endl;
			cout << "3. \t" << product[2] << "\t\t\t    " << memberPrice[2] << endl << endl;
			cout << "Quantity: ";
			cin >> num3;
			
			while(num3 < 0)
			{
				cout << "Invalid entry." << endl << endl;
				cout << "Quantity: ";
				cin >> num3;	
			}
			
			sum3 = memberPrice[2] * num3;
			total += (memberPrice[2] * num3);
			saving += ((itemPrice[2] - memberPrice[2]) * num3);
			cout << product[2] << " x " << num3 << " = " << "RM " << sum3 << endl; 
			cout << "Your current spent is RM " << total << endl << endl;
			
			break; 
			
		case 4:
			system("cls");
				
			cout << "---------------------------------------------------------------" << endl;
			cout << "NO.  |  PRODUCT \t\t\t |  PRICE (RM)" << endl;
			cout << "---------------------------------------------------------------" << endl;
			cout << "4. \t" << product[3] << "\t\t\t    " << memberPrice[3] << endl << endl;
			cout << "Quantity: ";
			cin >> num4;
			
			while(num4 < 0)
			{
				cout << "Invalid entry." << endl << endl;
				cout << "Quantity: ";
				cin >> num4;	
			}
			
			sum4 = memberPrice[3] * num4;
			total += (memberPrice[3] * num4);
			saving += ((itemPrice[3] - memberPrice[3]) * num4);
			cout << product[3] << " x " << num4 << " = " << "RM " << sum4 << endl; 
			cout << "Your current spent is RM " << total << endl << endl;
			
			break; 
		
		case 5:
			system("cls");
			
			cout << "---------------------------------------------------------------" << endl;
			cout << "NO.  |  PRODUCT \t\t\t |  PRICE (RM)" << endl;
			cout << "---------------------------------------------------------------" << endl;
			cout << "5. \t" << product[4] << "\t\t\t    " << memberPrice[4] << endl << endl;
			cout << "Quantity: ";
			cin >> num5;
			
			while(num5 < 0)
			{
				cout << "Invalid entry." << endl << endl;
				cout << "Quantity: ";
				cin >> num5;	
			}
			
			sum5 = memberPrice[4] * num5;
			total += (memberPrice[4] * num5);
			saving += ((itemPrice[4] - memberPrice[4]) * num5);
			cout << product[4] << " x " << num5 << " = " << "RM " << sum5 << endl; 
			cout << "Your current spent is RM " << total << endl << endl;
			
			break; 
			
		case 6:
			system("cls");
			
			cout << "---------------------------------------------------------------" << endl;
			cout << "NO.  |  PRODUCT \t\t\t |  PRICE (RM)" << endl;
			cout << "---------------------------------------------------------------" << endl;
			cout << "6. \t" << product[5] << "\t\t    " << memberPrice[5] << endl << endl;
			cout << "Quantity: ";
			cin >> num6;
			
			while(num6 < 0)
			{
				cout << "Invalid entry." << endl << endl;
				cout << "Quantity: ";
				cin >> num6;	
			}
			
			sum6 = memberPrice[5] * num6;
			total += (memberPrice[5] * num6);
			saving += ((itemPrice[5] - memberPrice[5]) * num6);
			cout << product[5] << " x " << num6 << " = " << "RM " << sum6 << endl; 
			cout << "Your current spent is RM " << total << endl << endl;
			
			break; 
			
		case 7:
			system("cls");
			
			cout << "---------------------------------------------------------------" << endl;
			cout << "NO.  |  PRODUCT \t\t\t |  PRICE (RM)" << endl;
			cout << "---------------------------------------------------------------" << endl;
			cout << "7. \t" << product[6] << "\t    " << memberPrice[6] << endl << endl;
			cout << "Quantity: ";
			cin >> num7;
			
			while(num7 < 0)
			{
				cout << "Invalid entry." << endl << endl;
				cout << "Quantity: ";
				cin >> num7;	
			}
			
			sum7 = memberPrice[6] * num7;
			total += (memberPrice[6] * num7);
			saving += ((itemPrice[6] - memberPrice[6]) * num7);
			cout << product[6] << " x " << num7 << " = " << "RM " << sum7 << endl; 
			cout << "Your current spent is RM " << total << endl << endl;
			
			break; 
			
		case 8:
			system("cls");
			
			cout << "---------------------------------------------------------------" << endl;
			cout << "NO.  |  PRODUCT \t\t\t |  PRICE (RM)" << endl;
			cout << "---------------------------------------------------------------" << endl;
			cout << "8. \t" << product[7] << "\t\t    " << memberPrice[7] << endl << endl;
			cout << "Quantity: ";
			cin >> num8;
			
			while(num8 < 0)
			{
				cout << "Invalid entry." << endl << endl;
				cout << "Quantity: ";
				cin >> num8;	
			}
			
			sum8 = memberPrice[7] * num8;
			total += (memberPrice[7] * num8);
			saving += ((itemPrice[7] - memberPrice[7]) * num8);
			cout << product[7] << " x " << num8 << " = " << "RM " << sum8 << endl; 
			cout << "Your current spent is RM " << total << endl << endl;
			
			break;
		
		case 9: //billing
			system("cls");
		
			cout << "Your shopping list: " << endl << endl;
			if(num1 > 0)
				cout << x++ << ". " << product[0] << " x " << num1 << " = RM " << sum1 << endl;
			if(num2 > 0)
				cout << x++ << ". " << product[1] << " x " << num2 << " = RM " << sum2 << endl;
			if(num3 > 0)
				cout << x++ << ". " << product[2] << " x " << num3 << " = RM " << sum3 << endl;
			if(num4 > 0)
				cout << x++ << ". " << product[3] << " x " << num4 << " = RM " << sum4 << endl;
			if(num5 > 0)
				cout << x++ << ". " << product[4] << " x " << num5 << " = RM " << sum5 << endl;
			if(num6 > 0)
				cout << x++ << ". " << product[5] << " x " << num6 << " = RM " << sum6 << endl;
			if(num7 > 0)
				cout << x++ << ". " << product[6] << " x " << num7 << " = RM " << sum7 << endl;
			if(num8 > 0)
				cout << x++ << ". " << product[7] << " x " << num8 << " = RM " << sum8 << endl;
			
			cout << "\nYour original spent is: RM " << total << endl;	
			temp = total;			
			
			if(total > 300) 
			{
				discount = total * 0.05;
				saving += discount;
				total *= 0.95;
				cout << "Discount = 5%" << endl;
				cout << "Amount of discount: RM " << discount  << endl;
				cout << "You has achieved RM " << saving << " savings. " << endl << endl;
				cout << "Your final total amount is: RM " << total << endl << endl;	
				cout << "======================================================" << endl;
				cout << "\t\tThank you for using!" << endl;
				cout << "======================================================" << endl;
				
				{outFile.open("receipt.txt");
	
				time_t now = time(0);
				char* dt = ctime(&now);
				outFile << dt << endl << endl;
				
				outFile << "Your shopping list: " << endl << endl;
				if(num1 > 0)
					outFile << x++ << ". " << product[0] << " x " << num1 << " = RM " << sum1 << endl;
				if(num2 > 0)
					outFile << x++ << ". " << product[1] << " x " << num2 << " = RM " << sum2 << endl;
				if(num3 > 0)
					outFile << x++ << ". " << product[2] << " x " << num3 << " = RM " << sum3 << endl;
				if(num4 > 0)
					outFile << x++ << ". " << product[3] << " x " << num4 << " = RM " << sum4 << endl;
				if(num5 > 0)
					outFile << x++ << ". " << product[4] << " x " << num5 << " = RM " << sum5 << endl;
				if(num6 > 0)
					outFile << x++ << ". " << product[5] << " x " << num6 << " = RM " << sum6 << endl;
				if(num7 > 0)
					outFile << x++ << ". " << product[6] << " x " << num7 << " = RM " << sum7 << endl;
				if(num8 > 0)
					outFile << x++ << ". " << product[7] << " x " << num8 << " = RM " << sum8 << endl;
				
				outFile << "\nYour original spent is: RM " << temp << endl;
				outFile << "Discount = 5%" << endl;
				outFile << "Amount of discount: RM " << discount  << endl;
				outFile << "You has achieved RM " << saving << " savings. " << endl << endl;
				outFile << "Your final total amount is: RM " << total << endl << endl;	
				outFile << "======================================================" << endl;
				outFile << "\t\tThank you for using!" << endl;
				outFile << "======================================================" << endl;
			
				outFile.close(); }
				
				exit(0);					
			}
			else
			{
				cout << "Discount = 0%" << endl;
				cout << "You has achieved RM " << saving << " savings. " << endl << endl;
				cout << "Your final total amount is: RM " << total << endl << endl;
				cout << "======================================================" << endl;
				cout << "\t\tThank you for using!" << endl;
				cout << "======================================================" << endl;
				
				{outFile.open("receipt.txt");
	
				time_t now = time(0);
				char* dt = ctime(&now);
				outFile << dt << endl << endl;
				
				outFile << "Your shopping list: " << endl << endl;
				if(num1 > 0)
					outFile << x++ << ". " << product[0] << " x " << num1 << " = RM " << sum1 << endl;
				if(num2 > 0)
					outFile << x++ << ". " << product[1] << " x " << num2 << " = RM " << sum2 << endl;
				if(num3 > 0)
					outFile << x++ << ". " << product[2] << " x " << num3 << " = RM " << sum3 << endl;
				if(num4 > 0)
					outFile << x++ << ". " << product[3] << " x " << num4 << " = RM " << sum4 << endl;
				if(num5 > 0)
					outFile << x++ << ". " << product[4] << " x " << num5 << " = RM " << sum5 << endl;
				if(num6 > 0)
					outFile << x++ << ". " << product[5] << " x " << num6 << " = RM " << sum6 << endl;
				if(num7 > 0)
					outFile << x++ << ". " << product[6] << " x " << num7 << " = RM " << sum7 << endl;
				if(num8 > 0)
					outFile << x++ << ". " << product[7] << " x " << num8 << " = RM " << sum8 << endl;
				
				outFile << "\nYour original spent is: RM " << temp << endl;
				outFile << "Discount = 0%" << endl;
				outFile << "You has achieved RM " << saving << " savings. " << endl << endl;
				outFile << "Your final total amount is: RM " << total << endl << endl;	
				outFile << "======================================================" << endl;
				outFile << "\t\tThank you for using!" << endl;
				outFile << "======================================================" << endl;
		
			outFile.close(); }
				
				exit(0);
			}
							
			break;
			
		case 0: //exit
			system("cls");
			cout << "\n\n======================================================" << endl;
			cout << "\t\tThank you for using!" << endl;
			cout << "======================================================" << endl;
			exit(0);
			break;
		
		default:
			cout << "Invalid entry." << endl << endl;
			break;		
		}
		system("pause");	
	}
}

void staff(string product[], double itemPrice[],  double memberPrice[], const int size)
{
	int choice;
	double total;
	double discount;
	double saving;
	double staffPrice[size];
	double sum1, sum2, sum3, sum4, sum5, sum6, sum7, sum8;
 	int num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0, num6 = 0, num7 = 0, num8 = 0;
 	int x = 1;
 	string menu = "1";
 	ofstream outFile;
		
	while(menu == "1") //loop for menu
	{
	system("cls");	
	readData(product, itemPrice, memberPrice, size);
	
	for(int i = 0; i < size; i++)
	{
		if(itemPrice[i] >= 5 && itemPrice[i] <= 30)
			staffPrice[i] = itemPrice[i] - 1;
		else if(itemPrice[i] >= 31 && itemPrice[i] <= 99)
			staffPrice[i] = itemPrice[i] - 5;
		else if(itemPrice[i] >= 100)
			staffPrice[i] = itemPrice[i] - 10;
		else
			staffPrice[i] = itemPrice[i];
	}
		
	cout << endl;
	cout << "\t\t======================================" << endl << endl; //For greetings
	cout << "\t\t\tWELCOME TO ONLINE MART" << endl << endl;
	cout << "\t\t======================================" << endl << endl;
	
	cout << "Which product you want to buy?" << endl; //menu
	cout << "---------------------------------------------------------------" << endl;
	cout << "NO.  |  PRODUCT \t\t\t |  PRICE (RM)" << endl;
	cout << "---------------------------------------------------------------" << endl;
	
	for(int i = 0; i < size; i++)
	{
		cout << (i+1) << "\t" << product[i] << "\t\t\t\t" << staffPrice[i] << endl;
	}
	cout << "Your total spent is: RM " << total << endl << endl;
	cout << "Press '9' to purchase." << endl; //billing
	cout << "Press '0' to exit." << endl << endl; //exit
	cout << "Which option you want to select? ";
	cin >> choice;
		
	switch(choice)
	{
		case 1:
			system("cls");
							
			cout << "---------------------------------------------------------------" << endl;
			cout << "NO.  |  PRODUCT \t\t\t |  PRICE (RM)" << endl;
			cout << "---------------------------------------------------------------" << endl;
			cout << "1. \t" << product[0] << "\t\t    " << staffPrice[0] << endl << endl;
			cout << "Quantity: ";
			cin >> num1;
			
			while(num1 < 0)
			{
				cout << "Invalid entry." << endl << endl;
				cout << "Quantity: ";
				cin >> num1;	
			}
			
			sum1 = staffPrice[0] * num1;
			total += (staffPrice[0] * num1);
			saving += ((itemPrice[0] - staffPrice[0]) * num1);
			cout << product[0] << " x " << num1 << " = " << "RM " << sum1 << endl; 
			cout << "Your current spent is RM " << total << endl << endl;
			
			break; 
			
		case 2:
			system("cls");
			
			cout << "---------------------------------------------------------------" << endl;
			cout << "NO.  |  PRODUCT \t\t\t |  PRICE (RM)" << endl;
			cout << "---------------------------------------------------------------" << endl;
			cout << "2. \t" << product[1] << "\t\t\t    " << staffPrice[1] << endl << endl;
			cout << "Quantity: ";
			cin >> num2;
			
			while(num2 < 0)
			{
				cout << "Invalid entry." << endl << endl;
				cout << "Quantity: ";
				cin >> num2;	
			}
			
			sum2 = staffPrice[1] * num2;
			total += (staffPrice[1] * num2);
			saving += ((itemPrice[1] - staffPrice[1]) * num2);
			cout << product[1] << " x " << num2 << " = " << "RM " << sum2 << endl; 
			cout << "Your current spent is RM " << total << endl << endl;
			
			break; 
		
		case 3:
			system("cls");
			
			cout << "---------------------------------------------------------------" << endl;
			cout << "NO.  |  PRODUCT \t\t\t |  PRICE (RM)" << endl;
			cout << "---------------------------------------------------------------" << endl;
			cout << "3. \t" << product[2] << "\t\t\t    " << staffPrice[2] << endl << endl;
			cout << "Quantity: ";
			cin >> num3;
			
			while(num3 < 0)
			{
				cout << "Invalid entry." << endl << endl;
				cout << "Quantity: ";
				cin >> num3;	
			}
			
			sum3 = staffPrice[2] * num3;
			total += (staffPrice[2] * num3);
			saving += ((itemPrice[2] - staffPrice[2]) * num3);
			cout << product[2] << " x " << num3 << " = " << "RM " << sum3 << endl; 
			cout << "Your current spent is RM " << total << endl << endl;
			
			break; 
			
		case 4:
			system("cls");
				
			cout << "---------------------------------------------------------------" << endl;
			cout << "NO.  |  PRODUCT \t\t\t |  PRICE (RM)" << endl;
			cout << "---------------------------------------------------------------" << endl;
			cout << "4. \t" << product[3] << "\t\t\t    " << staffPrice[3] << endl << endl;
			cout << "Quantity: ";
			cin >> num4;
			
			while(num4 < 0)
			{
				cout << "Invalid entry." << endl << endl;
				cout << "Quantity: ";
				cin >> num4;	
			}
			
			sum4 = staffPrice[3] * num4;
			total += (staffPrice[3] * num4);
			saving += ((itemPrice[3] - staffPrice[3]) * num4);
			cout << product[3] << " x " << num4 << " = " << "RM " << sum4 << endl; 
			cout << "Your current spent is RM " << total << endl << endl;
			
			break; 
		
		case 5:
			system("cls");
			
			cout << "---------------------------------------------------------------" << endl;
			cout << "NO.  |  PRODUCT \t\t\t |  PRICE (RM)" << endl;
			cout << "---------------------------------------------------------------" << endl;
			cout << "5. \t" << product[4] << "\t\t\t    " << staffPrice[4] << endl << endl;
			cout << "Quantity: ";
			cin >> num5;
			
			while(num5 < 0)
			{
				cout << "Invalid entry." << endl << endl;
				cout << "Quantity: ";
				cin >> num5;	
			}
			
			sum5 = staffPrice[4] * num5;
			total += (staffPrice[4] * num5);
			saving += ((itemPrice[4] - staffPrice[4]) * num5);
			cout << product[4] << " x " << num5 << " = " << "RM " << sum5 << endl; 
			cout << "Your current spent is RM " << total << endl << endl;
			
			break; 
			
		case 6:
			system("cls");
			
			cout << "---------------------------------------------------------------" << endl;
			cout << "NO.  |  PRODUCT \t\t\t |  PRICE (RM)" << endl;
			cout << "---------------------------------------------------------------" << endl;
			cout << "6. \t" << product[5] << "\t\t    " << staffPrice[5] << endl << endl;
			cout << "Quantity: ";
			cin >> num6;
			
			while(num6 < 0)
			{
				cout << "Invalid entry." << endl << endl;
				cout << "Quantity: ";
				cin >> num6;	
			}
			
			sum6 = staffPrice[5] * num6;
			total += (staffPrice[5] * num6);
			saving += ((itemPrice[5] - staffPrice[5]) * num6);
			cout << product[5] << " x " << num6 << " = " << "RM " << sum6 << endl; 
			cout << "Your current spent is RM " << total << endl << endl;
			
			break; 
			
		case 7:
			system("cls");
			
			cout << "---------------------------------------------------------------" << endl;
			cout << "NO.  |  PRODUCT \t\t\t |  PRICE (RM)" << endl;
			cout << "---------------------------------------------------------------" << endl;
			cout << "7. \t" << product[6] << "\t    " << staffPrice[6] << endl << endl;
			cout << "Quantity: ";
			cin >> num7;
			
			while(num7 < 0)
			{
				cout << "Invalid entry." << endl << endl;
				cout << "Quantity: ";
				cin >> num7;	
			}
			
			sum7 = staffPrice[6] * num7;
			total += (staffPrice[6] * num7);
			saving += ((itemPrice[6] - staffPrice[6]) * num7);
			cout << product[6] << " x " << num7 << " = " << "RM " << sum7 << endl; 
			cout << "Your current spent is RM " << total << endl << endl;
			
			break; 
			
		case 8:
			system("cls");
			
			cout << "---------------------------------------------------------------" << endl;
			cout << "NO.  |  PRODUCT \t\t\t |  PRICE (RM)" << endl;
			cout << "---------------------------------------------------------------" << endl;
			cout << "8. \t" << product[7] << "\t\t    " << staffPrice[7] << endl << endl;
			cout << "Quantity: ";
			cin >> num8;
			
			while(num8 < 0)
			{
				cout << "Invalid entry." << endl << endl;
				cout << "Quantity: ";
				cin >> num8;	
			}
			
			sum8 = staffPrice[7] * num8;
			total += (staffPrice[7] * num8);
			saving += ((itemPrice[7] - staffPrice[7]) * num8);
			cout << product[7] << " x " << num8 << " = " << "RM " << sum8 << endl; 
			cout << "Your current spent is RM " << total << endl << endl;
			
			break;
		
		case 9: //billing
			system("cls");
		
			cout << "Your shopping list: " << endl << endl;
			if(num1 > 0)
				cout << x++ << ". " << product[0] << " x " << num1 << " = RM " << sum1 << endl;
			if(num2 > 0)
				cout << x++ << ". " << product[1] << " x " << num2 << " = RM " << sum2 << endl;
			if(num3 > 0)
				cout << x++ << ". " << product[2] << " x " << num3 << " = RM " << sum3 << endl;
			if(num4 > 0)
				cout << x++ << ". " << product[3] << " x " << num4 << " = RM " << sum4 << endl;
			if(num5 > 0)
				cout << x++ << ". " << product[4] << " x " << num5 << " = RM " << sum5 << endl;
			if(num6 > 0)
				cout << x++ << ". " << product[5] << " x " << num6 << " = RM " << sum6 << endl;
			if(num7 > 0)
				cout << x++ << ". " << product[6] << " x " << num7 << " = RM " << sum7 << endl;
			if(num8 > 0)
				cout << x++ << ". " << product[7] << " x " << num8 << " = RM " << sum8 << endl;
					
			cout << "\nYou has achieved RM " << saving << " savings. " << endl << endl;
			cout << "Your final total amount is: RM " << total << endl << endl;
			cout << "======================================================" << endl;
			cout << "\t\tThank you for using!" << endl;
			cout << "======================================================" << endl;
			
			{outFile.open("receipt.txt");
	
			time_t now = time(0);
			char* dt = ctime(&now);
			outFile << dt << endl << endl;
			
			outFile << "Your shopping list: " << endl << endl;
			if(num1 > 0)
				outFile << x++ << ". " << product[0] << " x " << num1 << " = RM " << sum1 << endl;
			if(num2 > 0)
				outFile << x++ << ". " << product[1] << " x " << num2 << " = RM " << sum2 << endl;
			if(num3 > 0)
				outFile << x++ << ". " << product[2] << " x " << num3 << " = RM " << sum3 << endl;
			if(num4 > 0)
				outFile << x++ << ". " << product[3] << " x " << num4 << " = RM " << sum4 << endl;
			if(num5 > 0)
				outFile << x++ << ". " << product[4] << " x " << num5 << " = RM " << sum5 << endl;
			if(num6 > 0)
				outFile << x++ << ". " << product[5] << " x " << num6 << " = RM " << sum6 << endl;
			if(num7 > 0)
				outFile << x++ << ". " << product[6] << " x " << num7 << " = RM " << sum7 << endl;
			if(num8 > 0)
				outFile << x++ << ". " << product[7] << " x " << num8 << " = RM " << sum8 << endl;
			
			outFile << "You has achieved RM " << saving << " savings. " << endl << endl;
			outFile << "Your final total amount is: RM " << total << endl << endl;	
			outFile << "======================================================" << endl;
			outFile << "\t\tThank you for using!" << endl;
			outFile << "======================================================" << endl;
		
			outFile.close(); }
			
			exit(0);
				
			break;
			
		case 0: //exit
			system("cls");
			cout << "\n\n======================================================" << endl;
			cout << "\t\tThank you for using!" << endl;
			cout << "======================================================" << endl;
			exit(0);
			break;
		
		default:
			cout << "Invalid entry." << endl << endl;
			break;		
		}
		system("pause");	
	}
}

void customer(string product[], double itemPrice[],  double memberPrice[], const int size)
{
	int choice;
	double total;
	double temp;
	double discount;
	double sum1, sum2, sum3, sum4, sum5, sum6, sum7, sum8;
 	int num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0, num6 = 0, num7 = 0, num8 = 0;
 	int x = 1;
 	string menu = "1";
 	ofstream outFile;
		
	while(menu == "1") //loop for menu
	{
	system("cls");	
	readData(product, itemPrice, memberPrice, size);
	
	cout << endl;
	cout << "\t\t======================================" << endl << endl; //For greetings
	cout << "\t\t\tWELCOME TO ONLINE MART" << endl << endl;
	cout << "\t\t======================================" << endl << endl;
	
	cout << "Which product you want to buy?" << endl; //menu
	cout << "---------------------------------------------------------------" << endl;
	cout << "NO.  |  PRODUCT \t\t\t |  PRICE (RM)" << endl;
	cout << "---------------------------------------------------------------" << endl;
	
	for(int i = 0; i < size; i++)
	{
		cout << (i+1) << "\t" << product[i] << "\t\t\t\t" << itemPrice[i] << endl;
	}
	cout << "Your total spent is: RM " << total << endl << endl;
	cout << "Press '9' to purchase." << endl; //billing
	cout << "Press '0' to exit." << endl << endl; //exit
	cout << "Which option you want to select? ";
	cin >> choice;
		
	switch(choice)
	{
		case 1:
			system("cls");
							
			cout << "---------------------------------------------------------------" << endl;
			cout << "NO.  |  PRODUCT \t\t\t |  PRICE (RM)" << endl;
			cout << "---------------------------------------------------------------" << endl;
			cout << "1. \t" << product[0] << "\t\t    " << itemPrice[0] << endl << endl;
			cout << "Quantity: ";
			cin >> num1;
			
			while(num1 < 0)
			{
				cout << "Invalid entry." << endl << endl;
				cout << "Quantity: ";
				cin >> num1;	
			}
			
			sum1 = itemPrice[0] * num1;
			total += (itemPrice[0] * num1);
			cout << product[0] << " x " << num1 << " = " << "RM " << sum1 << endl; 
			cout << "Your current spent is RM " << total << endl << endl;
			
			break; 
			
		case 2:
			system("cls");
			
			cout << "---------------------------------------------------------------" << endl;
			cout << "NO.  |  PRODUCT \t\t\t |  PRICE (RM)" << endl;
			cout << "---------------------------------------------------------------" << endl;
			cout << "2. \t" << product[1] << "\t\t\t    " << itemPrice[1] << endl << endl;
			cout << "Quantity: ";
			cin >> num2;
			
			while(num2 < 0)
			{
				cout << "Invalid entry." << endl << endl;
				cout << "Quantity: ";
				cin >> num2;	
			}
			
			sum2 = itemPrice[1] * num2;
			total += (itemPrice[1] * num2);
			cout << product[1] << " x " << num2 << " = " << "RM " << sum2 << endl; 
			cout << "Your current spent is RM " << total << endl << endl;
			
			break; 
		
		case 3:
			system("cls");
			
			cout << "---------------------------------------------------------------" << endl;
			cout << "NO.  |  PRODUCT \t\t\t |  PRICE (RM)" << endl;
			cout << "---------------------------------------------------------------" << endl;
			cout << "3. \t" << product[2] << "\t\t\t    " << itemPrice[2] << endl << endl;
			cout << "Quantity: ";
			cin >> num3;
			
			while(num3 < 0)
			{
				cout << "Invalid entry." << endl << endl;
				cout << "Quantity: ";
				cin >> num3;	
			}
			
			sum3 = itemPrice[2] * num3;
			total += (itemPrice[2] * num3);
			cout << product[2] << " x " << num3 << " = " << "RM " << sum3 << endl; 
			cout << "Your current spent is RM " << total << endl << endl;
			
			break; 
			
		case 4:
			system("cls");
				
			cout << "---------------------------------------------------------------" << endl;
			cout << "NO.  |  PRODUCT \t\t\t |  PRICE (RM)" << endl;
			cout << "---------------------------------------------------------------" << endl;
			cout << "4. \t" << product[3] << "\t\t\t    " << itemPrice[3] << endl << endl;
			cout << "Quantity: ";
			cin >> num4;
			
			while(num4 < 0)
			{
				cout << "Invalid entry." << endl << endl;
				cout << "Quantity: ";
				cin >> num4;	
			}
			
			sum4 = itemPrice[3] * num4;
			total += (itemPrice[3] * num4);
			cout << product[3] << " x " << num4 << " = " << "RM " << sum4 << endl; 
			cout << "Your current spent is RM " << total << endl << endl;
			
			break; 
		
		case 5:
			system("cls");
			
			cout << "---------------------------------------------------------------" << endl;
			cout << "NO.  |  PRODUCT \t\t\t |  PRICE (RM)" << endl;
			cout << "---------------------------------------------------------------" << endl;
			cout << "5. \t" << product[4] << "\t\t\t    " << itemPrice[4] << endl << endl;
			cout << "Quantity: ";
			cin >> num5;
			
			while(num5 < 0)
			{
				cout << "Invalid entry." << endl << endl;
				cout << "Quantity: ";
				cin >> num5;	
			}
			
			sum5 = itemPrice[4] * num5;
			total += (itemPrice[4] * num5);
			cout << product[4] << " x " << num5 << " = " << "RM " << sum5 << endl; 
			cout << "Your current spent is RM " << total << endl << endl;
			
			break; 
			
		case 6:
			system("cls");
			
			cout << "---------------------------------------------------------------" << endl;
			cout << "NO.  |  PRODUCT \t\t\t |  PRICE (RM)" << endl;
			cout << "---------------------------------------------------------------" << endl;
			cout << "6. \t" << product[5] << "\t\t    " << itemPrice[5] << endl << endl;
			cout << "Quantity: ";
			cin >> num6;
			
			while(num6 < 0)
			{
				cout << "Invalid entry." << endl << endl;
				cout << "Quantity: ";
				cin >> num6;	
			}
			
			sum6 = itemPrice[5] * num6;
			total += (itemPrice[5] * num6);
			cout << product[5] << " x " << num6 << " = " << "RM " << sum6 << endl; 
			cout << "Your current spent is RM " << total << endl << endl;
			
			break; 
			
		case 7:
			system("cls");
			
			cout << "---------------------------------------------------------------" << endl;
			cout << "NO.  |  PRODUCT \t\t\t |  PRICE (RM)" << endl;
			cout << "---------------------------------------------------------------" << endl;
			cout << "7. \t" << product[6] << "\t    " << itemPrice[6] << endl << endl;
			cout << "Quantity: ";
			cin >> num7;
			
			while(num7 < 0)
			{
				cout << "Invalid entry." << endl << endl;
				cout << "Quantity: ";
				cin >> num7;	
			}
			
			sum7 = itemPrice[6] * num7;
			total += (itemPrice[6] * num7);
			cout << product[6] << " x " << num7 << " = " << "RM " << sum7 << endl; 
			cout << "Your current spent is RM " << total << endl << endl;
			
			break; 
			
		case 8:
			system("cls");
			
			cout << "---------------------------------------------------------------" << endl;
			cout << "NO.  |  PRODUCT \t\t\t |  PRICE (RM)" << endl;
			cout << "---------------------------------------------------------------" << endl;
			cout << "8. \t" << product[7] << "\t\t    " << itemPrice[7] << endl << endl;
			cout << "Quantity: ";
			cin >> num8;
			
			while(num8 < 0)
			{
				cout << "Invalid entry." << endl << endl;
				cout << "Quantity: ";
				cin >> num8;	
			}
			
			sum8 = itemPrice[7] * num8;
			total += (itemPrice[7] * num8);
			cout << product[7] << " x " << num8 << " = " << "RM " << sum8 << endl; 
			cout << "Your current spent is RM " << total << endl << endl;
			
			break;
		
		case 9: //billing
			system("cls");
		
			cout << "Your shopping list: " << endl << endl;
			if(num1 > 0)
				cout << x++ << ". " << product[0] << " x " << num1 << " = RM " << sum1 << endl;
			if(num2 > 0)
				cout << x++ << ". " << product[1] << " x " << num2 << " = RM " << sum2 << endl;
			if(num3 > 0)
				cout << x++ << ". " << product[2] << " x " << num3 << " = RM " << sum3 << endl;
			if(num4 > 0)
				cout << x++ << ". " << product[3] << " x " << num4 << " = RM " << sum4 << endl;
			if(num5 > 0)
				cout << x++ << ". " << product[4] << " x " << num5 << " = RM " << sum5 << endl;
			if(num6 > 0)
				cout << x++ << ". " << product[5] << " x " << num6 << " = RM " << sum6 << endl;
			if(num7 > 0)
				cout << x++ << ". " << product[6] << " x " << num7 << " = RM " << sum7 << endl;
			if(num8 > 0)
				cout << x++ << ". " << product[7] << " x " << num8 << " = RM " << sum8 << endl;
			
			cout << "\nYour original spent is: RM " << total << endl;
			temp = total;				
			
			if(total > 300) 
			{
				discount = total * 0.05;
				total *= 0.95;
				cout << "Discount = 5%" << endl;
				cout << "Amount of discount: RM " << discount  << endl;
				cout << "Your final total amount is: RM " << total << endl << endl;	
				cout << "======================================================" << endl;
				cout << "\t\tThank you for using!" << endl;
				cout << "======================================================" << endl;
				
				{outFile.open("receipt.txt");
	
				time_t now = time(0);
				char* dt = ctime(&now);
				outFile << dt << endl << endl;
				
				outFile << "Your shopping list: " << endl << endl;
				if(num1 > 0)
					outFile << x++ << ". " << product[0] << " x " << num1 << " = RM " << sum1 << endl;
				if(num2 > 0)
					outFile << x++ << ". " << product[1] << " x " << num2 << " = RM " << sum2 << endl;
				if(num3 > 0)
					outFile << x++ << ". " << product[2] << " x " << num3 << " = RM " << sum3 << endl;
				if(num4 > 0)
					outFile << x++ << ". " << product[3] << " x " << num4 << " = RM " << sum4 << endl;
				if(num5 > 0)
					outFile << x++ << ". " << product[4] << " x " << num5 << " = RM " << sum5 << endl;
				if(num6 > 0)
					outFile << x++ << ". " << product[5] << " x " << num6 << " = RM " << sum6 << endl;
				if(num7 > 0)
					outFile << x++ << ". " << product[6] << " x " << num7 << " = RM " << sum7 << endl;
				if(num8 > 0)
					outFile << x++ << ". " << product[7] << " x " << num8 << " = RM " << sum8 << endl;
				
				outFile << "\nYour original spent is: RM " << temp << endl;
				outFile << "Discount = 5%" << endl;
				outFile << "Amount of discount: RM " << discount  << endl;
				outFile << "Your final total amount is: RM " << total << endl << endl;	
				outFile << "======================================================" << endl;
				outFile << "\t\tThank you for using!" << endl;
				outFile << "======================================================" << endl;
		
				outFile.close(); }
				
				exit(0);					
			}
			else
			{
				cout << "Discount = 0%" << endl;
				cout << "Your final total amount is: RM " << total << endl << endl;
				cout << "======================================================" << endl;
				cout << "\t\tThank you for using!" << endl;
				cout << "======================================================" << endl;
				
				{outFile.open("receipt.txt");
	
				time_t now = time(0);
				char* dt = ctime(&now);
				outFile << dt << endl << endl;
				
				outFile << "Your shopping list: " << endl << endl;
				if(num1 > 0)
					outFile << x++ << ". " << product[0] << " x " << num1 << " = RM " << sum1 << endl;
				if(num2 > 0)
					outFile << x++ << ". " << product[1] << " x " << num2 << " = RM " << sum2 << endl;
				if(num3 > 0)
					outFile << x++ << ". " << product[2] << " x " << num3 << " = RM " << sum3 << endl;
				if(num4 > 0)
					outFile << x++ << ". " << product[3] << " x " << num4 << " = RM " << sum4 << endl;
				if(num5 > 0)
					outFile << x++ << ". " << product[4] << " x " << num5 << " = RM " << sum5 << endl;
				if(num6 > 0)
					outFile << x++ << ". " << product[5] << " x " << num6 << " = RM " << sum6 << endl;
				if(num7 > 0)
					outFile << x++ << ". " << product[6] << " x " << num7 << " = RM " << sum7 << endl;
				if(num8 > 0)
					outFile << x++ << ". " << product[7] << " x " << num8 << " = RM " << sum8 << endl;
				
				outFile << "\nYour original spent is: RM " << temp << endl;
				outFile << "Discount = 0%" << endl;
				outFile << "Your final total amount is: RM " << total << endl << endl;	
				outFile << "======================================================" << endl;
				outFile << "\t\tThank you for using!" << endl;
				outFile << "======================================================" << endl;
		
				outFile.close(); }
				
				exit(0);
			}
				
			break;
			
		case 0: //exit
			system("cls");
			cout << "\n\n======================================================" << endl;
			cout << "\t\tThank you for using!" << endl;
			cout << "======================================================" << endl;
			exit(0);
			break;
		
		default:
			cout << "Invalid entry." << endl << endl;
			break;		
		}
		system("pause");	
	}
}

