#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
 	const string item1 = "Microwave Oven 1.5L";
 	const string item2 = "Panasonic Iron";
 	const string item3 = "Rice Cooker 1L";
 	const string item4 = "Hair Dryer";
 	const string item5 = "Tiers Shoe Rack";
 	const string item6 = "Kitchen L Shape Carpet";
 	const string item7 = "San Disk Ultra Micro SD 32GB";
 	const string item8 = "Mini Bluetooth Speaker";
 	const double price1 = 299.00;
 	const double price2 = 40.00;
 	const double price3 = 80.00;
 	const double price4 = 50.00;
 	const double price5 = 12.00;
 	const double price6 = 24.00;
 	const double price7 = 40.00;
 	const double price8 = 10.00;
 	const double discount = 0.95;
 	string menu = "1";
 	string tqt = "1";
 	string code;
 	double total;
	double sum1, sum2, sum3, sum4, sum5, sum6, sum7, sum8;
 	int num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0, num6 = 0, num7 = 0, num8 = 0;
 	int x = 1;
 	int choice;
 	char ch;
 	
 	cout << fixed << showpoint << setprecision(2); //To display certain values in 2 decimal points
 		 	
	while(menu == "1") //loop for menu
	{
		
		
		cout << endl;
		cout << "\t\t======================================" << endl << endl; //For greetings
		cout << "\t\t\tWELCOME TO ONLINE MART" << endl << endl;
		cout << "\t\t======================================" << endl << endl;
		
		cout << "Which product you want to buy?" << endl; //menu
		cout << "---------------------------------------------------------------" << endl;
		cout << "NO.  |  PRODUCT \t\t\t |  PRICE (RM)" << endl;
		cout << "---------------------------------------------------------------" << endl;
		cout << "1. \t" << item1 << "\t\t    " << price1 << endl;
		cout << "2. \t" << item2 << "\t\t\t    " << price2 << endl;
		cout << "3. \t" << item3 << "\t\t\t    " << price3 << endl;
		cout << "4. \t" << item4 << "\t\t\t    " << price4 << endl;
		cout << "5. \t" << item5 << "\t\t\t    " << price5 << endl;
		cout << "6. \t" << item6 << "\t\t    " << price6 << endl;
		cout << "7. \t" << item7 << "\t    " << price7 << endl;
		cout << "8. \t" << item8 << "\t\t    " << price8 << endl << endl;
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
				cout << "1. \t" << item1 << "\t\t    " << price1 << endl << endl;
				cout << "Quantity: ";
				cin >> num1;
				
				while(num1 < 0)
				{
					cout << "Invalid entry." << endl << endl;
					cout << "Quantity: ";
					cin >> num1;	
				}
				
				sum1 = price1 * num1;
				total += (price1 * num1);
				cout << item1 << " x " << num1 << " = " << "RM " << sum1 << endl; 
				cout << "Your current spent is RM " << total << endl << endl;
				
				break; 
			
			case 2:
				system("cls");
				
				cout << "---------------------------------------------------------------" << endl;
				cout << "NO.  |  PRODUCT \t\t\t |  PRICE (RM)" << endl;
				cout << "---------------------------------------------------------------" << endl;
				cout << "2. \t" << item2 << "\t\t\t    " << price2 << endl << endl;
				cout << "Quantity: ";
				cin >> num2;
				
				while(num2 < 0)
				{
					cout << "Invalid entry." << endl << endl;
					cout << "Quantity: ";
					cin >> num2;	
				}
				
				sum2 = price2 * num2;
				total += (price2 * num2);
				cout << item2 << " x " << num2 << " = " << "RM " << sum2 << endl; 
				cout << "Your current spent is RM " << total << endl << endl;
				
				break; 
			
			case 3:
				system("cls");
				
				cout << "---------------------------------------------------------------" << endl;
				cout << "NO.  |  PRODUCT \t\t\t |  PRICE (RM)" << endl;
				cout << "---------------------------------------------------------------" << endl;
				cout << "3. \t" << item3 << "\t\t\t    " << price3 << endl << endl;
				cout << "Quantity: ";
				cin >> num3;
				
				while(num3 < 0)
				{
					cout << "Invalid entry." << endl << endl;
					cout << "Quantity: ";
					cin >> num3;	
				}
				
				sum3 = price3 * num3;
				total += (price3 * num3);
				cout << item3 << " x " << num3 << " = " << "RM " << sum3 << endl; 
				cout << "Your current spent is RM " << total << endl << endl;
				
				break; 
				
			case 4:
				system("cls");
				
				cout << "---------------------------------------------------------------" << endl;
				cout << "NO.  |  PRODUCT \t\t\t |  PRICE (RM)" << endl;
				cout << "---------------------------------------------------------------" << endl;
				cout << "4. \t" << item4 << "\t\t\t    " << price4 << endl << endl;
				cout << "Quantity: ";
				cin >> num4;
				
				while(num4 < 0)
				{
					cout << "Invalid entry." << endl << endl;
					cout << "Quantity: ";
					cin >> num4;	
				}
				
				sum4 = price4 * num4;
				total += (price4 * num4);
				cout << item4 << " x " << num4 << " = " << "RM " << sum4 << endl; 
				cout << "Your current spent is RM " << total << endl << endl;
				
				break; 
			
			case 5:
				system("cls");
				
				cout << "---------------------------------------------------------------" << endl;
				cout << "NO.  |  PRODUCT \t\t\t |  PRICE (RM)" << endl;
				cout << "---------------------------------------------------------------" << endl;
				cout << "5. \t" << item5 << "\t\t\t    " << price5 << endl << endl;
				cout << "Quantity: ";
				cin >> num5;
				
				while(num5 < 0)
				{
					cout << "Invalid entry." << endl << endl;
					cout << "Quantity: ";
					cin >> num5;	
				}
				
				sum5 = price5 * num5;
				total += (price5 * num5);
				cout << item5 << " x " << num5 << " = " << "RM " << sum5 << endl; 
				cout << "Your current spent is RM " << total << endl << endl;
				
				break; 
				
			case 6:
				system("cls");
				
				cout << "---------------------------------------------------------------" << endl;
				cout << "NO.  |  PRODUCT \t\t\t |  PRICE (RM)" << endl;
				cout << "---------------------------------------------------------------" << endl;
				cout << "6. \t" << item6 << "\t\t    " << price6 << endl << endl;
				cout << "Quantity: ";
				cin >> num6;
				
				while(num6 < 0)
				{
					cout << "Invalid entry." << endl << endl;
					cout << "Quantity: ";
					cin >> num6;	
				}
				
				sum6 = price6 * num6;
				total += (price6 * num6);
				cout << item6 << " x " << num6 << " = " << "RM " << sum6 << endl; 
				cout << "Your current spent is RM " << total << endl << endl;
				
				break; 
				
			case 7:
				system("cls");
				
				cout << "---------------------------------------------------------------" << endl;
				cout << "NO.  |  PRODUCT \t\t\t |  PRICE (RM)" << endl;
				cout << "---------------------------------------------------------------" << endl;
				cout << "7. \t" << item7 << "\t    " << price7 << endl << endl;
				cout << "Quantity: ";
				cin >> num7;
				
				while(num7 < 0)
				{
					cout << "Invalid entry." << endl << endl;
					cout << "Quantity: ";
					cin >> num7;	
				}
				
				sum7 = price7 * num7;
				total += (price7 * num7);
				cout << item7 << " x " << num7 << " = " << "RM " << sum7 << endl; 
				cout << "Your current spent is RM " << total << endl << endl;
				
				break; 
				
			case 8:
				system("cls");
				
				cout << "---------------------------------------------------------------" << endl;
				cout << "NO.  |  PRODUCT \t\t\t |  PRICE (RM)" << endl;
				cout << "---------------------------------------------------------------" << endl;
				cout << "8. \t" << item8 << "\t\t    " << price8 << endl << endl;
				cout << "Quantity: ";
				cin >> num8;
				
				while(num8 < 0)
				{
					cout << "Invalid entry." << endl << endl;
					cout << "Quantity: ";
					cin >> num8;	
				}
				
				sum8 = price8 * num8;
				total += (price8 * num8);
				cout << item8 << " x " << num8 << " = " << "RM " << sum8 << endl; 
				cout << "Your current spent is RM " << total << endl << endl;
				
				break;
			
			case 9: //billing
				system("cls");
			
				cout << "Your shopping list: " << endl << endl;
				if(num1 > 0)
					cout << x++ << ". " << item1 << " x " << num1 << " = RM " << sum1 << endl;
				if(num2 > 0)
					cout << x++ << ". " << item2 << " x " << num2 << " = RM " << sum2 << endl;
				if(num3 > 0)
					cout << x++ << ". " << item3 << " x " << num3 << " = RM " << sum3 << endl;
				if(num4 > 0)
					cout << x++ << ". " << item4 << " x " << num4 << " = RM " << sum4 << endl;
				if(num5 > 0)
					cout << x++ << ". " << item5 << " x " << num5 << " = RM " << sum5 << endl;
				if(num6 > 0)
					cout << x++ << ". " << item6 << " x " << num6 << " = RM " << sum6 << endl;
				if(num7 > 0)
					cout << x++ << ". " << item7 << " x " << num7 << " = RM " << sum7 << endl;
				if(num8 > 0)
					cout << x++ << ". " << item8 << " x " << num8 << " = RM " << sum8 << endl;
				
				cout << "\nTotal amount: RM " << total << endl << endl;				
				cout << "Do you have promotion code / staff code? (Y or N): ";
				cin >> ch;
				
				while(tqt == "1") //loop
				{
					if(ch == 'y' || ch == 'Y')
					{
						cout << "\nPlease key in the promotion code / staff code: ";
						cin >> code;
						
						if(code == "STAFF")
						{
							total *= discount;
							cout << "\n\nDiscount = 5%" << endl << endl;
							cout << "\nYour final total amount is: RM " << total << endl << endl;
							cout << "======================================================" << endl;
							cout << "\t\tThank you for using!" << endl;
							cout << "======================================================" << endl;
							exit(0);
								
						}
						else
						{
							cout << "This code does not exist!" << endl << endl;
							cout << "Do you have promotion code / staff code? (Y or N): ";
							cin >> ch;
						}
					}
					else if(ch == 'n' || ch == 'N')
					{
						if(total > 300) 
						{
							total *= discount;
							cout << "\n\nDiscount = 5%" << endl << endl;
							cout << "Your final total amount is: RM " << total << endl << endl;	
							cout << "======================================================" << endl;
							cout << "\t\tThank you for using!" << endl;
							cout << "======================================================" << endl;
							exit(0);					
						}
						else
						{
							cout << "\n\nDiscount = 0%" << endl << endl;
							cout << "Your final total amount is: RM " << total << endl << endl;
							cout << "======================================================" << endl;
							cout << "\t\tThank you for using!" << endl;
							cout << "======================================================" << endl;
							exit(0);
						}
					}
					else
					{
						cout << "Invalid entry.	" << endl << endl;
						cout << "Do you have promotion code / staff code? (Y or N): ";
						cin >> ch;
					}										
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

	return 0;
}
