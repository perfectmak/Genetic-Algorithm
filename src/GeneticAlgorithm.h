/* 
 * File:   GeneticAlgorithm.h
 * Author: perfectmak
 *
 * Created on September 24, 2015, 10:49 PM
 */

#ifndef GENETICALGORITHM_H
#define	GENETICALGORITHM_H

#define GA_DEBUG 1

#include <vector>
#include <string>
#include "Individual.h"
#include "Population.h"

typedef std::ptrdiff_t PointerPosition;
typedef std::pair<float, Individual*> IndividualFitness;

const float FITNESS_MIN = 0.0f;
const float FITNESS_MAX = 1.0f;

class GeneticAlgorithm {
public:    
    static Individual* compute(Population& population, int generations = 100);
    static PointerPosition pickParent(std::vector<float> probabilties);
    static void log(std::string);
};

#endif	/* GENETICALGORITHM_H */

