#ifndef DTWOTHREE_HPP_
#define DTWOTHREE_HPP_

#include "ttTree/ttNode.hpp"

namespace trees {

class TT {
private:
    TTNode* root;
    void resetNode(TTNode* node);
    void reorder(TTNode* node);
    void insert_rec(int val, TTNode* node);
    TTNode* find_rec(int val, TTNode* node);
public:
    TT();
    void insert(int val);
    TTNode* find(int val);
    TTNode* getRoot(); 
    virtual ~TT();
};

}

#endif 