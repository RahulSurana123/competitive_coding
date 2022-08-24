
#include <bits/stdc++.h>
#define ll          long long
#define vl          vector<ll>
#define vi          vector<int>
#define pi          pair<int,int>
#define pl          pair<ll,ll>
#define all(a)      a.begin(),a.end()
#define mem(a,x)    memset(a,x,sizeof(a))
#define pb          push_back
#define mp          make_pair
#define F           first
#define S           second
#define trace(x)    cerr<<#x<<" : "<<x<<endl;
#define trace2(x,y) cerr<<#x<<" : "<<x<<" | "<<#y<<" : "<<y<<endl;
#define trace3(x,y,z) cerr<<#x<<" : "<<x<<" | "<<#y<<" : "<<y<<" | "<<#z<<" : "<<z<<endl;
#define fast_io     std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

using namespace std;

 
// Function to find precedence of
// operators.
int precedence(char op){
    if(op == '+'||op == '-')
    return 1;
    if(op == '*'||op == '/')
    return 2;
    return 0;
}
 
// Function to perform arithmetic operations.
int applyOp(int a, int b, char op){
    switch(op){
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
}
 
// Function that returns value of
// expression after evaluation.
int evaluate(string tokens){
    int i;
     
    // stack to store integer values.
    stack <int> values;
     
    // stack to store operators.
    stack <char> ops;
     
    for(i = 0; i < tokens.length(); i++){
         
        if(tokens[i] == ' ')
            continue;
         
        else if(tokens[i] == '('){
            ops.push(tokens[i]);
        }
         
        else if(isdigit(tokens[i])){
            int val = 0;
             
            while(i < tokens.length() &&
                        isdigit(tokens[i]))
            {
                val = (val*10) + (tokens[i]-'0');
                i++;
            }
            cout << val <<" pushed in values \n";
            values.push(val);
              i--;
        }
         
        else if(tokens[i] == ')')
        {   cout << ") encountered solving the thing";
            while(!ops.empty() && ops.top() != '(')
            {
                int val2 = values.top();
                values.pop();
                 
                int val1 = values.top();
                values.pop();
                 
                char op = ops.top();
                ops.pop();
                int z;
                values.push(z = applyOp(val1, val2, op));
                cout << val1 << " " << op <<" "<< val2 << " " << z <<"\n";
            }
             
            if(!ops.empty())
               ops.pop();
        }
         
        else
        {
            while(!ops.empty() && precedence(ops.top())
                                >= precedence(tokens[i])){
                int val2 = values.top();
                values.pop();
                 
                int val1 = values.top();
                values.pop();
                 
                char op = ops.top();
                ops.pop();
                int z; 
                values.push(z = applyOp(val1, val2, op));
                cout << val1 << " " << op <<" "<< val2 << " " << z <<"\n";
            }
             
            ops.push(tokens[i]);
        }
    }
     
    while(!ops.empty()){
        int val2 = values.top();
        values.pop();
                 
        int val1 = values.top();
        values.pop();
                 
        char op = ops.top();
        ops.pop();

        int z;
        values.push(z = applyOp(val1, val2, op));
        cout << val1 << " " << op <<" "<< val2 << " " << z <<"\n";    
    }
     
    // Top of 'values' contains result, return it.
    return values.top();
}
 
int main() {
    // cout << evaluate("10 + 2 * 6") << "\n";
    // cout << evaluate("100 * 2 + 12") << "\n";
    // cout << evaluate("100 * ( 2 + 12 )") << "\n";
    cout << evaluate("100 * ( 2 + 12 ) / 14");
    return 0;
}