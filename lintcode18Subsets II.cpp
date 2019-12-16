#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    /**
     * @param nums: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    void dfs(vector<vector<int>> &res, vector<int> &tem, vector<int> &nums, int start)
    {
    	int n = nums.size();
    	if(start == n && find(res.begin(), res.end(), tem) == res.end())
    	{
    		res.push_back(tem);
    		return;
		}
		if(find(res.begin(), res.end(), tem) == res.end())
		{
			res.push_back(tem);
		}
		for(int i = start; i < n; ++i)
		{
			tem.push_back(nums[i]);
			dfs(res, tem, nums, i + 1);
			tem.pop_back();
		}
	}
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        // write your code here
        vector<vector<int>> res = {{}};
        vector<int> tem;
        sort(nums.begin(),nums.end());
        dfs(res, tem, nums, 0);
		return res;
    }
};
int main()
{
	Solution solove;
	vector<int> nums = {0,1,3,4,4,5};
	vector<vector<int>> out;
	out = solove.subsetsWithDup(nums);
	for(auto i: out)
	{
		for(auto j:i)
			cout<<j<<" ";
		cout<<endl;
	}
} 
