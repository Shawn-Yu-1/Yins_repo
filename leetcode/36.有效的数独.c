/*
 * @lc app=leetcode.cn id=36 lang=c
 *
 * [36] 有效的数独
 */

// @lc code=start

void Ifsudoku(char** board,int boardSize,int row,int clum,bool* result){
    int i,j,k,p,q;
    if(row==boardSize){
        (*result) = true;
        return ;
    }
    if(board[row][clum] == '.'){
        for(i=1;i < 10;i++){
            k=0;
            board[row][clum] = i + '0';
            for(j=0;j<boardSize;j++){
                    if(clum != j && board[row][clum]==board[row][j]){
                        k=1;
                        break;
                    }
                }
            if(k == 1){
                board[row][clum] = '.';
                continue;
            }
            for(j=0;j<boardSize;j++){
                    if(row != j && board[row][clum]==board[j][clum]){
                        k=1;
                        break;
                    }
                }
            if(k == 1){
                board[row][clum] = '.';
                continue;
            }
            for(p=(row/3)*3;p<((row/3)*3+3);p++){
                for(q=(clum/3)*3;q<((clum/3)*3+3);q++){
                    if(row!=p&&clum!=q&&board[row][clum]==board[p][q]){
                        k=1;
                        break;
                        }
                    }
                }
            if(k == 1){
                board[row][clum] = '.';
                continue;
            }
            if(clum == 8){
                Ifsudoku(board,boardSize,row+1,0,result);
            }
            else{
                Ifsudoku(board,boardSize,row,clum+1,result);
            }
            board[row][clum] = '.';

        }

    }
    else{
        if(clum == 8){
           Ifsudoku(board,boardSize,row+1,0,result); 
        }
        else{
            Ifsudoku(board,boardSize,row,clum+1,result);
        }
    }
}

bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    int i,j,k,p,q;
    bool* result = (bool*)malloc(sizeof(bool)*1);
    *result = false;
    for(i=0;i<boardSize;i++){
        for(j=0;j<(*boardColSize);j++){
            if(board[i][j] != '.'){
                for(k=j+1;k<(*boardColSize);k++){
                    if(board[i][j]==board[i][k]){
                        return false;
                    }
                }
                for(k=i+1;k<boardSize;k++){
                    if(board[i][j]==board[k][j]){
                        return false;
                    }
                }
                for(p=(i/3)*3;p<((i/3)*3+3);p++){
                    for(q=(j/3)*3;q<((j/3)*3+3);q++){
                        if(i!=p&&j!=q&&board[i][j]==board[p][q]){
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
    printf("123");
    //Ifsudoku(board,boardSize,0,0,result);
    //return *result;

}


// @lc code=end

