#include <iostream>	
using namespace std;

int main()
{
	int month = 1;
	double outstandingBalance = 0.0;
	double monthlyPayment = 0.0;
	double annualInterest = 0.0;
	double netIncome = 0.0;
	double monthlyInterest = 0.0;
	double extraInterest = 3;
	double totalInterest = 0.0;
	double percentage = 0.0;
	
		cout.setf(ios::fixed); //To allow all arrays display in 2 decimal places
		cout.setf(ios::showpoint);
		cout.precision(2);
	
	cout << endl;
	cout << "\t\t===========================================================" << endl << endl; //For greetings
	cout << "\t\t\tWELCOME TO CREDIT CARD PAYMENT CALCULATOR" << endl << endl;
	cout << "\t\t===========================================================" << endl << endl;
	
	cout << "What is the amount of outstanding credit balance? Please enter : RM "; //Ask user for outstanding credit balance
	cin >> outstandingBalance;
		while (outstandingBalance <= 0)
		{
			cout << "\tERROR. Please try again with a bigger number : RM " ;
			cin >> outstandingBalance;
		}
	cout << "---------------------------------------------------------------------------------------------" << endl;
	
	cout << "How much is your monthly payment? Please enter : RM "; //Ask user for his/her monthly payment
	cin >> monthlyPayment;
		while ((monthlyPayment/outstandingBalance) < 0.05)
		{
			cout << "\tERROR. Please try again with a number that exceed 5% of outstanding balance : RM " ;
			cin >> monthlyPayment;
		}
	cout << "---------------------------------------------------------------------------------------------" << endl;
	
	cout << "What is the annual interest(%)? Please enter : "; //Ask user for annual interest
	cin >> annualInterest;
		while (annualInterest <= 0 or annualInterest >= 30) //Annual interest should not be too much
		{
			cout << "\tERROR. Please try again with a another value : ";
			cin >> annualInterest;
		}
	cout << "---------------------------------------------------------------------------------------------" << endl;
	
	cout << "How much is your net income? Please enter : RM "; //Ask user for his/her net income
	cin >> netIncome;
		while (netIncome <= 0)
		{
			cout << "\tERROR. Please try again with a bigger value : RM ";
			cin >> netIncome;
		}
	cout << "---------------------------------------------------------------------------------------------" << endl;
	
	cout << endl;
	
	
	while (month <= 12 && outstandingBalance > monthlyPayment) //Calculation of monthly interest within 12 months
	{
		monthlyInterest = outstandingBalance * annualInterest / (12 * 100);
		outstandingBalance = outstandingBalance + monthlyInterest;
		outstandingBalance -= monthlyPayment;
		
		cout << "Your balance in " << month++ << " month is : RM " << outstandingBalance; //To show the balance for every months
		cout <<	"\t\t\t" << "(monthly interest = RM " << monthlyInterest << ")" << endl; //To show monthly interest
		
		if (outstandingBalance < monthlyPayment)
		{
			cout << "Your balance in " << month << " month is : RM 0.00 " << endl;
			cout << "\n*********************************************************************************************" << endl;
			cout << "\n\t\t\t\tYour debt will be paid off in " << endl; //To show the number of months needed to pay off the debt
			cout << "\t\t\t\t\t  " << month << " month" << endl << endl;			
		}
	}
	
	
	while (month > 12 && outstandingBalance > monthlyPayment) //Calculation of monthly interest after exceeding 12 months
	{
		monthlyInterest = outstandingBalance * (annualInterest + extraInterest) / (12 * 100);
		outstandingBalance = outstandingBalance + monthlyInterest;
		outstandingBalance -= monthlyPayment;
		
		cout << "Your balance in " << month++ << " month is : RM " << outstandingBalance;
		cout <<	"\t\t\t" << "(monthly interest = RM " << monthlyInterest << ")" << endl;
		
		if (outstandingBalance < monthlyPayment)
		{
			cout << "Your balance in " << month << " month is : RM 0.00 " << endl;
			cout << "\n*********************************************************************************************" << endl;
			cout << "\n\t\t\t\tYour debt will be paid off in " << endl;
			cout << "\t\t\t\t\t  " << month << " month" << endl << endl;
		}
	}


	//To determine the financial status of the user
	percentage = monthlyPayment / netIncome * 100;
	
	if (percentage >= 30 && month > 24)
		cout << "\t\t\t\t  Financial status: Very Bad";
	
	else if (percentage >= 30 && month <= 24)
		cout << "\t\t\t\t  Financial status: Bad";
		
	else if (percentage >= 20 && percentage < 30)
		cout << "\t\t\t\t  Financial status: Bad";
	
	else if (percentage >= 10 && percentage < 20)
		cout << "\t\t\t\t  Financial status: Moderate";
		
	else 
		cout << "\t\t\t\t  Financial status: Good";
	
	cout << "\n\n*********************************************************************************************" << endl;
	
	return 0;
}
