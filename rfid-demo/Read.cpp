#include <iostream>
#include <sstream>
#include <iomanip> // for std::setw and std::setfill
#include "MFRC522.h"

#ifdef WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

void delay(int ms){
#ifdef WIN32
    Sleep(ms);
#else
    usleep(ms * 1000);
#endif
}

int main() {
    MFRC522 mfrc;

    mfrc.PCD_Init();

    while (1) {
        // Look for a card
        if (!mfrc.PICC_IsNewCardPresent())
            continue;

        if (!mfrc.PICC_ReadCardSerial())
            continue;

        // Use stringstream to format UID
        std::stringstream ss;
        for (byte i = 0; i < mfrc.uid.size; ++i) {
            if (i > 0)
                ss << " "; // Add a space between bytes
            ss << std::hex << std::uppercase << std::setw(2) << std::setfill('0') << static_cast<int>(mfrc.uid.uidByte[i]);
        }

        // Convert stringstream to string and print
        std::string uidStr = ss.str();
        std::cout << "UID: " << uidStr << std::endl;

        delay(1000);
    }
    return 0;
}

