#include <iostream>
#include<sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

class Client {
public:
	Client(int socket_fd)
	{
		is_authenticated = false;
		is_registered = false;
		pass = "abc";
		this->socket_fd = socket_fd;
		is_operator = false;
	}

	void authentication();
	
private:
	int socket_fd;
	bool is_operator;
	bool is_authenticated;
	bool is_registered;
	std::string nickname;// for case-insensitive.
    std::string origin_nickname;
	std::string username;
	std::string pass;

	void	sendReply(std::string& reply);

	void	Pass(std::vector<std::string>& pass);
	void	Nick(std::vector<std::string>& nick);
	void	User(std::string& command);
};