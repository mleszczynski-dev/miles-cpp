#include <gtest/gtest.h>
#include <iostream>

#include "AppInfo.h"

TEST(AppInfoTest, ToStringNotEmpty)
{
    const auto info = AppInfo::toString();
    
    std::cout << info << std::endl;
    
    EXPECT_FALSE(info.empty());
}

