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
			//�����û���
			ret = checkUsername();
			if (ret != ret_ok)
			{
				//������
			}
			//��������
			ret = checkPassword();
			if (ret != ret_ok)
			{
				//������
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