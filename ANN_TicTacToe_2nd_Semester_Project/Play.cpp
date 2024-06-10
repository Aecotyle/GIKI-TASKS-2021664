#include "trainNetwork.h"
/************************************/
//Reg no.2021468, 2021578, 2021446
/************************************/
//prototypes
void gameOverCheck(bool &loop, TicTac gameBoard);
void menu();
void screenClear();
void validOption(int &choice, int from, int to);


int main()
{

	int choice, menuOption;
	double probability, min;
	int AImove;
	bool loop;
	TicTac gameBoard;
	std::vector<double> test;
	std::vector<int> topology;
	topology.push_back(9);
	topology.push_back(36);
	topology.push_back(36);
	topology.push_back(1);

	Network net(topology, 0.1);
	/*passing the network to training funciton for feedforward
	back propogation*/
	train(net);

	while (true)
	{
		loop = true;
		gameBoard.clearBoard();

		menu();
		std::cin >> menuOption;

		validOption(menuOption, 1, 2);
		if (menuOption == 2)
		{
			std::cout << "Quiting...\n";
			break;
		}

		while (loop)
		{

			test.clear();
			test.resize(0);
			gameBoard.displayBoard();

			std::cout << "Enter your option: ";
			std::cin >> choice;
			validOption(choice, 1, 9);
			while (gameBoard.isEmpty(choice - 1))
			{
				std::cout << "The cell is already filled\n";
				std::cout << "Enter your options: ";
				std::cin >> choice;
				validOption(choice, 1, 9);
			}

			switch (choice)
			{
			case 1:
				gameBoard.setBoard(choice - 1) = X;
				break;
			case 2:
				gameBoard.setBoard(choice - 1) = X;
				break;
			case 3:
				gameBoard.setBoard(choice - 1) = X;
				break;
			case 4:
				gameBoard.setBoard(choice - 1) = X;
				break;
			case 5:
				gameBoard.setBoard(choice - 1) = X;
				break;
			case 6:
				gameBoard.setBoard(choice - 1) = X;
				break;
			case 7:
				gameBoard.setBoard(choice - 1) = X;
				break;
			case 8:
				gameBoard.setBoard(choice - 1) = X;
				break;
			case 9:
				gameBoard.setBoard(choice - 1) = X;
				break;
			}
			gameOverCheck(loop, gameBoard);
			if (loop)
				screenClear();
			gameBoard.displayBoard();

			// coping all the board values into a temporary test vector
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					test.push_back(gameBoard.at(i, j));
				}
			}

			/**
			 * @brief
			 * cell left and calulate the probabilityability at each step
			 * and then in the end make the best AImove possible
			 * A test vector is used for this purpose and then after testing
			 *changes are made to original boradGame vector
			 */
			min = RAND_MAX;
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (gameBoard.at(i, j) == _blank)
					{

						test.at((i * 3) + j) = O;
						net.feedForward(test);
						probability = net.getOutput();
						test.at((i * 3) + j) = _blank;
						//calculating the distance
						probability=abs(probability-O);

						if (min > probability)
						{
							min = probability;
							AImove = (i * 3) + j;
						}
					}
				}
			}

			gameOverCheck(loop, gameBoard);
			gameBoard.setBoard(AImove) = O;
			if (loop)
				screenClear();
		}
	}
}

/********Funtions********/

void screenClear()
{
	// Function to print 50 new empty lines to clear the scree/console
	for (int i = 0; i < 50; i++)
		std::cout << std::endl;
}
void gameOverCheck(bool &loop, TicTac gameBoard)
{
	// Checking for game win/loss/draw!

	if (gameBoard.evaluate() == X)
	{
		screenClear();
		gameBoard.displayBoard();
		std::cout << "X won the game\n";
		std::cout << "Do you want to play again?\n";
		loop = false;
	}
	else if (gameBoard.evaluate() == O)
	{
		screenClear();
		gameBoard.displayBoard();
		std::cout << "O won the game\n";
		std::cout << "Do you want to play again?\n";

		loop = false;
	}
	else if (gameBoard.draw())
	{
		screenClear();
		gameBoard.displayBoard();
		std::cout << "\n------Game DRAW!------\n";
		std::cout << "Do you want to play again?\n";

		loop = false;
	}
}
void menu()
{
	std::cout << "\n-------------------------------\n";
	std::cout << "    Please Selcect your Option	 \n";
	std::cout << "-------------------------------\n";
	std::cout << "1.Play game\n2.Quit\n";
}

/**
 * @brief
 * function to accept input in the specified range
 * choice->input to be checked
 * from  ->Start of range
 * to    ->end of range
 */
void validOption(int &input, int from, int to)
{
	while (input < from || input > to)
	{
		std::cout << "Please enter valid option form " << from << " to " << to << " : ";
		std::cin >> input;
	}
}