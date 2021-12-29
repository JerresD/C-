#include <iostream>
using namespace std;

class datetype
{
  public:
	void setdate(int month, int day, int year); //function to set the date 
	void getdate(int& month, int& day,int& year); //function to return the date 
	void printdate() const; //function to output the date in the form (mmKdd—yy) 	
	void setmonth(int month);
	void setday(int day);
	void setyear(int year);
	int getmonth() const;
	int getday() const;
	int getyear() const;
	bool leapyear() const;
	int daysInMonth() const;
	void calculateNewDate(int addDay);
	datetype(int month = 1, int day = 1, int year = 2020);

  private:
	int dmonth;	//variable to store the month
	int dday;	//variable to store the day
	int dyear;	//variable to store the year
	friend class extdatetype; //allow derived class to access

};

class extdatetype:public datetype
{
  public: 
	void printstring();
	void printboth();
	extdatetype(){smonth = "";};
	
  private:
	string smonth; 
};

class studentinfo
{
  public:	
	studentinfo& info(string f, string l, string m, int month, int day, int year);
	void printinfo();
	studentinfo(string f = "", string l = "", string m = "", int month = 1, int day = 1, int year = 2020);
	
  private:
	string firstname;
	string lastname;
	string matricNo;
	extdatetype birthday; //composition
};


//function of base class
void datetype::setdate(int month, int day, int year)
{
	setmonth(month);
	setday(day);
	setyear(year);
}

void datetype::getdate(int& month, int& day,int& year) 
{
	month = dmonth;
	day = dday;
	year = dyear;
}

void datetype::printdate() const
{
	cout << dmonth << "-" << dday << "-" << dyear;
}


void datetype::setmonth(int month)
{
	if(month >= 1 && month <= 12)
		dmonth = month;
	else
		dmonth = 1; 
}

void datetype::setday(int day)
{
	int arr[12] = {31,28,31,30,31,30,31,31,30,31,30,31} ;
	if(leapyear())
		arr[1]++;
	if(day >= 1 && day <= arr[dmonth - 1])	
		dday = day;
	else
		dday = 1;
}

void datetype::setyear(int year)
{
	if(year > 0)
		dyear = year;
	else 
		dyear = 2020;
} 

int datetype::getmonth() const
{
	return dmonth;
}

int datetype::getday() const
{
	return dday;
}

int datetype::getyear() const
{
	return dyear;
}

bool datetype::leapyear() const
{
	int div4 = dyear % 4;
	int div100 = dyear % 100;
	int div400 = dyear % 400;
	
	if(div4 == 0 && (div100 != 0 || div400 == 0))
		return true;
	else
		return false;	
}

int datetype::daysInMonth() const
{
	switch(dmonth)
	{
		case 1:
			return 31;
			break;
		case 2:
			if(leapyear())
				return 29;
			else
				return 28;
		case 3:
			return 31;
			break;
		case 4:
			return 30; 
			break;
		case 5:
			return 31;
			break;
		case 6:
			return 30; 
			break;
		case 7:
			return 31;
			break;
		case 8:
			return 31; 
			break;
		case 9:
			return 30; 
			break;
		case 10:
			return 31;
			break;
		case 11:
			return 30; 
			break;
		case 12:
			return 31;
			break;
		default:
			return 0;
	}
}

void datetype::calculateNewDate(int addDay)
{
	int arr[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	if(leapyear())
		arr[1]++;	

	for(int i = 0; i < addDay; i++)
	{
		if(dday < arr[dmonth - 1])
			dday++;
		else if((dday == arr[dmonth - 1]) && (dmonth < 12))
		{
			dday = 1;
			dmonth++;
		}
		else if((dday == arr[dmonth - 1]) && (dmonth = 12))
		{
			dday = 1;
			dmonth = 1;
			dyear++;
		}		
	}
}

datetype::datetype(int month, int day, int year)
{
	setdate(month, day, year);
}

//function of derived class
void extdatetype::printstring()
{	
	if(dmonth == 1)
		smonth = "January";
	else if(dmonth == 2)
		smonth = "February";
	else if(dmonth == 3)
		smonth = "March";
	else if(dmonth == 4)
		smonth = "April";
	else if(dmonth == 5)
		smonth = "May";
	else if(dmonth == 6)
		smonth = "June";
	else if(dmonth == 7)
		smonth = "July";
	else if(dmonth == 8)
		smonth = "August";
	else if(dmonth == 9)
		smonth = "September";
	else if(dmonth == 10)
		smonth = "October";
	else if(dmonth == 11)
		smonth = "November";
	else if(dmonth == 12)
		smonth = "December";
		
	cout << smonth << "-" << dday << "-" << dyear;
}

void extdatetype::printboth()
{
	printdate();
	cout << " and ";
	printstring();
}

//Function of another base class
studentinfo& studentinfo::info(string f, string l, string m, int month, int day, int year)
{
	firstname = f;
	lastname = l;
	matricNo = m;
	birthday.setdate(month, day, year); //call function from other class
	return *this;
}

void studentinfo::printinfo()
{
	cout << "Name: " << firstname << " " << lastname << endl;
	cout << "   Matric No: " << matricNo << endl;
	cout << "   Birthday: ";
	birthday.printboth();
}

studentinfo::studentinfo(string f, string l, string m, int month, int day, int year) 
{
	birthday.setdate(month, day, year);
	firstname = f;
	lastname = l;
	matricNo = m;
}

int main()
{
	extdatetype date;
	date.setdate(5,20,2005);
	
	cout << "**Tesing: " << "\nOriginal date: ";
	date.printdate();
	date.getdate();
	date.printdate();
	cout << "\nIn string form: ";
	date.printstring();
	cout << "\nFormat as B(print both): ";
	date.printboth();
	
	int x = 1000; //Number of days to be added
	cout << "\n\nAfter adding " << x << " days: ";
	date.calculateNewDate(x);
	date.printboth();
	cout << "\n**";
	
	studentinfo stu1("James", "Oliver", "14327", 5, 21, 1980);
	studentinfo stu2;
	stu2.info("Adam", "Billy", "17356", 12, 18, 1999);	
	cout << "\n\nStudent information: " << endl;
	cout << "1. " ;
	stu1.printinfo();
	cout << "\n\n2. ";
	stu2.printinfo();
	cout << endl;
	
	return 0;
}





