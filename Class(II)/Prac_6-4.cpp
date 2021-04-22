#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    stack<char> par;
    string pars;
    cin>>pars;
    for(int i=0; i<pars.size(); i++)
    {
        if(pars[i]=='(')
            par.push('(');
        else if(pars[i]==')')
        {
            if(!par.empty()&&par.top()=='(')
                par.pop();
            else
            {
                cout<<0<<endl;
                return 0;
            }
        }
    }
    if(!par.empty())
        cout<<0<<endl;
    else
        cout<<1<<endl;
    return 0;
}