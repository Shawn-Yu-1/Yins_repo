/*
 * @lc app=leetcode.cn id=539 lang=c
 *
 * [539] 最小时间差
 */

// @lc code=start

int findMinDifference(char ** timePoints, int timePointsSize){
        //  利用枚举方式，计算每2个时间之间的差，再取最小
    int time[timePointsSize][2];
    int i,j,min,temp,left,right;
    min = __INT32_MAX__;
    for(i=0;i<timePointsSize;i++){//    将时间转化为数字，分别是小时和分钟
        time[i][0] = (timePoints[i][0]-'0')*10 + (timePoints[i][1] - '0');
        time[i][1] = (timePoints[i][3]-'0')*10 + (timePoints[i][4] - '0');
    }
    for(i=0;i<timePointsSize;i++){//    枚举每个时间差
        for(j=i+1;j<timePointsSize;j++){
            left = ((time[i][0]-time[j][0]+24)%24)*60 + (time[i][1]-time[j][1]);
            right = ((time[j][0]-time[i][0]+24)%24)*60 + (time[j][1]-time[i][1]);
            temp = (abs(left)<abs(right))?abs(left):abs(right);
            if(min > temp){
                min = temp;
            }
            if(min==0){//   如果有最小值为零，跳出（零是最小时间差）
                break;
            }
        }
        if(min==0){
            break;
        }
    }
    return min;

}


// @lc code=end

