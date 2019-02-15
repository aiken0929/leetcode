#include "c_standard.h"

int lengthOfLongestSubstring(char* s) {
    //算法：用book标记出现过的字符的index，用max标记最大长度，用start标记当前不重复开始的index，用num表示当前不重复的个数
    //遍历数组，若book[]大于start，说明遇到相同元素，则从其相同处重新计算长度和起始位置
    if(NULL == s)
        return NULL;
    int len=strlen(s);
    int book[255]={0};
    //memset(book,0xff,255*sizeof(int));//将book初始化为-1
    if (0==len)
        return 0;
    int start=0,max=0;//max_start=0;
    int num=0;
    for (int i=0;i<len;i++)
    {
        if(book[s[i]]==0 || book[s[i]]<start+1)
        {
            num++;
            if(num>max)
            {
                //max_start=start;
                max=num;
            }
            book[s[i]]=i+1;
        }
        else
        {
            start=book[s[i]];
            num=i-start+1;
            book[s[i]]=i+1;
        }
    }
    return max;
}


