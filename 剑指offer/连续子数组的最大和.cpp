/*
HZż������Щרҵ������������Щ�Ǽ����רҵ��ͬѧ��
��������鿪����,���ַ�����:�ڹ��ϵ�һάģʽʶ����,������Ҫ��������������������,������ȫΪ������ʱ��,����ܺý����
����,��������а�������,�Ƿ�Ӧ�ð���ĳ������,�������Աߵ��������ֲ����أ�����:{6,-3,-2,7,-15,1,2,2},����������������Ϊ8(�ӵ�0����ʼ,����3��Ϊֹ)��
��һ�����飬��������������������еĺͣ���᲻�ᱻ������ס��(�������ĳ���������1)
*/

#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		int len = array.size();
		if (len == 0){
			return 0;
		}
		int sum = array[0];  //��ʼ��Ϊ array[0]
		int summax=array[0];
		for (int i = 1; i < len; i++){
			if (sum <= 0){
				sum = array[i];
			}
			else{
				sum += array[i];
			}
			if (sum > summax){
				summax = sum;
			}
		}
		return summax;
	}
};
/*
int main(){
	Solution S;
	vector<int> v = { 1, -2, 3, 10, -4, 7, 2, -5 };
	cout << S.FindGreatestSumOfSubArray(v)<<endl;
	system("pause");
	return 0;
}
*/