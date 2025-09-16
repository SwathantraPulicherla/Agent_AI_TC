#ifndef CONVERTER_H
#define CONVERTER_H

typedef int (*sensor_func_t)();
extern sensor_func_t sensor_func;

float convert_to_fahrenheit();

#endif