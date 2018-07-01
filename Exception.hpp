//
//  Exception.hpp
//  CollectionsTd
//
//  Created by Nagi's Macbook Air on 10/8/15.
//  Copyright © 2015 Nagi's Macbook Air. All rights reserved.
//

#ifndef Exception_hpp
#define Exception_hpp

#include <string>

class Exception {
    std::string _m;

public:
    Exception(std::string message);
    std::string message() const;
    virtual ~Exception();
};

#endif /* Exception_hpp */
