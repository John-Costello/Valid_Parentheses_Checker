#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int lenOfString=s.size();   // length()
        int lenOfTempBrackets;
        string tempBrackets="";
        char c;
        char lt;  // last temp
        bool stillValid=true;
        for(int i=0; i<lenOfString; i++)
        {
            c=s.at(i);    // charAt()
            if(c=='(' || c=='[' || c=='{')
            {    tempBrackets+=c;   }
            else if(c==')' || c==']' || c=='}')
            {
                lenOfTempBrackets=tempBrackets.size();  
                if(lenOfTempBrackets==0)
                {
                    stillValid=false;
                    break;
                }
                else
                {
                    lt=tempBrackets.at(lenOfTempBrackets-1);  
                    if( (c==')' && lt=='(') || (c==']' && lt=='[') || (c=='}' && lt=='{') )
                    {
                        tempBrackets=tempBrackets.substr(0,lenOfTempBrackets-1);
                    }
                    else if( (c==')' && lt!='(') || (c==']' && lt!='[') || (c=='}' && lt!='{') )
                    {
                        stillValid=false;
                        break;
                    }
                }
            }
        }
        if(tempBrackets.size()>0) stillValid=false;
        
        return stillValid;
    }
};

int main()
{
    Solution solution;
    string s1="()()()(){{}}[][99]()({})[]uu[](())";
    if(solution.isValid(s1))
    {   cout << "The string: " << s1 << " has got valid parentheses." << endl;   }
    else
    {   cout << "The string: " << s1 << " has not got valid parentheses." << endl;   }

    string s2="()()()(){{}}[][99]()({ ] })[]uu[](())";
    if(solution.isValid(s2))
    {   cout << "The string: " << s2 << " has got valid parentheses." << endl;   }
    else
    {   cout << "The string: " << s2 << " has not got valid parentheses." << endl;   }

    return 0;
}

