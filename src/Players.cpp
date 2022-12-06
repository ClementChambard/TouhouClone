#include "Players.h"

PlayerData Pl00 = {

    []()
    {
        return "assets/TH15pl00.sht";
    },

    []()
    {
        return new THAnim(pl00Center,pl00ToLeft,pl00FromLeft,pl00ToRight,pl00FromRight,pl00Dead);
    },

    [](bool fullpower)
    {
        return fullpower?pl00OptionFP:pl00Option;
    },

    [](int i)
    {
        static std::vector<animscript_t> scripts = {
            pl00Bullet0,
            pl00Bullet1,
            pl00Bullet1,
            pl00Bullet2
        };
        return scripts[i];
    }

};

PlayerData Pl01 = {

    []()
    {
        return "assets/TH17pl01.sht";
    },

    []()
    {
        return new THAnim(pl01Center,pl01ToLeft,pl01FromLeft,pl01ToRight,pl01FromRight,pl01Dead);
    },

    [](bool fullpower)
    {
        return fullpower?pl01OptionFP:pl01Option;
    },

    [](int i)
    {
        static std::vector<animscript_t> scripts = {
            pl01Bullet0,
            pl01Bullet1_1,
            pl01Bullet2_2,
            pl01Bullet2_2,
            pl01Bullet2_2,
            pl01Bullet2_2,
            pl01Bullet2_1
        };
        return scripts[i];
    }

};

PlayerData Pl02 = {

    []()
    {
        return "assets/TH15pl00.sht";
    },

    []()
    {
        return new THAnim(pl00Center,pl00ToLeft,pl00FromLeft,pl00ToRight,pl00FromRight,pl00Dead);
    },

    [](bool fullpower)
    {
        return fullpower?pl00OptionFP:pl00Option;
    },

    [](int i)
    {
        static std::vector<animscript_t> scripts = {
            pl00Bullet0,
            pl00Bullet1,
            pl00Bullet1,
            pl00Bullet2
        };
        return scripts[i];
    }

};

PlayerData Pl03 = {

    []()
    {
        return "assets/TH15pl03.sht";
    },

    []()
    {
        return new THAnim(pl03Center,pl03ToLeft,pl03FromLeft,pl03ToRight,pl03FromRight,pl03Dead);
    },

    [](bool fullpower)
    {
        return fullpower?pl03OptionFP:pl03Option;
    },

    [](int i)
    {
        static std::vector<animscript_t> scripts = {
            pl03Bullet0,
            pl03Bullet1,
            pl03Bullet2,
            pl03Bullet2
        };
        return scripts[i];
    }

};
