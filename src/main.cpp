#include "imgui.h"
#include "imgui-SFML.h"
#include "utils/simple_mail_box.hpp"
#include "graphics/engine.hpp"
#include "graphics/dummy_sprite.hpp"
#include "events/event_processor.hpp"
#include "elements/bomberman.hpp"
#include "elements/block.hpp"
#include "graphics/background.hpp"
#include "game/gamecore.hpp"

#include <iostream>
#include <thread>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <time.h>
#include <limits.h>

#include <unistd.h>

void test_scope();

int main()
{
    frame_timer f = {0,0,0,false};
    engine* e = engine::getInstance();

    gamecore g;
    g.run();

    e->close();
    e->join();
}
