#include "unity.h"
#include "converter.h"
#include "sensor.h"

// Stub variable
int stub_sensor_value = 25;

// Stub function
int stub_get_sensor_reading() {
    return stub_sensor_value;
}

// Test for sensor
void test_get_sensor_reading() {
    TEST_ASSERT_EQUAL(25, get_sensor_reading());
}

// Test for converter normal case
void test_convert_to_fahrenheit_normal() {
    sensor_func = stub_get_sensor_reading;
    stub_sensor_value = 25;
    float result = convert_to_fahrenheit();
    TEST_ASSERT_FLOAT_WITHIN(0.01, 77.0, result);
}

// Test for zero Celsius
void test_convert_to_fahrenheit_zero() {
    sensor_func = stub_get_sensor_reading;
    stub_sensor_value = 0;
    float result = convert_to_fahrenheit();
    TEST_ASSERT_FLOAT_WITHIN(0.01, 32.0, result);
}

// Test for negative Celsius
void test_convert_to_fahrenheit_negative() {
    sensor_func = stub_get_sensor_reading;
    stub_sensor_value = -10;
    float result = convert_to_fahrenheit();
    TEST_ASSERT_FLOAT_WITHIN(0.01, 14.0, result);
}

// Test for high Celsius value
void test_convert_to_fahrenheit_high() {
    sensor_func = stub_get_sensor_reading;
    stub_sensor_value = 100;
    float result = convert_to_fahrenheit();
    TEST_ASSERT_FLOAT_WITHIN(0.01, 212.0, result);
}

// setUp and tearDown
void setUp() {
    // Reset to default
    sensor_func = get_sensor_reading;
}

void tearDown() {
    // nothing
}

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_get_sensor_reading);
    RUN_TEST(test_convert_to_fahrenheit_normal);
    RUN_TEST(test_convert_to_fahrenheit_zero);
    RUN_TEST(test_convert_to_fahrenheit_negative);
    RUN_TEST(test_convert_to_fahrenheit_high);
    return UNITY_END();
}