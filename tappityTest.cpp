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
	ASSERT_EQ(output, 0);
}

TEST(tappityTest, length_comp_equal_empty){
	tappity tap("");
	tap.entry("");
	int output = tap.length_difference();
	ASSERT_EQ(output, 0);
}

TEST(tappityTest, length_comp_in_small){
	tappity tap("Limgrave");
	tap.entry("grave");
	int output = tap.length_difference();
	ASSERT_EQ(output, 3);
}

TEST(tappityTest, length_comp_in_big){
	tappity tap("Limgrave");
	tap.entry("Limgrave, Starting Area");
	int output = tap.length_difference();
	ASSERT_EQ(output, 15);
}

TEST(tappityTest, length_comp_in_default){
	tappity tap("Liurnia");
	int output = tap.length_difference();
	ASSERT_EQ(output, 7);
}

TEST(tappityTest, accuracy_same){
	tappity tap("Mount Gelmir");
	tap.entry("Mount Gelmir");
	double output = tap.accuracy();
	ASSERT_DOUBLE_EQ(output, double(100));
}

TEST(tappityTest, accuracy_same_single_char){
	tappity tap("A");
	tap.entry("A");
	double output = tap.accuracy();
	ASSERT_DOUBLE_EQ(output, double(100));
}

TEST(tappityTest, accuracy_same_symbol){
	tappity tap(")(!@&R%@)@RF886");
	tap.entry(")(!@&R%@)@RF886");
	double output = tap.accuracy();
	ASSERT_DOUBLE_EQ(output, double(100));
}

TEST(tappityTest, accuracy_same_empty){
	tappity tap("");
	tap.entry("");
	double output = tap.accuracy();
	ASSERT_DOUBLE_EQ(output, double(100));
}

TEST(tappityTest, accuracy_ref_empty){
	tappity tap("");
	tap.entry("Qiodh");
	double output = tap.accuracy();
	ASSERT_DOUBLE_EQ(output, double(0));
}

TEST(tappityTest, accuracy_in_empty){
	tappity tap("Consecrated Snowfield");
	tap.entry("");
	double output = tap.accuracy();
	ASSERT_DOUBLE_EQ(output, double(0));
}

TEST(tappityTest, accuracy_equal_len){
	tappity tap("Leyndell, Royal Capital");
	tap.entry("Leyndell, Ashen Capital");
	double output = tap.accuracy();
	ASSERT_DOUBLE_EQ(output, double(1800)/23);
}

TEST(tappityTest, accuracy_caps_diff){
	tappity tap("Nokstella");
	tap.entry("nOksTElLA");
	double output = tap.accuracy();
	ASSERT_DOUBLE_EQ(output, double(300)/9);
}

TEST(tappityTest, accuracy_in_long){
	tappity tap("Castle Morne");
	tap.entry("Castle Stormveil");
	double output = tap.accuracy();
	ASSERT_DOUBLE_EQ(output, double(700)/16);
}

TEST(tappityTest, accuracy_in_short){
	tappity tap("Deeproot Depths");
	tap.entry("Deekmoot");
	double output = tap.accuracy();
	ASSERT_DOUBLE_EQ(output, double(600)/15);
}

TEST(tappityTest, accuracy_in_default){
	tappity tap("Crumbling Farum Azula");
	double output = tap.accuracy();
	ASSERT_DOUBLE_EQ(output, double(0));
}

TEST(tappityTest, accuracy_in_all_wrong){
	tappity tap("Crumbling Farum Azula");
	tap.entry("ALfdgsapowfrlbnwfclkw");
	double output = tap.accuracy();
	ASSERT_DOUBLE_EQ(output, double(0));
}