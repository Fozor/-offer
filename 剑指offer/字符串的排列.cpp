/*
����һ���ַ���,���ֵ����ӡ�����ַ������ַ����������С����������ַ���abc,���ӡ�����ַ�a,b,c�������г����������ַ���abc,acb,bac,bca,cab��cba��
*/


#include<iostream>
#include<vector>
#include<string>
#include<algorithm>   //sort
using namespace std;


class Solution {
public:
	vector<string> Permutation(string str) {
		if (str.length() == 0){
			return result;
		}
		PermutationSwap(str,0);  //ȫ���� �ݹ�ʵ��
		sort(result.begin(), result.end());   //����
		return result;
	}

	void Show(){
		for (int i = 0; i < result.size(); i++){
			cout << result[i] << endl;
		}
	}
private: 
	vector<string> result;  //˽�б��� ��������

	void PermutationSwap(string str, int index){  //ͷ��Ԫ�����κͺ��Ԫ�ؽ��е���  ����ֵΪvoid
		if (index == str.length()){
			result.push_back(str);
			return ;
		}
		for (int i = index; i < str.length(); i++){
			if ((str[i] == str[index]) && (i != index)){
				continue;
			}
			//swap str[i] str[index]
			swap(str[i], str[index]);
			PermutationSwap(str, index+1);  //�������Ϊindex+1   �ݹ����
		}
	}

};

/*

int main(){
	Solution S;
	string str = "abc";
	S.Permutation(str);
	S.Show();
	system("pause");
	return 0;
}
*/
