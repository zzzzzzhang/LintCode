#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;
class Solution {
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @return: Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int>> threeSum(vector<int> &numbers) {
        // write your code here
    }
};
int main()
{
	Solution solve;
	vector<int> input = {-1,0,1,2,-1,-4};
	vector<vector<int>> out = {};
//	out = solve.threeSum(input);
	out = {{1,2},{1,2}};
	for(int i = 0; i < out.size(); i++)
	{
	for(int j = 0; j < out[0].size(); j++)
		cout<<out[i][j]<<" ";
	cout<<endl;
	}
	return 0;
}
