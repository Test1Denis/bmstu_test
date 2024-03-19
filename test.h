#ifndef _test_h_
#define _test_h_

#include <iostream>
#include <string>

void run_test(void (*test)(), const std::string& name_func); 
#define RUN_TEST(f) run_test(f, #f)	


void Assert(bool expression);
void Assert_Hint(bool expression, const std::string& hint); 

#define ASSERT(expr) Assert_Hint(expr, "")
#define ASSERT_HINT(expr, hint) Assert_Hint(expr, hint)

//template<class T>
//void AssertArray(const T* array_in, const T* array_etalon, size_t size) {}

void AssertArray(const int* array_in, const int* array_etalon, size_t size);
#define ASSERT_ARRAY(expr, size, expr_true)	AssertArray(expr, expr_true, size)

void AssertEqual(int expression, int expression_true, 
				const std::string& str_expression, const std::string& str_expression_true);
#define ASSERT_EQUAL(expr, expr_true)	AssertEqual(expr, expr_true, #expr, #expr_true)

void AssertEqualHint(int expr, int expr_true, 
				const std::string& str_expression, const std::string& str_expression_true, const std::string& hint);
#define ASSERT_EQUAL_HINT(expr, epxr_true, hint)	AssertEqualHint(expr, expr_true, #expr, #expr_true, #hint)
											

#endif
