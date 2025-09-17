#ifndef SENSOR_H
#define SENSOR_H

#include <stdbool.h>

int get_sensor_reading();
int get_sensor_status();
float calibrate_sensor(int offset);
int validate_temperature(int temp);
int get_sensor_health_percentage();
void reset_sensor_calibration();
int is_sensor_calibrated();
float get_sensor_accuracy();
int get_sensor_error_code();
void set_sensor_threshold(float threshold);
float get_sensor_threshold();
int is_sensor_connected();
void log_sensor_reading(int temp);
int get_sensor_reading_history(int index);
int get_sensor_uptime();
bool detect_rapid_temperature_change(int previous_temp, int current_temp, int threshold);

#endif