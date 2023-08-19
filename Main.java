public class Main
{
    public static void main(String[] args)
    {
        String s1="()()()(){{}}[][99]()({})[]uu[](())";
        String result;
        if(new Solution().isValid(s1))result=" has got valid parentheses.";
        else result=" has not got valid parentheses.";
        System.out.println("The string: "+s1+result+"\n");
        
        String s2="()()()(){{}}[][99]()({ ] })[]uu[](())";
        if(new Solution().isValid(s2))result=" has got valid parentheses.";
        else result=" has not got valid parentheses.";
        System.out.println("The string: "+s2+result+"\n");
    }
}
