int findMinDifference(char ** timePoints, int timePointsSize){
    int time[timePointsSize][2];
    int i,j,min,temp,left,right;
    min = __INT32_MAX__;
    for(i=0;i<timePointsSize;i++){
        time[i][0] = (timePoints[i][0]-'0')*10 + (timePoints[i][1] - '0');
        time[i][1] = (timePoints[i][3]-'0')*10 + (timePoints[i][4] - '0');
    }
    for(i=0;i<timePointsSize;i++){
        for(j=i+1;j<timePointsSize;j++){
            left = ((time[i][0]-time[j][0]+24)%24)*60 + (time[i][1]-time[j][1]);
            right = ((time[j][0]-time[i][0]+24)%24)*60 + (time[j][1]-time[i][1]);
            temp = (abs(left)<abs(right))?abs(left):abs(right);
            if(min > temp){
                min = temp;
            }
        }
    }
    return min;

}
