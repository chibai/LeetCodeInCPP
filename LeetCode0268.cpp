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
	int missingNumberSwap(vector<int>& nums) {
		int nLen = nums.size();
		if (nLen == 0)
			return 0;
		else if (nLen == 1)
			return nums[0] == 0 ? 1 : 0;
		for (int i = 0; i < nLen; i++)
		{
			int j = i;
			while (1)
			{
				bool swapFlag = false;
				int perfectIndex = nums[j];
				if (nums[j] != nLen &&  perfectIndex != j)
				{
					swapFlag = true;
					swap(nums[j], nums[perfectIndex]);
				}
				if (!swapFlag)
					break;
			}
		}
		for (int i = 0; i < nLen; i++)
			if (nums[i] != i)
				return i;
		return nLen;
	}

	int missingNumberFlag(vector<int>& nums) {
		int nLen = nums.size();
		if (nLen == 0)
			return 0;
		else if (nLen == 1)
			return nums[0] == 0 ? 1 : 0;
		//set corresponding place as negative, for 0, minus 1
		bool containN = false;
		for (int i = 0; i < nLen; i++)
		{
			if (nums[i] == nLen || nums[i] == -nLen)
				containN = true;
			else
				nums[abs(nums[i])] = -abs(nums[abs(nums[i])]);
		}
		if (containN)
		{
			int index0 = -1;
			for (int i = 0; i < nLen; i++)
			{
				if (nums[i] == 0)
					index0 = i;
				else if (nums[i] > 0)
					return i;
			}
			return index0;
		}
		else
			return nLen;
	}
};

int main()
{
	Solution solution = Solution();
	vector<int> nums = { 1, 3, 0 };
	auto result = solution.missingNumberFlag(nums);
	std::cout << result << std::endl;
	return 0;
}