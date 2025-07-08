//Header Files
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void engineeringNotationConverter(double resistorValue, double toleranceValue);
char prefixSymbol(int exponentCount);

void engineeringNotationConverter(double resistorValue, double toleranceValue){
    double engNotationNumber = resistorValue; //Will hold the value of the converted number,
    int exponentCount = 0; //Will hold the value of the exponent of the converted number
    bool inUpperOutsideRange = false; //True represents that engNotationNumber is above 999, False represents it is between 0 and 1

    if (engNotationNumber == 0){ 
        printf("The value of your resistor is 0 ohms\n"); 
        return;
    }

    if((engNotationNumber >= 1 && engNotationNumber < 1000)){ //If the user's number is already in engineering notation, then exit the function
        printf("The value of your resistor is %.2lf ohms Tolerance = +/- %.2lf%%\n", engNotationNumber, toleranceValue); //Prints the number in Engineering Notation in the format of a number with the corresponding prefix
        return; //Empty return to exit this function
    }

    if(engNotationNumber > 999){
        inUpperOutsideRange = true; //In the upper outside range, which starts at 1000, otherwise it is in the lower outside range, which is in between 0 and 1
    }

    if(inUpperOutsideRange){
        while(engNotationNumber > 999){ //Above the upper limit of 999
            engNotationNumber /= 10; //Divides it to bring it in the range of 1 - 999
            exponentCount++; //Increase exponent count
        }

        while(exponentCount % 3 != 0 ){ //While the exponent is not a multiple of 3
            engNotationNumber /= 10; //Continue to divide
            exponentCount++; //Increase exponent count
        }
    }
    else{
        while(engNotationNumber < 1){ //In the lower outside range
            engNotationNumber *= 10; //Multiplies it to bring it in the range of 1 - 999
            exponentCount--; //Decrease exponent count
        }
    
        while(exponentCount % 3 != 0 ){ //While the exponent is not a multiple of 3
            engNotationNumber *= 10; //Continue to multiply
            exponentCount--; //Decrease exponent count
        }
    }
    printf("The value of your resistor is %.2lf %c ohms Tolerance = +/- %.2lf%%\n", engNotationNumber, prefixSymbol(exponentCount), toleranceValue); //Prints the number in Engineering Notation in the format of a number with the corresponding prefix
}

char prefixSymbol(int exponentCount){
    char prefixChar;
    switch(exponentCount){
        case 9:
            prefixChar = 'G'; //Giga
            break;
        case 6:
            prefixChar ='M'; //Mega
            break;
        case 3:
            prefixChar = 'k'; //Kilo
            break;
        default:
            prefixChar = ' ';
    }
    return prefixChar;
}
