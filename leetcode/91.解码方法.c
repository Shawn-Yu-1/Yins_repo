/*
 * @lc app=leetcode.cn id=91 lang=c
 *
 * [91] 解码方法
 */

// @lc code=start


void decode(char* s,int len,int* count,int p){
    int i,j;
    if(p == len){   //全部解码，解码数加一
        (*count)++;
        return;
    }
    if(s[p] == '0'){    //如果是零，不满足密码体系，返回
        return;
    }
    decode(s,len,count,p+1);    //此位按一位数解码
    if(p < (len - 1)){
        i = s[p] - '0';
        j = s[p+1] - '0';
        if((i*10+j) <= 26){     //若满足密码体系，按2位数解码
            decode(s,len,count,p+2);
            }
    }
}

int numDecodings(char * s){
    //  回溯法，简单易懂
    int* count = (int*)malloc(sizeof(int)*1);
    (*count) = 0;
    decode(s,strlen(s),count,0);
    return *count;

}


// @lc code=end

