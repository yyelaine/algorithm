class Solution {
public:
    /**
     * @param dictionary: a vector of strings
     * @return: a vector of strings
     */
    vector<string> longestWords(vector<string> &dictionary) {
        // write your code here
        vector<string>res;
        int len = 0;
        for(int i=0;i<(int)dictionary.size();i++){
            if(dictionary[i].length()>=len){
                if(dictionary[i].length()>len){
                    res.clear();
                    len = dictionary[i].length();
                }
                res.push_back(dictionary[i]);
            }
        }
        return res;
    }
};