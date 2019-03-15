/*
Problem 65: Valid Number

Validate if a given string can be interpreted as a decimal number.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
" -90e3   " => true
" 1e" => false
"e3" => false
" 6e-1" => true
" 99e2.5 " => false
"53.5e93" => true
" --6 " => false
"-+3" => false
"95a54e53" => false

Note: It is intended for the problem statement to be ambiguous. You should gather 
all requirements up front before implementing one. However, here is a list of 
characters that can be in a valid decimal number:

Numbers 0-9
Exponent - "e"
Positive/negative sign - "+"/"-"
Decimal point - "."
Of course, the context of these characters also matters in the input.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your 
function signature accepts a const char * argument, please click the reload 
button to reset your code definition.

*/

/* Time: 16ms */
class Solution {
public:
  bool isNumber(string s) {
		//trim whitespace
		trimString(s);
		//find 'e'
		int pos = s.find('e');
		if (pos == 0 || pos == s.size() - 1)
			return false;
		if (pos == -1) {
			return isFloat(s);
		} else {
			return isFloat(s.substr(0, pos)) && isInt(s.substr(pos + 1));
		}
	}

	void trimString(string &s) {
		int pos = s.find_first_not_of(" ");
		if (pos != -1)
			s = s.substr(pos);
		pos = s.find_last_not_of(" ");
		if (pos != -1)
			s.erase(s.begin() + pos + 1, s.end());
	}

	bool isFloat(string s) {
		if (s[0] == '-' || s[0] == '+')
			s = s.substr(1);
		int pos = s.find('.');
		if (pos == -1) {
			return isPositiveInt(s);
		} else if (pos == 0) {
			return isPositiveInt(s.substr(1));
		} else if (pos == s.size() - 1) {
			s.erase(pos);
			return isPositiveInt(s);
		} else {
			return isPositiveInt(s.substr(0, pos)) && isPositiveInt(s.substr(pos + 1));
		}
	}

	bool isInt(string s) {
		if (s[0] == '-' || s[0] == '+')
			s = s.substr(1);
		return isPositiveInt(s);
	}

	bool isPositiveInt(string s) {
		if (s.size() == 0)
			return false;
		for (char c : s) {
			if (!(c >= '0' && c <= '9'))
				return false;
		}
		return true;
	}
};