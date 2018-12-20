#include "RPN.h"

RPN::RPN()
{
}


RPN::~RPN()
{
}

int RPN::counting(string expression)
{
	int result = 0;
	stack<int> newStack;

	for (int i = 0; i < expression.size(); i++)
	{
		if (isDigit(expression[i]))
		{
			string number = "";
			while (!isDelimeter(expression[i]) && !isOperator(expression[i]))
			{
				number += expression[i];
				i++;
				if (i == expression.size())
					break;
			}
			newStack.push(stoi(number));
			i--;
		}
		else if (isOperator(expression[i]))
		{
			if (newStack.size() < 3) { cout << "Invalid expression format, insufficient operands"; exit(0); }
			int x = newStack.top();
			newStack.pop();
			int y = newStack.top();
			newStack.pop();
			if (expression[i] == '+') result = y + x;
			else if (expression[i] == '-') result = y - x;
			else result = y * x;
			newStack.push(result);
		}
	}
	result = newStack.top();
	newStack.pop();
	return result;
}

bool RPN::stringIsEmpty(string str)
{
	for (int i = 0; i < str.size(); i++)
	{
		if (!isspace(str[i])) return false;
	}
	return true;
}

bool RPN::isDelimeter(char c)
{
	if (string(" =").find(c) != string::npos)
		return true;
	return false;
}

bool RPN::isOperator(char c)
{
	if (string("+-*").find(c) != string::npos)
		return true;
	return false;
}

bool RPN::isDigit(char c)
{
	int symbol = c - '0';
	if (symbol <= 9 && symbol >= 0)
		return true;
	return false;
}
