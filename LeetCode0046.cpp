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
	vector<vector<int>> results;
public:
	vector<vector<int>> permute(vector<int>& nums) {
		if (nums.size() == 0)
			return results;
		else
		{
			backtrace(nums, 0);
			return results;
		}
	}

	void backtrace(vector<int>& nums, int index)
	{
		if (index == nums.size())
		{
			results.push_back({nums});
		}
		else
		{
			for (int i = index; i < nums.size(); i++)
			{
				swap(nums[index], nums[i]);
				backtrace(nums, index + 1);
				swap(nums[index], nums[i]);
			}
		}
	}
};

int main()
{
	Solution solution = Solution();
	vector<int> nums = { 2,3,1,4 };
	auto results = solution.permute(nums);
	for (auto result: results)
	{
		for (auto n:result)
		{
			std::cout << n;
		}
		std::cout << std::endl;
	}
	return 0;
}