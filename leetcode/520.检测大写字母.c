/*
 * @lc app=leetcode.cn id=520 lang=c
 *
 * [520] 检测大写字母
 */

// @lc code=start


bool detectCapitalUse(char * word){
    int len,i=0;
    len = strlen(word); //统计字符串长度
    if(len==1)
        return true;
    if(word[i]==toupper(word[i])){ //判断是否以大写字母开头
        i++;
        if(word[i]==toupper(word[i])){ //全大写
            for(;i<len&&word[i]==toupper(word[i]);i++);
                if(i==len)
                    return true;
                else
                    return false;
                    
            }
        else{
            for(;i<len&&word[i]==tolower(word[i]);i++); //只有首字母大写
                if(i==len)
                    return true;
                return false;
            }
    }
    else{
        for(;i<len&&word[i]==tolower(word[i]);i++);//判断是否为全小写
        if(i==len)
            return true;
        return false;
    }

}


// @lc code=end

