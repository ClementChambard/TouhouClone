#include "PlayerHUD.h"
#include <NSEngine.h>
#include <math/math.h>
#include <sstream>

int PlayerHUD::etama = 0;
int PlayerHUD::laser = 0;
int PlayerHUD::anmscr = 0;
int PlayerHUD::item = 0;
int PlayerHUD::itemc = 0;

long PlayerHUD::score = 0;
long PlayerHUD::hiscore = 0;
int PlayerHUD::pointValue = 10000;
int PlayerHUD::graze = 0;
int PlayerHUD::power = 0;
int PlayerHUD::steppower = 20;
int PlayerHUD::maxpower = 80;

template <typename T>
std::string to_string_with_precision(const T a_value, const int n = 6)
{
    std::ostringstream out;
    out.precision(n);
    out << std::fixed << a_value;
    return out.str();
}

#include "textAnm.h"
#include "ECLManager.h"
PlayerHUD::PlayerHUD(long hiscore, int maxpower, int steppower) 
{ 
    PlayerHUD::hiscore = hiscore; this->maxpower = maxpower; this->steppower = steppower; 
    AnmManager::newAnim(frontAll);
    int anm = AnmManager::newAnim(frontDifficulty1,-1,1); AnmManager::anim(anm)->offset_sprite(ECLManager::difficulty);
    anm = AnmManager::newAnim(frontDifficulty2,-1,1); AnmManager::anim(anm)->offset_sprite(ECLManager::difficulty);
    for (int i = 0; i < 8; i++)
    {
        anmh[i] = AnmManager::newAnim(frontHeart);
        AnmManager::UpdateChild(anmh[i],i*13,0,0,0,0,0,1,1,1,i<2?2:0);
    }
    for (int i = 0; i < 8; i++)
    {
        anms[i] = AnmManager::newAnim(frontSpell);
        AnmManager::UpdateChild(anms[i],i*13,0,0,0,0,0,1,1,1,i<2?2:0);
    }
}
PlayerHUD::~PlayerHUD() 
{
}

void stringScoreCommas(std::string& s)
{
    std::string s2 = "";
    for (int i = 0; i < s.length(); i++)
    {
        s2 = s[s.length()-1-i] + s2;
        if (i%3==2 && i != s.length()-1) s2 = ',' + s2;
    }
    s = s2;
}

void ScoreText()
{
    static AsciiElement* TEXT = nullptr;
    static AsciiElement* TEXTH = nullptr;
    static long score = 0;
    if (TEXT == nullptr)
    {
        TEXT = AsciiManager::newTxt(NSEngine::engineData::debugLayer,gameassets::fnt_score2,"");
        TEXTH = AsciiManager::newTxt(NSEngine::engineData::debugLayer,gameassets::fnt_score2,"");
        TEXT->set_align(NSEngine::fa_right,NSEngine::fa_center);
        TEXTH->set_align(NSEngine::fa_right,NSEngine::fa_center);
        TEXTH->set_color(128,128,128);
        TEXT->set_alpha(0);
        TEXT->alpha_time(70,1,255);
        TEXTH->set_alpha(0);
        TEXTH->alpha_time(60,1,255);
        TEXT->set_pos(302,160);
        TEXTH->set_pos(302,182);
    }
    int augment = 1000; if (PlayerHUD::score - score > 10000) augment*=10; if (PlayerHUD::score - score > 100000) augment*=10;
    score = fmin(score+augment,PlayerHUD::score);
    std::string scores = std::to_string(math::min(score,9999999990));
    std::string hiscores = std::to_string(math::max(math::min(PlayerHUD::hiscore,9999999990),score));
    stringScoreCommas(scores); stringScoreCommas(hiscores);
    TEXT->set_text(scores);
    TEXTH->set_text(hiscores);
}

void PowerText()
{
    static AsciiElement* TEXT1 = nullptr;
    static AsciiElement* TEXT2 = nullptr;
    static AsciiElement* TEXT3 = nullptr;
    static AsciiElement* TEXT4 = nullptr;
    if (TEXT1 == nullptr)
    {
        TEXT1 = AsciiManager::newTxt(NSEngine::engineData::debugLayer,gameassets::fnt_score2,"");
        TEXT2 = AsciiManager::newTxt(NSEngine::engineData::debugLayer,gameassets::fnt_score2,""); TEXT2->set_scale(.65,.65);
        TEXT3 = AsciiManager::newTxt(NSEngine::engineData::debugLayer,gameassets::fnt_score2,"");
        TEXT4 = AsciiManager::newTxt(NSEngine::engineData::debugLayer,gameassets::fnt_score2,""); TEXT4->set_scale(.65,.65);
        TEXT1->set_align(NSEngine::fa_right,NSEngine::fa_center); TEXT1->set_color(0xfd,0x7f,0x3c);
        TEXT2->set_align(NSEngine::fa_right,NSEngine::fa_center); TEXT2->set_color(0xfd,0x7f,0x3c);
        TEXT3->set_align(NSEngine::fa_right,NSEngine::fa_center); TEXT3->set_color(0xfd,0x7f,0x3c);
        TEXT4->set_align(NSEngine::fa_right,NSEngine::fa_center); TEXT4->set_color(0xfd,0x7f,0x3c);
        TEXT1->set_alpha(0); TEXT1->alpha_time(100,1,255);
        TEXT2->set_alpha(0); TEXT2->alpha_time(100,1,255);
        TEXT3->set_alpha(0); TEXT3->alpha_time(100,1,255);
        TEXT4->set_alpha(0); TEXT4->alpha_time(100,1,255);
        TEXT1->set_pos(302-46-15,42);
        TEXT2->set_pos(302-46,42);
        TEXT3->set_pos(302-15,42);
        TEXT4->set_pos(302,42);
    }
    std::string pow1str = to_string_with_precision((float)PlayerHUD::power/(float)PlayerHUD::steppower,2);
    std::string pow2str = to_string_with_precision((float)PlayerHUD::maxpower/(float)PlayerHUD::steppower, 2);
    TEXT1->set_text(pow1str.substr(0, 2).c_str());
    TEXT2->set_text(pow1str.substr(2,2).c_str());
    TEXT3->set_text(("/"+pow2str.substr(0, 2)).c_str());
    TEXT4->set_text(pow2str.substr(2,2).c_str());
}

void PIVText()
{
    static AsciiElement* TEXT = nullptr;
    if (TEXT == nullptr)
    {
        TEXT = AsciiManager::newTxt(NSEngine::engineData::debugLayer,gameassets::fnt_score2,"");
        TEXT->set_align(NSEngine::fa_right,NSEngine::fa_center);
        TEXT->set_color(0x36,0xbc,0xfa);
        TEXT->set_pos(302,20);
        TEXT->set_alpha(0);
        TEXT->alpha_time(110,1,255);
    }
    std::string s = std::to_string(PlayerHUD::pointValue);
    stringScoreCommas(s);
    TEXT->set_text(s);
}

void GrazeText()
{
    static AsciiElement* TEXT = nullptr;
    if (TEXT == nullptr)
    {
        TEXT = AsciiManager::newTxt(NSEngine::engineData::debugLayer,gameassets::fnt_score2,"");
        TEXT->set_align(NSEngine::fa_right,NSEngine::fa_center);
        TEXT->set_pos(302,-2);
        TEXT->set_alpha(0);
        TEXT->alpha_time(120,1,255);
    }
    TEXT->set_text(std::to_string(PlayerHUD::graze));
}

void FpsText()
{
    static AsciiElement* FPSTEXT = nullptr;
    if (FPSTEXT == nullptr)
    {
        FPSTEXT = AsciiManager::newTxt(NSEngine::engineData::debugLayer,gameassets::fnt_small,"");
        FPSTEXT->set_align(NSEngine::fa_right,NSEngine::fa_bottom);
        FPSTEXT->set_pos(318,-238);
    }
    float fps = NSEngine::engineData::fps->GetFPS();
    FPSTEXT->set_text(to_string_with_precision(fps,1) + "fps");
}
void EtamaText()
{
    static AsciiElement* FPSTEXT = nullptr;
    if (FPSTEXT == nullptr)
    {
        FPSTEXT = AsciiManager::newTxt(NSEngine::engineData::debugLayer,gameassets::fnt_small,"");
        FPSTEXT->set_align(NSEngine::fa_right,NSEngine::fa_bottom);
        FPSTEXT->set_pos(318,-223);
    }
    static bool show = true;
    if (!show && NSEngine::engineData::gameflags&0b00000010) {show=true;FPSTEXT->set_alpha(255);}
    if (show && !(NSEngine::engineData::gameflags&0b00000010)) {show=false;FPSTEXT->set_alpha(0);}
    FPSTEXT->set_text(std::to_string(PlayerHUD::etama) + " etama");
}
void LaserText()
{
    static AsciiElement* FPSTEXT = nullptr;
    if (FPSTEXT == nullptr)
    {
        FPSTEXT = AsciiManager::newTxt(NSEngine::engineData::debugLayer,gameassets::fnt_small,"");
        FPSTEXT->set_align(NSEngine::fa_right,NSEngine::fa_bottom);
        FPSTEXT->set_pos(318,-208);
    }
    static bool show = true;
    if (!show && NSEngine::engineData::gameflags&0b00000010) {show=true;FPSTEXT->set_alpha(255);}
    if (show && !(NSEngine::engineData::gameflags&0b00000010)) {show=false;FPSTEXT->set_alpha(0);}
    FPSTEXT->set_text(std::to_string(PlayerHUD::laser) + " laser");
}
void ItemText()
{
    static AsciiElement* FPSTEXT = nullptr;
    if (FPSTEXT == nullptr)
    {
        FPSTEXT = AsciiManager::newTxt(NSEngine::engineData::debugLayer,gameassets::fnt_small,"");
        FPSTEXT->set_align(NSEngine::fa_right,NSEngine::fa_bottom);
        FPSTEXT->set_pos(318,-193);
    }
    static bool show = true;
    if (!show && NSEngine::engineData::gameflags&0b00000010) {show=true;FPSTEXT->set_alpha(255);}
    if (show && !(NSEngine::engineData::gameflags&0b00000010)) {show=false;FPSTEXT->set_alpha(0);}
    FPSTEXT->set_text(std::to_string(PlayerHUD::item) + " item");
}
void ItemcText()
{
    static AsciiElement* FPSTEXT = nullptr;
    if (FPSTEXT == nullptr)
    {
        FPSTEXT = AsciiManager::newTxt(NSEngine::engineData::debugLayer,gameassets::fnt_small,"");
        FPSTEXT->set_align(NSEngine::fa_right,NSEngine::fa_bottom);
        FPSTEXT->set_pos(318,-178);
    }
    static bool show = true;
    if (!show && NSEngine::engineData::gameflags&0b00000010) {show=true;FPSTEXT->set_alpha(255);}
    if (show && !(NSEngine::engineData::gameflags&0b00000010)) {show=false;FPSTEXT->set_alpha(0);}
    FPSTEXT->set_text(std::to_string(PlayerHUD::itemc) + " itemc");
}
void AnmText()
{
    static AsciiElement* FPSTEXT = nullptr;
    if (FPSTEXT == nullptr)
    {
        FPSTEXT = AsciiManager::newTxt(NSEngine::engineData::debugLayer,gameassets::fnt_small,"");
        FPSTEXT->set_align(NSEngine::fa_right,NSEngine::fa_bottom);
        FPSTEXT->set_pos(318,-163);
    }
    static bool show = true;
    if (!show && NSEngine::engineData::gameflags&0b00000010) {show=true;FPSTEXT->set_alpha(255);}
    if (show && !(NSEngine::engineData::gameflags&0b00000010)) {show=false;FPSTEXT->set_alpha(0);}
    FPSTEXT->set_text(std::to_string(PlayerHUD::anmscr) + " anms");
}
void IntText()
{
    static AsciiElement* FPSTEXT = nullptr;
    if (FPSTEXT == nullptr)
    {
        FPSTEXT = AsciiManager::newTxt(NSEngine::engineData::debugLayer,gameassets::fnt_small,"");
        FPSTEXT->set_align(NSEngine::fa_right,NSEngine::fa_bottom);
        FPSTEXT->set_pos(318,-148);
    }
    static bool show = true;
    if (!show && NSEngine::engineData::gameflags&0b00000010) {show=true;FPSTEXT->set_alpha(255);}
    if (show && !(NSEngine::engineData::gameflags&0b00000010)) {show=false;FPSTEXT->set_alpha(0);}
    FPSTEXT->set_text(std::to_string(NSEngine::InterpolateManager::NumOfInterpolators()) + " interpolators");
}

void PlayerHUD::Update(float power, int score, int life, int spell, int pointValue, int graze, float framespeed)
{
    FpsText();
    EtamaText();
    LaserText();
    ItemText();
    ItemcText();
    AnmText();
    IntText();
    ScoreText();
    PowerText();
    PIVText();
    GrazeText();
    if (this->life != life)
    {
        static int currentheart = 2;
        static int currentheartstate = 0;
        currentheartstate = life%5;
        if (life/5 != this->life/5)
        {
            if (life < this->life) 
            {
                AnmManager::interrupt(anmh[currentheart],3);
                if (currentheart > 0) currentheart--;
            }
            else
            {
                AnmManager::interrupt(anmh[currentheart],2);
                if (currentheart < 7) currentheart++;
            }
        }
        if (life < 40)
        AnmManager::interrupt(anmh[currentheart],currentheartstate==0?3:7+currentheartstate);
        this->life = life;
    }
    if (this->spell != spell)
    {
        static int currentspell = 2;
        static int currentspellstate = 0;
        currentspellstate = spell%5;
        if (spell/5 != this->spell/5)
        {
            if (spell < this->spell) 
            {
                AnmManager::interrupt(anms[currentspell],3);
                if (currentspell > 0) currentspell--;
            }
            else
            {
                AnmManager::interrupt(anms[currentspell],2);
                if (currentspell < 7) currentspell++;
            }
        }
        if (spell < 40)
        AnmManager::interrupt(anms[currentspell],currentspellstate==0?3:7+currentspellstate);
        this->spell = spell;
    }
    int score_before = PlayerHUD::score; PlayerHUD::score = score;
    this->power = power; this->pointValue = pointValue; this->graze = graze;
    if (score_before <= hiscore && score > hiscore) AnmManager::newAnim(frontHighScore);
}
