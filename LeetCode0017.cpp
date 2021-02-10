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
	vector<string> letterCombinations(string digits) {
		vector<string> digit2str = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
		vector<string> results;
		if (digits.length() == 0)
			return results;
		for (auto & ch : digit2str[digits[0] - '0'])
			results.push_back(string(1, ch));
		for (auto &digit:digits.substr(1))
		{
			string current_str = digit2str[digit - '0'];
			vector<string> tmp_results = results;
			results.clear();
			for (auto pre_result:tmp_results)
			{
				for (auto ch : current_str)
				{
					string s = pre_result + ch;
					results.push_back(s);
				}
			}
		}
		return results;
	}

	vector<string> letterCombinationsDFS(string digits) {
		vector<string> digit2str = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
		vector<string> results;
		if (digits.length() == 0)
			return results;

		string current = "";
		DFS(results, digit2str, 0, current, digits);
		return results;
	}
	void DFS(vector<string>& results, vector<string>& digit2str, int index, string current, string& digits)
	{
		if (index == digits.size())
			results.push_back(current);
		else
		{
			int digitIndex = digits[index] - '0';
			string currentStr = digit2str[digitIndex];
			for (auto ch:currentStr)
			{
				current.push_back(ch);
				DFS(results, digit2str, index + 1, current, digits);
				current.pop_back();
			}
		}
	}
	
};

int main()
{
	Solution solution = Solution();
	auto results = solution.letterCombinationsDFS("234");
	for (auto &str:results)
	{
		for (auto &ch:str)
		{
			std::cout << ch;
		}
		std::cout << std::endl;
	}
	return 0;
}