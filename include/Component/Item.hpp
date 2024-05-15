#ifndef ITEM_HPP
#define ITEM_HPP

#include "Component/Collider.hpp"
#include "Util/Animation.hpp"
#include "Util/GameObject.hpp"
#include "Util/Image.hpp"

enum class ItemType {
    SMALL_HEALTH_ENERGY,
    BIG_HEALTH_ENERGY,
    SMALL_WEAPON_ENERGY,
    BIG_WEAPON_ENERGY,
    ONE_UP,
    SPECIAL_WEAPON_ITEM,
    SCORE_BALL
};

// TODO: Implement Gravity for Items later

class Item final : public Util::GameObject {
public:
    explicit Item(ItemType type, glm::vec2 position);
    ~Item() override = default;

    [[nodiscard]] ItemType GetType() const { return m_Type; }

    [[nodiscard]] Collider GetCollider() const { return *m_Collider; }

private:
    ItemType m_Type;
    std::shared_ptr<Collider> m_Collider;
};

#endif