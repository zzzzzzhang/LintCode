#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    /**
     * @param A: an integer rotated sorted array
     * @param target: an integer to be searched
     * @return: an integer
     */
    int search(vector<int> &A, int target) {
        // write your code here
        int start = 0, end = A.size()-1;
        int mid = (start + end)/2;
        bool flag = 1;
        if (target > A[A.size() - 1])
        	flag = 0;
        if (flag)
        {
        	while (start < end -1)
        	{
	        	if (A[mid] < A[A.size() -1])
	        	{
	        		if(A[mid] < target)
	        			{
	        				
						}
				}
				else
				{
					start = mid;
					mid = (start + end)/2;
				}
			}
		}

    }
}; 

