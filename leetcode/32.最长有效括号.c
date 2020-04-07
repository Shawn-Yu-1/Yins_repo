/*
 * @lc app=leetcode.cn id=32 lang=c
 *
 * [32] 最长有效括号
 */

// @lc code=start


int longestValidParentheses(char * s){
    int left=0,right=0,i,j,max=0,templ=0,tempr=0;
    for(i=0;s[i]!='\0';i++){
        if(s[i]=='('){
            left++;
        }
        else{
            right++;
        }
        if(left == right){
            if(templ < left)
                templ = left;
        }
        if(left<right){
            left = 0;
            right = 0;
        }
    }
    left=0;
    right=0;
    for(j=i-1;j>=0;j--){
        if(s[j]=='('){
            left++;
        }
        else{
            right++;
        }
        if(left == right){
            if(tempr < left)
                tempr = left;
        }
        if(left>right){
            left = 0;
            right = 0;
        }
    }
    max = (templ > tempr)?templ:tempr;
    max = max*2;
    return max;
}


// @lc code=end

