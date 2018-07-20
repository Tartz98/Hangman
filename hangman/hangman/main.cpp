#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>

namespace hangman {

	void Comparison(std::string realWord, char guess, std::vector<char> &charArray, int &wrongCount, std::vector<char> &wrongs) { //function to be used to compare the user guess
		int correct = 0;											//amount of times a guess is correct					      //to the word itself
		std::vector<int> locations(realWord.length());											//a vector to store the order that correct guesses have been made, and replace the unguessed ones with blanks

		for (unsigned int i = 0; i < realWord.length(); i++) {
			if (guess == realWord[i]) {
				correct += 1;									//checks to see if the guess matches anywhere in the word by looping through each char of the string and marks the location
				locations[i] = 1;

			}
			else {
				locations[i] = 0;								//marks the location where it's wrong
			}

		}

		if (correct == 0) {
			wrongCount = wrongCount + 1;
			wrongs.push_back(guess);							//a vector that stores the wrong guesses so the user can see
		}
		else {
			std::cout << "\"" << guess << "\" was a correct guess!\n\n";
		}

		for (unsigned int i = 0; i < locations.size(); i++) {
			if (locations[i] == 1) {
				charArray[i] = guess;							//puts in correct guesses where they belong, and leaves the other spots blank
			}
			else {
				locations[i] = '_';
			}
		}
	}

	void Gallow(int wrongCount, std::vector<char> wrongs) {			//a switch function that prints out the correct hangman graphic based on the amount of wrong guesses
		switch (wrongCount)
		{
		case 0: std::cout << "    __________\n";
				std::cout << "    |         |\n";
				std::cout << "    |          \n";
				std::cout << "    |          \n";
				std::cout << "    |          \n";
				std::cout << "    |          \n";
				std::cout << "    |          \n\n\n";
				for (unsigned int i = 0; i < wrongs.size(); i++) {
					if (i == wrongs.size() - 1) {
						std::cout << wrongs[i] << "\n\n\n";				//a loop to print out the user's wrong guesses and format it correctly
					}
					else {
						std::cout << wrongs[i] << ", ";
					}
				}
			break;
		case 1:	std::cout << "    __________\n";
				std::cout << "    |         |\n";
				std::cout << "    |         O\n";
				std::cout << "    |          \n";
				std::cout << "    |          \n";
				std::cout << "    |          \n";
				std::cout << "    |          \n\n\n";
				for (unsigned int i = 0; i < wrongs.size(); i++) {
					if (i == wrongs.size() - 1) {
						std::cout << wrongs[i] << "\n\n\n";
					}
					else {
						std::cout << wrongs[i] << ", ";
					}
				}
			break;
		case 2:	std::cout << "    __________\n";
				std::cout << "    |         |\n";
				std::cout << "    |         O\n";
				std::cout << "    |         |\n";
				std::cout << "    |          \n";
				std::cout << "    |          \n";
				std::cout << "    |          \n\n\n";
				for (unsigned int i = 0; i < wrongs.size(); i++) {
					if (i == wrongs.size() - 1) {
						std::cout << wrongs[i] << "\n\n\n";
					}
					else {
						std::cout << wrongs[i] << ", ";
					}
				}
			break;
		case 3:	std::cout << "    __________\n";
				std::cout << "    |         |\n";
				std::cout << "    |         O\n";
				std::cout << "    |        /|\n";
				std::cout << "    |          \n";
				std::cout << "    |          \n";
				std::cout << "    |          \n\n\n";
				for (unsigned int i = 0; i < wrongs.size(); i++) {
					if (i == wrongs.size() - 1) {
						std::cout << wrongs[i] << "\n\n\n";
					}
					else {
						std::cout << wrongs[i] << ", ";
					}
				}
			break;
		case 4:	std::cout << "    __________\n";
				std::cout << "    |         |\n";
				std::cout << "    |         O\n";
				std::cout << "    |        /|\\\n";
				std::cout << "    |          \n";
				std::cout << "    |          \n";
				std::cout << "    |          \n\n\n";
				for (unsigned int i = 0; i < wrongs.size(); i++) {
					if (i == wrongs.size() - 1) {
						std::cout << wrongs[i] << "\n\n\n";
					}
					else {
						std::cout << wrongs[i] << ", ";
					}
				}
			break;
		case 5:	std::cout << "    __________\n";
				std::cout << "    |         |\n";
				std::cout << "    |         O\n";
				std::cout << "    |        /|\\\n";
				std::cout << "    |        / \n";
				std::cout << "    |          \n";
				std::cout << "    |          \n\n\n";
				for (unsigned int i = 0; i < wrongs.size(); i++) {
					if (i == wrongs.size() - 1) {
						std::cout << wrongs[i] << "\n\n\n";
					}
					else {
						std::cout << wrongs[i] << ", ";
					}
				}
			break;
		case 6:	std::cout << "    __________\n";
				std::cout << "    |         |\n";
				std::cout << "    |         O\n";
				std::cout << "    |        /|\\\n";
				std::cout << "    |        / \\\n";
				std::cout << "    |          \n";
				std::cout << "    |          \n\n\n";
				for (unsigned int i = 0; i < wrongs.size(); i++) {
					if (i == wrongs.size() - 1) {
						std::cout << wrongs[i] << "\n\n\n";
					}
					else {
						std::cout << wrongs[i] << ", ";
					}
				}
			break;
		default: std::cout << "There has been an error. Contact the dude who made this.";
		}
	}

	std::string Random_Word() {				//a function to generate a random number to place in a vector to choose a random word.
		std::vector<std::string> words_list; words_list.push_back("word"); words_list.push_back("random"); words_list.push_back("laptop");
		int vector_size = words_list.size();
		int numbo = rand() % vector_size;
		return words_list[numbo];
	}

}

//---------------------------------------------------------------------------------------------------

int main() {
	bool endGame = 0;		//detects if the user is at the end of the game. 0 for no, 1 for yes.
	char guess;				//the user's guess
	std::string realWord = hangman::Random_Word();		//word randomly generated from a preset list of words for the game
	int wrongCount = 0;								//a count of the wrong guesses
	int compareCount;							//a way to compare if the wrong guesses has increased
	std::string again;							//for later use if user input is invalid
	std::vector<char> charArray(realWord.size());			//the vector that will be used to print out blanks/correct guesses
	std::vector<char> wrongs;								//vector list of all the wrong guesses

	for (unsigned int i = 0; i < realWord.length(); i++) {
		charArray[i] = '_';										//initializing the charArray with all blanks to start the game
	}



	while (endGame == 0) {							//while in the middle of the game, keep looping

		std::cout << "Enter a letter: ";

		for (unsigned int i = 0; i < charArray.size(); i++) {
			std::cout << charArray[i];								//printing the blanks/what is correct
		}
		std::cout << ":  ";

		std::cin >> guess;							//user input
		std::cout << "\n";											//adding spaces to clean it up
		compareCount = wrongCount;												//will later be compared to detect if another wrong answer has been made
		hangman::Comparison(realWord, guess, charArray, wrongCount, wrongs);			//calling the compare function for the guess to the word

		if (wrongCount == compareCount) {
			int count = 0;
			hangman::Gallow(wrongCount, wrongs);

			for (unsigned int i = 0; i < realWord.length(); i++) {
				if (charArray[i] == '_')
				{
					count += 1;				//counts amount of blanks left
				}
			}

			if (count < 1) {						//when blanks are 0, you win
				std::cout << "You WIN!!!\n\n\n";
				endGame = 1;	
			}
		}

		else {
			std::cout << "WRONG! YOU HAVE BEEN PENALIZED!" << std::endl << std::endl;	//prints the new hangman board if a wrong letter has been guessed
			hangman::Gallow(wrongCount, wrongs);

			if (wrongCount == 6) {										//if you run out of limbs to use, you lose
				std::cout << "YOU LOSE! TRY AGAIN NEXT TIME!";
				endGame = 1;
			}
		}

		if (endGame == 1) {
			std::cout << std::endl << std::endl << "Would you like to play again? y/n:  ";		//obviously, if you want to play again, you will.
			std::cin >> again;

			while (again != "y" && again != "n") {		//if an invalid answer is detected, try again
				std::cout << std::endl << "You have entered an invalid option. Please try again: " << std::endl;
				std::cin >> again;
			}

			if (again == "y") {
				endGame = 0;
				wrongCount = 0;							//Resetting the game
				compareCount = 0;
				realWord = hangman::Random_Word();

				wrongs.clear();						//Clearing vectors to reset
				charArray.clear();	
				for (unsigned int i = 0; i < realWord.length(); i++) {		//Inserting the proper amount of spaces of the random word
					charArray.push_back('_');
				}
				std::cout << "\n\n\n";				//Giving enough space to clean it up
			}
		}
	}

	return 0;
}