/*
 * @lc app=leetcode.cn id=763 lang=c
 *
 * [763] 划分字母区间
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void makepiece(int* result,char* s,int* returnSize,int tail){
    int i,j,p;
    if(tail == strlen(s)){
        return;
    }
    p=0;
    for(i=tail;i<strlen(s);i++){
        for(j=strlen(s)-1;j>=p;j--){
            if(s[i]==s[j]){
                p = j;
                break;
            }
        }
        if(i==p){
            break;
        }

    }
    result[*returnSize] = p+1-tail;
    (*returnSize)++;
    makepiece(result,s,returnSize,p+1);

}
int* partitionLabels(char * S, int* returnSize){
    //使用递归，简单易懂
    int* result = (int*)malloc(sizeof(int)*100);
    int i,temp;
    *returnSize = 0;
    makepiece(result,S,returnSize,0);
    return result;

}


// @lc code=end

