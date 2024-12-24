#ifndef DERIBIT_API_H
#define DERIBIT_API_H

#include <string>
#include <curl/curl.h>

class DeribitAPI {
public:
    DeribitAPI(const std::string& client_id, const std::string& client_secret);
    bool authenticate();

private:
    std::string client_id;
    std::string client_secret;
    std::string access_token;
};

#endif // DERIBIT_API_H
