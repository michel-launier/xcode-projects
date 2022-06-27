//
//  NamedObject.hpp
//  yaris
//
//  Created by Michel Launier on 2022-03-06.
//

#ifndef NamedObject_hpp
#define NamedObject_hpp

#include <memory>

class NamedObject {
    const static size_t    kMaxNameSize = 4095;
    const static char      kSeparator   = '/';
    
    const char*     name;
    size_t          nameSize;
    NamedObject*    parent;
    
public:
    NamedObject(const char* name, NamedObject* parent = 0);
    
    const char* getName() const                         { return name; }
    size_t      getNameSize() const                     { return nameSize; }
    size_t      getNameAllocationSize() const           { return getNameSize()+1; }
    const char* getQualifiedName(char* buffer, size_t bufferSize) const;
    size_t      getQualifiedNameSize() const;
    size_t      getQualifiedNameAllocationSize() const  { return getQualifiedNameSize()+1; }
    
private:
    size_t      _getQualifiedName(char* buffer, size_t buffersize) const;
};

#endif /* NamedObject_hpp */
