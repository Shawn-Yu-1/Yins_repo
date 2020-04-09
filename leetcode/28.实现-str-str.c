/*
 * @lc app=leetcode.cn id=28 lang=c
 *
 * [28] 实现 strStr()
 */

// @lc code=start
void getnext(char* needle,int len1,int next[]){
    int i,j;
    i=0;
    next[0]=-1;
    j=-1;
    while(i<len1-1){
        if(j==-1||needle[i]==needle[j]){
            i++;
            j++;
            next[i]=j;
        }
        else 
            j=next[j];
    }
}

int strStr(char * haystack, char * needle){
    //就是KMP算法
    int i,j,len1,len2;
    int next[100000];
    len1=strlen(haystack);
    len2=strlen(needle);
    if(haystack[0]=='\0'&&needle[0]=='\0'){
        return 0;
    }
    getnext(needle,len2,next);
    i=0;
    j=0;
    while(i<len1&&j<len2){
        if(j==-1 || haystack[i]==needle[j])
      {
         i++;
         j++;
      }
      else j=next[j]; 
    }
    if(j>=len2){
        return i-len2;
    }
    /*for(i=0;haystack[i]!='\0';i++){
        count=0;
        for(j=i,k=0;haystack[j]!='\0'&&needle[k]!='\0';j++,k++){
            if(haystack[j]!=needle[k]){
                break;
            }
            count++;
        }
        if(needle[count]=='\0'){
            return i;
        }
    }*/
    return -1;

}


// @lc code=end

