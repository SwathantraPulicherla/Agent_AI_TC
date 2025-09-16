#ifndef CONVERTER_H
#define CONVERTER_H

typedef int (*sensor_func_t)();
extern sensor_func_t sensor_func;

float convert_to_fahrenheit();
float convert_to_kelvin();
float convert_to_rankine();
char* get_temperature_scale_name(int scale);
int is_temperature_extreme(float temp, int scale);

#endif