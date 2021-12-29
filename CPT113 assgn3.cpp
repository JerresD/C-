#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include "STACK.h"
using namespace std;

void convertToPostfix(char infix[], char postfix[]);
bool isOperator(char c);
int precedence(char operator1, char operator2);

int main()
{
	const int MAX_SIZE = 30;
	char infix[MAX_SIZE], postfix[MAX_SIZE] = {0};
	string exp;
	
	cout << "Enter the infix expression: ";
	getline(cin, exp);
	strcpy(infix, exp.c_str()); //convert string to array of char(store in infix[])
	
    cout << endl;
	convertToPostfix(infix, postfix);
	cout << "The postfix expression is: " << postfix;
	cout << endl;

    return 0;
}

void convertToPostfix(char infix[], char postfix[])
{
	stack1<char> s;	
	int j = 0;
	
	s.push('('); //push a left parenthesis
	
	for(int i = 0; i < strlen(infix); i++) //i for infix, j for postfix
	{
		if(isdigit(infix[i]))
			postfix[j++] = infix[i];
			
		else if(infix[i] == '(')
			s.push(infix[i]);
		
		else if(isOperator(infix[i]))
		{
			char operator2 = infix[i]; //current operatpr
			while(!s.isEmpty() && isOperator(s.stackTop()) && ((precedence(s.stackTop(), operator2) == 1) || (precedence(s.stackTop(), operator2) == 0)))
			{
				postfix[j++] = ' ';
				postfix[j++] = s.stackTop();
				s.pop();
			}	
			postfix[j++] = ' ';
			s.push(operator2);
		}
		
		else if(infix[i] == ')')
		{
            while(!s.isEmpty() && s.stackTop() != '(') 
			{
				postfix[j++] = ' ';
				postfix[j++] = s.stackTop();
				s.pop();
            }
            if(s.isEmpty()) 
            	cout << "missing left parenthesis '('. ";	
			
			s.pop(); // Discard the left paren
			postfix[j++] = ' ';
        } 
        
        else if(isspace(infix[i])) { }
        
		else 
			cout << "invalid input character. ";
	}
		
	while(!s.isEmpty() && s.stackTop() != '(') 
	{
		postfix[j++] = ' ';
		postfix[j++] = s.stackTop();
		s.pop();
    }
    
    if (s.isEmpty())
    	cout << "missing left parenthesis '('. ";

    s.pop();

    if (!s.isEmpty()) 
    cout << "missing right parenthesis ')'. ";
}


bool isOperator(char c)
{
    switch (c) 
	{
	    case '+':
	    case '-':
	    case '*':
	    case '/':
	    case '^':
	    case '%':
	        return true;
	    default:
	        return false;
    }
}

int precedence(char operator1, char operator2)
{	
	int prec; 
	
    if ( operator1 == '^' ) 
    {
    	prec = 1;
	}
	else if ( operator2 == '^' )
	{
		prec = -1;
	}
	else if ( operator1 == '*' || operator1 == '/' || operator1 == '%' ) 
	{
        if( operator2 == '+' || operator2 == '-' )
        	prec = 1;
        else if( operator2 == '*' || operator2 == '/' || operator2 == '%' )
        	prec = 0;
    } 
	else if ( operator1 == '+' || operator1 == '-' ) 
	{
        if ( operator2 == '+' || operator2 == '-' )
        	prec = 0;
        else
        	prec = -1;
    }

    return prec;
}

