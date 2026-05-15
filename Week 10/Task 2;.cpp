//#include <iostream>
//using namespace std;
//
//
//int getLength(string s, int i) {
//    if (s[i] == '\0') {
//        return i;
//    }
//
//    return getLength(s, i + 1);
//
//}
//
//
//bool isPalindrome(string str, int s, int e) {
//
//    if (s >= e) {
//        return true;
//    }
//
//
//    if (str[s] != str[e]) {
//        return false;
//    }
//
// 
//    return isPalindrome(str, s + 1, e - 1);
//}
//
//int main() {
//    string input;
//    cout << "Enter a word: ";
//    cin >> input;
//
//   
//    int len = getLength(input, 0);
//
//    
//    if (isPalindrome(input, 0, len - 1)) {
//        cout << "It is a palindrome!" << endl;
//    }
//    else {
//        cout << "It is not a palindrome." << endl;
//    }
//
//    return 0;
//}