#include <bits/stdc++.h>
using namespace std;
ifstream f("in2");
int n1,n2,v3[1<<10][1<<10][26],n;
vector < tuple <int, int, int> > v6,v7;
vector< pair <tuple<int,int,int> , tuple<int,int,int> > >v5[1<<10][1<<10][26];
char v1[26],v2[1<<10],s[1<<10],w[1<<10],v8[1<<10][26];
map <char,int> v4;
vector <char> G[1<<9][1<<9];

int main()
{
    f>>n1;
    for(int i=1;i<=n1;++i)
    {
        f>>v1[i];
        v4[v1[i]]=i;
    }
    f>>n2;
    for(int i=1;i<=n2;++i)
        f>>v2[i];
    for(int i=1;i<=n1;++i)
    {
        f>>w;
        cout<<w<<"\n";
        int lw=strlen(w);
        char x=w[0];
        for(int j=3;j<lw;j++)
        {
            char y=0,z=0;
            if(w[j+1]=='|'||w[j+1]==0)
            {
                y=w[j];
                G[y][z].push_back(v4[x]);
                j+=1;
            }
            else if(w[j+2]=='|'||w[j+2]==0)
            {
                y=w[j];
                z=w[j+1];
                G[y][z].push_back(v4[x]);
                j+=2;
            }
        }
    }
    f>>(s+1);
    n=strlen(s+1);
    for(int j=1;j<=n;++j)
        for(int k=0;k<(int)G[s[j]][0].size();++k)
        {
            v3[1][j][G[s[j]][0][k]]=1;
            v8[j][G[s[j]][0][k]]=s[j];
        }
//    for(int j=1;j<=n;++j)
//    {
//        for(int b=1;b<=n1;b++)
//            if(v3[1][j][b])
//            cout<<v1[b]<<" ";
//        cout<<"\n";
//    }
//    cout<<"\n";
    for(int i=2;i<=n;++i)
        for(int j=1;j<=n-i+1;++j)
            for(int k=1;k<=i-1;++k)
                for(int b=1;b<=n1;b++)
                    if(v3[k][j][b])
                        for(int c=1;c<=n1;c++)
                            if(v3[i-k][j+k][c])
                                {
                                    for(int a=0;a<(int)G[v1[b]][v1[c]].size();++a)
                                    {
                                        v3[i][j][G[v1[b]][v1[c]][a]]=1;
                                        v5[i][j][G[v1[b]][v1[c]][a]].push_back(make_pair(make_tuple(k,j,b), make_tuple(i-k,j+k,c)));
                                    }
                                }
//    for(int i=2;i<=n;i++)
//    {
//        for(int j=1;j<=n-i+1;j++)
//        {for(int k=1;k<=26;k++)
//            if(v3[i][j][k])
//            cout<<v1[k];
//            cout<<" ";
//        }
//        cout<<"\n";
//    }
    if(v3[n][1][1])
    {cout<<"DA\n";
    int h=1;
    tuple<int,int,int> x=make_tuple(n,1,1);
    v6.push_back(x);
    cout<<v1[1];
    do
    {
        v7.clear();
        h=0;
        for(int i=0;i<(int)v6.size();i++)
        {
            int a=get<0>(v6[i]);
            int b=get<1>(v6[i]);
            int c=get<2>(v6[i]);
            if(a==0)
                v7.push_back(v6[i]);
            else if(a==1)
                {v7.push_back(make_tuple(0,b,v8[b][c]));h=1;}
            else
            {
                h=1;
                v7.push_back(v5[a][b][c][0].first);
                v7.push_back(v5[a][b][c][0].second);
            }
        }
        v6=v7;
        if(h==1)
        {
            cout<<"=>";
            for(int i=0;i<(int)v7.size();i++)
            if(get<0>(v7[i]))
            cout<<v1[get<2>(v7[i])];
            else
                cout<<(char)get<2>(v7[i]);
        }
    }while(h);
    }
    else
        cout<<"NU";
}
