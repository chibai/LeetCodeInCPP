#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
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
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> results;
		if (nums.size() < 4)
			return results;
		sort(nums.begin(), nums.end());
		int left, right, sum4;
		for (int first = 0; first < nums.size() - 3; first++)
		{
			if (first > 0 && nums[first] == nums[first - 1])
				continue;
			for (int second = first + 1; second < nums.size() - 2; second++)
			{
				if (second > first + 1 && nums[second] == nums[second - 1])
					continue;
				left = second + 1;
				right = nums.size() - 1;
				while (left < right)
				{
					if (left > second + 1 && nums[left] == nums[left - 1])
					{
						left++;
						continue;
					}
					if (right < nums.size() - 1 && nums[right] == nums[right + 1])
					{
						right--;
						continue;
					}
					sum4 = nums[first] + nums[second] + nums[left] + nums[right];
					if (sum4 == target)
					{
						results.push_back({ nums[first], nums[second], nums[left], nums[right] });
						left++;
						right--;
					}
					else if (sum4 > target)
					{
						right--;
					}
					else if (sum4 < target)
					{
						left++;
					}
				}
			}
		}
		return results;
	}
};

int main()
{
	Solution solution = Solution();
	vector<int> nums = { 1,0,-1,0,-2,2 };
	auto results = solution.fourSum(nums, 0);
	for (auto &str:results)
	{
		for (auto &ch:str)
		{
			std::cout << ch << ' ';
		}
		std::cout << std::endl;
	}
	return 0;
}