class NumberContainers {
public:
    unordered_map<int, int> idxNum;
    unordered_map<int, set<int>> numIdx;
    NumberContainers() {
    }
    
    void change(int index, int number) {
        auto foundIdxNum = idxNum.find(index);
        if (foundIdxNum == idxNum.end())
            idxNum[index] = number;
        else
        {
            if (foundIdxNum->second == number)
                return;
            if (numIdx[foundIdxNum->second].size() == 1)
                numIdx.erase(foundIdxNum->second);
            else
                numIdx[foundIdxNum->second].erase(index);
            foundIdxNum->second = number;
        }
        numIdx[number].insert(index);
    }
    
    int find(int number) {
        auto found = numIdx.find(number);
        if (found == numIdx.end())
            return -1;
        return *found->second.begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */