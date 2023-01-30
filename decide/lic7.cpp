#include <cassert>
#include <decide/decide.hpp>

// 1 <= K_PTS <= (NUMPOINTS - 2). According to specification.
bool lic7(Points points, Parameters parameters) {
  int npts = points.size();
  int kpts = parameters.KPTS;
  double length = parameters.LENGTH1;

  // The condition is not met when NUMPOINTS < 3
  if (npts < 3)
    return false;

  Coordinate *last = &points[0];

  // Next point separated by kpts points.
  for (int i = 1 + kpts; i < npts; i++) {
    Coordinate *current = &points[i];
    double distance = current->distance(*last);

    if (distance > length)
      return true;

    last = current;
  }

  return false;
}