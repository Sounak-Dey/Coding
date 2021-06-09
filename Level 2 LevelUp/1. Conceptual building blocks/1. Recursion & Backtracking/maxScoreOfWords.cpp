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
    bool include = false;
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
        freq[word[i] - 'a']--;        


    return max(sumNo, sumYes);
}

int main()
{
    int noofWords;
    cin>>noofWords;

    vector<string> words(noofWords);
    for(auto i=0; i<words.size(); i++)
        cin>>words[i];

    int noofLetters;
    cin>>noofLetters;

    vector<char> letters(noofLetters);
    for(auto i=0; i<letters.size(); i++)
        cin>>letters[i];

    vector<int> score(26);
    for(auto i=0; i<score.size(); i++)
        cin>>score[i];

    // if (words == nullptr || words.size() == 0 || letters == null || letters.size() == 0 || score == null || score.size() == 0)
    // {
	// 	cout<<(0)<<endl;
	// 	return;
    // }
    if (words.size() == 0 || letters.size() == 0 || score.size() == 0)
    {
		cout<<(0);
		return 0;
    }

    vector<int> freq(26);
    for(auto l: letters)
        freq[l - 'a']++;

    cout<<msof(words, freq, score, 0);

    return 0;

}