#include <stdio.h>
#include "sensor.h"

int get_sensor_reading() {
    // Simulate sensor reading
    return 25; // degrees Celsius
}

int get_sensor_status() {
    // Check if sensor is working
    return 1; // 1 = OK, 0 = Error
}

float calibrate_sensor(int offset) {
    // Calibrate sensor with offset
    return 25.0 + offset;
}

int validate_temperature(int temp) {
    // Validate temperature range
    if (temp >= -50 && temp <= 100) {
        return 1; // Valid
    }
    return 0; // Invalid
}