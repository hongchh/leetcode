class Solution {
public:
    string getHint(string secret, string guess) {
        memset(ch, 0, sizeof(ch));
        for (int i = 0; i < secret.size(); ++i)
            ++ch[secret[i]-'0'];
        int bulls = 0, cows = 0;
        for (int i = 0; i < guess.size(); ++i) {
            if (guess[i] == secret[i]) {
                ++bulls;
                --ch[guess[i]-'0'];
            }
        }
        for (int i = 0; i < guess.size(); ++i) {
            if (guess[i] != secret[i] && ch[guess[i]-'0'] > 0) {
                ++cows;
                --ch[guess[i]-'0'];
            }
        }
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
private:
    int ch[10];
};