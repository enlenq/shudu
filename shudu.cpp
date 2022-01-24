#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool jc(int h,int l,int a[9][9]){
    int ii=0;
    for(int i=0;i<=8;i++){
        if(a[h][l]==a[h][i])
            ii+=1;
    }
    for(int i=0;i<=8;i++){
        if(a[h][l]==a[i][l])
            ii+=1;
    }
    int hh=h/3;
    int ll=l/3;
    for(int i=hh*3;i<hh*3+3;i++){
        for(int j=ll*3;j<ll*3+3;j++){
            if(a[h][l]==a[i][j])
                ii+=1;
        }
    }            
    if(ii>3)
        return false;
    else
        return true;
}

void shuchu(int a[9][9]){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

void shuchu(int a[9]){
    for(int j=0;j<9;j++){
            cout<<a[j]<<" ";
    }
    cout<<endl;
}

bool jc2(int i,int j){
    if(i==0&&(j==0||j==2||j==6||j==8))return false;
    if(i==1&&(j==4))return false;
    if(i==2&&(j==0||j==5||j==6||j==8))return false;
    if(i==3&&(j==3||j==5))return false;
    if(i==4&&(j==1||j==7))return false;
    if(i==5&&(j==3||j==5))return false;
    if(i==6&&(j==0||j==2||j==6||j==8))return false;
    if(i==7&&(j==4))return false;
    if(i==8&&(j==0||j==2||j==6||j==8))return false;
    return true;
}

vector<vector<int>> jc2(int a[9][9]){//找出数列里给出的位置
    vector<vector<int>>b;
    int ii=0;
    for(int i=0;i<=8;i++){
        for(int j=0;j<=8;j++){
            if(a[i][j]!=0){
                int c[2]={i,j};
                vector<int>bb(c,c+2);
                b.push_back(bb);
            }
        }
    }
    return b;
}

bool panduan(vector<vector<int>> vec,int i,int j){//i,j为已给数字时返回false,为空时返回true
    int x=0;
    int shu;
    for(int ii=0;ii<=vec.size()-1;ii++){
        for(int jj=0;jj<=vec[0].size()-1;jj++){
            shu=vec[ii][jj];
            //cout<<shu;
            if(shu==i && x==0){
                x++;
                continue;
            }
            
            if(shu==j && x==1){
                return false;
            }
            else{x=0;break;}
            
            x=0;
            break;
            

        }
    }
    return true;
}



int main()
{
    /*int a[9][9]={
  {0,0,0,0,0,0,0,1,2},
  {0,0,0,0,0,0,3,4,5},
  {0,0,0,0,0,3,6,7,0},
  {0,0,0,0,8,7,9,0,0},
  {0,0,0,5,3,9,0,0,0},
  {0,0,5,4,2,0,0,0,0},
  {0,8,1,2,0,0,0,0,0},
  {7,6,3,0,0,0,0,0,0},
  {4,9,0,0,0,0,0,0,0}
  };*/
    /*int a[9][9]={
  {7,0,5,0,0,0,9,0,3},
  {0,0,0,0,6,0,0,0,0},
  {4,0,9,0,0,0,8,0,6},
  {0,0,0,6,0,2,0,0,0},
  {0,5,0,0,0,0,0,3,0},
  {0,0,0,4,0,8,0,0,0},
  {2,0,6,0,0,0,5,0,7},
  {0,0,0,0,9,0,0,0,0},
  {9,0,8,0,0,0,2,0,4}
  };*/
    int a[9][9]={
  {7,0,0,0,0,0,0,2,0},
  {0,0,0,0,0,5,0,4,0},
  {0,0,0,9,4,0,1,0,8},
  {0,0,0,1,9,0,0,0,2},
  {0,8,0,0,0,0,0,7,0},
  {5,0,0,0,2,3,0,0,0},
  {8,0,2,0,3,4,0,0,0},
  {0,6,0,5,0,0,0,0,0},
  {0,9,0,0,0,0,0,0,3}
  }; 
    int i=0,j=0;
    vector<vector<int>> b=jc2(a);
    while(i<9){
        j=0;
        while(j<9){
            if(panduan(b,i,j)){
                a[i][j]+=1;
                while(jc(i,j,a)==false)
                a[i][j]+=1;
                
                if(a[i][j]==10){
                    a[i][j]=0;
                    j-=1;

                    while(panduan(b,i,j)==false){
                        //if(panduan(b,i,j))cout<<"true";else cout<<"false";
                        j-=1;
                    }

                    if(j<0){
                        j=8;
                        i-=1;
                        while(panduan(b,i,j)==false){
                            j-=1;
                        }
                        continue;
                    }
                    continue;
                }
            }
            j+=1;
        }
        i+=1;
    }
    
    shuchu(a);
    return 0;
}