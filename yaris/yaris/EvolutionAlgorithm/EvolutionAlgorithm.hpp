//
//  EvolutionAlgorithm.h
//  genetic-programming
//
//  Created by Michel Launier on 2021-08-24.
//

#ifndef EvolutionAlgorithm_h
#define EvolutionAlgorithm_h

#include <vector>

// Forward References
class AlgorithmConfig;
class EvolutionDelegate;
class Individual;
class EvolutionOperator;

class EvolutionAlgorithm {
    Individual*  bestIndividual; ///< The best individual of the run
    
    // Genetic Programming configuration
    EvolutionDelegate* delegate;
    
    const AlgorithmConfig*     algorithmConfig;
    
    typedef std::vector<EvolutionOperator*>  Operators;
    Operators myOperators;
    
    // Population related storage
    typedef std::vector< Individual* >   Population;
    Population* currentGeneration;
    Population* nextGeneration;
    Population  generationA;
    Population  generationB;

public:
    EvolutionAlgorithm(const AlgorithmConfig*, EvolutionDelegate*);
    ~EvolutionAlgorithm();
    
    Individual* run();
    
    void addOperator(EvolutionOperator*);

protected:
    void createInitialPopulation();
    Individual* evaluatePopulation();
    void evolvePopulation();
};

#endif /* EvolutionAlgorithm_h */
