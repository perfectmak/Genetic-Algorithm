/* 
 * File:   BookArrangement.h
 * Author: perfectmak
 *
 * Created on September 25, 2015, 2:09 AM
 */

#ifndef BOOKARRANGEMENT_H
#define	BOOKARRANGEMENT_H

#include <vector>
#include "Book.h"
#include "../../src/Individual.h"

class Book;

class BookArrangement : public Individual {
public:
    BookArrangement(std::vector<Book*> arrangements);
    virtual float fitness();
    virtual Individual* reproduce(Individual* partner);
    virtual void mutate();
    virtual std::string description();
private:
    std::vector<Book*> _arrangements;

};

#endif	/* BOOKARRANGEMENT_H */

