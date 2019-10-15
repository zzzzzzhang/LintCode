#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    /**
     * @param n: An integer
     * @param nums: An array
     * @return: the Kth largest element
     */
    int kthLargestElement(int n, vector<int> &nums) {
        // write your code here
    }
private:
	int partition(vector<int> &nums, int start, int end, int k){
		if (strat >= end) return nums[start];
		int pivot = nums[start];
		
	}
	void swap(vector<int> &nums, i, j){
		int a = nums[i];
		nums[i] = nums[j];
		nums[j] = a;
	}
}; 

int main()
{
	Solution solve;
	int k = 0, out = 0;
	vector<int> nums = {1,2,3,4,5};
	out = solve.kthLargestElement(k, nums);
	cout<<out<<endl;
}
