/*

  oscsend-vst - An audio plugin that speaks OSC.
  Copyright (C) 2020 Patric Schmitz

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#pragma once

#include "ControlElement.h"

class ControlElementUI :
    public ControlElement,
    public Component,
    public Value::Listener
{
public:
    ControlElementUI
    (const CreateInfo & info,
        OSCSender & oscSender);

    virtual int getNumberOfRows() const = 0;
    void resized() override;

    void registerSendValue();

    void valueChanged(Value & value) override;

    void send() override;

protected:

    virtual Value & getSpecificSendValue() = 0;

private:

    std::unique_ptr<TextButton> buttonMute;
    Value sendValue;
};
using ControlElementUIUniq = std::unique_ptr<ControlElementUI>;