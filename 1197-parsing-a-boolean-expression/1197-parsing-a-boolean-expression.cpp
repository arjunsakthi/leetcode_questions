class Solution {
public:
    bool eval(vector<bool> val, char oper){
        int op = 0;
        if(oper == '&') op = 0;
        if(oper == '|') op = 1;
        if(oper == '!') op = 2;
        if(op == 1){
            bool ored = false;
            for(auto i : val){
                ored |= i;
            }
            return ored;
        }else if(op == 0){
            bool aned = true;
            for(auto i:val){
                aned &= i;
            }
            return aned;
        }
        else{
            return !val[0];
        }
    }
    bool f(string expression,int low,int high){
        // low = 0, high = expression.size()-1
        if(low == high) return expression[low] == 'f'?false:true;
        vector<bool> val;
        int op = expression[low] == '!'? 2:expression[low] == '|'?1:0;
        int i=low+2;
        while(i<=high){
            int open = 0;
            int close = 0;
            int k = i;
            while(i<=high){
                if((open == close) && (expression[i] == ',' || expression[i] == ')')){
                    i++;
                    break;
                }
                if(expression[i] == '(')    open++;
                if(expression[i] == ')')    close++;
                i++;
            }
            val.push_back(f(expression,k,i-2));
        }
        return eval(val,op);
    }
    bool parseBoolExpr(string expression) {
        // return f(expression, 0,expression.size()-1);
        stack<char> st;
        int i=0;
        if(expression.size() == 1)  return expression[0] == 'f'?false:true;
        while(i<expression.size()){
            while(expression[i] != ')' && i<expression.size()){
                st.push(expression[i]);
                i++;
            }
            i++;
            vector<bool> val;
            while(st.top() != '('){
                char k = st.top();
                st.pop();
                if(k == ',') continue;
                if(k == 'f') val.push_back(false);
                if(k == 't') val.push_back(true);
            }
            st.pop();
            char op = st.top();
            st.pop();
            bool res = eval(val,op);
            st.push(res == true? 't':'f');
        }
        return st.top() == 'f'?false:true;
    }
};