//
// Created by Bradley Remedios on 10/25/24.
//

#include "gtest/gtest.h"
#include "../os/Path.h"

TEST(OSPathTestSuite, GetCwd) {
    EXPECT_NE(os::Path::GetCwd(), "");
}