/*
 * SPDX-FileCopyrightText: 2025-2026 Juergen Winkler <MobaLedLib@gmx.at>
 * SPDX-License-Identifier: LGPL-2.1-or-later
*/

#pragma once
#include "ServoController.h"

class StatefulServoController : public ServoController
{
public:
    StatefulServoController(uint8_t pin, uint16_t min, uint16_t max, int speed, uint saveTimeout, uint disableTimeout)
        : ServoController(pin, min, max, speed)
    {
        lastMoveTime = 0;
        lastLedValue = 0;
        this->saveTimeout = saveTimeout;
        this->disableTimeout = disableTimeout;
    }
    bool shouldSavePosition()
    {
        if (!isReady()) return false;
        if (isMoving())
        {
            lastMoveTime = millis();
            return false;
        }
        if (lastMoveTime == 0) return false;
        return (millis() - lastMoveTime) >= saveTimeout;
    }
    bool shouldAutomaticallyDisable()
    {
        if (!isReady() || isMoving() || lastMoveTime == 0) return false;
        return (millis() - lastMoveTime) >= disableTimeout;                           // change from 100 to 250, older slow servos need more time to reach the target position
    }

    void resetSavePosition()
    {
        lastMoveTime = 0;
    }
public: // todo should be protected
    uint8_t buttonChanged;
    uint8_t lastLedValue;
protected:
    unsigned long lastMoveTime;
    uint saveTimeout;
    uint disableTimeout;
};