class Solution {
public:
    const int MOD = 1e9 + 7;

    using ll = long long;
    using Matrix = vector<vector<int>>;

    
    vector<ll> multiplyVecMat(const vector<ll>& vec, const Matrix& mat) {
        vector<ll> result(26, 0);
        for (int j = 0; j < 26; ++j) {
            for (int i = 0; i < 26; ++i) {
                result[j] = (result[j] + vec[i] * mat[i][j]) % MOD;
            }
        }
        return result;
    }

    Matrix multiplyMat(const Matrix& A, const Matrix& B) {
        Matrix res(26, vector<int>(26, 0));
        for (int i = 0; i < 26; ++i) {
            for (int k = 0; k < 26; ++k) {
                if (A[i][k] == 0) continue;
                for (int j = 0; j < 26; ++j) {
                    res[i][j] = (res[i][j] + 1LL * A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return res;
    }

  
    Matrix matrixPower(Matrix base, int power) {
        Matrix result(26, vector<int>(26, 0));
        for (int i = 0; i < 26; ++i) result[i][i] = 1;  // Identity matrix
        while (power > 0) {
            if (power % 2) result = multiplyMat(result, base);
            base = multiplyMat(base, base);
            power /= 2;
        }
        return result;
    }

    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<ll> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        // Build the transformation matrix
        Matrix trans(26, vector<int>(26, 0));
        for (int i = 0; i < 26; ++i) {
            for (int j = 1; j <= nums[i]; ++j) {
                int target = (i + j) % 26;
                trans[i][target]++;
            }
        }

        // Raise the transformation matrix to the t-th power
        Matrix transT = matrixPower(trans, t);

     
        vector<ll> finalCount = multiplyVecMat(count, transT);

        
        ll total = 0;
        for (ll val : finalCount) {
            total = (total + val) % MOD;
        }

        return total;
    }
};
