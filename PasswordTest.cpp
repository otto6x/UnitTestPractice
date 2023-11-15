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
TEST(PasswordTest, must_fail_count)
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
TEST(PasswordTest, blank)
{
	Password my_password;
	ASSERT_EQ(1,my_password.count_leading_characters(""));
}
TEST(PasswordTest, blank_space)
{
	Password my_password;
	ASSERT_EQ(1,my_password.count_leading_characters(" "));
}
TEST(PasswordTest, blank_spaces)
{
	Password my_password;
	ASSERT_EQ(1,my_password.count_leading_characters("   "));
}

TEST(PasswordTest, must_fail_lowercase)
{
	Password my_password;
	ASSERT_EQ(true,my_password.has_mixed_case("aaa"));
}
TEST(PasswordTest, must_fail_uppercase)
{
	Password my_password;
	ASSERT_EQ(true,my_password.has_mixed_case("AAA"));
}
TEST(PasswordTest, mixed_1_char_uppercase)
{
	Password my_password;
	ASSERT_EQ(true,my_password.has_mixed_case("A"));
}
TEST(PasswordTest, mixed_1_char_lowercase)
{
	Password my_password;
	ASSERT_EQ(true,my_password.has_mixed_case("a"));
}
TEST(PasswordTest, mixed_normal)
{
	Password my_password;
	ASSERT_EQ(true,my_password.has_mixed_case("aBcdE"));
}
TEST(PasswordTest, mixed_special)
{
	Password my_password;
	ASSERT_EQ(true,my_password.has_mixed_case(" !@#$%^&*():;,./<>?`~|-=_+"));
}
TEST(PasswordTest, mixed_special_with_normal)
{
	Password my_password;
	ASSERT_EQ(true,my_password.has_mixed_case(" !@#$%^&*():;,./<>?`~|-=_+abcdABCD"));
}

TEST(PasswordTest, check_default)
{
	Password my_password;
	ASSERT_EQ(false,my_password.authenticate("test"));
}

TEST(PasswordTest, add_new_working_password)
{
	Password my_password;
	my_password.set("NewPassword");
	ASSERT_EQ(true,my_password.authenticate("NewPassword"));
}
TEST(PasswordTest, add_new_short_password)
{
	Password my_password;
	my_password.set("New");
	ASSERT_EQ(false,my_password.authenticate("New"));
}
TEST(PasswordTest, add_new_repeat_password)
{
	Password my_password;
	my_password.set("NNNNewPassword");
	ASSERT_EQ(false,my_password.authenticate("NNNNewPassword"));
}
TEST(PasswordTest, add_new_fake_password)
{
	Password my_password;
	my_password.set("NewPassword");
	ASSERT_EQ(false,my_password.authenticate("Password"));
}