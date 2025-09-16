#include "converter.h"
#include "sensor.h"

sensor_func_t sensor_func = get_sensor_reading;

float convert_to_fahrenheit() {
    int celsius = sensor_func();
    return (celsius * 9.0 / 5.0) + 32.0;
}

float convert_to_kelvin() {
    int celsius = sensor_func();
    return celsius + 273.15;
}

float convert_to_rankine() {
    int celsius = sensor_func();
    return (celsius + 273.15) * 9.0 / 5.0;
}

char* get_temperature_scale_name(int scale) {
    switch (scale) {
        case 0: return "Celsius";
        case 1: return "Fahrenheit";
        case 2: return "Kelvin";
        case 3: return "Rankine";
        default: return "Unknown";
    }
}

int is_temperature_extreme(float temp, int scale) {
    switch (scale) {
        case 0: // Celsius
            return (temp < -40 || temp > 50) ? 1 : 0;
        case 1: // Fahrenheit
            return (temp < -40 || temp > 122) ? 1 : 0;
        case 2: // Kelvin
            return (temp < 233 || temp > 323) ? 1 : 0;
        default:
            return 0;
    }
}