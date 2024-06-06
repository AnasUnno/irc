#include "Client.hpp"


void	Client::authentication()
{
	int	flag = 0;

	while (!flag)
	{
		std::vector<std::string> tokens;
		std::string	cmd_parts;
		std::string	command;
		std::getline(std::cin, command);
		if (command[0] == '\n')
			continue;
		std::istringstream cmd(command);
		while (std::getline(cmd, cmd_parts, ' '))
			tokens.push_back(cmd_parts);
		if (tokens[0] != "PASS" && tokens[0] != "NICK" && tokens[0] != "USER")
		{
			std::cout << "UNREGOGNIZED_COMMAND" << std::endl;
			continue;
		}
		if (!this->is_authenticated)
			Pass(tokens);
		else if (this->nickname.empty())
			Nick(tokens);
		else if (this->username.empty())
		{
			User(command);
		}
		if (this->is_authenticated && this->is_registered)
			flag = 1;
		tokens.clear();
	}
}

void	Client::Pass(std::vector<std::string>& tokens)
{
	if (tokens.size() < 2)
	{
		std::cout << "ERR_NEEDMOREPARAMS" << std::endl;
		return ;
	}
	if (tokens.size() != 2)
	{
		std::cout << "ERR_WRONGPARAMS" << std::endl;
		return ;
	}
	if (tokens[0] == "PASS")
	{
		if (tokens[1] == this->pass)
		{
			this->is_authenticated = true;
			return;
		}
		else
		{
			std::cout << "WRONG_PASS" << std::endl;
			return;
		}
	}
	std::cout << "YOU ARE NOT REGISTRED" << std::endl;
}

void	Client::Nick(std::vector<std::string>& nick)
{
	//need to check on existing nicknames!!
	if (nick.size() < 2)
	{
		std::cout << "ERR_NONICKNAMEGIVEN" << std::endl;
		return;
	}
	if (nick.size() != 2)
	{
		std::cout << "ERR_WRONGPARAMS" << std::endl;
		return ;
	}
	if (nick[0] == "NICK")
	{
		if (nick[1].size() > 9 || !std::isalpha(nick[1][0]))
		{
			std::cout << "ERR_ERRONEUSNICKNAME" << std::endl;
			return;
		}
		std::string specialCharacters = "-\\[]^{}";
		for (int i = 1; nick[1][i]; i++)
		{
			if (!std::isdigit(nick[1][i]) && !std::isalpha(nick[1][i]) && specialCharacters.find(nick[1][i]) == std::string::npos)
			{
				std::cout << "ERR_ERRONEUSNICKNAME" << std::endl;
				return;
			}
		}
		this->origin_nickname = nick[1];
		// std::transform(nick[1].begin(), nick[1].end(), ::toupper);
		this->nickname = nick[1];
		return;
	}
	std::cout << "ERR_NONICKNAMEGIVEN" << std::endl;
}

void	Client::User(std::string& command)
{
	std::vector<std::string> tokens;
	std::istringstream cmd(command);
	std::string part1;
	std::string part2;
	std::string tmp;

	std::getline(cmd, part1, ':');
	std::getline(cmd, part2);
	std::istringstream stream(part1);
	while (std::getline(stream, tmp, ' '))
		tokens.push_back(tmp);
	tokens.push_back(part2);
	if (tokens.size() != 5)
	{
		std::cout << "ERR_WRONGPARAMS" << std::endl;
		return;
	}
	this->username = tokens[1];
	this->is_registered = true;
	//need to check if the username is unique in the server.
}

int main()
{
	std::string tmp ;
	Client c(1);
	c.authentication();
	return (0);
		
}