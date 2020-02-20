/*
在一个长度为n的数组里的所有数字都在0到n-1的范围内。 
数组中某些数字是重复的，但不知道有几个数字是重复的。
也不知道每个数字重复几次。请找出数组中任意一个重复的数字。
例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。
*/

#include<iostream>
#include<algorithm>   //swap

using namespace std;

class Solution {
public:

	bool duplicate(int numbers[], int length, int* duplication) {
		// 非法输入
		if (numbers == NULL || length <= 0){
			return false;
		}
		//非法输入
		for (int i = 0; i < length; i++){
			if (numbers[i] < 0 || numbers[i] > length - 1){
				return false;
			}
		}
		// 遍历查找第一个重复的数
		for (int i = 0; i < length; i++){
			while (numbers[i] != i){
				if (numbers[i] == numbers[numbers[i]]){
					*duplication = numbers[i];
					return true;
				}
				swap(numbers[i], numbers[numbers[i]]);
			}
		}
		return false;
	}

};
/*
int main(){
	int  v[] = { 2, 3, 1, 0, 2, 5, 3 };
	Solution  S;
	int len=sizeof(v)/sizeof(int);
	int duplication=0;
	S.duplicate(v, len, &duplication);
	cout << duplication << endl;

	system("pause");
	return 0;
}
*/