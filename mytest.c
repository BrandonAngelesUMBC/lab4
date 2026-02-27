#include <stdio.h>
#include <string.h>
#include <stdbool.h>

extern int sum_ints(int *arr, int size);                       // Assembly function with two parameters and int return type
int main()
{
    FILE *dataFile;
    bool validFile = false;
    char fileName[100];                                // Initialize fileName 

    while(!validFile){
        printf("Enter file name: ");                   // Prompt for user input
        fgets(fileName, sizeof(fileName), stdin);
        fileName[strcspn(fileName, "\n")] = '\0';      // Remove "\n" from the string to prevent extra bits

        dataFile = fopen(fileName, "r");

        if(dataFile == NULL){
            printf("Error opening file\n");
        }else{
            printf("Reading data from file..\n");
            validFile = true;
        }
    }

    int totalNums = 0;
    int counter = 0;
    int currNum = 0;
    
    if(fscanf(dataFile, "%d", &currNum) == 1){
        totalNums = currNum;
    }

    int nums[totalNums];

    while(fscanf(dataFile, "%d", &currNum) == 1){
        nums[counter] = currNum;
        counter++;
    }

    // Close the file
    fclose(dataFile);

    int sum = sum_ints(nums, totalNums);

    printf("Total sum: %d\n", sum);

    return 0;
}