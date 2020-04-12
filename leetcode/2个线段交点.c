/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double* intersection(int* start1, int start1Size, int* end1, int end1Size, int* start2, int start2Size, int* end2, int end2Size, int* returnSize){
    //判断2个线段是否有交点，有则返回最小交点，无则返回空
    double* result = (double*)malloc(sizeof(double)*2);
    double k1,k2,a,b;
    int* min1 = (int*)malloc(sizeof(int)*2);
    int* min2 = (int*)malloc(sizeof(int)*2);
    int* max1 = (int*)malloc(sizeof(int)*2);
    int* max2 = (int*)malloc(sizeof(int)*2);
    max1 = (start1[1] > end1[1])?start1:end1;
    min1 = (start1[1] < end1[1])?start1:end1;
    max2 = (start2[1] > end2[1])?start2:end2;
    min2 = (start2[1] < end2[1])?start2:end2;
    if(start1[0]==end1[0]&&start2[0]==end2[0]){ //2线段斜率都为零
        if(start1[0]==start2[0]){
            if(min1[1]>=min2[1] && min1[1]<=max2[1]){
                *returnSize = 2;
                result[0] = (double)min1[0];
                result[1] = (double)min1[1];
                return result; 
                }
            if(min2[1]>=min1[1] && min2[1]<=max1[1]){
                *returnSize = 2;
                result[0] = (double)min2[0];
                result[1] = (double)min2[1];
                return result;
                }
            }
        
        *returnSize = 0;
        result = NULL;
        return result;
        
    }
    if(start1[0]==end1[0]&&start2[0]!=end2[0]){//1线段斜率不存在，2线段斜率存在
        k2 = (double)(start2[1] - end2[1]) / (start2[0] - end2[0]);
        b = (double)(start2[1] - k2*start2[0]);
        result[0] = (double)start1[0];
        result[1] = k2*result[0] + b;
        if(result[1] >= min1[1] &&result[1] <= max1[1]){
            if(result[1] >= min2[1] && result[1] <= max2[1]){
                *returnSize = 2;
                return result;
            }
        }
        *returnSize = 0;
        result = NULL;
        return result;

    }
    if(start1[0]!=end1[0]&&start2[0]==end2[0]){//2线段斜率不存在，1线段斜率存在
        a = (double)(start1[1] - k1*start1[0]);
        k1 = (double)(start1[1] - end1[1]) / (start1[0] - end1[0]);
        result[0] = (double)start2[0];
        result[1] = k1*result[0] + a;
        if(result[1] >= min1[1] &&result[1] <= max1[1]){
            if(result[1] >= min2[1] && result[1] <= max2[1]){
                *returnSize = 2;
                return result;
            }
        }
        *returnSize = 0;
        result = NULL;
        return result;

    }
    k1 = (double)(start1[1] - end1[1]) / (start1[0] - end1[0]);
    k2 = (double)(start2[1] - end2[1]) / (start2[0] - end2[0]);
    max1 = (start1[0] > end1[0])?start1:end1;
    min1 = (start1[0] < end1[0])?start1:end1;
    max2 = (start2[0] > end2[0])?start2:end2;
    min2 = (start2[0] < end2[0])?start2:end2;
    if(k1 == k2){ //斜率均存在且相等
        if(min1[0]==min2[0]&&min1[1]==min2[1]){
           *returnSize = 2;
            result[0] = (double)min1[0];
            result[1] = (double)min1[1];
            return result; 
        }
        if(min1[0]==max2[0]&&min1[1]==max2[1]){
            *returnSize = 2;
            result[0] = (double)min1[0];
            result[1] = (double)min1[1];
            return result; 
        }
        if(min2[0]==max1[0]&&min2[1]==max1[1]){
            *returnSize = 2;
            result[0] = (double)min2[0];
            result[1] = (double)min2[1];
            return result;

        }
        if(((double)(start2[1] - min1[1]) / (start2[0] - min1[0]))==((double)(min1[1] - end2[1]) / (min1[0] - end2[0]))){
            if(min1[0]>=min2[0]&&min1[0]<=max2[0]){
                *returnSize = 2;
                result[0] = (double)min1[0];
                result[1] = (double)min1[1];
                return result;
                }
        }
        if(((double)(start1[1] - min2[1]) / (start1[0] - min2[0]))==((double)(min2[1] - end1[1]) / (min2[0] - end1[0]))){
            if(min2[0]>=min1[0]&&min2[0]<=max1[0]){
                *returnSize = 2;
                result[0] = (double)min2[0];
                result[1] = (double)min2[1];
                return result;
                }
        }
        *returnSize = 0;
        return result = NULL;      

    }
    else{ //斜率均存在但不等
        a = (double)(start1[1] - k1*start1[0]);
        b = (double)(start2[1] - k2*start2[0]);
        result[0] = (a-b) / (k2-k1);
        result[1] = k1*result[0] + a;
        if(result[0] >= min1[0] &&result[0] <= max1[0]){
            if(result[0] >= min2[0] && result[0] <= max2[0]){
                *returnSize = 2;
                return result;
            }
        }
        *returnSize = 0;
        result = NULL;
        return result;

    }

}