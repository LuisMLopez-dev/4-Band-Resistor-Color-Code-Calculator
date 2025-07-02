//Header Files
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef ENGINEERING_NOTATION_H
#define ENGINEERING_NOTATION_H

void engineeringNotationConverter(double resistorValue, double toleranceValue);
char prefixSymbol(int exponentCount);

#endif // ENGINEERING_NOTATION_H

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
        case 24:
            prefixChar = 'Y'; //Yotta
            break;
        case 21:
            prefixChar = 'Z'; //Zetta
            break;
        case 18:
            prefixChar = 'E'; //Exa
            break;
        case 15:
            prefixChar = 'P'; //Peta
            break;
        case 12:
            prefixChar = 'T'; //Tera
            break;
        case 9:
            prefixChar = 'G'; //Giga
            break;
        case 6:
            prefixChar ='M'; //Mega
            break;
        case 3:
            prefixChar = 'k'; //Kilo
            break;
        case -3:
            prefixChar = 'm'; //Milli
            break;
        case -6:
            prefixChar = 'u'; //Micro (µ)
            break;
        case -9:
            prefixChar = 'n'; //Nano
            break;
        case -12:
            prefixChar = 'p'; //Pico
            break;
        case -15:
            prefixChar = 'f'; //Femto
            break;
        case -18:
            prefixChar = 'a'; //Atto
            break;
        case -21:
            prefixChar = 'z'; //Zepto
            break;
        case -24:
            prefixChar = 'y'; //Yocto
            break;
        default:
            prefixChar = ' ';
    }
    return prefixChar;
}
