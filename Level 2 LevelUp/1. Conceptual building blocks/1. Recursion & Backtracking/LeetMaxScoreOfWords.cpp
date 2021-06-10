#include<bits/stdc++.h>
using namespace std;

int msof(vector<string> &words, vector<int> &freq, vector<int> &score, int idx)
{   
    if(idx == words.size())
        return 0;


    // not include the word at current index
    int sumNo = msof(words, freq, score, idx+1);


    //trying to include the word at current index
    int wordVal = 0;
    bool include = true;
    string word = words[idx];

    for(auto i=0; i<word.length(); i++)     //getting letters of the word and calculating
    {
        if(freq[word[i] - 'a'] == 0)        //checking if the letter is still available
            include = false;

        
        freq[word[i] - 'a']--;              //reducing frequency of the letter left
        wordVal += score[word[i] - 'a'];    //adding score of the letter to the wordValue
    }

    int sumYes = 0;
    if(include == true)
        sumYes = wordVal + msof(words, freq, score, idx+1);

    for(auto i=0; i<word.length(); i++)     //backtracking 
        freq[word[i] - 'a']++;        


    return max(sumNo, sumYes);
}



class Solution 
{
    public:
        int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) 
        {
            
            if (words.size() == 0 || letters.size() == 0 || score.size() == 0)
            {
                cout<<(0);
                return 0;
            }
            
            vector<int> freq(26);
            for(auto l: letters)
                freq[l - 'a']++;
            
            return msof(words, freq, score, 0);
            
        }
};