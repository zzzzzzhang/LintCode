#include<string>
#include<iostream>
#include <cctype>
using namespace std;

class Solution {
public:
    /**
     * @param s: A string
     * @return: Whether the string is a valid palindrome
     */
    bool isPalindrome(string &s) {
        // write your code here
    	int i = 0;
    	int j = s.length() - 1;
    	while(i<j)
    	{
//    		cout<<i<< " " <<j<<endl;
    		char str_1 = ' ', str_2 = ' ';
    		while(i<j)
		 	{
			 if(isalpha(s[i]))
			 	{
				str_1 = tolower(s[i]); 
			 	break;
			 	}
			 else if(isdigit(s[i]))
			 	{str_1 = s[i];
			 	break;
			 	}
			 else
			 	i++;
			}
			while(i<j)
			{
			 if(isalpha(s[j]))
			 	{
				str_2 = tolower(s[j]);
				break;
				}
			 else if(isdigit(s[j]))
			 	{
				str_2 = s[j];
			 	break;
			 	} 
			 else
			 	j--;	
			}
			if (i == j)
				return true;
			cout<<str_1<<" "<<str_2<<endl;
			if(str_1 != str_2)
				return false;
			i++;
			j--;
		}
		return true;
	}
};
int main()
{
	Solution solve;
	bool flag = 0;
	string s = "a.";
//	string s = "A man, a plan, a canal: Panama";
	flag = solve.isPalindrome(s);
	cout<<flag<<endl;
	return 0;
 } 
