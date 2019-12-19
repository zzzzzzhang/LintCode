#include<vector>
#include<string>
#include<iostream>
#include<unordered_set>
using namespace std;

class Solution {
public:
    /*
     * @param s: A string
     * @param wordDict: A set of words.
     * @return: All possible sentences.
     */
//    unordered<string> = {};
    void dfs(vector<string> &res, string &tem, const string &s, unordered_set<string> &wordDict)
    {
    	int n = s.size();
    	if(s.empty())
    	{
    		res.push_back(tem);
    		return;
		}
		for(int i = 1; i <= n; ++i)
		{
			if(wordDict.find(s.substr(0, i)) != wordDict.end())
			{
				int flag = 0;
				if(!tem.empty()) tem +=" ", flag = 1; 
				tem += s.substr(0, i);
				dfs(res, tem, s.substr(i), wordDict);
				tem = tem.substr(0, tem.size() - flag - i);
			}
		}
	}
    vector<string> wordBreak(string &s, unordered_set<string> &wordDict) {
        // write your code here
        vector<string> res;
		string tem;
		dfs(res, tem, s, wordDict);
		return res; 
    }
};

int main()
{
	Solution solve;
	unordered_set<string> wordDict = {"a", "b","c","ab", "bc", "d"};
	string s = "aabc";
	auto out = solve.wordBreak(s, wordDict);
	for(auto i:out)
	{
		cout<<"res: "<<i<<endl;
	}
//	cout<<s.substr(0,0);
} 
