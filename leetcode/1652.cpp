class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int size = code.size();
        vector<int> decryptionCode(code.size());
        if (k == 0) return decryptionCode;
        if (size == 1) return code;
        int left, right;
        int sum = 0;
        if (k > 0) {
            left = 1;
            right = k;
            for (int i = 1; i <= k; ++i) sum += code[i];
        }
        else {
            right = size - 1;
            left = size + k;
            for (int i = left; i <= right; ++i) sum += code[i];
        }
        for (int i = 0; i < size; ++i) {
            decryptionCode[i] = sum;
            sum -= code[left];
            left = (left + 1) % size;
            right = (right + 1) % size;
            sum += code[right];
        }
        return decryptionCode;
    }
};