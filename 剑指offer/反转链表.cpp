/*
输入一个链表，反转链表后，输出新链表的表头。
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

//使用三个指针，分别指向当前遍历到的结点、它的前一个结点以及后一个结点。
//在遍历的时候，做当前结点的尾结点和前一个结点的替换。
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
				//return ReverseListHead; 放这里会产生段错误
			}
				pNode->next = pPrev;
				pPrev = pNode;
				pNode = pNext;
			
		}
		return ReverseListHead;
	}
};