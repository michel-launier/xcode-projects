//
//  Heap.cpp
//  yaris
//
//  Created by Michel Launier on 2022-03-06.
//

#include "Heap.hpp"

namespace GlobalHeapStatistics {
    size_t   sizeAllocated = 0;
    unsigned nbOfAllocations = 0;
    unsigned nbOfDeallocations = 0;
}
using namespace GlobalHeapStatistics;

void* operator new(size_t size) {
    sizeAllocated += size;
    ++nbOfAllocations;
    return malloc(size);
}

void* operator new[](size_t size) {
    sizeAllocated += size;
    ++nbOfAllocations;
    return malloc(size);
}

void operator delete(void* memory, size_t size) throw() {
    sizeAllocated -= size;
    ++nbOfDeallocations;
    free(memory);
}

void operator delete[](void* memory, size_t size) throw() {
    sizeAllocated -= size;
    ++nbOfDeallocations;
    free(memory);
}
