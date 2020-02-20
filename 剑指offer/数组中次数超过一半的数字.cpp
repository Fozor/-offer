/*
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
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
//法2 ：遍历 设置计数标志位最后剩下的数就是出现次数最多的数
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