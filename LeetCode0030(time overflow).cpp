#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <stack>
using namespace std;

//Definition for singly linked list
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution1 {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> results;
		if (s.size() == 0 || words.size() == 0)
			return results;
		map<string, int> wordCountRecords;
		vector<string> wordRecords(s.length());
		int patternSize = words[0].length();
		for (auto &word : words)
		{
			if (wordCountRecords.find(word) == wordCountRecords.end())
			{
				wordCountRecords[word] = 1;
				patternSearch(s, word, patternSize, wordRecords);
			}
			else
				wordCountRecords[word]++;
		}
		for (size_t i = 0; i < s.size() - words.size() * patternSize + 1; i++)
		{
			auto tmpRecords = wordCountRecords;
			for (size_t j = 0; j < words.size(); j++)
			{
				string currentStr = wordRecords[i + patternSize * j];
				if (currentStr.length() > 0)
					tmpRecords[currentStr] -= 1;
				else
					break;
			}
			if (allZeroMap(tmpRecords))
				results.push_back(i);
		}
		return results;
	}

	bool allZeroMap(map<string, int> container)
	{
		for (auto &e:container)
		{
			if (e.second != 0)
				return false;
		}
		return true;
	}

	void patternSearch(string& txt, string& pattern, int patternSize, vector<string>& wordRecords)
	{
		//create DFA of pattern
		vector<vector<int>> DFA(patternSize + 1, vector<int>(256, 0));
		DFA[0][pattern[0]] = 1;
		int X = 0;
		for (size_t i = 1; i < patternSize + 1; i++)
		{
			for (size_t c = 0; c < 256; c++)
				DFA[i][c] = DFA[X][c];
			if (i != patternSize)
			{
				DFA[i][pattern[i]] = i + 1;
				X = DFA[X][pattern[i]];
			}
		}
		//search pattern
		int j = 0;
		for (size_t i = 0; i < txt.size(); i++)
		{
			j = DFA[j][txt[i]];
			if (j == patternSize)
				wordRecords[i - patternSize + 1] = pattern;
		}
	}
};

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> results;
		// create all queries
		vector<int> nums;
		for (size_t i = 0; i < words.size(); i++)
			nums.push_back(i);
		vector<vector<int>> permutations;
		backtrace(permutations, nums, 0);
		set<string> querySet;
		for (auto indeVec:permutations)
		{
			string query = "";
			for (auto index : indeVec)
				query += words[index];
			querySet.insert(query);
		}
		// do KMP search on original s
		for (auto query:querySet)
		{
			vector<int> subResult = KMPsearch(s, query);
			results.insert(results.end(), subResult.begin(), subResult.end());
		}
		return results;
	}

	vector<int> KMPsearch(string& s, string& pattern)
	{
		vector<int> results;
		// create DFA
		int pSize = pattern.size();
		vector<vector<int>> DFA(pSize + 1, vector<int>(26, 0));
		DFA[0][pattern[0] - 'a'] = 1;
		int X = 0;
		for (size_t i = 1; i < pSize + 1; i++)
		{
			for (size_t c = 0; c < 26; c++)
				DFA[i][c] = DFA[X][c];
			if (i != pSize)
			{
				DFA[i][pattern[i] - 'a'] = i + 1;
				X = DFA[X][pattern[i] - 'a'];
			}
		}
		// do search
		int j = 0;
		for (size_t i = 0; i < s.size(); i++)
		{
			j = DFA[j][s[i] - 'a'];
			if (j == pSize)
				results.push_back(i - pSize + 1);
		}
		return results;
	}

	void backtrace(vector<vector<int>>& results, vector<int> nums, int index)
	{
		if (index == nums.size())
		{
			results.push_back(nums);
		}
		else
		{
			for (size_t i = index; i < nums.size(); i++)
			{
				swap(nums[i], nums[index]);
				backtrace(results, nums, index + 1);
				swap(nums[i], nums[index]);
			}
		}
	}
	
};

int main()
{
	Solution solution = Solution();
	string s = "pjzkrkevzztxductzzxmxsvwjkxpvukmfjywwetvfnujhweiybwvvsrfequzkhossmootkmyxgjgfordrpapjuunmqnxxdrqrfgkrsjqbszgiqlcfnrpjlcwdrvbumtotzylshdvccdmsqoadfrpsvnwpizlwszrtyclhgilklydbmfhuywotjmktnwrfvizvnmfvvqfiokkdprznnnjycttprkxpuykhmpchiksyucbmtabiqkisgbhxngmhezrrqvayfsxauampdpxtafniiwfvdufhtwajrbkxtjzqjnfocdhekumttuqwovfjrgulhekcpjszyynadxhnttgmnxkduqmmyhzfnjhducesctufqbumxbamalqudeibljgbspeotkgvddcwgxidaiqcvgwykhbysjzlzfbupkqunuqtraxrlptivshhbihtsigtpipguhbhctcvubnhqipncyxfjebdnjyetnlnvmuxhzsdahkrscewabejifmxombiamxvauuitoltyymsarqcuuoezcbqpdaprxmsrickwpgwpsoplhugbikbkotzrtqkscekkgwjycfnvwfgdzogjzjvpcvixnsqsxacfwndzvrwrycwxrcismdhqapoojegggkocyrdtkzmiekhxoppctytvphjynrhtcvxcobxbcjjivtfjiwmduhzjokkbctweqtigwfhzorjlkpuuliaipbtfldinyetoybvugevwvhhhweejogrghllsouipabfafcxnhukcbtmxzshoyyufjhzadhrelweszbfgwpkzlwxkogyogutscvuhcllphshivnoteztpxsaoaacgxyaztuixhunrowzljqfqrahosheukhahhbiaxqzfmmwcjxountkevsvpbzjnilwpoermxrtlfroqoclexxisrdhvfsindffslyekrzwzqkpeocilatftymodgztjgybtyheqgcpwogdcjlnlesefgvimwbxcbzvaibspdjnrpqtyeilkcspknyylbwndvkffmzuriilxagyerjptbgeqgebiaqnvdubrtxibhvakcyotkfonmseszhczapxdlauexehhaireihxsplgdgmxfvaevrbadbwjbdrkfbbjjkgcztkcbwagtcnrtqryuqixtzhaakjlurnumzyovawrcjiwabuwretmdamfkxrgqgcdgbrdbnugzecbgyxxdqmisaqcyjkqrntxqmdrczxbebemcblftxplafnyoxqimkhcykwamvdsxjezkpgdpvopddptdfbprjustquhlazkjfluxrzopqdstulybnqvyknrchbphcarknnhhovweaqawdyxsqsqahkepluypwrzjegqtdoxfgzdkydeoxvrfhxusrujnmjzqrrlxglcmkiykldbiasnhrjbjekystzilrwkzhontwmehrfsrzfaqrbbxncphbzuuxeteshyrveamjsfiaharkcqxefghgceeixkdgkuboupxnwhnfigpkwnqdvzlydpidcljmflbccarbiegsmweklwngvygbqpescpeichmfidgsjmkvkofvkuehsmkkbocgejoiqcnafvuokelwuqsgkyoekaroptuvekfvmtxtqshcwsztkrzwrpabqrrhnlerxjojemcxel";
	vector<string> words{ "dhvf","sind","ffsl","yekr","zwzq","kpeo","cila","tfty","modg","ztjg","ybty","heqg","cpwo","gdcj","lnle","sefg","vimw","bxcb" };
	auto results = solution.findSubstring(s, words);
	for (auto num:results)
	{
		std::cout << num << std::endl;
	}
	return 0;
}