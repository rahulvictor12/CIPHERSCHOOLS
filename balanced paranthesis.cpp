//balanced paranthesis
bool isValid( string s) {
        int len = s.length();
        stack<int> st;
        st.push(s[0]);
        for(int i=1;i<len;i++){
            if(s[i]=='(' || s[i]=='{'||s[i]=='['){
                st.push(s[i]);
            }    
            else if(s[i]==')' ){
                if(!st.empty() && st.top() == '(') st.pop();
                else st.push(s[i]);
            }
            else if(s[i]=='}' ){
                if(!st.empty() &&  st.top() == '{') st.pop();
                else st.push(s[i]);
            }
            else if(s[i]==']' ){
                if(!st.empty() &&  st.top() == '[') st.pop();
                else st.push(s[i]);
            }
        }
        if(len==0) 
		return 1;
        else if(st.empty())
		 return 1;
        else return 0;
    }
