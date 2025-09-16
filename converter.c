#include "converter.h"
#include "sensor.h"

sensor_func_t sensor_func = get_sensor_reading;

float convert_to_fahrenheit() {
    int celsius = sensor_func();
    return (celsius * 9.0 / 5.0) + 32.0;
}