/*��һ����ά�����У�ÿ��һά����ĳ�����ͬ����ÿһ�ж����մ����ҵ�����˳������
��ÿһ�ж����մ��ϵ��µ�����˳������
�����һ������������������һ����ά�����һ���������ж��������Ƿ��и�������
*/

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		int m = array.size();        //��ȡ��
		int n = array[0].size();     //��ȡ��
		int i = 0;                  //��ʼ��
		int j = n - 1;
		cout << m << "  "<<n<<endl;
		while (i<m && j>=0){
			cout << array[i][j] << endl;
			if (target > array[i][j]){      //Ŀ��������ұߵ�ֵ  ��+1
				i+=1;
			}
			else if (target < array[i][j]){  //Ŀ��С�����ұߵ�ֵ  ��-1
				j -= 1;
			}
			else {
				return true;
			}
		}
		return false;
	}

};
/*
int main(){

	vector<vector<int> > array = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 }, {3,5,18,20} };
	Solution S;
	
	if (S.Find(7, array)){
		cout << "Find it" << endl;

	}
	else{
		cout << "Not find" << endl;
	}
	system("pause");
	return 1;
}
*/