#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#ifndef CARDVALUES_H
#define CARDVALUES_H
struct CardValues
{
    //struct of Card values to initialize a deck of Card objects
    string rankArry[13] = {"Ace", "Two", "Three", "Four", "Five" , "Six", "Seven", "Eight", "Nine", "Ten","Jack", "Queen", "King"};
    string SuitArry[4] = {"Clubs", "Spades", "Diamonds", "Hearts"};
    int valueArry[13]={1,2,3,4,5,6,7,8,9,10,11,12,13};
    //arrays that hold the rank, suits, and integer values of each card in a standard deck of cards
    
};
#endif /* CARDVALUES_H */

