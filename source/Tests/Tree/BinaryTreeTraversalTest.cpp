#include <Tree/BinaryTreeTraversal.hpp>

namespace tree
{
class BinaryTreeTraversalTests : public testing::Test
{
public:
    BinaryTreeTraversalTests() = default;
    virtual ~BinaryTreeTraversalTests() = default;
    BinaryTreeTraversal sut_ = BinaryTreeTraversal();

    TreeNodePtr createTree1()
    {
        TreeNodePtr treeNode1 = std::make_shared<TreeNode>(nullptr, nullptr, nullptr, 1);
        TreeNodePtr treeNode2 = std::make_shared<TreeNode>(nullptr, nullptr, treeNode1, 2);
        TreeNodePtr treeNode3 = std::make_shared<TreeNode>(nullptr, nullptr, treeNode1, 3);
        TreeNodePtr treeNode4 = std::make_shared<TreeNode>(nullptr, nullptr, treeNode2, 4);
        TreeNodePtr treeNode5 = std::make_shared<TreeNode>(nullptr, nullptr, treeNode2, 5);
        TreeNodePtr treeNode6 = std::make_shared<TreeNode>(nullptr, nullptr, treeNode3, 6);
        TreeNodePtr treeNode7 = std::make_shared<TreeNode>(nullptr, nullptr, treeNode3, 7);
        treeNode1->leftChild_ = treeNode2;
        treeNode1->rightChild_ = treeNode3;
        treeNode2->leftChild_ = treeNode4;
        treeNode2->rightChild_ = treeNode5;
        treeNode3->leftChild_ = treeNode6;
        treeNode3->rightChild_ = treeNode7;
        return treeNode1;
    }

    TreeNodePtr createTree2()
    {
        auto treeNode2 = std::make_shared<TreeNode>(nullptr, nullptr, nullptr, 2);
        auto treeNode1 = std::make_shared<TreeNode>(treeNode2, nullptr, nullptr, 1);
        auto treeNode3 = std::make_shared<TreeNode>(nullptr, nullptr, treeNode2, 3);
        treeNode2->leftChild_ = treeNode3;
        treeNode2->parent_ = treeNode1;
        return treeNode1;
    }

    TreeNodePtr createTree3()
    {
        auto treeNode2 = std::make_shared<TreeNode>(nullptr, nullptr, nullptr, 2);
        auto treeNode1 = std::make_shared<TreeNode>(nullptr, treeNode2, nullptr, 1);
        auto treeNode3 = std::make_shared<TreeNode>(nullptr, nullptr, treeNode2, 3);
        treeNode2->rightChild_ = treeNode3;
        treeNode2->parent_ = treeNode1;
        return treeNode1;
    }

    TreeNodePtr createTree4()
    {
        auto treeNode2 = std::make_shared<TreeNode>(nullptr, nullptr, nullptr, 2);
        auto treeNode1 = std::make_shared<TreeNode>(treeNode2, nullptr, nullptr, 1);
        auto treeNode3 = std::make_shared<TreeNode>(nullptr, nullptr, treeNode2, 3);
        auto treeNode4 = std::make_shared<TreeNode>(nullptr, nullptr, treeNode2, 4);
        treeNode2->leftChild_ = treeNode3;
        treeNode2->rightChild_ = treeNode4;
        treeNode2->parent_ = treeNode1;
        return treeNode1;
    }

    TreeNodePtr createTree5()
    {
        auto treeNode2 = std::make_shared<TreeNode>(nullptr, nullptr, nullptr, 2);
        auto treeNode1 = std::make_shared<TreeNode>(nullptr, treeNode2, nullptr, 1);
        auto treeNode3 = std::make_shared<TreeNode>(nullptr, nullptr, treeNode2, 3);
        auto treeNode4 = std::make_shared<TreeNode>(nullptr, nullptr, treeNode2, 4);
        treeNode2->leftChild_ = treeNode3;
        treeNode2->rightChild_ = treeNode4;
        treeNode2->parent_ = treeNode1;
        return treeNode1;
    }
};

TEST_F(BinaryTreeTraversalTests, InorderOk)
{
/*        tree 1                  tree 2            tree 3                tree 4          tree 5
*
*             1                       1                 1                    1              1
*          /    \                    /                   \                  /                \
*         2      3                  2                     2                2                  2
*        / \    / \                /                       \              / \                / \
*       4   5  6   7              3                         3            3   4              3   4
*InOrder:{4,2,5,1,6,3,7}        {3,2,1}              {1,2,3}           {3,2,4,1}           {1,3,2,4}

*/
    std::vector<int> expectedResult = {4,2,5,1,6,3,7};
    sut_.setTree(createTree1());
    auto result = sut_.Inorder();
    EXPECT_EQ(expectedResult, result);

    expectedResult = {3,2,1};
    sut_.setTree(createTree2());
    result = sut_.Inorder();
    EXPECT_EQ(expectedResult, result);

    expectedResult = {1,2,3};
    sut_.setTree(createTree3());
    result = sut_.Inorder();
    EXPECT_EQ(expectedResult, result);

    expectedResult = {3,2,4,1};
    sut_.setTree(createTree4());
    result = sut_.Inorder();
    EXPECT_EQ(expectedResult, result);

    expectedResult = {1,3,2,4};
    sut_.setTree(createTree5());
    result = sut_.Inorder();
    EXPECT_EQ(expectedResult, result);
}
}  // namespace tree
