#include <font.h>
 
struct Font
{
    const Bitmap* const* glyphs;
};
 
 
// Default character for unknown glyphs
const uint8_t char_unknown[] PROGMEM ={ 0xFC, 0x63, 0x18, 0xC7, 0xE0 };
const Bitmap defaultBitmap PROGMEM = {5, 7, char_unknown};
 
// Character '!' (ASCII 33)
const uint8_t char_33[] PROGMEM ={ 0x21, 0x08, 0x42, 0x00, 0x80 };
const Bitmap bmp_33 PROGMEM = {5, 7, char_33};
 
// Character '%' (ASCII 37)
const uint8_t char_37[] PROGMEM ={ 0xC6, 0x44, 0x44, 0x4C, 0x60 };
const Bitmap bmp_37 PROGMEM = {5, 7, char_37};
 
// Character '(' (ASCII 40)
const uint8_t char_40[] PROGMEM ={ 0x11, 0x10, 0x84, 0x10, 0x40 };
const Bitmap bmp_40 PROGMEM = {5, 7, char_40};
 
// Character ')' (ASCII 41)
const uint8_t char_41[] PROGMEM ={ 0x41, 0x04, 0x21, 0x11, 0x00 };
const Bitmap bmp_41 PROGMEM = {5, 7, char_41};
 
// Character ',' (ASCII 44)
const uint8_t char_44[] PROGMEM ={ 0x00, 0x00, 0x03, 0x19, 0x00 };
const Bitmap bmp_44 PROGMEM = {5, 7, char_44};
 
// Character '-' (ASCII 45)
const uint8_t char_45[] PROGMEM ={ 0x00, 0x01, 0xF0, 0x00, 0x00 };
const Bitmap bmp_45 PROGMEM = {5, 7, char_45};
 
// Character '.' (ASCII 46)
const uint8_t char_46[] PROGMEM ={ 0x00, 0x00, 0x00, 0x18, 0xC0 };
const Bitmap bmp_46 PROGMEM = {5, 7, char_46};
 
// Character '0' (ASCII 48)
const uint8_t char_48[] PROGMEM ={ 0x74, 0x67, 0x5C, 0xC5, 0xC0 };
const Bitmap bmp_48 PROGMEM = {5, 7, char_48};
 
// Character '1' (ASCII 49)
const uint8_t char_49[] PROGMEM ={ 0x23, 0x08, 0x42, 0x11, 0xC0 };
const Bitmap bmp_49 PROGMEM = {5, 7, char_49};
 
// Character '2' (ASCII 50)
const uint8_t char_50[] PROGMEM ={ 0x74, 0x42, 0x22, 0x23, 0xE0 };
const Bitmap bmp_50 PROGMEM = {5, 7, char_50};
 
// Character '3' (ASCII 51)
const uint8_t char_51[] PROGMEM ={ 0x74, 0x42, 0xE0, 0xC5, 0xC0 };
const Bitmap bmp_51 PROGMEM = {5, 7, char_51};
 
// Character '4' (ASCII 52)
const uint8_t char_52[] PROGMEM ={ 0x11, 0x95, 0x2F, 0x88, 0x40 };
const Bitmap bmp_52 PROGMEM = {5, 7, char_52};
 
// Character '5' (ASCII 53)
const uint8_t char_53[] PROGMEM ={ 0xFC, 0x3C, 0x10, 0xC5, 0xC0 };
const Bitmap bmp_53 PROGMEM = {5, 7, char_53};
 
// Character '6' (ASCII 54)
const uint8_t char_54[] PROGMEM ={ 0x74, 0x21, 0xE8, 0xC5, 0xC0 };
const Bitmap bmp_54 PROGMEM = {5, 7, char_54};
 
// Character '7' (ASCII 55)
const uint8_t char_55[] PROGMEM ={ 0xF8, 0x44, 0x44, 0x21, 0x00 };
const Bitmap bmp_55 PROGMEM = {5, 7, char_55};
 
// Character '8' (ASCII 56)
const uint8_t char_56[] PROGMEM ={ 0x74, 0x62, 0xE8, 0xC5, 0xC0 };
const Bitmap bmp_56 PROGMEM = {5, 7, char_56};
 
// Character '9' (ASCII 57)
const uint8_t char_57[] PROGMEM ={ 0x74, 0x62, 0xF0, 0x85, 0xC0 };
const Bitmap bmp_57 PROGMEM = {5, 7, char_57};
 
// Character 'A' (ASCII 65)
const uint8_t char_65[] PROGMEM ={ 0x74, 0x63, 0xF8, 0xC6, 0x20 };
const Bitmap bmp_65 PROGMEM = {5, 7, char_65};
 
// Character 'B' (ASCII 66)
const uint8_t char_66[] PROGMEM ={ 0xF4, 0x63, 0xE8, 0xC7, 0xC0 };
const Bitmap bmp_66 PROGMEM = {5, 7, char_66};
 
// Character 'C' (ASCII 67)
const uint8_t char_67[] PROGMEM ={ 0x74, 0x61, 0x08, 0x45, 0xC0 };
const Bitmap bmp_67 PROGMEM = {5, 7, char_67};
 
// Character 'D' (ASCII 68)
const uint8_t char_68[] PROGMEM ={ 0xF4, 0x63, 0x18, 0xC7, 0xC0 };
const Bitmap bmp_68 PROGMEM = {5, 7, char_68};
 
// Character 'E' (ASCII 69)
const uint8_t char_69[] PROGMEM ={ 0xFC, 0x21, 0xE8, 0x43, 0xE0 };
const Bitmap bmp_69 PROGMEM = {5, 7, char_69};
 
// Character 'F' (ASCII 70)
const uint8_t char_70[] PROGMEM ={ 0xFC, 0x21, 0xE8, 0x42, 0x00 };
const Bitmap bmp_70 PROGMEM = {5, 7, char_70};
 
// Character 'G' (ASCII 71)
const uint8_t char_71[] PROGMEM ={ 0x74, 0x61, 0x78, 0xC5, 0xC0 };
const Bitmap bmp_71 PROGMEM = {5, 7, char_71};
 
// Character 'H' (ASCII 72)
const uint8_t char_72[] PROGMEM ={ 0x8C, 0x63, 0xF8, 0xC6, 0x20 };
const Bitmap bmp_72 PROGMEM = {5, 7, char_72};
 
// Character 'I' (ASCII 73)
const uint8_t char_73[] PROGMEM ={ 0x71, 0x08, 0x42, 0x11, 0xC0 };
const Bitmap bmp_73 PROGMEM = {5, 7, char_73};
 
// Character 'J' (ASCII 74)
const uint8_t char_74[] PROGMEM ={ 0x38, 0x42, 0x10, 0xC5, 0xC0 };
const Bitmap bmp_74 PROGMEM = {5, 7, char_74};
 
// Character 'K' (ASCII 75)
const uint8_t char_75[] PROGMEM ={ 0x8C, 0xA9, 0x8A, 0x4A, 0x20 };
const Bitmap bmp_75 PROGMEM = {5, 7, char_75};
 
// Character 'L' (ASCII 76)
const uint8_t char_76[] PROGMEM ={ 0x84, 0x21, 0x08, 0x43, 0xE0 };
const Bitmap bmp_76 PROGMEM = {5, 7, char_76};
 
// Character 'M' (ASCII 77)
const uint8_t char_77[] PROGMEM ={ 0x8E, 0xEB, 0x18, 0xC6, 0x20 };
const Bitmap bmp_77 PROGMEM = {5, 7, char_77};
 
// Character 'N' (ASCII 78)
const uint8_t char_78[] PROGMEM ={ 0x8E, 0x6B, 0x59, 0xC6, 0x20 };
const Bitmap bmp_78 PROGMEM = {5, 7, char_78};
 
// Character 'O' (ASCII 79)
const uint8_t char_79[] PROGMEM ={ 0x74, 0x63, 0x18, 0xC5, 0xC0 };
const Bitmap bmp_79 PROGMEM = {5, 7, char_79};
 
// Character 'P' (ASCII 80)
const uint8_t char_80[] PROGMEM ={ 0xF4, 0x63, 0xE8, 0x42, 0x00 };
const Bitmap bmp_80 PROGMEM = {5, 7, char_80};
 
// Character 'Q' (ASCII 81)
const uint8_t char_81[] PROGMEM ={ 0x74, 0x63, 0x1A, 0xC9, 0xA0 };
const Bitmap bmp_81 PROGMEM = {5, 7, char_81};
 
// Character 'R' (ASCII 82)
const uint8_t char_82[] PROGMEM ={ 0xF4, 0x63, 0xEA, 0x4A, 0x20 };
const Bitmap bmp_82 PROGMEM = {5, 7, char_82};
 
// Character 'S' (ASCII 83)
const uint8_t char_83[] PROGMEM ={ 0x7C, 0x20, 0xE0, 0x87, 0xC0 };
const Bitmap bmp_83 PROGMEM = {5, 7, char_83};
 
// Character 'T' (ASCII 84)
const uint8_t char_84[] PROGMEM ={ 0xF9, 0x08, 0x42, 0x10, 0x80 };
const Bitmap bmp_84 PROGMEM = {5, 7, char_84};
 
// Character 'U' (ASCII 85)
const uint8_t char_85[] PROGMEM ={ 0x8C, 0x63, 0x18, 0xC5, 0xC0 };
const Bitmap bmp_85 PROGMEM = {5, 7, char_85};
 
// Character 'V' (ASCII 86)
const uint8_t char_86[] PROGMEM ={ 0x8C, 0x63, 0x18, 0xA8, 0x80 };
const Bitmap bmp_86 PROGMEM = {5, 7, char_86};
 
// Character 'W' (ASCII 87)
const uint8_t char_87[] PROGMEM ={ 0x8C, 0x63, 0x5A, 0xD5, 0x40 };
const Bitmap bmp_87 PROGMEM = {5, 7, char_87};
 
// Character 'X' (ASCII 88)
const uint8_t char_88[] PROGMEM ={ 0x8C, 0x54, 0x45, 0x46, 0x20 };
const Bitmap bmp_88 PROGMEM = {5, 7, char_88};
 
// Character 'Y' (ASCII 89)
const uint8_t char_89[] PROGMEM ={ 0x8C, 0x54, 0x42, 0x10, 0x80 };
const Bitmap bmp_89 PROGMEM = {5, 7, char_89};
 
// Character 'Z' (ASCII 90)
const uint8_t char_90[] PROGMEM ={ 0xF8, 0x44, 0x44, 0x43, 0xE0 };
const Bitmap bmp_90 PROGMEM = {5, 7, char_90};
 
// Character 'a' (ASCII 97)
const uint8_t char_97[] PROGMEM ={ 0x00, 0x1E, 0x17, 0xC5, 0xE0 };
const Bitmap bmp_97 PROGMEM = {5, 7, char_97};
 
// Character 'b' (ASCII 98)
const uint8_t char_98[] PROGMEM ={ 0x84, 0x3D, 0x18, 0xC7, 0xC0 };
const Bitmap bmp_98 PROGMEM = {5, 7, char_98};
 
// Character 'c' (ASCII 99)
const uint8_t char_99[] PROGMEM ={ 0x00, 0x1D, 0x08, 0x41, 0xC0 };
const Bitmap bmp_99 PROGMEM = {5, 7, char_99};
 
// Character 'd' (ASCII 100)
const uint8_t char_100[] PROGMEM ={ 0x08, 0x5F, 0x18, 0xC5, 0xE0 };
const Bitmap bmp_100 PROGMEM = {5, 7, char_100};
 
// Character 'e' (ASCII 101)
const uint8_t char_101[] PROGMEM ={ 0x00, 0x1D, 0x1F, 0xC1, 0xC0 };
const Bitmap bmp_101 PROGMEM = {5, 7, char_101};
 
// Character 'f' (ASCII 102)
const uint8_t char_102[] PROGMEM ={ 0x32, 0x11, 0xE4, 0x21, 0x00 };
const Bitmap bmp_102 PROGMEM = {5, 7, char_102};
 
// Character 'g' (ASCII 103)
const uint8_t char_103[] PROGMEM ={ 0x03, 0xE3, 0x17, 0x85, 0xC0 };
const Bitmap bmp_103 PROGMEM = {5, 7, char_103};
 
// Character 'h' (ASCII 104)
const uint8_t char_104[] PROGMEM ={ 0x84, 0x3D, 0x18, 0xC6, 0x20 };
const Bitmap bmp_104 PROGMEM = {5, 7, char_104};
 
// Character 'i' (ASCII 105)
const uint8_t char_105[] PROGMEM ={ 0x20, 0x18, 0x42, 0x11, 0xC0 };
const Bitmap bmp_105 PROGMEM = {5, 7, char_105};
 
// Character 'j' (ASCII 106)
const uint8_t char_106[] PROGMEM ={ 0x10, 0x0C, 0x21, 0x49, 0x80 };
const Bitmap bmp_106 PROGMEM = {5, 7, char_106};
 
// Character 'k' (ASCII 107)
const uint8_t char_107[] PROGMEM ={ 0x84, 0x25, 0x4C, 0x52, 0x40 };
const Bitmap bmp_107 PROGMEM = {5, 7, char_107};
 
// Character 'l' (ASCII 108)
const uint8_t char_108[] PROGMEM ={ 0x61, 0x08, 0x42, 0x11, 0xC0 };
const Bitmap bmp_108 PROGMEM = {5, 7, char_108};
 
// Character 'm' (ASCII 109)
const uint8_t char_109[] PROGMEM ={ 0x00, 0x35, 0x5A, 0xC6, 0x20 };
const Bitmap bmp_109 PROGMEM = {5, 7, char_109};
 
// Character 'n' (ASCII 110)
const uint8_t char_110[] PROGMEM ={ 0x00, 0x3D, 0x18, 0xC6, 0x20 };
const Bitmap bmp_110 PROGMEM = {5, 7, char_110};
 
// Character 'o' (ASCII 111)
const uint8_t char_111[] PROGMEM ={ 0x00, 0x1D, 0x18, 0xC5, 0xC0 };
const Bitmap bmp_111 PROGMEM = {5, 7, char_111};
 
// Character 'p' (ASCII 112)
const uint8_t char_112[] PROGMEM ={ 0x07, 0xA3, 0x1F, 0x42, 0x00 };
const Bitmap bmp_112 PROGMEM = {5, 7, char_112};
 
// Character 'q' (ASCII 113)
const uint8_t char_113[] PROGMEM ={ 0x03, 0xE3, 0x17, 0x84, 0x20 };
const Bitmap bmp_113 PROGMEM = {5, 7, char_113};
 
// Character 'r' (ASCII 114)
const uint8_t char_114[] PROGMEM ={ 0x00, 0x2D, 0x88, 0x42, 0x00 };
const Bitmap bmp_114 PROGMEM = {5, 7, char_114};
 
// Character 's' (ASCII 115)
const uint8_t char_115[] PROGMEM ={ 0x00, 0x1F, 0x07, 0x07, 0xC0 };
const Bitmap bmp_115 PROGMEM = {5, 7, char_115};
 
// Character 't' (ASCII 116)
const uint8_t char_116[] PROGMEM ={ 0x42, 0x3C, 0x84, 0x20, 0xC0 };
const Bitmap bmp_116 PROGMEM = {5, 7, char_116};
 
// Character 'u' (ASCII 117)
const uint8_t char_117[] PROGMEM ={ 0x00, 0x23, 0x18, 0xC5, 0xE0 };
const Bitmap bmp_117 PROGMEM = {5, 7, char_117};
 
// Character 'v' (ASCII 118)
const uint8_t char_118[] PROGMEM ={ 0x00, 0x23, 0x18, 0xA8, 0x80 };
const Bitmap bmp_118 PROGMEM = {5, 7, char_118};
 
// Character 'w' (ASCII 119)
const uint8_t char_119[] PROGMEM ={ 0x00, 0x23, 0x1A, 0xD5, 0x40 };
const Bitmap bmp_119 PROGMEM = {5, 7, char_119};
 
// Character 'x' (ASCII 120)
const uint8_t char_120[] PROGMEM ={ 0x00, 0x22, 0xA2, 0x2A, 0x20 };
const Bitmap bmp_120 PROGMEM = {5, 7, char_120};
 
// Character 'y' (ASCII 121)
const uint8_t char_121[] PROGMEM ={ 0x04, 0x63, 0x17, 0x85, 0xC0 };
const Bitmap bmp_121 PROGMEM = {5, 7, char_121};
 
// Character 'z' (ASCII 122)
const uint8_t char_122[] PROGMEM ={ 0x00, 0x3E, 0x22, 0x23, 0xE0 };
const Bitmap bmp_122 PROGMEM = {5, 7, char_122};
 
 
static const Bitmap* fontGlyphs[128] = {
    nullptr, // 0
    nullptr, // 1
    nullptr, // 2
    nullptr, // 3
    nullptr, // 4
    nullptr, // 5
    nullptr, // 6
    nullptr, // 7
    nullptr, // 8
    nullptr, // 9
    nullptr, // 10
    nullptr, // 11
    nullptr, // 12
    nullptr, // 13
    nullptr, // 14
    nullptr, // 15
    nullptr, // 16
    nullptr, // 17
    nullptr, // 18
    nullptr, // 19
    nullptr, // 20
    nullptr, // 21
    nullptr, // 22
    nullptr, // 23
    nullptr, // 24
    nullptr, // 25
    nullptr, // 26
    nullptr, // 27
    nullptr, // 28
    nullptr, // 29
    nullptr, // 30
    nullptr, // 31
    &bmp_33, // 33
    nullptr, // 34
    nullptr, // 35
    &bmp_37, // 37
    nullptr, // 38
    &bmp_40, // 40
    &bmp_41, // 41
    nullptr, // 42
    nullptr, // 43
    &bmp_44, // 44
    &bmp_45, // 45
    &bmp_46, // 46
    nullptr, // 47
    &bmp_48, // 48
    &bmp_49, // 49
    &bmp_50, // 50
    &bmp_51, // 51
    &bmp_52, // 52
    &bmp_53, // 53
    &bmp_54, // 54
    &bmp_55, // 55
    &bmp_56, // 56
    &bmp_57, // 57
    nullptr, // 58
    nullptr, // 59
    nullptr, // 60
    nullptr, // 61
    nullptr, // 62
    nullptr, // 63
    nullptr, // 64
    &bmp_65, // 65
    &bmp_66, // 66
    &bmp_67, // 67
    &bmp_68, // 68
    &bmp_69, // 69
    &bmp_70, // 70
    &bmp_71, // 71
    &bmp_72, // 72
    &bmp_73, // 73
    &bmp_74, // 74
    &bmp_75, // 75
    &bmp_76, // 76
    &bmp_77, // 77
    &bmp_78, // 78
    &bmp_79, // 79
    &bmp_80, // 80
    &bmp_81, // 81
    &bmp_82, // 82
    &bmp_83, // 83
    &bmp_84, // 84
    &bmp_85, // 85
    &bmp_86, // 86
    &bmp_87, // 87
    &bmp_88, // 88
    &bmp_89, // 89
    &bmp_90, // 90
    nullptr, // 91
    nullptr, // 92
    nullptr, // 93
    nullptr, // 94
    nullptr, // 95
    nullptr, // 96
    &bmp_97, // 97
    &bmp_98, // 98
    &bmp_99, // 99
    &bmp_100, // 100
    &bmp_101, // 101
    &bmp_102, // 102
    &bmp_103, // 103
    &bmp_104, // 104
    &bmp_105, // 105
    &bmp_106, // 106
    &bmp_107, // 107
    &bmp_108, // 108
    &bmp_109, // 109
    &bmp_110, // 110
    &bmp_111, // 111
    &bmp_112, // 112
    &bmp_113, // 113
    &bmp_114, // 114
    &bmp_115, // 115
    &bmp_116, // 116
    &bmp_117, // 117
    &bmp_118, // 118
    &bmp_119, // 119
    &bmp_120, // 120
    &bmp_121, // 121
    &bmp_122, // 122
    nullptr, // 123
    nullptr, // 124
    nullptr, // 125
    nullptr, // 126
    nullptr, // 127
};

const Font font = { fontGlyphs };

const Bitmap* getBitmap(char c)
{
    uint8_t index = (uint8_t)c;
 
    if (index >= 128)
    {
        return &defaultBitmap;
    }
 
    const Bitmap* bmp = font.glyphs[index];
 
    return bmp != nullptr ? bmp : &defaultBitmap;
}