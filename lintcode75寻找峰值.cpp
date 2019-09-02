#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> &A) {
        // write your code here
        int i = 0, j = A.size() - 1;
        while(i < A.size() || j>0)
        {
        	if(A[i] > A[i + 1])
        		return i;
        	else
        		i++;
        	if(A[j] > A[j - 1])
        		return j;
        	else
        		j--;
		}
    }
}; 
int main()
{
	Solution solve;
	int out = 0;
	vector<int> A = {1,1,2,3,4,5,7,6};
	out = solve.findPeak(A);
	cout<<"½á¹ûÊÇ£º"<<out<<endl; 
	return 0;	
}
