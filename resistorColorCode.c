//Header Files
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "engineeringNotation.h"

//Function Prototypes
void printBandInformation(void);
bool isValidBandValue(int bandValue);
void resistorColorCodeCalculator(void);
double toleranceBandValue(int fourthBandValue);

int main(void){
    int userContinueStatus; //1 to continue, 0 to end the program
    bool continueStatus = true;
    
    printf("Enter the value corresponding to each band when prompted to\n");

    while(continueStatus){ //Runs until the user wants to stop
        resistorColorCodeCalculator(); //Calls the function that calculates the resistor's value using the color code
        puts("");    

        do{
            printf("Do you want to enter the band colors for another resistor?\nEnter 1 to continue, or enter 0 to end the program: ");
            scanf("%d", &userContinueStatus); //Determines if the user wants to contine or end the program
        }while(userContinueStatus != 0 && userContinueStatus != 1); //While the user has not entered a correct number, it will keep requesting a proper input

        if(userContinueStatus == 0){
            continueStatus = false; //Ends the program
            puts("");
        }
        else{
            continueStatus = true; //Continues the program
            puts("");
        }
    }
    printf("The program has ended\n");
    return 0;
}

//Prints band inforamtion for the first three bands and the fourth band
void printBandInformation(void){
    const char *bandColors[] = {
        "0 --> Black", 
        "1 --> Brown", 
        "2 --> Red", 
        "3 --> Orange", 
        "4 --> Yellow", 
        "5 --> Green", 
        "6 --> Blue", 
        "7 --> Violet",
        "8 --> Grey",
        "9 --> White",
        "FOURTH BAND ONLY:",
        "2 --> Red (Tolerance = +/- 1%)",
        "3 --> Orange (Tolerance = +/- 2%)",
        "5 --> Green (Tolerance = +/- 0.5%)", 
        "6 --> Blue (Tolerance = +/- 0.25%)", 
        "7 --> Violet (Tolerance = +/- 0.1%)",
        "8 --> Grey (Tolerance = +/- 0.05%)",
        "10 --> Golden (Tolerance = +/- 5%)",
        "11 --> Silver (Tolerance = +/- 10%)"
    };

    int numBandColors = sizeof(bandColors) / sizeof(bandColors[0]);
    for(int i = 0; i < numBandColors; i++){
        printf("%s\n", bandColors[i]);
    }
}

//Checks each band, up to the 3rd one, to see if it is a valid value
bool isValidBandValue(int bandValue){
    return bandValue > -1 && bandValue < 10;
}

void resistorColorCodeCalculator(void){ //This resistor color code calculator is for 4-band resistors
    int firstBandValue, secondBandValue, thirdBandValue, fourthBandValue = 0;
    double preEngNotationResistorValue, toleranceValue = 0.00;

    printBandInformation(); //Calls the function that prints the information about the band colors
    do{ //Enter the values of the four bands
        printf("Enter the value of the first band: ");
        scanf("%d", &firstBandValue);
        printf("Enter the value of the second band: ");
        scanf("%d", &secondBandValue);
        printf("Enter the value of the third band: ");
        scanf("%d", &thirdBandValue);
        printf("Enter the value of the fourth band: ");
        scanf("%d", &fourthBandValue);
    }while(!isValidBandValue(firstBandValue) || !isValidBandValue(secondBandValue) || !isValidBandValue(thirdBandValue) || 
           !((fourthBandValue == 2 || fourthBandValue == 3) || 
             (fourthBandValue > 4 && fourthBandValue < 9) || 
             (fourthBandValue == 10 || fourthBandValue == 11))); //While any of the entered values are incorrect, repeat asking the user for their input

    //Concantenates the first band value and second band value to represent a two digit number, and multiplies it with 10 raised to the power of the third band value
    preEngNotationResistorValue = ((firstBandValue * 10) + secondBandValue) * pow(10, thirdBandValue);
    
    //Prints the value of the resistor in engineering notation with the proper prefix and symbol, and the tolerance value 
    engineeringNotationConverter(preEngNotationResistorValue, toleranceBandValue(fourthBandValue)); 
}

//Determins the tolerance percentage based on the fourth band value
double toleranceBandValue(int fourthBandValue){
    double toleranceValue = 0.00;
    switch(fourthBandValue){
        case 2:
            toleranceValue = 1;
            break;
        case 3:
            toleranceValue = 2;
            break;
        case 5:
            toleranceValue = 0.5; 
            break;
        case 6:
            toleranceValue = 0.25;
            break;
        case 7:
            toleranceValue = 0.1;
            break;
        case 8:
            toleranceValue = 0.05;
            break;
        case 10:
            toleranceValue = 5;
            break;
        case 11:
            toleranceValue = 10;
            break;
        default:
            toleranceValue = 0;
            break;
    }
    return toleranceValue;
}