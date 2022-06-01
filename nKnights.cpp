#include <iostream>
#include <string>
#include <vector>
#define N 3
using namespace std;
void printVectorMatrix(vector<vector<bool>> vec)
{
  for (int i = 0; i < vec.size(); i++)
  {
    for (int j = 0; j < vec[i].size(); j++){
      if(vec[i][j]==0){
          cout<<"X ";
      }
      else{  
          cout << "\x1B[34m" << "K " << "\x1B[0m";
      }
    }   
    cout << endl;
  }
}
bool isvalid(vector<vector<bool> > board, int r, int c)
{
  if(r>=0 && c>=0 && r<board.size() && c<board.size())
   return true;
  return false; 
}

bool isKnightSafe(vector<vector<bool>> board, int r, int c)
{
  if(isvalid(board,r-1,c-2)){
      if(board[r-1][c-2]==1)
       return 0;  
  }
  if(isvalid(board,r-1,c+2)){
      if(board[r-1][c+2]==1)
       return 0;  
  }if(isvalid(board,r-2,c+1)){
      if(board[r-2][c+1]==1)
       return 0;  
  }if(isvalid(board,r-2,c-1)){
      if(board[r-2][c-1]==1)
       return 0;  
  }
  return true;
}

void nKnight(vector<vector<bool>> board, int r, int c,int cnt)
{
  if (cnt==0)
  {
    printVectorMatrix(board);
    cout<<endl<<endl;
    return;
  }   

  if(r==board.size()-1 && c==board.size())
   return;

  if(c==board.size()) {
     nKnight(board,r+1,0,cnt);
     return;
  } 

  if (isKnightSafe(board, r, c))
   {
     board[r][c] = true;
     nKnight(board, r, c+1 ,cnt-1);
     //Bactracking
     board[r][c] = false;
   }

   nKnight(board,r,c+1,cnt);

}
int main()
{ 
  vector<bool> v(N,0);
  vector<vector<bool> > board(N,v);
  nKnight(board,0,0,5);
  return 0;
}