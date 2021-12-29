#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <sstream>   
#include <cctype>

using namespace std;

void header();
void readData(string, string[], string[], char[], string[], double[], string[], double[], string[], double[], int);
void calculateBMI(double[], double[], double[]);
void calculateBMR(char[], double[], double[], double[], double[]);
void calculateRMR(char[], double[], double[], double[], double[]);
void searchSpecific(string[], char[], double[], string[], double[], double[], double[], int, int, const int);
void searchCombine(string[], string[], char[], double[], double[], int, const int);
void statDistribution(double[], double[], char[]);
void caloriesConsume(string[], string[], char[], string[], string[], string[], double[], double[], double[], int, int, const int);	
void addInfo(string, string[], string[], char[], string[], string[], string[], int);	
void modifyInfo(string, string[], string[], char[], string[], string[], string[], int, int, const int);
void outFile(string[], string[], char[], string[], string[], string[], int count, const int size);
void close();

	
int main()
{
	int choice; 
	int i = 0, count = 0;
	const int size = 50;
	string filename;
	string name[size], staffID[size], age[size], weight[size], height[size];
	char gender[size];
	double BMI[size];
	double BMR[size];
	double RMR[size];
	double ageDouble[size];
	double weightDouble[size];   //Use to store weight in string double
	double heightDouble[size];   //Use to store height in string double
	string menu = "1";
	
	
	system("cls");

	header();
	
	cout << "\n\nEnter the file name (make sure to type '.txt'): ";
	getline(cin, filename);

	cout << "\n\nReading data from input file . . . " << endl << endl;

	system("pause");
	
	
	while(menu == "1")
	{
	system("cls");
	
	header();
	
	readData(filename, name, staffID, gender, age, ageDouble, weight, weightDouble, height, heightDouble, i); //Data will be updated every time return back to menu
	
	calculateBMI(BMI, weightDouble, heightDouble);
	calculateBMR(gender, BMR, weightDouble, heightDouble, ageDouble);
	calculateRMR(gender, RMR, weightDouble, heightDouble, ageDouble);	

	
	cout << "Hi, how may I help you?" << endl << endl;
	cout << "1. Search information based on specific criteria. " << endl;
	cout << "2. Search information based on combinational information. " << endl;
	cout << "3. Display statistical distribution. " << endl;
	cout << "4. Calculation for calories consumption in order to achieve certain target. " << endl;
	cout << "5. Add a new staff information. " << endl;
	cout << "6. Modify staff information. " << endl;
	cout << "7. Produce an output file. " << endl;
	cout << "8. Exit. " << endl << endl;
	cout << "Please select a number of your choice: ";
	cin >> choice;
		
	
	
	if (choice == 1)
	{
		system("cls");

		searchSpecific(staffID, gender, ageDouble, name, BMI, BMR, RMR, i, count, size);		
		
		system("pause");
	}

	else if (choice == 2)
	{	
		system("cls"); 

		searchCombine(name, staffID, gender, ageDouble, BMI, count, size);
		
		system("pause");
	}
	
	else if (choice == 3)
	{
		system("cls");
		
		statDistribution(BMI, ageDouble, gender);
	
		system("pause");
	}
	
	else if (choice == 4)
	{
		system("cls");
		
		caloriesConsume(name, staffID, gender, age, weight, height, BMI, BMR, RMR, i, count, size);
		
		system("pause");
	}
	
	else if (choice == 5)
	{
		system("cls");

		addInfo(filename, name, staffID, gender, age, weight, height, i);
	
		system("pause");
	}
	
	else if (choice == 6)
	{
		system("cls");

		modifyInfo(filename, name, staffID, gender, age, weight, height, i, count, size);

		system("pause");
	}
	
	else if (choice == 7)
	{
		system("cls");
		
		outFile(name, staffID, gender, age, weight, height, count, size);

		system("pause");
	}

	else if (choice == 8)
	{
		system("cls");
		
		close();
		
		exit(0);
		
	}
	
	else
	{
		cout << "\nERROR! Please try again. " << endl << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		
		system("pause");
	}
	}

	return 0;
}

void header()
{
	time_t now = time(0);
	char* dt = ctime(&now);
	cout << "\t\t\t" << "   " << dt << endl;

	cout << "\t==============================================================" << endl << endl; //For greetings
	cout << "\t\t\tWELCOME TO LET'S GET FIT (LGF)" << endl << endl;
	cout << "\t==============================================================" << endl << endl;
}

void readData(string filename, string name[], string staffID[], char gender[], string age[], double ageDouble[], string weight[], double weightDouble[], string height[], double heightDouble[], int i)
{	
	char tab;
	fstream inFile;
	inFile.open(filename.c_str(), ios::in);
	if(!inFile) //In case the input file is not existing
	{
		cout << "Cannot open input file. Please exit and try again. " << endl << endl;
		exit(0);
	}
	else
	{
		while (!inFile.eof())
		{
			getline(inFile, name[i], '\t');
			getline(inFile, staffID[i], '\t');
			inFile.get(gender[i]);
			inFile.get(tab);
			getline(inFile, age[i], '\t');
			istringstream ag(age[i]);
			ag >> ageDouble[i];
			getline(inFile, weight[i], '\t');
			istringstream weig(weight[i]);      // Use istringstream to convert from string to double
			weig >> weightDouble[i];			
			getline(inFile, height[i], '\n');
			istringstream heig(height[i]);     // Use istringstream to convert from string to double
			heig >> heightDouble[i];
			i++;
		}
		
			cout << "Data has been read successfully. " << endl << endl;
	}
	
	inFile.close();
}

void calculateBMI(double BMI[], double weightDouble[], double heightDouble[])
{
	for(int i = 0; i < 50; i++)
	{
		BMI[i] = (weightDouble[i]) / (heightDouble[i]/100 * heightDouble[i]/100);   // remember to convert height from cm to meter
	}
}

void calculateBMR(char gender[], double BMR[], double weightDouble[], double heightDouble[], double ageDouble[])
{
	for(int i = 0; i < 50; i++)
	{
		if(toupper(gender[i]) == 'M')
		{
			BMR[i] = 10 * weightDouble[i] + 6.25 * heightDouble[i] - 5 * ageDouble[i] + 5;
		}
		else if(toupper(gender[i]) == 'F')
		{
			BMR[i] = 10 * weightDouble[i] + 6.25 * heightDouble[i] - 5 * ageDouble[i] - 161;
		}
	}

}

void calculateRMR(char gender[], double RMR[], double weightDouble[], double heightDouble[], double ageDouble[])
{
	for(int i = 0; i < 50; i++)
	{
		if(toupper(gender[i]) == 'M')
		{
			RMR[i] = 447.593 + (9.247 * weightDouble[i]) + (3.098 * heightDouble[i]) - (4.330 * ageDouble[i]);
		}
		else if(toupper(gender[i]) == 'F')
		{
			RMR[i] = 88.362 + (13.397 * weightDouble[i]) + (4.799 * heightDouble[i]) - (5.677 * ageDouble[i]);	
		} 
	}
}

void searchSpecific(string staffID[], char gender[], double ageDouble[], string name[], double BMI[], double BMR[], double RMR[], int i, int count, const int size)		
{	
	string loop = "1";	
	int select, select1, select2;
	string searchID;
	
	cout << " *Insert '0' to back to menu* " << endl << endl; //in case user want to return back to menu
	
	while(loop == "1")
	{ 
		cout << "Which selection you want to choose? " << endl;
		cout << "1. Staff ID. " << endl;
		cout << "2. Gender. " << endl;
		cout << "3. Age. " << endl;
		cout << "Your selection is: ";
		cin >> select;
		cout << endl;
		
		if(select == 1)
		{
			cout << "Please key in ID number." << endl;
			cout << "ID: ";
			cin >> searchID;
			cout << endl;
				
			for(i = 0; i < size; i++)
			{
				if(searchID == staffID[i])
				{
					count = i;
					break;
				}
			}
			if(count == i)
			{
				cout << "Staff Information" << endl;
				cout << "Name: " << name[count] << "\t";
				cout << "Staff ID: " << staffID[count] << endl;
				cout << "BMI: " << BMI[count] << "\t";
				cout << "BMR: " << BMR[count] << "\t";
				cout << "RMR: " << RMR[count] << endl << endl;
				loop = "2";
			}
			else
			{
				cout << "\nThe staff ID is not in record. Please try again. " << endl << endl;
			}
		}
		
		else if(select == 2)
		{
			cout << "Which gender you want to choose?" << endl;
			cout << "1. Male" << endl;
			cout << "2. Female" << endl;
			cout << "Your selection is: ";
			cin >> select1;
			cout << endl;
			
			if(select1 == 1)
			{
				cout << "Staff Information" << endl;
				for(count = 0; count < size; count++)
				{
					if(toupper(gender[count]) == 'M')
					{
						cout << "Name: " << name[count] << "\t";
						cout << "Staff ID: " << staffID[count] << endl;
						cout << "BMI: " << BMI[count] << "\t";
						cout << "BMR: " << BMR[count] << "\t";
						cout << "RMR: " << RMR[count] << endl << endl;
						loop = "2";
					}
				}
			}
			else if(select1 == 2)
			{
				cout << "Staff Information" << endl;
				for(count = 0; count < size; count++)
				{
					if(toupper(gender[count]) == 'F')
					{
						cout << "Name: " << name[count] << "\t";
						cout << "Staff ID: " << staffID[count] << endl;
						cout << "BMI: " << BMI[count] << "\t";
						cout << "BMR: " << BMR[count] << "\t";
						cout << "RMR: " << RMR[count] << endl << endl;
						loop = "2";
					}
				}	
			}
			else
			{
				cout << "\nERROR! Please try again. " << endl << endl; //error message
				cin.clear();
				cin.ignore(1000, '\n');
			}
		}
		
		else if(select == 3)
		{
			cout << "What range of age you want to choose?" << endl;
			cout << "1. Below 40" << endl;
			cout << "2. Above 40" << endl;
			cout << "Your selection is: ";
			cin >> select2;
			cout << endl;
			
			if(select2 == 1)
			{
				cout << "Staff Information" << endl;
				for(count = 0; count < 10; count++)
				{
					if(ageDouble[count] < 40)
					{
						cout << "Name: " << name[count] << "\t";
						cout << "Staff ID: " << staffID[count] << "\t";
						cout << "Age: " << ageDouble[count] << endl;
						cout << "BMI: " << BMI[count] << "\t";
						cout << "BMR: " << BMR[count] << "\t";
						cout << "RMR: " << RMR[count] << endl << endl;
						loop = "2";
					}
				}
			}
			else if(select2 == 2)
			{
				cout << "Staff Information" << endl;
				for(count = 0; count < size; count++)
				{
					if(ageDouble[count] >= 40)
					{
						cout << "Name: " << name[count] << "\t";
						cout << "Staff ID: " << staffID[count] << "\t";
						cout << "Age: " << ageDouble[count] << endl;
						cout << "BMI: " << BMI[count] << "\t";
						cout << "BMR: " << BMR[count] << "\t";
						cout << "RMR: " << RMR[count] << endl << endl;
						loop = "2";
					}
				}	
			}
			else
			{
				cout << "\nERROR! Please try again. " << endl << endl; //error message
				cin.clear();
				cin.ignore(1000, '\n');
			}
		}
		else if(select == 0)
		{
			loop = "2";
		}
		else
		{
			cout << "\nERROR! Please try again. " << endl << endl; //error message
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
}

void searchCombine(string name[], string staffID[], char gender[], double ageDouble[], double BMI[], int count, const int size)		
{
	string loop = "1";
	int value, value2; 
	char gender1, gender2;
	int choice1, choice2, choice3, choice4;
	
	cout << " *Insert '0' to back to menu* " << endl << endl; //in case user want to return back to menu
	
	while(loop == "1")
	{
		cout << "1: BMI" << endl;  
		cout << "2: Gender" << endl; 
		cout << "3: Age" << endl;
		cout << "Please enter your first choice: ";
		cin >> choice1;
		cout << endl;
		if(choice1 == 1 || choice1 == 3)
		{
			cout << "Please insert value (less than or more than): ";
			cin >> value;
			cout << "1 : for value equal or less than" << endl; 
			cout << "2 : for value equal or more than" << endl; 
			cout << "Please enter your choice: ";
			cin >> choice3;
		}
		else if(choice1 == 2)
		{
			cout << "Please insert a letter (M or F): ";
			cin >> gender1;
			cout << endl;
		}
		else if(choice1 == 0)
		{
			break;
			loop = "2";
		}
		else
		{
			cout << "\nERROR! Please try again . " << endl << endl; //error message
			cin.clear();
			cin.ignore(1000, '\n');
			loop = "1";
		}	
		
		cout << endl << endl;
		cout << "  1: BMI" << endl; 
		cout << "  2: Gender" << endl; 
		cout << "  3: Age" << endl;
		cout << "  Please enter your second choice: ";
		cin >> choice2;
		cout << endl;
		if(choice2 == 1 || choice2 == 3)
		{
			cout << "  Please insert value (less than or more than): ";
			cin >> value2;
			cout << "  1 : for value equal or less than" << endl; 
			cout << "  2 : for value equal or more than" << endl; 
			cout << "  Please enter your choice: ";
			cin >> choice4;
			cout << endl;
		}
		else if(choice2 == 2)
		{
			cout << "  Please insert a letter (M or F): ";
			cin >> gender2;
			cout << endl;
		}
		else if(choice1 == 0)
		{
			break;
			loop = "2";
		}
		else
		{
			cout << "\nERROR! Please try again . . " << endl << endl; //error message
			cin.clear();
			cin.ignore(1000, '\n');
			loop = "1";
		}	
		
				
		for(count = 0; count < size; count++)
		{	
			if(choice1 == 1 && choice2 == 3) // BMI and Age
			{ 
				if(choice3 == 1 && BMI[count] <= value && choice4 == 1 && ageDouble[count] <= value2){ 
					cout << name[count] << "\t" << staffID[count] <<endl;
					loop = "2";
				}
				if(choice3 == 1 && BMI[count] <= value && choice4 == 2 && ageDouble[count] >= value2){
					cout << name[count] << "\t" << staffID[count] <<endl;
					loop = "2";
				}
				if(choice3 == 2 && BMI[count] >= value && choice4 == 1 && ageDouble[count] <= value2){
					cout << name[count] << "\t" << staffID[count] <<endl;
					loop = "2";
				}
				if(choice3 == 2 && BMI[count] >= value && choice4 == 2 && ageDouble[count] >= value2){
					cout << name[count] << "\t" << staffID[count] <<endl;
					loop = "2";
				}
			}
			
			else if(choice1 == 3 && choice2 == 1) // Age and BMI
			{
				if(choice3 == 1 && ageDouble[count] <= value && choice4 == 1 && BMI[count] <= value2){
					cout << name[count] << "\t" << staffID[count] <<endl;
					loop = "2";
				}
				if(choice3 == 1 && ageDouble[count] <= value && choice4 == 2 && BMI[count] >= value2){
					cout << name[count] << "\t" << staffID[count] <<endl;
					loop = "2";
				}
				if(choice3 == 2 && ageDouble[count] >= value && choice4 == 1 && BMI[count] <= value2){
					cout << name[count] << "\t" << staffID[count] <<endl;
					loop = "2";
				}
				if(choice3 == 2 && ageDouble[count] >= value && choice4 == 2 && BMI[count] >= value2){
					cout << name[count] << "\t" << staffID[count] <<endl;
					loop = "2";
				}
			}
			
			else if(choice1 == 1 && choice2 == 2) // BMI and Gender
			{ 
				if(choice3 == 1 && BMI[count] <= value && toupper(gender2) == 'M' && gender[count] == 'M'){ 
					cout << name[count] << "\t" << staffID[count] <<endl;
					loop = "2";
				}
				if(choice3 == 1 && BMI[count] <= value && toupper(gender2) == 'F' && gender[count] == 'F'){
					cout << name[count] << "\t" << staffID[count] <<endl;
					loop = "2";
				}
				if(choice3 == 2 && BMI[count] >= value && toupper(gender2) == 'M' && gender[count] == 'M'){
					cout << name[count] << "\t" << staffID[count] <<endl;
					loop = "2";
				}
				if(choice3 == 2 && BMI[count] >= value && toupper(gender2) == 'F' && gender[count] == 'F'){
					cout << name[count] << "\t" << staffID[count] <<endl;
					loop = "2";
				}
			}
			
			else if(choice1 == 2 && choice2 == 1) // Gender and BMI
			{ 
				if(choice4 == 1 && BMI[count] <= value2 && toupper(gender1) == 'M' && gender[count] == 'M'){ 
					cout << name[count] << "\t" << staffID[count] <<endl;
					loop = "2";
				}
				if(choice4 == 1 && BMI[count] <= value2 && toupper(gender1) == 'F' && gender[count] == 'F'){
					cout << name[count] << "\t" << staffID[count] <<endl;
					loop = "2";
				}
				if(choice4 == 2 && BMI[count] >= value2 && toupper(gender1) == 'M' && gender[count] == 'M'){
					cout << name[count] << "\t" << staffID[count] <<endl;
					loop = "2";
				}
				if(choice4 == 2 && BMI[count] >= value2 && toupper(gender1) == 'F' && gender[count] == 'F'){
					cout << name[count] << "\t" << staffID[count] <<endl;
					loop = "2";
				}
			}
			
			else if(choice1 == 3 && choice2 == 2) // Age and Gender
			{ 
				if(choice3 == 1 && ageDouble[count] <= value && toupper(gender2) == 'M' && gender[count] == 'M'){ 
					cout << name[count] << "\t" << staffID[count] <<endl;
					loop = "2";
				}
				if(choice3 == 1 && ageDouble[count] <= value && toupper(gender2) == 'F' && gender[count] == 'F'){
					cout << name[count] << "\t" << staffID[count] <<endl;
					loop = "2";
				}
				if(choice3 == 2 && ageDouble[count] >= value && toupper(gender2) == 'M' && gender[count] == 'M'){
					cout << name[count] << "\t" << staffID[count] <<endl;
					loop = "2";
				}
				if(choice3 == 2 && ageDouble[count] >= value && toupper(gender2) == 'F' && gender[count] == 'F'){
					cout << name[count] << "\t" << staffID[count] <<endl;
					loop = "2";
				}
			}
			
			else if(choice1 == 2 && choice2 == 3) // Gender and Age
			{ 
				if(choice4 == 1 && ageDouble[count] <= value2 && toupper(gender1) == 'M' && gender[count] == 'M'){ 
					cout << name[count] << "\t" << staffID[count] <<endl;
					loop = "2";
				}
				if(choice4 == 1 && ageDouble[count] <= value2 && toupper(gender1) == 'F' && gender[count] == 'F'){
					cout << name[count] << "\t" << staffID[count] <<endl;
					loop = "2";
				}
				if(choice4 == 2 && ageDouble[count] >= value2 && toupper(gender1) == 'M' && gender[count] == 'M'){
					cout << name[count] << "\t" << staffID[count] <<endl;
					loop = "2";
				}
				if(choice4 == 2 && ageDouble[count] >= value2 && toupper(gender1) == 'F' && gender[count] == 'F'){
					cout << name[count] << "\t" << staffID[count] <<endl;
					loop = "2";
				}
			}
			
			else
			{
				cout << "\nERROR! Please try again . . . " << endl << endl; //error message
				cin.clear();
				cin.ignore(1000, '\n');
				break;
			}	
		}
	}
	cout << endl;
}

void statDistribution(double BMI[], double ageDouble[], char gender[])
{	
	int count = 0;
	const int size = 50;
	double sum1, sum2, sum3, sum4, sum5, sum6, sum7, sum8;
	double sum9, sum10, sum11, sum12, sum13, sum14, sum15, sum16;
	
	for(count = 0; count < size; count++) 
	{
		if(BMI[count] < 20 && ageDouble[count] < 40 && gender[count] == 'M'){ //Underweight
			sum1++;
		}
		else if(BMI[count] < 20 && ageDouble[count] < 40 && gender[count] == 'F'){
			sum2++;
		}
		else if(BMI[count] < 20 && ageDouble[count] >= 40 && gender[count] == 'M'){
			sum3++;
		}
		else if(BMI[count] < 20 && ageDouble[count] >= 40 && gender[count] == 'F'){
			sum4++;
		}
			
			else if(BMI[count] >= 20 && BMI[count] < 25 && ageDouble[count] < 40 && gender[count] == 'M'){ //Normal weight
			sum5++;
		}
		else if(BMI[count] >= 20 && BMI[count] < 25 && ageDouble[count] < 40 && gender[count] == 'F'){
			sum6++;
		}
		else if(BMI[count] >= 20 && BMI[count] < 25 && ageDouble[count] >= 40 && gender[count] == 'M'){
			sum7++;
		}
		else if(BMI[count] >= 20 && BMI[count] < 25 && ageDouble[count] >= 40 && gender[count] == 'F'){
			sum8++;
		}
		
		else if(BMI[count] >= 25 && BMI[count] < 30 && ageDouble[count] < 40 && gender[count] == 'M'){ //Overweight
			sum9++;
		}
		else if(BMI[count] >= 25 && BMI[count] < 30 && ageDouble[count] < 40 && gender[count] == 'F'){
			sum10++;
		}
		else if(BMI[count] >= 25 && BMI[count] < 30 && ageDouble[count] >= 40 && gender[count] == 'M'){
			sum11++;
		}
		else if(BMI[count] >= 25 && BMI[count] < 30 && ageDouble[count] >= 40 && gender[count] == 'F'){
			sum12++;
		}
		
		else if(BMI[count] >= 30 && ageDouble[count] < 40 && gender[count] == 'M'){ //Obese
			sum13++;
		}
		else if(BMI[count] >= 30 && ageDouble[count] < 40 && gender[count] == 'F'){
			sum14++;
		}
		else if(BMI[count] >= 30 && ageDouble[count] >= 40 && gender[count] == 'M'){
			sum15++;
		}
		else if(BMI[count] >= 30 && ageDouble[count] >= 40 && gender[count] == 'F'){
			sum16++;
		}
	}
	
	if(sum1 >= 1){ // avoid getting some unknown number whenever there is no value inside the array
		sum1 = sum1;
	}
	else{
		sum1 = 0; 
	}
	if(sum2 >= 1){
		sum2 = sum2;
	}
	else{
		sum2 = 0;
	}
	if(sum3 >= 1){
		sum3 = sum3;
	}
	else{
		sum3 = 0;
	}
	if(sum4 >= 1){
		sum4 = sum4;
	}
	else{
		sum4 = 0;
	}
	if(sum5 >= 1){
		sum5 = sum5;
	}
	else{
		sum5 = 0;
	}
	if(sum6 >= 1){
		sum6 = sum6;
	}
	else{
		sum6 = 0;
	}
	if(sum7 >= 1){
		sum7 = sum7;
	}
	else{
		sum7 = 0;
	}
	if(sum8 >= 1){
		sum8 = sum8;
	}
	else{
		sum8 = 0;
	}
	if(sum9 >= 1){
		sum9 = sum9;
	}
	else{
		sum9 = 0;
	}
	if(sum10 >= 1){
		sum10 = sum10;
	}
	else{
		sum10 = 0;
	}
	if(sum11 >= 1){
		sum11 = sum11;
	}
	else{
		sum11 = 0;
	}
	if(sum12 >= 1){
		sum12 = sum12;
	}
	else{
		sum12 = 0;
	}
	if(sum13 >= 1){
		sum13 = sum13;
	}
	else{
		sum13 = 0;
	}
	if(sum14 >= 1){
		sum14 = sum14;
	}
	else{
		sum14 = 0;
	}
	if(sum15 >= 1){
		sum15 = sum15;
	}
	else{
		sum15 = 0;
	}
	if(sum16 >= 1){
		sum16 = sum16;
	}
	else{
		sum16 = 0;
	}
	
	cout << endl << endl; 
	
	cout << "\t" << "**********************************************" << endl; //table for minimal distribution information
	cout << "\t*\t " << "BMI" << "\t   " << "*" << "\t" << "Weight Category" << "\t     " << "*" <<endl;
	cout << "\t" << "**********************************************" << endl;
	cout << "\t*   " << "Less than 20" << "   " << "*" << "\t  " << "Underweight" << "\t     " << "*" << endl;
	cout << "\t" << "**********************************************" << endl;
	cout << "\t*   " << "20 - 25" << "\t   " << "*" << "\t  " << "Normal weight" << "\t     " << "*" << endl;
	cout << "\t" << "**********************************************" << endl;
	cout << "\t*   " << "25 - 30" << "\t   " << "*" << "\t  " << "Overweight" << "\t     " << "*" << endl;
	cout << "\t" << "**********************************************" << endl;
	cout << "\t*   " << "More than 30" << "   " << "*" << "\t  " << "Obese" << "\t\t     " << "*" << endl;
	cout << "\t" << "**********************************************" << endl;

	
			
	cout << endl << endl;

	cout << "\t" << "------UNDERWEIGHT------" << endl << endl; // table for statistical distribution
	cout << "\t" << "__________________________________________________________________________________" << endl;
	cout << "\t\t    " << "Age below 40" << "\t\t" << "||" << "\t\t" << "Age above 40" << endl;
	cout << "\t" << "__________________________________________________________________________________" << endl;
	cout << "\t\t" << "Male" << "  \t  " << "|" << "\t  " << "Female" << "\t" << "||" << "\t  " << "Male" << "\t    " << "|" << "\t    " << "Female" << endl;
	cout << "\t" << "__________________________________________________________________________________" << endl;
	cout << "\t\t  " << sum1 << "  \t  " << "|" << "\t     " << sum2 << "\t\t" << "||" << "\t    " << sum3 << "\t    " << "|" << "\t       " << sum4 << endl;
	cout << "\t" << "__________________________________________________________________________________" << endl;
	
	cout << endl << endl;
	
	cout << "\t" << "------NORMAL WEIGHT------" << endl << endl;
	cout << "\t" << "__________________________________________________________________________________" << endl;
	cout << "\t\t    " << "Age below 40" << "\t\t" << "||" << "\t\t" << "Age above 40" << endl;
	cout << "\t" << "__________________________________________________________________________________" << endl;
	cout << "\t\t" << "Male" << "  \t  " << "|" << "\t  " << "Female" << "\t" << "||" << "\t  " << "Male" << "\t    " << "|" << "\t    " << "Female" << endl;
	cout << "\t" << "__________________________________________________________________________________" << endl;
	cout << "\t\t  " << sum5 << "  \t  " << "|" << "\t     " << sum6 << "\t\t" << "||" << "\t    " << sum7 << "\t    " << "|" << "\t       " << sum8 << endl;
	cout << "\t" << "__________________________________________________________________________________" << endl;
	
	cout << endl << endl;
	
	cout << "\t" << "------OVERWEIGHT------" << endl << endl;
	cout << "\t" << "__________________________________________________________________________________" << endl;
	cout << "\t\t    " << "Age below 40" << "\t\t" << "||" << "\t\t" << "Age above 40" << endl;
	cout << "\t" << "__________________________________________________________________________________" << endl;
	cout << "\t\t" << "Male" << "  \t  " << "|" << "\t  " << "Female" << "\t" << "||" << "\t  " << "Male" << "\t    " << "|" << "\t    " << "Female" << endl;
	cout << "\t" << "__________________________________________________________________________________" << endl;
	cout << "\t\t  " << sum9 << "  \t  " << "|" << "\t     " << sum10 << "\t\t" << "||" << "\t    " << sum11 << "\t    " << "|" << "\t       " << sum12 << endl;
	cout << "\t" << "__________________________________________________________________________________" << endl;
	
	cout << endl << endl;
	
	cout << "\t" << "------OBESE------" << endl << endl;
	cout << "\t" << "__________________________________________________________________________________" << endl;
	cout << "\t\t    " << "Age below 40" << "\t\t" << "||" << "\t\t" << "Age above 40" << endl;
	cout << "\t" << "__________________________________________________________________________________" << endl;
	cout << "\t\t" << "Male" << "  \t  " << "|" << "\t  " << "Female" << "\t" << "||" << "\t  " << "Male" << "\t    " << "|" << "\t    " << "Female" << endl;
	cout << "\t" << "__________________________________________________________________________________" << endl;
	cout << "\t\t  " << sum13 << "  \t  " << "|" << "\t     " << sum14 << "\t\t" << "||" << "\t    " << sum15 << "\t    " << "|" << "\t       " << sum16 << endl;
	cout << "\t" << "__________________________________________________________________________________" << endl;
	
	cout << endl << endl;
		
}

void caloriesConsume(string name[], string staffID[], char gender[], string age[], string weight[], string height[], double BMI[], double BMR[], double RMR[], int i, int count, const int size)	
{	
	string loop = "1";
	string ID;
	char ch;
	double lossWeight;
	
	while(loop == "1")
	{		
		cout << "Who do you want to search for?" << endl;
		cout << "Please enter the staffID: ";
		cin >> ID;
		cout << endl;
		
		for(i = 0; i < size; i++)
		{
			if(ID == staffID[i])
			{
				count = i;
				break;	
			}
		}
		
		lossWeight = BMR[i] * 1.2 - 500; 
		
		if(count == i)
		{
			cout << "Name: " << name[count] << "\t" << endl;
			cout << "Staff ID: " << staffID[count] << "\t" << endl;
			cout << "Gender: " << gender[count] << "\t" << endl;
			cout << "Age: " << age[count] << "\t" << endl;
			cout << "Weight: " << weight[count] << "\t" << endl;
			cout << "Height: " << height[count] << endl;
			cout << "BMI: " << BMI[count] << endl;
			cout << "BMR: " << BMR[count] << endl;
			cout << "RMR: " << RMR[count] << endl << endl;
			cout << "In order to loss weight of 2kg in 1 month, " << endl;
			cout << "Recommended calories consumption = " << lossWeight << " calories" << endl << endl;
			
			if(lossWeight < 1200) //small reminder
			{
				cout << "=====================================================================================================================" << endl;
				cout << "The recommended calories consumption is less than minimum requirement of daily calories consumption (1200 calories). " << endl;
				cout << "Therefore, it is highly recommend not to decrease calories consumption. " << endl;
				cout << "=====================================================================================================================" << endl;
			}
			
			loop = "2";
		}
		else
		{
			cout << "\nThe staff ID is not in record. " << endl << endl; //error message and 
			cout << " *Insert '0' to back to menu* " << endl << endl;	 //in case user want to return back to menu
			cout << "Please try again. (Insert any character)  ";
			cin >> ch;
			if(ch == '0')
			{
				loop = "2";
			}
			else
			{
				loop = "1";
				cout << endl;
			}
		}	
	}
	cout << endl;	
}

	void addInfo(string filename, string name[], string staffID[], char gender[], string age[], string weight[], string height[], int i)		
{
	string loop ="1";
	char ch;
	
	cout << " *Insert '0' to back to menu* " << endl << endl; //in case user want to return back to menu
	cout << "Do you want to proceed? (Insert any character)  ";
	cin >> ch;
	
	while(loop == "1")
	{
		if(ch == '0')
		{
			loop = "2";
		}
		else
		{
			fstream inFile;
			inFile.open(filename.c_str(), ios::in | ios::out | ios::app); //contents will not deleted when new information is added
		
			cout << "Please enter the name: ";
			cin.get();
			getline(cin, name[i]);
			cout << "\nPlease enter the staff ID: ";
			cin >> staffID[i];
			cout << "\nPlease enter the gender (M or F): ";
			cin >> gender[i];
			gender[i] = toupper(gender[i]);
			cout << "\nPlease enter the age: ";
			cin >> age[i];
			cout << "\nPlease enter the weight: ";
			cin >> weight[i];
			cout << "\nPlease enter the height: ";
			cin >> height[i];
			
			inFile << name[i] << "\t" << staffID[i] << "\t" << gender[i] << "\t" << age[i] << "\t" << weight[i] << "\t" << height[i] << endl;
			cout << "\nNew staff information has been added successfully. " << endl << endl;
		
			inFile.close();
			loop = "2";
		}
	}
}

void modifyInfo(string filename, string name[], string staffID[], char gender[], string age[], string weight[], string height[], int i, int count, const int size)
{
	string loop ="1";
	char ch;
	string ID;
	int info;

	cout << " *Insert '0' to back to menu* " << endl << endl; //in case user want to return back to menu
	cout << "Do you want to proceed? (Insert any character)  ";
	cin >> ch;
	
	while(loop == "1")
	{
		if(ch == '0')
		{
			loop = "2";
		}
		else
		{
			cout << "Who do you want to modify?" << endl;
			cout << "Please enter the staffID: ";
			cin >> ID;
			cout << endl;
			
			for(i = 0; i < size; i++)
			{
				if(ID == staffID[i])
				{
					count = i;
					break;
				}
			}
			
			if(count == i)
			{
				cout << "Name: " << name[count] << "\t" << endl;
				cout << "Staff ID: " << staffID[count] << "\t" << endl;
				cout << "Gender: " << gender[count] << "\t" << endl;
				cout << "Age: " << age[count] << "\t" << endl;
				cout << "Weight: " << weight[count] << "\t" << endl;
				cout << "Height: " << height[count] << endl << endl;
				
				cout << "Which information do you want to modify? " << endl;
				cout << "1. Name " << endl;
				cout << "2. Staff ID " << endl;
				cout << "3. Gender " << endl;
				cout << "4. Age " << endl;
				cout << "5. Weight " << endl;
				cout << "6. Height " << endl;
				cout << "Your selection is: ";
				cin >> info;
				
				
				if(info == 1)
				{
					cout << "Please enter a new name: ";
					for(count = 0; count < size; count++)
					{
						if(ID == staffID[count])
						{
							cin.get();
							getline(cin, name[count]);
							cout << "\nThe information has been updated." << endl;
						}
					}
				}
				else if(info == 2)
				{
					cout << "Please enter a new ID number: ";
					for(count = 0; count < size; count++)
					{
						if(ID == staffID[count])
						{
							cin.get();
							getline(cin, staffID[count]);
							cout << "\nThe information has been updated." << endl;
						}
					}
				}
				else if(info == 3)
				{
					cout << "Please enter a new gender: ";
					for(count = 0; count < size; count++)
					{
						if(ID == staffID[count])
						{
							cin >> gender[count];
							gender[count] = toupper(gender[count]);
							cout << "\nThe information has been updated." << endl;
						}
					}
				}
				else if(info == 4)
				{
					cout << "Please enter a new age: ";
					for(count = 0; count < size; count++)
					{
						if(ID == staffID[count])
						{
							cin >> age[count];
							cout << "\nThe information has been updated." << endl;
						}
					}
				}
				else if(info == 5)
				{
					cout << "Please enter a new weight: ";
					for(count = 0; count < size; count++)
					{
						if(ID == staffID[count])
						{
							cin >> weight[count];
							cout << "\nThe information has been updated." << endl;
						}
					}
				}
				else if(info == 6)
				{
					cout << "Please enter a new height: ";
					for(count = 0; count < size; count++)
					{
						if(ID == staffID[count])
						{
							cin >> height[count];
							cout << "\nThe information has been updated." << endl;
						}
					}
				}
				else
				{
					cout << "\nERROR! Please try again. " << endl << endl;
					cin.clear();
					cin.ignore(1000, '\n');
				}
				
				fstream inFile;
				inFile.open(filename.c_str(), ios::out); //rewrite the contents of file
				
				
				for(count = 0; count < 12; count++)
				{
					inFile << name[count] << "\t" << staffID[count] << "\t" << gender[count] << "\t" << age[count] << "\t" << weight[count] << "\t" << height[count] << endl;
				}
				
				inFile.close();
				
				cout << "\nNew staff information has been updated successfully. " << endl << endl << endl;
				loop = "2";
				
			}
			else
			{
				cout << "\nThe staff ID is not in record. Please try again. " << endl;
				loop = "1"; 
			}
		}
	}
}

void outFile(string name[], string staffID[], char gender[], string age[], string weight[], string height[], int count, const int size)
{
	string loop ="1";
	char ch;
	string outputfile;
	fstream outFile; 
	
	cout << " *Insert '0' to back to menu* " << endl << endl; //in case user want to return back to menu
	cout << "Do you want to proceed? (Insert any character)  ";
	cin >> ch;
	
	while(loop == "1")
	{	
		if(ch == '0')
		{
			loop = "2";
		}
		else
		{
			cout << "Name a new output file (make sure to type '.txt'): ";
			cin.get();
			getline(cin, outputfile);
			outFile.open(outputfile.c_str(), ios::out);
			cout << endl;
			
			cout << "Producing a new file . . ." << endl << endl << endl;
			
			for(count = 0; count < size; count++)
			{
				outFile << name[count] << "\t" << staffID[count] << "\t" << gender[count] << "\t" << age[count] << "\t" << weight[count] << "\t" << height[count] << endl;
			}
			
			system("pause");
			
			cout << "\n\nA new file named '" << outputfile << "' has been created successfully." << endl << endl;
			
			outFile.close();
			loop = "2";
		}
	}
}
	
void close() 
{
	cout << endl << endl;
	cout << "\t      RRORERRO  RRORERRO  RRORERRO  RRORER      ORERRORE  ORERRORE  ORERRO   " << endl; // for goodbye message
	cout << "\t     ER        ER    RR  ER    RR  ER    RR        RR    RO    OR  RO    OR  " << endl;
	cout << "\t    RE        RE    ER  RE    ER  RE    ER        ER    RR    RO  RR    RO    " << endl;
	cout << "\t   OR  RORE  OR    RE  OR    RE  OR    RE        RE    ER    RR  ERRORE      " << endl;
	cout << "\t  RO    OR  RO    OR  RO    OR  RO    OR        OR    RE    ER  RE    ER     " << endl;
	cout << "\t RR    RO  RR    RO  RR    RO  RR    RO    OR  RO    OR    RE  OR    RE      " << endl;
	cout << "\tERRORERR  ERRORERR  ERRORERR  ERRORE      RORERR    RORERROR  RORERR         " << endl;
	
	cout << endl << endl;
	cout << "\t\t\t     Thank you for using LGF!" << endl << endl;
	cout << "\t\t\t      Hope to see you soon!" << endl << endl;
}

