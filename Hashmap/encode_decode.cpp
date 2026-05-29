/*
    LeetCode 535 - Encode and Decode TinyURL
    Link: https://leetcode.com/problems/encode-and-decode-tinyurl/

    Approach:
    - Generate a hash key for the long URL.
    - Store key -> long URL in unordered_map.
    - If collision occurs, keep increasing key using while loop.
    - Decode by extracting key from short URL and returning original URL.
*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<size_t, string> map;

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        size_t key = hash<string>{}(longUrl);

        while (map.count(key) && map[key] != longUrl) {
            key++;
        }

        map[key] = longUrl;

        return "https://tinyUrl/" + to_string(key);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        size_t key = stoull(shortUrl.substr(shortUrl.rfind('/') + 1));
        return map[key];
    }
};

int main() {
    Solution solution;

    string url = "https://leetcode.com/problems/encode-and-decode-tinyurl/";

    string shortUrl = solution.encode(url);
    string originalUrl = solution.decode(shortUrl);

    cout << "Original URL: " << url << endl;
    cout << "Short URL: " << shortUrl << endl;
    cout << "Decoded URL: " << originalUrl << endl;

    return 0;
}