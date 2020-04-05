/*
 * @lc app=leetcode.cn id=20 lang=c
 *
 * [20] 有效的括号
 */

// @lc code=start


bool isValid(char * s){
    char temp[5000]={};
    int i,j=0;
    for(i=0;s[i]!='\0';i++){
        if(s[i]=='('||s[i]=='{'||s[i]=='[')
            temp[j++]=s[i];
        if(s[i]==')'){
            if(j==0)
                return false;
            if(temp[--j]!='('){
                j++;
                break;
            }
            
        }
        if(s[i]=='}'){
            if(j==0)
                return false;
            if(temp[--j]!='{'){
                j++;
                break;
                }
        }
        if(s[i]==']'){
            if(j==0)
                return false;
            if(temp[--j]!='['){
                j++;
                break;
            }
        }
    }
    if(j==0)
        return true;
    return false;


}


// @lc code=end

