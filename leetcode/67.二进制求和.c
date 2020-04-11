/*
 * @lc app=leetcode.cn id=67 lang=c
 *
 * [67] 二进制求和
 */

// @lc code=start


char * addBinary(char * a, char * b){
    /*利用归并的思想，将2个字符串逆向每位相加，有进位则传递给信号量p，
    结束后将没有计算完的根据进位量计算，最后将结果字符串倒置，再输出*/
    int i,j,lena,lenb,max,count=0,p=0,k;
    char temp;
    lena = strlen(a);
    lenb = strlen(b);
    max = (lena > lenb)?lena:lenb;
    char* result = (char*)malloc(sizeof(char)*(max+2));
    i = lena - 1;
    j = lenb - 1;
    while(i>=0&&j>=0){ //从尾向头加和
        result[count++] = (p + (a[i]-'0') + (b[j]-'0')) % 2 + '0';
        if((p + (a[i]-'0') + (b[j]-'0'))>=2){
            p = 1;
        }
        else{
            p = 0;
        }
        i--;
        j--;
    }
    printf("%d\n",p);
    if(i < 0 && j>= 0){ //处理剩余字符串
        for(k=j;k>=0;k--){
            result[count++] = (p + (b[k]-'0')) % 2 + '0';
            if((p + (b[k]-'0'))>=2){
                p = 1;
            }
            else{
                p = 0;
            }  
        }
        if(p == 1){  //判断最高位是否有进位
            result[count++] = '1';
        }
    }
    if(j < 0 && i>=0){
        for(k=i;k>=0;k--){
            result[count++] = (p + (a[k]-'0')) % 2 + '0';
            if((p + (a[k]-'0'))>=2){
                p = 1;
            }
            else{
                p = 0;
            }  
        }
        if(p == 1){  //判断最高位是否有进位
            result[count++] = '1';
        }
    }
    if(i<0 && j<0){ //判断最高位是否有进位
        if(p == 1){
            result[count++] = '1';
        }
    }
    result[count] = '\0';
    printf("%s",result);
    for(i=0;i<(count/2);i++){ //倒置
        temp = result[i];
        result[i] = result[count - i -1];
        result[count - 1 -i] = temp;
    }
    return result;


}


// @lc code=end

