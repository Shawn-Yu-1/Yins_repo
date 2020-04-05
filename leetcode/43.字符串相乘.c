/*
 * @lc app=leetcode.cn id=43 lang=c
 *
 * [43] 字符串相乘
 */

// @lc code=start


char * multiply(char * num1, char * num2){
    char* result =(char*)malloc(sizeof(char)*300);
    int temp[300];
    int n1[150]={},n2[150]={};
    int i,j,p,q,c,k=0,t;
    if(num1[0]=='0'||num2[0]=='0')
        return result ="0";
    for(i=0;i<300;i++)
        temp[i]=0;
    for(i=0;num1[i]!='\0';i++);
    for(j=0;num2[j]!='\0';j++);
    for(p=i-1,q=0;p>=0;p--,q++){
        n1[q]=num1[p]-48;
        }
    for(p=j-1,q=0;p>=0;p--,q++){
        n2[q]=num2[p]-48;
        }
    printf("%d,%d\n",i,j);
    //printf("%d,%d",n1[0],n2[0]);
    for(p=0;p<i;p++){
        c=p;
        for(q=0;q<j;q++){
            if(num1[p]==0)
                break;
            t = (temp[c] + n1[p]*n2[q] + k)/10;
            temp[c] = (temp[c] + n1[p]*n2[q] + k)%10;
            k = t;
            printf("%d,%d\n",n1[p]*n2[q],temp[c]);
            c++;
        }
        if(k!=0){
            temp[c] = k;
            c++;
        }
            k=0;

    }
    printf("%d,%d",c,temp[0]);
    for(p=c-1,q=0;p>=0;p--,q++){
        result[q] = temp[p] + 48;
        }
    result[q]='\0';
    return result;

}


// @lc code=end

