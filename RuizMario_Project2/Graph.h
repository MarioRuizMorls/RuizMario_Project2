/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Graph.h
 * Author: marioruiz
 *
 * Created on December 17, 2023, 4:54 PM
 */
#include "DeckofCards.h"
#include "Card.h"
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
#ifndef GRAPH_H
#define GRAPH_H




class Graph {
private:
    std::unordered_map<Card, std::list<Card>, CardHashs> adjacencyList;

public:
    void addEdge(const Card& card1, const Card& card2) {
        adjacencyList[card1].push_back(card2);
        adjacencyList[card2].push_back(card1);
    }

    void printGraph() {
        for (const auto& entry : adjacencyList) {
            std::cout << "Card " << entry.first.rank << " of " << entry.first.suit << " (" << entry.first.value << ") is adjacent to: ";
            for (const auto& neighbor : entry.second) {
                std::cout << neighbor.rank << " of " << neighbor.suit << " (" << neighbor.value << ") "<<endl;
            }
            std::cout << std::endl;
        }
    }
};

#endif /* GRAPH_H */

