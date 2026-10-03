class Solution {
public:
    string reorderSpaces(string text) {
        vector<string> words;
        int spaces = 0;
        string word = "";

        for (char c : text) {
            if (c == ' ') {
                spaces++;
                if (!word.empty()) {
                    words.push_back(word);
                    word = "";
                }
            } else {
                word += c;
            }
        }

        if (!word.empty()) {
            words.push_back(word);
        }

        int n = words.size();

        if (n == 1) {
            return words[0] + string(spaces, ' ');
        }

        int between = spaces / (n - 1);
        int extra = spaces % (n - 1);

        string result = "";

        for (int i = 0; i < n; i++) {
            result += words[i];

            if (i < n - 1) {
                result += string(between, ' ');
            }
        }

        result += string(extra, ' ');

        return result;
    }
};