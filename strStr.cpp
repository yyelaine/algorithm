class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        // write your code here
        //string::size_type position;
        if (source == NULL || target == NULL)
            return -1;
        int l1=strlen(source);
        int l2=strlen(target);
        for(int i=0;i<l1-l2+1;i++)
        {
            int j;
            for(j=0;j<l2;j++)
            {
                if (source[i+j]!=target[j])
                break;
            }
            if (j==l2)
            return i;
            
        }
    return -1;
}
};