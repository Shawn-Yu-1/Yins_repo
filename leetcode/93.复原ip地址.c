/*
 * @lc app=leetcode.cn id=93 lang=c
 *
 * [93] 复原IP地址
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void lookIPaddress(char** result,char* s,int* returnSize,char* temp,int count,int p){
    int i,j,c,sum=0;
    if((count - p) == 4 && p < strlen(s)){ //存入4个数字，但是原字符串没用完，直接返回
        return;
    }
    if( (count - p) == 4 && p == strlen(s)){ //满足条件，将ipd地址存进结果字符串数组
        temp[count-1] = '\0';
        result[*returnSize] = (char*)malloc(sizeof(char)*(count));
        strcpy(result[*returnSize],temp);
        (*returnSize)++;
        return ;
    }
    if(p == strlen(s)){//没存够就超出字符串长度，返回
        return;
    }
    c = count;
    for(i=p;i<strlen(s);i++){
        sum += (s[i] - '0');
        if(sum == 0){ //sum为零，直接进入递归
            temp[count++] = s[i];
            temp[count++] = '.';
            lookIPaddress(result,s,returnSize,temp,count,i+1);
            return ; //不满足，直接返回
        }
        if(sum > 0 && sum <=255){ //sum满足范围，将数存入临时字符串，进入递归
            sum *= 10;
            for(j=p;j<=i;j++){
                temp[count++] = s[j];
            }
            temp[count++] = '.';
            lookIPaddress(result,s,returnSize,temp,count,i+1);
            count = c;//跳出递归，将count重置
        }
        else{
            return;
        }
    }   
}


char ** restoreIpAddresses(char * s, int* returnSize){
    //利用递归来枚举，满足条件存进结果数组
    char** result = (char**)malloc(sizeof(char*)*40); //结果数组
    *returnSize = 0;
    char* temp = (char*)malloc(sizeof(char)*20); //暂存字符串
    if(strlen(s) == 0){
        return NULL ;
    }
    lookIPaddress(result,s,returnSize,temp,0,0);
    return result;
}


// @lc code=end

