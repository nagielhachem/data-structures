//
//  Collection.hpp
//
//  Created by Nagi's Macbook Air on 10/8/15.
//  Copyright © 2015 Nagi's Macbook Air. All rights reserved.
//

#ifndef Collection_hpp
#define Collection_hpp

class Collection {
public:
    virtual void add(float value) = 0;
    //  throws Exception("add error") if adding fails

    virtual void removeFirst(float value) = 0;
    //  throws Exception("not found") if inexistant element

    virtual bool find(float value) = 0;
    virtual unsigned int size() = 0;

    virtual ~Collection() {}
};

#endif /* Collection_hpp */
