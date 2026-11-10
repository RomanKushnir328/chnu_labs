#include <iostream>
#include <string>
#include <vector>
#include <array>
#include "intarray.hpp"

int main() {
    const std::string A_NAME = "A";
    const std::string B_NAME = "B";
    const int ARR_A_EL_COUNT = 5;
    const int VECT_B_EL_COUNT = 7;
    std::array<float, ARR_A_EL_COUNT> arr_a;
    std::vector<float> vect_b(VECT_B_EL_COUNT, 0);

    fill_in_and_process_int_array(A_NAME, arr_a);
    fill_in_and_process_int_array(B_NAME, vect_b); 

    return 0;
}