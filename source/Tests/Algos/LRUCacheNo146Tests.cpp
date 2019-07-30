#include <iostream>
#include <Algos/LRUCacheNo146.hpp>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace LRUCache
{
class LRUCacheNo146Tests : public testing::Test
{
public:
    LRUCacheNo146Tests() = default;
    ~LRUCacheNo146Tests() = default;
    LRUCache sut_ ;
};

TEST_F(LRUCacheNo146Tests, TestCases1)
{

    sut_.setCapacity(2);
    sut_.put(1, 1);
    sut_.put(2, 2);
    EXPECT_EQ(1, sut_.get(1));
    sut_.put(3, 3);
    EXPECT_EQ(-1, sut_.get(2));
    sut_.put(4, 4);
    EXPECT_EQ(-1, sut_.get(1));
    EXPECT_EQ(3, sut_.get(3));
    EXPECT_EQ(4, sut_.get(4));
}

//["LRUCache", 2
// "get",  [2]        expect -1
// "put",  [2,6]
// "get",  [1]        expect -1
// "put",  [1,5]
// "put",  [1,2]
// "get",  [1]        expect 2
// "get",  [2]        expect 6

//,[2],,,,,[1],[2]]
//[null,-1,null,-1,null,null,2,6]
//
TEST_F(LRUCacheNo146Tests, TestCases2)
{
    sut_.setCapacity(2);
    EXPECT_EQ(-1, sut_.get(2));
    sut_.put(2, 6);
    EXPECT_EQ(-1, sut_.get(1));
    sut_.put(1, 5);
    sut_.put(1, 2);
    EXPECT_EQ(2, sut_.get(1));
    EXPECT_EQ(6, sut_.get(2));
}

TEST_F(LRUCacheNo146Tests, fsanitizeCrash)
{
    int* test = new int{2};
    delete test;
    std::cout << *test << std::endl;  // this heap memory access is invalied
}

}  // namespace LRUCache