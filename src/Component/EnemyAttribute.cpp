//
// Created by User on 2024/5/12.
//

#include "Component/EnemyAttribute.hpp"

Enemy::Enemy(glm::vec2 pos, std::string path, int hp, bool visable, glm::vec2 collidersize, Enemy::HurtState state,Enemy::LifeState lifeState,glm::vec2 scale) {
    this->Health = hp;
    this->Life = lifeState;
    this->Hurt = state;
    this->Visable = visable;
    this->Position = std::make_shared<glm::vec2>(pos);
    this->Hitbox = std::make_shared<Collider>(Position,collidersize,glm::vec2 {0,0});
    this->Object = std::make_shared<ImageObject>(path);
    this->Scale = scale;
    Object->SetPosition(pos);
    Object->SetScale(Scale);
    Object->SetVisible(visable);
    Object->SetZIndex(70);
}

void Enemy::SetHealth(int health){
    Health = health;
    if(Health<=0){ //If health = 0,Set Enemy to Death
        Life = LifeState::DEAD;
        SetVisable(false);
    }
}
int Enemy::GetHealth(){
    return Health;
}

void Enemy::SetVisable(bool visable){
    Visable = visable;
    Object->SetVisible(Visable);
}
bool Enemy::GetVisable(){
    return Visable;
}

void Enemy::SetImage(std::string path){
    Object->SetImage(path);
}

Enemy::HurtState Enemy::GetHurtState(){
    return Hurt;
}
void Enemy::SetHurtState(HurtState hurtstate){
    Hurt = hurtstate;
}

Enemy::LifeState Enemy::GetLifeState(){
    return Life;
}
void Enemy::SetLifeState(LifeState lifestate){
    Life = lifestate;
}

glm::vec2 Enemy::GetPosition(){
    return *Position;
}
void Enemy::SetPosition(glm::vec2 pos){
    *Position = pos;
    Object->SetPosition(pos);
}