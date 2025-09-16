#include <stdbool.h>
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


void test_convert_between_scales_celsius_to_fahrenheit() {
    // AI-generated test for convert_between_scales - Celsius to Fahrenheit
    float result = convert_between_scales(25.0, 0, 1);
    TEST_ASSERT_FLOAT_WITHIN(0.01, 77.0, result);
}

void test_convert_between_scales_fahrenheit_to_celsius() {
    // AI-generated test for convert_between_scales - Fahrenheit to Celsius
    float result = convert_between_scales(77.0, 1, 0);
    TEST_ASSERT_FLOAT_WITHIN(0.01, 25.0, result);
}

void test_convert_between_scales_celsius_to_kelvin() {
    // AI-generated test for convert_between_scales - Celsius to Kelvin
    float result = convert_between_scales(25.0, 0, 2);
    TEST_ASSERT_FLOAT_WITHIN(0.01, 298.15, result);
}

void test_convert_between_scales_kelvin_to_rankine() {
    // AI-generated test for convert_between_scales - Kelvin to Rankine
    float result = convert_between_scales(298.15, 2, 3);
    TEST_ASSERT_FLOAT_WITHIN(0.01, 536.67, result);
}

void test_convert_between_scales_invalid_scale() {
    // AI-generated test for convert_between_scales - Invalid scale
    float result = convert_between_scales(25.0, 99, 0);
    TEST_ASSERT_FLOAT_WITHIN(0.01, 0.0, result);  // Should return 0 for invalid scale
}


void test_get_temperature_category_cold() {
    // AI-generated test for get_temperature_category - Cold temperature
    int result = get_temperature_category(-10.0, 0);
    TEST_ASSERT_EQUAL(0, result);  // Should be Cold
}

void test_get_temperature_category_normal() {
    // AI-generated test for get_temperature_category - Normal temperature
    int result = get_temperature_category(15.0, 0);
    TEST_ASSERT_EQUAL(1, result);  // Should be Normal
}

void test_get_temperature_category_warm() {
    // AI-generated test for get_temperature_category - Warm temperature
    int result = get_temperature_category(25.0, 0);
    TEST_ASSERT_EQUAL(2, result);  // Should be Warm
}

void test_get_temperature_category_hot() {
    // AI-generated test for get_temperature_category - Hot temperature
    int result = get_temperature_category(35.0, 0);
    TEST_ASSERT_EQUAL(3, result);  // Should be Hot
}

void test_get_temperature_category_invalid_scale() {
    // AI-generated test for get_temperature_category - Invalid scale
    int result = get_temperature_category(25.0, 99);
    TEST_ASSERT_EQUAL(-1, result);  // Should return -1 for invalid scale
}


void test_get_temperature_category_name_cold() {
    // AI-generated test for get_temperature_category_name - Cold category
    char* result = get_temperature_category_name(0);
    TEST_ASSERT_EQUAL_STRING("Cold", result);
}

void test_get_temperature_category_name_normal() {
    // AI-generated test for get_temperature_category_name - Normal category
    char* result = get_temperature_category_name(1);
    TEST_ASSERT_EQUAL_STRING("Normal", result);
}

void test_get_temperature_category_name_warm() {
    // AI-generated test for get_temperature_category_name - Warm category
    char* result = get_temperature_category_name(2);
    TEST_ASSERT_EQUAL_STRING("Warm", result);
}

void test_get_temperature_category_name_hot() {
    // AI-generated test for get_temperature_category_name - Hot category
    char* result = get_temperature_category_name(3);
    TEST_ASSERT_EQUAL_STRING("Hot", result);
}

void test_get_temperature_category_name_unknown() {
    // AI-generated test for get_temperature_category_name - Unknown category
    char* result = get_temperature_category_name(99);
    TEST_ASSERT_EQUAL_STRING("Unknown", result);
}


void test_get_temperature_warning_threshold_freeze_celsius() {
    // AI-generated test for get_temperature_warning_threshold - Freeze threshold Celsius
    float result = get_temperature_warning_threshold(0, 0);
    TEST_ASSERT_FLOAT_WITHIN(0.01, 0.0, result);
}

void test_get_temperature_warning_threshold_heat_fahrenheit() {
    // AI-generated test for get_temperature_warning_threshold - Heat threshold Fahrenheit
    float result = get_temperature_warning_threshold(1, 1);
    TEST_ASSERT_FLOAT_WITHIN(0.01, 86.0, result);
}

void test_get_temperature_warning_threshold_extreme_cold_kelvin() {
    // AI-generated test for get_temperature_warning_threshold - Extreme cold threshold Kelvin
    float result = get_temperature_warning_threshold(2, 2);
    TEST_ASSERT_FLOAT_WITHIN(0.01, 253.15, result);
}

void test_get_temperature_warning_threshold_extreme_heat_celsius() {
    // AI-generated test for get_temperature_warning_threshold - Extreme heat threshold Celsius
    float result = get_temperature_warning_threshold(0, 3);
    TEST_ASSERT_FLOAT_WITHIN(0.01, 40.0, result);
}


void test_get_temperature_scale_name_celsius() {
    // AI-generated test for get_temperature_scale_name - Celsius scale
    char* result = get_temperature_scale_name(0);
    TEST_ASSERT_EQUAL_STRING("Celsius", result);
}

void test_get_temperature_scale_name_fahrenheit() {
    // AI-generated test for get_temperature_scale_name - Fahrenheit scale
    char* result = get_temperature_scale_name(1);
    TEST_ASSERT_EQUAL_STRING("Fahrenheit", result);
}

void test_get_temperature_scale_name_kelvin() {
    // AI-generated test for get_temperature_scale_name - Kelvin scale
    char* result = get_temperature_scale_name(2);
    TEST_ASSERT_EQUAL_STRING("Kelvin", result);
}

void test_get_temperature_scale_name_rankine() {
    // AI-generated test for get_temperature_scale_name - Rankine scale
    char* result = get_temperature_scale_name(3);
    TEST_ASSERT_EQUAL_STRING("Rankine", result);
}

void test_get_temperature_scale_name_unknown() {
    // AI-generated test for get_temperature_scale_name - Unknown scale
    char* result = get_temperature_scale_name(99);
    TEST_ASSERT_EQUAL_STRING("Unknown", result);
}


void test_is_temperature_extreme_celsius_normal() {
    // AI-generated test for is_temperature_extreme - Celsius normal temperature
    int result = is_temperature_extreme(25.0, 0);
    TEST_ASSERT_EQUAL(0, result);  // Should not be extreme
}

void test_is_temperature_extreme_celsius_extreme() {
    // AI-generated test for is_temperature_extreme - Celsius extreme temperature
    int result = is_temperature_extreme(60.0, 0);
    TEST_ASSERT_EQUAL(1, result);  // Should be extreme
}

void test_is_temperature_extreme_fahrenheit_normal() {
    // AI-generated test for is_temperature_extreme - Fahrenheit normal temperature
    int result = is_temperature_extreme(77.0, 1);
    TEST_ASSERT_EQUAL(0, result);  // Should not be extreme
}

void test_is_temperature_extreme_fahrenheit_extreme() {
    // AI-generated test for is_temperature_extreme - Fahrenheit extreme temperature
    int result = is_temperature_extreme(140.0, 1);
    TEST_ASSERT_EQUAL(1, result);  // Should be extreme
}

void test_is_temperature_extreme_kelvin_normal() {
    // AI-generated test for is_temperature_extreme - Kelvin normal temperature
    int result = is_temperature_extreme(298.0, 2);
    TEST_ASSERT_EQUAL(0, result);  // Should not be extreme
}

void test_is_temperature_extreme_kelvin_extreme() {
    // AI-generated test for is_temperature_extreme - Kelvin extreme temperature
    int result = is_temperature_extreme(350.0, 2);
    TEST_ASSERT_EQUAL(1, result);  // Should be extreme
}

void test_is_temperature_extreme_invalid_scale() {
    // AI-generated test for is_temperature_extreme - Invalid scale
    int result = is_temperature_extreme(25.0, 99);
    TEST_ASSERT_EQUAL(0, result);  // Should return 0 for invalid scale
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

    
    RUN_TEST(test_convert_between_scales_celsius_to_fahrenheit);
    RUN_TEST(test_convert_between_scales_fahrenheit_to_celsius);
    RUN_TEST(test_convert_between_scales_celsius_to_kelvin);
    RUN_TEST(test_convert_between_scales_kelvin_to_rankine);
    RUN_TEST(test_convert_between_scales_invalid_scale);

    
    RUN_TEST(test_get_temperature_category_cold);
    RUN_TEST(test_get_temperature_category_normal);
    RUN_TEST(test_get_temperature_category_warm);
    RUN_TEST(test_get_temperature_category_hot);
    RUN_TEST(test_get_temperature_category_invalid_scale);

    
    RUN_TEST(test_get_temperature_category_name_cold);
    RUN_TEST(test_get_temperature_category_name_normal);
    RUN_TEST(test_get_temperature_category_name_warm);
    RUN_TEST(test_get_temperature_category_name_hot);
    RUN_TEST(test_get_temperature_category_name_unknown);

    
    RUN_TEST(test_get_temperature_warning_threshold_freeze_celsius);
    RUN_TEST(test_get_temperature_warning_threshold_heat_fahrenheit);
    RUN_TEST(test_get_temperature_warning_threshold_extreme_cold_kelvin);
    RUN_TEST(test_get_temperature_warning_threshold_extreme_heat_celsius);

    
    RUN_TEST(test_get_temperature_scale_name_celsius);
    RUN_TEST(test_get_temperature_scale_name_fahrenheit);
    RUN_TEST(test_get_temperature_scale_name_kelvin);
    RUN_TEST(test_get_temperature_scale_name_rankine);
    RUN_TEST(test_get_temperature_scale_name_unknown);

    
    RUN_TEST(test_is_temperature_extreme_celsius_normal);
    RUN_TEST(test_is_temperature_extreme_celsius_extreme);
    RUN_TEST(test_is_temperature_extreme_fahrenheit_normal);
    RUN_TEST(test_is_temperature_extreme_fahrenheit_extreme);
    RUN_TEST(test_is_temperature_extreme_kelvin_normal);
    RUN_TEST(test_is_temperature_extreme_kelvin_extreme);
    RUN_TEST(test_is_temperature_extreme_invalid_scale);

    return UNITY_END();
}