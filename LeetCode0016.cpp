#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
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
	int threeSumClosest(vector<int>& nums, int target) {
		if (nums.size() < 3)
			return 0;
		int result = nums[0] + nums[1] + nums[2];
		int left, right, sum3;
		std::sort(nums.begin(), nums.end());
		for (size_t i = 0; i < nums.size() - 2; i++)
		{
			if (i > 0 && nums[i] == nums[i - 1])
				continue;
			left = i + 1;
			right = nums.size() - 1;
			while (left < right)
			{
				if (left > i + 1 && nums[left] == nums[left - 1])
				{
					left++;
					continue;
				}
				if (right < nums.size() - 1 && nums[right] == nums[right + 1])
				{
					right--;
					continue;
				}
				sum3 = nums[i] + nums[left] + nums[right];
				if (abs(sum3 - target) < abs(result - target))
					result = sum3;
				if (sum3 == target)
				{
					return target;
				}
				else if (sum3 > target)
					right--;
				else // sum3 < target
					left++;
			}
			
		}
		return result;
	}
};

int main()
{
	Solution solution = Solution();
	vector<int> nums = { 1,2,4,8,16,32,64,128};
	auto result = solution.threeSumClosest(nums, 82);
	std::cout << result << std::endl;
	return 0;
}