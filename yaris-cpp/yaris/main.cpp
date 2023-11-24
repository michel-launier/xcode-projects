//
//  main.cpp
//  yaris
//
//  Created by Michel Launier on 2021-09-26.
//

#include <iostream>

#include "Common/Heap.hpp"
#include "Common/NamedObject.hpp"

#include "EvolutionAlgorithm/Individual.hpp"
#include "EvolutionAlgorithm/EvolutionDelegate.hpp"
#include "EvolutionAlgorithm/AlgorithmConfig.hpp"
#include "EvolutionAlgorithm/EvolutionAlgorithm.hpp"


class TestIndividual : public Individual {
public:
    TestIndividual() { std::cout << "creating individual\n"; }
protected:
    void dipose() { std::cout << "disposing of individual\n"; delete this; }
};

class TestDelegate : public EvolutionDelegate {
    Individual*  createIndividual() const { return new TestIndividual; }
    void         releaseIndividual(Individual* i) { delete i; }
    float        evaluateIndividual(const Individual*) const { return 0.5f; }
    bool         isIndividualGoodEnough(const Individual* i) const { return i->fitnessScore > 0.95f; }
};

AlgorithmConfig testConfig(10,10);


void printHeapStatistics() {
    std::cout << "Actual size allocated: " << GlobalHeapStatistics::sizeAllocated << std::endl;
    std::cout << "Number of allocations: " << GlobalHeapStatistics::nbOfAllocations << std::endl;
    std::cout << "Number of deallocations: " << GlobalHeapStatistics::nbOfDeallocations << std::endl;
}

class Parent : public NamedObject {
public:
    Parent() : NamedObject("Parent") {}
};

class Child : public NamedObject {
public:
    Child(NamedObject* parent) : NamedObject("Child", parent) {}
};

Parent  gParent;
Child   gChild(&gParent);

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    char buffer[100];
    gChild.getQualifiedName(buffer, sizeof(buffer));
    printf("Child name: %s of size: %d\n", buffer, gChild.getQualifiedNameSize());

#if 0
    TestDelegate delegate;
    auto algo = EvolutionAlgorithm(&testConfig, &delegate);
    
    algo.run();
#endif
    
    return 0;
}
