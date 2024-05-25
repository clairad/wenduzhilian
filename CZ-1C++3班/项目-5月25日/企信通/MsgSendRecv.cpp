#include "MSNMessage.h"

#ifdef CLIENT

int MSNSendMsg();
int MSNRecvMsg();

#else

int MSNSendMsg();
int MSNRecvMsg();
int MSNSendMsgMulti();

#endif