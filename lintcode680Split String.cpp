#include<string>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    /*
     * @param : a string to be split
     * @return: all possible split string array
     */
    void help(vector<vector<string>> &result, vector<string> &path, string &s, int k)
    {
    	if(s.size() == k)
    	{
    		result.push_back(path);
    		return;
		}
		if(s.size() < k) return;
    	string str = s.substr(k, 1);
    	path.push_back(str);
    	help(result, path, s, k+1);
//		cout<<path.size()<<endl;
    	path.pop_back();
    	str = s.substr(k, 2);
    	path.push_back(str);
    	help(result, path, s, k+2);
    	path.pop_back();
    	for(auto p:path) cout<<p;
    	cout<<endl;
    	return;
	}
    vector<vector<string>> splitString(string& s) {
        // write your code here
        vector<vector<string>> result;
        vector<string> path;
        help(result, path, s, 0);
        return result;
    }
};
int main()
{
	Solution solove;
	string s = "abcde";
	vector<vector<string>> out;
	out = solove.splitString(s);
	for(auto i: out)
	{
		for(auto j:i)
			cout<<j<<" ";
		cout<<endl;
	}
} 
