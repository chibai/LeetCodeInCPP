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
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		if (nums.size() == 0)
			return results;
		else
		{
			backtrace(nums, 0);
			return results;
		}
	}

	bool isSwapable(vector<int>& nums, int left, int right)
	{
		for (size_t i = left; i < right; i++)
			if (nums[i] == nums[right])
				return false;
		return true;
	}

	void backtrace(vector<int>& nums, int index)
	{
		if (index == nums.size())
		{
			results.emplace_back(nums);
		}
		else
		{
			for (int i = index; i < nums.size(); i++)
			{
				if (!isSwapable(nums, index, i))
				{
					continue;
				}
				else
				{
					swap(nums[index], nums[i]);
					backtrace(nums, index + 1);
					swap(nums[index], nums[i]);
				}

			}
		}
	}
};

int main()
{
	Solution solution = Solution();
	vector<int> nums = {0,0,0,1,9};
	auto results = solution.permuteUnique(nums);
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