#include <cmath>
#include <stdexcept>

#include "CrtbpSystem.hpp"

CrtbpSystem::CrtbpSystem(double mu)
{
	if (mu <= 0.0 || mu >= 1.0) {
		throw std::invalid_argument("mu value outside of range (0, 1)");
	}
  this->mu = mu;
}

double CrtbpSystem::getMassRatio()
{
  return mu;
}

void CrtbpSystem::operator()(const state_type &q, state_type &dqdt,
														 const double /* t */)
{
	double x, y, z, vx, vy, vz;
	double omm, r13, r23, r13_3, r23_3;

	x = q[0];
	y = q[1];
	z = q[2];
	vx = q[3];
	vy = q[4];
	vz = q[5];

	omm = 1.0 - mu;
	r13 = sqrt((x + mu) * (x + mu) + y * y + z * z);
	r23 = sqrt((x - 1.0 + mu) * (x - 1.0 + mu) + y * y + z * z);

	r13_3 = r13 * r13 * r13;
	r23_3 = r23 * r23 * r23;

	dqdt[0] = vx;
	dqdt[1] = vy;
	dqdt[2] = vz;
	dqdt[3] = 2.0 * vy + x - omm * (x + mu) / r13_3 - mu * (x - omm) / r23_3;
	dqdt[4] = -2.0 * vx + y - omm * y / r13_3 - mu * y / r23_3;
	dqdt[5] = -omm * z / r13_3 - mu * z / r23_3;
}
