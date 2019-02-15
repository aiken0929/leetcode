#include "c_standard.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    /* 算法 1 ：相加，复杂度位O（m+n）这种方法会改变原来的链表结构  若位相反 反转链表*/
    /* 算法2 ： 将各链表转为整数，相加，再用链表存，注意非负正数的范围，这个方法只能实现10位（INT_MAX）的相加 */
    /* 这个题目 没说位数，就只能用算法1 */
    int carry=0;
    struct ListNode* now=l1,*head=l2,*pre=NULL;   
     struct ListNode* result= calloc(1,sizeof(struct ListNode));
    if(NULL==l1 ) return l2;
    if(NULL==l2 ) return l1;
    /*  */
    pre=result;
    /* 开始计算和 */
    while(now && head)
    {
        pre->val=now->val+head->val+carry;
        if(10 <=pre->val)
        {
            carry=1;
            pre->val=(pre->val)%10;
        }
        else carry=0;
        now=now->next;
        head=head->next;
        if(now && head)
        {
           pre->next = calloc(1,sizeof(struct ListNode)); 
           pre=pre->next;
        }
    }
    while(now)
    {
        pre->next = calloc(1,sizeof(struct ListNode)); 
        pre->next->val=now->val+carry;
        if(10 <=pre->next->val)
        {
            carry=1;
            pre->next->val=(pre->next->val)%10;
        }
        else carry=0;
        pre=pre->next;
        now=now->next;
    }
    while(head)
    {
        pre->next = calloc(1,sizeof(struct ListNode)); 
        pre->next->val=head->val+carry;
        if(10 <=pre->next->val)
        {
            carry=1;
            pre->next->val=(pre->next->val)%10;
        }
        else carry=0;
        pre=pre->next;
        head=head->next;
    }
    if(carry)
    {
       pre->next = calloc(1,sizeof(struct ListNode)); 
       pre->next->val=1;
       pre=pre->next;
    }
    pre->next=NULL;
    
    return result;
}
/* 若链表为倒序
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    /* 算法 1 ：相加，复杂度位O（m+n）这种方法会改变原来的链表结构  若位相反 反转链表
    /* 算法2 ： 将各链表转为整数，相加，再用链表存，注意非负正数的范围，这个方法只能实现10位（INT_MAX）的相加 
    /* 这个题目 没说位数，就只能用算法1 
    int size1,size2,carry=0;
    struct ListNode* now=l1->next,*head=l1,*pre=l1;   
     struct ListNode* result= calloc(1,sizeof(struct ListNode));
    if(NULL==l1 ) return l2;
    if(NULL==l2 ) return l1;
    if(now){
      /* 反转链表1 
      while(now->next)
      {
          pre->next=now->next;
          now->next=head;
          head=now;
          now=pre->next;
      }
      pre->next=NULL;
      now->next=head;
      head=now;
    }
    l1=head;
    /* 反转链表2
    now=l2->next;
    head=l2;
    pre=l2;
    if(now)
    {
      while(now->next)
      {
          pre->next=now->next;
          now->next=head;
          head=now;
          now=pre->next;
      }
      pre->next=NULL;
      now->next=head;
      head=now;
    }
    l2=head;
    /*  
    now=l1;
    pre=result;
    /* 开始计算和 
    while(now && head)
    {
        pre->val=now->val+head->val+carry;
        if(10 <=pre->val)
        {
            carry=1;
            pre->val=(pre->val)%10;
        }
        else carry=0;
        now=now->next;
        head=head->next;
        if(now && head)
        {
           pre->next = calloc(1,sizeof(struct ListNode)); 
           pre=pre->next;
        }
    }
    while(now)
    {
        pre->next = calloc(1,sizeof(struct ListNode)); 
        pre->next->val=now->val;
        pre=pre->next;
        now=now->next;
    }
    while(head)
    {
        pre->next = calloc(1,sizeof(struct ListNode)); 
        pre->next->val=head->val;
        pre=pre->next;
        head=head->next;
    }
    pre->next=NULL;
    
    /*反转result 链表
    now=result->next;
    head=result;
    pre=result;
    if(now)
    {
      while(now->next)
      {
          pre->next=now->next;
          now->next=head;
          head=now;
          now=pre->next;
      }
      pre->next=NULL;
      now->next=head;
      head=now;
    }
    result=head;
        
    /*还原（反转）l1 l2 链表
    
    return result;
}


