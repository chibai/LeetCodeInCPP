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
	int trap(vector<int>& height) {
		int hLen = height.size();
		if (hLen < 3)
			return 0;
		int maxIndex = 0;
		for (int i = 0; i < hLen; i++)
			maxIndex = height[maxIndex] > height[i] ? maxIndex : i;
		int highest = height[maxIndex];
		int result = 0;
		// check left part
		int leftMax = height[0];
		for (int i = 1; i < maxIndex; i++)
		{
			if (leftMax > height[i])
				result += (leftMax - height[i]);
			else
				leftMax = height[i];
		}
		// check right part
		int rightMax = height[hLen - 1];
		for (int i = hLen - 2; i > maxIndex; i--)
		{
			if (rightMax > height[i])
				result += (rightMax - height[i]);
			else
				rightMax = height[i];
		}
		return result;
	}
	
};

int main()
{
	Solution solution = Solution();
	vector<int> nums{ 4,2,0,3,2,5 };
	auto result = solution.trap(nums);
	std::cout << result << std::endl;
	return 0;
}