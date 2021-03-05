#include "algebra_tests.hpp"
#include "basic_operations_tests.hpp"
#include "datatype_conversion_tests.hpp"
#include "initialization_tests.hpp"
#include "logical_operations_tests.hpp"
#include "mathematical_operations_tests.hpp"
#include "min_max_tests.hpp"
#include "miscellaneous_tests.hpp"
#include "slicing_tests.hpp"
#include "statistical_operations_tests.hpp"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}