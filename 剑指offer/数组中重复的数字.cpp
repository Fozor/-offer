/*
��һ������Ϊn����������������ֶ���0��n-1�ķ�Χ�ڡ� 
������ĳЩ�������ظ��ģ�����֪���м����������ظ��ġ�
Ҳ��֪��ÿ�������ظ����Ρ����ҳ�����������һ���ظ������֡�
���磬������볤��Ϊ7������{2,3,1,0,2,5,3}����ô��Ӧ������ǵ�һ���ظ�������2��
*/

#include<iostream>
#include<algorithm>   //swap

using namespace std;

class Solution {
public:

	bool duplicate(int numbers[], int length, int* duplication) {
		// �Ƿ�����
		if (numbers == NULL || length <= 0){
			return false;
		}
		//�Ƿ�����
		for (int i = 0; i < length; i++){
			if (numbers[i] < 0 || numbers[i] > length - 1){
				return false;
			}
		}
		// �������ҵ�һ���ظ�����
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