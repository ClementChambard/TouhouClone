#ifndef TEXTANM
#define TEXTANM

#include <AnmManager.h>

class textAnm {
    public:
        textAnm(int digit, int space, void(*anm)(AnimScript*),int offset = 0, bool showAll = false);
        ~textAnm();
        void set_number(int num);
        void reset();
        void interrupt(int i);
    private:
        int* anms;
        int digit;
        int offset;
        int space;
        int num;
        bool showAll;
};

#include <math/math.h>
#include <NSEngine.h>
class AsciiElement {
    public:

        void Init(int l, int f, std::string t) { destroy(); font = f; active = 1; layerID = l; set_text(t); }

        void Draw();

        bool isActive() { return active; }

        void set_text(std::string t);
        void set_font(int f) { font = f; }
        void set_color(uint8_t r, uint8_t g, uint8_t b) { col = glm::vec<3, uint8_t>(r, g, b); }
        void color_time(uint16_t t, uint8_t m, uint8_t r, uint8_t g, uint8_t b) { ITP_ (&col, col, glm::vec<3, uint8_t>(r, g, b), m, t, false); }
        void set_pos(float x, float y) { pos = glm::vec2(x, y); }
        void pos_time(uint16_t t, uint8_t m, float x, float y) { ITP_ (&pos, pos, glm::vec2(x, y), m, t, false); }
        void set_alpha(uint8_t a) { this->a = a; }
        void alpha_time(uint16_t t, uint8_t m, uint8_t a) { ITP_ (&this->a, this->a, a, m, t, false); }
        void set_scale(float x, float y) { scale = glm::vec2(x, y); }
        void scale_time(uint16_t t, uint8_t m, float x, float y) { ITP_ (&scale, scale, glm::vec2(x, y), m, t, false); }
        void set_align(NSEngine::font_align h, NSEngine::font_align v) { halign = h; valign = v; }

        void destroy() {pos = glm::vec2();scale = glm::vec2(1.f, 1.f);col = glm::vec<3, uint8_t>(255, 255, 255);a = 255;layerID=0;active=0;halign=NSEngine::fa_left;valign=NSEngine::fa_top;text="";}
    private:
        std::string text = "";
        int font = 0;
        uint8_t halign = NSEngine::fa_left;
        uint8_t valign = NSEngine::fa_top;
        uint8_t layerID = 0;
        std::vector<int> anmids;
        bool active = 0;
        glm::vec2 pos;
        glm::vec2 scale = glm::vec2(1.f, 1.f);
        glm::vec<3, uint8_t> col;
        uint8_t a;
};

class AsciiManager {
    public:
        static void Init();
        static void Cleanup() { delete[] asciipool; }
        static AsciiElement* newTxt(int l, int f, std::string t);
        static void Update() {}
        static void Draw() { for (int i = 0; i < 100; i++) asciipool[i].Draw(); }
    private:
        static AsciiElement* asciipool;
        static int currentpos;
};

#endif
