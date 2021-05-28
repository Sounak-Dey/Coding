#include <iostream>
#include <map>

using namespace std;


int main()
{
    map<string, int> m;
    int q, type, y;
    string x;

    cin>>q;

    while(q--)
    {
        cin>>type>>x;

        switch(type)
        {
            case 1:
                cin>>y;
                m[x] += y;
                break;
            case 2:
                m.erase(x);
                break;
            case 3:
                cout<<m[x]<<endl;
        }
    }

    return 0;
}





















// int main() {

// 	int q, type;
//     map<string,int> clas; 
//     string name;


//     cin >> q; 

// 	for (int i(0), mark; i<q; ++i)
// 	{
// 		cin >> type >> name;

// 		if (type == 1)
//         {
// 			cin >> mark;
// 			clas[name] += mark;
// 		}
// 		else if (type == 2)
// 			clas.erase(name);
// 		else
// 			cout << clas[name] << "\n";
// 	}
// 	return 0;
// }