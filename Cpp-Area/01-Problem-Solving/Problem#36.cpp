#include <iostream>
using namespace std;

enum enOperationType { Add = '+', Subtract = '-', Multiply = '*', Divide = '/' };

float ReadNumber(string Message)
{
	float Number = 0;

	cout << Message;
	cin >> Number;
	return Number;
}

enOperationType ReadOpType()
{
	char OT = '+';
	cout << "Please enter Operation Type ( +, - , * , / )? ";
	cin >> OT;
	return (enOperationType)OT;
}

float Calculate(float Number1, float Number2, enOperationType OpType)
{
    switch (OpType)
    {
    case enOperationType::Add:
        return Number1 + Number2;
    case enOperationType::Subtract:
        return Number1 - Number2;
    case enOperationType::Multiply:
        return Number1 * Number2;
    case enOperationType::Divide:
        return Number1 / Number2;
    default:
        return Number1 + Number2;
    }
}

int main()
{
    float Number1 = ReadNumber("Enter the first number: ");
    float Number2 = ReadNumber("Enter the second number: ");

    enOperationType OpType = ReadOpType();
    cout << endl << "Result = " << Calculate(Number1, Number2, OpType) << endl;

    return 0;
}