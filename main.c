#include <stdio.h>
#include "converter.h"

int main() {
    float fahrenheit = convert_to_fahrenheit();
    printf("Temperature in Fahrenheit: %.2f\n", fahrenheit);
    return 0;
}