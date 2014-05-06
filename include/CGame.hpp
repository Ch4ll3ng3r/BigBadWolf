#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#include <windows.h>
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
#include "Control.hpp"
#include "CControlWolf.hpp"
#include "CControlRotkaeppchen.hpp"

class CGame
{
    public:
        CGame ();
        ~CGame ();
        void run ();
        void displayGameOverScreen ();

    private:
        void processWindowEvents ();
        void processKeyboardEvents ();
        void processGameEvents ();
        void checkCollisions ();
        void checkGameEndConditions ();
        void updateAI ();
        void render ();
        void initializeCreatures ();
        void loadTextures ();
        void loadTexture (string strPath, string strDescription);
        void loadFont (string strPath, string strDescription);
        void loadSprite (string strDescription);
        void loadIniFile (string strPath);
        string loadIniString (string strSection, string strKey, string strPath);
        int loadIniInt (string strSection, string strKey, string strPath);
        bool loadIniBool (string strSection, string strKey, string strPath);
        sf::RenderWindow *m_pWindow;
        sf::Clock m_Clock;
        sf::Vector2u m_uiResolution;
        CLogfile *m_pLogfile;
        CLevel *m_pLevel;
        CWolf *m_pWolf;
        CRotkaeppchen *m_pRotkaeppchen;
        CCreature *m_pWinner;
        list<sf::Sprite*> m_lpSprites;
        map<string, sf::Texture> m_Textures;
        map<string, sf::Font> m_Fonts;
        queue<CEvent*> m_qpPendingEvents;
        EControl m_ControlWolf;
        EControl m_ControlRotkaeppchen;
        CControlWolf *m_pControlWolf;
        CControlRotkaeppchen *m_pControlRotkaeppchen;
        bool m_bRun;
        bool m_bUseLogging;
        bool m_bFullscreen;
        unsigned int m_uiMaxFrames;
        unsigned int m_uiElapsedTime;
        unsigned int m_uiNow;
        unsigned int m_uiLastUpdateTime;
        unsigned int m_uiGameOverTime;
        unsigned int m_uiTimeLimit; // in seconds
        unsigned int m_uiGameStartTime;
};

#endif // GAME_HPP_INCLUDED
