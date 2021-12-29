#ifndef LINKEDLIST1_H
#define LINKEDLIST1_H
#include <cassert>
#include <iostream>
using namespace std;

template <class A, class B, class C, class D>
struct listNode
{
	A name;
	B matric;
	C year;
	D cgpa;
   	listNode<A, B, C, D> *link; // Pointer to the next node
};

template <class A, class B, class C, class D>
class linkedListType
{

	public:
		void initialize();
		bool isEmpty() const;
		int length() const;
		void print() const;
		void destroyList();
	/*	T front() const;
		T back() const; */
		bool search(const A &searchItem); 
		void searchName(const A &searchItem);
		void searchMatric(const B &searchItem);
		void searchYear(const C &searchItem);
		void searchCGPA(const D &searchItem);
		void deleteNode(const A &deleteItem);
		linkedListType();
		~linkedListType();
	
/*	private:*/
		int count;
		listNode<A, B, C, D> *first;
		listNode<A, B, C, D> *last;

};

template <class A, class B, class C, class D>
bool linkedListType<A, B, C, D>::isEmpty() const
{
	return(first == NULL);
}

template <class A, class B, class C, class D>
void linkedListType<A, B, C, D>::destroyList()
{
	listNode<A, B, C, D> *temp;
	
	while(first != NULL)
	{
		temp = first;
		first = first->link;
		delete temp;
	}
	last = NULL;
	count = 0;
}

template <class A, class B, class C, class D>
void linkedListType<A, B, C, D>::initialize()
{
	destroyList();
}

template <class A, class B, class C, class D>
void linkedListType<A, B, C, D>::print() const
{
	listNode<A, B, C, D> *current; 
    current = first;  
    
	cout << "Name" << "\t" << "Matric" << "\t" << "Year" << "\t" << "CGPA" << endl;
    while (current != NULL) 
    {
    	cout << current->name << "\t" << current->matric << "\t" << current->year << "\t" << current->cgpa << "\t" << endl;
    	current = current->link;
    }
}

template <class A, class B, class C, class D>
int linkedListType<A, B, C, D>::length() const
{
    return count;
}
/*
template <class T>
T linkedListType<T>::front() const
{   
    assert(first != NULL)
    return first->info;
}

template <class T>
T linkedListType<T>::back() const
{   
    assert(last != NULL)

    return last->info; 
}
*/		
template <class A, class B, class C, class D>
bool linkedListType<A, B, C, D>::search(const A &searchItem)
{
	listNode<A, B, C, D> *current;
    bool found = false;
    
	current = first;	
	while (current != NULL && !found)
	{
		if  (current->name == searchItem || current->matric == searchItem)
			found = true;
		else
			current = current->link;
	}
			
    return found;
}         

template <class A, class B, class C, class D>
void linkedListType<A, B, C, D>::searchName(const A &searchItem)
{
	listNode<A, B, C, D> *current;
	bool found = false;
	
	current = first;
	while (current != NULL && !found)
	{
		if  (current->name == searchItem)
			found = true;
		else
			current = current->link;
	}
	
	if(current != NULL)
		cout << current->name << "\t" << current->matric << "\t" << current->year << "\t" << current->cgpa << "\t" << endl;
	else
		cout << "Item not found. " << endl;
}

template <class A, class B, class C, class D>
void linkedListType<A, B, C, D>::searchMatric(const B &searchItem)
{
	listNode<A, B, C, D> *current;
	bool found = false;
	
	current = first;
	while (current != NULL && !found)
	{
		if  (current->matric == searchItem)
			found = true;
		else
			current = current->link;
	}
	
	if(current != NULL)
		cout << current->name << "\t" << current->matric << "\t" << current->year << "\t" << current->cgpa << "\t" << endl;
	else
		cout << "Item not found. " << endl;}

template <class A, class B, class C, class D>
void linkedListType<A, B, C, D>::searchYear(const C &searchItem)
{
	listNode<A, B, C, D> *current;
	
	current = first;
	while (current != NULL)
	{
		if  (current->year == searchItem)
		{
			cout << current->name << "\t" << current->matric << "\t" << current->year << "\t" << current->cgpa << "\t" << endl;
			current = current->link;
		}
		else
			current = current->link;
	}
}

template <class A, class B, class C, class D>
void linkedListType<A, B, C, D>::searchCGPA(const D &searchItem)
{
	listNode<A, B, C, D> *current;
	
	current = first;
	while (current != NULL)
	{
		if  (current->cgpa == searchItem)
		{
			cout << current->name << "\t" << current->matric << "\t" << current->year << "\t" << current->cgpa << "\t" << endl;
			current = current->link;
		}
		else
			current = current->link;
	}
}

template <class A, class B, class C, class D>
void linkedListType<A, B, C, D>::deleteNode(const A &deleteItem)
{
	listNode<A, B, C, D> *current;
	listNode<A, B, C, D> *trailcurrent;
	bool found;
	   
	if (first == NULL)  // case 1
		cout << "Cannot delete from an empty list. " << endl;
	else
	{
		if(first->name == deleteItem || first->matric == deleteItem) //case 2   
		{
			current = first;
			first = first->link;
			count--;
			if(first == NULL)
				last = NULL;
			delete current;
			cout << "First node has been deleted. " << endl;
		}
		else
		{
			found = false;
			trailcurrent = first;
			current = first->link; 
			
			while (current != NULL && !found)
			{
				if (current->name != deleteItem || current->matric != deleteItem) //only student name and student matric number can be searched
				{
					trailcurrent = current;
					current = current->link;
				}
				else
					found = true;
			}
			
			if(found) // case 3 
			{
				trailcurrent->link = current->link;
				if (last == current)
				{
					last = trailcurrent;
					cout << "Last node has been deleted. "<< endl;
				}
				count--;
				delete current;
			}
			else //case 4
				cout << "Item to be deleted is not in the list." << endl;
		}
	}
}

template <class A, class B, class C, class D>
linkedListType<A, B, C, D>::linkedListType() //default constructor
{
	first = NULL;
	last = NULL;
	count = 0; 
}

template <class A, class B, class C, class D>
linkedListType<A, B, C, D>::~linkedListType() //destructor
{
	destroyList();
}



#endif
