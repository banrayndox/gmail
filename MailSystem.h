#pragma once
#include <string>
using namespace std;
class MailSystem{
public:
 void sendEmail(const std::string& sender);
 void showInbox(const std::string& user);
 void deleteEmail(const std::string& user);
};
