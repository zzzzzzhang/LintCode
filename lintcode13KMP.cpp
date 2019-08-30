#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    /**
     * @param source: 
     * @param target: 
     * @return: return the index
     */
    int strStr(string &source, string &target) {
        // Write your code here
        int n = source.length();
        int m = target.length();
        int k = -1;
        bool flag = 1;
        if (source == "" && target == "")
        {
        	return 0;
		}
        for(int i = 0; i < n; i++)
        {
        	flag = 1;
        	for(int j = 0; j < m; j++)
        	{
        		if (target[j] != source[i + j])
        		{
        			cout<<source[i + j]<<" "<<target[j]<<endl;
        			flag = 0;
					break;
				}	
			}
			if (flag)
			{
				k = i;
				return k;
			}
		}
		return k;
    }
};

int main()
{
	Solution solve;
	int k = -1;
	string source = "";
	string taget = "";
	k = solve.strStr(source, taget);
	cout<<"Î»ÖÃ£º"<<k<<endl;
	return 0;
}
