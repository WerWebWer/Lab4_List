#include "../gtest/gtest.h"
#include "../TPolinom/TPolinom.h"

TEST(TPolinom, can_create_polinom)
{
	int mas[][2] = { 3,100,-3,10,1,1 };
	int size = 3;

	ASSERT_NO_THROW(TPolinom p(mas, size));
}

TEST(TPolinom, can_create_polinom_default)
{
	ASSERT_NO_THROW(TPolinom p);
}

TEST(TPolinom, cant_create_polinom_with_negative_size)
{
	int mas[][2] = { NULL };
	int size = -1;

	ASSERT_ANY_THROW(TPolinom p(mas, size));
}

TEST(TPolinom, cant_create_polinom_with_negative_power)
{
	int mas[][2] = { 3,100,-3,-10,1,1 };
	int size = 3;

	ASSERT_ANY_THROW(TPolinom p(mas, size));
}

TEST(TPolinom, can_copy_polinom)
{
	int mas[][2] = { 3,100,-3,10,1,1 };
	int size = 3;
	TPolinom p(mas, size);

	ASSERT_NO_THROW(TPolinom p1(p));
}

TEST(TPolinom, copied_polinom_has_its_own_memory)
{
	int mas[][2] = { 3,100,-3,10,1,1 };
	int size = 3;
	TPolinom p(mas, size);
	TPolinom p1(p);

	EXPECT_NE(&p, &p1);
}

TEST(TPolinom, can_add_monom_to_polinom)
{
	int mas[][2] = { 3,100,-3,10,1,1 };
	int size = 3;
	TPolinom p(mas, size);
	TMonom m = { 5,102 };

	ASSERT_NO_THROW(p.InsMonom(m));
}

TEST(TPolinom, can_add_two_polinoms)
{
	int mas[][2] = { 3,100,-3,10,1,1 };
	int size = 3;
	TPolinom p(mas, size);
	int mas1[][2] = { 2,100,3,10,4,0 };
	TPolinom p1(mas1, size);

	ASSERT_NO_THROW(p += p1);
}

TEST(TPolinom, can_add_two_polinoms_first_last_delete)
{
	int mas[][2] = { 3,101,-3,310,1,1 };
	int size = 3;
	TPolinom p(mas, size);
	int mas1[][2] = { 2,101,3,310,-1,1 };
	TPolinom p1(mas1, size);
	p += p1;
	EXPECT_NE(5, p.GetMonom().coeff);
	EXPECT_NE(101, p.GetMonom().power);
}

TEST(TPolinom, can_subtract_two_polinoms)
{
	int mas[][2] = { 3,100,-3,10,1,1 };
	int size = 3;
	TPolinom p(mas, size);
	int mas1[][2] = { 2,100,3,10,4,0 };
	TPolinom p1(mas1, size);

	ASSERT_NO_THROW(p -= p1);
}

TEST(TPolinom, can_multiply_polinom_on_const_number)
{
	int mas[][2] = { 3,100,-3,10,1,1 };
	int size = 3;
	TPolinom p(mas, size);

	ASSERT_NO_THROW(p *= 2);
}