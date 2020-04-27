#include "CrtbpSystem.hpp"
#include <assert.h>


int main()
{
  CrtbpSystem sys(0.5);
  assert(sys.getMassRatio() == 0.5);
  return 0;
}

