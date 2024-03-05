#include <gtest/gtest.h>

#include "../include/npc.hpp"
#include "../include/slaver.hpp"
#include "../include/druid.hpp"
#include "../include/orc.hpp"
#include "../include/visitor.hpp"


class VisitorTest : public testing::Test {
protected:
    void SetUp() override {
        slaver = std::make_shared<Slaver>("George", 0, 15);
        druid = std::make_shared<Druid>("John", 50, 15);
        orc = std::make_shared<Orc>("David", 100, 15);

        slaver_visitor = std::make_shared<SlaverVisitor>();
        druid_visitor = std::make_shared<DruidVisitor>();
        orc_visitor = std::make_shared<OrcVisitor>();
    }

    std::shared_ptr<NPC> slaver, druid, orc;
    std::shared_ptr<Visitor> slaver_visitor, druid_visitor, orc_visitor;
};

TEST_F(VisitorTest, VisitTest) {
    ASSERT_TRUE(orc_visitor->visit(std::static_pointer_cast<Slaver>(slaver)));
    ASSERT_TRUE(orc_visitor->visit(std::static_pointer_cast<Druid>(druid)));
    ASSERT_TRUE(orc_visitor->visit(std::static_pointer_cast<Orc>(orc)));

    ASSERT_FALSE(slaver_visitor->visit(std::static_pointer_cast<Slaver>(slaver)));
    ASSERT_TRUE(slaver_visitor->visit(std::static_pointer_cast<Druid>(druid)));
    ASSERT_FALSE(slaver_visitor->visit(std::static_pointer_cast<Orc>(orc)));

    ASSERT_FALSE(druid_visitor->visit(std::static_pointer_cast<Slaver>(slaver)));
    ASSERT_FALSE(druid_visitor->visit(std::static_pointer_cast<Druid>(druid)));
    ASSERT_FALSE(druid_visitor->visit(std::static_pointer_cast<Orc>(orc)));
}
