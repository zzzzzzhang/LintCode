#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    /**
     * @param nums: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &nums) {
        // write your code here
        for(int i = 0; i < nums.size() - 1; i++)
        {
        	if (nums[i+1] < nums[i])
        		return nums[i+1];
		}
		return nums[0];
    }
};
int main()
{
	Solution solve;
	vector<int> nums = {1, 2};
	int out = 0;
	out = solve.findMin(nums);
	cout<<out<<endl; 
	return 0;	
}
