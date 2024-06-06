#include <Channel.hpp>

void	Channel::parseMode(std::string& modeLine)
{
	std::istringstream cmd(command);
	std::string tmp;
	std::vector<std::string> tokens;

	while (std::getline(cmd, tmp, ' '))
		tokens.push_back(tmp);
	if (tokens.size() < 2)
	{
		std::cout << "ERR_NEEDMOREPARAMS" << std::endl;
		return;
	}

}