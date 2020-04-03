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
if(nums1Size==0&&nums2Size==0)
    return -1;
if(nums1Size!=0){
    if(nums1Size%2==0)
        i=(double)(nums1[nums1Size/2]+nums1[nums1Size/2-1])/2;
    else
        i=(double)nums1[nums1Size/2];
        }
if(nums2Size!=0){
    if(nums2Size%2==0)
        j=(double)(nums2[nums2Size/2]+nums2[nums2Size/2-1])/2;
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
        for(k=0;k<num;k++){
            if(nums1[p]<nums2[q]){
                temp[k]=nums1[p];
                p++;
            }
            else{
                temp[k]=nums2[q];
                q++;
            }
        }
        if((nums1Size+nums2Size)%2==0)
            return (double)((temp[num/2]+temp[num/2-1])/2);
        else
            return (double)temp[num/2];
        
    }
    
}



// @lc code=end

