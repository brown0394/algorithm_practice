#include <string>
#include <vector>
#include <map>

using namespace std;

void changeNames(map <string, vector<string*>>& accountRecord, string& str) {
    string id = "";
    string name = "";
    int idx = 7;
    while (str[idx] != ' ') {
        id.push_back(str[idx]);
        ++idx;
    }
    ++idx;
    while (str[idx] != '\0') {
        name.push_back(str[idx++]);
    }
    auto found = accountRecord.find(id);
    char command;
    for (auto it = found->second.begin(); it != found->second.end(); ++it) {
        command = (**it)[(*it)->size() - 1];
        **it = name;
        (*it)->push_back(command);
    }
}

void Enter(map <string, vector<string*>>& accountRecord, string& str,
    vector<string*>& answer) {
    string id = "";
    string name = "";
    int idx = 6;

    while (str[idx] != ' ') {
        id.push_back(str[idx]);
        ++idx;
    }
    auto found = accountRecord.find(id);
    ++idx;
    while (str[idx] != '\0') {
        name.push_back(str[idx++]);
    }
    name.push_back('E');
    answer.push_back(new string(name));
    if (found == accountRecord.end()) {
        auto a = accountRecord.insert(make_pair(id, vector<string*>()));
        a.first->second.push_back(answer.back());
    }
    else {
        string nameToComp = *(found->second[0]);
        name[name.size() - 1] = '\0';
        nameToComp[nameToComp.size() - 1] = '\0';
        if ((found->second[0])->compare(name) == 0) {
            found->second.push_back(answer.back());
        }
        else {
            char lcommand;
            for (auto it = found->second.begin(); it != found->second.end(); ++it) {
                lcommand = (**it)[(*it)->size() - 1];
                name[name.size() - 1] = lcommand;
                (**it) = name;
                name[name.size() - 1] = '\0';
            }
            found->second.push_back(answer.back());
        }
    }
}
void Leave(map <string, vector<string*>>& accountRecord, string& str,
    vector<string*>& answer) {
    string name;
    string id = "";
    int idx = 6;
    while (str[idx] != '\0') {
        id.push_back(str[idx]);
        ++idx;
    }
    auto found = accountRecord.find(id);
    string* test = found->second[0];
    name = *test;
    name[name.size() - 1] = 'L';
    answer.push_back(new string(name));
    found->second.push_back(answer.back());
}

vector<string> solution(vector<string> record) {
    map <string, vector<string*>> accountRecord;
    vector<string> answer;
    vector<string*> temp;
    for (auto iter = record.begin(); iter != record.end(); ++iter) {
        switch ((*iter)[0]) {
        case 'E': {Enter(accountRecord, *iter, temp); break; }
        case 'L': {Leave(accountRecord, *iter, temp); break; }
        default: {changeNames(accountRecord, *iter); break; }
        }
    }
    string ans;
    ans.reserve(100);
    string out = "님이 나갔습니다.";
    string in = "님이 들어왔습니다.";
    for (auto it = temp.begin(); it != temp.end(); ++it) {
        ans = **it;
        switch (ans[ans.size()-1]) {
        case 'E': { ans.pop_back(); ans = ans + in; break; }
        case 'L': { ans.pop_back(); ans = ans + out; break; }
        }
        answer.push_back(ans);
        delete *it;
    }

    return answer;
}

int main() {

    vector<string> record{"Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan"};
    vector<string> answer = solution(record);

    for (auto it = answer.begin(); it != answer.end(); ++it) {
        printf("%s\n", it->c_str());
    }

}