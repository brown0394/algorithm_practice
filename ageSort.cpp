#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <iterator>

class memberInfo{
private:
    int _age;
    std::string _name;
    int _idx;

public:
    memberInfo(int p_age, char* p_name, int idx): _age(p_age), _name(p_name), _idx(idx){}
    bool operator < (memberInfo& other);
    friend std::ostream& operator << (std::ostream &out, const memberInfo& member);
};

bool memberInfo::operator<(memberInfo& other) {
    if (this->_age == other._age) {
        return this->_idx < other._idx;
    }
    return this->_age < other._age;
}

std::ostream& operator << (std::ostream &out, const memberInfo& member) {
    return out << member._age << ' ' << member._name;
}

int main() {
    int num, ageIn;
    char nameIn[105];
    std::vector <memberInfo> arr;

    scanf("%d", &num);

    for (int i = 0; i < num; ++i) {
        scanf("%d %s", &ageIn, nameIn);
        arr.push_back(memberInfo(ageIn, nameIn, i));
    }
    std::sort(arr.begin(), arr.end());
    std::copy(arr.begin(), arr.end(), std::ostream_iterator<memberInfo>(std::cout, "\n"));
}