#include <string>
#include <vector>

using namespace std;

bool compareGreaterEqual(string& one, string& two) {
    if (two[0] < one[0]) return false;
    if (two[0] > one[0]) return true;
    if (two[1] < one[1]) return false;
    if (two[1] > one[1]) return true;
    if (two[3] < one[3]) return false;
    if (two[3] > one[3]) return true;
    if (two[4] < one[4]) return false;
    return true;
}

bool compareLesserEqual(string& one, string& two) {
    if (two[0] > one[0]) return false;
    if (two[0] < one[0]) return true;
    if (two[1] > one[1]) return false;
    if (two[1] < one[1]) return true;
    if (two[3] > one[3]) return false;
    if (two[3] < one[3]) return true;
    if (two[4] > one[4]) return false;
    return true;
}

void next(string& pos, string& video_len) {
    if (pos[3] + 1 > '5') {
        pos[3] = '0';
        if (pos[1] + 1 > '9') {
            pos[1] = '0';
            if (pos[0] + 1 > '5') {
                pos = video_len;
                return;
            }
            else ++pos[0];
        }
        else ++pos[1];
    }
    else ++pos[3];
    if (compareGreaterEqual(video_len, pos)) {
        pos = video_len;
        return;
    }
}

void prev(string& pos) {
    if (pos[3] - 1 < '0') {
        pos[3] = '5';
        if (pos[1] - 1 < '0') {
            pos[1] = '9';
            if (pos[0] - 1 < '0') {
                pos = "00:00";
                return;
            }
            else --pos[0];
        }
        else --pos[1];
    }
    else --pos[3];
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    if (compareGreaterEqual(op_start, pos) && compareLesserEqual(op_end, pos)) {
        pos = op_end;
    }
    for (string& cmd : commands) {
        if (cmd[0] == 'n') next(pos, video_len);
        else prev(pos);
        if (compareGreaterEqual(op_start, pos) && compareLesserEqual(op_end, pos)) {
            pos = op_end;
        }
    }
    
    return pos;
}