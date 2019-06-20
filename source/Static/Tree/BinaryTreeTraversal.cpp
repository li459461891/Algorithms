#include <Tree/BinaryTreeTraversal.hpp>

namespace tree
{

void BinaryTreeTraversal::visitNode(const TreeNodePtr& node, std::vector<int>& vec)
{
    vec.push_back(node->data_);
}

std::vector<int> BinaryTreeTraversal::inorder()
{
    std::vector<int> visitOrderVec_; // First step, make a clean vector
    // if topNode_ is null
    if (not topNode_) return std::vector<int>{};
    std::vector<TreeNodePtr> tmpStack;
    tmpStack.push_back(topNode_);
    auto traversalPtr = topNode_;
    while((not tmpStack.empty()) or (traversalPtr))
    {
        if (traversalPtr)
        {
            traversalPtr = traversalPtr->leftChild_;  // move to left
            tmpStack.push_back(traversalPtr);
            continue;
        }
        tmpStack.pop_back(); // pop the nullptr
        if (tmpStack.size() <= 0) return visitOrderVec_;
        traversalPtr = tmpStack[tmpStack.size() - 1];
        tmpStack.pop_back();
        visitNode(traversalPtr, visitOrderVec_);// pop and visit the node
        traversalPtr = traversalPtr->rightChild_; // move to right child
        tmpStack.push_back(traversalPtr);
    }
    return visitOrderVec_;
}


	void BinaryTreeTraversal::preOrderRecurse(TreeNodePtr nodePtr)
	{
		if (not nodePtr) return ;
		visitNode(nodePtr,  vecForRecurseTraversal_);
		preOrderRecurse(nodePtr->leftChild_);
		preOrderRecurse(nodePtr->rightChild_);
	}

	void BinaryTreeTraversal::inOrderRecurse(TreeNodePtr nodePtr)
	{
		if (not nodePtr) return ;
		inOrderRecurse(nodePtr->leftChild_);
		visitNode(nodePtr,  vecForRecurseTraversal_);
		inOrderRecurse(nodePtr->rightChild_);
	}

	void BinaryTreeTraversal::postOrderRecurse(TreeNodePtr nodePtr)
	{
		if (not nodePtr) return ;
		postOrderRecurse(nodePtr->leftChild_);
		postOrderRecurse(nodePtr->rightChild_);
		visitNode(nodePtr,  vecForRecurseTraversal_);
	}

}  // namespace tree


