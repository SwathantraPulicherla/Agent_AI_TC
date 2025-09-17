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
float celsius_to_fahrenheit(float celsius);
float fahrenheit_to_celsius(float fahrenheit);
float celsius_to_kelvin(float celsius);
float kelvin_to_celsius(float kelvin);
float fahrenheit_to_kelvin(float fahrenheit);
float kelvin_to_fahrenheit(float kelvin);
float celsius_to_rankine(float celsius);
float rankine_to_celsius(float rankine);
int is_temperature_in_range(float temp, int scale, float min, float max);
float get_temperature_difference(float temp1, float temp2, int scale);
char* format_temperature(float temp, int scale, int precision);
int compare_temperatures(float temp1, float temp2);
float get_average_temperature(float temps[], int count);
float get_temperature_variance(float temps[], int count, float mean);
int is_temperature_safe(float temp, int scale);

#endif