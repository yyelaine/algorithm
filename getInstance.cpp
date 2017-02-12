class Solution {
public:
    /**
     * @return: The same instance of this class every time
     */
    static Solution* getInstance() {
        // write your code here
         static bool ex=false;
        static Solution* one;
        if(ex==false)
        {
             one=new Solution();
             ex=true;
             return one;
        }
        else
        return one;
    }
};