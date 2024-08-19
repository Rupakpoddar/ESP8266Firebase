/*
MIT License
Copyright (c) 2020 Rupak Poddar

*/

#pragma once

#if defined(ESP8266)
    #include "ESP8266Firebase.hpp"
#else
    #error "Please select an ESP8266 board for this sketch."
#endif
