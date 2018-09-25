class Solution {
public:
    bool isValid(string s) {
        int i,len=s.length();
        if(len==0)
            return true;
        stack<char> left;
        for(i=0;i<len;i++)
        {
            if(s[i]=='('||s[i]=='['||s[i]=='{')
                left.push(s[i]);
            else
            {
                if(left.empty())
                    return false;
                char x=left.top();
                left.pop();
                if(x=='['&&s[i]==']')
                    continue;
                if(x=='{'&&s[i]=='}')
                    continue;
                if(x=='('&&s[i]==')')
                    continue;
                return false;
            }
        }
        if(left.empty())
            return true;
        return false;
    }
};
