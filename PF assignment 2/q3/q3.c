//M.Raahim //24k-0543 //q3
#include <stdio.h>
#include <string.h>
int compress_word(char word[], char compressed_word[], int *removed_count)
{
    int length=strlen(word);
    int j=0;
    *removed_count=0;
    for (int i=0; i<length; i++)
	{
        if (i==0 || word[i]!=word[i-1])
		{
            compressed_word[j++] = word[i];
        }
		else
		{
            (*removed_count)++;
        }
    }
    compressed_word[j]='\0';
}
int compress_multiple_words(char words[100][100], int num_words, char compressed_words[100][100], int removed_counts[])
{
    for (int i=0; i<num_words; i++)
	{
        compress_word(words[i], compressed_words[i], &removed_counts[i]);
    }
}
int main()
{
    char words[100][100];
    char compressed_words[100][100];
    int removed_counts[100];
    int num_words;
    printf("Enter the number of words you want to compress: ");
    scanf("%d", &num_words);
    for (int i=0; i<num_words; i++)
	{
        printf("Enter word %d: ", i+1);
        scanf("%s", words[i]);
    }
    compress_multiple_words(words, num_words, compressed_words, removed_counts);

    printf("\nCompressed Words:\n");
    for (int i=0; i<num_words; i++) {
        printf("Compressed: \"%s\" (Removed: %d characters)\n", compressed_words[i], removed_counts[i]);
    }
}