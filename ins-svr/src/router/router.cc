#include "router.h"

void RunRouter(httplib::Server& svr)
{
    svr.Post("/", [=](const httplib::Request & /*req*/, httplib::Response &res) {
        res.set_content("ok", "text/plain");
    });

    svr.Post("/ping", [](const httplib::Request & /*req*/, httplib::Response &res) {
        res.set_content("pong", "text/plain");
    });
}
