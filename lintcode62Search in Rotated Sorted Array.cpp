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
        if(A.empty())
        return -1;
        int start = 0, end = A.size()-1;
        int mid = (start + end)/2;
        bool flag = 1;
        if (target > A[A.size() - 1])
        	flag = 0;
        if (flag)
        {
        	while (start < end -1)
        	{
        		cout<<A[start]<<" "<<A[end]<<" "<<mid<<endl;
        		if (A[mid] == target)
        			return mid;
	        	if (A[mid] < A[A.size() -1])
	        	{
	        		if(A[mid] < target)
	        		{
        				start = mid;
						mid = (start + end)/2;	
					}
					else
					{
						end = mid;
						mid = (start + end)/2;
					}
				}
				else
				{
					start = mid;
					mid = (start + end)/2;
				}
			}
		}
		else
		{
			while (start < end -1)
        	{
        		cout<<A[start]<<" "<<A[end]<<" "<<mid<<endl;
        		if (A[mid] == target)
        			return mid;
	        	if (A[mid] < A[A.size() -1])
	        	{
        			end = mid;
					mid = (start + end)/2;	
				}
				else
				{
					if(A[mid] < target)
	        		{
        				start = mid;
						mid = (start + end)/2;	
					}
					else
					{
						end = mid;
						mid = (start + end)/2;
					}
				}
			}
		}
		if (A[start] == target)
		return start;
		else if (A[end] == target)
		return end;
		else
		return -1;
	}
}; 

int main()
{
	Solution solve;
	vector<int> A = {6,8,9,1,3,5};
	int target = 5, out = -1;
	out = solve.search(A, target);
	cout<<"½á¹ûÊÇ£º"<<out<<endl;
	return 0;
}














