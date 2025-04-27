#include <gtest/gtest.h>
#include <private_member_access.hpp>

class sample_class
{	private:
		int member1, member2;
	public:
		sample_class() : member1(4) {}
		int get_member2(void) { return member2; }
};

PMA_DECLARE(sample_class, member1)
PMA_DECLARE(sample_class, member2)

TEST(basic, basic)
{	sample_class instance;

	ASSERT_EQ(PMA_GET(sample_class, member1, int, &instance), 4);

	PMA_GET(sample_class, member2, int, &instance) = 12;
	ASSERT_EQ(instance.get_member2(), 12);

	int & reference = PMA_GET(sample_class, member2, int, &instance);
	reference = 25;
	ASSERT_EQ(instance.get_member2(), 25);
}
