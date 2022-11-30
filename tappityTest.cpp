/**
 * Unit Test suite
**/

#include <gtest/gtest.h>
#include "tappity.h"
 
class tappityTest : public ::testing::Test
{
	protected:
		tappityTest(){} 
		virtual ~tappityTest(){} 
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(tappityTest, smoke_test){
	ASSERT_TRUE(true);
}

TEST(tappityTest, set_ref){
	tappity tap("Altus Plateau");
	ASSERT_TRUE(true);
}

TEST(tappityTest, set_ref_empty){
	tappity tap("");
	ASSERT_TRUE(true);
}

TEST(tappityTest, set_input){
	tappity tap("Leyndell, Royal Capital");
	tap.entry("Leyndell, Ashen Capital");
	ASSERT_TRUE(true);
}

TEST(tappityTest, set_input_empty){
	tappity tap("Caelid Wilds");
	tap.entry("");
	ASSERT_TRUE(true);
}

TEST(tappityTest, length_comp_equal){
	tappity tap("Leyndell, Royal Capital");
	tap.entry("Leyndell, Ashen Capital");
	int output = tap.length_difference();
	ASSERT_EQ(output, 0)
}

TEST(tappityTest, length_comp_in_small){
	tappity tap("Limgrave");
	tap.entry("grave");
	int output = tap.length_difference();
	ASSERT_EQ(output, 3)
}

TEST(tappityTest, length_comp_in_big){
	tappity tap("Limgrave");
	tap.entry("Limgrave, Starting Area");
	int output = tap.length_difference();
	ASSERT_EQ(output, 15)
}