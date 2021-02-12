#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <stack>
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
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() < 2)
			return nums.size();
		int j = 0;
		for (size_t i = 1; i < nums.size(); i++)
		{
			if (nums[i] == nums[j])
				continue;
			else
			{
				j++;
				nums[j] = nums[i];
			}
		}
		return j + 1;
	}
	
};

int main()
{
	Solution solution = Solution();
	vector<int> nums = { 1,1,1,2,2,2,3,3,4,4 };
	auto result = solution.removeDuplicates(nums);
	for (auto num:nums)
	{
		std::cout << num << ' ';
	}
	return 0;
}