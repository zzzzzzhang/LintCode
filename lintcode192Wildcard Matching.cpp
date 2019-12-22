#include<vector>
#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "?" and "*"
     * @return: is Match?
     */
    bool isMatch(string &s, string &p) {
    	int m = s.size(), n = p.size(), star = -1, i = 0, j = 0, index = -1;
    	while(i < m)
    	{
    		if(j < n &&(s[i] == p[j] || p[j] == '?')) i++,j++;
    		else if(j < n && p[j] == '*') star = j++, index = i;
    		else if(star != -1) i = ++index, j = star + 1;
    		else return false;
		}
		while(j < n && p[j] == '*') ++j;
		return j == n;
	}
};
int main()
{
	Solution solve;
	string s = "aabaab";
	string p = "*?";
	auto out = solve.isMatch(s, p);
	cout<<out<<endl;
} 
