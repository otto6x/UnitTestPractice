/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
    Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1,actual);
}
TEST(PasswordTest, repeating_at_end)
{
	Password my_password;
	ASSERT_EQ(1,my_password.count_leading_characters("Zoo"));
}
TEST(PasswordTest, repeating_in_middle)
{
	Password my_password;
	ASSERT_EQ(1,my_password.count_leading_characters("Book"));
}
TEST(PasswordTest, first_character_repeats_later)
{
	Password my_password;
	ASSERT_EQ(1,my_password.count_leading_characters("abaaa"));
}
TEST(PasswordTest, must_fail)
{
	Password my_password;
	ASSERT_EQ(1,my_password.count_leading_characters("aaa"));
}
TEST(PasswordTest, upper_lower)
{
	Password my_password;
	ASSERT_EQ(1,my_password.count_leading_characters("Aa"));
}
TEST(PasswordTest, lower_upper)
{
	Password my_password;
	ASSERT_EQ(1,my_password.count_leading_characters("aA"));
}

