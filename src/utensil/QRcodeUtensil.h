#ifndef _QRcodeUtensil_H_
#define _QRcodeUtensil_H_

class _QRcodeUtensil;

#ifndef __QRCODE_H_
#include <QRCode.h>
#endif

class _QRcodeUtensil
{
private:
    QRCode qrcode;
    uint8_t qrcodeData[256];

public:
    _QRcodeUtensil();
    void begin();
    void draw(const char *);
};

extern _QRcodeUtensil QRcodeUtensil;

#endif