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
public:
	int firstMissingPositiveHash(vector<int>& nums) {
		if (!contain1(nums))
			return 1;
		// update out range number to 1
		for (size_t i = 0; i < nums.size(); i++)
			if (nums[i] < 1 || nums[i] > nums.size())
				nums[i] = 1;
		// update corresponding place 2 negative
		for (size_t i = 0; i < nums.size(); i++)
		{
			int index = abs(nums[i]) - 1;
			nums[index] = -abs(nums[index]);
		}
		// find first positive number
		for (size_t i = 0; i < nums.size(); i++)
			if (nums[i] > 0)
				return i + 1;
		
		return nums.size() + 1;
	}

	bool contain1(vector<int>& nums)
	{
		for (auto num : nums)
			if (num == 1)
				return true;
		return false;
	}

	int firstMissingPositiveSwap(vector<int>& nums) {
		int nLen = nums.size();
		if (nLen == 0)
			return 1;
		else if (nLen == 1)
			return nums[0] == 1 ? 2 : 1;
		for (int i = 0; i < nLen; i++)
		{
			int j = i;
			while (1)
			{
				bool swapFlag = false;
				if (0 < nums[j] && nums[j] < nLen + 1)
				{
					int perfectIndex = nums[j] - 1;
					if (perfectIndex != j && nums[perfectIndex] != nums[j])
					{
						swap(nums[j], nums[perfectIndex]);
						swapFlag = true;
					}
				}
				if (!swapFlag)
					break;
			}
		}
		// find first positive number
		for (size_t i = 0; i < nLen; i++)
			if (nums[i] != i + 1)
				return i + 1;
		return nLen + 1;
	}
};

int main()
{
	Solution solution = Solution();
	vector<int> nums{ 1,1 };
	auto result = solution.firstMissingPositiveSwap(nums);
	std::cout << result << std::endl;
	return 0;
}