#include <string>
#include <stack>
#include <iostream>   
#pragma once

using namespace std;
class RPN
{
public:
	RPN();
	~RPN();

	int counting(string expression);
	bool stringIsEmpty(string str);

private:
	bool isDelimeter(char c);
	bool isOperator(char c);
	bool isDigit(char c);
};

