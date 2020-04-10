/*
 * @lc app=leetcode.cn id=207 lang=c
 *
 * [207] 课程表
 */

// @lc code=start


bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize){
    int i,j,k,t,p;
    int* temp = (int*)malloc(sizeof(int)*2);
    if(prerequisitesSize==0){
        return true;
    }
    for (i=0;i<prerequisitesSize;i++){
        if(prerequisites[i][0]==prerequisites[i][1]){
            return false;
        }
        if(prerequisites[i][0]>=numCourses||prerequisites[i][1]>=numCourses){
            return false;
        }
        
    }
    
    for(i=0;i<prerequisitesSize;i++){
        temp[0]=prerequisites[i][0];
        temp[1]=prerequisites[i][1];
        p = prerequisites[i][0];
        t = prerequisites[i][1];
        for(k=0;k<prerequisitesSize;k++){
            for(j=0;j<prerequisitesSize;j++){
                if(temp[1]==prerequisites[j][0]&&temp[0]==prerequisites[j][1]){
                    return false;
                }
                if(temp[1]==prerequisites[j][0]){
                    temp[1]=prerequisites[j][1];
                }
                if(temp[0]== prerequisites[j][1]){
                    temp[0] = prerequisites[j][1];
                }
                if(temp[0]==temp[1]){
                    return false;
                }
                printf("%d\n",j);
            }
            if(t == temp[1]&& p==temp[0]){
                break;
            }
        }
    }
    return true;

}


// @lc code=end

