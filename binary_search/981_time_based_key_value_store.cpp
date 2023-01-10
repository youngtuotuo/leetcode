#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/* Design a time-based key-value data structure that can store multiple values
for the same key at different time stamps and retrieve the key's value at a
certain timestamp.

Implement the TimeMap class:

TimeMap() Initializes the object of the data structure.

void set(String key, String value, int timestamp) Stores the key key with
the value value at the given time timestamp.

String get(String key, int timestamp) Returns a value such that set was called
previously, with timestamp_prev <= timestamp. If there are multiple such
values, it returns the value associated with the largest timestamp_prev. If
there are no values, it returns "".

https://leetcode.com/problems/time-based-key-value-store/
O(log n), O(n)
*/

class TimeMap {
public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        keyStore[key].push_back({value, timestamp});
    }

    string get(string key, int timestamp) {
        if (keyStore.find(key) == keyStore.end()) {
            return "";
        }

        int l(0), r(keyStore[key].size() - 1);

        string res("");
        while (l <= r) {
            int m = l + (r - l) / 2;
            // timestamp is naturally in order
            if (keyStore[key][m].second <= timestamp) {
                res = keyStore[key][m].first;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return res;
    }

private:
    unordered_map<string, vector<pair<string, int>>> keyStore;
};

int main(int argc, char *argv[]) {
    TimeMap tm = TimeMap();
    tm.set("foo", "bar", 1);
    cout << tm.get("foo", 1) << endl;
    cout << tm.get("foo", 3) << endl;
    tm.set("foo", "bar2", 1);
    cout << tm.get("foo", 4) << endl;
    cout << tm.get("foo", 5) << endl;
    return 0;
}
