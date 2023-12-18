/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   DeckTree.h
 * Author: marioruiz
 *
 * Created on December 17, 2023, 5:19 PM
 */

#ifndef DECKTREE_H
#define DECKTREE_H
#include <stdio.h>
#include <iostream>
#include <list>
#include <stdexcept> // For std::invalid_argument
#include "DeckofCards.h"

// Define a basic node structure
struct CardNode {
    Card card;
    CardNode* left;
    CardNode* right;

    CardNode(const Card& c) : card(c), left(nullptr), right(nullptr) {}
};

// Define a tree class to manage the decks
class DeckTree {
private:
    CardNode* root;

    // Helper function to recursively build the tree
    CardNode* buildTree(std::list<Card>& cards) {
        if (cards.empty()) {
            return nullptr;
        }

        auto mid = std::next(cards.begin(), std::distance(cards.begin(), cards.end()) / 2);
        CardNode* newNode = new CardNode(*mid);
        cards.erase(mid);
        newNode->left = buildTree(cards);
        newNode->right = buildTree(cards);

        return newNode;
    }

    // Helper function to recursively check if the top card's value is valid
    bool isValidTopCardValue(CardNode* node, int userValue, int& validValue) const {
        if (node == nullptr) {
            return false;
        }

        // Check if the current node's value is one below or above the user-provided value
        if ((node->card.getIntValue() == 1) || (node->card.getIntValue() == 13))
        {
            if ((node->card.getIntValue() == userValue + 12) || (node->card.getIntValue() == userValue - 12))
            {
                validValue = node->card.getIntValue();
                return true;
            }
            
            
        }
        
        if ((node->card.getIntValue() == userValue - 1) || (node->card.getIntValue() == userValue + 1)) {
            validValue = node->card.getIntValue();
            return true;
        }
        
        // Recursively check the left and right subtrees
        if (isValidTopCardValue(node->left, userValue, validValue) ||
            isValidTopCardValue(node->right, userValue, validValue)) {
            return true;
        }

        return false;
    }

public:
    // Constructor
    DeckTree(std::list<Card>& cards) : root(nullptr) {
        // Assuming cards is already sorted based on Card's value attribute
        root = buildTree(cards);
    }

    // Function to get the root of the tree
    CardNode* getRoot() const {
        return root;
    }

    // Function to validate whether the top card's value is within the specified range
    bool validateTopCardValue(int userValue) const {
        int validValue = 0; // Placeholder for the valid value if found
        return isValidTopCardValue(root, userValue, validValue);
    }
};







#endif /* DECKTREE_H */

