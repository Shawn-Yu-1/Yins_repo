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
int i=1,j,k,p=0;
int q=0;
for(;i<n;i++){
        j=strlen(a);
        q=1;
        p=0;
        if(j==1){
        b[0]=1;
        b[1]=1;
        }
        for(k=0;k<j-1;k++){
            if(a[k]==a[k+1]){
                q++;
                }
            else{
                b[p++]=q+'0';
                b[p++]=a[k];
                q=1;
            } 
              
        }
        b[p++]=q+'0';
        b[p++]=a[k];
        b[p]='\0';
       for(j=0;j<strlen(b);j++) {
           a[j]=b[j];
       }
       a[j]='\0';
    }
   return r=&a; 
}
    
    
    





// @lc code=end

