#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;
#ifndef CARD_H
#define CARD_H
struct Card{
    //Card struct attributes 
    string rank;//rank of a Card 
    string suit;//suit of a Card
    int value = 1;//integer value of rank
    
    //Functions
    
  
    //override < operator
    bool operator<(const Card& other) const {
           return value < other.value;//returns Card Value
       }
    //override() operator
    size_t operator()(const Card& obj) const {
            return std::hash<int>()(obj.value);//returns Card Value
        }
    //override == operator
        bool operator==(const Card& other) const {
            return value == other.value;
        }
        //returns value of Card
    int getIntValue() const {
            return value;
        }
   
};


struct CardHashs {
    std::size_t operator()(const Card& card) const {
        return std::hash<int>()(card.getIntValue());
    }
};
#endif /* CARD_H */

