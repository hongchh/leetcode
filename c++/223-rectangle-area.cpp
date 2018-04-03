class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int left = A > E ? A : E;
        int right = C < G ? C : G;
        int bottom = B > F ? B : F;
        int top = D < H ? D : H;
        int s = (right-left)*(top-bottom);
        if (right <= left) s = 0;
        if (top <= bottom) s = 0;
        return (C-A)*(D-B)+(G-E)*(H-F)-s;
    }
};