#include<iostream>
#include<string>
#include<vector> 
 
using namespace std;
 
void Move(int n, char A, char B, char C)
{
	if (n == 1)
	{
		//Բ��ֻ��һ��ʱ��ֻ�轫���A���Ƶ�C��
		cout << "move " << n << " from " << A << " to " << C << endl;
	}
	else
	{
		Move(n - 1, A, C, B);//�ݹ飬��A���ϱ��1~n-1��Բ���Ƶ�B�ϣ���CΪ������
		cout << "move " << n << " from " << A << " to " << C << endl;//��A���ϱ��Ϊn��Բ���Ƶ�C��
		Move(n - 1, B, A, C);//�ݹ飬��B���ϱ��1~n-1��Բ���Ƶ�C�ϣ���AΪ������
	}
}
 
void Hanoi(int n)
{
	if (n <= 0)
		return;
	Move(n, 'A', 'B', 'C');
}
 
int main()
{
	Hanoi(3);
	return 0;
}
