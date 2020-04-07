

void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int i,j,temp;
    for(i=0;i<matrixSize;i++)
        for(j=0;j<i;j++){
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    for(i=0;i<matrixSize;i++)
        for(j=0;j<(*matrixColSize/2);j++){
            temp = matrix[i][j];
            matrix[i][j] = matrix[i][*matrixColSize-1-j];
            matrix[i][*matrixColSize-1-j] = temp;
        }

}