#include <bits/stdc++.h>
using namespace std;


class Request {
private:
    string url;
    map<string, string> header;

public:
    Request(string _url): url(_url) {
        header.clear();
    }

    string getHost() const { return url; }

    void setHeaderAttr(string key, string value) { header[key] = value; }

    string getHeaderAttr(string key) { return header[key]; }


    bool post(bool response = true) {
        printf("post to %s\n", url.c_str());
        return response;
    }
};

class RequestProxy {
private:
    Request *req;
public:
    RequestProxy(string url): req(new Request(url)) { }
    void setContent(string contentType, string contentLength, string charset) {
        // set header
        req->setHeaderAttr("content-type", contentType);
        req->setHeaderAttr("content-length", contentLength);
        req->setHeaderAttr("accept-charset", charset);
    }

    ~RequestProxy() { delete req; }

    void post(bool testResponse = true) {
        setContent("text/plain", "512", "utf-8");
        // do post
        printf("request content:\n");
        printf("content-type: %s\n", req->getHeaderAttr("content-type").c_str());
        printf("content-length: %s\n", req->getHeaderAttr("content-length").c_str());
        printf("accept-charset: %s\n", req->getHeaderAttr("accept-charset").c_str());
        bool res = req->post(testResponse);
        if (res) {
            printf("from host: %s\n", req->getHost().c_str());
            printf("request accepted\n");
        }
        else {
            printf("bad request\n");
        }
        printf("\n");
    }
};


int main() {
    string host = "http://lavende.github.io";
    RequestProxy proxy(host);
    proxy.post(true);
    proxy.post(false);
    return 0;
}

/*

Output

request content:
content-type: text/plain
content-length: 512
accept-charset: utf-8
post to http://lavende.github.io
from host: http://lavende.github.io
request accepted

request content:
content-type: text/plain
content-length: 512
accept-charset: utf-8
post to http://lavende.github.io
bad request

*/