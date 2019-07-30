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

TEST_F(LRUCacheNo146Tests, TestCases)
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


}

