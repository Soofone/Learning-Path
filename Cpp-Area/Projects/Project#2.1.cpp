#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

enum enQuestionsLevel { Easy = 1, Med = 2, Hard = 3, Mix = 4 };

enum enOperationType { Add = 1, Sub = 2, Mul = 3, Div = 4, MixOp = 5 };

struct stOperationElements
{
	short NumberOfQuestions = 0, Number1 = 0, Number2 = 0, OperationResult = 0;
	enOperationType OperationType;
	enQuestionsLevel QuestionsLevel;
};

short RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

short ReadNumberOfQuestions()
{
	short Number = 0;
	cout << "How Many Questions do you want to answer ? ";
	cin >> Number;
	return Number;
}

enQuestionsLevel ReadQuestionsLevel()
{
	short Number = 0;
	do
	{
		cout << "Enter Questions Level [1] Easy, [2] Med, [3] Hard, [4] Mix ? ";
		cin >> Number;
	} while (Number < 1 || Number > 4);
	return (enQuestionsLevel)Number;
}

enOperationType ReadOperationType()
{
	short Number = 0;
	do
	{
		cout << "Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ? ";
		cin >> Number;
	} while (Number < 1 || Number > 5);
	return (enOperationType)Number;
}

char PrintOperationType(enOperationType OperationType)
{
	if (OperationType == enOperationType::MixOp)
		return PrintOperationType((enOperationType)RandomNumber(1, 4));
	switch (OperationType)
	{
	case enOperationType::Add:
		return '+';
		break;
	case enOperationType::Div:
		return '/';
		break;
	case enOperationType::Mul:
		return '*';
		break;
	case enOperationType::Sub:
		return '-';
		break;
	}
}

short PrintOperationNumbers(enQuestionsLevel QuestionsLevel)
{
	if (QuestionsLevel == enQuestionsLevel::Easy)
		return RandomNumber(1, 10);
	else if (QuestionsLevel == enQuestionsLevel::Med)
		return RandomNumber(10, 100);
	else if (QuestionsLevel == enQuestionsLevel::Hard)
		return RandomNumber(100, 1000);
	else
		return RandomNumber(1, 1000);
}

int CalculateOperationResult(stOperationElements OperationElements, char OpType)
{
	switch (OpType)
	{
	case '+':
		return OperationElements.Number1 + OperationElements.Number2;
		break;
	case '-':
		return OperationElements.Number1 - OperationElements.Number2;
		break;
	case '*':
		return OperationElements.Number1 * OperationElements.Number2;
		break;
	case '/':
		return OperationElements.Number1 / OperationElements.Number2;
		break;
	}
}

bool IsCorrectAnswer(int ComputerAnswer, int PlayerResult, int& NumberOfRightAnswers, int& NumberOfWrongAnswers)
{
	if (ComputerAnswer == PlayerResult)
	{
		NumberOfRightAnswers++;
		return true;
	}
	else
	{
		NumberOfWrongAnswers++;
		return false;
	}
}

void PrintResult(bool Decision, int ComputerAnswer)
{
	if (Decision)
		cout << "Right Answer ;-)";
	else
	{
		cout << "Wrong Answer ;-(\n";
		cout << "The right answer is: " << ComputerAnswer;
	}
}

void SetColorScreen(bool Desicion)
{
	if (Desicion)
		system("color 2F");
	else
		system("color 4F");
}

void SetFinalColorScreen(string Result)
{
	if (Result == "PASS :-)")
		system("color 2F");
	else
		system("color 4F");
}

stOperationElements FillOperationElements()
{
	stOperationElements OperationElements;
	OperationElements.NumberOfQuestions = ReadNumberOfQuestions();
	OperationElements.QuestionsLevel = ReadQuestionsLevel();
	OperationElements.OperationType = ReadOperationType();
	return OperationElements;
}

string GameResultDesicion(int NumberOfRightAnswers, int NumberOfWrongAnswers)
{
	if (NumberOfRightAnswers < NumberOfWrongAnswers)
		return "FAIL :-(";
	else
		return "PASS :-)";
}

void StartGame(stOperationElements OperationElements, int& NumberOfRightAnswers, int& NumberOfWrongAnswers)
{
	for (short i = 1; i <= OperationElements.NumberOfQuestions; i++)
	{
		OperationElements.Number1 = PrintOperationNumbers(OperationElements.QuestionsLevel);
		OperationElements.Number2 = PrintOperationNumbers(OperationElements.QuestionsLevel);
		int PlayerResult = 0;
		char OpType = ' ';
		cout << "\n\nQuestion [" << i << '/' << OperationElements.NumberOfQuestions << "]\n\n";

		cout << OperationElements.Number1 << endl;
		cout << OperationElements.Number2;
		OpType = PrintOperationType(OperationElements.OperationType);
		cout << " " << OpType;
		cout << "\n\n____________\n";
		cin >> PlayerResult;
		int ComputerAnswer = CalculateOperationResult(OperationElements, OpType);
		bool Decision = IsCorrectAnswer(ComputerAnswer, PlayerResult, NumberOfRightAnswers, NumberOfWrongAnswers);
		PrintResult(Decision, ComputerAnswer);
		SetColorScreen(Decision);
	}

}

string PrintOpType(enOperationType OpType)
{
	switch (OpType)
	{
	case enOperationType::Add:
		return "Add";
		break;
	case enOperationType::Sub:
		return "Sub";
		break;
	case enOperationType::Mul:
		return "Mul";
		break;
	case enOperationType::Div:
		return "Div";
		break;
	case enOperationType::MixOp:
		return "Mix";
		break;
	}
}

string PrintQuestionLevel(enQuestionsLevel QuestionLevel)
{
	switch (QuestionLevel)
	{
	case enQuestionsLevel::Easy:
		return "Easy";
		break;
	case enQuestionsLevel::Med:
		return "Med";
		break;
	case enQuestionsLevel::Hard:
		return "Hard";
		break;
	case enQuestionsLevel::Mix:
		return "Mix";
		break;
	}
}

void GameResult(string Result, stOperationElements OperationElements, int NumberOfRightAnswers, int NumberOfWrongAnswers)
{
	SetFinalColorScreen(Result);
	cout << "\n\n-------------------------------\n\n";
	cout << " Final Results is " << Result;
	cout << "\n\n-------------------------------\n";
	cout << "\nNumber of Questions    : " << OperationElements.NumberOfQuestions;
	cout << "\nQuestion Level         : " << PrintQuestionLevel(OperationElements.QuestionsLevel);
	cout << "\nOperation Type         : " << PrintOpType(OperationElements.OperationType);
	cout << "\nNumber of Right Answers: " << NumberOfRightAnswers;
	cout << "\nNumber of Wrong Answers: " << NumberOfWrongAnswers;
	cout << "\n\n-------------------------------\n";
}

void PlayGame()
{
	char PlayAgain = 'y';
	do
	{
		system("cls");
		system("color 0F");
		stOperationElements OperationElements = FillOperationElements();
		int NumberOfRightAnswers = 0, NumberOfWrongAnswers = 0;
		StartGame(OperationElements, NumberOfRightAnswers, NumberOfWrongAnswers);
		GameResult(GameResultDesicion(NumberOfRightAnswers, NumberOfWrongAnswers), OperationElements, NumberOfRightAnswers, NumberOfWrongAnswers);
		cout << "Do yo want to play again? Y/N? ";
		cin >> PlayAgain;
	} while (tolower(PlayAgain) == 'y');
}

int main()
{
	srand((unsigned)time(NULL));

	PlayGame();

	return 0;
}