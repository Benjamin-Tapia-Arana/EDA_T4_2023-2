#ifndef DTWOTHREENODE_HPP_
#define DTWOTHREENODE_HPP_

#include <memory> 

namespace trees {

class TTNode {
private:
	std::unique_ptr<TTNode> ptrParent;
	std::unique_ptr<TTNode> ptrLeft;
	std::unique_ptr<TTNode> ptrMiddle;
	std::unique_ptr<TTNode> ptrRight;
	int dataMin;
	int dataMax;
public:
	TTNode();
	TTNode(int val);
	void setParent(std::unique_ptr<TTNode> node);
	void setLeft(std::unique_ptr<TTNode> node);
	void setMiddle(std::unique_ptr<TTNode> node);
	void setRight(std::unique_ptr<TTNode> node);
	void dropLeft();
	void dropMiddle();
	void dropRight();
	void setMin(int val);
	void setMax(int val);
	std::unique_ptr<TTNode> getParent();
	std::unique_ptr<TTNode> getLeft();
	std::unique_ptr<TTNode> getMiddle();
	std::unique_ptr<TTNode> getRight();
	int getMin();
	int getMax();
	int child(int val);
	virtual ~TTNode();
};

}

#endif
