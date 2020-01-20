#include <stdio.h>
#define MaxSize 20
typedef int KeyType;    //����ؼ�������
typedef char InfoType[10];
typedef struct          //��¼����
{
    KeyType key;        //�ؼ�����
    InfoType data;      //����������,����ΪInfoType
} RecType;              //����ļ�¼���Ͷ���

void ShellSort(RecType R[],int n)   //ϣ�������㷨
{
    int i,j,gap;
    RecType tmp;
    gap=n/2;                //�����ó�ֵ
    while (gap>0)
    {
        for (i=gap; i<n; i++) //���������gapλ�õ�����Ԫ�����������
        {
            tmp=R[i];
            j=i-gap;
            while (j>=0 && tmp.key<R[j].key)//�����gapλ�õ�Ԫ�����������
            {
                R[j+gap]=R[j];
                j=j-gap;
            }
            R[j+gap]=tmp;
            j=j-gap;
        }
        gap=gap/2;  //��С����
    }
}

int main()
{
    int i,n=11;
    RecType R[MaxSize];
    KeyType a[]= {16,25,12,30,47,11,23,36,9,18,31};
    for (i=0; i<n; i++)
        R[i].key=a[i];
    printf("����ǰ:");
    for (i=0; i<n; i++)
        printf("%d ",R[i].key);
    printf("\n");
    ShellSort(R,n);
    printf("�����:");
    for (i=0; i<n; i++)
        printf("%d ",R[i].key);
    printf("\n");
    return 0;
}