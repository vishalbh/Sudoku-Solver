#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

#define F(i,n) for(int i=0;i<n;i++)
#define FR(i,n) for(int i=n-1;i>=0;i--)
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define pll pair<lli,lli>
#define vpii vector<pii>
#define vpll vector<pll>
#define vi vector<int>
#define pb push_back
#define all(c) c.begin(),c.end()
#define FL(i,a,b,p) for(int i=a;i<=b;i+=p)
#define FastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

bool unassignedPos(vector<vector<char>>A,int &row,int &column){
    for(row=0;row<9;row++){
        for(column=0;column<9;column++){
            if(A[row][column]=='.')return true;
        }
    }
    return false;
}
bool isRow(vector<vector<char>>A,int col,char num){
    for(int i=0;i<9;i++){
        if(A[i][col]==num)return true;
    }
    return false;
}
bool isCol(vector<vector<char>>A,int row,char num){
    for(int i=0;i<9;i++){
        if(A[row][i]==num)return true;
    }
    return false;
}
bool isBox(vector<vector<char>>A,int sR,int sC,char num){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(A[sR+i][sC+j]==num)return true;
        }
    }
    return false;
}
bool isSafe(vector<vector<char>>A,int row, int col,char num){
    return !(isCol(A,row,num)||isRow(A,col,num)||isBox(A,row-row%3,col-col%3,num));
}
bool solveIt(vector<vector<char>>&A){
    int row,column;
    if(!unassignedPos(A,row,column))return true;
    for(char num='1';num<='9';num++){
        if(isSafe(A,row,column,num)){
            A[row][column]=num;
            if(solveIt(A))return true;
            A[row][column]='.';
        }
    }
    return false;
}
void solveSudoku(vector<vector<char> > &A) {
    solveIt(A);
    return;
}
void solve()
{
	// freopen("inp.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	vector<vector<char>>A(9,vector<char>(9));
	for(int i=0;i<9;i++){
		cout<<"Enter values in "<<(i+1)<<"th row. Every number should be separated by space. For blank position enter *."<<endl;
		for(int j=0;j<9;j++){
			char x;
			cin>>x;
			if((x>'9' or x<'0') and x!='*'){
				cout<<"Invalid Input!!! Retry."<<endl;
				return ;
			}
			A[i][j]=(x=='*')?'.':x;
		}
	}
	cout<<"given Sudoku is: "<<endl;
	for(int i=0;i<22;i++)cout<<"-";
	cout<<endl;
	for(int i=0;i<9;i++){
		cout<<"|";
		for(int j=0;j<9;j++){
			cout<<A[i][j]<<' ';
			if(j==2 or j==5 or j==8)cout<<"|";
		}
		cout<<endl;
		if(i==2 or i==5 or i==8){
			for(int i=0;i<22;i++)cout<<"-";
			cout<<endl;
		}	
	}
	solveSudoku(A);
	cout<<"Solved sudoku is: "<<endl;
	for(int i=0;i<22;i++)cout<<"-";
	cout<<endl;
	for(int i=0;i<9;i++){
		cout<<"|";
		for(int j=0;j<9;j++){
			cout<<A[i][j]<<' ';
			if(j==2 or j==5 or j==8)cout<<"|";
		}
		cout<<endl;
		if(i==2 or i==5 or i==8){
			for(int i=0;i<22;i++)cout<<"-";
			cout<<endl;
		}	
	}
}
int main(){
	FastIO;
	int x;
	while(1){
		cout<<"Enter 1 if you want to challenge me to solve Sudoku.\n";
		cout<<"Enter 2 if you accept defeat."<<endl;
		cin>>x;
		if(x==1)solve();
		else break;
	}
	return 0;
}