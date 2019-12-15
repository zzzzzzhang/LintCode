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
    void dfs(vector<vector<int>> &result, vector<int> &tem, vector<int> &nums, int target, int k)
    {
    	if(target<0) return;
    	if(target == 0) 
		{
			result.push_back(tem);
			return;
		}
    	for(int i = k; i < nums.size(); ++i)
    	{
    		if(i>k && nums[i] == nums[i-1]) continue;
    		tem.push_back(nums[i]);
    		int t = target - nums[i];
    		if(t<0) 
			{
				tem.pop_back();
				return;
			}
    		dfs(result, tem, nums, t, i+1);
    		tem.pop_back();
		}
	}
    vector<vector<int>> combinationSum2(vector<int> &nums, int target) {
        // write your code here
        vector<vector<int>> res;
        vector<int> tem;
        sort(nums.begin(),nums.end());
        dfs(res, tem, nums, target, 0);
        return res;
    }
};
int main()
{
	Solution solove;
	vector<int> nums = {1,9,8,2};
	int target = 10;
	vector<vector<int>> out;
	out = solove.combinationSum2(nums, target);
	for(auto i: out)
	{
		for(auto j:i)
			cout<<j<<" ";
		cout<<endl;
	}
} 

