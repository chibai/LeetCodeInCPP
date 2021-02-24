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

class Solution {
private:
	
public:
	void rotate(vector<vector<int>>& matrix) {
		if (matrix.size() < 2)
			return;
		int n = matrix.size();
		for (int rowIndex = 0; rowIndex < n / 2; rowIndex++)
		{
			for (int colIndex = 0; colIndex < n - rowIndex - 1; colIndex++)
			{
				int tmp = matrix[rowIndex][colIndex];
				matrix[rowIndex][colIndex] = matrix[n - 1 - colIndex][rowIndex];
				matrix[n - 1 - colIndex][rowIndex] = matrix[n - 1 - rowIndex][n - 1 - colIndex];
				matrix[n - 1 - rowIndex][n - 1 - colIndex] = matrix[colIndex][n - 1 - rowIndex];
				matrix[colIndex][n - 1 - rowIndex] = tmp;
				
				
				
			}
		}
	}
};

int main()
{
	Solution solution = Solution();
	vector<vector<int>> nums = { {1,2,3},{4,5,6},{7,8,9} };
	solution.rotate(nums);
	for (auto result: nums)
	{
		for (auto n:result)
		{
			std::cout << n;
		}
		std::cout << std::endl;
	}
	return 0;
}