/*
 * @lc app=leetcode.cn id=391 lang=c
 *
 * [391] 完美矩形
 */

// @lc code=start


bool isRectangleCover(int** rectangles, int rectanglesSize, int* rectanglesColSize){
    int i,j,k,s,sum = 0;
    int* min = (int*)malloc(sizeof(int)*2);
    int* max = (int*)malloc(sizeof(int)*2);
    for(i=0;i<rectanglesSize;i++){
        for(j=i+1;j<rectanglesSize;j++){
            if(rectangles[j][3]<=rectangles[i][1]){
                continue;
            }
            else if(rectangles[j][2]<=rectangles[i][0]){
                continue;
            }
            else if(rectangles[j][1]>=rectangles[i][3]){
                continue;
            }
            else if(rectangles[j][0]>=rectangles[i][2]){
                continue;
            }else{
                return false;
            }
        }
    }
    min[0] = rectangles[0][0];
    min[1] = rectangles[0][1];
    max[0] = rectangles[0][2];
    max[1] = rectangles[0][3];
    for(i=0;i<rectanglesSize;i++){
        if(rectangles[i][0]< min[0]){
            min[0] = rectangles[i][0];
            min[1] = rectangles[i][1];
        }
        if(rectangles[i][0]==min[0]&&rectangles[i][1]<min[1]){
            min[0] = rectangles[i][0];
            min[1] = rectangles[i][1];
        }
        if(rectangles[i][2]>max[0]){
            max[0] = rectangles[i][2];
            max[1] = rectangles[i][3];
        }
        if(rectangles[i][2]==max[0]&&rectangles[i][3]>max[1]){
            max[0] = rectangles[i][2];
            max[1] = rectangles[i][3];
        }
        sum += (rectangles[i][2]-rectangles[i][0])*(rectangles[i][3]-rectangles[i][1]);
    }
    s = (max[0]-min[0])*(max[1]-min[1]);
    printf("%d,%d\n",min[0],min[1]);
    printf("%d,%d\n",max[0],max[1]);
    if(s != sum){
        return false;
    }
    for(i=0;i<rectanglesSize;i++){
        if(rectangles[i][0]>=min[0]&&rectangles[i][1]>=min[1]){
            if(rectangles[i][0]<=max[0]&&rectangles[i][1]<=max[1]){

                }
            else{
                return false;
            }     
        }
        else{
            return false;
        }
        if(rectangles[i][2]>=min[0]&&rectangles[i][3]>=min[1]){
            if(rectangles[i][2]<=max[0]&&rectangles[i][3]<=max[1]){

                }
            else{
                return false;
            }     
        }
        else{
            return false;
        }
    }
    return true;

}


// @lc code=end

