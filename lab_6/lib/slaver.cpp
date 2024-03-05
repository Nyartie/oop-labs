#include "../include/slaver.hpp"


Slaver::Slaver(const std::string& name, int x, int y) : NPC(SlaverType, name, x, y) {}
Slaver::Slaver(std::istream& is) : NPC(SlaverType, is) {}

bool Slaver::accept(const std::shared_ptr<NPC>& attacker) const {
    std::shared_ptr<Visitor> attacker_visitor = VisitorFactory::CreateVisitor(attacker->type);
    std::shared_ptr<Slaver> defender = std::dynamic_pointer_cast<Slaver>(std::const_pointer_cast<NPC>(shared_from_this()));
    bool result = attacker_visitor->visit(defender);
    attacker->fight_notify(defender, result);
    return result;
}

void Slaver::save(std::ostream& os) {
    os << SlaverType << std::endl;
    NPC::save(os);
}

std::ostream& operator<<(std::ostream& os, Slaver& Slaver) {
    os << "Slaver " << *static_cast<NPC*>(&Slaver) << std::endl;
    return os;
}