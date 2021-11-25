#include <bits/stdc++.h>
using namespace std;
ifstream f("in");
int N,M,P,S;
char Let[1<<10],F[1<<10],w[1<<10],C[1][1<<10];
vector <char> G[1<<9][1<<9];
pair <int,int> dp[30][30][1<<9];
struct tp
{
    int a;
    int b;
    int c;
};
tp U[2][30][30][1<<9];
int main()
{
    f>>n1;
    int prima=1<<10,ultima=0;
    for(int i=1;i<=n1;++i)
    {
        f>>v1[i];
        if(prima>Let[i])
            prima=Let[i];
        if(ultima<Let[i])
            ultima=Let[i];
    }
    f>>n2;
    for(int i=1;i<=n2;++i)
        f>>v2[i];
    for(int i=1;i<=n1;++i)
    {
        f>>w;
        int lw=strlen(w);
        char x=w[0];
        for(int j=2;j<lw;)
        {
            char y=0,z=0;
            if(w[j+1]=='|')
            {
                y=w[j];
                G[y][z].push_back(x);
                j+=2;
            }
            else if(w[j+2]=='|')
            {
                y=w[j];
                z=w[j+1];
                G[y][z].push_back(x);
                j+=3;
            }
        }
    }
    f>>S;
    f>>(C[0]+1);
    ///dp i j litera
    int l=strlen(C[0]+1);
    for(int j=1;j<=l;++j)
        for(int k=0;k<(int)G[C[0][j]][0].size();++k)
        {
            dp[1][j][G[C[0][j]][0][k]]=make_pair(C[0][j],0);
          U[0][1][j][G[C[0][j]][0][k]]={0,0,C[0][j]};
        }
    /// incep la pozitia j si folosesc i litere
    pair <char,char> NULE = make_pair(0,0);
    for(int i=2;i<=litere;++i)
        for(int j=1;j<=litere-i+1;++j)
            for(int k=j;k<=j+i-1;++k)
                for(int a=prima;a<=ultima;++a)
                    if(dp[k-j+1][j][a]!=NULE)
                        for(int b=prima;b<=ultima;++b)
                            if(dp[i-(k-j+1)][k+1][b]!=NULE)
                                for(int c=0;c<(int)G[a][b].size();++c)
                                {
                                    dp[i][j][G[a][b][c]]=make_pair(a,b);
                                  U[0][i][j][G[a][b][c]]={k-j+1,j,a};
                                  U[1][i][j][G[a][b][c]]={i-(k-j+1),k+1,b};
                                }
    if(dp[litere][1][S]!=NULE)
    {
        queue <pt> Q[2];
        pt NULEE={0,0,0};
        Q[0].push({litere,1,S});
        bool modify=1;
        for(int i=0;modify;++i)
        {
            modify=0;
            while(!Q[i&1].empty())
            {
                pt nod=Q[i&1].front();
                Q[i&1].pop();
                cout<<nod.c;
                bool ok=0;
                if(U[0][nod.a][nod.b][nod.c]!=NULEE)
                {
                    Q[(i+1)&1].push(U[0][nod.a][nod.b][nod.c]);
                    ok=1;
                }
                if(U[1][nod.a][nod.b][nod.c]!=NULEE)
                {
                    Q[(i+1)&1].push(U[1][nod.a][nod.b][nod.c]);
                    ok=1;
                }
                if(ok) modify=1;
                if(!ok)
                    Q[(i+1)&1].push(nod);
            }
            cout<<'\n';
        }
    }
    else cout<<"This can't be possible!\n";
    return 0;
}
