#include "textAnm.h"

textAnm::textAnm(int digit, int space, void(*anm)(AnimScript*), int offset, bool showAll) 
{
    this->digit = digit;
    this->offset = offset;
    this->space = space;
    this->showAll = showAll;
    anms = new int[digit];
    num = 0;
    for (int i = 0; i < digit; i++)
    {
        anms[i] = AnmManager::newAnim(anm,-1,1);
        AnmManager::UpdateChild(anms[i],(float)(offset+space*i),0,0,0,0,0,1,1,1);
    }
}

textAnm::~textAnm() 
{
    for (int i = 0; i < digit; i++) AnmManager::deleteAnim(anms[i]);
}

void textAnm::interrupt(int i) { for (int j = 0; j < digit; j++) AnmManager::interrupt(anms[j],i); }
void textAnm::reset()
{
    int n = num;
    for (int i = digit-1; i >= 0; i--)
    {
        AnmManager::anim(anms[i])->offset_sprite(-(n%10));
        n/=10;
    }
    num = 0;
}
void textAnm::set_number(int num)
{

    if (num == this->num) return;
    reset();

    this->num = num;
    for (int i = digit-1; i >= 0; i--)
    {
        if (!showAll) AnmManager::UpdateChild(anms[i],(float)(offset+space*i),0,0,0,0,0,num!=0,num!=0,1);
        AnmManager::anim(anms[i])->offset_sprite(num%10);
        num/=10;
    }

}

#include <NSEngine.h>
void AsciiElement::Draw()
{
    if (!active) return;
    NSEngine::draw_set_layer(layerID);
    NSEngine::Color c = NSEngine::Color(col.r, col.g, col.b, a);
    //NSEngine::draw_set_halign((NSEngine::font_align)halign);
    //NSEngine::draw_set_valign((NSEngine::font_align)valign);
    //NSEngine::SpriteManager::draw_text(font,text.c_str(),pos,scale,c);
}

void AsciiElement::set_text(std::string t)
{
    text = t;
}

AsciiElement* AsciiManager::asciipool;
int AsciiManager::currentpos;
void AsciiManager::Init()
{
    asciipool = new AsciiElement[100];
    currentpos = 0;
}
AsciiElement* AsciiManager::newTxt(int l, int f, std::string t)
{
    int i = 0;
    while (asciipool[currentpos].isActive() && i < 100) { currentpos = (currentpos+1)%100; i++; }
    i = currentpos; currentpos = (currentpos+1)%100;
    asciipool[i].Init(l,f,t);
    return &(asciipool[i]);
}
