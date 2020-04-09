/*
 * @lc app=leetcode.cn id=9 lang=c
 *
 * [9] 回文数
 */

// @lc code=start


bool isPalindrome(int x){
    int i,j,p,len;
    char temp[20];
    if(x==0){ //零直接返回true
        return true;
    }
    if(x>0){
        for(i=0,p=x;p/10!=0;i++){//若是正数，将其转换为字符串
            p=p/10;
        }
        printf("%d\n",i);
        p=x;
        temp[i+1]='\0';
        for(j=i;j>=0;j--){
            temp[j]=p%10+48;
            p=p/10;
        }
    }
    else{
        for(i=1,p=x;p/10!=0;i++){//若是负数，将其转换为字符串
            p=p/10;
        }
        p=x;
        temp[i+1]='\0';
        for(j=i;j>=0;j--){
            temp[j]=abs(p%10)+48;
            p=p/10;
        }
        temp[0]='-';
    }
    printf("%s",temp);
    len=strlen(temp);
    for(i=0;i<(len/2);i++){  //比较字符串是否对称
        if(temp[i]!=temp[len-1-i]){
            return false;
        }
    } 
    return true;

}


// @lc code=end

