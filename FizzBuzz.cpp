#include <iostream>

using namespace std;

int main()
{
    vector<string> fizzBuzz(int n) {
        ArrayList<string> results;
        for (int i = 1; i <= n; i++) {
            if (i % 15 == 0) {
                results.push_back("fizz buzz");
            } else if (i % 5 == 0) {
                results.push_back("buzz");
            } else if (i % 3 == 0) {
                results.push_back("fizz");
            } else {
                results.push_back(string.valueOf(i));
            }
        }
        return results;
    }
}
