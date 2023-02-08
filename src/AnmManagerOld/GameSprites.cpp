#include "GameSprites.h"

sprite_data::sprite_data(int t, int w, int h, float u1, float v1, float u2, float v2)
{
    this->tex_id = t;
    this->w = w;
    this->h = h;
    this->u1 = u1;
    this->v1 = v1;
    this->u2 = u2;
    this->v2 = v2;
}

std::vector<sprite_data> GS_ sprs;

int GS_ AddSprite(int tex_id, int x, int y, int w, int h)
{
    int id = sprs.size();
    glm::vec2 uv1 = NSEngine::TextureManager::GetUVAt(tex_id, x, y);
    glm::vec2 uv2 = NSEngine::TextureManager::GetUVAt(tex_id, x+w, y+h);
    sprs.push_back(sprite_data(tex_id,w,h,uv1.x,uv1.y,uv2.x,uv2.y));
    return id;
}

int GS_ AddSprites(int tex_id, int xstart, int ystart, int nx, int ny, int w, int h)
{
    int ret;
    for (int i = 0; i < ny; i++)
        for (int j = 0; j < nx; j++)
            if (i == 0 && j == 0) ret = AddSprite(tex_id, xstart, ystart, w, h);
            else AddSprite(tex_id, xstart + j * w, ystart + i * h, w, h);
    return ret;
}

sprite_data* sprite(unsigned int i)
{
    if (i >= GS_ sprs.size()) return nullptr;
    return &(GS_ sprs[i]);
}

#include <NSEngine.h>
namespace NSEngine {

    void batch_draw_game_sprite(SpriteBatch* batch, int sprite_index, float x, float y, float xs, float ys, float rot, Color ctl, Color ctr, Color cbr, Color cbl)
    {

        sprite_data* sd = &(GS_ sprs[sprite_index]);

        glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.f), rot, {0.f, 0.f, 1.f});

        glm::vec3 tl1 = glm::vec3(-xs*sd->w/2, -ys*sd->h/2, 0.f);
        glm::vec4 rotatedTL = glm::vec4(tl1,1.f) * rotationMatrix;
        glm::vec3 tr1 = glm::vec3(xs*sd->w/2, -ys*sd->h/2, 0.f);
        glm::vec4 rotatedTR = glm::vec4(tr1,1.f) * rotationMatrix;
        glm::vec3 br1 = glm::vec3(xs*sd->w/2, ys*sd->h/2, 0.f);
        glm::vec4 rotatedBR = glm::vec4(br1,1.f) * rotationMatrix;
        glm::vec3 bl1 = glm::vec3(-xs*sd->w/2, ys*sd->h/2, 0.f);
        glm::vec4 rotatedBL = glm::vec4(bl1,1.f) * rotationMatrix;

        Vertex TL = {rotatedTL, ctl, {sd->u1, sd->v2}};
        Vertex TR = {rotatedTR, ctr, {sd->u2, sd->v2}};
        Vertex BR = {rotatedBR, cbr, {sd->u2, sd->v1}};
        Vertex BL = {rotatedBL, cbl, {sd->u1, sd->v1}};

        batch->draw(sd->tex_id, TL, TR, BR, BL, 0);
    }
    void draw_game_sprite(int sprite_index, float x, float y, float xs, float ys, float rot, Color ctl, Color ctr, Color cbr, Color cbl)
    { batch_draw_game_sprite(&engineData::layers[engineData::targetLayer], sprite_index, x, y, xs, ys, rot, ctl, ctr, cbr, cbl); }

}
