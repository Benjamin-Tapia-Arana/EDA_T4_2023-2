#ifndef DTWOTHREE_HPP_
#define DTWOTHREE_HPP_

#include "ttTree/ttNode.hpp"
#include <memory> 

namespace trees {

class TT {
private:
    TTNode* root;
    void resetNode(TTNode* node);
public:
    TT();
    void reorder(TTNode* node);
    void insert_rec(int val, TTNode* node);
    void insert(int val);
    TTNode* getRoot(); 
    virtual ~TT();
};

}

#endif 