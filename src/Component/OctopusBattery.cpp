//
// Created by User on 2024/5/6.
//

#include "Component/OctopusBattery.hpp"
#include "Util/Logger.hpp"
#include "Util/Time.hpp"

OctopusBattery::OctopusBattery(glm::vec2 inipos, glm::vec2 finpos,
                               glm::vec2 collidersize, glm::vec2 speed,
                               glm::vec2 scale, std::vector<std::string> path,
                               int health, bool visable, OctopusState state,
                               Enemy::HurtState hurtstate)
    : Enemy(inipos, path[0], health, visable, collidersize, hurtstate) {
    this->InitialPosition = inipos;
    this->FinalPosition = finpos;
    this->Speed = speed;
    this->State = state;
    this->Path = path;
}
void OctopusBattery::DoBehavior(glm::vec2 position) {
    float direction =
        sqrt((position.x - Position->x) * (position.x - Position->x) +
             (position.y - Position->y) * (position.y - Position->y));
    if (direction <= 530) {
        PhysicEngine();
    }
}
void OctopusBattery::PhysicEngine() {
    switch (State) {
    case OctopusState::SLEEP:
        if (Util::Time::GetElapsedTimeMs() - SleepCounter > 2000) {
            State = OctopusState::BLEAZY;
            BleazyCounter = Util::Time::GetElapsedTimeMs();
            Object->SetImage(Path[1]);
        }
        break;
    case OctopusState::BLEAZY:
        if (Util::Time::GetElapsedTimeMs() - BleazyCounter > 500) {
            State = OctopusState::AWAKE;
            Object->SetImage(Path[2]);
        }
        break;
    case OctopusState::AWAKE:
        if (Position->x != FinalPosition.x) {
            glm::vec2 dir = {(FinalPosition.x - InitialPosition.x) /
                                 abs(FinalPosition.x - InitialPosition.x),
                             1};
            Position->x += Speed.x * dir.x;
            Position->y += Speed.y * dir.y;
            Object->SetPosition(*Position);
        }
        else {
            std::swap(InitialPosition, FinalPosition);
            SleepCounter = Util::Time::GetElapsedTimeMs();
            Object->SetImage(Path[0]);
            State = OctopusState::SLEEP;
        }
        break;
    }
}
