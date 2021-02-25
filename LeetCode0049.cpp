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
	
public:
	vector<vector<string>> groupAnagramsCount(vector<string>& strs) {
		vector<vector<string>> results;
		vector<vector<int>> flags;
		int strsLen = strs.size();
		if (strsLen == 0)
			return results;
		else if (strsLen == 1)
		{
			results.push_back({ strs[0] });
			return results;
		}
		for (auto &str: strs)
		{
			vector<int> currentFlag(26, 0);
			for (auto &ch: str)
				currentFlag[ch - 'a'] += 1;
			int index = containVector(flags, currentFlag);
			if (index == -1)
			{
				flags.push_back(currentFlag);
				results.push_back({ str });
			}
			else
			{
				results[index].push_back(str);
			}
		}
		return results;
	}

	int containVector(vector<vector<int>> &flags, vector<int>&flag)
	{
		for (int i = 0; i < flags.size(); i++)
		{
			int j = 0;
			for (; j < 26; j++)
				if (flag[j] != flags[i][j])
					break;
			if (j == 26)
				return i;
		}
		return -1;
	}

	vector<vector<string>> groupAnagramsHash(vector<string>& strs) {
		vector<vector<string>> results;
		vector<string> flags;
		int strsLen = strs.size();
		if (strsLen == 0)
			return results;
		else if (strsLen == 1)
		{
			results.push_back({ strs[0] });
			return results;
		}
		for (auto &str : strs)
		{
			string currentFlag = str;
			sort(currentFlag.begin(), currentFlag.end());
			int i = 0;
			for (; i < flags.size(); i++)
				if (flags[i] == currentFlag)
					break;
			if (i == flags.size())
			{
				results.push_back({ str });
				flags.push_back(currentFlag);
			}
			else
			{
				results[i].push_back(str);
			}
		}
		return results;
	}
};

int main()
{
	Solution solution = Solution();
	vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
	auto results = solution.groupAnagramsHash(strs);
	for (auto result: results)
	{
		for (auto n:result)
		{
			std::cout << n << std::endl;;
		}
		std::cout << std::endl;
	}
	return 0;
}