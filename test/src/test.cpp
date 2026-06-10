#include <gtest/gtest.h>

#include "AppInfo.h"

TEST(AppInfoTest, ToJsonNotEmpty)
{
    const auto json = AppInfo::toJson();
    EXPECT_FALSE(json.empty());
}

TEST(AppInfoTest, ToStringNotEmpty)
{
    EXPECT_FALSE(AppInfo::toString().empty());
}
