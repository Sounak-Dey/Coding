#include<iostream>
#include<vector>

using namespace std;

void print(vector<vector<char>> &ans)
{
    for(auto i=0; i<ans.size(); i++)
    {
        for(auto j=0; j<ans[0].size(); j++)
            cout<<ans[i][j]<<" ";

        cout<<endl;
    }      
}

int countInRow(vector<vector<char>> &ans, vector<int> &rowCount, char sign, int r) // can be optimised
{
    int counter = 0;
    for(auto j=0; j<ans[0].size(); j++)
    {
        if(ans[r][j] == sign)
            counter++;
    }
    return counter;
}

int countInCol(vector<vector<char>> &ans, vector<int> &colCount, char sign, int c) //can be optimised
{

    int counter = 0;
    for(auto i=0; i<ans.size(); i++)
    {
        if(ans[i][c] == sign)
            counter++;
    }
    return counter;
}


bool isItSafe(vector<vector<char>> &ans, vector<int> &top, vector<int> &left, vector<int> &right, vector<int> &bottom, int r, int c, char sign)
{
    //checking if same sign is present at left, top or right cells
    if((c-1>=0 && ans[r][c-1] == sign) || (r-1>=0 && ans[r-1][c] == sign) || (c+1 < ans[0].size() && ans[r][c+1] == sign))
        return false;
    
    // checking for row and column counts of sign
    if(sign == '+')
    {
        int rowCount = countInRow(ans, left, sign, r);
        int colCount = countInCol(ans, top, sign, c);

        if(left[r] != -1 && rowCount >= left[r])
            return false;
        if(top[c] != -1 && colCount >= top[c])
            return false;
    }
    else
    {

        int rowCount = countInRow(ans, right, sign, r);
        int colCount = countInCol(ans, bottom, sign, c);

        if(right[r] != -1 && rowCount >= right[r])
            return false;
        if(bottom[c] != -1 && colCount >= bottom[c])
            return false;
    }

    return true;

}

bool isAnsValid(vector<vector<char>> &ans, vector<int> &top, vector<int> &left, vector<int> &right, vector<int> &bottom)
{
    for(int i=0; i<top.size(); i++)
    {
        int colCount = countInCol(ans, top, '+', i);
        if(top[i] != -1 && top[i] !=colCount)
            return false;
    }

    for(int i=0; i<left.size(); i++)
    {
        int rowCount = countInCol(ans, left, '+', i);
        if(left[i] != -1 && left[i] !=rowCount)
            return false;
    }

    for(int i=0; i<bottom.size(); i++)
    {
        int colCount = countInCol(ans, bottom, '-', i);
        if(bottom[i] != -1 && bottom[i] !=colCount)
            return false;
    }

    for(int i=0; i<right.size(); i++)
    {
        int rowCount = countInCol(ans, right, '-', i);
        if(right[i] != -1 && right[i] !=rowCount)
            return false;
    }

    return true;
}

bool solution(vector<vector<char>> &arr, vector<int> &top, vector<int> &left, vector<int> &right, vector<int> &bottom, vector<vector<char>> &ans, int r, int c)
{
    if(c == arr[0].size())
    {
        c = 0;
        r++;
    }

    if(r == arr.size())
    {
        if(isAnsValid(ans, top, left, right, bottom))
            return true;

        return false;
    }

    //checking if the magnet needs to placed in horizontal allignment i.e arr[r][c] and arr[r][c+1] contains L R respectively
    if(arr[r][c] == 'L')
    {
        //checking if we can place '+ -'
        if(isItSafe(ans, top, left, right, bottom, r, c, '+') && isItSafe(ans, top, left, right, bottom, r, c+1, '-'))
        {
            //placing '+ -'
            ans[r][c] = '+';
            ans[r][c+1] = '-';

            if(solution(arr, top, left, right, bottom, ans, r, c+2))  // checking if we got a solution following this path
                return true;
                                                   
            ans[r][c] = 'X';        //clearing while backtracking
            ans[r][c+1] = 'X';
        }

        //checking if we can place '- +'
        if(isItSafe(ans, top, left, right, bottom, r, c, '-') && isItSafe(ans, top, left, right, bottom, r, c+1, '+'))
        {
            ans[r][c] = '-';
            ans[r][c+1] = '+';

            if(solution(arr, top, left, right, bottom, ans, r, c+2))
                return true;
                                                   
            ans[r][c] = 'X';     
            ans[r][c+1] = 'X';
        }
    }

    //vertical allignment
    else if(arr[r][c] == 'T')
    {
        if(isItSafe(ans, top, left, right, bottom, r, c, '+') && isItSafe(ans, top, left, right, bottom, r+1, c, '-'))
        {
            ans[r][c] = '+';
            ans[r][c+1] = '-';

            if(solution(arr, top, left, right, bottom, ans, r, c+1))  
                return true;
                                                   
            ans[r][c] = 'X';        
            ans[r][c+1] = 'X';
        }

        if(isItSafe(ans, top, left, right, bottom, r, c, '-') && isItSafe(ans, top, left, right, bottom, r+1, c, '+'))
        {
            ans[r][c] = '-';
            ans[r][c+1] = '+';

            if(solution(arr, top, left, right, bottom, ans, r, c+1))  
                return true;
                                                   
            ans[r][c] = 'X';        
            ans[r][c+1] = 'X';
        }

    }

    //no
    if(solution(arr, top, left, right, bottom, ans, r, c+1));
        return true;

    return false;
}

int main()
{
    int m, n;
    cin>>m>>n;

    vector<vector<char>> arr(m, vector<char> (n));
    for(auto i=0; i<m; i++)
        for(auto j=0; j<n; j++)
            cin>>arr[i][j];

    vector<int> top(n);
    for(auto i=0; i<n; i++)
        cin>>top[i];

    vector<int> left(m);
    for(auto i=0; i<m; i++)
        cin>>top[i];

    vector<int> bottom(n);
    for(auto i=0; i<n; i++)
        cin>>top[i];

    vector<int> right(m);
    for(auto i=0; i<m; i++)
        cin>>top[i];

    vector<vector<char>> ans(m, vector<char> (n,'X'));
    
    

    if(solution(arr, top, left, right, bottom, ans, 0, 0) == false)
    {
        cout<<"No Solution";
        return 0;
    }

    print(ans);

    return 0;
    
}