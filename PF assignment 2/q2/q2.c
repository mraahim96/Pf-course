//M.Raahim //24k-0543 //q2
#include <stdio.h>
#include <string.h>

void freq(const char *slogan)
{
    int frequency[256]={0};
    char order[100];
    int index=0;

    int length=strlen(slogan);
    
    for (int i=0; i <length; i++)
	{
        unsigned char ch=slogan[i];
        if (frequency[ch]==0)
		{
            order[index++]=ch;
        }
        frequency[ch]++;
    }

    printf("{");
    for (int i=0; i<index; i++)
	{
        printf("'%c': %d", order[i], frequency[(unsigned char)order[i]]);
        if (i<index-1)
		{
            printf(", ");
        }
    }
    printf("}\n");
}

int main()
{
    char slogans[100][100]; 
    int numslogans;
    printf("Enter the number of slogans: ");
    scanf("%d", &numslogans);
    getchar(); 
    for (int i=0; i<numslogans; i++)
	{
        printf("Enter slogan %d: ", i+1);
        fgets(slogans[i], 100, stdin);
        
        size_t len=strlen(slogans[i]);
        if (len>0 && slogans[i][len - 1]=='\n')
		{
            slogans[i][len-1]='\0';
        }
    }
    for (int i=0; i<numslogans; i++)
	{
        printf("For \"%s\": ", slogans[i]);
        freq(slogans[i]);
    }
    return 0;
}