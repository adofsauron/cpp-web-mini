#include <iostream>

#include "router_test.h"
#include "../logger/logger.h"

void RunRouterTest(httplib::Server& svr)
{
    // test data
    svr.Post("/testData", [](const httplib::Request& req, httplib::Response &res) {
        LogInstance().info("testData body: %s", req.body.c_str());

        {
            httplib::Client cli("localhost", 8080);
            if (auto res = cli.Post("/ping")) {
                std::cout << "res->status: " << res->status << std::endl;
                std::cout << "res->get_header: " << res->get_header_value("Content-Type") << std::endl;
                std::cout << "res->body: " << res->body << std::endl;
            } else {
                std::cout << "error code: " << res.error() << std::endl;
            }
        }

        res.set_content(req.body.c_str(), "text/plain");
    });
}

