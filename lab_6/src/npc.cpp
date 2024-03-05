#include <gtest/gtest.h>

#include "../include/npc.hpp"
#include "../include/slaver.hpp"
#include "../include/druid.hpp"
#include "../include/orc.hpp"


class NPCTest : public testing::Test {
protected:
    void SetUp() override {
        slaver = std::make_shared<Slaver>("George", 0, 15);
        druid = std::make_shared<Druid>("John", 50, 15);
        orc = std::make_shared<Orc>("David", 100, 15);
    }

    std::shared_ptr<NPC> slaver, druid, orc;
};

TEST_F(NPCTest, AcceptTest) {
    ASSERT_TRUE(slaver->accept(orc));
    ASSERT_TRUE(druid->accept(orc));
    ASSERT_TRUE(orc->accept(orc));

    ASSERT_FALSE(slaver->accept(slaver));
    ASSERT_TRUE(druid->accept(slaver));
    ASSERT_FALSE(orc->accept(slaver));

    ASSERT_FALSE(slaver->accept(druid));
    ASSERT_FALSE(druid->accept(druid));
    ASSERT_FALSE(orc->accept(druid));
}

TEST_F(NPCTest, IsCloseTest) {
    ASSERT_TRUE(slaver->is_close(druid, 50));
    ASSERT_TRUE(slaver->is_close(orc, 100));
    ASSERT_FALSE(slaver->is_close(druid, 25));
    ASSERT_FALSE(slaver->is_close(orc, 50));
}