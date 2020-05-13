#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

int sort_by_area(triangle *tr,int n)
{
    float  s[100],p[100];
    float  t[100];
    int i,j;
    triangle temp[100];
    for(i=0;i<n;i++)
    {
        s[i]=(tr[i].a+tr[i].b+tr[i].c)/2.0;
    }
    for(i=0;i<n;i++)
    {
        p[i]=sqrt(s[i]*(s[i]-tr[i].a)*(s[i]-tr[i].b)*(s[i]-tr[i].c));
    }
    for(j=1;j<n;j++)
    {
        for(i=0;i<n-j;i++)
        {
            if(p[i]>p[i+1])
            {
                t[i]=p[i];
                p[i]=p[i+1];
                p[i+1]=t[i];
                temp[i]=tr[i];
                tr[i]=tr[i+1];
                tr[i+1]=temp[i];
            }
        }
    }
    return 0;
}




int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
