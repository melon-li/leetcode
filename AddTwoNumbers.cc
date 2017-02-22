/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
#include <stdio.h>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result = new ListNode(0);
        ListNode *lt1 = l1, *lt2 = l2,  *cur = result;
        int ext = 0;
        while(lt1 || lt2){
            int n1 = lt1 ? lt1->val: 0;
            int n2 = lt2 ? lt2->val: 0;
            int sum = n1 + n2 + ext;
            cur->next = new ListNode(sum%10);
            cur = cur->next;
            ext = sum/10;
            lt1 = lt1 ? lt1->next: NULL;
            lt2 = lt2 ? lt2->next: NULL;
        }
        if(ext > 0) cur->next = new ListNode(ext);
        return result->next;
    }
};

//Test
int main(){
    ListNode l1(2), l12(5), l13(3);
    l1.next = &l12;
    l12.next = &l13;
    ListNode l2(5), l22(6), l23(4);
    l2.next = &l22;
    l22.next = &l23;
    Solution s;
    ListNode *l3 = s.addTwoNumbers(&l1, &l2);
    ListNode *lt = l3;
    while(lt){
        cout<<lt->val<<endl;
        lt = lt->next;
    }

}
