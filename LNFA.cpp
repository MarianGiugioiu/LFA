#include<fstream>
using namespace std;
ifstream f("test2");
ofstream g("raspuns2");
int n1,n2,n3,n4,n5,v1[150],v3[150],v4[15000][26][26],q0,a,c,h,k,e;
char v2[26],v5[150],b;
void solve(int q, char *s)
{
    int i;
    if(*s==0)
    {
        for(i=1;i<=n3;i++)
            if(q==v3[i])
            h=1;
    }
    if(h!=1&&((k==0)||(k==1&&e!=q)))
    {

        if(v4[q][0][0]||v4[q][*s-'a'+1][0])
        {
            for(i=1;i<=v4[q][*s-'a'+1][0];i++)
            {
                k=0;e=0;
                solve(v4[q][*s-'a'+1][i],s+1);
            }
            for(i=1;i<=v4[q][0][0];i++)
            {
                if(k==0)
                    e=q;
                k=1;
                solve(v4[q][0][i],s);
            }
        }
        else
            h=2;
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
    f>>n3;
    for(i=1;i<=n3;i++)
        f>>v3[i];
    f>>n4;
    for(i=1;i<=n4;i++)
    {
        f>>a>>b>>c;
        if(b=='.')
        {
            v4[a][0][0]++;
            v4[a][0][v4[a][0][0]]=c;
        }
        else
        {
            v4[a][b-'a'+1][0]++;
            v4[a][b-'a'+1][v4[a][b-'a'+1][0]]=c;
        }
    }
    f>>n5;
    for(i=1;i<=n5;i++)
    {
        f>>v5;
        h=0;k=0;e=0;
        solve(q0,v5);
        if(h==1)
           g<<"DA"<<"\n";
        else
           g<<"NU"<<"\n";
    }
}
