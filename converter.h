#ifndef CONVERTER_H
#define CONVERTER_H

typedef int (*sensor_func_t)();
extern sensor_func_t sensor_func;

float convert_to_fahrenheit();
float convert_to_kelvin();
float convert_to_rankine();
char* get_temperature_scale_name(int scale);
int is_temperature_extreme(float temp, int scale);
float convert_between_scales(float temp, int from_scale, int to_scale);
int get_temperature_category(float temp, int scale);
char* get_temperature_category_name(int category);
float get_temperature_warning_threshold(int scale, int warning_type);

#endif