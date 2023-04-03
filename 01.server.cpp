#include <iostream>
#include <vector>
#include <utility>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

int main(){
	try{
		boost::asio::io_service io_service;

		tcp::endpoint endpoint(tcp::v4(), 13);
		tcp::acceptor acceptor(io_service, endpoint);

		std::cout << "Server Started\n";

		for(;;){
			const std::string message_to_send = "Hello from Server";

			boost::asio::ip::tcp::iostream stream;

			std::cout << "check 1\n";

			boost::system::error_code ec;
			acceptor.accept(*stream.rdbuf(), ec);

			std::cout << "check 2" << std::endl;

			if(ec) continue;

			std::string line;
			std::getline(stream, line);
			std::cout << line << "\n";

			stream << message_to_send;
			stream << "\n";
		}

	}
	catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}
	

	return 0;
}
