#include <iostream>
#include <string>
#include "intarray.h"

int main() {
    const std::string A_NAME = "A";
    const std::string B_NAME = "B";
    const int ARR_A_EL_COUNT = 5;
    const int ARR_B_EL_COUNT = 7;
    int a[ARR_A_EL_COUNT];
    int b[ARR_B_EL_COUNT];

    fill_in_and_process_int_array(A_NAME, a, ARR_A_EL_COUNT);
    fill_in_and_process_int_array(B_NAME, b, ARR_B_EL_COUNT); 

    return 0;
}