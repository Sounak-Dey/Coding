#include<iostream>
#include<vector>

using namespace std;

void solution(int i, int n, vector<bool> &used, string asf, int &counter)
{
    if(i>n)
    {
        cout << counter++ <<"."<<asf<<endl;
        return;
    }

    if(used[i] == false)
    {
        used[i] = true;
        // looping through j's, with whom i will pair
        for(int j=i; j<=n; j++)     
        {
            if(j==i)        // i goes alone
            {
                solution(i+1, n, used, asf + "("+to_string(i)+") ", counter );
            }
            else        // i pairs with some other number j
            {
                if(used[j] == false)
                {
                    used[j] = true;
                    solution(i+1, n, used, asf + "("+to_string(i)+","+to_string(j)+") ", counter);
                    used[j] = false;
                }
            }
        }

        used[i] = false;
    }
    else        // if i has been already used
        solution(i+1, n, used, asf, counter);
        
    return ;
}


int main()
{
    int n, counter=1;
    cin>>n;

    vector<bool> used(n+1);

    solution(1, n, used, "", counter);

    return 0;
}