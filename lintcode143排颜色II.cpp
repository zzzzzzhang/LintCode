#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */
    void sortColors2(vector<int> &colors, int k) {
        // write your code here
        int c[k] = {0};
		for(int i = 0; i < colors.size(); i++)
        {
			c[colors[i]-1] += 1;
    	}
        int m = 0;
        for(int i = 0; i < k; i++)
        {
        	for(int j = 0; j<c[i]; j++)
        		colors[m++] = i+1;
    	}
    }
};
int main()
{
	Solution solve;
	vector<int> input = {2,1,1,2,2};
	int k = 2;
	solve.sortColors2(input, k);
	for(int i = 0; i < input.size();i++)
		cout<<input[i]<<" ";
	return 0;
}
