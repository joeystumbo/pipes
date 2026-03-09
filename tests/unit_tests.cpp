#include <gtest/gtest.h>

#include <regex>

#include "../include/date_utils.h"

TEST(DateUtilsTest, GetCurrentIso8601Format) {
    std::string iso_date = get_current_iso8601();

    // ISO 8601 format: YYYY-MM-DDTHH:MM:SSZ
    std::regex iso_regex(R"(\d{4}-\d{2}-\d{2}T\d{2}:\d{2}:\d{2}Z)");
    EXPECT_TRUE(std::regex_match(iso_date, iso_regex))
        << "Generated date " << iso_date << " does not match ISO 8601 format";
}
