/* 
 * File:   Book.h
 * Author: perfectmak
 *
 * Created on September 25, 2015, 3:10 AM
 */

#ifndef BOOK_H
#define	BOOK_H

#include <vector>

class Book {
public:
    Book(int id, int height);
    
    static std::vector<Book *>& fromHeightVector(std::vector<int>&);
    
    int _id;
    int _height;
};

#endif	/* BOOK_H */

