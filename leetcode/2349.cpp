class NumberContainers {
public:
    unordered_map<int, int> idxNum;
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> numIdx;
    NumberContainers() {
    }
    
    void change(int index, int number) {
        auto foundIdxNum = idxNum.find(index);
        if (foundIdxNum == idxNum.end())
            idxNum[index] = number;
        else
            foundIdxNum->second = number;
        numIdx[number].push(index);
    }
    
    int find(int number) {
        auto found = numIdx.find(number);
        if (found == numIdx.end())
            return -1;
        while (found->second.empty() == false)
        {
            if (idxNum[found->second.top()] == number)
                return found->second.top();
            found->second.pop();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */