#include "../include/CGame.hpp"

CGame::CGame ()
{
    m_pWindow = nullptr;
    m_pLogfile = nullptr;
    m_bUseLogging = false;
    m_pWindow = new sf::RenderWindow (sf::VideoMode::getDesktopMode (), "B1G B4D W0LF", sf::Style::Fullscreen);
    if (m_bUseLogging)
        m_pLogfile = new CLogfile ("log");
    cout << "starting game..." << endl;
    if (m_bUseLogging)
        m_pLogfile->write ("starting game...");
    loadTextures ();
    if (m_bUseLogging)
        m_pLogfile->write ("textures loaded");
    loadSprite ("background");
    if (m_bUseLogging)
        m_pLogfile->write ("sprites loaded");
    m_pLevel = nullptr;
    m_pLevel = new CLevel (&m_lpSprites, m_Textures.at ("tree"), sf::Vector2i (static_cast<int> (m_pWindow->getSize ().x),
                                                                               static_cast<int> (m_pWindow->getSize ().y)));
    sf::Sprite *pSprite = nullptr;
    pSprite = new sf::Sprite (m_Textures.at ("wolf"));
    m_lpSprites.push_back (pSprite);
    m_pWolf = nullptr;
    m_pWolf = new CWolf (pSprite, sf::Vector2f (500.f, 300.f));
    pSprite = nullptr;
    pSprite = new sf::Sprite (m_Textures.at ("rotkaeppchen"));
    m_lpSprites.push_back (pSprite);
    m_pRotkaeppchen = nullptr;
    m_pRotkaeppchen = new CRotkaeppchen (pSprite, sf::Vector2f (100.f, 100.f));
    pSprite = nullptr;
    m_uiMaxFrames = 1000;
    m_bRun = true;
}

CGame::~CGame ()
{
    if (m_bUseLogging)
        m_pLogfile->write ("exiting game...");
    cout << "exiting game..." << endl;
    m_pWindow->close ();
    list<sf::Sprite*>::iterator i;
    for (i = m_lpSprites.begin (); i != m_lpSprites.end (); i++)
    {
        SAFE_DELETE (*i);
    }
    while (!m_qpPendingEvents.empty ())
    {
        SAFE_DELETE (m_qpPendingEvents.front ());
        m_qpPendingEvents.pop ();
    }
    m_lpSprites.clear ();
    SAFE_DELETE (m_pRotkaeppchen);
    SAFE_DELETE (m_pWolf);
    SAFE_DELETE (m_pLevel);
    SAFE_DELETE (m_pWindow);
    if (m_bUseLogging)
        SAFE_DELETE (m_pLogfile);
}

void CGame::run ()
{
    while (m_bRun)
    {
        if (m_Clock.getElapsedTime ().asMilliseconds () >= 1000 / m_uiMaxFrames)
        {
            processWindowEvents ();
            processKeyboardEvents ();
            checkCollisions ();
            processGameEvents ();
            render ();
            m_uiElapsedTime = m_Clock.restart ().asMilliseconds ();
        }
    }
}

void CGame::processKeyboardEvents ()
{
    // esc -> exit game
    if (sf::Keyboard::isKeyPressed (sf::Keyboard::Escape))
        m_bRun = false;

    // moving wolf
    if (sf::Keyboard::isKeyPressed (sf::Keyboard::Up))
    {
        m_pWolf->setDirection (0.f);
        m_pWolf->move (m_uiElapsedTime);
    }
    else if (sf::Keyboard::isKeyPressed (sf::Keyboard::Right))
    {
        m_pWolf->setDirection (90.f);
        m_pWolf->move (m_uiElapsedTime);
    }
    else if (sf::Keyboard::isKeyPressed (sf::Keyboard::Down))
    {
        m_pWolf->setDirection (180.f);
        m_pWolf->move (m_uiElapsedTime);
    }
    else if (sf::Keyboard::isKeyPressed (sf::Keyboard::Left))
    {
        m_pWolf->setDirection (270.f);
        m_pWolf->move (m_uiElapsedTime);
    }

    // moving rotkaeppchen
    if (sf::Keyboard::isKeyPressed (sf::Keyboard::I))
    {
        m_pRotkaeppchen->setDirection (0.f);
        m_pRotkaeppchen->move (m_uiElapsedTime);
    }
    else if (sf::Keyboard::isKeyPressed (sf::Keyboard::L))
    {
        m_pRotkaeppchen->setDirection (90.f);
        m_pRotkaeppchen->move (m_uiElapsedTime);
    }
    else if (sf::Keyboard::isKeyPressed (sf::Keyboard::K))
    {
        m_pRotkaeppchen->setDirection (180.f);
        m_pRotkaeppchen->move (m_uiElapsedTime);
    }
    else if (sf::Keyboard::isKeyPressed (sf::Keyboard::J))
    {
        m_pRotkaeppchen->setDirection (270.f);
        m_pRotkaeppchen->move (m_uiElapsedTime);
    }
}

void CGame::processWindowEvents ()
{
    sf::Event event;
    while (m_pWindow->pollEvent(event))
    {
        switch (event.type)
        {
            // window close
            case sf::Event::Closed:
            {
                m_pWindow->close ();
            } break;

            // default
            default:
            {
                // nothing
            }
        }
    }
}

void CGame::processGameEvents ()
{
    while (!m_qpPendingEvents.empty ())
    {
        m_qpPendingEvents.front ()->handle ();
        SAFE_DELETE (m_qpPendingEvents.front ());
        m_qpPendingEvents.pop ();
    }
}

void CGame::checkCollisions ()
{
    // wolf
    if (m_pLevel->checkCollision (m_pWolf->getPos (), m_pWolf->getSize ()))
    {
        CCollision *pCollision = nullptr;
        pCollision = new CCollision (m_pWolf);
        m_qpPendingEvents.push (pCollision);
        pCollision = nullptr;
    }
    else
    {
        CMovement *pMovement = nullptr;
        pMovement = new CMovement (m_pWolf);
        m_qpPendingEvents.push (pMovement);
        pMovement = nullptr;
    }

    // rotkaeppchen
    if (m_pLevel->checkCollision (m_pRotkaeppchen->getPos (), m_pRotkaeppchen->getSize ()))
    {
        CCollision *pCollision = nullptr;
        pCollision = new CCollision (m_pRotkaeppchen);
        m_qpPendingEvents.push (pCollision);
        pCollision = nullptr;
    }
    else
    {
        CMovement *pMovement = nullptr;
        pMovement = new CMovement (m_pRotkaeppchen);
        m_qpPendingEvents.push (pMovement);
        pMovement = nullptr;
    }

    // wolf vs rotkaeppchen
    if (m_pRotkaeppchen->checkCollision (m_pWolf->getPos (), m_pWolf->getSize ()))
        m_bRun = false;
}

void CGame::render ()
{
    m_pWindow->clear ();
    list<sf::Sprite*>::iterator i;
    for (i = m_lpSprites.begin (); i != m_lpSprites.end (); i++)
    {
        m_pWindow->draw (**i);
    }
    m_pWindow->display ();
}

void CGame::loadTextures ()
{
    loadTexture ("textures/level_background.bmp", "background");
    loadTexture ("textures/level_tree.bmp", "tree");
    loadTexture ("textures/creature_wolf.bmp", "wolf");
    loadTexture ("textures/creature_rotkaeppchen.bmp", "rotkaeppchen");
}

void CGame::loadTexture (string strPath, string strDescription)
{
    pair<string, sf::Texture> texture;
    sf::Texture _texture;
    if (!_texture.loadFromFile (strPath))
    {
        if (m_bUseLogging)
            m_pLogfile->write ("failed to load" + strPath);
        cout << "failed to load " << strPath << endl;
    }
    else
    {
        texture = make_pair (strDescription, _texture);
        m_Textures.insert (texture);
    }
}

void CGame::loadSprite (string strDescription)
{
    sf::Sprite *pSprite = nullptr;
    pSprite = new sf::Sprite (m_Textures.at (strDescription));
    m_lpSprites.push_back (pSprite);
    pSprite = nullptr;
}
