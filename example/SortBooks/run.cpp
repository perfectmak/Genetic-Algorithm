/* 
 * File:   run.cpp
 * Author: perfectmak
 * 
 * Created on September 25, 2015, 2:18 AM
 */
#include <iostream>
#define GA_DEBUG

#include "../../src/GeneticAlgorithm.h"
#include "BookArrangement.h"
#include "run.h"

using namespace std;

void run() {
    Population possibleArrangments;
    
    //intialize five books
    Book *book1 = new Book(1, 5);
    Book *book2 = new Book(2, 2);
    Book *book3 = new Book(3, 4);
    Book *book4 = new Book(4, 7);
    Book *book5 = new Book(5, 8);
    
    
    possibleArrangments.push_back(new BookArrangement({book1,book2,book3,book4,book5}));
    possibleArrangments.push_back(new BookArrangement({book2,book1,book5,book4,book3}));
    possibleArrangments.push_back(new BookArrangement({book4,book1,book3,book5,book2}));
    
    int generations = 5;
    
    BookArrangement* resultArrangement = 
            static_cast<BookArrangement*>(GeneticAlgorithm::compute(
                possibleArrangments));

    if(resultArrangement == nullptr)
    {
        cout << "No solution was found\n";
    }
    else
    {
        cout << "Solution found: Arrangement is " << resultArrangement->description() << endl;
    }
}
