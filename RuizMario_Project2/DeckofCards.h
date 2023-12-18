
  
#include "Card.h"
#include "CardValues.h"
#include <random>
#include <algorithm>
#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H

struct DeckofCards{
    //Creates an object of CardValues
    CardValues print;
    //Creates an array object of Cards 
    Card deck[52];
    
    void MakeDeckRecursive(int col, int row) {
        if (col > 12 || row > 3) {
            return;  // Base case: stop recursion when all cards are assigned
        }

        deck[col + (row * 13)].rank = print.rankArry[col];
        deck[col + (row * 13)].suit = print.SuitArry[row];
        deck[col + (row * 13)].value = print.valueArry[col];

        // Recursively fill the next card
        MakeDeckRecursive(col + 1, row);

        // Move to the next row after completing a column
        if (col == 12) {
            MakeDeckRecursive(0, row + 1);
        }
    };

    void MakeDeck() {
        MakeDeckRecursive(0, 0);
    };
    //Prints the deck of Cards in four rows, each row corresponding to a suit
    void PrintDeck(){
        for(int col = 0; col <=12; col++)
        {
            for(int row = 0; row <=3; row++){
                
                cout << deck[(col+(row*13))].rank << " of " <<  deck[(col+(row*13))].suit << " "<< deck[(col+(row*13))].value<< ", ";
            }
            cout <<endl;
        }
    };
   
    //static function used to compare card values in order to sort deck
    static bool compare(Card a, Card b){
    return a.value > b.value;//if first card is higher in value returns true otherwise false
    
    //Shuffles the entire deck of Cards
    }
     void ShuffleDeck()
    {
        int seed = time(0);
        srand(seed);//creates true randomization
            shuffle(deck, deck+52,
                    default_random_engine(seed));
    }
     //sorts the entire deck in descending order 
    void merge(Card arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temporary arrays
    Card L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    // Merge the temporary arrays back into arr[l..r]
    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2) {
        if (compare(L[i], R[j])) { // Use the custom compare function
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
};

    // Recursive function to perform merge sort on arr[l..r]
    void mergeSort(Card arr[], int l, int r) {
        if (l < r) {
            // Same as (l+r)/2, but avoids overflow for large l and r
            int m = l + (r - l) / 2;

            // Sort first and second halves
            mergeSort(arr, l, m);
            mergeSort(arr, m + 1, r);

            // Merge the sorted halves
            merge(arr, l, m, r);
        }
    };

    // Modified SortDeck using Recursive Merge Sort
    void SortDeck() {
        int n = sizeof(deck) / sizeof(deck[0]);
        mergeSort(deck, 0, n - 1);
    };
};
#endif /* DECKOFCARDS_H */

