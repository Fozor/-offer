/*
�������е��������֣����ǰ��һ�����ִ��ں�������֣����������������һ������ԡ�
����һ������,�����������е�����Ե�����P������P��1000000007ȡģ�Ľ������� �����P%1000000007
*/

#include<iostream>
#include<vector>
using namespace std;

//ʧ��  ��������ͨ����50%   ���г�ʱ  ˵��ʱ�临�Ӷȹ���O(n2��  ��Ҫ�ù鲢����O(nlogn)
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
		// ����ĸ�������
		vector<int> copy;
		for (int i = 0; i < data.size(); ++i){
			copy.push_back(data[i]);
		}
		return InversePairsCore(data, copy, 0, data.size() - 1) % 1000000007;
	}
	long InversePairsCore(vector<int> &data, vector<int> &copy, int begin, int end){
		// ���ָ����ͬλ�ã���û������ԡ�
		if (begin == end){
			copy[begin] = data[end];
			return 0;
		}
		// ���е�
		int mid = (end + begin) >> 1;
		// ʹdata�������򣬲�������������Ե���Ŀ
		long leftCount = InversePairsCore(copy, data, begin, mid);
		// ʹdata�Ұ�����򣬲������Ұ������Ե���Ŀ
		long rightCount = InversePairsCore(copy, data, mid + 1, end);

		int i = mid; // i��ʼ��Ϊǰ������һ�����ֵ��±�
		int j = end; // j��ʼ��Ϊ�������һ�����ֵ��±�
		int indexcopy = end; // �������鸴�Ƶ���������һ�����ֵ��±�
		long count = 0; // ����������Եĸ�����ע������

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