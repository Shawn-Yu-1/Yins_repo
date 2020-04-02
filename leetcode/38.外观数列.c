/*
 * @lc app=leetcode.cn id=38 lang=c
 *
 * [38] 外观数列
 */

// @lc code=start


char * countAndSay(int n){
char a[20]="1";
char b[20]="";
char *r;
int i=1,j,k,p=0,s=0;
char q='0';
for(;i<n;i++){
    if(s==0){
        for(j=0;a[j]!='\0';j++);
        q='0';
        p=0;
        for(k=0;k<j;k++){
            if(a[k]==a[k+1]){
                q++;
                }
            else{
                b[p++]=++q;
                b[p++]=a[k];
                q='0';
            }   
        }
        b[p]='\0';
        s=1;
    }
    else{
        for(j=0;b[j]!='\0';j++);
        q='0';
        p=0;
        for(k=0;k<j;k++){
            if(b[k]==b[k+1]){
                q++;
                }
            else{
                a[p++]=++q;
                a[p++]=b[k];
                q='0';
            }   
        }
        a[p]='\0';
        s=0;
    }
}
    if(s==0)
        return r=&a;
    else
        return r=&b;
    

}



// @lc code=end

