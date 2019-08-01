#include <iostream>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

// Merge two sorted linked lists and return it as a new list.
// The new list should be made by splicing together the nodes of the first two lists.

// Example:

// Input: 1->2->4, 1->3->4
// Output: 1->1->2->3->4->4

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode* tempHead = new ListNode(0);
        ListNode* movablePtr = tempHead;
        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                movablePtr->next = l1;
                l1 = l1->next;
            }
            else
            {
                movablePtr->next = l2;
                l2 = l2->next;
            }
            movablePtr = movablePtr->next;
        }
        movablePtr->next = (l1 == NULL ? l2 : l1);
        movablePtr = tempHead->next;
        delete tempHead;  // delete extra space in heap
        return movablePtr;
    }
};  // class Solution

// ==========================================================TEST CODE=================================================
// ==========================================================TEST CODE=================================================
// ==========================================================TEST CODE=================================================
class MergeTwoSortedListsNo21Tests : public testing::Test
{
public:
    Solution sut_;

    void createNodeLists(const std::vector<int>& elems, ListNode** head)
    {

        ListNode* movablePtr = new ListNode(0);
        *head = movablePtr;

        for (const auto& elem : elems)
        {
            ListNode* tmp = new ListNode(elem);
            movablePtr->next = tmp;
            movablePtr = movablePtr->next;
        }
        ListNode* extraHead = *head;
        *head = extraHead->next;
        delete extraHead;
    }

    void clearList(ListNode* head)
    {
        while(NULL != head)
        {
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    std::vector<int> getElemsFromListHeader(const ListNode* nodePtr)
    {
        std::vector<int> retElems;
        while(NULL != nodePtr)
        {
            retElems.emplace_back(nodePtr->val);
            nodePtr = nodePtr->next;
        }
        return retElems;
    }
};


TEST_F(MergeTwoSortedListsNo21Tests, TestCases)
{
    // input 4->2->1->3
    ListNode* l1 = NULL;
    ListNode* l2 = NULL;
    ListNode* lMerge = NULL;

    createNodeLists(std::vector<int>{1,2,4}, &l1);
    createNodeLists(std::vector<int>{1,3,4}, &l2);
    auto l1Elems = getElemsFromListHeader(l1);
    auto l2Elems = getElemsFromListHeader(l2);

    EXPECT_EQ((std::vector<int>{1,2,4}), l1Elems);
    EXPECT_EQ((std::vector<int>{1,3,4}), l2Elems);
    lMerge = sut_.mergeTwoLists(l1, l2);
    auto lMergeElems = getElemsFromListHeader(lMerge);
    EXPECT_EQ((std::vector<int>{1,1,2,3,4,4}), lMergeElems);
    clearList(lMerge);
}
