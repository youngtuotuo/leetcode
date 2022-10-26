#include <iostream>
#include <string>
#include <vector>
using namespace std;


// https://leetcode.com/problems/encode-and-decode-strings/
// O(n), O(1)
class Codec {
public:
  string encode(vector<string> &strs) {
    //
    string res = "";
    for (string s: strs) {
      res += to_string(s.size()) + "#" + s;
    }
    return res;
  }
  vector<string> decode(string s) {
    vector<string> res;
    int j = 0, i = 0;
    while (i < s.size()) {
      j = i;
      while (s[j] != '#') {
        j++;
      }
      int length = stoi(s.substr(i, j - i));
      string str = s.substr(j + 1, length);
      res.push_back(str);
      i = j + 1 + length;
    }
    return res;
  }
};


int main (int argc, char *argv[])
{
  vector<string> strs = {"leet", "code", "love", "you"};
  Codec sol = Codec();
  string en = sol.encode(strs);
  cout << en << endl;
  vector<string> de = sol.decode(en);
  for (string s: de) {
    cout << s << ", ";
  }
  cout << endl;
  return 0;
}
