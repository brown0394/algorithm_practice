class Solution {
public:
    bool canBeValid(string s, string locked) {
        if (s.size() % 2 == 1) 
            return false;

        int size = locked.size();
        stack<int> open;
        stack<int> free;
        for (int i = 0; i < size; ++i)
        {
            if (locked[i] == '0')
                free.push(i);
            else
            {
                if (s[i] == ')')
                {
                    if (open.empty() == false)
                        open.pop();
                    else if (free.empty() == false)
                        free.pop();
                    else
                        return false;
                }
                else
                    open.push(i);
            }
        }
        while (open.empty() == false)
        {
            if (free.empty() == true || free.top() < open.top())
                return false;
            free.pop();
            open.pop();
        }
        return true;
    }
};