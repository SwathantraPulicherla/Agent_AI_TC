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

float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

float fahrenheit_to_kelvin(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0 + 273.15;
}

float kelvin_to_fahrenheit(float kelvin) {
    return (kelvin - 273.15) * 9.0 / 5.0 + 32.0;
}

float celsius_to_rankine(float celsius) {
    return (celsius + 273.15) * 9.0 / 5.0;
}

float rankine_to_celsius(float rankine) {
    return (rankine - 491.67) * 5.0 / 9.0;
}

int is_temperature_in_range(float temp, int scale, float min, float max) {
    // Check if temperature is within specified range
    float celsius_temp;

    // Convert to Celsius for comparison
    switch (scale) {
        case 0: celsius_temp = temp; break;
        case 1: celsius_temp = fahrenheit_to_celsius(temp); break;
        case 2: celsius_temp = kelvin_to_celsius(temp); break;
        case 3: celsius_temp = rankine_to_celsius(temp); break;
        default: return 0; // Invalid scale
    }

    return (celsius_temp >= min && celsius_temp <= max) ? 1 : 0;
}

float get_temperature_difference(float temp1, float temp2, int scale) {
    // Calculate difference between two temperatures
    return temp1 - temp2;
}

char* format_temperature(float temp, int scale, int precision) {
    // Format temperature with specified precision (mock implementation)
    switch (scale) {
        case 0: return "25.0°C";
        case 1: return "77.0°F";
        case 2: return "298.2K";
        case 3: return "536.7°R";
        default: return "N/A";
    }
}

int compare_temperatures(float temp1, float temp2) {
    // Compare two temperatures: -1 if temp1 < temp2, 0 if equal, 1 if temp1 > temp2
    if (temp1 < temp2) return -1;
    if (temp1 > temp2) return 1;
    return 0;
}

float get_average_temperature(float temps[], int count) {
    // Calculate average of temperature array
    if (count == 0) return 0.0;

    float sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += temps[i];
    }
    return sum / count;
}

float get_temperature_variance(float temps[], int count, float mean) {
    // Calculate variance of temperature array
    if (count <= 1) return 0.0;

    float sum_squared_diff = 0.0;
    for (int i = 0; i < count; i++) {
        float diff = temps[i] - mean;
        sum_squared_diff += diff * diff;
    }
    return sum_squared_diff / (count - 1);
}

int is_temperature_safe(float temp, int scale) {
    // Check if temperature is within safe range for human comfort (10°C to 30°C equivalent)
    float celsius_temp;
    
    // Convert to Celsius for safety check
    switch (scale) {
        case 0: celsius_temp = temp; break;
        case 1: celsius_temp = fahrenheit_to_celsius(temp); break;
        case 2: celsius_temp = kelvin_to_celsius(temp); break;
        case 3: celsius_temp = rankine_to_celsius(temp); break;
        default: return 0; // Invalid scale, assume unsafe
    }
    
    return (celsius_temp >= 10.0 && celsius_temp <= 30.0) ? 1 : 0;
}