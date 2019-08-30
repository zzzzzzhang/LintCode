#include<unordered_map>
#include<string>
#include<iostream> 
using namespace std;


class Solution {
public:
    /**
     * @param s: a string which consists of lowercase or uppercase letters
     * @return: the length of the longest palindromes that can be built
     */
    int longestPalindrome(string &s) 
	{
        int k = 0;
        int n = s.length();
		unordered_map <char, int> str_num; 
        for(int i = 0; i < n; i++)
        {
			if (str_num.count(s[i]) == 0)
            {
				str_num[s[i]] = 1;
			}
			else if (str_num[s[i]]== 0)
			{
				str_num[s[i]] = 1;
			}
			else if (str_num[s[i]] == 1)
			{
				str_num[s[i]] = 0;
				k += 2;
			}
        }
        if(k < s.length()) 
		{
			k++;
		}
        return k;
    }
};
int main()
{
	int m = 0;
	Solution solve;
	string s = "abcdadce";
	m = solve.longestPalindrome(s);
	cout<<"最长回文字符串长度："<< m <<endl;
	
	return 0;
}


