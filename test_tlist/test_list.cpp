#include "../gtest/gtest.h"
#include "../List/TLink.h"
#include "../List/THeadList.h"

TEST(TLink, can_create_link)
{
	ASSERT_NO_THROW(TLink <int> *p=new TLink <int>);
}

TEST(TLink, can_set_val)
{
	TLink <int> *p=new TLink <int>;
	p->val = 10;

	EXPECT_EQ(10, p->val);
}

TEST(THeadList, can_create_headlist)
{
	ASSERT_NO_THROW(THeadList <int> h);
}

TEST(THeadList, can_insert_first_elem)
{
	THeadList <int> h;
	ASSERT_NO_THROW(h.InsFirst(10));
}

TEST(THeadList, can_delete_first_elem)
{
	THeadList <int> h;
	h.InsFirst(10);

	ASSERT_NO_THROW(h.DelFirst());
}