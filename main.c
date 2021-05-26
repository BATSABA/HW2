#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"hf.h"

int darr[1000000];
int qarr[100000];
int array[1000000];


struct treenode *root;

int main(int argc, char **argv)
{
    int i = 1;
    int insertNum, searchNum;
    int bst = 0;
    int bs = 0;
    int arr = 0;
    int ll = 0;
    int j, k;
    unsigned long diff;
    struct timeval tv_start, tv_end;
    while(i < argc)
    {
        if(strcmp(argv[i], "-d") == 0)
        {
            i ++;
            if(strcmp(argv[i], "1e4") == 0)
            {
                insertNum = 10000;
            }
            if(strcmp(argv[i], "1e5") == 0)
            {
                insertNum = 100000;
            }
            if(strcmp(argv[i], "1e6") == 0)
            {
                insertNum = 1000000;
            }
        }
        else if(strcmp(argv[i], "-q") == 0)
        {
            i ++;
            if(strcmp(argv[i], "1e3") == 0)
            {
                searchNum = 1000;
            }
            if(strcmp(argv[i], "1e4") == 0)
            {
                searchNum = 10000;
            }
            if(strcmp(argv[i], "1e5") == 0)
            {
                searchNum = 100000;
            }
        }
        else if(strcmp(argv[i], "-bst") == 0)
        {
            bst = 1;
        }
        else if(strcmp(argv[i], "-bs") == 0)
        {
            bs = 1;
        }
        else if(strcmp(argv[i], "-arr") == 0)
        {
            arr = 1;
        }
        else if(strcmp(argv[i], "-ll") == 0)
        {
            ll = 1;
        }
        i ++;
    }
    srand(time(NULL));
    for(j = 0;j < insertNum;j ++)
    {
        k = rand();
        darr[j] = k;
    }
    for(j = 0;j < searchNum;j ++)
    {
        k = rand();
        qarr[j] = k;
    }
    if(arr == 1)
    {
        gettimeofday(&tv_start, NULL);
        for(i = 0;i < insertNum;i ++)
        {
            array[i] = darr[i];
        }
        gettimeofday(&tv_end, NULL);
        diff = 1000000 * (tv_end.tv_sec - tv_start.tv_sec) + tv_end.tv_usec - tv_start.tv_usec;
        printf("arr:\nbuilding time: %f sec\n", diff / 1000000.0);
        gettimeofday(&tv_start, NULL);
        for(i = 0;i < searchNum;i ++)
        {
            arrsearch(qarr[i], array, insertNum);
        }
        gettimeofday(&tv_end, NULL);
        diff = 1000000 * (tv_end.tv_sec - tv_start.tv_sec) + tv_end.tv_usec - tv_start.tv_usec;
        printf("search time: %f sec\n\n", diff / 1000000.0);
    }
    if(bs == 1)
    {
        gettimeofday(&tv_start, NULL);
        for(i = 0;i < insertNum;i ++)
        {
            array[i] = darr[i];
        }
        qsort(array, insertNum, sizeof(int), cmp);
        gettimeofday(&tv_end, NULL);
        diff = 1000000 * (tv_end.tv_sec - tv_start.tv_sec) + tv_end.tv_usec - tv_start.tv_usec;
        printf("bs:\nbuilding time: %f sec\n", diff / 1000000.0);
        gettimeofday(&tv_start, NULL);
        for(i = 0;i < searchNum;i ++)
        {
            binarysearch(qarr[i], array, insertNum);
        }
        gettimeofday(&tv_end, NULL);
        diff = 1000000 * (tv_end.tv_sec - tv_start.tv_sec) + tv_end.tv_usec - tv_start.tv_usec;
        printf("search time: %f sec\n\n", diff / 1000000.0);
    }
    if(bst == 1)
    {
        gettimeofday(&tv_start, NULL);
        root = bstcreate(darr[0]);
        for(i = 1;i < insertNum;i ++)
        {
            bstinsert(darr[i], root);
        }
        gettimeofday(&tv_end, NULL);
        diff = 1000000 * (tv_end.tv_sec - tv_start.tv_sec) + tv_end.tv_usec - tv_start.tv_usec;
        printf("bst:\nbuilding time: %f sec\n", diff / 1000000.0);
        gettimeofday(&tv_start, NULL);
        for(i = 0;i < searchNum;i ++)
        {
            bstsearch(qarr[i], root);
        }
        gettimeofday(&tv_end, NULL);
        diff = 1000000 * (tv_end.tv_sec - tv_start.tv_sec) + tv_end.tv_usec - tv_start.tv_usec;
        printf("search time: %f sec\n\n", diff / 1000000.0);
    }
    if(ll == 1)
    {
        gettimeofday(&tv_start, NULL);
        for(i = 0;i < insertNum;i ++)
        {
            llinsert(darr[i]);
        }
        gettimeofday(&tv_end, NULL);
        diff = 1000000 * (tv_end.tv_sec - tv_start.tv_sec) + tv_end.tv_usec - tv_start.tv_usec;
        printf("ll:\nbuilding time: %f sec\n", diff / 1000000.0);
        gettimeofday(&tv_start, NULL);
        for(i = 0;i < searchNum;i ++)
        {
            llsearch(qarr[i]);
        }
        gettimeofday(&tv_end, NULL);
        diff = 1000000 * (tv_end.tv_sec - tv_start.tv_sec) + tv_end.tv_usec - tv_start.tv_usec;
        printf("search time: %f sec\n\n", diff / 1000000.0);
    }
}
