#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
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
	int maxArea(vector<int>& height) {
		if (height.size() < 2)
			return 0;
		int left = 0, right = height.size() - 1;
		int maxArea = min(height[left], height[right]) * (right - left);
		while (left < right)
		{
			maxArea = max(maxArea, min(height[left], height[right]) * (right - left));
			if (height[left] > height[right])
				right--;
			else
				left++;
		}
		return maxArea;
	}
};

int main()
{
	Solution solution = Solution();
	vector<int> heights{ 1,8,6,2,5,4,8,3,7 };
	auto result = solution.maxArea(heights);
	std::cout << result;
	return 0;
}