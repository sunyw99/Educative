using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class WordConcatenation {
   public:
    static vector<int> findWordConcatenation(const string& str, const vector<string>& words) {
        vector<int> resultIndices;
        // TODO: Write your code here
        int wordsCount = words.size();
        int wordLength = words[0].length();
        unordered_map<string, int> wordFreq;
        for (auto word : words) {
            wordFreq[word]++;
        }
        for (int i = 0; i <= int(str.length()) - wordsCount * wordLength; i++) {
            unordered_map<string, int> wordsSeen;
            for (int j = 0; j < wordsCount; j++) {
                int nextWordIndex = i + j * wordLength;
                // get the next word from the string
                string word = str.substr(nextWordIndex, wordLength);
                if (wordFreq.find(word) == wordFreq.end()) {  // break if we don't need this word
                    break;
                }

                wordsSeen[word]++;  // add the word to the 'wordsSeen' map

                // no need to process further if the word has higher frequency than required
                if (wordsSeen[word] > wordFreq[word]) {
                    break;
                }

                if (j + 1 == wordsCount) {  // store index if we have found all the words
                    resultIndices.push_back(i);
                }
            }
        }
        return resultIndices;
    }
};
