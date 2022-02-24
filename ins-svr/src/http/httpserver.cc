#include <chrono>
#include <cstdio>

#include "httpserver.h"
#include "../coroutine/coroutine.h"
#include "../http/httplib.h"
#include "../router/router.h"
#include "../router/router_test.h"
#include "../proc/heart_beat.h"
#include "../logger/logger.h"

const static char* LISTERN_HOST = "localhost";
const static int LISTERN_PORT = 8080;


static std::string httpDumpHeaders(const httplib::Headers &headers) {
    std::string s;
    char buf[BUFSIZ] = {0};

    for (auto it = headers.begin(); it != headers.end(); ++it) {
        const auto &x = *it;
        snprintf(buf, sizeof(buf), "%s: %s\n", x.first.c_str(), x.second.c_str());
        s += buf;
    }

    return s;
}

static std::string httpLog(const httplib::Request &req, const httplib::Response &res) {
    std::string s;
    char buf[BUFSIZ] = {0};

    s += "================================\n";

    snprintf(buf, sizeof(buf), "%s %s %s", req.method.c_str(),
            req.version.c_str(), req.path.c_str());
    s += buf;

    std::string query;
    for (auto it = req.params.begin(); it != req.params.end(); ++it) {
        const auto &x = *it;
        snprintf(buf, sizeof(buf), "%c%s=%s",
                    (it == req.params.begin()) ? '?' : '&', x.first.c_str(),
                    x.second.c_str());
        query += buf;
    }

    snprintf(buf, sizeof(buf), "%s\n", query.c_str());
    s += buf;

    s += httpDumpHeaders(req.headers);

    s += "--------------------------------\n";

    snprintf(buf, sizeof(buf), "%d %s\n", res.status, res.version.c_str());
    s += buf;
    s += httpDumpHeaders(res.headers);
    s += "\n";

    if (!res.body.empty()) { 
        s += res.body; 
    }

    s += "\n";

    return s;
}

int StartHttpServer(void) {
#ifdef CPPHTTPLIB_OPENSSL_SUPPORT
    httplib::SSLServer svr(SERVER_CERT_FILE, SERVER_PRIVATE_KEY_FILE);
#else
    httplib::Server svr;
#endif
  
    if (!svr.is_valid()) {
        printf("server has an error...\n");
        return -1;
    }

    svr.set_error_handler([](const httplib::Request & /*req*/, httplib::Response &res) {
        const char *fmt = "<p>Error Status: <span style='color:red;'>%d</span></p>";
        char buf[BUFSIZ] = {0};
        snprintf(buf, sizeof(buf), fmt, res.status);
        res.set_content(buf, "text/html");
    });

    svr.set_logger([](const httplib::Request &req, const httplib::Response &res) {
        printf("%s", httpLog(req, res).c_str());
    });

    // router
    RunRouter(svr);

    // router test
    RunRouterTest(svr);

    co_yield;
    svr.listen(LISTERN_HOST, static_cast<int>(LISTERN_PORT));

    return 0;
}
