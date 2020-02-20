/*
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
*/
#include<iostream>
#include<vector>
#include<set>
using namespace std;
//法1:简单 耗时长
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
//法2：加入二分查找思想,速度快
class Solution2 {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		int size = rotateArray.size();                            //数组长度
		if (size == 0){
			return 0;
		}
		int left = 0;                                            //左指针
		int right = size - 1;                                    //右指针
		int mid = 0;                                            //中间指针
		while (rotateArray[left] >= rotateArray[right]){            //确保旋转
			if (right - left == 1){                                //左右指针相邻
				mid = right;
				break;
			}
			mid = left + (right - left) / 2;                    //计算中间指针位置
			//特殊情况：如果无法确定中间元素是属于前面还是后面的递增子数组，只能顺序查找
			if (rotateArray[left] == rotateArray[right] && rotateArray[mid] == rotateArray[left]){
				return MinInOrder(rotateArray, left, right);
			}
			//中间元素位于前面的递增子数组，此时最小元素位于中间元素的后面
			if (rotateArray[mid] >= rotateArray[left]){
				left = mid;
			}
			//中间元素位于后面的递增子数组，此时最小元素位于中间元素的前面
			else{
				right = mid;
			}
		}
		return rotateArray[mid];
	}
private:
	//顺序寻找最小值
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