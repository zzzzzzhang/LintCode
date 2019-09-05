#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    /**
     * @param A: an integer array
     * @return: nothing
     */
    void sortIntegers2(vector<int> &A) {
        // write your code here
        quickSort(A, 0, A.size()-1);
        
    }
private:
	void quickSort(vector<int> &A, int left, int right)
	{
//		for(int i = 0; i < A.size(); i ++)
//			cout<<A[i]<<" "; 
//		cout<<endl;
		if(left >= right) return;
        int temp = A[right];
        int i = left, j = right;
        while(i < j)
        {
//        	cout<<i<<" "<<j<<endl;
        	while(i < j && A[i] <= temp)
			{
//			cout<<i<<" "<<j<<endl; 
				i++;
			}
			if(i < j)
				{
					A[j] = A[i];
					j--;
				}
			while(i < j && A[j] >= temp)
			{
//			cout<<i<<" "<<j<<endl; 
				j--;
			}
			if(i < j)
				{
					A[i] = A[j];
					i++;
				}
		}
//		for(int i = 0; i < A.size(); i ++)
//			cout<<A[i]<<" ";
//		cout<<endl;
//		cout<<i<<" "<<j<<endl;
		A[i] = temp;
		quickSort(A, left, i-1);
		quickSort(A, i+1, right);
	}
};
int main()
{
	Solution solve;
	vector<int> input = {10,1,12,75,35,62,50,59};
	solve.sortIntegers2(input);
	for(int i = 0; i < input.size(); i ++)
		cout<<input[i]<<" "; 	
}
