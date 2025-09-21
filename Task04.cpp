#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <curl/curl.h>

using namespace std;
size_t WriteCallback(void* contents, size_t size, size_t nmemb, string* output) {
    size_t totalSize = size * nmemb;
    output->append((char*)contents, totalSize);
    return totalSize;
}

int main() {
    CURL* curl;
    CURLcode res;
    string html;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://example.com/products");
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &html);
        res = curl_easy_perform(curl);

        if(res != CURLE_OK) {
            cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << endl;
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    regex nameRegex("<h2 class=\"product-name\">([^<]+)</h2>");
    regex priceRegex("<span class=\"price\">\\$([0-9]+\\.[0-9]{2})</span>");
    regex ratingRegex("<span class=\"rating\">([0-9]\\.[0-9])</span>");

    smatch match;
    auto namesBegin = sregex_iterator(html.begin(), html.end(), nameRegex);
    auto pricesBegin = sregex_iterator(html.begin(), html.end(), priceRegex);
    auto ratingsBegin = sregex_iterator(html.begin(), html.end(), ratingRegex);

    ofstream file("products.csv");
    file << "Name,Price,Rating\n";

    auto nameIt = namesBegin;
    auto priceIt = pricesBegin;
    auto ratingIt = ratingsBegin;

    while (nameIt != sregex_iterator() && priceIt != sregex_iterator() && ratingIt != sregex_iterator()) {
        string name = (*nameIt)[1].str();
        string price = (*priceIt)[1].str();
        string rating = (*ratingIt)[1].str();

        file << "\"" << name << "\"," << price << "," << rating << "\n";

        ++nameIt;
        ++priceIt;
        ++ratingIt;
    }

    file.close();
    cout << "Data saved to products.csv\n";

    return 0;
}

