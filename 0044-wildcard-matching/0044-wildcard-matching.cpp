class Solution {
public:
    int t[2001][2001];

    bool solve(string& s, string& p, int i, int j) {

        if (i < 0 && j < 0) {
            return true;
        }

        if (i < 0 && j >= 0) {
            for (int k = 0; k <= j; k++) {
                if (p[k] != '*') {
                    return false;
                }
            }
            return true;
        }

        if (j < 0 && i >= 0) {
            return false;
        }

        if (t[i][j] != -1) {
            return t[i][j];
        }

        if (s[i] == p[j] || p[j] == '?') {
            return t[i][j] = solve(s, p, i - 1, j - 1);
        }

        if (p[j] == '*') {
            return t[i][j] = solve(s, p, i, j - 1) || solve(s, p, i - 1, j);
        }

        return t[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();

        memset(t, -1, sizeof(t));
        return solve(s, p, n-1, m-1);
    }
};