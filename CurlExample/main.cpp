#include <iostream>
#include "curly.h"

int main (int argc, const char * argv[])
{

    Curly curly;

    if (curly.Fetch("http://www.google.com") == CURLE_OK){

        std::cout << "status: " << curly.HttpStatus() << std::endl;
        std::cout << "type: " << curly.Type() << std::endl;
        std::vector<std::string> headers = curly.Headers();

        for(std::vector<std::string>::iterator it = headers.begin();
                it != headers.end(); it++)
            std::cout << "Header: " << (*it) << std::endl;

        std::cout << "Content:\n" << curly.Content() << std::endl;
    }

    return 0;
}

