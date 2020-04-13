/*
 * @lc app=leetcode.cn id=1392 lang=c
 *
 * [1392] 最长快乐前缀
 */

// @lc code=start


char * longestPrefix(char * s){
    //  利用KMP算法，计算最长后缀前缀匹配，输出匹配字符串
    int i,j,len;
    len = strlen(s);
    int next[len+1];
    i=0;
    next[0]=-1;
    j=-1;
    while(i<len){
        if(j==-1||s[i]==s[j]){
            i++;
            j++;
            next[i]=j;
        }
        else 
            j=next[j];
    }
    char* result = (char*)malloc(sizeof(char)*(next[len]+1));
    for(i=0;i < next[len];i++){
        result[i] = s[i];
    }
    result[i] = '\0';
    return result;

}


// @lc code=end

