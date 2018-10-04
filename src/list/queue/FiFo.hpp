//
//  FiFo.hpp
//
//  Created by Nagi's Macbook Air on 10/8/15.
//  Copyright © 2015 Nagi's Macbook Air. All rights reserved.
//

#ifndef FiFo_hpp
#define FiFo_hpp

// First In, First Out ou File
class FiFo {
public:
    virtual void push(float value) = 0;
    //  throws Exception("add error") if adding fails

    virtual void pop() = 0;
    //  throws Exception("pop error") if popping from empty list
    virtual float top() = 0;
    //  throws Exception("empty list") if popping from empty list

    virtual bool isEmpty() = 0;
    virtual ~FiFo() {}
};

#endif /* FiFo_hpp */
