#include "c_standard.h"

char* longestPalindrome(char* s) {
    //算法：遍历字串，在当前位置寻找最长字串（双数串 和 单数串）
    int len=strlen(s);
    if(len <= 1 )
        return s;
    int low=0,high=0,max=0,max_begin=0;
    for(int i=0;i<len-1;i++)
    {
        low =i;
        high=i;//单数串
        while(low>=0 && high<=len-1)
        {
            if(s[low]==s[high])
            {
                if(high-low+1 > max)
                {
                    max=high-low+1;
                    max_begin=low;
                }
                low--;
                high++;
            }
            else
                break;
        }
        low =i;
        high=i+1;//双数串
        while(low>=0 && high<=len-1)
        {
            if(s[low]==s[high])
            {
                if(high-low+1 > max)
                {
                    max=high-low+1;
                    max_begin=low;
                }
                low--;
                high++;
            }
            else
                break;
        }
    }
    char * result = calloc(max+1,sizeof(char));
    strncpy(result,s+max_begin,max);
    result[max]='\0';
    return result;
}
        /*
        if(s[i] == s[i + 1]) {//双数串
            left = i;
            right = i + 1;
            len = 2;
            j = 1;
            while((left - j >= 0) && (right + j < totalLen)) {
                if(s[left - j] == s[right + j]) {
                    len += 2;
                    j++;
                } else {
                    break;
                }
            }
            
            if(len > max) {
                max = len;
                maxLeft = left - j + 1;
            }
        }
        if( (i > 0) && (s[i - 1] == s[i + 1])) {//单数串
            left = i - 1;
            right = i + 1;
            len = 3;
            j = 1;
            while((left - j >= 0) && (right + j < totalLen)) {
                if(s[left - j] == s[right + j]) {
                    len += 2;
                    j++;
                } else {
                    break;
                }
            }
            
            if(len > max) {
                max = len;
                maxLeft = left - j + 1;
            }
        }
        */
/* 时间复杂度O（n3） 太高超出时间限制
char* longestPalindrome(char* s) {
    if(NULL==s)
        return NULL;
    int len=strlen(s);
    if(len <= 1 )
        return s;
    for(int i = len;i > 0; i--) //子串长度
    {
        for (int j = 0; j <= len - i; j++)
        {
           char * sub = calloc(i+1,sizeof(char));//子串位置
           strncpy(sub,s+j,i);
           sub[i]='\0';
           int count = 0;//计数，用来判断是否对称
           for (int k = 0; k < i / 2; k++)//左右对称判断
           {
              if (sub[k] == sub[i - k - 1])
                count++;
           }
           if (count == i / 2)
                return sub;
            free(sub);
        }
     }
    return "";//表示字符串中无回文子串
}

/* best 

char* longestPalindrome(char* s) {
    int max = 1, len;
    int left, right;
    int maxLeft = 0;
    int totalLen = strlen(s);
    int i,j;
    char *res = (char *) calloc(1, 1001);
    
    if(totalLen == 1) {
        res[0] = s[0];
        return res;
    }
    
    for(i = 0; i < totalLen - 1; ) {    
        if(totalLen-i<=max/2)//减少循环次数
            break;
        //first, pass consecutive numbers equal to each other
        right = i;
        left = i;
        while((right < totalLen - 1) && (s[right] == s[right + 1])) {
            right ++;
        }
        
        //second, set i = r + 1, for there is no len larger when start from i to r
        i = right + 1;
        
        //third, count those s[right] == s[left]
        while((left > 0) && (right < totalLen - 1) && (s[left - 1] == s[right + 1])) {
            right++;
            left--;
        }
        
        if(right - left + 1 > max) {
            maxLeft = left;
            max = right - left + 1;
        }
    }
    
   
    strncpy(res, s + maxLeft, max);
    return res;

}
*/


