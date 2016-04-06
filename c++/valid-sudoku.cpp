class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // check row
        for (int i = 0; i < board.size(); ++i) {
            set<char> ithRow;
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == '.') continue;
                if (ithRow.find(board[i][j]) != ithRow.end())
                    return false;
                ithRow.insert(board[i][j]);
            }
        }
        // check col
        for (int j = 0; j < board[0].size(); ++j) {
            set<char> jthCol;
            for (int i = 0; i < board.size(); ++i) {
                if (board[i][j] == '.') continue;
                if (jthCol.find(board[i][j]) != jthCol.end())
                    return false;
                jthCol.insert(board[i][j]);
            }
        }
        // check block
        for (int i = 0; i < board.size(); i += 3) {
            for (int j = 0; j < board[i].size(); j += 3) {
                set<char> kthBlock;
                for (int k = 0; k < 3; ++k) {
                    for (int l = 0; l < 3; ++l) {
                        if (board[i+k][j+l] == '.')
                            continue;
                        if (kthBlock.find(board[i+k][j+l]) != kthBlock.end())
                            return false;
                        kthBlock.insert(board[i+k][j+l]);
                    }
                }
            }
        }
        return true;
    }
};