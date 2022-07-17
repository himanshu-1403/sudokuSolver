class Solution {
public:
    bool findEmptyPos(vector<vector<char>>&board, int &row, int &col){  //it returns empty position co-ordinates, row & col are passed by reference
    
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]=='.'){
                row=i;
                col=j;
                return true;
            }
        }
    }
    return false;
}
bool isSafeInRow(vector<vector<char>>&board, int row, char num){  //it checks whether num exists in current row
    
    for(int i=0;i<9;i++){
        if(board[row][i]==num) return false;
    }
    return true;
}

bool isSafeInCol(vector<vector<char>>&board, int col, char num){  //it checks whether num exists in current column
    
    for(int i=0;i<9;i++){
        if(board[i][col]==num) return false;
    }
    return true;
}

bool isSafeInGrid(vector<vector<char>>&board, int row, int col, char num){  //it checks whether current num exists in it's respectiver 3*3 grid
    
    int rowF=row-(row%3);
    int colF=col-(col%3);
    
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i+rowF][j+colF]==num) return false;
        }
    }
    return true;
}

bool isSafe(vector<vector<char>>&board, int row, int col, char num){  //it return true if current num can be placed in grid
    
    if(isSafeInRow(board,row,num) && isSafeInCol(board,col,num) && isSafeInGrid(board,row,col,num)){
        return true;
    }
    return false;
}
bool helper(vector<vector<char>>&board){
    
    int row, col;
    
    if(!findEmptyPos(board,row,col)){  //if no empty position found return true
        return true;
    }
            
    for(char i='1'; i<='9'; i++){  //numbers can be filled from 1 to 9 only
        
        if(isSafe(board,row,col,i)){
            board[row][col]=i;
            if(helper(board)==true) return true;
            board[row][col]='.';                  //backtrack
        }
        
    }
    return false;
    
}

void solveSudoku(vector<vector<char>>& board) {
    
    helper(board);
}
};
