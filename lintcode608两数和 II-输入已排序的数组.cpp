#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;
class Solution {
public:
    /**
     * @param nums: an array of Integer
     * @param target: target = nums[index1] + nums[index2]
     * @return: [index1 + 1, index2 + 1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        // write your code here
        vector<int> out = {};
		unordered_map<int,int> data;
        for(int i = 0; i < nums.size(); i++)
        {
        	if(data.count(target - nums[i]) > 0)
        	{
				out.push_back(data[target - nums[i]]);
        		out.push_back(i+1);
        	}
        	else
        		data[nums[i]] = i+1;
		}
		return	out;
    }
};
int main()
{
	Solution solve;
	vector<int> input = {2, 3};
	int target = 5;
	vector<int> out;
	out = solve.twoSum(input, target);
	for(int i = 0; i<out.size(); i++)
	cout<<out[i]<<" ";
}
