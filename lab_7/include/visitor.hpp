#pragma once

#include "npc.hpp"
#include "orc.hpp"
#include "druid.hpp"
#include "slaver.hpp"


class Visitor {
public:
    virtual bool visit(const std::shared_ptr<Orc>&) const = 0;
    virtual bool visit(const std::shared_ptr<Druid>&) const = 0;
    virtual bool visit(const std::shared_ptr<Slaver>&) const = 0;
};


class OrcVisitor final : public Visitor {
public:
    virtual bool visit(const std::shared_ptr<Orc>&) const override { return true; }
    virtual bool visit(const std::shared_ptr<Druid>&) const override { return true; }
    virtual bool visit(const std::shared_ptr<Slaver>&) const override { return true; }
};

class DruidVisitor final : public Visitor {
    virtual bool visit(const std::shared_ptr<Orc>&) const override { return false; }
    virtual bool visit(const std::shared_ptr<Druid>&) const override { return false; }
    virtual bool visit(const std::shared_ptr<Slaver>&) const override { return false; }
};

class SlaverVisitor final : public Visitor {
    virtual bool visit(const std::shared_ptr<Orc>&) const override { return false; }
    virtual bool visit(const std::shared_ptr<Druid>&) const override { return true; }
    virtual bool visit(const std::shared_ptr<Slaver>&) const override { return false; }
};


class VisitorFactory {
public:
    static std::shared_ptr<Visitor> CreateVisitor(const NPCType& type) {
        std::shared_ptr<Visitor> result;

        switch (type) {
            case NPCType::OrcType:
                result = std::static_pointer_cast<Visitor>(std::make_shared<OrcVisitor>());
                break;

            case NPCType::DruidType:
                result = std::static_pointer_cast<Visitor>(std::make_shared<DruidVisitor>());
                break;

            case NPCType::SlaverType:
                result = std::static_pointer_cast<Visitor>(std::make_shared<SlaverVisitor>());
                break;

            default:
                break;
        }

        return result;
    }
};