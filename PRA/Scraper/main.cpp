#include <iostream>
#include <string>
#include <fstream>
#include <curl/curl.h>
#include <http_parser.h>

CURL *curl_easy_init( );
CURLcode curl_easy_perform(CURL * easy_handle );
void curl_easy_cleanup(CURL * handle );

using namespace std;

int main () {
    int i=0;
            
    CURL * curl = curl_easy_init();
    if(curl) {
        CURLcode res;
        curl_easy_setopt(curl, CURLOPT_URL, "http://www.yahii.com.br/dolardiario85.html");
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }


    return 0;
}
