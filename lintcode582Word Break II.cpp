#include<vector>
#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    /*
     * @param s: A string
     * @param wordDict: A set of words.
     * @return: All possible sentences.
     */
    vector<string> wordBreak(string &s, unordered_set<string> &wordDict) {
        // write your code here
    }
};

int main()
{
	Solution solve;
	vector<int> nums = {1,2};
	auto out = solve.subsets(nums);
	for(auto v:out)
	{
		for(auto i:v)
			cout<<i<<" ";
		cout<<endl;
	}
} 
