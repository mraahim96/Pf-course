//M.Raahim //24k-0543 //q4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sortString(char str[])
{
    int n=strlen(str);
    for (int i=0; i<n-1; i++)
	{
        for (int j=i+1; j<n; j++)
		{
            if (str[i]>str[j])
			{
                char temp=str[i];
                str[i]=str[j];
                str[j]=temp;
            }
        }
    }
}
int groupAnagrams(char transactions[100][100], int size)
{
    char sortedTransactions[100][100];
    int grouped[100]={0};
    for (int i=0; i<size; i++)
    {
        if (!grouped[i])
		{
            strcpy(sortedTransactions[i], transactions[i]);
            sortString(sortedTransactions[i]);
            printf("\n");
            printf("\"%s\"", transactions[i]);
            for (int j=i+1; j<size; j++)
			{
                if (!grouped[j])
				{
                    char temp[100];
                    strcpy(temp, transactions[j]);
                    sortString(temp);
                    if (strcmp(sortedTransactions[i], temp)==0)
					{
                        printf(", \"%s\"", transactions[j]);
                        grouped[j] = 1;
                    }
                }
            }
        }
    }
}
int main()
{
    char transactions[100][100]={"eat", "tea", "tan", "ate", "nat", "bat"};
    int size=6;
    printf("Grouped Transactions:\n");
    groupAnagrams(transactions, size);
    return 0;
}
