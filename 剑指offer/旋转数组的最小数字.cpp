/*
��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
����һ���ǵݼ�����������һ����ת�������ת�������СԪ�ء�
��������{3,4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת�����������СֵΪ1��
NOTE������������Ԫ�ض�����0���������СΪ0���뷵��0��
*/
#include<iostream>
#include<vector>
#include<set>
using namespace std;
//��1:�� ��ʱ��
class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.size() == 0)
			return 0;
		set<int>myset;
		for (int i = 0; i<rotateArray.size(); ++i){
			myset.insert(rotateArray[i]);
		}
		int result= *myset.begin();
		return result;
	}
};
//��2��������ֲ���˼��,�ٶȿ�
class Solution2 {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		int size = rotateArray.size();                            //���鳤��
		if (size == 0){
			return 0;
		}
		int left = 0;                                            //��ָ��
		int right = size - 1;                                    //��ָ��
		int mid = 0;                                            //�м�ָ��
		while (rotateArray[left] >= rotateArray[right]){            //ȷ����ת
			if (right - left == 1){                                //����ָ������
				mid = right;
				break;
			}
			mid = left + (right - left) / 2;                    //�����м�ָ��λ��
			//�������������޷�ȷ���м�Ԫ��������ǰ�滹�Ǻ���ĵ��������飬ֻ��˳�����
			if (rotateArray[left] == rotateArray[right] && rotateArray[mid] == rotateArray[left]){
				return MinInOrder(rotateArray, left, right);
			}
			//�м�Ԫ��λ��ǰ��ĵ��������飬��ʱ��СԪ��λ���м�Ԫ�صĺ���
			if (rotateArray[mid] >= rotateArray[left]){
				left = mid;
			}
			//�м�Ԫ��λ�ں���ĵ��������飬��ʱ��СԪ��λ���м�Ԫ�ص�ǰ��
			else{
				right = mid;
			}
		}
		return rotateArray[mid];
	}
private:
	//˳��Ѱ����Сֵ
	int MinInOrder(vector<int> &num, int left, int right){
		int result = num[left];
		for (int i = left + 1; i < right; i++){
			if (num[i] < result){
				result = num[i];
			}
		}
		return result;
	}
};

/*
int main(){
	Solution S2;
	vector<int> arr = { 3, 4, 5, 1, 2 };
	cout << S2.minNumberInRotateArray(arr) << endl;
	system("pause");
	return 0;


}
*/