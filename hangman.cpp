#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <ctime>
#include <ctype.h>
#include "graphics.h"

#define WORDS_NUM 7717

using namespace std;

vector<int> findLocations(string, char);

int main()
{
    // Loading the words file
    ifstream words("words.txt");
    string wordsArray[WORDS_NUM];
    int allowedErrorsNum = sizeof(printPhases) / sizeof(printPhases[0]);

    if (words.is_open())
    {
            for (int i = 0; i < WORDS_NUM; i++)
            {
                    getline(words, wordsArray[i]);
            }
            words.close();
    }
    else
    {
            cout << "Problem opening the words input file" << endl;
            return 0;
    }

    string letters = "abcdefghijklmnopqrstuvwxyz";
    string toContinue = "yes";

    do
    {

        string guess;
        string usedLetters = "";
        string toFind;
        string toPrint;
        int errorState = 0;
        bool success = true;


        // Get a random word
        srand(time(NULL));
        int r = rand() % WORDS_NUM;
        toFind = wordsArray[r];
        printPhases[errorState]();
        // print word state
        size_t toFindLength = toFind.length();
        string currentFind(toFindLength, '_');
        cout << currentFind << endl << endl;

        while (currentFind != toFind)
        {

            // Ask for guess
            while (true)
            {
                cout << "enter guess: ";
                cin >> guess;
                // lowercase the string
                string tmp;
                for (char& c: guess)
                {
                    char i = tolower(c);
                    tmp += i;
                }
                guess = tmp;

                if ((guess.length() == 1) && (letters.find(guess) != string::npos))
                {
                    break;
                }
                cout << "Wrong input, ";
            }

            // if it's been checked before continue
            if (usedLetters.find(guess) != string::npos)
            {
                cout << "You've already tried this.." << endl;
                continue;
            }

            // add it to the used letters
            usedLetters += guess;
            // get indexes for the found letters
            char guessChar = guess[0];
            vector<int> places = findLocations(toFind, guessChar);
            // if the letter is not found in the word
            if (places.size() == 0)
            {
                errorState++;
                printPhases[errorState]();
                cout << "Already tried letters: " << usedLetters << endl;
                cout << currentFind << endl << endl;
                // if more mistakes than allowedErrorsNum
                if (errorState == allowedErrorsNum - 1)
                {
                    success = false;
                    break;
                }
                continue;
            }
            // fill the new letters to the word to show
            for (int i: places)
            {
                currentFind[i] = guessChar;
            }
            // show output
            printPhases[errorState]();
            cout << "Already tried letters: " << usedLetters << endl;
            cout << currentFind << endl << endl;

        }
        if (success == false)
        {
            cout << "You lost.." << endl;
            cout << "The word was " << toFind << endl;
        }
        else
        {
            cout << "Congratulations! You won!" << endl;
        }

        cout << "Do you want to play again? ('yes' or 'y' to continue)" << endl;
        cin >> toContinue;

    } while ((toContinue == "yes") || (toContinue == "y"));

    return 0;
}

vector<int> findLocations(string sample, char findIt)
{
    vector<int> characterLocations;
    for(int i =0; i < sample.size(); i++)
        if(sample[i] == findIt)
            characterLocations.push_back(i);

    return characterLocations;
}
