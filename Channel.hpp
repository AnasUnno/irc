#include <vector>
#include <string>
class Channel {
public:
	Channel(std::string& name)
		: name(name), inviteOnly(false), topicRestricted(false), userLimit(10) {}
	void	Channel::parseMode(std::string& modeLine);

	std::string name;                           // Name of the channel
	bool inviteOnly;                           // Invite-only mode
	bool topicRestricted;                     // Topic restricted to channel operators
	std::string password;					 // Channel password (if any)
	int userLimit;                          // User limit (if any)
	std::vecotr<std::string> operators;    // Set of channel operators
	std::vector<std::string> users;       // Set of users in the channel
	std::vector<std::string> bannedUsers;// Set of banned users
};