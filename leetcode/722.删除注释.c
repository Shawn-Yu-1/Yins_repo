/*
 * @lc app=leetcode.cn id=722 lang=c
 *
 * [722] 删除注释
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** removeComments(char ** source, int sourceSize, int* returnSize){
    char** result=(char**)malloc(sizeof(char*)*sourceSize);
    int i,j,k,p,count;
    for(i=0;i<sourceSize;i++){ //循环测试整个数组
        count=0;
        for(j=0;source[i][j]!='\0';j++){
            if(source[i][j]=='/'&&source[i][j+1]=='/'){//出现"//"注释符，后面全删
                source[i][j]='\0';
                printf("123\n");
                break;
                }
            if(source[i][j]=='/'&&source[i][j+1]=='*'){//出现/*注释符
                for(p=j+2;source[i][p]!='\0';p++){
                    if(source[i][p]=='*'&&source[i][p+1]=='/'){//在同一行，这将结束符后面字符串覆盖注释，跳出并重新测试该行
                        for(p=p+2;source[i][p]!='\0';p++){
                            source[i][j]=source[i][p];
                            j++;
                        }
                        count=1;
                        source[i][j]='\0';
                        i--;
                        break;
                    }
                }
                if(count==1){
                    break;
                }
                for(k=i,i++;i<sourceSize;i++){ //若不在同一行，则将中间行全删除，同事将最后一行剩余字符复制到注释符行，重新检测该行
                    for(p=0;source[i][p]!='\0';p++){
                        if(source[i][p]=='*'&&source[i][p+1]=='/'){
                            for(p=p+2;source[i][p]!='\0';p++){
                            source[k][j]=source[i][p];
                            j++;
                            }
                            count=1;
                            source[k][j]='\0';
                            source[i][0]='\0';
                            i=k-1;
                            break;
                        }
                    }
                    if(count==1){
                    break;
                    }
                    if(source[i][p]=='\0'){
                       source[i][0]='\0';
                    }

                    }
                    if(count==1){
                        break;
                    }
                }
            }
        }
        for(p=0,i=0;p<sourceSize;p++){
            if(source[p][0]!='\0'){
                result[i]=(char*)malloc(sizeof(char)*90);
                strcpy(result[i],source[p]);
                i++;
            }
        }
        printf("%d",i);
        *returnSize=i;
        return result;
    }



// @lc code=end

