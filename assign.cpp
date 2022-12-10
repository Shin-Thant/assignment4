#include <stdio.h>
#include <stdlib.h>


void findWords(char findMe[50]);
bool isWordsMatched(char current[50], char findMe[50]);

int main() {
    char word[50] = "winhtut";
    findWords(word);
    
    return 0;
}

void findWords(char findMe[50]) {
    FILE *fp = fopen("./text.txt", "r");

    int firstCount = 0;
    char first[50] = "winhtut";

    int secondCount = 0;
    char second[50] = "NationalCyberCity";

    if(fp == NULL) {
        printf("File Not Found!\n");

        return;
    } else {
        

        char currentWord[50];

        while (fscanf(fp, "%s", currentWord) != EOF) {
            bool isFirstMatched = isWordsMatched(currentWord, first);
            bool isSecondMatched = isWordsMatched(currentWord, second);

            if(isFirstMatched) {
                printf("%s\n", currentWord);
                firstCount++;
            }

            if(isSecondMatched) {
                printf("%s\n", currentWord);
                secondCount++;
            }
        }
        
    }

    fclose(fp);

    printf("==============\n");
    printf("%s: %d\n", first, firstCount);
    printf("%s: %d\n", second, secondCount);
}

bool isWordsMatched(char current[50], char findMe[50]) {
    int ind = 0;

    while (findMe[ind] != NULL) {
        if(current[ind] != findMe[ind]) {
            return false;
        }

        ind++;
    }
    

    return true;
}


// char first[50] = "hello";
        // char second[50] = "hello";

        // int boo = "hello" == "ello";

        // printf("%d\n", first == second);
        // printf("%d\n", first[0] != NULL);
        // printf("%c, %c\n", first[0], second[30]);

        // bool isMatched = isWordsMatched(first, second);
        // printf("bool: %d\n", isMatched);