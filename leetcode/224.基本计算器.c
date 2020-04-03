/*
 * @lc app=leetcode.cn id=224 lang=c
 *
 * [224] 基本计算器
 */

// @lc code=start


int calculate(char * s){
    int a[1000]={}; //定义2个数组用来存操作数及运算符，模拟栈
    char b[1000]={};
    int i=0,j=0,p=0,q=0;
    for(;s[p]!='\0';p++){ //扫描输入字符串
        switch (s[p])
        {
        case '(':b[j]='('; //加上括号
                 j++;
                 break;
        case '+':if(j>0){ //出站运算
                    switch (b[--j])
                    {
                     case '+':i--;
                             a[i-1]=a[i-1]+a[i];
                             b[j]=s[p];
                             j++;
                            break;
                     case '-':i--;
                             a[i-1]=a[i-1]-a[i];
                             b[j]=s[p];
                             j++;
                             break;
                     case '(':b[++j]='+';
                             j++;
                             break;
                    }
                    q=0;
                    break;
                 }    
                 b[j]='+';
                 j++;
                 q=0;
                 break;
        case '-':if(j>0){ //出站运算
                    switch (b[--j])
                    {
                     case '+':i--;
                             a[i-1]=a[i-1]+a[i];
                             b[j]=s[p];
                             j++;
                            break;
                     case '-':i--;
                             a[i-1]=a[i-1]-a[i];
                             b[j]=s[p];
                             j++;
                             break;
                    case '(':b[++j]='-';
                            j++;
                            break;
                    }
                    q=0;
                    break;
                 }    
                 b[j]='-';
                 j++;
                 q=0;
                 break;
        case ')'://printf("%d",j);
                 j--;
                 i--;
                for(;b[j]!='(';j--){ //去括号运算
                    switch (b[j])
                    {
                    case '+':a[i-1]=a[i-1]+a[i];
                             i--;
                             break;
                    case '-':a[i-1]=a[i-1]-a[i];
                             i--;
                             break;
                    default:
                        break;
                    }
                }
                 i++;
                 q=0;
                 break;
        case ' ':break;//去掉空格
        
        default:if(q==1) //用q来控制多位数字
                a[i-1]=a[i-1]*10+(int)(s[p]-48);
                else{
                a[i]=(int)(s[p]-48);
                i++;
                q=1;
                }
                break;
        }

    }
    //printf("%d,%d\n",i,j);
    //printf("%d,%d",a[0],a[1]);
    if(j>0){ //查看是否还有运算符存在
        i--;
        j--;
        for(;j>=0;j--){
            switch (b[j])
                    {
                    case '+':a[i-1]=a[i-1]+a[i];
                             i--;
                             break;
                    case '-':a[i-1]=a[i-1]-a[i];
                             i--;
                             break;
                    }
        }
    }
    return a[0];
}


// @lc code=end

