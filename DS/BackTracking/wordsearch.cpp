#include <bits/stdc++.h>
#include<vector>
using namespace std;
bool chk;
void recur(vector<vector<char> >& board, string &word, int i, int j, int k)
{
    if(k == word.size())
    {
        chk = true;
        return;
    }
    if((i < 0) || (j < 0 )|| (i == board.size() )||( j == board[0].size() )|| (board[i][j] == '0'))
        return;
    
    if(board[i][j] == word[k])
    {
        char c = board[i][j];
        board[i][j] = '0';
        recur(board, word, i, j+1, k+1);
        recur(board, word, i+1, j, k+1);
        recur(board, word, i, j-1, k+1);
        recur(board, word, i-1, j, k+1);
        board[i][j] = c;
    }
    return;
}
bool wordSearch(vector<vector<char> > &board, string word)
{
    chk  = false;
    for(int i=0; i<board.size(); i++)
    {
        for(int j=0; j<board[0].size(); j++)
        {
            if(board[i][j]==word[0])
                recur(board, word, i, j, 0);
        }
    }
    
    return chk;
}

int main(){
	vector<vector<char> > board;
	int n,m;
	char a;
	char word[10];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		vector<char> row;
		for(int j=0;j<m;j++){
			cin>>a;
			row.push_back(a);	
		}
		board.push_back(row);
	}
	cin>>word;
	if(wordSearch(board,word)){
		cout<<"True";
	}
	else{
		cout<<"False";
	}
	return 0;
}
