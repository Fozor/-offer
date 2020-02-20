/*
一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
*/

#include<iostream>
#include<vector>
#include<algorithm>   //sort
using namespace std;
//相同的数做异或=0 
class Solution{
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
		int length = data.size();
		if (length < 2){
			return;
		}

		// 对原始数组每个元素求异或
		int resultExclusiveOR = 0;
		for (int i = 0; i < length; ++i){
			resultExclusiveOR ^= data[i];
		}

		unsigned int indexOf1 = FindFirstBitIs1(resultExclusiveOR);

		*num1 = *num2 = 0;
		for (int j = 0; j < length; j++){
			if (IsBit1(data[j], indexOf1)){
				*num1 ^= data[j];
			}
			else{
				*num2 ^= data[j];
			}
		}
	}
private:
	// 找到二进制数num第一个为1的位数，比如0010，第一个为1的位数是2。
	unsigned int FindFirstBitIs1(int num){
		unsigned int indexBit = 0;

		while(num != 0){
			if (num & 1){
				break;
			}else{
				num = num >> 1;
				indexBit++;
			}
		}
		return indexBit;    //==位数-1
	}
	// 判断第indexBit位是否为1
	bool IsBit1(int num, unsigned int indexBit){
		num = num >> indexBit;
		return (num & 1);
	}
};
/*
int main(){
	vector<int>v = { 2, 4, 3, 6, 3, 2, 5, 5 };
	int n1, n2;
	Solution S;
	S.FindNumsAppearOnce(v,&n1,&n2);
	cout << n1 << "," << n2 << endl;
	system("pause");
	return 0;
}
*/