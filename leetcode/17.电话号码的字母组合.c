/*
 * @lc app=leetcode.cn id=17 lang=c
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void numTolitter(char** result,char** relation,char* digits,int* returnSize,int n,char* temp){
    if(n==strlen(digits)){
        result[*returnSize]=(char*)calloc((strlen(digits)+1),sizeof(char));
        strcpy(result[*returnSize],temp);
        result[*returnSize][strlen(digits)] = '\0';
        (*returnSize)++;
        return ;
    }
        for(int i=0;i<strlen(relation[digits[n]-'2']);i++){
            temp[n]=relation[digits[n]-'2'][i];
            numTolitter(result,relation,digits,returnSize,n+1,temp);
    
    }
}
char ** letterCombinations(char * digits, int* returnSize){
    *returnSize = 0;
    if(strlen(digits)==0){
        return NULL;
    }
    char* relation[8] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    char** result=(char**)calloc(5000,sizeof(char*));
    char* temp=(char*)calloc((strlen(digits)+1),sizeof(char));
    numTolitter(result,relation,digits,returnSize,0,temp);
    return result;
}


// @lc code=end

