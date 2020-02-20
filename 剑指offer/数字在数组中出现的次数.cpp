/*
ͳ��һ�����������������г��ֵĴ�����
*/
#include<iostream>
#include<vector>
using namespace std;

//��һ������  O(n)

class Solution {
public:
	int GetNumberOfK(vector<int> data, int k) {
		int len = data.size();
		if (len == 0){
			return 0;
		}
		int cnt = 0;
		for (int i = 0; i<len; i++){
			if (data[i] == k)
				cnt += 1;
		}
		return cnt;
	}
};
//��2������ ��¼�±�  O(n)



//������������ַ�����  O(logn)
class Solution2 {
public:
	int GetNumberOfK(vector<int> data, int k) {
		int len = data.size();
		if (len == 0){
			return 0;
		}
	}
private:
};
/*
int main(){
	vector<int> v = { 1, 2, 3, 3, 3, 3 };
	Solution2 S;
	cout << S.GetNumberOfK(v,3) << endl;


	system("pause");
	return 0;
}
*/
