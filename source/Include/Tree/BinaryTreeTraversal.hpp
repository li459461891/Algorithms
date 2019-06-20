#ifndef __TREE_BINARY_TREE_TRAVERSAL_HPP__
#define __TREE_BINARY_TREE_TRAVERSAL_HPP__

#include <iostream>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <memory>
#include <vector>

namespace tree
{
// tree node with parent pointer
using namespace ::testing;
struct TreeNode;
using TreeNodePtr = std::shared_ptr<TreeNode>;

struct TreeNode
{
    TreeNode(TreeNodePtr leftChild, TreeNodePtr rightChiled, TreeNodePtr parent, int data)
        :leftChild_(leftChild),rightChild_(rightChiled), parent_(parent),data_(data){}
    TreeNode():leftChild_(nullptr),rightChild_(nullptr), parent_(nullptr),data_(0){}
    TreeNodePtr leftChild_;
    TreeNodePtr rightChild_;
    TreeNodePtr parent_;
    int data_;
};

class BinaryTreeTraversal
{
public:
    BinaryTreeTraversal():topNode_(nullptr){}
    void setTree(TreeNodePtr tree){topNode_ = tree;}
    std::vector<int> Inorder();
    void visitNode(const TreeNodePtr& node, std::vector<int>& vec);
private:
    TreeNodePtr topNode_;
};
}  // namespace tree

#endif  // __TREE_BINARY_TREE_TRAVERSAL_HPP__