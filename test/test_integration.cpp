#include "CrtbpSystem.hpp"
#include <assert.h>
#include <boost/numeric/odeint.hpp>
#include <iostream>

struct push_back_state_and_time
{
	std::vector<state_type> &m_states;
	std::vector<double> &m_times;

	push_back_state_and_time(std::vector<state_type> &states,
													 std::vector<double> &times)
			: m_states(states), m_times(times)
	{
	}

	void operator()(const state_type &x, double t)
	{
		m_states.push_back(x);
		m_times.push_back(t);
	}
};

int main()
{
	using namespace boost::numeric::odeint;

	CrtbpSystem sys(0.012);
	size_t steps;
	state_type x(6);
	x[0] = 0.8;
	x[1] = 0.0;
	x[2] = 0.0;
	x[3] = 0.0;
	x[4] = 0.7;
	x[5] = 0.0;

	std::vector<state_type> x_vec;
	std::vector<double> times;

	steps =
			integrate(sys, x, 0.0, 20.0, 0.1, push_back_state_and_time(x_vec, times));

	/* output */
	for (size_t i = 0; i <= steps; i++) {
		std::cout << x_vec[i][0] << ' ' << x_vec[i][1] << ' ' << x_vec[i][2]
							<< '\n';
	}
  return 0;
}
