//Libraries and files used
#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <map>
#include <thread>
#include <iomanip>
#include <cstdlib>
#include "DeckofCards.h"
#include "GameBoard.h"
#include "DeckTree.h"
using namespace std;

int main(int argc, char** argv) {
    //declare or make variables needed  
    string choice = "0";
    DeckofCards Hand;//object of DeckofCards Declared
    
    Hand.MakeDeck();//Hand object is initialized to make standard deck of cards 
    Hand.SortDeck();// Hand is Sorted
    Hand.ShuffleDeck();//Hand is shuffled
    Hand.SortDeck();// Hand is Sorted
    GameBoard g(Hand);//GameBoard object initialized and given Hand object as parameter
    //GameBoard is giving the deck of cards created and shuffled
    
    g.makeBoard(Hand.deck);//GameBoard object g will make the board
    //it will use a function that takes in an array of Card objects since 
    //it has not split the entire deck of in smaller decks
    
    //GameBoard will create all the  5 decks used for the game the user deck and the stock
    g.createDecks();
    cout << endl << endl;//add black spaces of lines
    
    
    
    // Assuming card2.deck is your array of card values
//    std::list<Card> cardValues;
//    // ... Populate cardValues with Card structs ...
//    cardValues = g.deck1;
//    DeckTree deck1Tree(cardValues);
//    // Create a tree for the deck
//  
//
//    // Example usage to validate the top card's value
//    int userProvidedValue =g.userdeck.front().value ; // Replace this with the user's input
//    if (deck1Tree.validateTopCardValue(userProvidedValue)) {
//        std::cout << "Top card's value is valid. Valid value: " << userProvidedValue << std::endl;
//    } else {
//        std::cout << "Top card's value is not valid for the specified range." << std::endl;
//    }
    
    
    
    
    
    
    //while loop to initialize main menu
    while(choice!="1"){//Keeps the menu open until user chooses option 1
        
        g.mainMenu(choice);//Main menu, start, rules and quit
        if(choice =="4"){//if they choose to quit
            return 0;
        }
   }
    
    if(choice == "1"){//if the user chose to start
        while(true){//the game will now initialize and loop till finished
            
            
            g.makeBoard();//first the game will display the board
            
            //then it will either check if the game has been won or lost
            if(g.checkLossCondition()){
                g.gameOverMenu();//game over menu displays
                return 0;//ends program
            }
            if( g.checkWinCondition()){
                g.wonMenu();//won over menu displays
                return 0;//ends program
            }
            //if neither a won or loss condition is meet the game continues
            
            //if the user is getting close to the game this condition will run
            if(g.stock.size()<10&&!g.ap[7]){
                //the following function is there to aid the user in finishing the game
                //it gives the user two tries at seeing what cards they have left in their stock
                //only happens two times
                cout << "you are getting close to the end of your stockpile\nthis is just a little help to aid in finishing the game"<<endl;
                cout << "This help will pop up for two turns only\n";
                g.createSet();
                cout << endl;
            }//other than if conditions are met, if statement ignored for most of the game
            
            
            g.AskUser();//Asks the user how they want to move their cards
            g.PopfromStack();//updates the decks based on user input
            //loop continues updating the GameBoard visualizing the user input
        }
     }
    else{//ends game 
        return 0;
    }
    
    
    
    
    
    
}

