#pragma once

#define ret_ok 1
#define ARROW_UP    0xE048
#define ARROW_DOWN  0xE050
#define ARROW_LEFT  0xE04B
#define ARROW_RIGHT 0xE04D
int getKeyBoard();
int pageMenu();

enum {
	SIGNIN,
	SIGNUP,
	SET,
	EXIT
};
#define MENUPAGENUM 4
void printSignIn();
void printSignUp();
void printSet();
void printExit();
int pageMenu();

#define SETPAGENUM 2
void printVolume();
void printColor();
int pageSet();