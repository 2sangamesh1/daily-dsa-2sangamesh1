class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rows(9, vector<bool>(9, false));
        vector<vector<bool>> columns(9, vector<bool>(9, false));
        vector<vector<bool>> boxes(9, vector<bool>(9, false));

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    int num = board[i][j] - '1';
                    int boxindex = (i / 3) * 3 + (j / 3);
                    if(rows[i][num] || columns[j][num] || boxes[boxindex][num]){
                        return false;
                    }

                    rows[i][num] = columns[j][num] = boxes[boxindex][num] = true;
                }
            }
        }

        return true;
    }
};
