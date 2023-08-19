#include <stdio.h>
#include <stdlib.h>

int lengthOfString(char* s);
char charAt(char* s, int n);
char* removeLastChar(char* s);
char* appendChar(char* s, char c_toAdd);
int isValid(char* s);

int main()
{
   char* s1="()()(){{}}[99]()({})[]uu[](())";
   //char* s1="() [{ }]";
   char* result;
   if(isValid(s1)==0)result=" has not got valid parentheses";
   else result=" has got valid parentheses";
   printf("The string: %s %s.\n\n",s1 , result);

   char* s2="()()(){{}}[99]()({ ] })[]uu[](())";
   if(isValid(s2)==0)result=" has not got valid parentheses";
   else result=" has got valid parentheses";
   printf("The string: %s %s.\n\n",s2 , result);
   
   return(0);
}

int lengthOfString(char* s)
{
   int count=0;
   while(*s!='\0'){count++;*s++;}
   return count;
}

char charAt(char* s, int n)
{ 
   int lenOfString=lengthOfString(s);
   char c='\0';
   if(n<lenOfString)
   {
      for(int i=0; i<n; i++)*s++;
      c=*s;      
   }
   return c;
}

char* removeLastChar(char* s)
{
   int lenOfString=lengthOfString(s);
   char* c_array=malloc(lenOfString*sizeof(char));
   if(lenOfString>0) 
   {     
      for(int i=0; i<lenOfString; i++)
      {  
         if(i<lenOfString-1)
         {
            c_array[i]=*s;
            *s++;
         }
         else  // if(i==lenOfString-1)
         {
            c_array[i]='\0';
         }
      }
   } 
   return c_array;
}

char* appendChar(char* s, char c_toAdd)
{
   int lenOfString=lengthOfString(s);
   char* c_array=malloc((lenOfString+2)*sizeof(char));
   for(int i=0; i<lenOfString+1; i++)
   {  
      if(i<lenOfString)
      {
         c_array[i]=*s;
         *s++;
      }
      else  // if(i==lenOfString)
      {
         c_array[i] = c_toAdd;
         c_array[i+1] = '\0';
      }
   }
   return c_array;
}

int isValid(char* s)
{
   int lenOfString=lengthOfString(s);
   int lenOfTempBrackets;
   char* tempBrackets="";
   char c;
   char lt;  // last temp
   int stillValid=1;
   
   for(int i=0; i<lenOfString; i++)
   {
      c=charAt(s,i);
      if(c=='(' || c=='[' || c=='{')
      {   tempBrackets=appendChar(tempBrackets,c);   }
      else if(c==')' || c==']' || c=='}')
      {
         lenOfTempBrackets=lengthOfString(tempBrackets);
         if(lenOfTempBrackets==0)
         {
            stillValid=0;
            break;
         }
         else
         {
            lt=charAt(tempBrackets,lenOfTempBrackets-1);
            if( (c==')' && lt=='(') || (c==']' && lt=='[') || (c=='}' && lt=='{') )
            {
               tempBrackets=removeLastChar(tempBrackets);
            }
            else if( (c==')' && lt!='(') || (c==']' && lt!='[') || (c=='}' && lt!='{') )
            {
               stillValid=0;
               break;      
            }
         }
      }
   }
   if(lengthOfString(tempBrackets)>0){   stillValid=0;   }
   return stillValid;
}