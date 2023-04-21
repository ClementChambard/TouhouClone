#include "PlayerBullet.h"
#include "CollisionManager.h"
#include "PlayerEntity.h"
#include "bulletsScripts.h"
#include <FileOpener.h>

int ShooterManager::power = 0;
int ShooterManager::powerstep = 20;
int ShooterManager::bulletcount;
int ShooterManager::optioncount;
int ShooterManager::shootercount;
ShooterManager::Bullet* ShooterManager::bullets;
ShooterManager::Option* ShooterManager::options;
ShooterManager::Shooter* ShooterManager::shooters;
ShooterManager::intRange* ShooterManager::shootersPower;
bool* ShooterManager::shootersFocus;
float ShooterManager::shootCounter = 0;
int ShooterManager::current_pos = 0;
int ShooterManager::src_bulletsnd;
int ShooterManager::pwr_lvl_cnt;
int ShooterManager::max_dmg;
PlayerData* ShooterManager::player;

void ShooterManager::Init(PlayerData* player, int& powerm, int& powers, float& hitbox, float& grazebox, float& itembox, float& spdnf, float& spdf, int& maxdmg)
{
    ShooterManager::player = player;
    std::string shtfile = player->shtfile();
    // src_bulletsnd = NSEngine::AudioEngine::CreateSource();
    pbscr::Init();
    bulletcount = 500;
    bullets = new Bullet[bulletcount];

    NSEngine::FileOpener::openFile(shtfile);
    int sht_off_cnt = NSEngine::FileOpener::readInt16(2);
    hitbox = NSEngine::FileOpener::readFloat(4);
    grazebox = NSEngine::FileOpener::readFloat(8);
    itembox = NSEngine::FileOpener::readFloat(12);
    spdnf = NSEngine::FileOpener::readFloat(16);
    spdf = NSEngine::FileOpener::readFloat(20);
    // 24 : diagonal nf
    // 28 : diagonal f
    pwr_lvl_cnt = NSEngine::FileOpener::readInt16(32);
    powerstep = NSEngine::FileOpener::readInt32(36);
    powers = powerstep;
    powerm = pwr_lvl_cnt * powerstep;
    max_dmg = maxdmg = NSEngine::FileOpener::readInt32(40);

    optioncount = (pwr_lvl_cnt * (1 + pwr_lvl_cnt)) / 2 + 1;
    options = new Option[optioncount];
    int off = 64;
    int p = 1, i = 1;
    while (i < optioncount) {
        float min = p * powerstep, max = (p + 1) * powerstep;
        for (int j = 0; j < p; j++) {
            options[i].nfx = options[i].x = NSEngine::FileOpener::readFloat(off);
            options[i].nfy = options[i].y = -NSEngine::FileOpener::readFloat(off + 4);
            options[i].powermin = min;
            options[i].powermax = max;
            options[i].anm1 = AnmManager::newAnim(player->OptionAnm(false), -1, 1);
            if (max - powers >= powerm)
                options[i].anm2 = AnmManager::newAnim(player->OptionAnm(true));
            i++;
            off += 8;
        }
        p++;
    }
    for (i = 1; i < optioncount; i++) {
        options[i].fx = NSEngine::FileOpener::readFloat(off);
        options[i].fy = -NSEngine::FileOpener::readFloat(off + 4);
        off += 8;
    }

    off += 4 * sht_off_cnt;
    shootercount = (NSEngine::FileOpener::getSize() - off - sht_off_cnt * 4) / 88;
    shooters = new Shooter[shootercount];
    shootersPower = new intRange[shootercount];
    shootersFocus = new bool[shootercount];

    int s = 0;
    int optionoffset = 0;
    for (i = 0; i < 2 * (pwr_lvl_cnt + 1); i++) {
        intRange rg = { (i % (pwr_lvl_cnt + 1)) * powerstep, (i % (pwr_lvl_cnt + 1) + 1) * powerstep };
        if (rg.min / powerstep == 0)
            optionoffset = 0;
        else
            optionoffset += (rg.min / powerstep - 1);
        bool focus = floor((float)i / (float)(pwr_lvl_cnt + 1));
        bool check = false;
        while (!check) {
            if (s >= shootercount)
                break;
            shootersFocus[s] = focus;
            shootersPower[s] = rg;
            shooters[s].fire_rate = NSEngine::FileOpener::readInt8(off);
            shooters[s].start_delay = NSEngine::FileOpener::readInt8(off + 1);
            shooters[s].dmg = NSEngine::FileOpener::readInt16(off + 2);
            shooters[s].off_x = NSEngine::FileOpener::readFloat(off + 4);
            shooters[s].off_y = -NSEngine::FileOpener::readFloat(off + 8);
            shooters[s].hitbox_x = NSEngine::FileOpener::readFloat(off + 12);
            shooters[s].hitbox_y = NSEngine::FileOpener::readFloat(off + 16);
            shooters[s].angle = -NSEngine::FileOpener::readFloat(off + 20);
            shooters[s].speed = NSEngine::FileOpener::readFloat(off + 24);
            shooters[s].unknown_sht_int32 = NSEngine::FileOpener::readInt32(off + 28);
            shooters[s].option = NSEngine::FileOpener::readInt8(off + 32);
            shooters[s].unknown_sht_byte_0 = NSEngine::FileOpener::readInt8(off + 33);
            shooters[s].anm = NSEngine::FileOpener::readInt8(off + 34);
            shooters[s].anm_hit = NSEngine::FileOpener::readInt8(off + 35);
            shooters[s].sfx_id = NSEngine::FileOpener::readInt16(off + 36);
            shooters[s].fire_rate2 = NSEngine::FileOpener::readInt8(off + 38);
            shooters[s].start_delay2 = NSEngine::FileOpener::readInt8(off + 39);
            shooters[s].func_on_init = NSEngine::FileOpener::readInt32(off + 40);
            shooters[s].func_on_tick = NSEngine::FileOpener::readInt32(off + 44);
            shooters[s]._old_on_draw = NSEngine::FileOpener::readInt32(off + 48);
            shooters[s].func_on_hit = NSEngine::FileOpener::readInt32(off + 52);
            shooters[s].flag0 = NSEngine::FileOpener::readInt32(off + 56);
            shooters[s].flag1 = NSEngine::FileOpener::readInt32(off + 60);
            shooters[s].flag2 = NSEngine::FileOpener::readInt32(off + 64);
            shooters[s].flag3 = NSEngine::FileOpener::readInt32(off + 68);
            shooters[s].flag4 = NSEngine::FileOpener::readInt32(off + 72);
            shooters[s].flag5 = NSEngine::FileOpener::readInt32(off + 76);
            shooters[s].flag6 = NSEngine::FileOpener::readInt32(off + 80);
            shooters[s].flag7 = NSEngine::FileOpener::readInt32(off + 84);
            if (shooters[s].option != 0)
                shooters[s].option += optionoffset;
            check = NSEngine::FileOpener::readInt32(off + 88) == 0xFFFFFFFF;
            s++;
            off += 88;
        }
        off += 4;
    }

    NSEngine::FileOpener::closeFile();
}

void ShooterManager::Delete()
{
    delete[] bullets;
    delete[] options;
    delete[] shooters;
    delete[] shootersPower;
    delete[] shootersFocus;
}

void ShooterManager::Update(bool shooting, bool focus, float framespeed)
{

    PlayerEntity* p = PlayerEntity::GetInstance();

    // update options
    for (int i = 0; i < optioncount; i++) {
        if (focus && options[i].x != options[i].fx)
            options[i].x += framespeed * (options[i].fx - options[i].nfx) / OPTION_MOVE_TIME;
        if (focus && options[i].y != options[i].fy)
            options[i].y += framespeed * (options[i].fy - options[i].nfy) / OPTION_MOVE_TIME;
        if (!focus && options[i].x != options[i].nfx)
            options[i].x += framespeed * (options[i].nfx - options[i].fx) / OPTION_MOVE_TIME;
        if (!focus && options[i].y != options[i].nfy)
            options[i].y += framespeed * (options[i].nfy - options[i].fy) / OPTION_MOVE_TIME;
        if (options[i].powermax > power && options[i].powermin <= power) {
            AnmManager::UpdateChild(options[i].anm1, options[i].x + p->xp[2], options[i].y + p->yp[2], 0, 0, 0, 0, 1, 1, true);
            if (options[i].anm2 != -1)
                AnmManager::UpdateChild(options[i].anm2, options[i].x + p->xp[2], options[i].y + p->yp[2], 0, 0, 0, 0, 1, 1, true);
            if (!options[i].isDrawn) {
                options[i].isDrawn = true;
                AnmManager::interrupt(options[i].anm1, 2);
                if (options[i].anm2 != -1)
                    AnmManager::interrupt(options[i].anm2, 2);
            }
        } else if (options[i].isDrawn) {
            options[i].isDrawn = false;
            AnmManager::interrupt(options[i].anm1, 3);
            if (options[i].anm2 != -1)
                AnmManager::interrupt(options[i].anm2, 3);
        }
    }

    // update bullets
    for (int i = 0; i < bulletcount; i++) {
        if (!bullets[i].active)
            continue;
        pbscr::scrtick[shooters[bullets[i].shooterID].func_on_tick](&(bullets[i]));
        AnmManager::UpdateChild(bullets[i].anm, bullets[i].x, bullets[i].y, 0, 0, 0, bullets[i].direction, 1, 1, true);
        float a;
        if (CollisionManager::IsHit(1, bullets[i].box, a)) {
            pbscr::scrhit[shooters[bullets[i].shooterID].func_on_hit](&(bullets[i]));
        }
    }

    // update shooters
    if (shooting) {
        for (int i = 0; i < shootercount; i++) {
            if ((focus && !shootersFocus[i]) || (!focus && shootersFocus[i]))
                continue;
            if (power < shootersPower[i].min || power >= shootersPower[i].max)
                continue;
            if (((int)floor(shootCounter) % shooters[i].fire_rate) != shooters[i].start_delay)
                continue;
            // if ((shootCounter - shooters[i].start_delay) < 0 || ((int)floor(shootCounter) % shooters[i].fire_rate) != 0) continue;
            int qqq = 0;
            while (qqq++ < bulletcount && bullets[current_pos].active)
                current_pos = (current_pos + 1) % bulletcount;
            if (bullets[current_pos].active) {
                CollisionManager::destroyPlayerHitbox(bullets[current_pos].box);
                AnmManager::deleteAnim(bullets[current_pos].anm);
            }
            bullets[current_pos].shooterID = i;
            bullets[current_pos].active = true;
            bullets[current_pos].x = shooters[i].off_x + options[shooters[i].option].x + p->xp[1];
            bullets[current_pos].y = shooters[i].off_y + options[shooters[i].option].y + p->yp[1];
            bullets[current_pos].direction = shooters[i].angle;
            bullets[current_pos].speed = shooters[i].speed;
            bullets[current_pos].hit = false;
            bullets[current_pos].shooterID = i;
            bullets[current_pos].anm = AnmManager::newAnim(player->BulletAnm(shooters[i].anm));
            bullets[current_pos].box = CollisionManager::NewPlayerHitbox(bullets[current_pos].x, bullets[current_pos].y, 8, shooters[i].dmg);
            pbscr::scrinit[shooters[i].func_on_init](&(bullets[current_pos]));
            // if (shooters[i].sfx_id != -1) NSEngine::AudioEngine::PlaySoundAtSource(src_bulletsnd, pbscr::sounds[shooters[i].sfx_id]);
            AnmManager::UpdateChild(bullets[current_pos].anm, bullets[current_pos].x, bullets[current_pos].y, 0, 0, 0, bullets[current_pos].direction, 1, 1, true);
            current_pos = (current_pos + 1) % bulletcount;
        }
        shootCounter += framespeed;
        float frac = shootCounter - floor(shootCounter);
        shootCounter = frac + (int)(floor(shootCounter)) % 15;
    } else
        shootCounter = 0;
}

void ShooterManager::OptionDie()
{
    for (int i = 0; i < optioncount; i++)
        if (options[i].powermax > power && options[i].powermin <= power) {
            AnmManager::interrupt(options[i].anm1, 1);
            if (options[i].anm2 != -1)
                AnmManager::interrupt(options[i].anm2, 1);
        }
}
void ShooterManager::OptionRespawn()
{
    for (int i = 0; i < optioncount; i++)
        if (options[i].powermax > power && options[i].powermin <= power) {
            AnmManager::interrupt(options[i].anm1, 2);
            if (options[i].anm2 != -1)
                AnmManager::interrupt(options[i].anm2, 2);
        }
}
