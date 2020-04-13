/*
 * @lc app=leetcode.cn id=204 lang=c
 *
 * [204] 计数质数
 */

// @lc code=start


int countPrimes(int n){
    //暴力枚举，如果发现有一个因数不是它本身，跳出本轮
    int count = 0,i ,j,p=0;
    if(n <= 2){ //小于2没有质数
        return 0;
    }
    for(i=2;i<n;i++){//暴力枚举
        p=0;
        for(j=2;j*j <= i;j++){
            if(i%j==0){
                p=1;
            }
            if(p==1){   // 如果存在一个因数，跳出循环
                break;
            }
        }
        if(p==1){   // 是质数就加一，不是就不加
            continue;
        }
        else{
            count++;
        }
    }
    return count;

}


// @lc code=end

