#pragma once
#include "npc.hpp"
#include "slaver.hpp"
#include "druid.hpp"
#include "orc.hpp"
#include "observer.hpp"

class Factory {
public:
    static std::shared_ptr<NPC> CreateNPC(const NPCType& type, const std::string& name, int x, int y) {
        std::shared_ptr<NPC> result;
        switch (type) {
            case NPCType::SlaverType:
                result = std::static_pointer_cast<NPC>(std::make_shared<Slaver>(name, x, y));
                break;

            case NPCType::DruidType:
                result = std::static_pointer_cast<NPC>(std::make_shared<Druid>(name, x, y));
                break;

            case NPCType::OrcType:
                result = std::static_pointer_cast<NPC>(std::make_shared<Orc>(name, x, y));
                break;
            default:
                break;
        }

        if (result) {
            result->subscribe(TextObserver::get());
            result->subscribe(FileObserver::get());
        }

        return result;
    }

    static std::shared_ptr<NPC> CreateNPC(std::istream& is) {
        std::shared_ptr<NPC> result;
        int type{0};
        if (is >> type) {
            switch (type) {
                case NPCType::SlaverType:
                    result = std::static_pointer_cast<NPC>(std::make_shared<Slaver>(is));
                    break;

                case NPCType::DruidType:
                    result = std::static_pointer_cast<NPC>(std::make_shared<Druid>(is));
                    break;

                case NPCType::OrcType:
                    result = std::static_pointer_cast<NPC>(std::make_shared<Orc>(is));
                    break;
                default:
                    break;
            }
        } else {
            std::cerr << "unexpected NPC type:" << type << std::endl;
        }

        if (result) {
            result->subscribe(TextObserver::get());
            result->subscribe(FileObserver::get());
        }

        return result;
    }
};
