#ifndef THANIM
#define THANIM

#include <vector>
#include "AnmManagerOld/AnmManager.h"

class THAnim {
    public:
        THAnim(void (*anmC)(AnimScript*), void (*anmCL)(AnimScript*), void (*anmLC)(AnimScript*), void (*anmCR)(AnimScript*), void (*anmRC)(AnimScript*), void (*anmSP)(AnimScript*) = nullptr) { this->anmC=anmC; this->anmCL=anmCL; this->anmCR=anmCR; this->anmLC=anmLC; this->anmRC=anmRC; this->anmSP = anmSP; anm = AnmManager::newAnim(anmC,-1,1); }

        void PlayAnimSP()
        {
            if (anmSP != nullptr) AnmManager::chgScript(anm,anmSP,1);
            AnmManager::UpdateChild(anm,x,y,0,0,0,0,1,1,true);
        }
        void Reset()
        {
            if (anm != -1 && AnmManager::IsActive(anm)) AnmManager::chgScript(anm,anmC,1);
            AnmManager::anim(anm)->offset_sprite(offset);
            AnmManager::anim(anm)->set_alpha(255);
        }
        void Update(float hsp, float x, float y)
        {
            this->x = x; this->y = y;
            if (hsp != this->hsp)
            {
                if (hsp < -0.1f && this->hsp >= -0.1f) 
                {
                    AnmManager::chgScript(anm,anmCL,1);
                    AnmManager::anim(anm)->offset_sprite(offset);
                }
                else if (hsp > 0.1f && this->hsp <= 0.1f) 
                {
                    AnmManager::chgScript(anm,anmCR,1);
                    AnmManager::anim(anm)->offset_sprite(offset);
                }
                else if (hsp >= -0.1f  && this->hsp < -0.1f) 
                {
                    AnmManager::chgScript(anm,anmLC,1);
                    AnmManager::anim(anm)->offset_sprite(offset);
                }
                else if (hsp <= 0.1f && this->hsp > 0.1f) 
                {
                    AnmManager::chgScript(anm,anmRC,1);
                    AnmManager::anim(anm)->offset_sprite(offset);
                }
                this->hsp = hsp;
            }
            AnmManager::UpdateChild(anm,x,y,0,0,0,0,1,1,true);
        }

        ~THAnim()
        {
            AnmManager::deleteAnim(anm);
        }

        void Offset(int i) { offset += i; AnmManager::anim(anm)->offset_sprite(offset); }

        AnimScript* Anim() { return AnmManager::anim(anm); }

    private:
        int offset = 0;
        int anm;
        float hsp = 0;
        float x, y;
        void (*anmC)(AnimScript*);
        void (*anmCR)(AnimScript*);
        void (*anmRC)(AnimScript*);
        void (*anmCL)(AnimScript*);
        void (*anmLC)(AnimScript*);
        void (*anmSP)(AnimScript*);
};

#endif
