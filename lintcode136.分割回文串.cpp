#include<string>
#include<vector>
#include<iostream>
#include<typeinfo>
using namespace std;

class Solution {
public:
    /*
     * @param : a string to be split
     * @return: all possible split string array
     */
    bool isPalindrome(const string &s)
    {
    	for(int l = 0, r = s.size() - 1; l < r; l++, r--)
    		if(s[l] != s[r]) return false;
    	return true;
	}
    void dfs(vector<vector<string>> &result, vector<string> &path, const string &s)
    {
    	int n = s.size();
  		if(0 == n)
		{
			result.push_back(path);
			return;
  		}
  		for(int i = 0; i<n; ++i)
  		{
  			if(isPalindrome(s.substr(0,i+1)))
  			{
  				path.push_back(s.substr(0,i+1));
  				dfs(result, path, s.substr(i+1));
  				path.pop_back();
			}
		}
	}
    vector<vector<string>> partition(string &s) {
        // write your code here
        vector<vector<string>> result;
        vector<string> path;
        dfs(result, path, s);
        return result;
    }
};
int main()
{
	Solution solove;
	string s = "ababcde";
	vector<vector<string>> out;
	out = solove.partition(s);
	for(auto i: out)
	{
		for(auto j:i)
			cout<<j<<" ";
		cout<<endl;
	}
} 
