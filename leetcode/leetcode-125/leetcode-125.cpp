#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
		int right = 1;
		int len = s.length();
		
		for (int i=0;i<len;i++) {
			while (!isalnum(s[i + left])) {
				left++;
				if (i + left >= len) return true;
			}

			while (!isalnum(s[len - i - right])) {
				right++;
				if (i + left + right >= len) return true;
			}

			if (tolower(s[i + left]) != tolower(s[len - i - right])) {
				return false;
			}
		}

		return true;
    }
}; 


int main()
{
	Solution s;
	bool res = s.isPalindrome("A man, a plan, a canal: Panama");
	cout << "res: " << (res ? "true" : "false") << endl;

	return 0;
}