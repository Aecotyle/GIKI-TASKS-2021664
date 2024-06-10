#include "NueralNetwork.cpp"
#include "ticTacToe.h"


void train(Network &net)
{

	/*Network instance-net is passed by reference to ensure that
	original network also trains*/

	/*reading test data from file and saving it in data
	and target vector with the help of string stream(delimiter)
	funtion*/
	std::vector<std::vector<double> > data;
	std::vector<std::vector<double> > targetValues;
	std::vector<double> target(1);
	std::ifstream file("tic-tac-toe.txt");
	if (file.is_open())
	{
		std::string s;
		while (std::getline(file, s))
		{
			std::vector<double> v;
			std::stringstream stream(s);
			std::string x;
			while (getline(stream, x, ','))
			{

				if (x == "x")
					v.push_back(X);
				else if (x == "o")
					v.push_back(O);
				else if (x == "b")
					v.push_back(_blank);
				else if (x == "positive")
					target.front() = X;
				else if (x == "negative")
					target.front() = O;
			}
			targetValues.push_back(target);
			data.push_back(v);
		}
	}
	else
		std::cout << "Unable to open the file\n";

	std::vector<double> res;

	// vector to display flickering animation effect on console
	std::vector<std::string> trainingFlickering;
	trainingFlickering.push_back("Training^*****");
	trainingFlickering.push_back("Training*^****");
	trainingFlickering.push_back("Training**^***");
	trainingFlickering.push_back("Training***^**");
	trainingFlickering.push_back("Training****^*");
	trainingFlickering.push_back("Training*****^");
	trainingFlickering.push_back("Training*****^");
	trainingFlickering.push_back("Training****^*");
	trainingFlickering.push_back("Training***^**");
	trainingFlickering.push_back("Training**^***");
	trainingFlickering.push_back("Training*^****");
	trainingFlickering.push_back("Training^*****");

	// running feedforward and back propogate on dataset to train the network
	for (int i = 0; i < data.size(); i++)
	{

		net.feedForward(data.at(i));
		net.backPropogate(targetValues.at(i));
		data[i].push_back(target.front());
		std::cout << trainingFlickering.at(i % trainingFlickering.size()) << std::endl;
	}

	std::cout << "\n------Training complete------\n";
}