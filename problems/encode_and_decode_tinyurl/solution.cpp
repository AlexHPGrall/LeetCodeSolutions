class Solution {
    int hshCnt=0;
    unordered_map<string, int> urlEncodeMap;
    unordered_map<int, string> urlDecodeMap;
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(!urlEncodeMap.count(longUrl))
        {
            hshCnt++;
            urlEncodeMap[longUrl]=hshCnt;
            urlDecodeMap[hshCnt]=longUrl;
        }
        return to_string(urlEncodeMap[longUrl]);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return urlDecodeMap[stoi(shortUrl)];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));