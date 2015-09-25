/* 
 * File:   GeneticAlgorithm.cpp
 * Author: perfectmak
 * 
 * Created on September 24, 2015, 10:49 PM
 */
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <functional>

#include "GeneticAlgorithm.h"
#include "Individual.h"
#include "Random.h"

Individual* GeneticAlgorithm::compute(Population& population, int generations)
{
    int currentGeneration = 1;
    int populationSize = population.size();
    log("Population Size:"+std::to_string(populationSize));
    
    while(currentGeneration <= generations)
    {
        log("\n======Generation "+std::to_string(currentGeneration)+" Begin======\n");
        
        std::vector<IndividualFitness> individualFitMap;        
        float totalFitValue = 0.0;
        //compute their fitness
        for(int i =0; i < populationSize; i++)
        {
            float fitValue = population[i]->fitness();            
            
            assert((fitValue >= 0.0) && (fitValue <= 1.0)); //ensures that fitValue is with 0 and 1
            
            if(fitValue == 1.0) //we have a solution
                return population[i];
            
            totalFitValue += fitValue;
            
//            log("Fitness value is: "+std::to_string(fitValue));
            
            individualFitMap.push_back(std::make_pair(fitValue, population[i]));
        }
        
        //sort fit map based on fitness in descending order
        std::sort(individualFitMap.begin(), individualFitMap.end(),
                [](IndividualFitness a, IndividualFitness b){
                    return (a.first > b.first);
                });
        
        //probabilities
        std::vector<float> individualProbability(populationSize);
        int j = 0;
        for(auto &individualFitness : individualFitMap){
            individualProbability[j] = individualFitness.first/totalFitValue;
            j++;
        };
        
        
        
        //status of currentPopulation
        j= 0;
        for(auto individualMap : individualFitMap)
        {
            log("Fitness: "+std::to_string(individualMap.first));
            log("Individual: "+individualMap.second->description());
            log("Probability: "+std::to_string(individualProbability[j]));
            log("");
            j++;
        }
        
        //reproduction cycle for next generation
        Population nextGen;
        std::vector<IndividualFitness>::iterator mapBegin = individualFitMap.begin();
        while(nextGen.size() != populationSize)
        {
            auto parentAPos = pickParent(individualProbability);
            log("Parent A Pos "+std::to_string(parentAPos));
            Individual* parentA = std::next(mapBegin, parentAPos)->second;
            
            auto parentBPos = pickParent(individualProbability);
            log("Parent B Pos "+std::to_string(parentBPos));
            Individual* parentB = std::next(mapBegin, parentBPos)->second;
//            
//            //push offspring into nextGen list
            Individual* offspring = parentA->reproduce(parentB);
//            
//            //conditionally mutate child in probability >= 0.6
            float mutateProbability = Random::generate(0.0f,1.0f);
            if(mutateProbability >= 0.6)
            {
                offspring->mutate();
            }
          
            if(offspring->fitness() == FITNESS_MAX)
            {
                //this offspring is the strongest of them all :D
                return offspring;
            }
            nextGen.push_back(offspring);
        }
        
        population = nextGen;

        log("\n======Generation "+std::to_string(currentGeneration)+" End======\n");
        //next generation
        currentGeneration++;
    }
    
    //no result found
    return nullptr;
}

/**
 * Randomly pick a parent based on the probability list.
 * Using Fitness Proportionate Selection.
 * 
 * @todo Ensure that higher probability is favoured
 * @param probabilties
 * @return 
 */
PointerPosition GeneticAlgorithm::pickParent(std::vector<float> probabilities)
{
    float randomValue = Random::generate(0.0f, 1.0f);
    std::vector<float>::iterator pos = std::find_if(probabilities.begin(),
            probabilities.end(), [randomValue](float value){
                if(randomValue >= value)
                    return true;
                else
                    return false;
            });

    if(pos == probabilities.end()) //to ensure that a value is chosen
    {
        return pickParent(probabilities);
    }
    else
        return std::distance(probabilities.begin(), pos);
}

void GeneticAlgorithm::log(std::string log)
{
#ifdef GA_DEBUG
    std::cout << log << std::endl;
#endif
}