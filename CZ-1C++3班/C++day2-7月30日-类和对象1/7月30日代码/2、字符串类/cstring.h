#pragma once
namespace Cpang {

	class string {
		char* val;
		int size;
	public:
		string();
		string(const char* str);
		string(string& o);
		string(char ch, int n);
		string(string& o, int start, int end);
		~string();

		string& operator=(string o);
		string operator+(const string& o) const;

		void printString();
	};



};