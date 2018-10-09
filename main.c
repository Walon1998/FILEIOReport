#include <stdio.h>
#include <string.h>

int main() {


    FILE *input;
    FILE *output;
    output = fopen("report.txt", "w+");
    input = fopen("stateoutflow0708.txt", "r");

    int charsize = 100;
    int arguments = 9;
    int total = 0;
    char line[charsize * arguments];

    char State_Code_Origin[charsize];
    char County_Code_Origin[charsize];
    char State_Code_Dest[charsize];
    char County_Code_Dest[charsize];
    char State_Abbrv[charsize];
    char State_Name[charsize];
    int Return_Num;
    int Exmpt_Num;
    int Aggr_AGI;


//Firstline
    fgets(line, charsize * arguments, input);
//    printf(line);
    char out[] = ("STATESTOTAL");
    fputs(out, output);
    printf("%-30s %6s\n", "STATE", "TOTAL");

    while (fgets(line, charsize * arguments, input)) {
     sscanf(line, "%s %s %s %s %s %s %d %d %d", State_Code_Origin, County_Code_Origin, State_Code_Dest,
               County_Code_Dest, State_Abbrv, State_Name, &Return_Num, &Exmpt_Num, &Aggr_AGI);

        if (strcmp(State_Code_Origin, "\"25\"") == 0) {
            printf("%-30s %6d\n", State_Name, Aggr_AGI);
            total += Aggr_AGI;
        }
    }
    printf("%-30s %6d\n", "Total", total);

    fclose(input);
    fclose(output);
    return 0;
}