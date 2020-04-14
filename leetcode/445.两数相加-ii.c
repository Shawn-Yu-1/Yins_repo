/*
 * @lc app=leetcode.cn id=445 lang=c
 *
 * [445] 两数相加 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    //  创建2个数组暂存2个链表，将加和放入新的链表
    int temp1[200];
    int temp2[200];
    int len1=1,len2=1;
    temp1[0] = l1->val;
    temp2[0] = l2->val;
    int i,j,k,p=0;
    int num1,num2;
    struct ListNode* res = (struct ListNode*)malloc(sizeof(struct ListNode)*1);
    res->next = NULL;
    while(l1->next != NULL) {
        l1 = l1->next;
        temp1[len1] = l1->val;
        ++len1;
    }
    while(l2->next != NULL){
        l2 = l2->next;
        temp2[len2] = l2->val;
        ++len2;
    }
    while(len1!=0 || len2!=0){
            num1 = (len1 == 0)?0:temp1[--len1];
            num2 = (len2 == 0)?0:temp2[--len2];
            k = (num1 + num2 + p) % 10;
            p = (num1 + num2 + p) / 10;
       struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode)*1);
        temp->val = k;
        temp->next = res->next;
        res->next = temp;

    }
    if(p==1){
        struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode)*1);
        temp->val = 1;
        temp->next = res->next;
        res->next = temp;
    }
    res = res->next;
    return res;
   
    

}


// @lc code=end

