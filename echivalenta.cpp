#include<bits/stdc++.h>
using namespace std;
ifstream f("test");
#define N 1500
#define p make_pair
map <pair <int,int>, int > viz;
struct dfa
{
    int n1,n2,n3,n4,v1[N],v3[N],q0;
    char v2[26];
    map< pair<int,char>, int> v4;
};
int cauta(dfa u, int x)
{
    for(int i=1;i<=u.n3;i++)
        if(x==u.v3[i])
        return 1;
    return 0;
}
int cauta1(dfa u, char x)
{
    for(int i=1;i<=u.n2;i++)
        if(u.v2[i]==x)
        return 1;
    return 0;
}
dfa citire()
{
    dfa u;
    int i,j,a,c;
    char b;
    f>>u.n1;
    for(i=1;i<=u.n1;i++)
        f>>u.v1[i];
    f>>u.n2;
    for(i=1;i<=u.n2;i++)
        f>>u.v2[i];
    for(j=0;j<26;j++)
    {
        b='a'+j;
        for(i=1;i<=u.n1;i++)
            u.v4[p(u.v1[i],b)]=-N;
        u.v4[p(-N,b)]=-N;
    }
    f>>u.q0;
    f>>u.n3;
    for(i=1;i<=u.n3;i++)
        f>>u.v3[i];
    f>>u.n4;
    for(i=1;i<=u.n4;i++)
    {
        f>>a>>b>>c;
        u.v4[p(a,b)]=c;
    }
    return u;
}
void afisare(dfa u)
{
    int i,j;
    cout<<u.n1<<"\n";
    for(i=1;i<=u.n1;i++)
        cout<<u.v1[i]<<" ";
    cout<<"\n";
    cout<<u.n2<<"\n";
    for(i=1;i<=u.n2;i++)
        cout<<u.v2[i]<<" ";
    cout<<"\n";
    cout<<u.q0<<"\n";
    cout<<u.n3<<"\n";
    for(i=1;i<=u.n3;i++)
        cout<<u.v3[i]<<" ";
        cout<<"\n";
    cout<<u.n4<<"\n";
    for(i=1;i<=u.n1;i++)
        for(j=1;j<=u.n2;j++)
        if(u.v4[p(u.v1[i],u.v2[j])])
           cout<<u.v1[i]<<" "<<u.v2[j]<<" "<<u.v4[p(u.v1[i],u.v2[j])]<<"\n";
}
dfa reuniune(dfa u1,dfa u2)
{
    dfa u;
    int k=1,m=0,l=0,i,j,a,b,w,q;
    char c;
    //map < pair< pair<int,int>, char >, pair<int,int> > D;
    map <pair <int,int>, int > R;
    queue < pair <int,int> > Q;
    for(i=1;i<=u1.n2;i++)
        u.v2[i]=u1.v2[i];
    m=u1.n2;
    for(i=1;i<=u2.n2;i++)
        if(!cauta1(u1,u2.v2[i]))
        u.v2[++m]=u2.v2[i];
    u.n2=m;
    R[p(u1.q0,u2.q0)]=1;
    u.q0=1;
    viz[p(u1.q0,u2.q0)]=1;
    Q.push(p(u1.q0,u2.q0));
    m=0;
    if(cauta(u1,u1.q0)||cauta(u2,u2.q0))
        u.v3[++l]=k;
    while(!Q.empty())
    {
        w=Q.front().first;
        q=Q.front().second;
        Q.pop();
        for(i=1;i<=u.n2;i++)
        {
            c=u.v2[i];
            a=u1.v4[p(w,c)];
            b=u2.v4[p(q,c)];
            //cout<<w<<" "<<q<<" "<<c<<" "<<a<<" "<<b<<"\n";
            if(a!=-N||b!=-N)
            {
                if(!viz[p(a,b)])
                {
                    viz[p(a,b)]=1;
                    Q.push(p(a,b));
                    R[p(a,b)]=++k;
                    if(cauta(u1,a)||cauta(u2,b))
                        u.v3[++l]=k;
                }
                m++;
                u.v4[p(R[p(w,q)],c)]=R[p(a,b)];
                //cout<<R[p(w,q)]<<c<<R[p(a,b)]<<"\n";
            }
        }
    }
    for(i=1;i<=k;i++)
        u.v1[i]=i;
    u.n1=k;
    u.n3=l;
    u.n4=m;
    return u;
}
dfa complement(dfa u1)
{
    dfa u=u1;
    int v[N],k=0;
    for(int i=1;i<=u.n1;i++)
        if(!cauta(u,u.v1[i]))
            v[++k]=u.v1[i];
    u.n3=k;
    for(int i=1;i<=k;i++)
        u.v3[i]=v[i];
    return u;
}
int viz1[N],h=1;
void dfs(dfa u,int a)
{
    viz1[a]=1;
    if(cauta(u,a))
        h=0;
    for(int i=1;i<=u.n2&&h;i++)
    {
        int b=u.v4[p(a,u.v2[i])];
        if(!viz1[b])
            dfs(u,b);
    }
}
int main()
{
    dfa u3,u4,u5,u6;
    u3=citire();
    u4=citire();
    u5=complement(reuniune(complement(u3),u4));
    viz.clear();
    //cout<<"\n";
    u6=complement(reuniune(complement(u4),u3));
    //u6=reuniune(u4,u3);
    //afisare(u5);
    //cout<<"\n";
    //afisare(u6);
    dfs(u5,u5.q0);
    if(h==1)
    {
        memset(viz1,0,sizeof(viz1));
        dfs(u6,u6.q0);
        if(h==1)
            cout<<"DA";
        else
            cout<<"NU";
    }
    else
        cout<<"NU";
}
