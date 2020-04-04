/*
 * @lc app=leetcode.cn id=7 lang=c
 *
 * [7] 整数反转
 */

// @lc code=start


int reverse(int x){
    int temp[20]={},a,b,k=0,i,j,p=0;
    int test[10]={2,1,4,7,4,8,3,6,4,7}; //用于比较溢出
    if(x==0)
        return 0;
    a=x;
    for(;a/10!=0;){ //将x翻转按位存进数组
        b=a%10;
        a=a/10;
        if(b!=0||p==1){ //跳过数尾若干零
            p=1;
            temp[k]=b;
            k++;
        }
    }
    temp[k]=a;
    k++;
    a=temp[k-1];
    b=1;
    printf("%d",k);
    if(k==10){ //判断是否int会溢出
        for(i=0;i<k;i++)
            if(abs(temp[i])>test[i])
                for(j=i-1;j>=0;j--)
                    if(abs(temp[j])<test[j])
                        break;
                    else
                        return 0;
    }
        
    
    for(i=k-2;i>=0;i--){ //输出翻转数
        b *=10;
        a += temp[i]*b;
        
    }
    /*if(x<0)
        return -a;*/
    return a;
    
}


// @lc code=end

