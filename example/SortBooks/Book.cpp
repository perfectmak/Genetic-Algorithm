/* 
 * File:   Book.cpp
 * Author: perfectmak
 * 
 * Created on September 25, 2015, 3:10 AM
 */

#include "Book.h"


Book::Book(int id, int height) : _id(id), _height(height)
{
}

std::vector<Book*>& fromHeightVector(std::vector<int>& bookHeights){
    unsigned int bookHeightsSize = bookHeights.size();
    
    std::vector<Book*> books(bookHeightsSize);
    
    for(unsigned int i = 0; i < bookHeightsSize; i++)
    {
        books[i] = new Book(i, bookHeights[i]);
    }
    
    return books;
}
