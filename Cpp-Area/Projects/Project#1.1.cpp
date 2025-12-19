#include <iostream>
#include <cstdlib>
using namespace std;

enum enGameChoices { Stone = 1, Paper = 2, Scissors = 3 };

enum enWinner { Player = 1, Computer = 2, NoWinner = 3 };

int ReadNumberOfRounds()
{
	int Number = 0;

	do
	{
		cout << "How Many Rounds 1 to 10 ?\n";
		cin >> Number;
	} while (Number < 1 || Number > 10);
	return Number;
}

int RandomNumber(int From, int To)
{
	int randnum = rand() % (To - From + 1) + From;
	return randnum;
}

enGameChoices ReadPlayerChoice()
{
	int Choice = 0;
	do
	{
		cout << "Your Choice: [1]:Stone, [2]:Paper, [3]:Scissors ? ";
		cin >> Choice;
	} while (Choice < 1 || Choice > 3);
	return (enGameChoices)Choice;
}

enGameChoices ReadComputerChoice()
{
	return (enGameChoices)RandomNumber(1, 3);
}

string PrintChoice(enGameChoices Choice)
{
	switch (Choice)
	{
	case enGameChoices::Paper:
		return "Paper";
		break;
	case enGameChoices::Stone:
		return "Stone";
		break;
	case enGameChoices::Scissors:
		return "Scissors";
		break;
	}
}

enWinner RoundWinner(enGameChoices PlayerChoice, enGameChoices ComputerChoice)
{
	if (PlayerChoice == ComputerChoice)
		return enWinner::NoWinner;
	if (PlayerChoice == enGameChoices::Paper)
	{
		if (ComputerChoice == enGameChoices::Scissors)
			return enWinner::Computer;
		else
			return enWinner::Player;
	}
	if (PlayerChoice == enGameChoices::Scissors)
	{
		if (ComputerChoice == enGameChoices::Stone)
			return enWinner::Computer;
		else
			return enWinner::Player;
	}
	if (PlayerChoice == enGameChoices::Stone)
	{
		if (ComputerChoice == enGameChoices::Paper)
			return enWinner::Computer;
		else
			return enWinner::Player;
	}
}

string PrintChoice(enWinner Winner)
{
	switch (Winner)
	{
	case enWinner::Player:
		return "Player";
	case enWinner::Computer:
		return "Computer";
	case enWinner::NoWinner:
		return "No Winner";
	}
}

void RoundCard(int RoundNumber, enGameChoices PlayerChoice, enGameChoices ComputerChoice, int& PlayerWonTimes, int& ComputerWonTimes, int& DrawTimes)
{
	cout << "\n\n_________________Round [" << RoundNumber << "]_________________\n";
	cout << "\nPlayer Choice  : " << PrintChoice(PlayerChoice);
	cout << "\nComputer Choice: " << PrintChoice(ComputerChoice);
	enWinner Winner = RoundWinner(PlayerChoice, ComputerChoice);
	cout << "\nRound Winner   : [" << PrintChoice(Winner) << "]";
	cout << "\n\n____________________________________________\n\n";
	if (Winner == enWinner::Player)
	{
		PlayerWonTimes++;
		system("color 2F");
	}
	else if (Winner == enWinner::Computer)
	{
		ComputerWonTimes++;
		system("color 4F");
	}
	else
	{
		DrawTimes++;
		system("color 6F");
	}
}

void ResultHeader()
{
	cout << "\t\t______________________________________________________\n\n";
	cout << "\t\t\t\t+++ G a m e  O v e r +++\n\n";
	cout << "\t\t______________________________________________________\n\n";
}

void GameRounds(int NumberOfRounds, int& PlayerWonTimes, int& ComputerWonTimes, int& DrawTimes)
{
	for (int i = 1; i <= NumberOfRounds; i++)
	{
		cout << "\n\nRound [" << i << "] begins:\n\n";
		enGameChoices PlayerChoice = ReadPlayerChoice();
		enGameChoices ComputerChoice = ReadComputerChoice();
		RoundCard(i, PlayerChoice, ComputerChoice, PlayerWonTimes, ComputerWonTimes, DrawTimes);
	}
}

void GameResults(int NumberOfRounds, int PlayerWonTimes, int ComputerWonTimes, int DrawTimes, string FinalWinner)
{;
	cout << "\t\t___________________[Game Results]_____________________\n";
	cout << "\n\t\tGame Rounds       : " << NumberOfRounds;
	cout << "\n\t\tPlayer Won Times  : " << PlayerWonTimes;
	cout << "\n\t\tComputer Won Times: " << ComputerWonTimes;
	cout << "\n\t\tDraw Won Times    : " << DrawTimes;
	cout << "\n\t\tFinal Winner      : " << FinalWinner;
	cout << "\n\n\t\t______________________________________________________\n\n";
}

string FindWinner(int PlayerWonTimes, int ComputerWonTimes, int DrawTimes)
{
	if (PlayerWonTimes > ComputerWonTimes && PlayerWonTimes > DrawTimes)
		return "Player";
	else if (ComputerWonTimes > PlayerWonTimes && ComputerWonTimes > DrawTimes)
		return "Computer";
	else
		return "No Winner";
}

void PlayGame()
{
	char PlayAgain = 'y';
	do
	{
		system("cls");
		system("color 0F");
		int NumberOfRounds = ReadNumberOfRounds();
		int PlayerWonTimes = 0, ComputerWonTimes = 0, DrawTimes = 0;
		string FinalWinner = "";
		GameRounds(NumberOfRounds, PlayerWonTimes, ComputerWonTimes, DrawTimes);
		ResultHeader();
		FinalWinner = FindWinner(PlayerWonTimes, ComputerWonTimes, DrawTimes);
		GameResults(NumberOfRounds, PlayerWonTimes, ComputerWonTimes, DrawTimes, FinalWinner);
		cout << "Do you want to play again: ";
		cin >> PlayAgain;
	} while (tolower(PlayAgain) == 'y');
}

int main()
{
	srand((unsigned)time(NULL));

	PlayGame();

	return 0;
}