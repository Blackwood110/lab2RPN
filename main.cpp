#include <iostream>     
#include <string>
#include "RPN.h"
using namespace std;

int main()
{
	RPN newRPN = RPN();
	string expression;

	cout << "Enter expression in postfix RPN: \n";
	getline(cin, expression);
	if (newRPN.stringIsEmpty(expression))
	{
		cout << "string is empty \n";
		return 0;
	}

	int result = newRPN.counting(expression);

	cout << "Result = " << result << "\n";

	system("pause");
	return 0;
}