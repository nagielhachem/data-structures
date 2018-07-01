//
//  LiFo.hpp
//
//  Created by Nagi's Macbook Air on 10/8/15.
//  Copyright © 2015 Nagi's Macbook Air. All rights reserved.
//

#ifndef LiFo_hpp
#define LiFo_hpp

// Last In First Out ou pile
class LiFo {
public:
    virtual void push(float value) = 0;
    //  throws Exception("add error") if adding fails

    virtual void pop() = 0;
    //  throws Exception("pop error") if popping from empty list
    virtual float top() = 0;
    //  throws Exception("empty list") if popping from empty list

    virtual bool isEmpty() = 0;
    virtual ~LiFo() {}
};

#endif /* LiFo_hpp */
