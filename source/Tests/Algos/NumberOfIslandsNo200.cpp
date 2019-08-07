#include <iostream>
#include <vector>
#include <utility>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using std::vector;
using std::pair;

// Given a 2d grid map of '1's (land) and '0's (water), count the number of islands.
// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
// You may assume all four edges of the grid are all surrounded by water.

// Example 1:

// Input:
// 11110
// 11010
// 11000
// 00000

// Output: 1
// Example 2:

// Input:
// 11000
// 11000
// 00100
// 00011

// Output: 3

class Solution {
public:
    // dfs + recursive
    // time: o(row * column)
    // space: o(row)
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) {return 0;}
        int count_of_islands = 0; // return value
        for (int row = 0; row < grid.size() ; ++ row)
        {
            for (int col = 0; col < grid[0].size(); ++col)
            {
                if('1' == grid[row][col])
                {
                    ++ count_of_islands;
                    dfs(grid, row, col);  // use the dfs to mark every grid = 2 which belongs to this island.
                }
            }
        }
        return count_of_islands;
    }

private:

    vector<pair<int, int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};//<row, column>

    // dfs to mark every grid in this island
    int dfs(vector<vector<char>>& grid, int row, int col)
    {
        grid[row][col] = '2';
        for (auto d : dir)
        {
            int next_row = row + d.first;
            int next_col = col + d.second;
            if (next_row >= 0
                && next_row < grid.size()
                && next_col >= 0
                && next_col < grid[0].size()
                && '1' == grid[next_row][next_col])
            {
                dfs(grid, next_row, next_col);
            }
        }
        return 0;
    }

};

// ==========================================================TEST CODE=================================================
// ==========================================================TEST CODE=================================================
// ==========================================================TEST CODE=================================================
class NumberOfIslandsNo200Tests : public testing::Test
{
public:
    Solution sut_;
}; // class NumberOfIslandsNo200Tests

TEST_F(NumberOfIslandsNo200Tests, testcases)
{
    using GRID_TYPE = std::vector<std::vector<char>>;
    GRID_TYPE G1 =
    {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };

    GRID_TYPE G2 =
    {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };


    EXPECT_EQ(1, sut_.numIslands(G1));
    EXPECT_EQ(3, sut_.numIslands(G2));
}