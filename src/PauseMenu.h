#ifndef PAUSEMENU
#define PAUSEMENU

#include <vector>
#include <functional>

class PauseMenu {

    public:
        static void Open(int i);
        static void Close();

        static void Update();

    private:
        struct option {
            option(int sprite, float yoffset, std::function<void(void)> click, bool first, bool confirm = false);
            void isOn(); void isNotOn(); void click(); void del();
            int anm;
            bool needsConfirm;
            std::function<void(void)> onClick;
        };
        static int anmback;
        static int anmtitle;
        static int optionOn;
        static bool opened;
        static bool firstupdate;
        static std::vector<option> options;
        struct conf {
            void Open(std::function<void(void)> confirmfunc);
            std::function<void(void)> func = nullptr;
            int anmtitle = -1;
            int anmyes = -1;
            int anmno = -1;
            bool confirm = true;
            bool open = false;
            void Chg();
            void Confirm();
        };
        static conf Confirm;

};

#endif
