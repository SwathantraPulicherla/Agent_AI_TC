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

float convert_between_scales(float temp, int from_scale, int to_scale) {
    // Convert temperature between different scales
    float celsius_temp;

    // First convert to Celsius
    switch (from_scale) {
        case 0: // Already Celsius
            celsius_temp = temp;
            break;
        case 1: // Fahrenheit to Celsius
            celsius_temp = (temp - 32) * 5.0 / 9.0;
            break;
        case 2: // Kelvin to Celsius
            celsius_temp = temp - 273.15;
            break;
        case 3: // Rankine to Celsius
            celsius_temp = (temp - 491.67) * 5.0 / 9.0;
            break;
        default:
            return 0.0; // Invalid scale
    }

    // Then convert from Celsius to target scale
    switch (to_scale) {
        case 0: // To Celsius
            return celsius_temp;
        case 1: // To Fahrenheit
            return (celsius_temp * 9.0 / 5.0) + 32;
        case 2: // To Kelvin
            return celsius_temp + 273.15;
        case 3: // To Rankine
            return (celsius_temp + 273.15) * 9.0 / 5.0;
        default:
            return 0.0; // Invalid scale
    }
}

int get_temperature_category(float temp, int scale) {
    // Categorize temperature as Cold, Normal, Warm, Hot
    float celsius_temp;

    // Convert to Celsius for categorization
    switch (scale) {
        case 0: celsius_temp = temp; break;
        case 1: celsius_temp = (temp - 32) * 5.0 / 9.0; break;
        case 2: celsius_temp = temp - 273.15; break;
        case 3: celsius_temp = (temp - 491.67) * 5.0 / 9.0; break;
        default: return -1; // Invalid
    }

    if (celsius_temp < 0) return 0;      // Cold
    else if (celsius_temp < 20) return 1; // Normal
    else if (celsius_temp < 30) return 2; // Warm
    else return 3;                       // Hot
}

char* get_temperature_category_name(int category) {
    switch (category) {
        case 0: return "Cold";
        case 1: return "Normal";
        case 2: return "Warm";
        case 3: return "Hot";
        default: return "Unknown";
    }
}

float get_temperature_warning_threshold(int scale, int warning_type) {
    // Return warning thresholds for different scales
    // warning_type: 0=freeze, 1=heat, 2=extreme_cold, 3=extreme_heat
    switch (scale) {
        case 0: // Celsius
            switch (warning_type) {
                case 0: return 0.0;   // Freeze warning
                case 1: return 30.0;  // Heat warning
                case 2: return -20.0; // Extreme cold
                case 3: return 40.0;  // Extreme heat
                default: return 0.0;
            }
        case 1: // Fahrenheit
            switch (warning_type) {
                case 0: return 32.0;   // Freeze warning
                case 1: return 86.0;   // Heat warning
                case 2: return -4.0;   // Extreme cold
                case 3: return 104.0;  // Extreme heat
                default: return 0.0;
            }
        case 2: // Kelvin
            switch (warning_type) {
                case 0: return 273.15; // Freeze warning
                case 1: return 303.15; // Heat warning
                case 2: return 253.15; // Extreme cold
                case 3: return 313.15; // Extreme heat
                default: return 0.0;
            }
        default:
            return 0.0;
    }
}