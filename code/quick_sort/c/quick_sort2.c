#include "stdio.h"
#include "stdlib.h"

void quick_sort(int s[],int l,int r)
{
    if(l < r)
    {
        int i=l,j=r,x=s[l];
        while(i<j)
        {
            while(i<j && s[j]>=x)//从右到左找到第一个小于x的数
                j--;
            if(i<j)
                s[i++]=s[j];

            while(i<j && s[i]<=x)//从左往右找到第一个大于x的数
                i++;
            if(i<j)
                s[j--]=s[i];

        }

        s[i]=x;//i = j的时候，将x填入中间位置
        quick_sort(s,l,i-1);//递归调用
        quick_sort(s,i+1,r);
    }
}

int main()
{
    int a[] = {1,8,44,77,35,65,78,12,25,455,20,15,45};
    int length = sizeof(a)/sizeof(int);//求数组的长度

    printf("原序列为： ");
    for(int i=0;i<length;i++)
    {
        printf("%3d ",a[i]);
    }

    quick_sort(a,0,length);

    printf("\n排序后的序列为：");
    for(int i=0;i<length;i++)
    {
        printf("%3d ",a[i]);
    }
    printf("\n");
}
