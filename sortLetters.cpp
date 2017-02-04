class Solution {
public:
    /** 
     * @param chars: The letters array you should sort.
     */
    void sortLetters(string &letters) {
        // write your code here
        int j = 0;
		while (letters[j] >= 'a')
		{
			j++;
		}
		for (int i = j; i < letters.size(); i++)
		{
			if (letters[i] >= 'a')
			{
				char tmp = letters[i];
				letters[i] = letters[j];
				letters[j] = tmp;
				j++;
			}
		}
		return;
    }
};
