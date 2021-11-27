#include<fstream>
#include<string.h>
using namespace std;
ifstream f("test");
ofstream g("raspuns");
int n1,n2,n4,n5,v1[150],q0,a,c,l,k,n3,nr1,n8,v8[150];
char v2[31],v5[150],b,d,v6[150],v3[31];
struct muchie{
    int nr,o[31];
    char s[31];
}v4[15000][31];
int gasit(int q)
{
    for(int w=1;w<=n8;w++)
        if(v8[w]==q)
        return 1;
    return 0;
}
void solve(int k, int q,int u)
{
    if(k==l&&gasit(q))
    {
        v6[u]=0;
        g<<v6<<"\n";
        nr1++;
    }
    else
    {
        for(int i=1;i<=v4[q][30].nr;i++)
        {
            if(v4[q][30].s[i]=='.')
            {
                solve(k,v4[q][30].o[i],u);
            }
            else
            {
                v6[u]=v4[q][30].s[i];
                solve(k,v4[q][v5[k]-'a'].o[i],u+1);
            }
        }
        for(int i=1;i<=v4[q][v5[k]-'a'].nr;i++)
        {
            if(v4[q][v5[k]-'a'].s[i]=='.')
            {
                solve(k+1,v4[q][v5[k]-'a'].o[i],u);
            }
            else
            {
                v6[u]=v4[q][v5[k]-'a'].s[i];
                solve(k+1,v4[q][v5[k]-'a'].o[i],u+1);
            }
        }
    }
}
int main()
{
    int i;
    f>>n1;
    for(i=1;i<=n1;i++)
        f>>v1[i];
    f>>n2;
    for(i=1;i<=n2;i++)
        f>>v2[i];
    f>>q0;
    f>>n8;
    for(i=1;i<=n8;i++)
        f>>v8[i];
    f>>n3;
    for(i=1;i<=n3;i++)
        f>>v3[i];
    f>>n4;
    for(i=1;i<=n4;i++)
    {
        f>>a>>b>>c>>d;
        if(b=='.')
        {
            v4[a][30].nr++;
            v4[a][30].o[v4[a][30].nr]=c;
            v4[a][30].o[v4[a][30].nr]=d;
        }
        v4[a][b-'a'].nr++;
        v4[a][b-'a'].o[v4[a][b-'a'].nr]=c;
        v4[a][b-'a'].s[v4[a][b-'a'].nr]=d;
    }
    f>>n5;
    for(i=1;i<=n5;i++)
    {
        f>>v5;
        nr1=0;
        l=strlen(v5);
        solve(0,q0,0);
        if(nr1==0)
            g<<"Imposibil\n";
        g<<"\n";
    }
}
