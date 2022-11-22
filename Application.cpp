#include "Application.h"

Application::~Application()
{
    if (m_window != nullptr) delete m_window;

}

void Application::Init()
{
    m_window = new sf::RenderWindow(sf::VideoMode(screenWidth, screenHeight), titleGame, sf::Style::Close);
    m_window->setFramerateLimit(60);
    m_window->setVerticalSyncEnabled(false);
    GameStateMachine::GetInstance()->ChangeState(StateTypes::MENU);
    srand(time(NULL));
    WConnect->setWindow(m_window);

     /*sprite = Animation("fly", 0.07, 15);
    sprite.scale(0.5f, 0.5f);
    sprite.setPosition(200.f, 200.f);
    rectSize = Vector2i(sprite.getTexture()->getSize().x, sprite.getTexture()->getSize().y);
    sprite.setOrigin(rectSize.x/2.f, rectSize.y/2.f);*/
    CircleShape cs;
    //cs = new CircleShape()

}

RenderWindow* Application::getWindow()
{
    return m_window;
}

void Application::Run()
{
    Init();
    sf::Clock clock;
    float deltaTime = 0.f;
    while (m_window->isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        sf::Event event;
        while (m_window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window->close();
        }
        Update(deltaTime);
        Render();
    }
}

void Application::Update(float deltaTime)
{
    if (GameStateMachine::GetInstance()->NeedToChangeState()) {
        GameStateMachine::GetInstance()->PerformStateChange();
    }
    GameStateMachine::GetInstance()->currentState()->Update(deltaTime);
    /*sprite.update(deltaTime);
    sprite.setTexture(*sprite.getTexture());
    if (Keyboard::isKeyPressed(Keyboard::D))
    {
        sprite.setScale(0.5, 0.5);
        sprite.move(2.f, 0.f);
    }
    if (Keyboard::isKeyPressed(Keyboard::A))
    {
        sprite.setScale(-0.5, 0.5);
        sprite.move(-2.f, 0.f);
    }
    if (GameStateMachine::GetInstance()->NeedToChangeState()) {
        GameStateMachine::GetInstance()->PerformStateChange();
    }
    GameStateMachine::GetInstance()->currentState()->Update(deltaTime);*/
}

void Application::Render()
{
    m_window->clear(sf::Color::White);
    //Drawing something
    GameStateMachine::GetInstance()->currentState()->Render(m_window);
    m_window->display();
}
