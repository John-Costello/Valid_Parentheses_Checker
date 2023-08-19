class Solution {
    public boolean isValid(String s) {
        int lenOfString=s.length();
        int lenOfTempBrackets;
        String tempBrackets="";
        char c;
        char lt;  // last temp
        boolean stillValid=true;
        for(int i=0; i<lenOfString; i++)
        {
            c=s.charAt(i);
            if(c=='(' || c=='[' || c=='{') 
            {    tempBrackets+=c;    }
            else if(c==')' || c==']' || c=='}') 
            {
                lenOfTempBrackets=tempBrackets.length();
                if(lenOfTempBrackets==0) 
                {
                    stillValid=false;
                    break;   
                }
                else
                {
                    lt=tempBrackets.charAt(lenOfTempBrackets-1); 
                    if( (c==')' && lt=='(') || (c==']' && lt=='[') || (c=='}' && lt=='{') )
                    {
                        tempBrackets=tempBrackets.substring(0,lenOfTempBrackets-1);
                    }
                    else if( (c==')' && lt!='(') || (c==']' && lt!='[') || (c=='}' && lt!='{') )
                    {
                        stillValid=false;
                        break;
                    }
                }              
            }           
        }
        
        if(tempBrackets.length()>0) stillValid=false;
        
        return stillValid;
    }
}