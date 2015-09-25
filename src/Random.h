/* 
 * File:   Random.h
 * Author: perfectmak
 *
 * Created on September 25, 2015, 9:31 AM
 */

#include <random>

#ifndef RANDOM_H
#define	RANDOM_H

class Random 
{

    template<class T>
    static T generate(T min, T max) 
    {
        
    }
    
public:
    static int generate(int min, int max)
    {
        std::random_device rd;
        std::mt19937 e2(rd());

        std::uniform_int_distribution<int> dist(min, max);
        
        return dist(e2);
    }
    
    static float generate(float min, float max)
    {
        std::random_device rd;
        std::mt19937 e2(rd());

        std::uniform_real_distribution<float> dist(min, max);
        
        return dist(e2);
    }
};

#endif	/* RANDOM_H */

