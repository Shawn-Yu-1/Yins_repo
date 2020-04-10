/*
 * @lc app=leetcode.cn id=191 lang=c
 *
 * [191] 位1的个数
 */

// @lc code=start
int hammingWeight(uint32_t n) {
    // 利用2进制与十进制转换，如果有一个1，计数就加1
    int count=0;
    while(n/2!=0){
        if(n%2==1){
            count++;
        }
        n = n / 2;
    }
    if(n%2 == 1){
        count++;
    }
    return count;
    
}
// @lc code=end

