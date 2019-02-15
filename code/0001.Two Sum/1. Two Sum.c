#include "c_standard.h"
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/*
int* twoSum(int* nums, int numsSize, int target) {
    int i,j,signal=0;
    int * result =(int*)malloc(2*sizeof(int));
    memset(result,0,8);
    for (i=0;i<numsSize;i++)
    {
        for(j=i+1;j<numsSize;j++)
            if (target==(nums[i]+nums[j]))
            {
                result[0]=i;
                result[1]=j;
                signal=1;
                break;
            }
        if(1==signal) break;
    }
    return result;
}

/* best answer */
typedef struct hash{
    int val;
    int index;
    struct hash *next;
}HASH;
int* twoSum(int* nums, int numsSize, int target) {  
    if(NULL==nums || numsSize<2)
        return NULL;
    HASH **h = (HASH*)calloc(64,sizeof(HASH*));  //若target是一个很大的数，min为一很小的数，table会很长，所以建议用哈希链表
    int *indice = (int*)malloc(2*sizeof(int));  
    
    long tmp=0;//记录target 与nums[]的差
    int h_tmp=0;
    HASH * t=NULL;
    HASH *before=NULL;//用于释放内存
    for (int i = 0; i < numsSize; i++) { 
        tmp=target-nums[i];
        if(tmp>INT_MAX || tmp<INT_MIN)
            continue;
        //if(INT_MIN==tmp)
            h_tmp=tmp&0X3F;//取最后6位
       // else
            //h_tmp=tmp>=0?tmp>>7:(-tmp)>>6;
        t=h[h_tmp];
        while (t) {  
            if (tmp == t->val) {        //满足相加为target (int )tmp? 
                indice[0] = t->index;  
                indice[1] = i; 
                //释放动态内存
                for(int m=0;m<64;m++)
                {
                    t=h[m];
                    while(t)
                    {
                      before=t;
                      t=t->next;
                      free(before);
                    }
                }
                free(h);
                return indice;  
            }  
            t=t->next;
        } 
        //没有找到则保存当前数
        t=(HASH *)calloc(1,sizeof(HASH));
        t->val=nums[i];
        t->index=i;
        h_tmp=nums[i]&0X3F;//取最后6位
        if(h[h_tmp])
        {
            t->next=h[h_tmp]->next;
            h[h_tmp]->next=t;
        }
        else
            h[h_tmp]=t;
    }  
    for(int m=0;m<64;m++)
    {
        t=h[m];
        while(t)
        {
            before=t;
            t=t->next;
            free(before);
        }
    }
    free(h);
    free(indice);
    return NULL;  
} 

