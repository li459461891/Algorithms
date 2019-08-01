#include <iostream>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

// Sort a linked list in O(n log n) time using constant space complexity.
// Example 1:

// Input : 4->2->1->3
// Output: 1->2->3->4
// Example 2:

// Input : -1->5->3->4->0
// Output: -1->0->3->4->5

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
    ListNode* sortList(ListNode* head)
    {
        // Empty list or the list only contains one element.
        if (!head || !head->next)
        {
            return head;
        }
        int len = getLen(head);
        return mergeList(head, len);
    }

private:
    int getLen(ListNode* head)
    {
        int index = 0;
        while (head)
        {
            head = head->next;
            ++index;
        }
        return index;
    }

    ListNode* merge(ListNode* list1, const int& list1Len, ListNode* list2, const int& list2Len)
    {
        ListNode* tempHead = new ListNode(0);
        ListNode* movablePtr = tempHead;

        // Merge the two list.
        for (int index = 0 ; index < (list1Len + list2Len) ; ++index)
        {
            if (!list1 || !list2)
            {
                break;
            }
            if (list1->val <= list2->val)
            {
                movablePtr->next = list1;
                list1 = list1->next;
            }
            else
            {
                movablePtr->next = list2;
                list2 = list2->next;
            }
            movablePtr = movablePtr->next;
        }
        movablePtr->next = (list1 == NULL ? list2 : list1);
        movablePtr = tempHead->next;
        delete tempHead;  // delete extra space in heap
        return movablePtr;
    }

    // recurisivly
    ListNode* mergeList(ListNode* head, int len)
    {
        if (1 == len || !head || !head->next)
        {
            return head;
        }
        ListNode* mid = split(head, len);
        auto postHead = mid->next;
        mid->next = NULL;
// TODO : Consider the edge elems by using len/2
        ListNode* preELems = mergeList(head, len/2);
        auto postLen = len%2==0 ? len/2 : len/2 + 1;
        ListNode* postELems = mergeList(postHead, postLen);
        return merge(preELems, len/2, postELems, postLen);
    }

    // TODO: need modify.
    ListNode* split(ListNode* head, int len)
    {
        if (!head || !head->next || 1 == len)
        {
            return head;
        }
        ListNode* retPtr = head;
        for (int index = 0 ; index < (len / 2) - 1 ; ++index)
        {
            retPtr = retPtr->next;
        }
        return retPtr;
    }
};  // Solution

// ==========================================================TEST CODE=================================================
// ==========================================================TEST CODE=================================================
// ==========================================================TEST CODE=================================================
class SortListNo148Tests : public testing::Test
{
public:
    Solution sut_;

    ListNode* createNodeLists(const std::vector<int>& elems, ListNode* head)
    {

        ListNode* movablePtr = new ListNode(0);
        head = movablePtr;

        for (const auto& elem : elems)
        {
            ListNode* tmp = new ListNode(elem);
            movablePtr->next = tmp;
            movablePtr = movablePtr->next;
        }
        ListNode* extraHead = head;
        head = head->next;
        delete extraHead;
        return head;
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


TEST_F(SortListNo148Tests, TestCases)
{
    // empty list
    ListNode* node = NULL;
    std::vector<int> listElems;
    node = createNodeLists({}, node);
    listElems = getElemsFromListHeader(node);
    EXPECT_EQ(std::vector<int>{}, listElems);
    clearList(node);

    // input 4->2->1->3
    node = createNodeLists(std::vector<int>{4,2,1,3}, node);
    listElems = getElemsFromListHeader(node);
    EXPECT_EQ((std::vector<int>{4,2,1,3}), listElems);
    node = sut_.sortList(node);
    listElems = getElemsFromListHeader(node);
    EXPECT_EQ((std::vector<int>{1,2,3,4}), listElems);
    clearList(node);

    // input 4->2->1->3->2
    node = createNodeLists(std::vector<int>{4, 2, 1, 3, 2}, node);
    listElems = getElemsFromListHeader(node);
    EXPECT_EQ((std::vector<int>{4, 2, 1, 3, 2}), listElems);
    node = sut_.sortList(node);
    listElems = getElemsFromListHeader(node);
    EXPECT_EQ((std::vector<int>{1, 2, 2, 3, 4}), listElems);
    clearList(node);

}
