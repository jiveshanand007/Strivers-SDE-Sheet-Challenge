bool isValidParenthesis(string s) {
  stack <char> stk;
        if(s[0]==')' || s[0]=='}' || s[0]==']') return false;
        for(auto it:s){
            if(it=='(' || it=='{' || it=='[')
                stk.push(it);
            else if(it==')'){
                if(!stk.empty() && stk.top()=='(') stk.pop();
                else return false;
            }
            else if(it=='}'){
                if(!stk.empty() && stk.top()=='{') stk.pop();
                else return false;
            }
            else{
                if(!stk.empty() && stk.top()=='[') stk.pop();
                else return false;
            }
        }
        if(stk.size()) return false;
        return true;
}