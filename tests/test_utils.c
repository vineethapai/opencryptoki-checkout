#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "../src/utils.h"

/* --- add() tests --- */
void test_add_positive(void)
{
    CU_ASSERT_EQUAL(add(2, 3), 5);
}

void test_add_negative(void)
{
    CU_ASSERT_EQUAL(add(-2, -3), -5);
}

void test_add_zero(void)
{
    CU_ASSERT_EQUAL(add(0, 0), 0);
}

/* --- subtract() tests --- */
void test_subtract_positive(void)
{
    CU_ASSERT_EQUAL(subtract(5, 3), 2);
}

void test_subtract_negative_result(void)
{
    CU_ASSERT_EQUAL(subtract(3, 5), -2);
}

/* --- multiply() tests --- */
void test_multiply_positive(void)
{
    CU_ASSERT_EQUAL(multiply(4, 3), 12);
}

void test_multiply_by_zero(void)
{
    CU_ASSERT_EQUAL(multiply(5, 0), 0);
}

void test_multiply_negative(void)
{
    CU_ASSERT_EQUAL(multiply(-2, 3), -6);
}

/* --- factorial() tests --- */
void test_factorial_zero(void)
{
    CU_ASSERT_EQUAL(factorial(0), 1);
}

void test_factorial_one(void)
{
    CU_ASSERT_EQUAL(factorial(1), 1);
}

void test_factorial_positive(void)
{
    CU_ASSERT_EQUAL(factorial(5), 120);
}

void test_factorial_negative(void)
{
    CU_ASSERT_EQUAL(factorial(-1), -1);
}

int main(void)
{
    if (CU_initialize_registry() != CUE_SUCCESS)
        return CU_get_error();

    CU_pSuite suite = CU_add_suite("utils_suite", NULL, NULL);
    if (suite == NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_add_test(suite, "add: positive numbers", test_add_positive);
    CU_add_test(suite, "add: negative numbers", test_add_negative);
    CU_add_test(suite, "add: zeros", test_add_zero);
    CU_add_test(suite, "subtract: positive result", test_subtract_positive);
    CU_add_test(suite, "subtract: negative result", test_subtract_negative_result);
    CU_add_test(suite, "multiply: positive numbers", test_multiply_positive);
    CU_add_test(suite, "multiply: by zero", test_multiply_by_zero);
    CU_add_test(suite, "multiply: negative numbers", test_multiply_negative);
    CU_add_test(suite, "factorial: zero", test_factorial_zero);
    CU_add_test(suite, "factorial: one", test_factorial_one);
    CU_add_test(suite, "factorial: positive", test_factorial_positive);
    CU_add_test(suite, "factorial: negative input", test_factorial_negative);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}
