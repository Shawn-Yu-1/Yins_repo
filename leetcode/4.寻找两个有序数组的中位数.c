/*
 * @lc app=leetcode.cn id=4 lang=c
 *
 * [4] 寻找两个有序数组的中位数
 */

// @lc code=start


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
double i,j;
int k,p=0,q=0;
int num=nums1Size+nums2Size;
int temp[num];
if(nums1Size==1&&nums2Size==1)
    return i=((double)nums1[0]+(double)nums2[0])/2;
if(nums1Size==0&&nums2Size==0)
    return -1;
if(nums1Size!=0){
    if(nums1Size%2==0)
        i=(double)((double)nums1[nums1Size/2]+(double)nums1[nums1Size/2-1])/2;
    else
        i=(double)nums1[nums1Size/2];
        }
if(nums2Size!=0){
    if(nums2Size%2==0)
        j=(double)((double)nums2[nums2Size/2]+(double)nums2[nums2Size/2-1])/2;
    else
        j=(double)nums2[nums2Size/2];
}
if(nums1Size==0)
    return j;
else if(nums2Size==0)
    return i;
else if(i==j)
    return i;
else{
        for(k=0;p<nums1Size&&q<nums2Size;k++){
            if(nums1[p]<nums2[q]){
                temp[k]=nums1[p];
                p++;
            }
            else{
                temp[k]=nums2[q];
                q++;
            }
        }
        if(p==nums1Size){
            while(q<nums2Size){
                temp[k]=nums2[q];
                k++;
                q++;
            }
        }
        if(q==nums2Size){
            while(p<nums1Size){
                temp[k]=nums1[p];
                k++;
                p++;
            }
        }
        printf("%d,%d,%d",temp[1],temp[2],num);
        if(num%2==0)
            return (double)(((double)temp[num/2]+(double)temp[num/2-1])/2);
        else
            return (double)temp[num/2];
        
    }
    
}



// @lc code=end

