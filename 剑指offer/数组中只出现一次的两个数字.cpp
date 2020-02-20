/*
һ�����������������������֮�⣬���������ֶ����������Ρ���д�����ҳ�������ֻ����һ�ε����֡�
*/

#include<iostream>
#include<vector>
#include<algorithm>   //sort
using namespace std;
//��ͬ���������=0 
class Solution{
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
		int length = data.size();
		if (length < 2){
			return;
		}

		// ��ԭʼ����ÿ��Ԫ�������
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
	// �ҵ���������num��һ��Ϊ1��λ��������0010����һ��Ϊ1��λ����2��
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
		return indexBit;    //==λ��-1
	}
	// �жϵ�indexBitλ�Ƿ�Ϊ1
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