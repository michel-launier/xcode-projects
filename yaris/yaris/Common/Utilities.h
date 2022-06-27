//
//  Utilities.h
//  yaris
//
//  Created by Michel Launier on 2022-01-11.
//

#ifndef Utilities_h
#define Utilities_h

// Preprocessor token conversion to string
#define STRINGIFY(x)    #x
#define TOSTRING(x)     STRINGIFY(x)

#define GetExtensionFor(interface) dynamic_cast<interface>getExtension(TOSTRING(interface))


#endif /* Utilities_h */
