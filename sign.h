#ifndef SIGN_H
#define SIGN_H

class QString;
class QByteArray;
class sign
{
public:
    sign();

};
QString hmacSha1(QByteArray key,QByteArray baseString);

#endif // SIGN_H
