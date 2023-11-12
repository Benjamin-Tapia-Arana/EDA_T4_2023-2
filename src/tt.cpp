#include "ttTree/tt.hpp"
#include "ttTree/ttNode.hpp"
#include <functional>
#include <memory>

namespace trees {

TT::TT():root(nullptr) {
	// TODO Auto-generated constructor stub
}

void TT::insert_rec(int val, TTNode* node) {
    if ((node->getLeft() == nullptr) && (node->getMiddle() == nullptr) && (node->getRight() == nullptr)) {
        if (node->getMax() == -1) {
            if (val < node->getMin()) {
                node->setMax(node->getMin());
                node->setMin(val);
            }
            else node->setMax(val);
        }
        else {
            if (val < node->getMin()) {
                node->setMax(node->getMin());
                node->setMin(val);
            }
            else if (val > node->getMax()) {
                node->setMin(node->getMax());
                node->setMax(val);
            }
            else node->setMin(val);
        }
    }
    else {
        std::function<void(int, TTNode*)> insertFunctions[] = {
            [&](int v, TTNode* n) {insert_rec(v, n->getLeft().get());},
            [&](int v, TTNode* n) {insert_rec(v, n->getMiddle().get());},
            [&](int v, TTNode* n) {insert_rec(v, n->getRight().get());}
        };

        int childIndex = node->child(val);
        insertFunctions[childIndex](val, node);

        TTNode* childNode = nullptr;
        switch (childIndex) {
            case 0: childNode = node->getLeft().get(); break;
            case 1: childNode = node->getMiddle().get(); break;
            case 2: childNode = node->getRight().get(); break;
            default: break;
        }

        if (childNode && childNode->getMax() != -1) reorder(childNode);
    }
}

void TT::insert(int val){
	if (root == nullptr) root = new TTNode(val);
	else insert_rec(val, root);
}

void TT::reorder(TTNode* node) {
    if (node->getMax() == -1) {
        auto auxDsc1 = std::make_unique<TTNode>(node->getMin());
        auto auxDsc2 = std::make_unique<TTNode>(node->getMax());
        auxDsc1->setLeft(std::move(node->getLeft()));
        auxDsc2->setLeft(std::move(node->getMiddle()));
        auxDsc1->setMiddle(std::move(node->getMiddle()));
        auxDsc2->setMiddle(std::move(node->getRight()));

        auto asc = node->getParent();
        if (asc) {
            int position = asc->child(node->getMin());
            if (position == 0) {
                asc->setLeft(std::move(auxDsc1));
                asc->setMiddle(std::move(auxDsc2));
            }
            else if (position == 1) {
                asc->setLeft(std::move(auxDsc1));
                asc->setRight(std::move(auxDsc2));
            } 
            else {
                asc->setMiddle(std::move(auxDsc1));
                asc->setRight(std::move(auxDsc2));
            }
            auxDsc1->setParent(std::move(asc));
            auxDsc2->setParent(std::move(asc));
            resetNode(node);
            reorder(asc.get());
        } else {
            auto root = std::make_unique<TTNode>(node->getMax());
            root->setLeft(std::move(auxDsc1));
            root->setMiddle(std::move(auxDsc2));
            auxDsc1->setParent(std::move(root));
            auxDsc2->setParent(std::move(root));
            resetNode(node);
        }
    }
}

void TT::resetNode(TTNode* node) {
    node->setMin(-1);
    node->setMax(-1);
    node->setLeft(nullptr);
    node->setMiddle(nullptr);
    node->setRight(nullptr);
}

TTNode* TT::find_rec(int val, TTNode* node) {
    if (node == nullptr) return nullptr;
    else if (node->getMin() == val) return node;
    else if (node->getMax() == val) return node;
    else {
        std::function<TTNode*(int, TTNode*)> findFunctions[] = {
            [&](int v, TTNode* n) {return find_rec(v, n->getLeft().get());},
            [&](int v, TTNode* n) {return find_rec(v, n->getMiddle().get());},
            [&](int v, TTNode* n) {return find_rec(v, n->getRight().get());}
        };
        int dscIndex = node->child(val);
        return findFunctions[dscIndex](val, node);
    }
}

TTNode* TT::find(int val) {
    return find_rec(val, root);
}

TTNode* TT::getRoot() {return root;}

TT::~TT() {delete root;}

}