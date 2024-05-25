#pragma once

struct UserData{
	int userID;
	char m_userName[32];
	char m_password[32];
	char m_phoneNum[12];
};

int sign_in();
int sign_up();
