// File: main.cpp

#include <iostream>
#include <cstdlib>
#include "deribit_api.h"

int main() {
    const char* client_id_env = std::getenv("DERIBIT_CLIENT_ID");
    const char* client_secret_env = std::getenv("DERIBIT_CLIENT_SECRET");

    if (!client_id_env || !client_secret_env) {
        std::cerr << "Environment variables not set!" << std::endl;
        return 1;
    }

    const std::string client_id = client_id_env;
    const std::string client_secret = client_secret_env;

    DeribitAPI api(client_id, client_secret);
    
    if (api.authenticate()) {
        std::cout << "API call successful!" << std::endl;
    } else {
        std::cerr << "API call failed!" << std::endl;
    }

    return 0;
}
