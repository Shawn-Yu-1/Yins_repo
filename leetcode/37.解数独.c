/*
 * @lc app=leetcode.cn id=37 lang=c
 *
 * [37] 解数独
 */

// @lc code=start

void Ifsudoku(char** board,int boardSize,int row,int clum,bool* result){
    int i,j,k,p,q;
    if(row==boardSize){ //得出解，将标记变量赋值为true，返回结果
        (*result) = true;
        return ;
    }
    if(board[row][clum] == '.'){    //对于没有填的数进行尝试
        for(i=1;i < 10;i++){
            k=0;
            board[row][clum] = i + '0';
            for(j=0;j<boardSize;j++){   //判断同行有没有相同
                    if(clum != j && board[row][clum]==board[row][j]){
                        k=1;
                        break;
                    }
                }
            if(k == 1){
                board[row][clum] = '.';
                continue;
            }
            for(j=0;j<boardSize;j++){   //判断同列有没有相同
                    if(row != j && board[row][clum]==board[j][clum]){
                        k=1;
                        break;
                    }
                }
            if(k == 1){
                board[row][clum] = '.';
                continue;
            }
            for(p=(row/3)*3;p<((row/3)*3+3);p++){   //判断同方格区间有没有相同
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
                if((*result)==true){
                    return;
                }
            }
            else{
                Ifsudoku(board,boardSize,row,clum+1,result);
                if((*result)==true){
                    return;
                }
            }
            board[row][clum] = '.'; //不满足返回时，重置为空

        }

    }
    else{   //是已知数，就跳过
        if(clum == 8){
           Ifsudoku(board,boardSize,row+1,0,result);
           if((*result)==true){
                    return;
                } 
        }
        else{
            Ifsudoku(board,boardSize,row,clum+1,result);
            if((*result)==true){
                    return;
                }
        }
    }
}
void solveSudoku(char** board, int boardSize, int* boardColSize){
    //默认数独是有解得，且返回其第一个解，直接用递归进行判断，求出解后，退出递归
    bool* result = (bool*)malloc(sizeof(bool)*1);   //用于判断是否得出解
    *result = false;
    Ifsudoku(board,boardSize,0,0,result);
    return;

}


// @lc code=end

