#include<stdio.h>
#include<string.h>
int main() {
    char ip[100],page[100];
    int n,l,i,j,w,k,count=0,recentNo[100],hit=0,temp=1,min;
    printf("Enter the input string: ");
    scanf("%s",ip);
    l = strlen(ip);
    printf("Enter the number of pages: ");
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        page[i]=ip[i];
        recentNo[i] = -1;
        count++;
    }

    for(i=n;i<l;i++) {

        for(j=0;j<n;j++) {
            if(page[j] == ip[i]) {
                hit++;
                temp=0;
            }
        }

        if(temp == 1) {

            for(j=0;j<n;j++) {
                for(k=i-1;k>=0;k--) {
                    if(page[j]==ip[k]) {
                        recentNo[i] = k;
                        k=0;
                    }
                }
            }

            min = 0;
            for(j=0;j<n;j++) {
                if(recentNo[min]>recentNo[j])
                    min = j;
            }

            page[min] = ip[i];
            count++;

        }

        temp=1;
        for(j=0;j<n;j++) {
            recentNo[i] = -1;
        }
    }

    printf("The number of page faults are: %d\n",count);
    printf("The number of page hits are: %d\n",l - count);
}
