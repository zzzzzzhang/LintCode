#include<vector>
#include<iostream>
using namespace std;
 
class Solution {
public:
    /**
     * @param nums: a mountain sequence which increase firstly and then decrease
     * @return: then mountain top
     */
    int mountainSequence(vector<int> &nums) {
        // write your code here
		if(nums.size() == 1)
			return nums[0];
		for(int i = 1; i < nums.size(); i++)
		{if(nums[i - 1] > nums[i])
			return nums[i - 1]; 
		}        
    }
};
int main()
{
	Solution solve;
	int max = 0;
	vector<int> a = {5}; 
	max = solve.mountainSequence(a);
	cout<<"·å£º"<<max<<endl; 
}
