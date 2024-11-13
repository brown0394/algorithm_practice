#include <string>
#include <vector>

using namespace std;


string solution(string p) {
    if (p.empty()) return "";
    string u;
    int open = 0, close = 0;
    bool broken = false;
    int i = 0, len = p.size();
    for (; i < len; ++i) {
        if (p[i] == '(') ++open;
        else {
            ++close;
            if (open < close) broken = true;
        }
        u.push_back(p[i]);
        if (open == close) {
            ++i;
            break;
        }
    }
    if (broken) {
        string ans;
        ans.push_back('(');
        ans += solution(p.substr(i, len));
        ans.push_back(')');
        for (int i = 1, len = u.size()-1; i < len; ++i) {
            if (u[i] == ')') ans.push_back('(');
            else ans.push_back(')');
        }
        return ans;
    }
    return u + solution(p.substr(i, len));
}