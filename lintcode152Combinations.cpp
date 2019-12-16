#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    /**
     * @param num: Given the candidate numbers
     * @param target: Given the target number
     * @return: All the combinations that sum to target
     */
    void dfs(vector<vector<int>> &result, vector<int> &tem, int n, int k, int start)
    {
    	if(k == 0) 
		{
			result.push_back(tem);
			return;
		}
    	for(int i = start; i <= n; ++i)
    	{
    		tem.push_back(i);
    		int _k = k-1;
    		dfs(result, tem, n, _k, ++start);
    		tem.pop_back();
		}
	}
    vector<vector<int>> combine(int n, int k) {
        // write your code here
        vector<vector<int>> res;
        vector<int> tem;
        dfs(res, tem, n, k, 1);
        return res;
    }
};
int main()
{
	Solution solove;
	int n = 4;
	int k = 2;
	vector<vector<int>> out;
	out = solove.combine(n, k);
	for(auto i: out)
	{
		for(auto j:i)
			cout<<j<<" ";
		cout<<endl;
	}
} 

