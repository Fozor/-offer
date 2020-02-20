/*在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序
，每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		int m = array.size();        //获取行
		int n = array[0].size();     //获取列
		int i = 0;                  //初始化
		int j = n - 1;
		cout << m << "  "<<n<<endl;
		while (i<m && j>=0){
			cout << array[i][j] << endl;
			if (target > array[i][j]){      //目标大于最右边的值  行+1
				i+=1;
			}
			else if (target < array[i][j]){  //目标小于最右边的值  列-1
				j -= 1;
			}
			else {
				return true;
			}
		}
		return false;
	}

};
/*
int main(){

	vector<vector<int> > array = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 }, {3,5,18,20} };
	Solution S;
	
	if (S.Find(7, array)){
		cout << "Find it" << endl;

	}
	else{
		cout << "Not find" << endl;
	}
	system("pause");
	return 1;
}
*/