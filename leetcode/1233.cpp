class Solution {
    bool isSubT(string& one, string& two) {
        for (int i = 0, len = one.size(); i < len; ++i) {
            if (one[i] != two[i]) return false;
        }
        if (two[one.size()] == '/') return true;
        return false;
    }
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        string last = folder[0];
        vector<string> ans;
        ans.push_back(last);
        
        for (int i = 1, len = folder.size(); i < len; ++i) {
            if (folder[i].size() == last.size() && folder[i] == last) continue; 
            else if (folder[i].size() < last.size() || !isSubT(last, folder[i])) {
                last = folder[i];
                ans.push_back(folder[i]);
            }
        }
        return ans;
    }
};
