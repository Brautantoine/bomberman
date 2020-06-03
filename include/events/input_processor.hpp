#ifndef INPUT_PROCESSOR_HPP
#define INPUT_PROCESSOR_HPP

#include "events/event_processor.hpp"
#include "utils/simple_mail_box.hpp"

#include <SFML/Window/Event.hpp>

// Input_processor disparait
// move_generator devient une entité indépendante et inclut event_mangaer
// Personnage est parametrable (id_joueur, type[player || ia])
// Personnage inclut un event_processor qui stocke les events valide dans la mail_box

#endif //INPUT_PROCESSOR_HPP
