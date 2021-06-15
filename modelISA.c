#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#define TEMP_TROPOPAUSE -56

/**
 * This method is a linear equation (temp = temp0 + (deltaT / deltaH) (height - height0))
 * @param height0 - initial height of the layer
 * @param height - the input height
 * @param temp0 -  the initial temperature in the layer
 * @param lapseRate
 * @return calculation of linear equation
 */
int getTemperature(double height0, double height, double temp0, double lapseRate){
    return round(temp0 + lapseRate * (height - height0));
}

int calculateTemperature(int height){
    if (height < 0 || height > 25000){
        return INT_MAX;
    }
    double heightKm = (double) height / 1000;
    if (heightKm >= 0 && heightKm <= 11){
        return getTemperature(0, heightKm, 15, -6.5);
    }
    if (heightKm >= 11 && heightKm <= 20){
        return TEMP_TROPOPAUSE;
    }
    else{
        return getTemperature(20, heightKm, -56, 1);
    }
}

int main() {
   FILE *fptr;
    fptr = fopen("C:\\Users\\Tamar.LAPTOP-55EK84EJ\\Desktop\\test\\program.txt","w");

    if(fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }

    int i = 0;
    while (i < 20000) {
        fprintf(fptr, "%d", calculateTemperature(i));
        fprintf(fptr, "%c", ',');
        fprintf(fptr, "%d\n", i);

        i += 10;
    }
    fclose(fptr);
  return 0;
}