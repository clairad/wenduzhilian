#include <iostream>
#include "menudefine.h"
#include "sql.h"
using namespace std;



int main()
{
	int ret;
	while (1)
	{
		switch (pageMenu())
		{
		case SIGNIN:
			//输入用户名
			ret = checkUsername();
			if (ret != ret_ok)
			{
				//错误处理
			}
			//输入密码
			ret = checkPassword();
			if (ret != ret_ok)
			{
				//错误处理
			}

			break;
		case SIGNUP:
			break;
		case SET:
			switch(pageSet())
			{
			case 0:

				break;
			case 1:
				break;
			}
			break;
		case EXIT:
			return 0;
		}
	}
	return 0;
}