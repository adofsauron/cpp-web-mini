

#include "server.h"
#include "../router/router.h"
#include "../router/router_test.h"

#define SERVER_CERT_FILE "./cert.pem"
#define SERVER_PRIVATE_KEY_FILE "./key.pem"

#define LISTERN_HOST "localhost"
#define LISTERN_PORT 8080

int main(void) {
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
        printf("%s", log(req, res).c_str());
    });

    // router
    RunRouter(svr);

    // router test
    RunRouterTest(svr);

    svr.listen(LISTERN_HOST, LISTERN_PORT);

    return 0;
}

