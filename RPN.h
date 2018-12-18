#include <string>
#include <stack>
#pragma once

using namespace std;
class RPN
{
public:
	RPN();
	~RPN();

	int counting(string expression);

private:
	bool isDelimeter(char c);
	bool isOperator(char c);
	bool isDigit(char c);
};

