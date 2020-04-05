/*
 * @lc app=leetcode.cn id=22 lang=c
 *
 * [22] 括号生成
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void generateTree(int left,int right,int n,char *str,int index,char ** result,int *returnSize){
    /*定义递归来求总括号输出序列*/
    if(left==n&&right==n){ //到左右括号都等于n时，完成一次生成，输出序列
        result[(*returnSize)]=(char *)malloc(sizeof(char)*(2*n+1));
        str[index]='\0';
        strcpy(result[(*returnSize)++],str);
        return;
    }
    if(left<n){ //当左括号未满时，添加左括号
        str[index]='(';
        generateTree(left+1,right,n,str,index+1,result,returnSize);
    }
    if(left>right&&right<n){//当右括号数小于左括号数且右括号小于n，添加右括号
        str[index]=')';
        generateTree(left,right+1,n,str,index+1,result,returnSize);
        
    }
}
char ** generateParenthesis(int n, int* returnSize){
    char* str=(char*)malloc(sizeof(char)*(2*n+1));
    char** result=(char**)malloc(sizeof(char*)*2000);
    *returnSize=0;
    generateTree(0,0,n,str,0,result,returnSize);
    return result;
}


// @lc code=end

