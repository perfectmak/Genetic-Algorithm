/* 
 * File:   BookArrangement.cpp
 * Author: perfectmak
 * 
 * Created on September 25, 2015, 2:09 AM
 */
#include <cassert>
#include <algorithm>
#include <iostream>

#include "../../src/Random.h"
#include "BookArrangement.h"

/**
 * @param arrangements : Arrangements of books based on their size
 */
BookArrangement::BookArrangement(std::vector<Book*> arrangements) : _arrangements(arrangements)
{
    assert(_arrangements.size() == 5); //ensure that not more than five books are used --- really trivial
}

/**
 * Calculates the fitness based on the amount of books in order
 */
float BookArrangement::fitness()
{
    unsigned int booksSize = _arrangements.size();
    unsigned int booksOutOfOrder = 0;
    for(int i = 0; i < booksSize-1; i++)
    {
        //book in front is smaller
        if(_arrangements[i+1]->_height < _arrangements[i]->_height)
        {
            booksOutOfOrder++;
        }
    }
    
    return (booksSize-booksOutOfOrder)/(float)booksSize;
}

/**
 * This method creates an offspring from the partner argument.
 * 
 * It does this by taking the first three books of this object and merges it with
 * remaining two books of the partner object while keeping their relative position
 * 
 * Note: this reproduce ensures that the set of books are maintained
 * 
 * @param partner : Partner this book will reproduce with
 * @return 
 */
Individual* BookArrangement::reproduce(Individual* partner)
{
    std::string logOutput = "";
    
    BookArrangement* partnerArrangement = static_cast<BookArrangement*>(partner);
    
    logOutput += this->description() + "(" + std::to_string(this->fitness()) + ")"
            + " + " + partnerArrangement->description() + "(" 
            + std::to_string(partnerArrangement->fitness()) + ")" 
            + " = ";
    
    std::vector<Book*>::iterator thisBeginIter = this->_arrangements.begin();
    
    std::vector<Book*> newBooks(thisBeginIter, thisBeginIter+3);
    
    for(auto i : partnerArrangement->_arrangements)
    {
        auto result =  std::find_if(newBooks.begin(), newBooks.end(), [&i](Book* book){
            return book->_id == i->_id;
        });
        
        if(result == newBooks.end()) //not already in newBook
        {
            newBooks.push_back(i);
        }
    }
    BookArrangement* newBookArrangment = new BookArrangement(newBooks);
    
    logOutput += newBookArrangment->description() + "(" 
            + std::to_string(newBookArrangment->fitness()) + ")";
    
    std::cout << logOutput << std::endl;
    
    return newBookArrangment;
}
/**
 * This method mutates the current book arrangement by randomly swapping 1 adjacent book
 */
void BookArrangement::mutate()
{
    for(int i = 0; i < 1; i++)
    {
        int position = Random::generate(0, (this->_arrangements.size()-2));
        
        //swap book pointers
        Book* firstBook = this->_arrangements[position];
        this->_arrangements[position] = this->_arrangements[position+1];
        this->_arrangements[position+1] = firstBook;
        
        //log
        std::cout << "Swapped books at position " << position << " with position " << position+1 << std::endl;
        
    }
}

std::string BookArrangement::description()
{
    std::string response;
    for(auto i :_arrangements)
    {
        response += std::to_string(i->_height);
    }
    
    return response;
}