#pragma once

#include "npc.hpp"
#include "visitor.hpp"


class Slaver: public NPC {
public:
    Slaver(const std::string&, int, int);
    Slaver(std::istream&);

    virtual bool accept(const std::shared_ptr<NPC>&) const override;

    virtual int get_move_distance() {
        return 4;
    }

    void save(std::ostream&) override;

    friend std::ostream& operator<<(std::ostream&, Slaver&);
};