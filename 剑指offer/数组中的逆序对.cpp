/*
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007
*/

#include<iostream>
#include<vector>
using namespace std;

//失败  ，暴力，通过率50%   运行超时  说明时间复杂度过高O(n2）  需要用归并排序O(nlogn)
class Solution {
public:
	int InversePairs(vector<int> data) {
		long len = data.size();
		if (len <= 1){
			return 0;
		}
		long cnt = 0;
		for (long i = 0; i < len - 1; i++){
			for (long j = i + 1; j < len; j++){
				if (data[i]>data[j]){
					cnt += 1;
				}
			}
		}
		return cnt % 1000000007;
	}
};

//

class Solution {
public:
	int InversePairs(vector<int> data) {
		if (data.size() == 0){
			return 0;
		}
		// 排序的辅助数组
		vector<int> copy;
		for (int i = 0; i < data.size(); ++i){
			copy.push_back(data[i]);
		}
		return InversePairsCore(data, copy, 0, data.size() - 1) % 1000000007;
	}
	long InversePairsCore(vector<int> &data, vector<int> &copy, int begin, int end){
		// 如果指向相同位置，则没有逆序对。
		if (begin == end){
			copy[begin] = data[end];
			return 0;
		}
		// 求中点
		int mid = (end + begin) >> 1;
		// 使data左半段有序，并返回左半段逆序对的数目
		long leftCount = InversePairsCore(copy, data, begin, mid);
		// 使data右半段有序，并返回右半段逆序对的数目
		long rightCount = InversePairsCore(copy, data, mid + 1, end);

		int i = mid; // i初始化为前半段最后一个数字的下标
		int j = end; // j初始化为后半段最后一个数字的下标
		int indexcopy = end; // 辅助数组复制的数组的最后一个数字的下标
		long count = 0; // 计数，逆序对的个数，注意类型

		while (i >= begin && j >= mid + 1){
			if (data[i] > data[j]){
				copy[indexcopy--] = data[i--];
				count += j - mid;
			}
			else{
				copy[indexcopy--] = data[j--];
			}
		}
		for (; i >= begin; --i){
			copy[indexcopy--] = data[i];
		}
		for (; j >= mid + 1; --j){
			copy[indexcopy--] = data[j];
		}
		return leftCount + rightCount + count;
	}
};

/*
int main(){
	Solution S;
	vector<int>v = { 1, 2, 3, 4, 5, 6, 7, 0 };
	cout << S.InversePairs(v) << endl;
	system("pause");
	return 0;
}*/