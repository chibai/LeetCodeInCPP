#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <bitset>
using namespace std;

//Definition for singly linked list
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution{
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<int> rowsMax;
        for (auto&row:grid)
            rowsMax.push_back(*max_element(row.begin(), row.end()));
        vector<int> colsMax;
        for (size_t colIndex = 0; colIndex < cols; colIndex++)
        {
            vector<int> newColumn;
            for (size_t rowIndex = 0; rowIndex < rows; rowIndex++)
                newColumn.push_back(grid[rowIndex][colIndex]);
            colsMax.push_back(*max_element(newColumn.begin(), newColumn.end()));
        }
        //
        int result = 0;
        for (size_t rowIndex = 0; rowIndex < rows; rowIndex++)
        {
            for (size_t colIndex = 0; colIndex < cols; colIndex++)
            {
                int minHeight = std::min(rowsMax[rowIndex], colsMax[colIndex]);
                if (grid[rowIndex][colIndex] < minHeight)
                    result += (minHeight - grid[rowIndex][colIndex]);
            }
        }
        return result;
    }
};

int main()
{
    vector<vector<int>> grid;
    grid.push_back(vector<int>{3,0,8,4});
    grid.push_back(vector<int>{2,4,5,7});
    grid.push_back(vector<int>{9,2,6,3});
    grid.push_back(vector<int>{0,3,1,0});
    Solution solution;
    std::cout << solution.maxIncreaseKeepingSkyline(grid) << std::endl;
}
