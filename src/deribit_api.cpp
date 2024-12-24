#include "deribit_api.h"
#include <iostream>
#include <sstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

DeribitAPI::DeribitAPI(const std::string& client_id, const std::string& client_secret)
    : client_id(client_id), client_secret(client_secret) {}

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* out) {
    size_t total_size = size * nmemb;
    if (out) {
        out->append((char*)contents, total_size);
    }
    return total_size;
}

bool DeribitAPI::authenticate() {
    CURL* curl = curl_easy_init();
    if (!curl) {
        std::cerr << "Failed to initialize CURL" << std::endl;
        return false;
    }

    std::string url = "https://test.deribit.com/api/v2/public/auth";
    
    // Create JSON payload
    json payload = {
        {"jsonrpc", "2.0"},
        {"id", "auth"},
        {"method", "public/auth"},
        {"params", {
            {"grant_type", "client_credentials"},
            {"client_id", client_id},
            {"client_secret", client_secret}
        }}
    };
    std::string json_str = payload.dump();

    // Set up headers
    struct curl_slist* headers = nullptr;
    headers = curl_slist_append(headers, "Content-Type: application/json");
    
    std::string response;

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json_str.c_str());
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    CURLcode res = curl_easy_perform(curl);
    curl_slist_free_all(headers);
    
    if (res != CURLE_OK) {
        std::cerr << "CURL request failed: " << curl_easy_strerror(res) << std::endl;
        curl_easy_cleanup(curl);
        return false;
    }

    long http_code = 0;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
    curl_easy_cleanup(curl);

    if (http_code != 200) {
        std::cerr << "HTTP response code: " << http_code << "\nResponse: " << response << std::endl;
        return false;
    }

    try {
        auto json_response = json::parse(response);
        if (json_response.contains("result") && json_response["result"].contains("access_token")) {
            access_token = json_response["result"]["access_token"].get<std::string>();
            return true;
        }
        std::cerr << "Response doesn't contain access token: " << response << std::endl;
        return false;
    } catch (const std::exception& e) {
        std::cerr << "Failed to parse JSON response: " << e.what() << std::endl;
        return false;
    }
}



// ---------------------------------------------------------------------------------------------------------
// #include "deribit_api.h"
// #include <iostream>
// #include <sstream>
// #include <nlohmann/json.hpp>

// using json = nlohmann::json;

// DeribitAPI::DeribitAPI(const std::string& client_id, const std::string& client_secret)
//     : client_id(client_id), client_secret(client_secret) {}

// static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* out) {
//     size_t total_size = size * nmemb;
//     if (out) {
//         out->append((char*)contents, total_size);
//     }
//     return total_size;
// }

// bool DeribitAPI::authenticate() {
//     CURL* curl = curl_easy_init();
//     if (!curl) {
//         std::cerr << "Failed to initialize CURL" << std::endl;
//         return false;
//     }

//     std::string url = "https://test.deribit.com/api/v2/public/auth";
//     std::string post_fields = "grant_type=client_credentials&client_id=" + client_id + "&client_secret=" + client_secret;
//     std::string response;

//     curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
//     curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post_fields.c_str());
//     curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
//     curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

//     CURLcode res = curl_easy_perform(curl);
//     if (res != CURLE_OK) {
//         std::cerr << "CURL request failed: " << curl_easy_strerror(res) << std::endl;
//         curl_easy_cleanup(curl);
//         return false;
//     }

//     long http_code = 0;
//     curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
//     curl_easy_cleanup(curl);

//     if (http_code != 200) {
//         std::cerr << "HTTP response code: " << http_code << "\nResponse: " << response << std::endl;
//         return false;
//     }

//     try {
//         auto json_response = json::parse(response);
//         access_token = json_response.at("result").at("access_token").get<std::string>();
//     } catch (const std::exception& e) {
//         std::cerr << "Failed to parse JSON response: " << e.what() << std::endl;
//         return false;
//     }

//     return true;
// }
