// File Name : SanJose_PA5.cpp
// Author : John Cris San Jose
// Email Address : jcsanjose@gbox.adnu.edu.ph
// ProgAss Number : 5
// Description : A Rolling Dice Guessing Game
// Last Changed :  December 5, 2023 || 12:12 pm

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <conio.h>

void Dices(int& die1, int& die2, int& die3);
void Result(int gwes, int rwesult, int* mwoney, int* bwet);

int main()
{
    /*choice!*/
    int Choice;
    /*for dices value*/
    int dice1 = 0, dice2 = 0, dice3 = 0;
    /*MONEY!*/
    int money = 100, bet = 0;
    /*guess*/
    int guess = 0;
    /*Condition for the loop*/
    bool exit = true;
    /*Result*/
    int RESULT = 0;

    srand((unsigned int)time(NULL));
    
    while (exit)
    {
        std::cout << "Your Money: " << money << "\n";

        if (money <= 0)
        {
            std::cout << "You do not have sufficient funds... Try Again Laturr. :(\n";
            exit = false;
            break;
        }
        std::cout << "(1) Place Bet\n";
        std::cout << "(2) Exit\n";

        Choice = _getch() - '0';
        
        switch (Choice)
        {
        case 1:            
            std::cout << "Place your bet: ";
            std::cin >> bet;

            if (bet <= 0 || bet > money)
            {
                std::cout << "Place a valid bet.\n";
            }
            else
            {
                std::cout << "Guess Sum: ";
                std::cin >> guess;
                std::cout << "Rolling Dice...\n";
                Dices(dice1, dice2, dice3);
                std::cout << "Die 1 = " << dice1 << "\n";
                std::cout << "Die 2 = " << dice2 << "\n";
                std::cout << "Die 3 = " << dice3 << "\n";
                RESULT = dice1 + dice2 + dice3;
                Result(guess, RESULT, &money, &bet);
            }
            break;
        case 2:
            std::cout << "Exiting...\n";
            exit = false;
        default:
            break;
        }

    }
    
}
/*Rolling Dice funtion*/
void Dices(int& die1, int& die2, int& die3)
{
    die1 = (rand() % 6) + 1;
    die2 = (rand() % 6) + 1;
    die3 = (rand() % 6) + 1;
}
/*Showing Result Function*/
void Result(int gwes, int rwesult, int* mwoney, int* bwet)
{
    if(gwes == rwesult)
    {//sir siunod ko lang po yung +888 sa sample dialouge hindi ko po alam kung by times 10 po ba talaga or +888, sample dialouge nalang po ko nagbase.
        //adds 888 to bet and adds to money
        *mwoney += *bwet + 888;
        std::cout << "You are Lucky!\n";
    }
    //this only adds the bet to money if he guessed off by 2
    else if (gwes == (rwesult - 2) || gwes == (rwesult + 2))
    {
        *mwoney += *bwet;
        std::cout << "Good!\n";
    }
    //this multiplies the bet and adds to moneyif he guessed off by 1
    else if (gwes == (rwesult - 1) || gwes == (rwesult + 1))
    {
        *mwoney += *bwet *2;
        std::cout << "Very Good!\n";
    }
    //si bro ay na talo || he guessed wrong
    else
    {
        *mwoney -= *bwet;
        std::cout << "Oops!\n";
    }

}