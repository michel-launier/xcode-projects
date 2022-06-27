//
//  NamedObject.cpp
//  yaris
//
//  Created by Michel Launier on 2022-03-06.
//

#include "NamedObject.hpp"

NamedObject::NamedObject(const char* name, NamedObject* parent) {
    this->parent   = parent;
    this->name     = name;
    this->nameSize = strlen(name);
}

const char* NamedObject::getQualifiedName(char* buffer, size_t bufferSize) const {
    _getQualifiedName(buffer, bufferSize);
    return buffer;
}

size_t NamedObject::_getQualifiedName(char* buffer, size_t bufferSize) const {
    // Verify "bad" buffer size.
    if(bufferSize == 0 || bufferSize > kMaxNameSize) return 0;
    
    size_t size = 0;
    if(parent != 0) {
        size += parent->_getQualifiedName(buffer, bufferSize);
    }
    buffer[size++] = kSeparator;
    strcpy(&buffer[size], name);
    return size + nameSize;
}

// ================================================================================
/// Returns the size of the qualified name without the null termination.
size_t NamedObject::getQualifiedNameSize() const {
    size_t size = nameSize + 1;
    if(parent != 0) size+= parent->getQualifiedNameSize() + 1;
    return size;
}
