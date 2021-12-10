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

class Solution{
    public:

    vector<int> word2shortestStatistics(string word)
    {
        std::vector<int> statistics = vector<int>(26);
        for (auto &ch:word)
            if ('a' <= ch && ch <= 'z')
                statistics[ch - 'a'] += 1; 
            else if ('A' <= ch && ch <= 'Z')
                statistics[ch - 'A'] += 1; 
        return statistics;
    }

    bool checkAvailable(vector<int> candidate, vector<int> word)
    {
        for (size_t i = 0; i < candidate.size(); i++)
            if (word[i] < candidate[i])
                return false;
        return true;
    }

    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        auto plateS = word2shortestStatistics(licensePlate);
        int minLen = 16;
        string result;
        for (auto& word:words)
            if (word.size() < minLen && checkAvailable(plateS, word2shortestStatistics(word)))
            {
                minLen = word.size();
                result = word;
            }
        return result;
    }
};

int main()
{
    Solution solution;
    string licensePlate = "iMSlpe4";
    vector<string> words = vector<string>{"claim","consumer","student","camera","public","never","wonder","simple","thought","use"};
    auto result = solution.shortestCompletingWord(licensePlate, words);
    std::cout << result << std::endl;
}