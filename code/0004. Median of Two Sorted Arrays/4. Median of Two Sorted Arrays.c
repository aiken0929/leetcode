#include "c_standard.h"

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if(NULL==nums1 || NULL==nums2 || (nums1Size <1 && nums2Size <1))
        return 0.0;
    int n=(nums1Size+nums2Size)/2;
    int y=(nums1Size+nums2Size)%2;
    int mid=0,pre=0,x1=0,x2=0,tmp=0;
    while(n>=0)
    {
        if(x1<nums1Size && x2 <nums2Size){
             tmp=nums1[x1]>nums2[x2]?nums2[x2++]:nums1[x1++];
        }
        else if(x1<nums1Size)
            tmp=nums1[x1++];
        else
            tmp=nums2[x2++];
        if (n==1)
            pre=tmp;
        n--;
    }
    mid=tmp;
    return y>0?mid:((mid+pre)/2.0);
}


