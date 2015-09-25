/* 
 * File:   Individual.h
 * Author: perfectmak
 *
 * Created on September 24, 2015, 10:40 PM
 */

#include <string>

#ifndef INDIVIDUAL_H
#define	INDIVIDUAL_H

class Individual{
public:
    virtual std::string description(){return "Base Individual class :D";}
    
    /**
     * 
     * @return float : A value between 0 and 1 representing the fitness of the individual
     */
    virtual float fitness() = 0;
    virtual Individual* reproduce(Individual* partner) = 0;
    virtual void mutate() = 0;
    
};

#endif	/* INDIVIDUAL_H */

