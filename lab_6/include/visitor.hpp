#pragma once

#include "npc.hpp"
#include "slaver.hpp"
#include "druid.hpp"
#include "orc.hpp"


class Visitor {
public:
    virtual bool visit(const std::shared_ptr<Slaver>&) const = 0;
    virtual bool visit(const std::shared_ptr<Druid>&) const = 0;
    virtual bool visit(const std::shared_ptr<Orc>&) const = 0;
};


class SlaverVisitor final : public Visitor {
public:
    virtual bool visit(const std::shared_ptr<Slaver>&) const override { return false; }
    virtual bool visit(const std::shared_ptr<Druid>&) const override { return true; }
    virtual bool visit(const std::shared_ptr<Orc>&) const override { return false; }
};

class DruidVisitor final : public Visitor {
    virtual bool visit(const std::shared_ptr<Slaver>&) const override { return false; }
    virtual bool visit(const std::shared_ptr<Druid>&) const override { return false; }
    virtual bool visit(const std::shared_ptr<Orc>&) const override { return false; }
};

class OrcVisitor final : public Visitor {
    virtual bool visit(const std::shared_ptr<Slaver>&) const override { return true; }
    virtual bool visit(const std::shared_ptr<Druid>&) const override { return true; }
    virtual bool visit(const std::shared_ptr<Orc>&) const override { return true; }
};


class VisitorFactory {
public:
    static std::shared_ptr<Visitor> CreateVisitor(const NPCType& type) {
        std::shared_ptr<Visitor> result;

        switch (type) {
            case NPCType::SlaverType:
                result = std::static_pointer_cast<Visitor>(std::make_shared<SlaverVisitor>());
                break;

            case NPCType::DruidType:
                result = std::static_pointer_cast<Visitor>(std::make_shared<DruidVisitor>());
                break;

            case NPCType::OrcType:
                result = std::static_pointer_cast<Visitor>(std::make_shared<OrcVisitor>());
                break;

            default:
                break;
        }

        return result;
    }
};