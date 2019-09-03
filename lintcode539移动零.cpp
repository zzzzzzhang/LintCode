#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    /**
     * @param nums: an integer array
     * @return: nothing
     */
    void moveZeroes(vector<int> &nums) {
        // write your code here
        int left = 0, right = 0;
        while(right < nums.size())
        {
        	if (nums[right] == 0)
        	{
				right++;
	        	continue;
        	}
			else
        	{
				int temp = nums[left];
				nums[left] = nums[right];
				nums[right] = temp;
				right++;
				left++;
        	}
		}
    }
};
int main()
{
	Solution solve;
	vector<int> nums = {0, 1, 0, 3, 12};
	solve.moveZeroes(nums);
	for (int i = 0; i < nums.size(); i++)
		cout<<nums[i]<<endl;
}
