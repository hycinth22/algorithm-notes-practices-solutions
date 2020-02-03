#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int n;
void run()
{
        int i,j,a[111],s,l,t=0;
        double x[111],y[111],m=0;
        for(i=1;i<=n;i++)
                scanf("%lf%lf",&x[i],&y[i]);
        for(i=1;i<=n;i++)
                a[i]=0;
        a[1]=1;
        while(t<n)
        {
                s=0;
                l=0;
                for(i=1;i<=n;i++)
                        if(a[i]==1)
                                for(j=1;j<=n;j++)
                                        if(a[j]==0)
                                                if((s==0)||((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])<(x[s]-x[l])*(x[s]-x[l])+(y[s]-y[l])*(y[s]-y[l])))
                                                {
                                                        s=i;
                                                        l=j;
                                                }
                a[l]=1;
                t++;
                m+=sqrt((x[s]-x[l])*(x[s]-x[l])+(y[s]-y[l])*(y[s]-y[l]));
        }
        printf("%.2f\n",m);
}
int main()
{
        scanf("%d",&n);
        while(n!=0)
        {
                run();
                n=0;
                scanf("%d",&n);
        }
        return 0;
}
