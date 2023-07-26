#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstdlib>

int main() {
    int numOfPokemons;
    int numOfProblems;
    scanf("%d %d", &numOfPokemons, &numOfProblems);

    std::vector<char[21]> pokeList(numOfPokemons);
    std::map<std::string, int> pokeIndex;
    int idx = 1;
    for (auto iter = pokeList.begin(); iter != pokeList.end(); ++iter) {
        scanf("%s", *iter);
        pokeIndex.insert(std::make_pair(*iter, idx++));
    }
    char prob[21];
    for (int i = 0; i < numOfProblems; ++i) {
        scanf("%s", prob);
        if (prob[0] >= '0' && prob[0] <= '9') {
            printf("%s\n", pokeList[atoi(prob) - 1]);
        }
        else {
            auto found = pokeIndex.find(prob);
            printf("%d\n", found->second);
        }
    }
    
}