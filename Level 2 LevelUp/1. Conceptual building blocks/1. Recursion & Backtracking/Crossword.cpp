#include <vector>
#include<iostream>
#include <string>

using namespace std;



void print( vector<vector<char>> &puzzle)
{
    for(auto i=0; i<10; i++)
        for(auto j=0; j<10; j++)
            cout<<puzzle[i][j];    
}




bool canPlaceVertical(vector<vector<char>> &puzzle, string word, int r, int c)
{
	int i = 0 ;
	for(; i < word.length(); i++)
    {
		if(r + i >= puzzle.size())
			return false;

		if(puzzle[r + i][c] == '-' || puzzle[r + i][c] == word[i])
			continue;
		else
			return false;
	}
		
	if(r + i == puzzle.size() || puzzle[r + i][c] == '+')
		return true;
	else 
		return false;
}

bool canPlaceHorizontal(vector<vector<char>> &puzzle, string word, int r, int c)
{
	int i = 0 ;
	for(; i < word.length(); i++)
    {
		if(c + i >= puzzle.size())
			return false;

		if(puzzle[r][c+i] == '-' || puzzle[r][c + i] == word[i])
			continue;
		else
			return false;
	}
		
	if(c + i == puzzle.size() || puzzle[r][c + i] == '+')
		return true;
	else 
		return false;
}



void placeVertical(vector<vector<char>> &puzzle, string word, int r, int c,vector<bool> &visited)
{
	for(int i = 0 ; i < word.length(); i++)
    {
		if(puzzle[r + i][c] == '-')
			visited[i] = true;
			
		puzzle[r + i][c] = word[i];
	}
}

void placeHorizontal(vector<vector<char>> &puzzle, string word, int r, int c,vector<bool> &visited)
{
	for(int i = 0 ; i < word.length(); i++)
    {
		if(puzzle[r][c + i] == '-')
			visited[i] = true;
			
		puzzle[r][c + i] = word[i];
	}
}




void unplaceVertical(vector<vector<char>> &puzzle, string word, int r, int c,vector<bool> &visited)
{
	for(int i = 0 ; i < word.length(); i++)
		if(visited[i] == true)
			puzzle[r + i][c] = '-';	
}

void unplaceHorizontal(vector<vector<char>> &puzzle, string word, int r, int c,vector<bool> &visited)
{
	for(int i = 0 ; i < word.length(); i++)
		if(visited[i] == true)
			puzzle[r][c + i] = '-';	
}





void crossword(vector<vector<char>> &puzzle, vector<string> &words, int widx)
{
    if(widx == words.size())
    {
        print(puzzle);
        return;
    }

    //start from all possible positions
        for(auto i=0; i<10; i++)
            for(auto j=0; j<10; j++)
            {
                string word = words[widx];

                if(puzzle[i][j] == '_' || puzzle[i][j] == word[0])
                {
                    if(canPlaceVertical(puzzle,word,i,j) == true)
                    {
						vector<bool> visited(word.size()) ;
						placeVertical(puzzle,word,i,j,visited);
						crossword(puzzle,words,widx + 1);
						unplaceVertical(puzzle,word,i,j,visited);
					}

					if(canPlaceHorizontal(puzzle,word,i,j) == true)
                    {
						vector<bool> visited(word.size()) ;
						placeHorizontal(puzzle,word,i,j,visited);
						crossword(puzzle,words,widx + 1);
						unplaceHorizontal(puzzle,word,i,j,visited);
					}
                }
            }

}




int main()
{
    vector<vector<char>> puzzle(10, vector<char> (10));
    for(auto i=0; i<10; i++)
        for(auto j=0; j<10; j++)
            cin>>puzzle[i][j];

    int n;
    cin>> n;
    vector<string> words(n);
    for(auto i=0; i<n; i++)
        cin>>words[i];

    crossword(puzzle, words, 0);

    return 0;
}