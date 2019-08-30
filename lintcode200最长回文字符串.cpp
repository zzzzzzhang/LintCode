#include<string>
#include<iostream>
#include <cctype>
using namespace std;
class Solution {
public:
    /**
     * @param s: input string
     * @return: the longest palindromic substring
     */
    string longestPalindrome(string &s) {
        // write your code here
        string str = "", ans = "";
        int len = s.length();
        int max = 0 ,count = 0;
        for (int i = 0; i < len; i++)
        {
        	str += "#";
        	str += s[i];
        }
        str += "#";
    	cout<<str<<endl;
    	for (int i = 0; i < str.length() - 1; i++)
		{
			count = 0;
			while((i - count >=0) && (i + count <= str.length()) && (str[i - count] == str[i + count]))
				{
					cout<<i<<" "<<count<<" "<<str[i - count]<<" "<<str[i + count]<<endl;
					count++;
//					cout<<i<<" "<<count<<" "<<str[i - count]<<" "<<str[i + count]<<endl;
				}
			count--;
			if (count > max)
				{
				max = count;
				ans = s.substr((i - count)/2, (i + count)/2 - (i - count) / 2);
				}
				
		}
		return ans;
	}
};
int main()
{
	Solution solve;
	string ans = "";
//	string s = "aba";
	string s = "abcdzdcab";
	ans = solve.longestPalindrome(s);
	cout<<ans<<endl;
	return 0;
 } 
