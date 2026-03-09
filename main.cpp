#include <iostream>
#include "include/external/httplib.h"
#include "include/external/json.hpp"
#include "include/date_utils.h"

using json = nlohmann::json;

int main() {
    httplib::Server svr;

    svr.Get("/datetime", [](const httplib::Request &, httplib::Response &res) {
        json j;
        j["current_datetime"] = get_current_iso8601();
        res.set_content(j.dump(), "application/json");
    });

    std::cout << "Server starting on http://0.0.0.0:8080" << std::endl;
    svr.listen("0.0.0.0", 8080);

    return 0;
}