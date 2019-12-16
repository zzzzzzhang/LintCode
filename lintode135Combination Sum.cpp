#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target: An integer
     * @return: A list of lists of integers
     */
    void dfs(vector<vector<int>> &res, vector<int> &tem, vector<int> &candidates, int target, int start)
    {
    	if(target < 0) return;
    	if(target == 0)
    	{
    		res.push_back(tem);
    		return;
		}
		for(int i = start; i < candidates.size(); ++i)
		{
			if(i>start && candidates[i] == candidates[i-1]) continue;
			tem.push_back(candidates[i]);
			int _target = target - candidates[i];
			dfs(res, tem, candidates, _target, i);
			tem.pop_back();
		}
	}
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        // write your code here
        sort(candidates.begin(), candidates.end());
        vector<int> tem;
        vector<vector<int>> res;
        dfs(res, tem, candidates, target, 0);
        return res;
    }
};
int main()
{
	Solution solove;
	vector<int> nums = {1,9,8,2,10};
	int target = 10;
	vector<vector<int>> out;
	out = solove.combinationSum(nums, target);
	for(auto i: out)
	{
		for(auto j:i)
			cout<<j<<" ";
		cout<<endl;
	}
} 
