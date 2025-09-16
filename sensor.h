#ifndef SENSOR_H
#define SENSOR_H

int get_sensor_reading();
int get_sensor_status();
float calibrate_sensor(int offset);
int validate_temperature(int temp);

#endif