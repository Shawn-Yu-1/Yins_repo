/*
 * @lc app=leetcode.cn id=556 lang=c
 *
 * [556] 下一个更大元素 III
 */

// @lc code=start


int nextGreaterElement(int n){
    //  将整数转换成数组，在对数组各位遍历，寻找是否存在比该数大的数，若存在，且没超过32位整数，返回该数
    int res[33];
    int len=0,i,j,temp;
    long long result = 0;
    while(n > 0){//整数转换成数组
        res[len++] = n % 10;
        n = n / 10;
    }
    for(i=0;i<len-1;i++){// 寻找是否存在大于该数的数
        if(res[i+1]<res[i]){   //若存在，将n变成大于他的数
            for(j=i;(j>=0)&&(res[i+1]<res[j]);j--);
            temp = res[j+1];
            res[j+1] = res[i+1];
            res[i+1] = temp;
            printf("%d",res[1]);
            for(j=0;j <= i/2;j++){
                temp = res[j];
                res[j] = res[i-j];
                res[i-j] = temp;
            }
            break;
                
         }
        }
    if(i==len-1){//如果不存在该数，返回-1
        return -1;
    }
    for(i=len-1;i>=0;i--){
        result = result*10;
        result += res[i];
    }
    if(result > __INT32_MAX__){//如果该数超过int，返回-1
        return -1;
    }
    return result;
}


// @lc code=end

