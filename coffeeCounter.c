#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int coffeeCount; 
int waterCount; 
int oatmealCount; 
int walkCount; 
int pushUpCount; 
int stretchCount; 

bool updateFlag;
bool done;

void DoNewLine()
{
    printf("\n");
}

void RevisedPrintCounts(int amount, char *name, char *incrementChar)
{
    printf("I've had %d %s today! (%s to increment)\n", amount, name, incrementChar);
}

void PrintCounts()
{
    RevisedPrintCounts(coffeeCount, "coffees", "c");
    RevisedPrintCounts(waterCount, "servings of water", "h");
    RevisedPrintCounts(oatmealCount, "bowls of oatmeal", "o"); 
    RevisedPrintCounts(walkCount, "walks", "w");
    RevisedPrintCounts(pushUpCount, "pushups", "p");
    RevisedPrintCounts(stretchCount, "stretches", "s");
}

void PrintOptions()
{
    printf("c to increment coffee\n");
    printf("s to increment stretches\n");
    printf("o to increment oatmeal\n");
    printf("h to increment water (h20)\n");
    printf("w to increment walks\n");
    printf("p to increment pushups\n");
}

bool ApplyCount(char charVal)
{
    bool result = true;
    switch (charVal) 
    {
        case 'c':  // coffee 
            coffeeCount++;
            break; 
        case 'h': // water
            waterCount++; 
            break;
        case 'w':
            walkCount++; // walks
            break; 
        case 's': // stretch
            stretchCount++;
            break;
        case 'p': // pushup
            pushUpCount++; 
            break; 
        case 'o': // oatmeal
            oatmealCount++;
            break;
        default:
            result = false;
            break;
    }
    return result; 
}

int main() {

    coffeeCount = 0; 
    done = false; 

    char *line = NULL;
    size_t len = 0;

    do 
    {
        PrintCounts();
        getline(&line, &len, stdin);

        if (strlen(line) > 0)
        {
            char c = line[0];

            if (!ApplyCount(c))
            {
                done = true;
            }
        }
        printf("\e[1;1H\e[2J");
    } while (!done);

    return 0;
}
