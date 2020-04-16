/*
 * @lc app=leetcode.cn id=25 lang=c
 *
 * [25] K 个一组翻转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseKGroup(struct ListNode* head, int k){
    //  简单，通过链表头插法，将每一个K里，从头开始，依次将节点查到头部，即可实现反转
    int count=0,times,temp=0;
    struct ListNode* h,*p,*q,*res;
    h = head;
    while(h!=NULL){//计算链表长
        count++;
        h = h->next;
    }
    printf("%d",count);
    times = count / k;//计算需要循环几个K
    if(times == 0 || k==1){//特殊情况，不做处理，直接输出
        return head;
    }
    count = 1;
    h = (struct ListNode*)malloc(sizeof(struct ListNode)*1);
    h->next = head;
    p = head->next;
    while(temp!=times){ //统计循环次数，达到次数就跳出
        q = p->next;    //将后一个插到头部
        head->next = q;
        p->next = h->next;
        h->next = p;
        p = q;
        count++;
        printf("%d",count);
        if(temp==0&&count==k){//记录第一次循环完成的头部，即为结果链表的头部
            res = h->next;
        }
        if(p==NULL){//循环到链尾，跳出
            break;
        }
        if(count==k){//若完成一次翻转，调整指针位置
            h = head;
            head = p;
            p = p->next;
            count = 1;
            temp++;
        }
    }
    return res;
}


// @lc code=end

