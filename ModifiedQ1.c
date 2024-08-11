#include <stdio.h>
#include <string.h>

// function to split string and return the no of substrings
int split_string(char *str, int N, char substring[][N + 1])
{
    int len = strlen(str); // Get the length of the string
    int count = 0;         // Initialize a counter which gives length of current subString
    int row = 0;           // to count number of subString
    for (int i = 0; i < len; i++)
    {
        substring[row][count] = str[i];
        count++;

        // Check conditions to split the string
        if (str[i] == '1')
        {
            if ((i + 1 < len && str[i] != str[i + 1]) || count == N || str[i - 1] != str[i])
            {
                substring[row][count] = '\0';
                count = 0;
                row++;
            }
        }
        else
        {
            if (count == N)
            {
                substring[row][count] = '\0';
                count = 0;
                row++;
            }
        }
        // for the last substring
        if (i == len - 1)
        {
            substring[row][count] = '\0';
            row++;
        }
    }
    return row;
}
int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    if (n < 2 || n > 4)
    {
        printf("Invalid Input! n should be between 2, 3 and 4.\n");
        return 1;
    }

    FILE *file = fopen("bin.txt", "r");
    if (file == NULL)
    {
        printf("Can not open the file.\n");
        return 1;
    }

    char str[100];
    if (fgets(str, sizeof(str), file) == NULL)
    {
        printf("Failed to read from file.\n");
        fclose(file);
        return 1;
    }
    fclose(file);
    // strcspn(str, "\n") return the index where \n present
    //  Replace newline character if present in the string with \0
    str[strcspn(str, "\n")] = '\0';

    int lengthOfstr=strlen(str);
    printf("Length of original string:%d",lengthOfstr);

    // n+1 because of extra '\0'
    char substring[100][n + 1];
    int num_substring = split_string(str, n, substring);

    printf("a. Substrings:\n");
    for (int i = 0; i < num_substring; i++)
    {
        printf("%s\n", substring[i]);
    }

    printf("b. Count the frequency of each substring.\n");

    int freq[num_substring];

    for (int i = 0; i < num_substring; i++)
    {
        freq[i] = 0;
    }
    for (int i = 0; i < num_substring; i++)
    {

        if (freq[i] != 0)
        {
            continue;
        }

        for (int j = 0; j < num_substring; j++)
        {
            if (strcmp(substring[i], substring[j]) == 0)
            {
                freq[i]++;
                if (i != j)
                {
                    freq[j] = -1;
                }
            }
        }
    }
    
    for (int i = 0; i < num_substring; i++)
    {
        if (freq[i] > 0)
        {
            printf("%s occurs %d time \n", substring[i], freq[i]);
        }
    }

    printf("c. Replace the substring with character A for length 1, B for length 2, C for length 3, D for length 4.\n");

    FILE* outputfile=fopen("output.txt","w");

    if(file==NULL){
        printf("File does not exist.");
        return 1;
    }
    for(int i=0;i<num_substring;i++){
        if(strlen(substring[i])==1 ){
            fprintf(file,"%s","A");
        }
        else if(strlen(substring[i])==2){
             fprintf(file,"%s","B");
        }
        else if(strlen(substring[i])==3){
            fprintf(file,"%s","C");
            
        }
        else{
           
                if(strcmp(substring[i],"0000")==0){
                    fprintf(file,"%s","E");
                }
                else{
                    fprintf(file,"%s","F");
                }
            }

    }

    
    fclose(outputfile);
    printf("\n");
    
    FILE* outputFile=fopen("output.txt","r");
    printf("d.\n");
    char newStr[100];
    char ch;
    int i=0;
    while((ch=fgetc(outputFile))!=EOF){
        newStr[i]=ch;
        i++;
    }
    fclose(outputFile);
    str[strcspn(newStr, "\n")] = '\0';
    int lenOfnewstr=strlen(newStr);
    printf("Length of old string : %d\n", lengthOfstr);
    printf("Length of new sting : %d\n",lenOfnewstr);
    int cal=((lengthOfstr-lenOfnewstr)*100)/lengthOfstr;
    printf("Reduction in length : %d%\n",cal);
return 0;
}
