/*
��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
��������һ������Ϊ9������{1,2,3,2,2,2,5,4,2}����������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2����������������0��
*/
#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		map<int, int>mmap;
		int len = numbers.size();
		if (len == 0){
			return 0;
		}
		for (int i = 0; i<len; i++){
			mmap[numbers[i]] += 1;
		}
		map<int, int>::iterator it;
		for (it = mmap.begin(); it != mmap.end(); it++){
			if (it->second>(len / 2)){
				return it->first;
			}
		}
		return 0;
	}
};
//��2 ������ ���ü�����־λ���ʣ�µ������ǳ��ִ���������
class Solution2 {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int result=numbers[0];
		int flag = 1;
		for (int i = 1; i < numbers.size(); i++){
			if (result == numbers[i]){
				flag += 1;
			}
			else{
				flag -= 1;
			}
			if (flag <= 0){
				result = numbers[i];
			}
		}
		int cnt=0;
		for (int i = 0; i < numbers.size(); i++){
			if (numbers[i] == result){
				cnt += 1;
			}
		}
		if (cnt>(numbers.size() / 2)){
			return result;
		}
		else{
			return 0;
		}
	}
};
/*
int main(){
	Solution2 S;
	vector<int> num = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
	cout << S.MoreThanHalfNum_Solution(num) << endl;
	system("pause");
	return 0;
}
*/