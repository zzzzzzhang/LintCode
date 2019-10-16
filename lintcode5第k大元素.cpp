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
        return partition(nums, 0, nums.size()-1, nums.size()-n);
    }
private:
	int partition(vector<int> &nums, int start, int end, int k){
		if (start >= end) return nums[k];
		int pivot = nums[start];
		int i = start, j = end;
		while(i < j){
			while(nums[i] < pivot && i < j) i++;
			while(nums[j] > pivot && i < j) j--;
			if (i < j) swap(nums, i , j);
		}
		nums[i] = pivot;
		if (k < i) return partition(nums, start, i-1, k);
		if (k > i) return partition(nums, i+1, end, k);
		return nums[k];
	}
	void swap(vector<int> &nums, int i, int j){
		int a = nums[i];
		nums[i] = nums[j];
		nums[j] = a;
	}
}; 

int main()
{
	Solution solve;
	int k = 5, out = 0;
	vector<int> nums = {100,1,2,11,4,5,10,321,4412,5315,7645,6463443,75445235,846435};
	out = solve.kthLargestElement(k, nums);
	cout<<out<<endl;
}
