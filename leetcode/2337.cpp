class Solution {
public:
    bool canChange(string start, string target) {
        int slen = start.size(), tlen = target.size();
        int sidx = 0, tidx = 0;
        while (true) {
            while (sidx < slen && start[sidx] == '_') ++sidx;
            while (tidx < tlen && target[tidx] == '_') ++tidx;
            if (sidx == slen || tidx == tlen) break;
            if (start[sidx] != target[tidx]) return false;
            if (start[sidx] == 'L' && sidx < tidx) return false;
            if (start[sidx] == 'R' && sidx > tidx) return false;
            ++sidx; ++tidx;
        }
        return (sidx == slen && tidx == tlen);
    }
};