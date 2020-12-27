#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "time.h"

//TODO: Complementary work neeed, 8-8: Your tests are insufficent, you
//should test all of the functionality relevant for each function (for
//example, am/pm or 24-hour clock in to_string).

//TODO: Complementary work neeed, 8-8: Your tests are insufficent,
//adding/subtracting should be tested when input is a large number
//(such as three days 86 400*3) to show whether the Time resets
//correctly.

//TODO: Complementary work neeed, 8-8: Your tests are insufficent, you
//should test whether all of the comparison operators, is_valid and is_am can
//return true and false respectivley.

TEST_CASE("New time")
{
    //Check if constructor is working
    Time time{23, 59, 59};
    REQUIRE(time.HH == 23);
    REQUIRE(time.MM == 59);
    REQUIRE(time.SS == 59);
}

TEST_CASE("Change time")
{
    Time time{};
    setTime(time, 12, 00, 10);
    //Check if setTime acutally altered time
    CHECK(time.HH == 12);
    CHECK(time.MM == 00);
    CHECK(time.SS == 10);
}

TEST_CASE("Test if time is valid")
{
    //Check if time is valid
    Time time{00, 01, 01};
    CHECK(is_valid(time));

    //Check if time is not valid
    setTime(time, 30, 00, 00);
    CHECK_FALSE(is_valid(time));

    setTime(time, -10, -20, -2139492);
    CHECK_FALSE(is_valid(time));
}

TEST_CASE("Check if time became a string with correct formatting")
{
    Time time {14, 39, 20}; 
    char extra_parameter{};

    //Check 24 hour time
    CHECK(to_string(time) == "14:39:20");

    //Check 12 hour time with extra parameter 
    CHECK(to_string(time, extra_parameter) == "02:39:20 pm");
}

TEST_CASE("Check if am/pm")
{
    //Check if time is am
    Time time {11, 39, 20};
    CHECK(is_am(time));

    //Check if time is pm
    setTime(time, 13, 39, 20);
    CHECK_FALSE(is_am(time));
    
}

TEST_CASE("Add N seconds")
{
    //Check if we can change only seconds
    Time time {12, 00, 05};
    Time testtime{12, 00, 10};
    CHECK(time + 5 == testtime);

    //Check if we can change only minutes 
    setTime(time, 23, 49, 59);
    setTime(testtime,23, 50, 59);
    CHECK(time + 60 == testtime);
    
    //Check if we can change only minutes and seconds
    setTime(time, 23, 49, 59);
    setTime(testtime,23, 50, 01);
    CHECK(time + 2 == testtime);

    //Check if we can change only hours
    setTime(time, 23, 49, 59);
    setTime(testtime, 00, 49, 59);
    CHECK(time + 3600 == testtime);

    //Check if we can change all values
    setTime(time, 23, 59, 59);
    setTime(testtime, 00, 00, 01);
    CHECK(time + 2 == testtime);

    //Another check of all values
    setTime(time, 12, 59, 59);
    setTime(testtime, 13, 02, 01);
    CHECK(time + 122 == testtime);

    //Another check of all values
    setTime(time, 12, 30, 30);
    setTime(testtime, 12, 30, 30);
    CHECK(time + 3600*192 == testtime); //Klarar 8 dagar.
}

TEST_CASE("Subtract N seconds")
{
    //Check if we can change only seconds
    Time time{12, 34, 07};
    Time testtime{12, 34, 02};
    CHECK(time - 5 == testtime);

    //Check if we can change only minutes
    setTime(time, 00, 01, 50);
    setTime(testtime, 00, 00, 50);
    CHECK(time - 60 == testtime);

    //Check if we can change only seconds and minutes
    setTime(time, 00, 01, 50);
    setTime(testtime, 00, 00, 59);
    CHECK(time - 51 == testtime);

    //Check if we can change only hours
    setTime(time, 23, 24, 50);
    setTime(testtime, 22, 24, 48);
    CHECK(time - 3602 == testtime);

    //Check if all values change correctly
    setTime(time, 00, 00, 04);
    setTime(testtime, 23, 59, 59);
    CHECK(time - 5 == testtime);

    //Another check of all values
    setTime(time, 12, 01, 02);
    setTime(testtime, 11, 59, 00);
    CHECK(time - 122 == testtime);

    //Another check of all values
    setTime(time, 11, 23, 02);
    setTime(testtime, 11, 23, 02);
    CHECK(time - 3600*192 == testtime);  
}


TEST_CASE("Increment addition Prefix/Postfix")
{
    //Postfix test, tmp should have original value while time changes
    Time time{12, 40, 50};
    Time testtime{12, 40, 51};
    Time testtime2{12, 40, 51};
    Time tmp{};
    CHECK(testtime++ == testtime2);
    CHECK(testtime != testtime2);


    //Prefix test, tmp should be the same value as time after add
    setTime(time, 12, 40, 50);
    setTime(testtime, 12, 40, 50); 
    tmp = ++time; 
    CHECK(tmp != testtime); 
    CHECK(tmp == time);
    testtime = testtime + 1; 
    CHECK(time == testtime);   

    //Check if operator works together with other operators to change minutes/hours
    setTime(time, 12,59,59); 
    setTime(testtime, 13,00,00);
    ++time;
    CHECK(time == testtime);
}

TEST_CASE("Increment subtraction Prefix/Postfix")
{
    //Postfix time, tmp should have original value while time changes
    Time time{12, 40, 50};
    Time testtime{12, 40, 50};
    CHECK(time-- == time);
    CHECK_FALSE(time == testtime);

    //Prefix test, tmp should be the same value as time after subtraction
    setTime(time, 12, 40, 50);
    setTime(testtime, 12, 40, 50); 
    CHECK_FALSE(--time == testtime); 
    CHECK_FALSE(time == testtime);

    //Check if operator works together with other operators to change minutes/hours
    setTime(time, 12,00,00); 
    setTime(testtime, 11,59,59);
    --time;
    CHECK(time == testtime);

}

TEST_CASE("Test not equal to")
{
    Time time{12, 12, 12};
    Time testtime{time + 1};
    CHECK(time != testtime);
}


TEST_CASE("Print time")
{
    //Add time as struct to a outputstringstream in the same way it would display through a cout and compare that string to correct formatting 
    Time time{12, 12, 12};
    std::ostringstream oss;
    oss << time;
    std::string str = oss.str();
    CHECK(str == "12:12:12");
}

TEST_CASE("Greater or equal") 
{
    //Reusing the operands > and ==
    Time time1{12,13,12};
    Time time2{12,12,12};
    CHECK (time1 >= time2);
    setTime(time1, 13,12,01);
    CHECK (time1 >= time2);
    setTime(time1, 12,12,12);
    CHECK (time1 >= time2);
}

TEST_CASE("Less or equal")
{
    //Reusing the operands < and == 
    Time time1{12,12,12};
    Time time2{12,13,12};
    CHECK (time1 <= time2);
    setTime(time1, 11,12,01);
    CHECK (time1 <= time2);
    setTime(time1, 12,13,12);
    CHECK (time1 <= time2);
}

TEST_CASE("Input stream")
{
    //Adding a string to an inputstringstream in the same way we would add it though a cin, to not require manual input for testing, and then comparing it to a time struct with original types (int)
    std::string strvalues("12:12:12");
    std::istringstream iss(strvalues);
    Time time{};
    Time testtime{12,12,12};
    iss >> time;
    CHECK(time == testtime);
}

TEST_CASE("Input stream flag test")
{
    //Check if the incorrect time value raised a flag
    std::string strvalues("12:12:100");
    std::istringstream iss(strvalues);
    Time time{};
    iss >> time; 
    CHECK(iss.fail());

    //Check if correct value didn't raise a flag
    strvalues = ("12:12:12");
    std::istringstream iss2(strvalues);
    iss2 >> time; 
    CHECK_FALSE(iss2.fail());
}