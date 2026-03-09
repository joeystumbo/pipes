#include <iostream>
#include <cassert>
#include <regex>
#include "../include/date_utils.h"

void test_get_current_iso8601() {
    std::string iso_date = get_current_iso8601();
    std::cout << "Generated date: " << iso_date << std::endl;
    
    // ISO 8601 format: YYYY-MM-DDTHH:MM:SSZ
    std::regex iso_regex(R"(\d{4}-\d{2}-\d{2}T\d{2}:\d{2}:\d{2}Z)");
    assert(std::regex_match(iso_date, iso_regex));
    std::cout << "test_get_current_iso8601 passed!" << std::endl;
}

int main() {
    test_get_current_iso8601();
    return 0;
}
