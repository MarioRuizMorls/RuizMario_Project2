#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include "Card.h"
#include "CardValues.h"
#include "DeckofCards.h"
#include "Graph.h"
#include <stdio.h>
#include <stack>
#include <list>
#include <thread>
#include <algorithm>
#include <unordered_set>
#include <map>
#include <iomanip>
#include <queue>
#include <stack>
//libraries


class GameBoard{//class GameBoard
private:
public:
    //all the variables used
    queue<int> q;
    int six;
    DeckofCards card2;
    
    map<string, string> sp;//map to store the card design
    map<int, string> rp;// map to store the card design
    map<int, bool> ap;//map to keep track of empty decks 
    list<Card> deck1;//list for all the decks used
    list<Card> deck2;
    list<Card> deck3;
    list<Card> deck4;
    list<Card> deck5;
    list<Card> stock;
    list<Card> userdeck;
    stack<Card> ddeck;// stack for the stock pile used 
    GameBoard();//Default Constructor
    GameBoard(DeckofCards);//One parameter Constructor
    //GameBoard Functions
    void mainMenu(string &);
    void makeBoard(Card deck[]);
    void gameOverMenu();
    void makeBoard();
    void createDecks();
    void PopfromStack();
    void PopfromStack2();
    void AskUser();
    bool notValidMove(Card *end,list<Card>stack);
    bool isValid(string &,int, int);
    bool checkLossCondition();
    bool checkWinCondition();
    void wonMenu();
    void createSet();
    void seeAdjancacy();
};
#endif /* GAMEBOARD_H */

