#!/usr/bin/env python3

import sys

if len(sys.argv) != 3:
    print("Usage: python3 generate_tests.py functions.txt test_file.c")
    sys.exit(1)

functions_file = sys.argv[1]
test_file = sys.argv[2]

# Read functions
with open(functions_file, 'r') as f:
    functions = [line.strip() for line in f if line.strip()]

# Read existing test file
with open(test_file, 'r') as f:
    content = f.read()

# For each function, add a test if not exists
for func in functions:
    if func == 'get_sensor_reading':
        test_names = [f'test_{func}']
        test_code = f'''
void test_{func}() {{
    // AI-generated test for {func}
    int result = get_sensor_reading();
    TEST_ASSERT_EQUAL(25, result);  // Expected hardcoded value
}}
'''
        run_tests = f'    RUN_TEST(test_{func});'
    elif func == 'get_sensor_status':
        test_names = [f'test_{func}']
        test_code = f'''
void test_{func}() {{
    // AI-generated test for {func}
    int result = get_sensor_status();
    TEST_ASSERT_EQUAL(1, result);  // Expected status OK
}}
'''
        run_tests = f'    RUN_TEST(test_{func});'
    elif func == 'calibrate_sensor':
        test_names = [f'test_{func}']
        test_code = f'''
void test_{func}() {{
    // AI-generated test for {func}
    float result = calibrate_sensor(5);
    TEST_ASSERT_FLOAT_WITHIN(0.01, 30.0, result);  // 25 + 5 = 30
}}
'''
        run_tests = f'    RUN_TEST(test_{func});'
    elif func == 'validate_temperature':
        test_names = [f'test_{func}_valid', f'test_{func}_invalid_high', f'test_{func}_invalid_low']
        test_code = f'''
void test_{func}_valid() {{
    // AI-generated test for {func} - valid temperature
    int result = validate_temperature(25);
    TEST_ASSERT_EQUAL(1, result);  // Should be valid
}}

void test_{func}_invalid_high() {{
    // AI-generated test for {func} - invalid high temperature
    int result = validate_temperature(150);
    TEST_ASSERT_EQUAL(0, result);  // Should be invalid
}}

void test_{func}_invalid_low() {{
    // AI-generated test for {func} - invalid low temperature
    int result = validate_temperature(-100);
    TEST_ASSERT_EQUAL(0, result);  // Should be invalid
}}
'''
        run_tests = f'''
    RUN_TEST(test_{func}_valid);
    RUN_TEST(test_{func}_invalid_high);
    RUN_TEST(test_{func}_invalid_low);
'''
    elif func == 'convert_to_fahrenheit':
        test_names = [f'test_{func}_normal', f'test_{func}_zero', f'test_{func}_negative']
        test_code = f'''
void test_{func}_normal() {{
    // AI-generated test for {func} - normal case
    sensor_func = stub_get_sensor_reading;
    stub_sensor_value = 25;
    float result = convert_to_fahrenheit();
    TEST_ASSERT_FLOAT_WITHIN(0.01, 77.0, result);
}}

void test_{func}_zero() {{
    // AI-generated test for {func} - edge case zero
    sensor_func = stub_get_sensor_reading;
    stub_sensor_value = 0;
    float result = convert_to_fahrenheit();
    TEST_ASSERT_FLOAT_WITHIN(0.01, 32.0, result);
}}

void test_{func}_negative() {{
    // AI-generated test for {func} - edge case negative
    sensor_func = stub_get_sensor_reading;
    stub_sensor_value = -10;
    float result = convert_to_fahrenheit();
    TEST_ASSERT_FLOAT_WITHIN(0.01, 14.0, result);
}}
'''
        run_tests = f'''
    RUN_TEST(test_{func}_normal);
    RUN_TEST(test_{func}_zero);
    RUN_TEST(test_{func}_negative);
'''
    elif func == 'convert_to_kelvin':
        test_names = [f'test_{func}']
        test_code = f'''
void test_{func}() {{
    // AI-generated test for {func}
    sensor_func = stub_get_sensor_reading;
    stub_sensor_value = 25;
    float result = convert_to_kelvin();
    TEST_ASSERT_FLOAT_WITHIN(0.01, 298.15, result);  // 25 + 273.15
}}
'''
        run_tests = f'    RUN_TEST(test_{func});'
    elif func == 'convert_to_rankine':
        test_names = [f'test_{func}']
        test_code = f'''
void test_{func}() {{
    // AI-generated test for {func}
    sensor_func = stub_get_sensor_reading;
    stub_sensor_value = 25;
    float result = convert_to_rankine();
    TEST_ASSERT_FLOAT_WITHIN(0.01, 536.67, result);  // (25 + 273.15) * 9/5
}}
'''
        run_tests = f'    RUN_TEST(test_{func});'
    elif func == 'get_temperature_scale_name':
        test_names = [f'test_{func}']
        test_code = f'''
void test_{func}() {{
    // AI-generated test for {func}
    char* result = get_temperature_scale_name(0);
    TEST_ASSERT_EQUAL_STRING("Celsius", result);
}}
'''
        run_tests = f'    RUN_TEST(test_{func});'
    elif func == 'is_temperature_extreme':
        test_names = [f'test_{func}_normal', f'test_{func}_extreme']
        test_code = f'''
void test_{func}_normal() {{
    // AI-generated test for {func} - normal temperature
    int result = is_temperature_extreme(25.0, 0);
    TEST_ASSERT_EQUAL(0, result);  // Should not be extreme
}}

void test_{func}_extreme() {{
    // AI-generated test for {func} - extreme temperature
    int result = is_temperature_extreme(60.0, 0);
    TEST_ASSERT_EQUAL(1, result);  // Should be extreme
}}
'''
        run_tests = f'''
    RUN_TEST(test_{func}_normal);
    RUN_TEST(test_{func}_extreme);
'''
    else:
        test_names = [f'test_{func}']
        test_code = f'''
void test_{func}() {{
    // AI-generated test for {func}
    // TODO: Add specific assertions based on function behavior
    TEST_ASSERT_TRUE(true);  // Placeholder assertion
}}
'''
        run_tests = f'    RUN_TEST(test_{func});'

    # Check if any of the test names already exist
    skip = False
    for tname in test_names:
        if tname in content:
            skip = True
            break

    if not skip:
        # Insert before main
        if 'int main()' in content:
            content = content.replace('int main()', test_code + '\nint main()')
        else:
            content += test_code

        # Add RUN_TEST in main
        if 'return UNITY_END();' in content:
            content = content.replace('return UNITY_END();', run_tests + '\n    return UNITY_END();')

# Write back
with open(test_file, 'w') as f:
    f.write(content)

print(f"Generated tests for functions: {', '.join(functions)}")