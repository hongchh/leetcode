class Solution {
public:
    int totalNQueens(int n) {
        size = n;
        count = 0;
        col_free = new bool[size];
        upward_free = new bool[2*size-1];
        downward_free = new bool[2*size-1];
        memset(col_free, 1, sizeof(bool)*size);
        memset(downward_free, 1, sizeof(bool)*(2*size-1));
        memset(upward_free, 1, sizeof(bool)*(2*size-1));
        queens = new int[size];
        result.clear();
        solve();
        return result.size();
    }
private:
    int size;
    int count;
    bool* col_free;
    bool* upward_free;
    bool* downward_free;
    int* queens;
    vector<vector<string> > result;

    void add_queen(int col) {
        queens[count] = col;
        col_free[col] = false;
        upward_free[count+col] = false;
        downward_free[count-col+size-1] = false;
        ++count;
    }
    void remove_queen(int col) {
        --count;
        col_free[col] = true;
        upward_free[count+col] = true;
        downward_free[count-col+size-1] = true;
    }
    void solve() {
        if (count == size) {
            vector<string> r;
            for (int i = 0; i < size; ++i) {
                string c(size, '.');
                c[queens[i]] = 'Q';
                r.push_back(c);
            }
            result.push_back(r);
        } else {
            for (int col = 0; col < size; ++col) {
                if (col_free[col] && upward_free[count+col] &&
                    downward_free[count-col+size-1]) {
                    add_queen(col);
                    solve();
                    remove_queen(col);
                }
            }
        }
    }
};
