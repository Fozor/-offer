/*��
����һ�������������β��ͷ��˳�򷵻�һ��ArrayList��
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

//˳�����vector������reverse�������з�ת
class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int>result ;
		if (head == nullptr){
			return result;
		}
		while ((head) != NULL){
			result.push_back(head->val);
			head = head->next;
		}
		reverse(result.begin(), result.end());
		return result;
	}
};
//insertÿ�����Ԫ�ص�vectorͷ��
class Solution2 {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int>result ;
		if (head == nullptr){
			return result;
		}
		while ((head) != NULL){
			result.insert(result.begin(), head->val);
			head = head->next;
		}
		
		return result;
	}
};
//����ջ�Ƚ����������
class Solution3 {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		stack<int>tmp;
		vector<int>result;
		ListNode* node = head;
		if (node == nullptr){
			return result;
		}
		while ((node) != NULL){
			tmp.push(node->val);
			node = node->next;
		}
		while (!tmp.empty())
		{
			result.push_back(tmp.top());
			tmp.pop();
		}
		return result;
	}
};
