/*
 * @lc app=leetcode.cn id=165 lang=c
 *
 * [165] 比较版本号
 */

// @lc code=start


int compareVersion(char * version1, char * version2){
    //依次遍历2个版本的每一个版本号，进行比较，满足条件就输出
    int num1=0,num2=0;
    int i=0,j=0;
    while(version1[i]!='\0' || version2[j]!='\0'){
        num1 = 0;
        num2 = 0;
        while(version1[i]>='0' && version1[i]<='9'){//记录小版本号
            num1 = num1*10 + (version1[i] - '0');
            i++;
        }
        while(version2[j]>='0' && version2[j]<='9'){//记录小版本号
            num2 = num2*10 + (version2[j] - '0');
            j++;
        }
        if(num1>num2){  //比较，v1大于v2输出1，反之输出-1
            return 1;
        }
        if(num1<num2){
            return -1;
        }
        if(version1[i]!='\0'){//判断是否到字符串尾，没有则指向下一个小版本
            i++;
        }
        if(version2[j]!='\0'){
            j++;
        }
        
    }
    return 0;//2个版本完全想等

}


// @lc code=end

