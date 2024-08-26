#include <iostream>
using namespace std;
// 原题链接:https://www.lanqiao.cn/problems/3984/learning/?page=1&first_category_id=1&tags=%E4%BA%8C%E7%BB%B4%E5%89%8D%E7%BC%80%E5%92%8C
const int N=2010;
char a[N][N];
long long preR[N][N]={0};
long long preG[N][N]={0};
int main()
{
  // 请在此输入您的代码
  int m,n;
  cin>>n>>m;

  for(int i=1;i<=n;++i){
    for(int j=1;j<=m;++j){
      cin>>a[i][j];
      if(a[i][j]=='R'){
        preR[i][j]=preR[i-1][j]+preR[i][j-1]-preR[i-1][j-1]+1;
      }else{
        preR[i][j]=preR[i-1][j]+preR[i][j-1]-preR[i-1][j-1];
      }
      if(a[i][j]=='G'){
        preG[i][j]=preG[i-1][j]+preG[i][j-1]-preG[i-1][j-1]+1;
      }else{
        preG[i][j]=preG[i-1][j]+preG[i][j-1]-preG[i-1][j-1];
      }
    }
  }
  
  long long cnt=0;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;++j){
      if(a[i][j]=='O'){
        cnt+=preR[i][j]*(preG[n][m]-preG[i-1][m]-preG[n][j-1]+preG[i-1][j-1]);
        cnt%=998244353;
      }
    }
  }
  cout<<cnt;

  return 0;
}