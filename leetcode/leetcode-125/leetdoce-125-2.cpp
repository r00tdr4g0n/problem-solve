#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) 
	{
		int len = s.length();
		int left = 0;
		int right = len - 1;

		while(left < right) {
			while(!isalnum(s[left]) && left < right) {
				left++;
			}
			
			while(!isalnum(s[right]) && left < right) {
				right--;
			}

			if (tolower(s[left]) != tolower(s[right])) {
				return false;
			}

			left++; 
			right--;
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