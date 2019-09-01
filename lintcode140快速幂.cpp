#include<iostream>
#include<cmath>
using namespace std;
class Solution {
public:
    /*
     * @param a, b, n: 32bit integers
     * @return: An integer
     */
    int fastPower(int a, int b, int n) 
	{
        if (n == 0) 
		{
            return 1;
        }
        if (n == 1) 
		{
            return a % b;
        }
        long long temp = 0;
        cout<<"¢Ù "<< n <<endl;
		temp = fastPower(a, b, n / 2);
        if (n % 2 == 0) 
        {
			cout<<"¢Ú "<< n << "  " <<(temp * temp) % b<<endl;
            return (temp * temp) % b;
        } 
		else 
		{
			cout<<"¢Û "<< n << "  " <<((temp * temp) % b * a) % b<<endl;
            return ((temp * temp) % b * a) % b;
        }
    }
};
int main()
{
	Solution solve;
	int a = 54, b = 100, n = 30, out = 0;
	out = solve.fastPower(a, b, n);
	cout<<"½á¹ûÊÇ£º"<<out<<endl; 
	return 0;	
}
