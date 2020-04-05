/*
 * @lc app=leetcode.cn id=19 lang=c
 *
 * [19] 删除链表的倒数第N个节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *h,*i,*j;
    //h=(struct Listnode*)malloc(sizeof(ListNode)*1);
    //i=(struct Listnode*)malloc(sizeof(ListNode)*1);
    //j=(struct Listnode*)malloc(sizeof(ListNode)*1);
    int length,count=0;
    h=head;
    for(length=1;h->next!=0;h=h->next)
        length++;
    if(n>length)
        return -1;
    if(length==1)
        return 0;
    
    for(j=head;count<length-n;count++){
        i=j;
        j=i->next;
    }
    if(j==head){
        j=j->next;
        free(head);
        return j;
    }
    i->next=j->next;
    free(j);
    printf("%d",length);
    return head;
}


// @lc code=end

