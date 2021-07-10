#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>


using namespace std;

int main()
{
	int n, m;
	cin>>n;
	
	vector<string> inp(n);

	for(auto &x: inp)
		cin>>x;
	
	cin>>m;
	vector<string> inp2(m);
	
	for(auto &x: inp2)
		cin>>x;
	

	// bureau data conversion
	vector<vector<string>> bdata(n, vector<string> (8));
	for(int i=0; i<n; i++)
	{
		int k=0, j=0;
		while( k < inp[i].length() )
		{
			if(inp[i][k] == ',')
				j++;
			else if(isalpha(inp[i][k])  ||  isdigit(inp[i][k]))
			{
				bdata[i][j].push_back(inp[i][k]);
			}

			k++;
		}
	}	

	//application data conv
	vector<vector<string>> adata(n, vector<string> (4));
	for(int i=0; i<m; i++)
	{
		int k=0, j=0;
		while( k < inp2[i].length() )
		{
			if(inp2[i][k] == ',')
				j++;
			else if(isalpha(inp2[i][k])  ||  isdigit(inp2[i][k]))
			{
				adata[i][j].push_back(inp2[i][k]);
			}

			k++;
		}
	}

	long long avg = 0;
	for(int i=0; i<n; i++)
	{
		if(bdata[i][2].length()>0)
			avg += stoll(bdata[i][2]);
	}
	avg = avg / n;

	
	for(int i=0; i<m; i++)
	{
		string fname = adata[i][0];
		string lname = adata[i][1];

		for(int j=0; j<n; j++)
		{
			if(bdata[j][0] == fname  && bdata[j][1] == lname)
			{
				if(stoll(bdata[j][3])>stoll(bdata[j][4]) && stoi(bdata[j][6])>50  &&  stof(bdata[j][2])/stof(adata[i][3]) >0.1  &&  stoll(bdata[j][2])>avg)
				{
					cout<<adata[i][0]<<","<<"Yes"<<endl;
					continue;
				}
				if(stoll(bdata[j][3])>stoll(bdata[j][4])  &&  bdata[j][5]=="1"  &&  stoi(bdata[j][6])>30 && stof(bdata[j][2])/stof(adata[i][3]) >0.1  &&  stoll(bdata[j][2])>avg)
				{
					cout<<adata[i][0]<<","<<"Yes"<<endl;
					continue;
				}
				else
					cout<<adata[i][0]<<","<<"No"<<endl;
			}
			else if(bdata[j][0] == fname  || bdata[j][1] == lname)
			{
				if(stoll(bdata[j][3])>stoll(bdata[j][4]) && stoi(bdata[j][6])>50  &&  stof(bdata[j][2])/stof(adata[i][3]) >0.1  &&  stoll(bdata[j][2])>avg)
				{
					cout<<adata[i][0]<<","<<"Yes"<<endl;
					continue;
				}
				if(stoll(bdata[j][3])>stoll(bdata[j][4])  &&  bdata[j][5]=="1"  &&  stoi(bdata[j][6])>30 && stof(bdata[j][2])/stof(adata[i][3]) >0.1  &&  stoll(bdata[j][2])>avg)
				{
					cout<<adata[i][0]<<","<<"Yes"<<endl;
					continue;
				}
				else
					cout<<adata[i][0]<<","<<"No"<<endl;
			}
				
		}

	}

	return 0;
}