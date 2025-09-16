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


void test_get_sensor_status() {
    // AI-generated test for get_sensor_status
    int result = get_sensor_status();
    TEST_ASSERT_EQUAL(1, result);  // Expected status OK
}


void test_calibrate_sensor() {
    // AI-generated test for calibrate_sensor
    float result = calibrate_sensor(5);
    TEST_ASSERT_FLOAT_WITHIN(0.01, 30.0, result);  // 25 + 5 = 30
}


void test_validate_temperature_valid() {
    // AI-generated test for validate_temperature - valid temperature
    int result = validate_temperature(25);
    TEST_ASSERT_EQUAL(1, result);  // Should be valid
}

void test_validate_temperature_invalid_high() {
    // AI-generated test for validate_temperature - invalid high temperature
    int result = validate_temperature(150);
    TEST_ASSERT_EQUAL(0, result);  // Should be invalid
}

void test_validate_temperature_invalid_low() {
    // AI-generated test for validate_temperature - invalid low temperature
    int result = validate_temperature(-100);
    TEST_ASSERT_EQUAL(0, result);  // Should be invalid
}


void test_convert_to_kelvin() {
    // AI-generated test for convert_to_kelvin
    sensor_func = stub_get_sensor_reading;
    stub_sensor_value = 25;
    float result = convert_to_kelvin();
    TEST_ASSERT_FLOAT_WITHIN(0.01, 298.15, result);  // 25 + 273.15
}


void test_convert_to_rankine() {
    // AI-generated test for convert_to_rankine
    sensor_func = stub_get_sensor_reading;
    stub_sensor_value = 25;
    float result = convert_to_rankine();
    TEST_ASSERT_FLOAT_WITHIN(0.01, 536.67, result);  // (25 + 273.15) * 9/5
}


void test_get_temperature_scale_name() {
    // AI-generated test for get_temperature_scale_name
    char* result = get_temperature_scale_name(0);
    TEST_ASSERT_EQUAL_STRING("Celsius", result);
}


void test_is_temperature_extreme_normal() {
    // AI-generated test for is_temperature_extreme - normal temperature
    int result = is_temperature_extreme(25.0, 0);
    TEST_ASSERT_EQUAL(0, result);  // Should not be extreme
}

void test_is_temperature_extreme_extreme() {
    // AI-generated test for is_temperature_extreme - extreme temperature
    int result = is_temperature_extreme(60.0, 0);
    TEST_ASSERT_EQUAL(1, result);  // Should be extreme
}

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_get_sensor_reading);
    RUN_TEST(test_convert_to_fahrenheit_normal);
    RUN_TEST(test_convert_to_fahrenheit_zero);
    RUN_TEST(test_convert_to_fahrenheit_negative);
    RUN_TEST(test_convert_to_fahrenheit_high);
        RUN_TEST(test_get_sensor_status);
        RUN_TEST(test_calibrate_sensor);
    
    RUN_TEST(test_validate_temperature_valid);
    RUN_TEST(test_validate_temperature_invalid_high);
    RUN_TEST(test_validate_temperature_invalid_low);

        RUN_TEST(test_convert_to_kelvin);
        RUN_TEST(test_convert_to_rankine);
        RUN_TEST(test_get_temperature_scale_name);
    
    RUN_TEST(test_is_temperature_extreme_normal);
    RUN_TEST(test_is_temperature_extreme_extreme);

    return UNITY_END();
}