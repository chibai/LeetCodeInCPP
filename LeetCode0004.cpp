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
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.size() > nums2.size())
		{
			std::swap(nums1, nums2);
		}
		int n = nums1.size(), m = nums2.size();
		int totalLeft = (n + m + 1) / 2;
		// nums1[i - 1] <= nums2[j] and nums[j - 1] <= nums1[i]
		int left = 0, right = n, i, j;
		while (left < right)
		{
			i = (left + right + 1) / 2;
			j = totalLeft - i;
			if (nums1[i - 1] > nums2[j])
				right = i - 1;
			else
				left = i;
		}
		i = left;
		j = totalLeft - i;
		double nums1Left = i == 0 ? INT_MIN : nums1[i - 1];
		double nums1Right = i == n ? INT_MAX : nums1[i];
		double nums2Left = j == 0 ? INT_MIN : nums2[j - 1];
		double nums2Right = j == m ? INT_MAX : nums2[j];
		if ((m + n) % 2 == 1)
			return max(nums1Left, nums2Left);
		else
			return (max(nums1Left, nums2Left) + min(nums1Right, nums2Right)) / 2;
	}
};

int main()
{
	Solution solution = Solution();
	vector<int> nums1{ 1,3 };
	vector<int> nums2{ 2 };
	auto result = solution.findMedianSortedArrays(nums1, nums2);
	std::cout << result << std::endl;
	return 0;
}