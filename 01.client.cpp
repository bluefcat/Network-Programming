#include <iostream>
#include <string>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

int main(int argc, char** argv){
	try{
		if(argc != 2){
			std::cerr << "USAGE: client <host>\n";
			return EXIT_FAILURE;
		}

		tcp::iostream stream(argv[1], std::to_string(int(13)));

		if(!stream){
			std::cout << "no addr. unable to connect: " << stream.error().message() << std::endl;
			return EXIT_FAILURE;
		}

		stream << "Hello from client\n";

		std::string line;
		std::getline(stream, line);
		std::cout << line << std::endl;

	}
	catch(std::exception& e){
		std::cout << e.what() << std::endl;	
	}
	return 0;
}
