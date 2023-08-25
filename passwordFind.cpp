#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, std::string> passDictionary;
    int passwords, toFind;
    scanf("%d %d", &passwords, &toFind);
    char url[21], pass[21];
    for (int i = 0; i < passwords; ++i) {
        scanf("%s %s", url, pass);
        passDictionary.insert(std::make_pair(url, pass));
    }
    for (int i = 0; i < toFind; ++i) {
        scanf("%s", url);
        auto found = passDictionary.find(url);
        printf("%s\n", found->second.c_str());
    }
}