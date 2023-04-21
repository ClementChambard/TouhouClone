#include "GameLayers.h"
#include "NSEngine.h"
#include <Engine.hpp>

NSEngine::SpriteBatch* layer(int i) { return &NSEngine::engineData::layers[i]; }

int GameLayers::L1;
int GameLayers::L2;
int GameLayers::L3;
int GameLayers::L4;
int GameLayers::L5;
int GameLayers::L6;
int GameLayers::L7;
int GameLayers::L8;
int GameLayers::L9;
int GameLayers::L10;
int GameLayers::L11;
int GameLayers::L12;
int GameLayers::L13;
int GameLayers::L14;
int GameLayers::L15;
int GameLayers::L16;
int GameLayers::L17;
int GameLayers::L18;
int GameLayers::L19;
int GameLayers::L20;
int GameLayers::L21;
int GameLayers::L22;
int GameLayers::L23;
int GameLayers::L24;
int GameLayers::L25;
int GameLayers::L26;
int GameLayers::L27;
int GameLayers::L28;
int GameLayers::L29;
int GameLayers::L30;

void GameLayers::Init(NSEngine::LayerRenderer* la)
{
    L1 = NSEngine::addGameLayer();
    L2 = NSEngine::addGameLayer(true);
    L3 = NSEngine::addGameLayer(false, true);
    L4 = NSEngine::addGameLayer(false, true);
    L5 = NSEngine::addGameLayer(false, true);
    L6 = NSEngine::addGameLayer(false, true);
    L7 = NSEngine::addGameLayer(false, true);
    L8 = NSEngine::addGameLayer(false, true);
    L9 = NSEngine::addGameLayer(false, true);
    L10 = NSEngine::addGameLayer(false, true);
    L11 = NSEngine::addGameLayer(false, true);
    L12 = NSEngine::addGameLayer(false, true);
    L13 = NSEngine::addGameLayer(false, true);
    L14 = NSEngine::addGameLayer(false, true);
    L15 = NSEngine::addGameLayer(false, true);
    L16 = NSEngine::addGameLayer(false, true);
    L17 = NSEngine::addGameLayer(false, true);
    L18 = NSEngine::addGameLayer(false, true);
    L19 = NSEngine::addGameLayer(false, true);
    L20 = NSEngine::addGameLayer(false, true);
    L21 = NSEngine::addGameLayer(false, true);
    L22 = NSEngine::addGameLayer(false, true);
    L23 = NSEngine::addGameLayer(false, true);
    L24 = NSEngine::addGameLayer(false, true);
    L25 = NSEngine::addGameLayer(false, true);
    L26 = NSEngine::addGameLayer(false, true);
    L27 = NSEngine::addGameLayer(false, true);
    L28 = NSEngine::addGameLayer(false, true);
    L29 = NSEngine::addGameLayer(false, true);
    L30 = NSEngine::addGameLayer(false, true);
    
    for (auto l : NSEngine::engineData::layers) la->addLayer(&l);
    la->setRenderFunction(Render);
}



void GameLayers::Render(NSEngine::LayerRenderer* w)
{

    static int surf1 = NSEngine::TextureManager::CreateSurface(416*2,480*2);
    static int surf2 = NSEngine::TextureManager::CreateSurface(416,480);

    NSEngine::TextureManager::SetSurfaceTarget(surf1);
       
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        for (unsigned int i = 0; i < GL_ L24; i++)
        {
            NSEngine::SpriteBatch* l = &NSEngine::engineData::layers[i];
            l->end();
            w->getShader()->SetProjectionMatrix(NSEngine::activeCamera3D()->getProjection(l->is_static));
            w->getShader()->SetViewMatrix(NSEngine::activeCamera3D()->getView(l->is_static));
            float mi=1000000.f, ma=1000000.f;
            glm::vec4 col = {0,0,0,0};
            if (NSEngine::engineData::cam3d!=nullptr && !l->is_static) col = NSEngine::engineData::cam3d->getFog(mi,ma);
            w->getShader()->SetFog(mi, ma, col);
            l->renderBatch();
        }

        NSEngine::getInstance()->window().BindAsRenderTarget();

    
    if (NSEngine::getInstance()->flags().flags.wireframe)
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    static NSEngine::SpriteBatch* drawbatch = (new NSEngine::SpriteBatch())->Init();

    drawbatch->begin();
    NSEngine::draw_surface(surf1,-320+16,240,112,-240,drawbatch);
    if (NSEngine::getInstance()->flags().val&0b10000000)
    {
        NSEngine::draw_set_color({32,224,32,128});
        NSEngine::draw_surface(surf1,-320+16,240+8,112,-240+8,drawbatch,0);
        NSEngine::draw_set_color({255,255,255,255});
    }
    drawbatch->end();
    w->getShader()->SetProjectionMatrix(NSEngine::activeCamera3D()->getProjection(true));
    w->getShader()->SetViewMatrix(NSEngine::activeCamera3D()->getView(true));
    drawbatch->renderBatch();
    if (NSEngine::getInstance()->flags().flags.wireframe)
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        for (unsigned int i = GL_ L24; i < NSEngine::engineData::layers.size(); i++)
        {
            NSEngine::SpriteBatch* l = &NSEngine::engineData::layers[i];
            l->end();
            w->getShader()->SetProjectionMatrix(NSEngine::activeCamera3D()->getProjection(l->is_static));
            w->getShader()->SetViewMatrix(NSEngine::activeCamera3D()->getView(l->is_static));
            float mi=1000000.f, ma=1000000.f;
            glm::vec4 col = {0,0,0,0};
            if (NSEngine::engineData::cam3d!=nullptr && !l->is_static) col = NSEngine::engineData::cam3d->getFog(mi,ma);
            w->getShader()->SetFog(mi, ma, col);
            l->renderBatch();
        }
}

void GameLayers::Render(NSEngine::Window* w)
{

    static int surf1 = NSEngine::TextureManager::CreateSurface(416*2,480*2);
    static int surf2 = NSEngine::TextureManager::CreateSurface(416,480);

    NSEngine::TextureManager::SetSurfaceTarget(surf1);
       
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        for (unsigned int i = 0; i < GL_ L24; i++)
        {
            NSEngine::SpriteBatch* l = &NSEngine::engineData::layers[i];
            l->end();
            w->getBaseShader()->SetProjectionMatrix(NSEngine::activeCamera3D()->getProjection(l->is_static));
            w->getBaseShader()->SetViewMatrix(NSEngine::activeCamera3D()->getView(l->is_static));
            float mi=1000000.f, ma=1000000.f;
            glm::vec4 col = {0,0,0,0};
            if (NSEngine::engineData::cam3d!=nullptr && !l->is_static) col = NSEngine::engineData::cam3d->getFog(mi,ma);
            w->getBaseShader()->SetFog(mi, ma, col);
            l->renderBatch();
        }

        w->BindAsRenderTarget();

    
    if (NSEngine::getInstance()->flags().flags.wireframe)
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    static NSEngine::SpriteBatch* drawbatch = (new NSEngine::SpriteBatch())->Init();

    drawbatch->begin();
    NSEngine::draw_surface(surf1,-320+16,240,112,-240,drawbatch);
    if (NSEngine::getInstance()->flags().val&0b10000000)
    {
        NSEngine::draw_set_color({32,224,32,128});
        NSEngine::draw_surface(surf1,-320+16,240+8,112,-240+8,drawbatch,0);
        NSEngine::draw_set_color({255,255,255,255});
    }
    drawbatch->end();
    w->getBaseShader()->SetProjectionMatrix(NSEngine::activeCamera3D()->getProjection(true));
    w->getBaseShader()->SetViewMatrix(NSEngine::activeCamera3D()->getView(true));
    drawbatch->renderBatch();
    if (NSEngine::getInstance()->flags().flags.wireframe)
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        for (unsigned int i = GL_ L24; i < NSEngine::engineData::layers.size(); i++)
        {
            NSEngine::SpriteBatch* l = &NSEngine::engineData::layers[i];
            l->end();
            w->getBaseShader()->SetProjectionMatrix(NSEngine::activeCamera3D()->getProjection(l->is_static));
            w->getBaseShader()->SetViewMatrix(NSEngine::activeCamera3D()->getView(l->is_static));
            float mi=1000000.f, ma=1000000.f;
            glm::vec4 col = {0,0,0,0};
            if (NSEngine::engineData::cam3d!=nullptr && !l->is_static) col = NSEngine::engineData::cam3d->getFog(mi,ma);
            w->getBaseShader()->SetFog(mi, ma, col);
            l->renderBatch();
        }
}
