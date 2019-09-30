#include<iostream>
#include<vector>
using namespace std;
 
class Solution {
public:
    /**
     * @param nums: The integer array you should partition
     * @param k: An integer
     * @return: The index after partition
     */
    int partitionArray(vector<int> &nums, int k) {
        // write your code here
        int l = nums.size();
        if(l == 0)
        	return 0;
		int arr[l] = {0};
		int a = 0, b = l-1;
		for (int i = 0; i < l; i++)
		{
			if (nums[i] < k)
				arr[a++] = nums[i];
			else 
				arr[b--] = nums[i];
		}
		return a;
    }
};

int main()
{
	Solution solve;
	vector<int> nums = {3,2,2,1};
	int k = 2, out = 0;
	out = solve.partitionArray(nums, k);
	cout<<out<<endl;
 } 
