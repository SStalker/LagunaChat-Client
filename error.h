#ifndef ERROR_H
#define ERROR_H

class Error
{

public:
    Error();
    void registrationFailed();
    void loginFailed();
    void sendFileFailedOffline();
};

#endif // ERROR_H
