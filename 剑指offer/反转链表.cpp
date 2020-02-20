/*
����һ��������ת��������������ı�ͷ��
*/

#include<iostream>

using namespace std;

struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};

//ʹ������ָ�룬�ֱ�ָ��ǰ�������Ľ�㡢����ǰһ������Լ���һ����㡣
//�ڱ�����ʱ������ǰ����β����ǰһ�������滻��
class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		ListNode* ReverseListHead = NULL;
		ListNode* pNode = pHead;
		ListNode* pPrev = NULL;
		if (pHead == NULL){
			return NULL;
		}
		while (pNode != NULL){
			ListNode* pNext = pNode->next;
			if (pNext == NULL){
				ReverseListHead = pNode;
				//return ReverseListHead; �����������δ���
			}
				pNode->next = pPrev;
				pPrev = pNode;
				pNode = pNext;
			
		}
		return ReverseListHead;
	}
};