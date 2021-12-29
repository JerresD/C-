#ifndef INHERITLINKEDLIST2_H
#define INHERITLINKEDLIST2_H

#include "LINKEDLIST1.h"
using namespace std;

template <class A, class B, class C, class D>
class orderedLinkedList:public linkedListType<A, B, C, D> //drived class for ordered linked list
{
	public:
		void insert(const A&, const B&, const C&, const D&);
};	

template <class A, class B, class C, class D>
class unorderedLinkedList:public linkedListType<A, B, C, D> //derived class for unordered linked list
{
	public:
		void insertLast(const A&, const B&, const C&, const D&);
		void insertAfter(const A&, const B&, const C&, const D&, const A&);
};


template <class A, class B, class C, class D>
void orderedLinkedList<A, B, C, D>::insert(const A& name, const B& matric, const C& year, const D& cgpa)
{
    listNode<A, B, C, D> *current;
    listNode<A, B, C, D> *trailCurrent; 
    listNode<A, B, C, D> *newNode; 
 
    bool found;
 
	assert(newNode != NULL);
    newNode = new listNode<A, B, C, D>;
    newNode->name = name;
    newNode->matric = matric;   
    newNode->year = year;   
    newNode->cgpa = cgpa;
    newNode->link = NULL;
 
    if(this->first == NULL)  //Case 1 (Empty)
    {
        this->first = newNode;
        this->last = newNode;
        this->count++;
    }
    else
    {
        current = this->first;
        found = false;
 
        while (current != NULL && !found) //search the list
           if (current->cgpa >= cgpa) //ascending order
               found = true;
           else
           {
               trailCurrent = current;
               current = current->link;
           }
 
        if (current == this->first) //Case 2 (first node)
        {
            newNode->link = this->first;
            this->first = newNode;
            this->count++;
        }
        else //Case 3 (any place)
        {
            trailCurrent->link = newNode; 
            newNode->link = current;
 
            if (current == NULL) //insert at last node
                this->last = newNode;
 
            this->count++;
        }
    }
}

template <class A, class B, class C, class D>
void unorderedLinkedList<A, B, C, D>::insertLast(const A& name, const B& matric, const C& year, const D& cgpa)
{
	listNode<A, B, C, D> *newNode;
	newNode = new listNode<A, B, C, D> ;
	
	assert(newNode != NULL);
	newNode->name = name;
    newNode->matric = matric;   
    newNode->year = year;   
    newNode->cgpa = cgpa;
	newNode->link = NULL;
	 
	if (this->first == NULL) //Empty
	{
		this->first = newNode;
		this->last = newNode;
		this->count++;
	}
	else //Insert at last node
	{
		this->last->link = newNode;
		this->last = newNode;
		this->count++;
	}
}

template <class A, class B, class C, class D>
void unorderedLinkedList<A, B, C, D>::insertAfter(const A& name, const B& matric, const C& year, const D& cgpa, const A& searchItem)
{
	listNode<A, B, C, D> *current;
    listNode<A, B, C, D> *newNode; 
 
    bool found;
 
	assert(newNode != NULL);
    newNode = new listNode<A, B, C, D>;
    newNode->name = name;
    newNode->matric = matric;   
    newNode->year = year;   
    newNode->cgpa = cgpa;
    newNode->link = NULL;
 
    if(this->first == NULL)  //Empty
    {
        cout << "The list is empty, can't insert after specific element. " << endl;
    }
    else
    {
        current = this->first;
        found = false;
 
        while (current != NULL && !found) //search the list
           if (current->name == searchItem || current->matric == searchItem) //search item
               found = true;
           else
           {
               current = current->link;
           }
 
        if (current == this->first) //first node
        {
            newNode->link = this->first->link;
            this->first->link = newNode;
            this->count++;
        }
        else //any place
        {
        	if(current != NULL)
        	{
            	newNode->link = current->link; 
            	current->link = newNode;
        	}
        	
        	else //last node
        	{
        		this->last->link = newNode;
				this->last = newNode;
			}
 
            this->count++;
        }
    }
}

#endif
