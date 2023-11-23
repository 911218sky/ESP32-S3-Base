#include <Arduino.h>
#include <QRCode.h>
#include "./../Settings.h"
#include "QRcodeUtensil.h"

_QRcodeUtensil::_QRcodeUtensil()
{
    QRCode qrcode;
    uint8_t qrcodeData[qrcode_getBufferSize(2)];
}

void _QRcodeUtensil::begin()
{
}

void _QRcodeUtensil::draw(const char *data)
{
    qrcode_initText(&qrcode, qrcodeData, 2, ECC_LOW, data);
    // 調整 QR code 的位置和大小
    int qrCodeSize = qrcode.size * 2;               // 縮小 QR code 大小的倍數
    int xOffset = (SCREEN_WIDTH - qrCodeSize) / 2;  // 計算 x 方向的偏移量
    int yOffset = (SCREEN_HEIGHT - qrCodeSize) / 2; // 計算 y 方向的偏移量
    for (uint8_t y = 0; y < qrcode.size; y++)
    {
        for (uint8_t x = 0; x < qrcode.size; x++)
        {
            if (qrcode_getModule(&qrcode, x, y))
            {
                display.fillRect(x * 2 + xOffset, y * 2 + yOffset, 2, 2, SSD1306_WHITE);
            }
        }
    }
}

_QRcodeUtensil QRcodeUtensil;
