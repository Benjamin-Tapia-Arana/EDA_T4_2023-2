#include "ttTree/ttNode.hpp"
#include <memory>

namespace trees {

TTNode::TTNode() {
    ptrParent = nullptr;
    ptrLeft = nullptr;
    ptrMiddle = nullptr;
    ptrRight = nullptr;
    dataMin = -1;
    dataMax = -1;
}

TTNode::TTNode(int val) {
    ptrParent = nullptr;
    ptrLeft = nullptr;
    ptrMiddle = nullptr;
    ptrRight = nullptr;
    dataMin = val;
    dataMax = -1;
}

int TTNode::child(int val) {
    if (dataMax == -1) return (val < dataMin) ? 0 : 1;
    else {
        if (val < dataMin) return 0;
        else if (val > dataMax) return 2;
        else return 1;
    }
}

void TTNode::setLeft(std::unique_ptr<TTNode> node) {ptrLeft = std::move(node);}

void TTNode::setMiddle(std::unique_ptr<TTNode> node) {ptrMiddle = std::move(node);}

void TTNode::setRight(std::unique_ptr<TTNode> node) {ptrRight = std::move(node);}

void TTNode::setParent(std::unique_ptr<TTNode> node) {ptrParent = std::move(node);}

void TTNode::setMin(int val) {dataMin = val;}

void TTNode::setMax(int val) {dataMax = val;}

int TTNode::getMin() {return dataMin;}

int TTNode::getMax() {return dataMax;}

std::unique_ptr<TTNode> TTNode::getLeft() {return std::move(ptrLeft);}

std::unique_ptr<TTNode> TTNode::getMiddle() {return std::move(ptrMiddle);}

std::unique_ptr<TTNode> TTNode::getRight() {return std::move(ptrRight);}

std::unique_ptr<TTNode> TTNode::getParent() {return std::move(ptrParent);}

TTNode::~TTNode() {}

}
