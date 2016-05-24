//This is not my code. I got this from: http://dahu.co.uk/blog/?p=77
#include <iostream> //Line fixed from original code.
#include "curly.h"

int main (int argc, const char * argv[])
{

    Curly curly;

    if (curly.Fetch("http://www.google.com") == CURLE_OK){

        std::cout << "status: " << curly.HttpStatus() << std::endl;
        std::cout << "type: " << curly.Type() << std::endl;
	//Fixed - Added argument list to vector object within the angled brackets std::string
        std::vector<std::string> headers = curly.Headers();
	//Same in this line. otherwise compiler will bitch on a mac.
        for(std::vector<std::string>::iterator it = headers.begin(); //Line fixed from original code.
                it != headers.end(); it++)
            std::cout << "Header: " << (*it) << std::endl;
        std::cout << "Content:\n" << curly.Content() << std::endl;
    }

    return 0;
}

