//---------------------------------------------------------------------------

#ifndef FuzzyNumberH
#define FuzzyNumberH
#include <vector>
#include <algorithm>
//---------------------------------------------------------------------------
class FuzzyNumber
{
public:
    FuzzyNumber()
    {};

    FuzzyNumber(double l, double a, double b, double r)
        : m_l(l), m_a(a), m_b(b), m_r(r)
    {};

    friend FuzzyNumber operator+ (const FuzzyNumber leftArg, const FuzzyNumber rightArg)
    {
        return FuzzyNumber(leftArg.m_l + rightArg.m_l, leftArg.m_a + rightArg.m_a, leftArg.m_b + rightArg.m_b, leftArg.m_r + rightArg.m_r);
    };

	friend FuzzyNumber operator- (const FuzzyNumber leftArg, const FuzzyNumber rightArg)
    {
        return FuzzyNumber(leftArg.m_l - rightArg.m_r, leftArg.m_a - rightArg.m_b, leftArg.m_b - rightArg.m_a, leftArg.m_r - rightArg.m_l);
    };

	friend FuzzyNumber operator* (const double x, const FuzzyNumber rightArg)
    {
        if(x >= 0)
            return FuzzyNumber(x*rightArg.m_l, x*rightArg.m_a, x*rightArg.m_b, x*rightArg.m_r);
        else
            return FuzzyNumber(x*rightArg.m_r, x*rightArg.m_b, x*rightArg.m_a, x*rightArg.m_l);
    };

	friend FuzzyNumber operator* (const FuzzyNumber leftArg, const double x)
	{
		return x*leftArg;
	};

	friend FuzzyNumber operator* (const FuzzyNumber leftArg, const FuzzyNumber rightArg)
	{
		FuzzyNumber res;
		std::vector<double> v;

		v.push_back(leftArg.m_a*rightArg.m_a);
		v.push_back(leftArg.m_a*rightArg.m_b);
		v.push_back(leftArg.m_b*rightArg.m_a);
		v.push_back(leftArg.m_b*rightArg.m_b);

		res.m_a = (*std::min_element(v.begin(), v.end()));
		res.m_b = (*std::max_element(v.begin(), v.end()));

		v.clear();
		v.push_back(leftArg.m_l*rightArg.m_l);
		v.push_back(leftArg.m_l*rightArg.m_r);
		v.push_back(leftArg.m_r*rightArg.m_l);
		v.push_back(leftArg.m_r*rightArg.m_r);

		res.m_l = (*std::min_element(v.begin(), v.end()));
		res.m_r = (*std::max_element(v.begin(), v.end()));

		return res;
	};

	static FuzzyNumber getInverse (const FuzzyNumber &x)
	{
		FuzzyNumber res;

		// check for zero left middle value
		if (x.m_a != 0) {
			res.m_b = 1. / x.m_a;
		}
		else
			res.m_b = 0;

		// check for zero right middle value
		if (x.m_b != 0) {
			res.m_a = 1. / x.m_b;
		}
		else
			res.m_a = 0;

		// check for zero right value
		if (0 == x.m_r)
			res.m_l = 0.0;
		else
			res.m_l = 1.0 / x.m_r;

		// check for zero left value
		if (0 == x.m_l)
			res.m_r = 0.0;
		else
			res.m_r = 1.0/x.m_l;

		return res;
	};


    double getMembershipVal(double x)
    {
         if(x <= m_l || x >= m_r)
             return 0;

         if(x >= m_a && x <= m_b)
             return 1;

         if(x >= m_l && x <= m_a)
             return(1. - (m_a - x)/(m_a - m_l));

         if(x >= m_b && x <= m_r)
             return(1. - (x - m_b)/(m_r - m_b));

    };

public:
    double m_l;
    double m_a;
    double m_b;
    double m_r;
};

#endif
