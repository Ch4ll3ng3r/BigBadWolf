#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#include <string>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include "CLevel.hpp"
#include "CLogfile.hpp"
#include "CWolf.hpp"
#include "CRotkaeppchen.hpp"
#include "SafeDelete.hpp"
#include "CMovement.hpp"
#include "CCollision.hpp"

class CGame
{
    public:
        CGame ();
        ~CGame ();
        void run ();

    private:
        void processWindowEvents ();
        void processKeyboardEvents ();
        void processGameEvents ();
        void checkCollisions ();
        void render ();
        void loadTextures ();
        void loadTexture (string strPath, string strDescription);
        void loadSprite (string strDescription);
        sf::RenderWindow *m_pWindow;
        sf::Clock m_Clock;
        CLogfile *m_pLogfile;
        CLevel *m_pLevel;
        CWolf *m_pWolf;
        CRotkaeppchen *m_pRotkaeppchen;
        list<sf::Sprite*> m_lpSprites;
        map<string, sf::Texture> m_Textures;
        queue<CEvent*> m_qpPendingEvents;
        bool m_bRun;
        bool m_bUseLogging;
        unsigned int m_uiMaxFrames;
        unsigned int m_uiElapsedTime;
};

#endif // GAME_HPP_INCLUDED
