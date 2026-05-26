#pragma once
#include "../../CWSDK/cwsdk.h"

namespace cube {
    class SaveData {
    public:
        int race;
        char gender;
        char padding[3];
        int face;
        int haircut;
        ByteRGBA hair_color;
    };
}
