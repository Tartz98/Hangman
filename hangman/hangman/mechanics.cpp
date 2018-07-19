#include <vector>
#include <string>
#include <iostream>


namespace hangman {

	void Comparison(std::string realWord, char guess, std::vector<char> &charArray, int &wrongCount) {
		int correct = 0;
		std::vector<int> locations(realWord.length());
		std::string spaces;

		for (unsigned int i = 0; i < realWord.length(); i++) {
			if (guess == realWord[i]) {
				correct += 1;
				locations[i] = 1;
				std::cout << "in";
			}
			else {
				locations[i] = 0;
			}
			
		}

		if (correct == 0) {
			wrongCount = wrongCount + 1;
		}
		else {
			std::cout << "\"" << guess << "\" was a correct guess!";
		}

		for (unsigned int i = 0; i < locations.size(); i++) {
			if (locations[i] == 1) {
				charArray[i] = guess;
			}
			else {
				locations[i] = '_';
			}
		}
	}

	void Gallow(int wrongCount) {
		switch (wrongCount)
		{
		case 0: std::cout << "    __________\n";
				std::cout << "    |         |\n";
				std::cout << "    |          \n";
				std::cout << "    |          \n";
				std::cout << "    |          \n";
				std::cout << "    |          \n";
				std::cout << "    |          \n";
			break;
		case 1:	std::cout << "    __________\n";
				std::cout << "    |         |\n";
				std::cout << "    |         O\n";
				std::cout << "    |          \n";
				std::cout << "    |          \n";
				std::cout << "    |          \n";
				std::cout << "    |          \n";
			break;
		case 2:	std::cout << "    __________\n";
				std::cout << "    |         |\n";
				std::cout << "    |         O\n";
				std::cout << "    |         |\n";
				std::cout << "    |          \n";
				std::cout << "    |          \n";
				std::cout << "    |          \n";
			break;
		case 3:	std::cout << "    __________\n";
				std::cout << "    |         |\n";
				std::cout << "    |         O\n";
				std::cout << "    |        /|\n";
				std::cout << "    |          \n";
				std::cout << "    |          \n";
				std::cout << "    |          \n";
			break;
		case 4:	std::cout << "    __________\n";
				std::cout << "    |         |\n";
				std::cout << "    |         O\n";
				std::cout << "    |        /|\\\n";
				std::cout << "    |          \n";
				std::cout << "    |          \n";
				std::cout << "    |          \n";
			break;
		case 5:	std::cout << "    __________\n";
				std::cout << "    |         |\n";
				std::cout << "    |         O\n";
				std::cout << "    |        /|\\\n";
				std::cout << "    |        / \n";
				std::cout << "    |          \n";
				std::cout << "    |          \n";
			break;
		case 6:	std::cout << "    __________\n";
				std::cout << "    |         |\n";
				std::cout << "    |         O\n";
				std::cout << "    |        /|\\\n";
				std::cout << "    |        / \\\n";
				std::cout << "    |          \n";
				std::cout << "    |          \n";
			break;
		default: std::cout << "There has been an error. Contact the dude who made this.";
		}
	}

	std::string spaces(std::string realWord) {
		std::string realSpaces;
		for (unsigned int i = 0; i < realWord.length(); i++) {
			realSpaces += "_";
		}
		return realSpaces;
			
	}
}

int main() {
	bool inGame = 0;
	char guess;
	/*temporary word*/ std::string realWord = "string";
	int wrongCount = 0;
	int compareCount;
	std::string again;
	std::vector<char> charArray(realWord.size());
	for (unsigned int i = 0; i < realWord.length(); i++) {
		charArray[i] = '_';
	}



	while (inGame == 0) {

		std::cout << "Enter a letter: ";
		for (unsigned int i = 0; i < charArray.size(); i++) {
			std::cout << charArray[i];
		}
		std::cout << ":  ";

		std::cin >> guess;
		std::cout << std::endl;
		compareCount = wrongCount;
		hangman::Comparison(realWord, guess, charArray, wrongCount);

		if (wrongCount == compareCount) {
			int count = 0;
			std::cout << "Correct!\n\n\n\n";
			hangman::Gallow(wrongCount);
			for (unsigned int i = 0; i < realWord.length(); i++) {
				if (charArray[i] == '_')
				{
					count += 1;
				}
			}
			if (count < 1) {
				std::cout << "You WIN!!!\n\n\n";
				inGame = 1;
			}
		}

		else {
			std::cout << "WRONG! YOU HAVE BEEN PENALIZED!" << std::endl << std::endl;
			hangman::Gallow(wrongCount);

			if (wrongCount == 6) {	
				std::cout << "YOU LOSE! TRY AGAIN NEXT TIME!";
				inGame = 1;
			}
		}
		if (inGame == 1) {
			std::cout << std::endl << std::endl << "Would you like to play again? y/n:  ";
			std::cin >> again;
			while (again != "y" && again != "n") {
				std::cout << std::endl << "You have entered an invalid option. Please try again: " << std::endl;
				std::cin >> again;
			}
			if (again == "y") {
				inGame = 0;
				wrongCount = 0;
				compareCount = 0;
				//random word = something new
				std::cout << std::endl << std::endl << std::endl;
			}
			else {
				std::cout << std::endl << "Bye.";
			}

		}
	}

	return 0;
}