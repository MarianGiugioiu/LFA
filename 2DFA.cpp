#include<fstream>
#include<string.h>
using namespace std;
ifstream f("test1");
ofstream g("raspuns1");
int n1,n2,n4,n5,v1[150],v4[15000][26][26],s,a,e,t,r,v3[15000][150],i,c,k;
char v2[26],v5[150],b,d,st,dr;
int solve(int poz,int l,int q,char *s)
{
    //g<<poz<<" "<<q<<"\n";
    if(poz==l&&q==t)
        return 1;
    if(poz==l&&q==r)
        return 0;
    if(v3[q][poz])
        return 0;
    v3[q][poz]=1;
    if(poz==l)
    {
        if(v4[q][31][0])
            return solve(poz-1,l,v4[q][31][0],s);
        return 0;
    }
    if(poz==0&&v4[q][*(s+1)-'a'][1]==-1)
    {
        if(v4[q][30][0])
            return solve(poz+1,l,v4[q][30][0],s);
        return 0;
    }
    if(v4[q][*(s+poz+1)-'a'][0])
        return solve(poz+v4[q][*(s+poz+1)-'a'][1],l,v4[q][*(s+poz+1)-'a'][0],s);
    else
        return 0;
}
int main()
{
    f>>n1;
    for(i=1;i<=n1;i++)
        f>>v1[i];
    f>>n2;
    for(i=1;i<=n2;i++)
        f>>v2[i];
    f>>st>>dr;
    f>>n4;
    for(i=1;i<=n4;i++)
    {
        f>>a>>b>>c>>d;
        if(b==st)
            v4[a][30][0]=c;
        else if(b==dr)
            v4[a][31][0]=c;
        else
        {
            v4[a][b-'a'][0]=c;
            if(d=='r')
                v4[a][b-'a'][1]=1;
            else
                v4[a][b-'a'][1]=-1;
        }

    }
    f>>s>>t>>r;
    f>>n5;
    //g<<v4[2][31][0];
    for(k=1;k<=n5;k++)
    {
        f>>(v5+1);
        v5[0]=st;
        v5[strlen(v5)+1]=dr;
        e=solve(0,strlen(v5)-1,s,v5);
        for(i=1;i<=3;i++)
        {
            for(int j=1;j<strlen(v5);j++)
            v3[i][j]=0;
        }
        if(e)
            g<<"DA\n";
        else
            g<<"NU\n";

    }
}
