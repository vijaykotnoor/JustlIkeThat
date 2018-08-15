#include "application.hpp"
#include <gmock/gmock.h>
#include <stdexcept>
#include <future>

using namespace testing;

// Unit test to test 0 Minutes arguments.
TEST(ArgumentTest, MinuteArgumentShouldNotBeZero) {
    using std::chrono::minutes;
    using crossover::monitor::client::application;
    try{
        application a{minutes(0)};
        FAIL();
    }
    catch(const std::invalid_argument & expected) {}
    
}

TEST(ArgumentTest, MinuteArgumentEqualToOne) {
    using std::chrono::minutes;
    using crossover::monitor::client::application;
    try{
        application a{minutes(1)};
        
    }
    catch(const std::invalid_argument & expected)
    {FAIL();}
    
}

TEST(RuntimeTest, RunTheApplicatin) {
    using std::chrono::minutes;
    using crossover::monitor::client::application;
    try{
        application a{minutes(1)};
        
        auto run_fut = std::async (std::launch::async, [&](){a.run();});
        auto stop_fut = std::async (std::launch::async, [&](){a.stop();});
        
    }
    catch(const std::invalid_argument & expected)
    {FAIL();}
    
}
void taska()
{
    int a = 0;
    a++;
}
int main( int argc, char *argv[] ) {
    ::testing::InitGoogleMock( &argc, argv );
    std::async(taska);
    return RUN_ALL_TESTS( );
}
